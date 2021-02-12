using System;
using System.Collections.Generic;
using System.Text;

namespace Labyrinth
{
    public class LabyrinthTable
    {
        public enum Field { BLACK_FLOOR, FLOOR, BLACK_WALL, WALL, BLACK_GOAL, GOAL, PLAYER }
        //                  0          , 1    , ...

        private Field[,] _fieldValues; //
        //private bool[][] fieldVisible; //true:lathato, false:nem

        public Field this[int x, int y] => _fieldValues[x, y];

        public void SetField(int x, int y, Field value)
        {
            _fieldValues[x,y] = value;
        }

        public LabyrinthTable(int size)
        {
            Size = size;
            _fieldValues = new Field[size, size];
        }

        public int Size { get; private set; }
    }
}
