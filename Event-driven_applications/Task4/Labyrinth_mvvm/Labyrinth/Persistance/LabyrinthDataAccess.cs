using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Labyrinth
{
    public class LabyrinthDataAccess
    {
        public LabyrinthTable Read (String path)
        {
            if (!File.Exists(path))
            {
                throw new Exception("nem jo, dude");
            }

            String[] allLines = File.ReadAllLines(path);
            int n = Convert.ToInt32(allLines[0]);
            LabyrinthTable table = new LabyrinthTable(n);

            for (int i = 0; i < n; i++)
            {
                String[] temp = allLines[i+1].Split(' ');

                for (int j = 0; j < n; j++)
                {
                    if (temp[j] == "w")
                    {
                        table.SetField(j, i, LabyrinthTable.Field.BLACK_WALL);//
                    }
                    else if (temp[j] == "f")
                    {
                        table.SetField(j, i, LabyrinthTable.Field.BLACK_FLOOR);//
                    }
                    else if (temp[j] == "g")
                    {
                        table.SetField(j, i, LabyrinthTable.Field.BLACK_GOAL);//
                    }
                    else if (temp[j] == "p")
                    {
                        table.SetField(j, i, LabyrinthTable.Field.PLAYER);
                    }
                }
            }
            
            return table;
        }
    }
}
