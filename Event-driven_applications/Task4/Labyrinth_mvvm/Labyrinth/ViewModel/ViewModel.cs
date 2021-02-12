using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using System.Timers;
using System.Windows;
using System.Windows.Input;

namespace Labyrinth
{
    public class ViewModel : ViewModelBase
    {
        private LabyrinthModel _model;

        Timer timer = new Timer(1000);
        int timeCount = 0;
        public int TimeCount { get { return timeCount; } set { OnPropertyChanged(); } }

        private ObservableCollection<FieldViewModel> field;
        public ObservableCollection<FieldViewModel> Field { get { return field; } set { field = value; OnPropertyChanged(); } }
        public int FieldCount { get { return Convert.ToInt32(Math.Sqrt(Field.Count)); } }

        public int GameTime { get { return timeCount; } } //?????

        public ViewModel(LabyrinthModel model)
        {
            Field = new ObservableCollection<FieldViewModel>();
            _model = model;

            timer.Elapsed += timeElapsed;
            timer.Start();

            _model.Update += OnUpdate;
            _model.Resize += OnResize;
            _model.End += OnEnd;

            Init();
        }

        public void Init(String path = "6x6.txt")
        {
            _model.LoadTable(path);
        }

        public void OnUpdate(object sender, EventArgs e)
        {
            for (int i = 0; i < Math.Sqrt(Field.Count); i++)
            {
                for (int j = 0; j < Math.Sqrt(Field.Count); j++)
                {
                    if (_model.table[j, i] == LabyrinthTable.Field.BLACK_FLOOR ||
                        _model.table[j, i] == LabyrinthTable.Field.BLACK_WALL ||
                        _model.table[j, i] == LabyrinthTable.Field.BLACK_GOAL)
                    {
                        Field[i * (int)Math.Sqrt(Field.Count) + j].Color = 4;
                    }
                    if (_model.table[j, i] == LabyrinthTable.Field.FLOOR)
                    {
                        Field[i * (int)Math.Sqrt(Field.Count) + j].Color = 1;
                    }
                    if (_model.table[j, i] == LabyrinthTable.Field.WALL)
                    {
                        Field[i * (int)Math.Sqrt(Field.Count) + j].Color = 2;
                    }
                    if (_model.table[j, i] == LabyrinthTable.Field.GOAL)
                    {
                        Field[i * (int)Math.Sqrt(Field.Count) + j].Color = 3;
                    }
                    if (_model.table[j, i] == LabyrinthTable.Field.PLAYER)
                    {
                        Field[i * (int)Math.Sqrt(Field.Count) + j].Color = 0;
                    }
                }
            }

            OnPropertyChanged();
        }

        public void OnResize(object sender, int e)
        {
            Field.Clear();

            for (int i = 0; i < e; i++)
            {
                for (int j = 0; j < e; j++)
                {
                    if (_model.table[i, j] == LabyrinthTable.Field.BLACK_FLOOR ||
                        _model.table[i, j] == LabyrinthTable.Field.BLACK_WALL ||
                        _model.table[i, j] == LabyrinthTable.Field.BLACK_GOAL)
                    {
                        Field.Add(new FieldViewModel(4));
                    }
                    if (_model.table[i, j] == LabyrinthTable.Field.FLOOR)
                    {
                        Field.Add(new FieldViewModel(1));
                    }
                    if (_model.table[i, j] == LabyrinthTable.Field.WALL)
                    {
                        Field.Add(new FieldViewModel(2));
                    }
                    if (_model.table[i, j] == LabyrinthTable.Field.GOAL)
                    {
                        Field.Add(new FieldViewModel(3));
                    }
                    if (_model.table[i, j] == LabyrinthTable.Field.PLAYER)
                    {
                        Field.Add(new FieldViewModel(0));
                    }
                }
            }

            OnPropertyChanged("FieldCount");
        }

        public void OnEnd(object sender, EventArgs e)
        {
            MessageBox.Show("GAME PASSED");
            _model.LoadTable("6x6.txt");

            timeCount = 0;
            TimeCount = 1500; //Beke nobel
        }

        public void Navigate(object sender, KeyEventArgs e)
        {
            if (!timer.Enabled)
            {
                goto CONTROLLERPLACE;
            }
            if (e.Key == Key.Left)
            {
                _model.Move("left");
            }
            if (e.Key == Key.Right)
            {
                _model.Move("right");
            }
            if (e.Key == Key.Up)
            {
                _model.Move("up");
            }
            if (e.Key == Key.Down)
            {
                _model.Move("down");
            }
CONTROLLERPLACE:
            if (e.Key == Key.L)
            {
                OpenFileDialog d = new OpenFileDialog();
                if (d.ShowDialog() == true)
                {
                    _model.LoadTable(d.FileName);
                }
                timeCount = 0;
                TimeCount = 1500; //Beke nobel
            }
            if (e.Key == Key.N)
            {
                _model.LoadTable("6x6.txt");

                timeCount = 0;
                TimeCount = 1500; //Beke nobel
            }
            if (e.Key == Key.P)
            {
                if (timer.Enabled)
                {
                    timer.Stop();
                }
                else
                {
                    timer.Start();
                }
            }
        }

        public void timeElapsed(object sender, EventArgs e)
        {
            timeCount++;
            TimeCount = 1500; //Beke nobel
        }

    }
}
