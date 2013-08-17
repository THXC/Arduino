Imports System.IO.Ports.SerialPort

Public Class Form1

    Dim Time As Long
    Dim X_Last As Long
    Dim Y_Last As Long
    Dim Plot_Value As Integer

    'Datenspeicher für eingehende Daten
    Dim input_data(255) As Byte

    'Spannungs Variablen
    Dim Spg_Data As Single

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        'Verfügbare Comports suchen
        Dim ports As String() = GetPortNames()
        Dim Port As String

        'Combobox richtig sortieren
        ComboBox_Comport.Items.Clear()

        If ports.Length > 0 Then

            ' für alle COM-Nr. < 10 ein Leerzeichen einfügen
            For ii As Integer = 0 To (ports.Length - 1)
                If CInt(ports(ii).Substring(3)) < 10 Then
                    ports(ii) = "COM " & ports(ii).Substring(3)
                End If
            Next

            Array.Sort(ports)

            ' das Leerzeichen in "COM x" wieder entfernen
            For ii As Integer = 0 To (ports.Length - 1)
                ports(ii) = "COM" & ports(ii).Substring(3).Trim
            Next

        End If

        'In die Combobox übernehmen
        For Each Port In ports
            ComboBox_Comport.Items.Add(Port)
        Next Port

        'Buttons sperren
        Button_Disconnect.Enabled = False
        Button_Connect.Enabled = False

        'Texte vorbelegen
        Label1.Text = "0.00 Volt"

        'Netz zeichnen
        Draw_Grid()

    End Sub

    Private Sub Draw_Grid()

        If Not Me.AutoRedraw1.Graphics Is Nothing Then

            Me.AutoRedraw1.Graphics.Clear(Color.Black)

            'Netz zeichnen
            'X-Linie
            For i = 0 To 500 Step 50
                Me.AutoRedraw1.Graphics.DrawLine(Pens.Gray, i, 0, i, 250)
            Next i

            'Y-Linie
            For i = 0 To 250 Step 25
                Me.AutoRedraw1.Graphics.DrawLine(Pens.Gray, 0, i, 500, i)
            Next

            Me.AutoRedraw1.Invalidate()

        End If

    End Sub
    Private Sub ComboBox_Comport_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox_Comport.SelectedIndexChanged

        'Comport auswählen
        If ComboBox_Comport.SelectedItem <> "" Then
            Button_Connect.Enabled = True
        End If

    End Sub

    Private Sub Button_Connect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button_Connect.Click

        'Comport verbinden
        Try

            'Buttons freigeben-/ sperren
            Button_Connect.Enabled = False
            Button_Disconnect.Enabled = True
            ComboBox_Comport.Enabled = False

            'Comport Einstellungen
            SerialPort1.PortName = ComboBox_Comport.Text
            SerialPort1.BaudRate = 9600
            SerialPort1.Open()

            Timer1.Enabled = True
            Timer1.Interval = 100
            RadioButton1.Checked = True

        Catch ex As Exception

            'Fehlermeldung 
            MessageBox.Show("Achtung die Schnittstelle konnte nicht geöffnet werden! " + e.ToString _
                       , "Ausnahmefehler", MessageBoxButtons.OK, MessageBoxIcon.Error)
            Button_Connect.Enabled = True
            Button_Disconnect.Enabled = False
            ComboBox_Comport.Enabled = True

        End Try

    End Sub

    Private Sub Button_Disconnect_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button_Disconnect.Click

        'Verbindung trennen
        Timer1.Enabled = False
        Button_Connect.Enabled = True
        Button_Disconnect.Enabled = False
        ComboBox_Comport.Enabled = True
        SerialPort1.Close()

    End Sub

    Private Sub SerialPort1_DataReceived(ByVal sender As Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived

        Dim cnt As Byte
        Dim in_bytes As Byte
        Dim HighByte As Byte
        Dim LowByte As Byte
        Dim crc As Byte
        Dim crc_ok As Byte
        Dim Spg_Data As Integer
        Dim Spannung As Single


        Try

            'Hier werden die Daten empfangen
            If SerialPort1.IsOpen Then

                Control.CheckForIllegalCrossThreadCalls = False

                'wieviele Bytes sind im Puffer
                in_bytes = SerialPort1.BytesToRead

                'Alle Bytes holen
                For cnt = 1 To (in_bytes)
                    input_data(cnt) = SerialPort1.ReadByte
                Next

                'Puffer leeren
                SerialPort1.DiscardInBuffer()

                HighByte = input_data(1)
                LowByte = input_data(2)
                crc = input_data(3)

                'Checksumme
                crc_ok = 170 Xor input_data(1) Xor input_data(2)

                If crc = crc_ok Then

                    'High und Low Byte wieder zusammensetzen
                    Spg_Data = (HighByte * 256) + LowByte

                    'RAW Wert umrechen und als Spannung Anzeigen
                    Spannung = (5 / 1024) * Spg_Data
                    Label1.Text = Format(Spannung, "0.00 Volt")

                    Plot_Value = 250 - (Spg_Data / 4)

                    'Linie plotten
                    Time = Time + 1

                    'löschen wenn das Feld voll ist
                    If Time > 500 Then
                        Time = 0
                        X_Last = 0
                        Y_Last = Plot_Value
                        Draw_Grid()
                    End If

                    If Not Me.AutoRedraw1.Graphics Is Nothing Then

                        'X,Y Start ; X,Y Ende
                        Me.AutoRedraw1.Graphics.DrawLine(Pens.Red, X_Last, Y_Last, Time, Plot_Value)

                        'letzte Werte speichern
                        X_Last = Time
                        Y_Last = Plot_Value

                        Me.AutoRedraw1.Invalidate()

                    End If

                End If

            End If

        Catch ex As Exception

        End Try

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick

        SerialPort1.Write(ChrW(55))

    End Sub

    Private Sub RadioButton1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton1.CheckedChanged

        Timer1.Interval = 100

    End Sub

    Private Sub RadioButton2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton2.CheckedChanged

        Timer1.Interval = 500

    End Sub

    Private Sub RadioButton3_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton3.CheckedChanged

        Timer1.Interval = 1000

    End Sub
End Class
