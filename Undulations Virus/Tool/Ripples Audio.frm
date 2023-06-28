VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Ripples Audio"
   ClientHeight    =   7692
   ClientLeft      =   36
   ClientTop       =   384
   ClientWidth     =   13548
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   7692
   ScaleWidth      =   13548
   StartUpPosition =   2  '屏幕中心
   Begin VB.CommandButton Command4 
      Caption         =   "复制"
      Height          =   612
      Left            =   11640
      TabIndex        =   30
      Top             =   4320
      Width           =   1812
   End
   Begin VB.Frame Frame6 
      BackColor       =   &H00FFFFFF&
      Caption         =   "批量生成"
      Height          =   2652
      Left            =   0
      TabIndex        =   17
      Top             =   5040
      Width           =   6492
      Begin VB.CheckBox Check1 
         BackColor       =   &H00FFFFFF&
         Caption         =   "去除相邻重复"
         Height          =   372
         Left            =   3720
         TabIndex        =   29
         Top             =   2040
         Width           =   1932
      End
      Begin VB.Frame Frame3 
         BackColor       =   &H00FFFFFF&
         Caption         =   "数组长度"
         Height          =   972
         Left            =   1560
         TabIndex        =   27
         Top             =   1440
         Width           =   1812
         Begin VB.TextBox Text6 
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   13.8
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   396
            Left            =   120
            TabIndex        =   28
            Text            =   "5"
            Top             =   360
            Width           =   1452
         End
      End
      Begin VB.Frame Frame5 
         BackColor       =   &H00FFFFFF&
         Caption         =   "生成数量"
         Height          =   972
         Left            =   1560
         TabIndex        =   25
         Top             =   360
         Width           =   1812
         Begin VB.TextBox Text9 
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   13.8
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   120
            TabIndex        =   26
            Text            =   "40"
            Top             =   360
            Width           =   1452
         End
      End
      Begin VB.Frame Frame4 
         BackColor       =   &H00FFFFFF&
         Caption         =   "频率"
         Height          =   1452
         Left            =   3480
         TabIndex        =   22
         Top             =   360
         Width           =   2772
         Begin VB.TextBox Text7 
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   13.8
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   240
            TabIndex        =   24
            Text            =   "22050"
            Top             =   360
            Width           =   2292
         End
         Begin VB.TextBox Text8 
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   13.8
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   372
            Left            =   240
            TabIndex        =   23
            Text            =   "22050 * 100"
            Top             =   840
            Width           =   2292
         End
      End
      Begin VB.Frame Frame1 
         BackColor       =   &H00FFFFFF&
         Caption         =   "注释设置"
         Height          =   2052
         Left            =   120
         TabIndex        =   18
         Top             =   360
         Width           =   1212
         Begin VB.OptionButton Option1 
            BackColor       =   &H00FFFFFF&
            Caption         =   "音谱"
            Height          =   372
            Left            =   240
            TabIndex        =   21
            Top             =   480
            Width           =   732
         End
         Begin VB.OptionButton Option2 
            BackColor       =   &H00FFFFFF&
            Caption         =   "序号"
            Height          =   372
            Left            =   240
            TabIndex        =   20
            Top             =   960
            Width           =   732
         End
         Begin VB.OptionButton Option3 
            BackColor       =   &H00FFFFFF&
            Caption         =   "无"
            Height          =   372
            Left            =   240
            TabIndex        =   19
            Top             =   1440
            Value           =   -1  'True
            Width           =   732
         End
      End
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H00FFFFFF&
      Caption         =   "音高范围"
      Height          =   972
      Left            =   6600
      TabIndex        =   13
      Top             =   5040
      Width           =   1812
      Begin VB.TextBox Text4 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   13.8
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   396
         Left            =   1080
         TabIndex        =   15
         Text            =   "9"
         Top             =   360
         Width           =   492
      End
      Begin VB.TextBox Text5 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   13.8
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   396
         Left            =   240
         TabIndex        =   14
         Text            =   "2"
         Top             =   360
         Width           =   492
      End
      Begin VB.Label Label1 
         AutoSize        =   -1  'True
         BackStyle       =   0  'Transparent
         Caption         =   "→"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   240
         Left            =   790
         TabIndex        =   16
         Top             =   450
         Width           =   252
      End
   End
   Begin VB.CommandButton Command3 
      Caption         =   "批量生成音频数组"
      Height          =   612
      Left            =   6600
      TabIndex        =   12
      Top             =   7080
      Width           =   2412
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   30
      Left            =   8520
      Top             =   5160
   End
   Begin VB.CommandButton Command2 
      Caption         =   "恢复默认值"
      Height          =   612
      Left            =   9720
      TabIndex        =   11
      Top             =   4320
      Width           =   1692
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   7
      Left            =   8400
      TabIndex        =   10
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   6
      Left            =   7200
      TabIndex        =   9
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   5
      Left            =   6000
      TabIndex        =   8
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   4
      Left            =   4800
      TabIndex        =   7
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   3
      Left            =   3600
      TabIndex        =   6
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   2
      Left            =   2400
      TabIndex        =   5
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   1
      Left            =   1200
      TabIndex        =   4
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text3 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   16.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   444
      Index           =   0
      Left            =   0
      TabIndex        =   3
      Top             =   4440
      Width           =   1092
   End
   Begin VB.TextBox Text2 
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   22.2
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   3372
      Left            =   0
      Locked          =   -1  'True
      MultiLine       =   -1  'True
      ScrollBars      =   3  'Both
      TabIndex        =   2
      Top             =   840
      Width           =   13452
   End
   Begin VB.TextBox Text1 
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   24
         Charset         =   134
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   732
      Left            =   0
      TabIndex        =   1
      Top             =   0
      Width           =   13452
   End
   Begin VB.CommandButton Command1 
      Caption         =   "转换音频数组"
      Height          =   612
      Left            =   6600
      TabIndex        =   0
      Top             =   6360
      Width           =   2412
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
Dim add As Integer


