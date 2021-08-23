using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace App
{
    public partial class Form1 : Form
    { string T;
        int N = 1;
        double a=0, b=0, SX = 0, SY = 0, SXX = 0, SXY = 0;
        double X1 = 0, X2 = 0, X3 = 0, X4 = 0, Z1 = 0, Z2 = 0, Z3 = 0, d, d0, d1, d2, a0=0, a1=0, a2=0;

        public Form1()
        {
            InitializeComponent();
            comboBox2.SelectedIndex = 0;
            comboBox1.SelectedItem = "1";
            comboBox1.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.chart1.Series[0].Points.Clear();
            this.chart1.Series[1].Points.Clear();

            double[] X = new double[N];
            double[] Y = new double[N];
            double[] Ei = new double[N];
            double[] F = new double[N];
            double a=0, b=0, SX = 0, SY = 0, SXX = 0, SXY = 0, a0 = 0, a1 = 0, a2 = 0;
            
            double X1 = 0, X2 = 0, X3 = 0, X4 = 0, Z1 = 0, Z2 = 0, Z3 = 0;
            if (textBox1.Text != string.Empty) X[0] = double.Parse(textBox1.Text.Replace(".", ","));
            if (textBox2.Text != string.Empty) X[1] = double.Parse(textBox2.Text.Replace(".", ","));
            if (textBox3.Text != string.Empty) X[2] = double.Parse(textBox3.Text.Replace(".", ","));
            if (textBox4.Text != string.Empty) X[3] = double.Parse(textBox4.Text.Replace(".", ","));
            if (textBox5.Text != string.Empty) X[4] = double.Parse(textBox5.Text.Replace(".", ","));
            if (textBox6.Text != string.Empty) X[5] = double.Parse(textBox6.Text.Replace(".", ","));
            if (textBox7.Text != string.Empty) X[6] = double.Parse(textBox7.Text.Replace(".", ","));
            if (textBox8.Text != string.Empty) X[7] = double.Parse(textBox8.Text.Replace(".", ","));
            if (textBox9.Text != string.Empty) X[8] = double.Parse(textBox9.Text.Replace(".", ","));
            if (textBox10.Text != string.Empty) X[9] = double.Parse(textBox10.Text.Replace(".", ","));
            if (textBox11.Text != string.Empty) X[10] = double.Parse(textBox11.Text.Replace(".", ","));


            if (textBox13.Text != string.Empty) Y[0] = double.Parse(textBox13.Text.Replace(".", ","));
            if (textBox14.Text != string.Empty) Y[1] = double.Parse(textBox14.Text.Replace(".", ","));
            if (textBox15.Text != string.Empty) Y[2] = double.Parse(textBox15.Text.Replace(".", ","));
            if (textBox16.Text != string.Empty) Y[3] = double.Parse(textBox16.Text.Replace(".", ","));
            if (textBox17.Text != string.Empty) Y[4] = double.Parse(textBox17.Text.Replace(".", ","));
            if (textBox18.Text != string.Empty) Y[5] = double.Parse(textBox18.Text.Replace(".", ","));
            if (textBox19.Text != string.Empty) Y[6] = double.Parse(textBox19.Text.Replace(".", ","));
            if (textBox20.Text != string.Empty) Y[7] = double.Parse(textBox20.Text.Replace(".", ","));
            if (textBox21.Text != string.Empty) Y[8] = double.Parse(textBox21.Text.Replace(".", ","));
            if (textBox22.Text != string.Empty) Y[9] = double.Parse(textBox22.Text.Replace(".", ","));
            if (textBox23.Text != string.Empty) Y[10] = double.Parse(textBox23.Text.Replace(".", ","));
           
   
            T = comboBox2.Text;
            if (T == "Линейная")
            {
                for (int i = 0; i < N; i++)
                {
                    SX = SX + X[i];
                }
                for (int i = 0; i < N; i++)
                {
                    SXX = SXX + (X[i] * X[i]);
                }
                for (int i = 0; i < N; i++)
                {
                    SY = SY + Y[i];
                }
                for (int i = 0; i < N; i++)
                {
                    SXY = SXY + (X[i] * Y[i]);
                }
                a = ((SXY * N) - (SX * SY)) / ((SXX * N) - (SX * SX));
                b = ((SXX * SY) - (SX * SXY)) / ((SXX * N) - (SX * SX));
                for (int i = 0; i < N; i++)
                {
                    F[i] = a * X[i] + b;
                }
                for (int i = 0; i < N; i++)
                {
                    Ei[i] = F[i] - Y[i];
                }
            }
            if (T == "Квадратичная")
            {
                for (int i = 0; i < N; i++)
                {
                    X1 = X1 + X[i];
                }
                for (int i = 0; i < N; i++)
                {
                    X2 = X2 + (X[i] * X[i]);
                }
                for (int i = 0; i < N; i++)
                {
                    X3 = X3 + (X[i] * X[i] * X[i]);
                }
                for (int i = 0; i < N; i++)
                {
                    X4 = X4 + (X[i] * X[i] * X[i] * X[i]);
                }
                for (int i = 0; i < N; i++)
                {
                    Z1 = Z1 + Y[i];
                }

                for (int i = 0; i < N; i++)
                {
                    Z2 = Z2 + (X[i] * Y[i]);
                }

                for (int i = 0; i < N; i++)
                {
                    Z3 = Z3 + (X[i] * X[i] * Y[i]);
                }
                d0 = (Z1 * X2 * X4) + (Z3 * X1 * X3) + (X2 * Z2 * X3) - (Z3 * X2 * X2) - (Z2 * X1 * X4) - (Z1 * X3 * X3);
                d1 = (N * Z2 * X4) + (X2 * Z1 * X3) + (X2 * X1 * Z3) - (X2 * Z2 * X2) - (X1 * Z1 * X4) - (N * Z3 * X3);
                d2 = (N * X2 * Z3) + (X1 * X3 * Z1) + (X1 * X2 * Z2) - (X2 * X2 * Z1) - (N * X3 * Z2) - (X1 * X1 * Z3);
                d = (N * X2 * X4) + (X1 * X2 * X3) + (X1 * X2 * X3) - (X2 * X2 * X2) - (X1 * X1 * X4) - (N * X3 * X3);

                a0 = d0 / d;
                a1 = d1 / d;
                a2 = d2 / d;
                for (int i = 0; i < N; i++)
                {
                    F[i] = a2 * (X[i] * X[i]) + a1* X[i] + a0;
                }
                for (int i = 0; i < N; i++)
                {
                    Ei[i] = F[i] - Y[i];
                }
            }

            if (N > 0) textBox12.Text = Convert.ToString(Math.Round(F[0], 4));
            if (N > 1) textBox24.Text = Convert.ToString(Math.Round(F[1], 4));
            if (N > 2) textBox25.Text = Convert.ToString(Math.Round(F[2], 4));
            if (N > 3) textBox26.Text = Convert.ToString(Math.Round(F[3], 4));
            if (N > 4) textBox27.Text = Convert.ToString(Math.Round(F[4], 4));
            if (N > 5) textBox28.Text = Convert.ToString(Math.Round(F[5], 4));
            if (N > 6) textBox29.Text = Convert.ToString(Math.Round(F[6], 4));
            if (N > 7) textBox30.Text = Convert.ToString(Math.Round(F[7], 4));
            if (N > 8) textBox31.Text = Convert.ToString(Math.Round(F[8], 4));
            if (N > 9) textBox32.Text = Convert.ToString(Math.Round(F[9], 4));
            if (N > 10) textBox33.Text = Convert.ToString(Math.Round(F[10], 4));

            if (N > 0) textBox34.Text = Convert.ToString(Math.Round(Ei[0], 4));
            if (N > 1) textBox35.Text = Convert.ToString(Math.Round(Ei[1], 4));
            if (N > 2) textBox36.Text = Convert.ToString(Math.Round(Ei[2], 4));
            if (N > 3) textBox37.Text = Convert.ToString(Math.Round(Ei[3], 4));
            if (N > 4) textBox38.Text = Convert.ToString(Math.Round(Ei[4], 4));
            if (N > 5) textBox39.Text = Convert.ToString(Math.Round(Ei[5], 4));
            if (N > 6) textBox40.Text = Convert.ToString(Math.Round(Ei[6], 4));
            if (N > 7) textBox41.Text = Convert.ToString(Math.Round(Ei[7], 4));
            if (N > 8) textBox42.Text = Convert.ToString(Math.Round(Ei[8], 4));
            if (N > 9) textBox43.Text = Convert.ToString(Math.Round(Ei[9], 4));
            if (N > 10) textBox44.Text = Convert.ToString(Math.Round(Ei[10], 4));

            textBox45.Text = Convert.ToString(Math.Round(b, 4));
            textBox46.Text = Convert.ToString(Math.Round(a, 4));
            textBox49.Text = Convert.ToString(Math.Round(a0, 4));
            textBox48.Text = Convert.ToString(Math.Round(a1, 4));
            textBox47.Text = Convert.ToString(Math.Round(a2, 4));
            for (int i = 0; i < N; i++)
            {
                this.chart1.Series[0].Points.AddXY(X[i], Y[i]);
            }
            for (int i = 0; i < N; i++)
            {
                this.chart1.Series[1].Points.AddXY(X[i], F[i]);
            }
        }

        private void tb_KeyPress(object sender, KeyPressEventArgs e)
        {
            char number = e.KeyChar;
            if ((e.KeyChar <= 47 || e.KeyChar >= 58) && number != 8 && number != 44) //цифры, клавиша BackSpace и запятая а ASCII
            {
                e.Handled = true;
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            var tbxs = this.Controls.OfType<TextBox>().ToList();
            foreach (TextBox tbx in tbxs)
            {
                tbx.Text = string.Empty;
            }

            N = int.Parse(comboBox1.Text);
            if (N > 1) {textBox2.ReadOnly = false; } else { textBox2.ReadOnly = true; }
            if (N > 2) {textBox3.ReadOnly = false;} else { textBox3.ReadOnly = true; }
            if (N > 3) {textBox4.ReadOnly = false;} else { textBox4.ReadOnly = true; }
            if (N > 4) {textBox5.ReadOnly = false;} else { textBox5.ReadOnly = true; }
            if (N > 5) {textBox6.ReadOnly = false;} else { textBox6.ReadOnly = true; }
            if (N > 6) {textBox7.ReadOnly = false;} else { textBox7.ReadOnly = true; }
            if (N > 7) {textBox8.ReadOnly = false;} else { textBox8.ReadOnly = true; }
            if (N > 8) {textBox9.ReadOnly = false;} else { textBox9.ReadOnly = true; }
            if (N > 9) {textBox10.ReadOnly = false;} else { textBox10.ReadOnly = true; }
            if (N > 10) {textBox11.ReadOnly = false;} else { textBox11.ReadOnly = true; }
            if (N > 1) {textBox14.ReadOnly = false;} else { textBox14.ReadOnly = true; }
            if (N > 2) {textBox15.ReadOnly = false;} else { textBox15.ReadOnly = true; }
            if (N > 3) {textBox16.ReadOnly = false;} else { textBox16.ReadOnly = true; }
            if (N > 4) {textBox17.ReadOnly = false;} else { textBox17.ReadOnly = true; }
            if (N > 5) {textBox18.ReadOnly = false;} else { textBox18.ReadOnly = true; }
            if (N > 6) {textBox19.ReadOnly = false;} else { textBox19.ReadOnly = true; }
            if (N > 7) {textBox20.ReadOnly = false;} else { textBox20.ReadOnly = true; }
            if (N > 8) {textBox21.ReadOnly = false;} else { textBox21.ReadOnly = true; }
            if (N > 9) {textBox22.ReadOnly = false;} else { textBox22.ReadOnly = true; }
            if (N > 10) {textBox23.ReadOnly = false;} else { textBox23.ReadOnly = true; }
        }

    }
}
