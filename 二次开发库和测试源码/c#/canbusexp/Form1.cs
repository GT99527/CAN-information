using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ucanbus;
using System.Runtime.InteropServices;

//using System.Threading;

namespace canbusexp
{
    public partial class Form1 : Form
    {
        UInt32 devnmb;
        int canopened;
      //  private Timer rectimer;
      //  private AutoResetEvent RecEvent;
       // private TimerCallback RecTimerDelegate;
        public Form1()
        {
            int i,itm;
            string str;
            InitializeComponent();
            itm= ucanbusdll.CAN_ScanDevice();
            Console.Write("CAN_ScanDevice = {0}", itm);
            if (itm > 0)
            {
                for (i = 0; i < itm; i++)
                {
                    str=string.Format("通道{0}",i);
                    this.comboBox1.Items.Add(str);
                }
                this.comboBox1.SelectedIndex = 0;
            }
            this.comboBox2.SelectedIndex = 0;
            this.comboBox3.SelectedIndex = 0;
            this.comboBox4.SelectedIndex = 0;
            this.comboBox5.SelectedIndex = 0;
        }

        byte findhex_formstr(ref byte idx, byte len, String str)
        {
            char dain;
            while (idx < len)
            {
                dain = str[idx];
                if ((dain >= '0') && (dain <= '9')) return ((byte)(dain - '0'));
                else if ((dain >= 'a') && (dain <= 'f')) return ((byte)(dain + 10 - 'a'));
                else if ((dain >= 'A') && (dain <= 'F')) return ((byte)(dain + 10 - 'F'));
                else (idx)++;
            }
            return 0xff;
        }

        byte str2u8(byte[] data, String str)
        {
            byte ret;
            int da, db;
            byte i = 0,j = 0;
            byte[] buf=new byte[8];
            ret = (byte)str.Length;

            while (i < ret)
            {
                da = findhex_formstr(ref i, ret, str);
                if (da == 0xff) da = 0;
                i++;
                db = findhex_formstr(ref i, ret, str);
                if (db == 0xff) { buf[j] = (byte)(da); j++; }
                else { buf[j] = (byte)((da << 4) | db); j++; }
                i++;
                if (j >= 8) break;
            }
            buf.CopyTo(data,0);
            return j;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            devnmb = (UInt32)comboBox1.SelectedIndex;
            Console.Write("SelectedIndex = {0}", devnmb);

            if (ucanbusdll.CAN_OpenDevice((UInt32)devnmb) != 0)
            {
                MessageBox.Show("Open device fault!", "Error!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }

            winitcan();
            canopened = 1;
            MessageBox.Show("Open device success!", "success!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            timer1.Start();
        }
        private void winitcan()
        {
            int rtn;
            uint tmp;
            double tm2;
            Can_Config cancfg;
            cancfg = new Can_Config();
            cancfg.model = (uint)comboBox2.SelectedIndex;
            tmp = Convert.ToUInt32(comboBox5.Text, 10);
            cancfg.baudrate = tmp*1000;
            cancfg.configs = 0;
            cancfg.configs |= 0x0001;  //接通内部匹配电阻
            cancfg.configs |= 0x0002;  //开启离线唤醒模式
            cancfg.configs |= 0x0004;  //开启自动重传
            rtn = ucanbusdll.CAN_Init(devnmb,ref cancfg);
            tm2 = cancfg.baudrate / 1000.0;
            Console.Write("real baudrate is = {0}\r\n", tm2);
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if (canopened == 0) return;
            ucanbusdll.CAN_CloseDevice(devnmb);
            canopened = 0;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            canopened = 0;
            Console.Write("canopened = 0");
        }
        private void button3_Click(object sender, EventArgs e)
        {
            if (canopened == 0) return;
            uint i = 0;
            IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(Can_Msg)) * 100);
            Can_Msg[] cmsg = new Can_Msg[100];
            for (i = 0; i < 100; i++) { cmsg[i] = new Can_Msg(); }
            for (i = 0; i < 10; i++)
            {
                cmsg[i].data = new byte[8];
                cmsg[i].ID = Convert.ToUInt32(textBox1.Text, 16) + i;
                cmsg[i].DataLen = str2u8(cmsg[i].data, textBox2.Text);
                cmsg[i].ExternFlag = (byte)this.comboBox3.SelectedIndex;
                cmsg[i].RemoteFlag = (byte)this.comboBox4.SelectedIndex;
                IntPtr ptr = (IntPtr)((UInt32)pt + i * Marshal.SizeOf(typeof(Can_Msg)));
                Marshal.StructureToPtr(cmsg[i], ptr, false);
            }
            ucanbusdll.CAN_Transmit(devnmb, pt, 10, 100);
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (canopened == 0) return;
            int lenth, i, j;
            String[] str = new String[5];
            IntPtr pt = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(Can_Msg)) * 100);
            Can_Msg[] rxmsg = new Can_Msg[100];
            lenth = ucanbusdll.CAN_Receive(devnmb,pt, 10, 100);
            for (i = 0; i < lenth; i++)
            {
                IntPtr ptr = (IntPtr)((UInt32)pt + i * Marshal.SizeOf(typeof(Can_Msg)));
                rxmsg[i] = (Can_Msg)Marshal.PtrToStructure(ptr, typeof(Can_Msg));
                Console.Write("receive ID:{0}  ", rxmsg[i].ID);

                str[0] = Convert.ToString(rxmsg[i].ID, 16);
                str[1] = Convert.ToString(rxmsg[i].TimeStamp, 10);
                if (rxmsg[i].ExternFlag == 1) str[2] = "扩展帧";
                else str[2] = "标准帧";
                if (rxmsg[i].RemoteFlag == 1) str[3] = "远程帧";
                else str[3] = "数据帧";
                str[4] = "";
                for (j = 0; j < rxmsg[i].DataLen; j++)
                {
                    str[4] += rxmsg[i].data[j].ToString("x2") + " ";
                }
                dataGridView1.Rows.Add(str);
            }
            Marshal.FreeHGlobal(pt);
        }
    }
}