Private Sub Command1_Click()
    Randomize
    Dim i As Integer
    Dim j As Integer
    Dim rand As Integer
    
    Dim arr(0 To 7)
    
    For j = 0 To 7
        arr(j) = Text3(j).Text
    Next j
    
    For i = 1 To Len(Text1.Text)
    
        rand = Int(Rnd * (Text4.Text - Text5.Text + 1)) + Text5.Text

        If i = 1 Then
            Text2.Text = "{" & "{" & arr(Mid(Text1.Text, i, 1) - 1) & "," & rand & "}"
        Else
            Text2.Text = Text2.Text + "," & "{" & arr(Mid(Text1.Text, i, 1) - 1) & "," & rand & "}"
        End If
    Next i
    
    If Len(Text1.Text) <> 0 Then
        Text2.Text = Text2.Text & "}"
    End If
    
End Sub

Private Sub Command2_Click()
 Call Form_Load
End Sub


Private Sub Command3_Click()
    add = 0
    Text2.Text = ""
    Timer1.Enabled = True
    Me.Enabled = False
End Sub


Private Sub Command4_Click()
Clipboard.Clear
Clipboard.SetText Text2.Text
End Sub



Private Sub Form_Load()
Dim mr()
mr = Array(526, 496, 443, 394, 352, 332, 296, 264)
    Dim i As Integer
    For i = 0 To 7
       Text3(i).Text = mr(i)
    Next i
End Sub


Private Sub Timer1_Timer()
    Randomize
    Dim str As String
    Dim str2 As String
    Dim i As Integer
    Dim j As Integer
    Dim k As Integer
    Dim a As String
    Dim b As String
    Dim rand As String
    Dim temp As String
    Dim temp2 As String
    add = add + 1
    
    For k = 1 To Text6.Text

        temp = Int(Rnd * (8 - 1 + 1)) + 1
        
        If Check1.Value Then
            Do While temp = temp2
                temp = Int(Rnd * (8 - 1 + 1)) + 1
            Loop
            temp2 = temp
        End If
        str = str & temp
    Next k
    
    Text1.Text = str

    Dim arr(0 To 7)
    
    For j = 0 To 7
        arr(j) = Text3(j).Text
    Next j
    
    a = Text7.Text
    b = Text8.Text
    
    For i = 1 To Len(str)
    
        rand = Int(Rnd * (Text4.Text - Text5.Text + 1)) + Text5.Text
        
        If i = 1 Then
            str2 = "{" & a & "," & b & ",{" & "{" & arr(Mid(str, i, 1) - 1) & "," & rand & "}"
        Else
           str2 = str2 + "," & "{" & arr(Mid(str, i, 1) - 1) & "," & rand & "}"
        End If
    Next i
    If Len(str) <> 0 Then
       str2 = str2 & "}" & "}" & IIf(add <> 40, ",", "")
    End If
    
    
    If (Option1.Value = True) Then
        Text2.Text = Text2.Text & str2 & " //" & str & vbCrLf
    ElseIf (Option2.Value = True) Then
        Text2.Text = Text2.Text & str2 & " //" & add & vbCrLf
    Else
        Text2.Text = Text2.Text & str2 & vbCrLf
    End If
    
    If (add = Text9.Text) Then
        Timer1.Enabled = False
        Me.Enabled = True
        MsgBox "生成完成", vbInformation, Me.Caption
    End If
    
End Sub
