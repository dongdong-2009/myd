using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
        
    }
    public class comset
    {
        public static string name = "COM18";//COM口的名称，在计算机设备管理器中查找
        public static int baudrate = 9600;//波特率，迈凯诺默认是9600
        public static string parity = "无校验";
        public static int databit = 8;
        public static int stopbit = 1;
    }
}
