#include "chameleonmodel.h"
#include <QDebug>

chameleonmodel::chameleonmodel(QObject *parent) : QObject(parent)
{
    init(size);
    refreshTable();
}

bool chameleonmodel::validMove(int from_i, int from_j, int to_i, int to_j)
{
    //van ott kameleon?
    if (0 == chameleonColor[from_i][from_j]) {
        return false;
    }

    int fromChameleon = chameleonColor[from_i][from_j];

    //az a jatekos jon?
    if (player != fromChameleon) {
        return false;
    }

    //szabalyos lepes?  /// min(from_i, to_i)+(max(from_i,to_i)-min(from_i,to_i)/2 ->
    bool next =    (abs(from_i-to_i) <= 1 && from_j == to_j)
                || (abs(from_j-to_j) <= 1 && from_i == to_i);
    bool jump =    chameleonColor[to_i][to_j] == 0
                && player != chameleonColor[(from_i+to_i)/2][(from_j+to_j)/2]
                && ((abs(from_i-to_i) == 2 && from_j == to_j)
                   || (abs(from_j-to_j) == 2 && from_i == to_i));

    if (!(next || jump))
    {
        return false;
    }

    //ures a celpont?
    if (0 != chameleonColor[to_i][to_j]) {
        return false;
    }

    return true;
}

void chameleonmodel::move(int from_i, int from_j, int to_i, int to_j)
{
    if (validMove(from_i, from_j, to_i, to_j)) {
        //athelyezodik a kameleon
        int movingChameleonColor = chameleonColor[from_i][from_j];
        chameleonColor[from_i][from_j] = 0;
        chameleonColor[to_i][to_j] = movingChameleonColor;

        //leutodik-e kameleon
        if(abs(from_i-to_i) == 2 || abs(from_j-to_j) == 2) {
            chameleonColor[(from_i+to_i)/2][(from_j+to_j)/2] = 0;
        }

        //atvaltozas
        if (player == 1) {
            // PLAYER 1
            if (-1 != changingX1 && !expired1) {
                expired1 = true;
            }
            if (-1 != changingX1 && expired1) {
                if (fieldColor[changingX1][changingY1] != chameleonColor[changingX1][changingY1]
                        && 0 != chameleonColor[changingX1][changingY1]) {//
                    chameleonColor[changingX1][changingY1] = fieldColor[changingX1][changingY1];
                    changingX1 = -1;
                    changingY1 = -1;
                }
            }
        }
        else {
            // PLAYER 2
            if (-1 != changingX2 && !expired2) {
                expired2 = true;
            }
            if (-1 != changingX2 && expired2) {
                if (fieldColor[changingX2][changingY2] != chameleonColor[changingX2][changingY2]
                        && 0 != chameleonColor[changingX2][changingY2]) {//
                    chameleonColor[changingX2][changingY2] = fieldColor[changingX2][changingY2];
                    changingX2 = -1;
                    changingY2 = -1;
                }
            }
        }

        for (int i = 0; i < fieldColor.size(); i++) {
            for (int j = 0; j < fieldColor[i].size(); j++) {
                if (!(i == to_i && j == to_j)) {
                    if (fieldColor[i][j] != chameleonColor[i][j]
                        && chameleonColor[i][j] != 0 && fieldColor[i][j] != 0)
                    {
                        if (1 == player) {
                            changingX2 = i;
                            changingY2 = j;
                            expired2 = false;
                        }
                        else {
                            changingX1 = i;
                            changingY1 = j;
                            expired1 = false;
                        }
                    }
                }
            }
        }
        if ((from_i == changingX1 && from_j == changingY1)) {
            changingX1 = -1;
            changingY1 = -1;
        }
        if ((from_i == changingX2 && from_j == changingY2)) {
            changingX2 = -1;
            changingY2 = -1;
        }


        //vege?
        if (endOfGame()) {
            end();
        }

        //masik jatekos jon
        if (1 == player) {
            player = 2;
        }
        else {
            player = 1;
        }

        //refresh table
        refreshTable();

    }
}

bool chameleonmodel::endOfGame()
{
    bool one = false;
    bool two = false;

    bool notEnd = false;

    for (int i = 0; i < chameleonColor.size() && !notEnd; i++) {
        for (int j = 0; j < chameleonColor[i].size() && !notEnd; j++) {
            if (1 == chameleonColor[i][j]) {
                one = true;
            }
            if (2 == chameleonColor[i][j]) {
                two = true;
            }

            notEnd = one && two;
        }
    }

    if (!notEnd && one) {
        winner = 1;
    }
    else {
        winner = 2;
    }

    return !notEnd;
}

void chameleonmodel::init(int size)
{
    this->size = size;

    player = 1;

    changingX1 = -1;
    changingY1 = -1;
    changingX2 = -1;
    changingY2 = -1;

    //also es felso sor
    int table_j;
    int table_i;

    int colorOne = 1;
    int colorTwo = 2;

    fieldColor.resize(size);
    chameleonColor.resize(size);
    for (int i = 0; i < size; i++) {
        fieldColor[i].resize(size);
        chameleonColor[i].resize(size);
    }

    for (int i = 0; i <= size/2; i++) {
        //felso also sorok
        for (table_i = 0+i; table_i < (size-i); table_i++) {
            table_j = 0+i;
            fieldColor[table_i][table_j] = colorOne;
            chameleonColor[table_i][table_j] = colorOne;

            table_j = size-(i+1);
            fieldColor[table_i][table_j] = colorTwo;
            chameleonColor[table_i][table_j] = colorTwo;
        }

        //oldalso sorok
        for (table_j = 1+i; table_j < size-(i+1); table_j++) {
            table_i = i+0;
            fieldColor[table_i][table_j] = colorOne;
            chameleonColor[table_i][table_j] = colorOne;

            table_i = size-(i+1);
            fieldColor[table_i][table_j] = colorTwo;
            chameleonColor[table_i][table_j] = colorTwo;
        }

        if (1 == colorOne) {
            colorOne = 2;
            colorTwo = 1;
        }
        else {
            colorOne = 1;
            colorTwo = 2;
        }
    }

    fieldColor[(size/2)][(size/2)] = 0;
    chameleonColor[(size/2)][(size/2)] = 0;
    qDebug() << fieldColor;
    qDebug() << chameleonColor;
    refreshTable();
}

bool chameleonmodel::loadGame(int gameIndex)
{
    QVector<int> saveGameData;

    if (!_dataAccess.loadGame(gameIndex, saveGameData)) {
        return false;
    }

    size = saveGameData[0];
    this->player = saveGameData[1];

    this->init(size);

    int temp = 2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fieldColor[i][j] = saveGameData[temp];
            temp++;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            chameleonColor[i][j] = saveGameData[temp];
            temp++;
        }
    }

    return true;

}

bool chameleonmodel::saveGame(int gameIndex) {
    return _dataAccess.saveGame(gameIndex, player, fieldColor, chameleonColor);
}

QVector<QString> chameleonmodel::saveGameList()
{
    return _dataAccess.saveGameList();
}
