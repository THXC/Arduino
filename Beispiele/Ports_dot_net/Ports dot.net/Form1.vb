Imports System.IO.Ports.SerialPort

Public Class Form1

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        If SerialPort1.IsOpen Then
            SerialPort1.Write(ChrW(100))
        End If
    End Sub

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
        SerialPort1.Write(ChrW(100))
        Timer1.Enabled = False
        Button_Connect.Enabled = True
        Button_Disconnect.Enabled = False
        ComboBox_Comport.Enabled = True
        SerialPort1.Close()

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        If SerialPort1.IsOpen Then
            SerialPort1.Write(ChrW(10))
        End If
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        If SerialPort1.IsOpen Then
            SerialPort1.Write(ChrW(20))
        End If
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        If SerialPort1.IsOpen Then
            SerialPort1.Write(ChrW(30))
        End If
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        If SerialPort1.IsOpen Then
            SerialPort1.Write(ChrW(40))
        End If
    End Sub
End Class
