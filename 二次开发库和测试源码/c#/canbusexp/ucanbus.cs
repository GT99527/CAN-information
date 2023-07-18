using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace ucanbus
{
     
    [Flags]
     public enum canStatus:int
    {
        
        STATUS_OK       = 0,
        STATUS_ERR      = -1,
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Can_Msg
    {
        public uint ID;
        public uint TimeStamp;
        public byte FrameType;
        public byte DataLen;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public byte[] data;
        public byte ExternFlag;
        public byte RemoteFlag;
        public byte BusSatus;
        public byte ErrSatus;
        public byte TECounter;
        public byte RECounter;
    }

    public struct Can_Config
    {
        public uint baudrate;
        public uint configs;
        public uint model;
    }
   
    public static class ucanbusdll 
    {
         
        [DllImport("ucanbus.dll", EntryPoint = "CAN_ScanDevice")]
        public static extern int CAN_ScanDevice( );

        [DllImport("ucanbus.dll", EntryPoint = "CAN_OpenDevice")]
        public static extern int CAN_OpenDevice( UInt32 devNum);

        [DllImport("ucanbus.dll", EntryPoint = "CAN_CloseDevice")]
        public static extern int CAN_CloseDevice(UInt32 devNum);

        [DllImport("ucanbus.dll", EntryPoint = "CAN_Init")]
        public static extern int CAN_Init(UInt32 devNum, ref Can_Config InitConfig);

        [DllImport("ucanbus.dll", EntryPoint = "CAN_Reset")]
        public static extern int CAN_Reset(UInt32 devNum);

        [DllImport("ucanbus.dll", EntryPoint = "CAN_SetFilter")]
        public static extern int CAN_SetFilter(
            UInt32 devNum,
            byte namber,
            byte type,
            UInt32 ftID,
            UInt32 ftMask,
            byte enable);


        [DllImport("ucanbus.dll", EntryPoint = "CAN_GetReceiveNum")]
        public static extern int CAN_GetReceiveNum(UInt32 devNum);


        [DllImport("ucanbus.dll", EntryPoint = "CAN_Transmit")]
        public static extern int CAN_Transmit(
            UInt32 devNum,
            IntPtr Receive,
           // ref Can_Msg Send,
            UInt16 length,
            UInt32 timeout);

        [DllImport("ucanbus.dll", EntryPoint = "CAN_Receive")]
        public static extern int CAN_Receive(
            UInt32 devNum,
            IntPtr Receive,
            UInt16 length,
            UInt32 timeout);
    }
}
