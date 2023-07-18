<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。  
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.ComboBox2 = New System.Windows.Forms.ComboBox()
        Me.ComboBox3 = New System.Windows.Forms.ComboBox()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.ComboBox4 = New System.Windows.Forms.ComboBox()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.ComboBox5 = New System.Windows.Forms.ComboBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.TextBox1 = New System.Windows.Forms.TextBox()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.DataGridView1 = New System.Windows.Forms.DataGridView()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.dt1 = New System.Windows.Forms.TextBox()
        Me.dt2 = New System.Windows.Forms.TextBox()
        Me.dt3 = New System.Windows.Forms.TextBox()
        Me.dt4 = New System.Windows.Forms.TextBox()
        Me.dt5 = New System.Windows.Forms.TextBox()
        Me.dt6 = New System.Windows.Forms.TextBox()
        Me.dt7 = New System.Windows.Forms.TextBox()
        Me.dt8 = New System.Windows.Forms.TextBox()
        Me.dtlenth = New System.Windows.Forms.TextBox()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.ID = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.time = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.style = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.form = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.dtlen = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.data = New System.Windows.Forms.DataGridViewTextBoxColumn()
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(39, 35)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(29, 12)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "通道"
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Location = New System.Drawing.Point(74, 27)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(68, 20)
        Me.ComboBox1.TabIndex = 1
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(165, 34)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(41, 12)
        Me.Label2.TabIndex = 2
        Me.Label2.Text = "波特率"
        '
        'ComboBox2
        '
        Me.ComboBox2.DisplayMember = "0"
        Me.ComboBox2.FormattingEnabled = True
        Me.ComboBox2.Items.AddRange(New Object() {"1000", "800", "666", "500", "250", "200", "125", "100", "50"})
        Me.ComboBox2.Location = New System.Drawing.Point(211, 29)
        Me.ComboBox2.Name = "ComboBox2"
        Me.ComboBox2.Size = New System.Drawing.Size(68, 20)
        Me.ComboBox2.TabIndex = 3
        Me.ComboBox2.ValueMember = "0"
        '
        'ComboBox3
        '
        Me.ComboBox3.DisplayMember = "0"
        Me.ComboBox3.FormattingEnabled = True
        Me.ComboBox3.Items.AddRange(New Object() {"正常模式", "环回模式", "静默模式", "静默环回模式"})
        Me.ComboBox3.Location = New System.Drawing.Point(364, 29)
        Me.ComboBox3.Name = "ComboBox3"
        Me.ComboBox3.Size = New System.Drawing.Size(82, 20)
        Me.ComboBox3.TabIndex = 5
        Me.ComboBox3.ValueMember = "0"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(305, 34)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(53, 12)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "工作模式"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(471, 27)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 6
        Me.Button1.Text = "打开"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'ComboBox4
        '
        Me.ComboBox4.FormattingEnabled = True
        Me.ComboBox4.Items.AddRange(New Object() {"标准帧", "扩展帧"})
        Me.ComboBox4.Location = New System.Drawing.Point(74, 66)
        Me.ComboBox4.Name = "ComboBox4"
        Me.ComboBox4.Size = New System.Drawing.Size(68, 20)
        Me.ComboBox4.TabIndex = 9
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(164, 69)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(41, 12)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "帧格式"
        '
        'ComboBox5
        '
        Me.ComboBox5.FormattingEnabled = True
        Me.ComboBox5.Items.AddRange(New Object() {"数据帧", "远程帧"})
        Me.ComboBox5.Location = New System.Drawing.Point(211, 66)
        Me.ComboBox5.Name = "ComboBox5"
        Me.ComboBox5.Size = New System.Drawing.Size(68, 20)
        Me.ComboBox5.TabIndex = 11
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(27, 69)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(41, 12)
        Me.Label5.TabIndex = 10
        Me.Label5.Text = "帧类型"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(317, 69)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(29, 12)
        Me.Label6.TabIndex = 12
        Me.Label6.Text = "帧ID"
        '
        'TextBox1
        '
        Me.TextBox1.Location = New System.Drawing.Point(364, 64)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(68, 21)
        Me.TextBox1.TabIndex = 13
        Me.TextBox1.Text = "111"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(164, 106)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(41, 12)
        Me.Label7.TabIndex = 14
        Me.Label7.Text = "帧数据"
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(471, 99)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(75, 23)
        Me.Button3.TabIndex = 16
        Me.Button3.Text = "发送"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'DataGridView1
        '
        Me.DataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.DataGridView1.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.ID, Me.time, Me.style, Me.form, Me.dtlen, Me.data})
        Me.DataGridView1.Location = New System.Drawing.Point(4, 144)
        Me.DataGridView1.Name = "DataGridView1"
        Me.DataGridView1.RowTemplate.Height = 23
        Me.DataGridView1.Size = New System.Drawing.Size(670, 341)
        Me.DataGridView1.TabIndex = 17
        '
        'Timer1
        '
        '
        'dt1
        '
        Me.dt1.Location = New System.Drawing.Point(211, 101)
        Me.dt1.Name = "dt1"
        Me.dt1.Size = New System.Drawing.Size(21, 21)
        Me.dt1.TabIndex = 18
        Me.dt1.Text = "01"
        '
        'dt2
        '
        Me.dt2.Location = New System.Drawing.Point(238, 101)
        Me.dt2.Name = "dt2"
        Me.dt2.Size = New System.Drawing.Size(21, 21)
        Me.dt2.TabIndex = 19
        Me.dt2.Text = "02"
        '
        'dt3
        '
        Me.dt3.Location = New System.Drawing.Point(265, 101)
        Me.dt3.Name = "dt3"
        Me.dt3.Size = New System.Drawing.Size(21, 21)
        Me.dt3.TabIndex = 20
        Me.dt3.Text = "03"
        '
        'dt4
        '
        Me.dt4.Location = New System.Drawing.Point(292, 101)
        Me.dt4.Name = "dt4"
        Me.dt4.Size = New System.Drawing.Size(21, 21)
        Me.dt4.TabIndex = 21
        Me.dt4.Text = "04"
        '
        'dt5
        '
        Me.dt5.Location = New System.Drawing.Point(319, 101)
        Me.dt5.Name = "dt5"
        Me.dt5.Size = New System.Drawing.Size(21, 21)
        Me.dt5.TabIndex = 22
        Me.dt5.Text = "05"
        '
        'dt6
        '
        Me.dt6.Location = New System.Drawing.Point(346, 101)
        Me.dt6.Name = "dt6"
        Me.dt6.Size = New System.Drawing.Size(21, 21)
        Me.dt6.TabIndex = 23
        Me.dt6.Text = "06"
        '
        'dt7
        '
        Me.dt7.Location = New System.Drawing.Point(373, 101)
        Me.dt7.Name = "dt7"
        Me.dt7.Size = New System.Drawing.Size(21, 21)
        Me.dt7.TabIndex = 24
        Me.dt7.Text = "07"
        '
        'dt8
        '
        Me.dt8.Location = New System.Drawing.Point(400, 101)
        Me.dt8.Name = "dt8"
        Me.dt8.Size = New System.Drawing.Size(21, 21)
        Me.dt8.TabIndex = 25
        Me.dt8.Text = "08"
        '
        'dtlenth
        '
        Me.dtlenth.Location = New System.Drawing.Point(74, 100)
        Me.dtlenth.Name = "dtlenth"
        Me.dtlenth.Size = New System.Drawing.Size(68, 21)
        Me.dtlenth.TabIndex = 27
        Me.dtlenth.Text = "08"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(15, 104)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(53, 12)
        Me.Label8.TabIndex = 26
        Me.Label8.Text = "数据长度"
        '
        'ID
        '
        Me.ID.HeaderText = "帧ID"
        Me.ID.Name = "ID"
        Me.ID.Width = 80
        '
        'time
        '
        Me.time.HeaderText = "时间戳"
        Me.time.Name = "time"
        Me.time.Width = 80
        '
        'style
        '
        Me.style.HeaderText = "帧类型"
        Me.style.Name = "style"
        Me.style.Width = 80
        '
        'form
        '
        Me.form.HeaderText = "帧格式"
        Me.form.Name = "form"
        Me.form.Width = 80
        '
        'dtlen
        '
        Me.dtlen.HeaderText = "数据长度"
        Me.dtlen.Name = "dtlen"
        Me.dtlen.Width = 80
        '
        'data
        '
        Me.data.HeaderText = "数据"
        Me.data.Name = "data"
        Me.data.Width = 220
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(677, 497)
        Me.Controls.Add(Me.dtlenth)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.dt8)
        Me.Controls.Add(Me.dt7)
        Me.Controls.Add(Me.dt6)
        Me.Controls.Add(Me.dt5)
        Me.Controls.Add(Me.dt4)
        Me.Controls.Add(Me.dt3)
        Me.Controls.Add(Me.dt2)
        Me.Controls.Add(Me.dt1)
        Me.Controls.Add(Me.DataGridView1)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.ComboBox5)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.ComboBox4)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.ComboBox3)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.ComboBox2)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.ComboBox1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Form1"
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents ComboBox1 As ComboBox
    Friend WithEvents Label2 As Label
    Friend WithEvents ComboBox2 As ComboBox
    Friend WithEvents ComboBox3 As ComboBox
    Friend WithEvents Label3 As Label
    Friend WithEvents Button1 As Button
    Friend WithEvents ComboBox4 As ComboBox
    Friend WithEvents Label4 As Label
    Friend WithEvents ComboBox5 As ComboBox
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents Label7 As Label
    Friend WithEvents Button3 As Button
    Friend WithEvents DataGridView1 As DataGridView
    Friend WithEvents Timer1 As Timer
    Friend WithEvents dt1 As TextBox
    Friend WithEvents dt2 As TextBox
    Friend WithEvents dt3 As TextBox
    Friend WithEvents dt4 As TextBox
    Friend WithEvents dt5 As TextBox
    Friend WithEvents dt6 As TextBox
    Friend WithEvents dt7 As TextBox
    Friend WithEvents dt8 As TextBox
    Friend WithEvents dtlenth As TextBox
    Friend WithEvents Label8 As Label
    Friend WithEvents ID As DataGridViewTextBoxColumn
    Friend WithEvents time As DataGridViewTextBoxColumn
    Friend WithEvents style As DataGridViewTextBoxColumn
    Friend WithEvents form As DataGridViewTextBoxColumn
    Friend WithEvents dtlen As DataGridViewTextBoxColumn
    Friend WithEvents data As DataGridViewTextBoxColumn
End Class
