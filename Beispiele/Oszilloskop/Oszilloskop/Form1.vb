Imports System.IO.Ports.SerialPort

Public Class Form1

    Dim time As Long
    Dim x_Last As Long
    Dim y_Last As Long
    Dim plot_Value As Integer
    Dim messpunkte As Integer

    'Datenspeicher für eingehende Daten
    Dim input_data(2048) As Byte

    'Spannungs Variablen
    Dim spg_Data As Single

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

        'Buttons setzen
        Button_Disconnect.Enabled = False
        Button_Connect.Enabled = False
        RadioButton3.Checked = True

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
            SerialPort1.BaudRate = 115200
            SerialPort1.Open()

            Timer1.Enabled = True
            Messpunkte = 250

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

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick

        Dim cnt As Integer
        Dim in_bytes As Integer
        Dim cnt_array As Integer
        Dim highByte As Byte
        Dim lowByte As Byte
        Dim Teiler As Integer
        Dim highbyte_last As Byte
        Dim lowbyte_last As Byte
        Dim crc As Byte
        Dim crc_ok As Byte


        Time = 0
        X_Last = 0
        Y_Last = Plot_Value
        Draw_Grid()

        SerialPort1.Write(ChrW(55))

        Try

            'Hier werden die Daten empfangen
            If SerialPort1.IsOpen Then

                Control.CheckForIllegalCrossThreadCalls = False

                'wieviele Bytes sind im Puffer
                in_bytes = SerialPort1.BytesToRead

                'Alle Bytes holen
                For cnt = 1 To in_bytes
                    input_data(cnt) = SerialPort1.ReadByte
                Next


                'Checksummen Berechnung
                highbyte_last = input_data(in_bytes - 2)
                lowbyte_last = input_data(in_bytes - 1)
                crc = input_data(in_bytes)
                crc_ok = 170 Xor highbyte_last Xor lowbyte_last

                If crc = crc_ok Then


                    For cnt_array = 1 To ((messpunkte * 2) + 2) Step 2

                        highByte = input_data(cnt_array)
                        lowByte = input_data(cnt_array + 1)

                        spg_Data = (highByte * 256) + lowByte

                        plot_Value = 250 - (spg_Data / 4)

                        'Linie plotten
                        Teiler = 500 / messpunkte
                        time = time + Teiler

                        If Not Me.AutoRedraw1.Graphics Is Nothing Then

                            'X,Y Start ; X,Y Ende
                            Me.AutoRedraw1.Graphics.DrawLine(Pens.Red, x_Last, y_Last, time, plot_Value)

                            'letzte Werte speichern
                            x_Last = time
                            y_Last = plot_Value

                            Me.AutoRedraw1.Invalidate()

                        End If

                    Next

                End If

            End If

        Catch ex As Exception

        End Try

    End Sub

    Private Sub RadioButton1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton1.CheckedChanged
        Messpunkte = 50
    End Sub

    Private Sub RadioButton2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton2.CheckedChanged
        Messpunkte = 100
    End Sub

    Private Sub RadioButton3_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles RadioButton3.CheckedChanged
        Messpunkte = 250
    End Sub

End Class
