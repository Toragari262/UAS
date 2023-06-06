Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Dim ports As String() = IO.Ports.SerialPort.GetPortNames()
        Dim port As String
        For Each port In ports
            ListBox1.Items.Add(port)
        Next port
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Label1.Visible = True
        Try
            SerialPort1.PortName = ListBox1.SelectedItem
            SerialPort1.BaudRate = 9600
            SerialPort1.Open()
            Label1.Text = ListBox1.SelectedItem & " is Connected"
        Catch ex As Exception
            Label1.Text = ListBox1.SelectedItem & " is not Connected"
        End Try
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        If SerialPort1.IsOpen And Double.TryParse(TextBox1.Text, Nothing) Then
            Dim value As Double = Double.Parse(TextBox1.Text)
            If value <= 255 Then
                SerialPort1.WriteLine(value.ToString())
            ElseIf value > 255 Then
                MessageBox.Show("Angka lebih dari 8 bit")
            End If
        ElseIf String.IsNullOrEmpty(TextBox1.Text) And SerialPort1.IsOpen Then
            MessageBox.Show("Textbox masih kosong!")
        ElseIf TextBox1.Text = "  masukan angka" And SerialPort1.IsOpen Then
            MessageBox.Show("masukan angka")
        ElseIf SerialPort1.IsOpen = False Then
            MessageBox.Show("Serial port is not connected")
        End If
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("256")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("257")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("259")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("260")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("261")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("262")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles Button9.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("263")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button10_Click(sender As Object, e As EventArgs) Handles Button10.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("264")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub Button11_Click(sender As Object, e As EventArgs) Handles Button11.Click
        If SerialPort1.IsOpen Then
            SerialPort1.WriteLine("258")
        Else
            MessageBox.Show("serial port is not connected")
        End If
    End Sub

    Private Sub TextBox1_Click(sender As Object, e As EventArgs) Handles TextBox1.Click
        TextBox1.Clear()
    End Sub
End Class
