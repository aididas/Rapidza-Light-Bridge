using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace light_bridge_UI
{
    public partial class Form1 : Form
    {
        int Num = 0;
        DataSender dataSender;
        public Form1()
        {
            InitializeComponent();
            dataSender = new DataSender("145.93.100.241", 8081);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            serialPort1.Open();
           
        }

        private void Form1_LoadClosed(object sender, EventArgs e)
        {
            serialPort1.Close();


        }


        private void Panel1_Paint(object sender, PaintEventArgs e)
        {
            
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
           
       
            if (serialPort1.BytesToRead > 0)
            {
                string number = serialPort1.ReadLine().Trim();
                if (number == "number")
                {
                    ++Num;
                    this.panel1.BackColor = Color.PaleGreen;
                    this.label1.Text = "Pizza is Ready ^^"+ Num;
                    Thread.Sleep(250);
                    dataSender.sendMessage("product_ready");

                }

               


            }

            else this.panel1.BackColor = Color.PaleGoldenrod;
        }
    }
}
