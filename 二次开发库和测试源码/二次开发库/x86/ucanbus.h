
#ifndef CANBUS_H
#define CANBUS_H

#if defined(_WIN32) || defined(__CYGWIN__) || defined(_WIN32_WCE)
#define LIBUSB_CALL WINAPI
#else
#define LIBUSB_CALL
#endif

typedef  struct  _Can_Msg {
    unsigned int    ID;
    unsigned int    TimeStamp;
    char            FrameType;
    char            DataLen;
    char	        Data[8];
    char	        ExternFlag;
    char	        RemoteFlag;
    char            BusSatus;
    char            ErrSatus;
    char            TECounter;
    char            RECounter;
}Can_Msg, *P_Can_Msg;

typedef struct _Can_Status {
    char            BusSatus;
    char            ErrSatus;
    char            TECounter;
    char            RECounter;
}Can_Status, *P_Can_Status;

typedef struct _Can_Config {
    unsigned int       baudrate;
    unsigned int       configs;
    unsigned int       model;
}Can_Config, *P_Can_Config;

#ifdef __cplusplus
extern "C" {
#endif

int __stdcall   Reg_HotPlug_Func(void(*pfunc)(void));

int __stdcall   CAN_ScanDevice(void);
int __stdcall   CAN_OpenDevice(unsigned int devNum);
int __stdcall   CAN_CloseDevice(unsigned int devNum);
int __stdcall   CAN_Init(unsigned int devNum,P_Can_Config pInitConfig);
int __stdcall   CAN_SetFilter(unsigned int devNum,char namber, char type, unsigned int ftID, unsigned int ftMask, char enable);
int __stdcall   CAN_Reset(unsigned int devNum);
int __stdcall   CAN_GetReceiveNum(unsigned int devNum);
int __stdcall   CAN_Transmit(unsigned int devNum, P_Can_Msg canmsg, unsigned int items, unsigned int timeou);
int __stdcall   CAN_Receive(unsigned int devNum,P_Can_Msg canmsg, int Len, unsigned int timeou);
int __stdcall   CAN_GetStatus(unsigned int devNum,P_Can_Status status);
#ifdef __cplusplus
}
#endif

#endif



