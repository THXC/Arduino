Imports System.IO.Ports.SerialPort

Public Class Form1

    'Datenspeicher für eingehende Daten
    Dim input_data(512) As Byte

    'Spannungs Variablen
    Dim spg_Data(10) As Single

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
        Dim highbyte_last As Byte
        Dim lowbyte_last As Byte
        Dim crc As Byte
        Dim crc_ok As Byte


        SerialPort1.Write(ChrW(42))

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
                highbyte_last = input_data(11)
                lowbyte_last = input_data(12)
                crc = input_data(13)
                crc_ok = 170 Xor highbyte_last Xor lowbyte_last


                If crc = crc_ok Then

                    cnt = 0
                    For cnt_array = 1 To 12 Step 2

                        highByte = input_data(cnt_array)
                        lowByte = input_data(cnt_array + 1)

                        cnt = cnt + 1
                        spg_Data(cnt) = (5 / 1024) * ((highByte * 256) + lowByte)


                        Select Case cnt

                            Case 1
                                TextBox1.Text = Format(spg_Data(1), "0.00 Volt")

                            Case 2
                                TextBox2.Text = Format(spg_Data(2), "0.00 Volt")

                            Case 3
                                TextBox3.Text = Format(spg_Data(3), "0.00 Volt")

                            Case 4
                                TextBox4.Text = Format(spg_Data(4), "0.00 Volt")

                            Case 5
                                TextBox5.Text = Format(spg_Data(5), "0.00 Volt")

                            Case 6
                                TextBox6.Text = Format(spg_Data(6), "0.00 Volt")

                        End Select

                    Next


                End If

            End If

        Catch ex As Exception

        End Try

    End Sub

End Class
