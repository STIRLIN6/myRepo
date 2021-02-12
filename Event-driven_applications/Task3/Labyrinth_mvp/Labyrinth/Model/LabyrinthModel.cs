using System;
using System.Collections.Generic;
using System.Text;

namespace Labyrinth
{
    public class LabyrinthModel
    {
        //el kellene fordiatani a tablat

        public LabyrinthTable table;
        public int playerX;
        public int playerY;

        private LabyrinthDataAccess _dataAccess;

        public event EventHandler Update;
        public event EventHandler<int> Resize;
        public event EventHandler End;

        private void OnUpdate()
        {
            if (null != Update)
            {
                Update(this, null);
            }
        }

        private void OnEnd()
        {
            if (null != End)
            {
                End(this, null);
            }
        }

        private void OnResize(int n)
        {
            if (null != Resize)
            {
                Resize(this, n);
            }
        }
        public LabyrinthModel(LabyrinthDataAccess dataAccess)
        {
            _dataAccess = dataAccess;
        }

        public void LoadTable (String path)
        {
            LabyrinthDataAccess data = new LabyrinthDataAccess();
            table = data.Read(path);

            OnResize(table.Size);
            playerX = 0;
            playerY = table.Size-1;

            Light();
            OnUpdate();
        }

        public bool Move(String direction)
        {
            int to_x = 0;
            int to_y = 0;

            if ("left" == direction)
            {
                to_x = playerX - 1;
                to_y = playerY;
            }
            if ("right" == direction)
            {
                to_x = playerX + 1;
                to_y = playerY;
            }
            if ("up" == direction)
            {
                to_x = playerX;
                to_y = playerY - 1;
            }
            if ("down" == direction)
            {
                to_x = playerX;
                to_y = playerY + 1;
            }

            if (to_x >= table.Size || to_x < 0 || to_y >= table.Size || to_y < 0)
            {
                return false;
            }

            // megfelelo mezo a celpont
            if (table[to_x,to_y] != LabyrinthTable.Field.FLOOR && table[to_x, to_y] != LabyrinthTable.Field.GOAL)
            {
                return false;
            }

            table.SetField(playerX, playerY, LabyrinthTable.Field.FLOOR);
            table.SetField(to_x, to_y, LabyrinthTable.Field.PLAYER);

            playerX = to_x;
            playerY = to_y;

            //VILAGITAS
            Light();
            OnUpdate();
            if (endOfGame())
            {
                OnEnd();
            }

            return true;
        }

        public bool isValidPos(int x, int y)
        {
            return x >= 0 && y >= 0 && x < table.Size && y < table.Size;
        }

        private void Light8(int xt, int yt)
        {
            // Elszomszedok
            //jobb
            int x = xt + 1;
            int y = yt;
            if (isValidPos(x, y))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            //le
            x = xt;
            y = yt + 1;
            if (isValidPos(x, y))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            //balra
            x = xt - 1;
            y = yt;
            if (isValidPos(x, y))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            //fel
            x = xt;
            y = yt - 1;
            if (isValidPos(x, y))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }

            //Sarokszomszedok
            x = xt - 1;
            y = yt - 1;
            if ((isValidPos(x, y)) && (table[x + 1, y] != LabyrinthTable.Field.WALL || table[x, y + 1] != LabyrinthTable.Field.WALL))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            x = xt + 1;
            y = yt - 1;
            if ((isValidPos(x, y)) && (table[x - 1, y] != LabyrinthTable.Field.WALL || table[x, y + 1] != LabyrinthTable.Field.WALL))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            x = xt - 1;
            y = yt + 1;
            if ((isValidPos(x, y)) && (table[x, y - 1] != LabyrinthTable.Field.WALL || table[x + 1, y] != LabyrinthTable.Field.WALL))
            {
                if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
            }
            x = xt + 1;
            y = yt + 1;
            if ((isValidPos(x, y)))
            {
                if ((table[x - 1, y] != LabyrinthTable.Field.WALL || table[x, y - 1] != LabyrinthTable.Field.WALL))
                {
                    if (table[x, y] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(x, y, LabyrinthTable.Field.FLOOR); }
                    if (table[x, y] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(x, y, LabyrinthTable.Field.WALL); }
                    if (table[x, y] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(x, y, LabyrinthTable.Field.GOAL); }
                }
            }
        }

        private void Light ()
        {
            toDark();

            Light8(playerX, playerY);
            
            if (isValidPos(playerX, playerY-1))
            {
                if (table[playerX, playerY-1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX, playerY - 1);
                }
            }
            if (isValidPos(playerX - 1, playerY))
            {
                if (table[playerX - 1, playerY] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX - 1, playerY);
                }
            }
            if (isValidPos(playerX, playerY + 1))
            {
                if (table[playerX, playerY + 1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX, playerY + 1);
                }
            }
            if (isValidPos(playerX + 1, playerY))
            {
                if (table[playerX + 1, playerY] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX + 1, playerY);
                }
            }

            if (isValidPos(playerX - 1, playerY - 1))
            {
                if (table[playerX - 1, playerY - 1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX - 1, playerY - 1);
                }
            }
            if (isValidPos(playerX + 1, playerY - 1))
            {
                if (table[playerX + 1, playerY - 1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX + 1, playerY - 1);
                }
            }
            if (isValidPos(playerX - 1, playerY + 1))
            {
                if (table[playerX - 1, playerY + 1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX - 1, playerY + 1);
                }
            }
            if (isValidPos(playerX + 1, playerY + 1))
            {
                if (table[playerX + 1, playerY + 1] == LabyrinthTable.Field.FLOOR)
                {
                    Light8(playerX + 1, playerY + 1);
                }
            }

            /*for (int i = playerX-2; i < playerX+3; i++)
            {
                for (int j = playerY - 2; j < playerY + 3; j++)
                {
                    if (!(playerY == j && playerX == i) && isValidPos(i,j))
                    {
                        if (table[i,j] == LabyrinthTable.Field.BLACK_FLOOR) { table.SetField(i, j, LabyrinthTable.Field.FLOOR); }
                        if (table[i,j] == LabyrinthTable.Field.BLACK_WALL) { table.SetField(i, j, LabyrinthTable.Field.WALL); }
                        if (table[i,j] == LabyrinthTable.Field.BLACK_GOAL) { table.SetField(i, j, LabyrinthTable.Field.GOAL); }
                    }
                }
            }*/
        }

        private LabyrinthTable toDark()
        {
            for (int i = 0; i < table.Size; i++)
            {
                for (int j = 0; j < table.Size; j++)
                {
                    if (table[i, j] == LabyrinthTable.Field.FLOOR)
                    {
                        table.SetField(i, j, LabyrinthTable.Field.BLACK_FLOOR);
                    }
                    else if (table[i, j] == LabyrinthTable.Field.WALL)
                    {
                        table.SetField(i, j, LabyrinthTable.Field.BLACK_WALL);
                    }
                    else if (table[i, j] == LabyrinthTable.Field.GOAL)
                    {
                        table.SetField(i, j, LabyrinthTable.Field.BLACK_GOAL);
                    }
                }
            }
            return table;
        }

        public bool endOfGame ()
        {
            
            return LabyrinthTable.Field.PLAYER == table[table.Size-1, 0];
        }
    }
}
