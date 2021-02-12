#include <QtTest>
#include "chameleonmodel.h"

// add necessary includes here

class Test : public QObject
{
    Q_OBJECT

public:
    Test();
    ~Test();
private:
    chameleonmodel* _m;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case4();
    void test_case5();
    void test_case6();
    void test_case7();
    void test_case8();

};

Test::Test()
{

}

Test::~Test()
{

}

void Test::initTestCase()
{
    _m = new chameleonmodel();
}

void Test::cleanupTestCase()
{

}

void Test::test_case1()
{
    //játéktábla létrehozás (5-re)
    _m->init(5);
    QCOMPARE(_m->fieldColor.size(),5);
    QCOMPARE(_m->chameleonColor.size(),5);
}

void Test::test_case2()
{
    //helyesen jön-e létre a játéktábla (3-ra)
    _m->init(3);
    QCOMPARE(_m->fieldColor.size(),3);
    QCOMPARE(_m->chameleonColor.size(),3);
    QVector<QVector<int>> tmp = {
        {1,1,2},
        {1,0,2},
        {1,2,2}
    };
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            QCOMPARE(_m->fieldColor[i][j],tmp[i][j]);
            QCOMPARE(_m->chameleonColor[i][j],tmp[i][j]);
        }
    }
}

void Test::test_case3()
{
    //játéktábla létrehozás (7-re)
    _m->init(7);
    QCOMPARE(_m->fieldColor.size(),7);
    QCOMPARE(_m->chameleonColor.size(),7);
}

void Test::test_case4()
{
    //lépés tesztelése
    _m->init(5);
    QVERIFY(_m->validMove(3,2,2,2));
    _m->init(5);
    QVERIFY(_m->validMove(0,2,2,2));
    _m->move(0,2,2,2);
    QVector<QVector<int>> tmp {
        {1,1,0,1,2},
        {1,2,0,1,2},
        {1,2,1,1,2},
        {1,2,1,1,2},
        {1,2,2,2,2}
    };
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            QCOMPARE(_m->chameleonColor[i][j],tmp[i][j]);
        }
    }
}

void Test::test_case5() {
    //játék vége tesztelése
    QVector<QVector<int>> tmp = {
        {1,1,0},
        {1,0,0},
        {1,0,0}
    };
    _m->chameleonColor = tmp;
    QVERIFY(_m->endOfGame());
}
void Test::test_case6() {
    //színváltozás tesztelése
    _m->init(5);
    QVERIFY(_m->validMove(0,2,2,2));
    _m->move(0,2,2,2);
    QVERIFY(_m->validMove(0,4,0,2));
    _m->move(0,4,0,2);
    QVERIFY(_m->validMove(1,3,0,3));
    _m->move(1,3,0,3);
    QVERIFY(_m->validMove(1,4,0,4));
    _m->move(1,4,0,4);
    QCOMPARE(_m->chameleonColor[0][2],1);
}
void Test::test_case7() {
    //a kozepson nem valtozik at
    _m->init(3);
    _m->move(0,1,1,1);
    _m->move(0,2,0,1);
    _m->move(0,0,0,2);
    QCOMPARE(_m->chameleonColor[1][1], 1);
}
void Test::test_case8() {
    //xd
    _m->init(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            QCOMPARE(_m->chameleonColor[i][j], _m->fieldColor[i][j]);
        }
    }
}



QTEST_APPLESS_MAIN(Test)

#include "tst_test.moc"
