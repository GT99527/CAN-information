Imports System.Collections.Generic
Imports System.Text
Imports System.Runtime.InteropServices

Namespace ucandll
    Public Structure Can_Msg
        Public ID As UInteger
        Public TimeStamp As UInteger
        Public FrameType As Byte
        Public DataLen As Byte
        <MarshalAs(UnmanagedType.ByValArray, SizeConst:=8)>
        Public data As Byte()
        Public ExternFlag As Byte
        Public RemoteFlag As Byte
        Public BusSatus As Byte
        Public ErrSatus As Byte
        Public TECounter As Byte
        Public RECounter As Byte
    End Structure

    Public Structure Can_Config
        Public baudrate As UInteger
        Public configs As UInteger
        Public model As UInteger
    End Structure



    Public Class ucanbusdll
        Private Sub New()
        End Sub

        <DllImport("ucanbus.dll", EntryPoint:="CAN_ScanDevice")>
        Public Shared Function CAN_ScanDevice() As Int32
        End Function

        <DllImport("ucanbus.dll", EntryPoint:="CAN_OpenDevice")>
        Public Shared Function CAN_OpenDevice(ByVal devNum As UInt32) As Int32
        End Function


        <DllImport("ucanbus.dll", EntryPoint:="CAN_CloseDevice")>
        Public Shared Function CAN_CloseDevice(ByVal devNum As UInt32) As Int32
        End Function


        <DllImport("ucanbus.dll", EntryPoint:="CAN_Init")>
        Public Shared Function CAN_Init(ByVal devNum As UInt32, ByRef InitConfig As Can_Config) As Int32
        End Function


        <DllImport("ucanbus.dll", EntryPoint:="CAN_Reset")>
        Public Shared Function CAN_Reset(ByVal devNum As UInt32) As Int32
        End Function

        <DllImport("ucanbus.dll", EntryPoint:="CAN_SetFilter")>
        Public Shared Function CAN_SetFilter(ByVal devNum As UInt32, ByVal namber As Byte, ByVal type As Byte, ByVal ftID As UInt32, ByVal ftMask As UInt32, ByVal enable As Byte) As Int32
        End Function


        <DllImport("ucanbus.dll", EntryPoint:="CAN_GetReceiveNum")>
        Public Shared Function CAN_GetReceiveNum(ByVal devNum As UInt32) As Int32
        End Function


        <DllImport("ucanbus.dll", EntryPoint:="CAN_Transmit")>
        Public Shared Function CAN_Transmit(ByVal devNum As UInt32, ByRef cmsg As Can_Msg, ByVal length As UInt32, ByVal timeout As UInt32) As Int32
        End Function

        <DllImport("ucanbus.dll", EntryPoint:="CAN_Receive")>
        Public Shared Function CAN_Receive(ByVal devNum As UInt32, ByRef cmsg As Can_Msg, ByVal length As UInt32, ByVal timeout As UInt32) As Int32
        End Function

    End Class



End Namespace
