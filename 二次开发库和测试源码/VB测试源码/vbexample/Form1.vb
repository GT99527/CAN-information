Public Class Form1
    Private ret As Integer
    Private canisopen As Byte

    Private Sub Label1_Click(sender As Object, e As EventArgs) Handles Label1.Click

    End Sub

    Private Sub ComboBox4_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox4.SelectedIndexChanged

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If canisopen = 0 Then
            ret = ucandll.ucanbusdll.CAN_OpenDevice(ComboBox1.SelectedIndex)
            If ret = 0 Then
                canisopen = 1
                Button1.Text = "关闭"

                Dim tmp As Integer
                Dim tm1, tm2 As Double
                tm1 = Val(ComboBox2.Text)
                tmp = tm1 * 1000
                Debug.Print(tm1)
                Debug.Print(ComboBox2.Text)
                Dim cancfg As ucandll.Can_Config
                cancfg = New ucandll.Can_Config()
                cancfg.model = ComboBox3.SelectedIndex
                Debug.Print(cancfg.model)
                cancfg.configs = 0        '初值
                cancfg.configs += &H0001  '接通内部匹配电阻
                cancfg.configs += &H0002  '开启离线唤醒模式
                cancfg.configs += &H0004  '开启自动重传
                cancfg.baudrate = tmp
                Debug.Print(tmp)
                ucandll.ucanbusdll.CAN_Init(ComboBox1.SelectedIndex, cancfg)
                tm2 = cancfg.baudrate
                Debug.Print(tm2)
            End If
        Else
            ucandll.ucanbusdll.CAN_CloseDevice(ComboBox1.SelectedIndex)
            canisopen = 0
            Button1.Text = "打开"
        End If


    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        If canisopen = 0 Then
            Return
        End If

        Dim cmsg As ucandll.Can_Msg
        cmsg = New ucandll.Can_Msg()
        cmsg.data = New Byte(7) {}
        cmsg.ID = Convert.ToUInt32(TextBox1.Text, 16)
        If ComboBox4.SelectedIndex = 1 Then
            cmsg.ExternFlag = 1
        Else cmsg.ExternFlag = 0
        End If

        If ComboBox5.SelectedIndex = 1 Then
            cmsg.RemoteFlag = 1
        Else cmsg.RemoteFlag = 0
        End If
        cmsg.DataLen = Val(dtlenth.Text)
        If cmsg.DataLen > 8 Then cmsg.DataLen = 8
        Dim candt As TextBox
        candt = dt1
        For i As Integer = 0 To cmsg.DataLen - 1
            cmsg.data(i) = Convert.ToByte(candt.Text, 16)
            If i < 7 Then
                candt = DirectCast(Me.GetNextControl(candt, True), TextBox)
            End If
        Next
        ucandll.ucanbusdll.CAN_Transmit(ComboBox1.SelectedIndex, cmsg, 1, 100)

    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick

        If canisopen = 0 Then
            Return
        End If

        Dim cmsg As New ucandll.Can_Msg()
        Dim mLen As Int32

        mLen = ucandll.ucanbusdll.CAN_Receive(ComboBox1.SelectedIndex, cmsg, 1, 100)
        If mLen <= 0 Then
            Return
        End If

        Dim lines(5) As String
        Dim strs As String
        lines(0) = Convert.ToString(cmsg.ID, 16)
        lines(1) = Convert.ToString(cmsg.TimeStamp, 10)
        If cmsg.ExternFlag = 1 Then
            lines(2) = "扩展帧"
        Else
            lines(2) = "标准帧"
        End If

        If cmsg.RemoteFlag = 1 Then
            lines(3) = "远程帧"
        Else
            lines(3) = "数据帧"
        End If
        lines(4) = Convert.ToString(cmsg.DataLen, 10)

        For i As Integer = 0 To cmsg.DataLen - 1
            Dim lens As Byte
            strs = Hex(cmsg.data(i))
            lens = Len(strs)
            If Len(strs) < 2 Then strs = "0" & strs
            lines(5) += strs + " "
        Next

        DataGridView1.Rows.Add(lines)

    End Sub


    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load

        ComboBox2.SelectedIndex = 0
        ComboBox3.SelectedIndex = 0
        ComboBox4.SelectedIndex = 0
        ComboBox5.SelectedIndex = 0
        Dim drives As Integer
        drives = ucandll.ucanbusdll.CAN_ScanDevice()
        If drives > 0 Then
            Dim i As Integer
            For i = 0 To drives - 1
                ComboBox1.Items.Add(i)
            Next
            ComboBox1.SelectedIndex = 0
        End If
        Timer1.Enabled = True
    End Sub

End Class
