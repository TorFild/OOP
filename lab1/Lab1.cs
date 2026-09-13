using System;
using System.Drawing;
using System.Windows.Forms;
using System.Drawing.Drawing2D;


namespace Lab1
{
    public partial class Form1 : Form
    {
        bool isEllipse = false;

        public Form1()
        {
            InitializeComponent();
        }

     
        private void timer1_Tick(object sender, EventArgs e)
        {
         
            button1.Location = new Point(button1.Location.X + 5, button1.Location.Y + 2);

            if (button1.Left > this.ClientSize.Width) button1.Left = 0;
            if (button1.Top > this.ClientSize.Height) button1.Top = 0;

            button1.Size = new Size(button1.Width + 2, button1.Height + 1);

           
            GraphicsPath path = new GraphicsPath();
            if (isEllipse)
            {
                path.AddEllipse(0, 0, button1.Width, button1.Height);
                isEllipse = false;
            }
            else
            {
                path.AddRectangle(new Rectangle(0, 0, button1.Width, button1.Height));
                isEllipse = true;
            }
            button1.Region = new Region(path);
        }
    }
}
