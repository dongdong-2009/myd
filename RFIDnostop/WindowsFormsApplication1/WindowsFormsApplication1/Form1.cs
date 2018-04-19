using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.IO.Ports;
using System.IO;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public int received;
        public int wr, t=0;

        public byte[] rebyte = new byte[8];
        public byte[] du1 = new byte[7];
        public byte[] du2 = new byte[9];
    
        public void readcomset()
        {
            mySerialPort.PortName = combox.Text;
            mySerialPort.BaudRate = comset.baudrate;
            // mySerialPort.Parity = comset.parity;
            if (comset.parity == "无校验")
            {
                mySerialPort.Parity = Parity.None;
            }
            if (comset.parity == "奇校验")
            {
                mySerialPort.Parity = Parity.Odd;
            }
            if (comset.parity == "偶校验")
            {
                mySerialPort.Parity = Parity.Even;
            }
            mySerialPort.DataBits = comset.databit;
            if (comset.stopbit == 1)
            {
                mySerialPort.StopBits = StopBits.One;
            }
            else if (comset.stopbit == 0)
            {
                mySerialPort.StopBits = StopBits.None;
            }
            else if (comset.stopbit == 2)
            {
                mySerialPort.StopBits = StopBits.Two;
            }

        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }
        int i=0;
        //byte[] card_msg_cp = new byte[1024];
        int readbyte;
        byte[] cardtable = new byte[4];
        byte cardcheck;
        byte cardaddr;
        byte cardstate;
        byte state;

        byte[] card_msg_cp = new byte[1024];//定义byte数组,serialPort读取数据 
        string card_state = "";  
        private void mySerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

            Console.Write("read\r\n");
            mySerialPort.Read(card_msg_cp, 0, card_msg_cp.Length);
            for (i = 0; i < card_msg_cp.Length-11; i++)
            {
                if (card_msg_cp[i + 0] == 0xff && card_msg_cp[i + 1] == 0xff && card_msg_cp[i + 2] == 0xff && card_msg_cp[i + 3] == 0xff && card_msg_cp[i + 4] == 0xff)
                {
                    //putchar2(0x01);
                    Console.Write("1\r\n");
                    cardcheck = (byte)(card_msg_cp[i + 5] ^ card_msg_cp[i + 6] ^ card_msg_cp[i + 7] ^ card_msg_cp[i + 8] ^ card_msg_cp[i + 9] ^ card_msg_cp[i + 10]);
                    if (cardcheck == card_msg_cp[i + 11])
                    {
                        //putchar2(0x02);
                        Console.Write("2\r\n");
                        cardaddr = (byte)card_msg_cp[i + 5];
                        cardstate = (byte)card_msg_cp[i + 6];
                        if (cardstate == 0x01)
                        {
                            card_state = "normal";
                        }
                        else
                            card_state = "low vol";
                        Console.Write("card_msg  " + card_msg_cp[i + 7].ToString() + "  " + "tab  " + cardtable[0].ToString() + "\r\n");
                        Console.Write("card_msg1  " + card_msg_cp[i + 8].ToString() + "  " + "tab  " + cardtable[1].ToString() + "\r\n");
                        Console.Write("card_msg2  " + card_msg_cp[i + 9].ToString() + "  " + "tab  " + cardtable[2].ToString() + "\r\n");
                        Console.Write("card_msg3  " + card_msg_cp[i + 10].ToString() + "  " + "tab  " + cardtable[3].ToString() + "\r\n");
                        if (cardtable[0] == card_msg_cp[i + 7] && cardtable[1] == card_msg_cp[i + 8] && cardtable[2] == card_msg_cp[i + 9] && cardtable[3] == card_msg_cp[i + 10])
                        {
                            //putchar2(0x03);
                            //display(0xd0d0);
                            Console.Write("right\r\n");
                            state = 0x01;
                            // listBox1.Items.T
                            // listBox1.Items.Add("card detected: card id:" + card_msg_cp[i + 7].ToString() + card_msg_cp[i + 8].ToString()+card_msg_cp[i+9].ToString()+card_msg_cp[i+10].ToString()+"card_state"+card_state+"addr"+cardaddr.ToString());
                        }
                        else
                        {
                            // display(0x0000);
                            Console.Write("error\r\n");
                            state = 0x02;
                            // listBox1.Items.Remove("card detected: card id:" + card_msg_cp[i + 7].ToString() + card_msg_cp[i + 8].ToString() + card_msg_cp[i + 9].ToString() + card_msg_cp[i + 10].ToString() + "card_state" + card_state + "addr" + cardaddr.ToString()); 
                        }
                    }

                }
                else  if (card_msg_cp[i + 0] == 0x01 && card_msg_cp[i + 1] == 0x01 && card_msg_cp[i + 2] == 0x01 && card_msg_cp[i + 3] == 0x01 && card_msg_cp[i + 4] == 0x01)
                        state = 0x03;

            }


        }

        private void timer1_Tick(object sender, EventArgs e)
        {
           /*
            if (received == 0)
                MessageBox.Show("超时！");
            timer1.Enabled = false;*/
            if(state == 0x01)
                listBox1.Items.Add("card detected: card id: " + card_msg_cp[i + 7].ToString() + card_msg_cp[i + 8].ToString() + card_msg_cp[i + 9].ToString() + card_msg_cp[i + 10].ToString() + "  card_state:" + card_state + "   addr:" + cardaddr.ToString());
            else if(state == 0x02)
                listBox1.Items.Add("no card detected"); 
            else
                listBox1.Items.Add("no card detected"); 

        }

        private void button1_Click(object sender, EventArgs e)
        {
            readcomset();
            mySerialPort.Open();
            cardtable[0] = (byte)0x00;
            cardtable[1] = (byte)0x03;
            cardtable[2] = (byte)0x4a;
            cardtable[3] = (byte)0x18;
            timer1.Enabled = true;
        }



        private void button4_Click(object sender, EventArgs e)
        {

            mySerialPort.Close();
            timer1.Enabled = false;

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }








    }
}
