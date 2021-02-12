using System;
using System.Collections.Generic;
using System.Text;

namespace Labyrinth
{
    public class FieldViewModel : ViewModelBase
    {
        //public int X { get; set; }
        //public int Y { get; set; }
        public int Color {
            get
            {
                return color;
            }
            set
            {
                color = value;
                OnPropertyChanged();
            }
        } //0:player, 1:floor, 2:wall, 3:goal, 4:black
        
        private int color;


        public FieldViewModel(int c)
        {
            Color = c;
        }
    }
}
