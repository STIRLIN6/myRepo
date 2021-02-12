using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Labyrinth
{
    public partial class GameForm : Form
    {
        LabyrinthModel _model;
        Button[,] buttons;

        int time = 0;
        Label textBox1;

        public GameForm()
        {
            InitializeComponent();

            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            
            textBox1 = new Label();
            textBox1.Enabled = true;
            textBox1.SetBounds(this.Width - 150, this.Height - 150, 50, 50);
            this.Controls.Add(textBox1);

            _model = new LabyrinthModel(new LabyrinthDataAccess());

            _model.Update += UpdateTable;
            _model.Resize += ResizeTable;
            _model.End += EndGame;

            InitGame();
        }

        private void ResizeTable(object sender, int n)
        {
            if (buttons != null)
            {
                foreach (Button x in buttons)
                {
                    this.Controls.Remove(x);
                }
            }
            

            buttons = new Button[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    buttons[i, j] = new Button();
                    buttons[i, j].Enabled = false;

                    buttons[i, j].SetBounds(i * 30, j * 30, 30, 30);
                    
                    this.Controls.Add(buttons[i, j]);
                }
            }
            Invalidate();
        }

        private void EndGame(object sender, EventArgs n)
        {
            MessageBox.Show("GAME PASSED");
            //InitGame("7x7.txt");
        }
        
        public void UpdateTable (object sender, EventArgs e)
        {
            for (int i = 0; i < Math.Sqrt(buttons.Length); i++)
            {
                for (int j = 0; j < Math.Sqrt(buttons.Length); j++)
                {
                    if (_model.table[i,j] == LabyrinthTable.Field.BLACK_FLOOR)
                    {
                        buttons[i, j].BackColor = Color.Black;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.BLACK_WALL)
                    {
                        buttons[i, j].BackColor = Color.Black;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.BLACK_GOAL)
                    {
                        buttons[i, j].BackColor = Color.Black;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.FLOOR)
                    {
                        buttons[i, j].BackColor = Color.Orange;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.WALL)
                    {
                        buttons[i, j].BackColor = Color.Brown;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.GOAL)
                    {
                        buttons[i, j].BackColor = Color.Gold;
                    }
                    else if (_model.table[i, j] == LabyrinthTable.Field.PLAYER)
                    {
                        buttons[i, j].BackColor = Color.White;
                    }
                }
            }
        }

        private void GameForm_Load(object sender, EventArgs e)
        {
            
        }

        private void InitGame(string path = "6x6.txt")
        {
            time = 0;
            _model.LoadTable(path);
            timer1.Interval = 1000;
            timer1.Start();
        }

        private void GameForm_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Left && timer1.Enabled)
            {
                _model.Move("left");
            }
            if (e.KeyCode == Keys.Right && timer1.Enabled)
            {
                _model.Move("right");
            }
            if (e.KeyCode == Keys.Up && timer1.Enabled)
            {
                _model.Move("up");
            }
            if (e.KeyCode == Keys.Down && timer1.Enabled)
            {
                _model.Move("down");
            }
            if (e.KeyCode == Keys.L)
            {
                OpenFileDialog d = new OpenFileDialog();
                if (d.ShowDialog() == DialogResult.OK)
                {
                    InitGame(d.FileName);
                }
            }
            if (e.KeyCode == Keys.P)
            {
                if (timer1.Enabled == true) { timer1.Enabled = false; }
                else { timer1.Enabled = true; }
            }
            if (e.KeyCode == Keys.N)
            {
                InitGame();
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            time++;
            textBox1.Text = time.ToString();
            Invalidate();
        }
    }
}
