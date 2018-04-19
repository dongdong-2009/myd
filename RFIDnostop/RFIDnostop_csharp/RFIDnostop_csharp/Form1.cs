using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RFIDnostop_csharp
{
   
    
    public partial class Form1 : Form
    {
        byte[] card_msg_cp = new byte[1024];
        int readbyte;
       byte[] cardtable=new byte[4];
       byte cardcheck;
       byte cardaddr;
       byte cardstate;
        
        public Form1()
        {
            
            InitializeComponent();

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
  
        }
        int readbyte
        private void button1_Click(object sender, EventArgs e)
        {
            int i;
            cardtable[0] = (byte)0x00;
            cardtable[1] = (byte)0x03;
            cardtable[2] = (byte)0x4a;
            cardtable[3] = (byte)0x18;
            this.serialPort.BaudRate = 9600;
            this.serialPort.DataBits = 8;
            //this.serialPort1.Parity = null;
            this.serialPort.Open();
            Console.Write("open\r\n" + "\r\n");
            this.serialPort.
            readbyte = this.serialPort.Read(card_msg_cp, 0, 100);
            Console.Write("readbyte"+readbyte.ToString()+"\r\n");
            for (i = 0; i < readbyte; i++)
            {
                if (card_msg_cp[i + 0] == 0xff && card_msg_cp[i + 1] == 0xff && card_msg_cp[i + 2] == 0xff && card_msg_cp[i + 3] == 0xff && card_msg_cp[i + 4] == 0xff)
                {
                    //putchar2(0x01);
                    cardcheck = (byte)(card_msg_cp[i + 5] ^ card_msg_cp[i + 6] ^ card_msg_cp[i + 7] ^ card_msg_cp[i + 8] ^ card_msg_cp[i + 9] ^ card_msg_cp[i + 10]);
                    if (cardcheck == card_msg_cp[i + 11])
                    {
                        //putchar2(0x02);
                        cardaddr = (byte)card_msg_cp[i + 5];
                        cardstate = (byte)card_msg_cp[i + 6];
                        if (cardtable[0] == card_msg_cp[i + 7] && cardtable[1] == card_msg_cp[i + 8] && cardtable[2] == card_msg_cp[i + 9] && cardtable[3] == card_msg_cp[i + 10])
                        {
                            //putchar2(0x03);
                            //display(0xd0d0);
                            Console.Write("right\r\n");
                        }
                        else
                        {
                            // display(0x0000);
                            Console.Write("error\r\n");
                        }
                    }
                }
            }
        }

    }
}
