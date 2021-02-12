using Microsoft.VisualStudio.TestTools.UnitTesting;
using Labyrinth;

//using Moq;

namespace LabyrintTest
{
    [TestClass]
    public class UnitTest1
    {
        LabyrinthModel _model;
        //LabyrinthTable _table;

        [TestInitialize]
        public void Init()
        {
            _model = new LabyrinthModel(null);
        }



        [TestMethod]
        public void LabyrinthTableInit()
        {
            _model.LoadTable("7x7.txt");
            Assert.AreEqual(7, _model.table.Size);
            Assert.AreEqual(LabyrinthTable.Field.BLACK_GOAL, _model.table[6, 0]);
            Assert.AreEqual(LabyrinthTable.Field.PLAYER, _model.table[0, 6]);
            Assert.AreEqual(LabyrinthTable.Field.BLACK_FLOOR, _model.table[6, 6]);
        }

        [TestMethod]
        public void LabyrinthMoveTest()
        {
            _model.LoadTable("7x7.txt");
            _model.Move("right");

            Assert.AreEqual(LabyrinthTable.Field.PLAYER, _model.table[1, 6]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[0, 6]);
        }
        
        [TestMethod]
        public void LabyrinthGoalTest()
        {
            _model.LoadTable("7x7.txt");

            for (int i = 0; i < 6; i++)
            {
                _model.Move("right");
            }
            for (int i = 0; i < 6; i++)
            {
                _model.Move("up");
            }

            Assert.AreEqual(LabyrinthTable.Field.PLAYER, _model.table[_model.table.Size-1, 0]);
            Assert.IsTrue(_model.endOfGame());
        }

        [TestMethod]
        public void LabyrinthLightTest()
        {
            _model.LoadTable("7x7.txt");

            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[1, 6]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 6]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 5]);

            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[0, 5]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[1, 5]);

            Assert.AreEqual(LabyrinthTable.Field.BLACK_WALL, _model.table[0, 4]);

            _model.Move("right");
            _model.Move("right");
            _model.Move("up");
            _model.Move("up");

            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[1, 2]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[1, 3]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[1, 4]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[1, 5]);

            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 2]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 3]);
            Assert.AreEqual(LabyrinthTable.Field.PLAYER, _model.table[2, 4]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 5]);

            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[3, 3]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[3, 4]);
            Assert.AreEqual(LabyrinthTable.Field.WALL, _model.table[3, 5]);

            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[1, 6]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[2, 6]);
            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[3, 6]);

            Assert.AreEqual(LabyrinthTable.Field.FLOOR, _model.table[3, 2]);
        }
    }
}
