#ifndef CHAMELEONMODEL_H
#define CHAMELEONMODEL_H

#include <QObject>
#include "QVector"

#include "chamealeondata.h"

class chameleonmodel : public QObject
{
    Q_OBJECT
public:
    explicit chameleonmodel(QObject *parent = nullptr);

    int size = 5;

    QVector<QVector<int>> fieldColor; // 0:grey; 1:green; 2:red
    QVector<QVector<int>> chameleonColor; // 0: empty; 1:green; 2:red

    void init(int size);

    int player = 1; // 1:green, 2:red

    bool validMove(int from_i, int from_j, int to_i, int to_j);
    void move(int from_i, int from_j, int to_i, int to_j);

    bool endOfGame();

    int changingX1 = -1;
    int changingY1 = -1;
    int changingX2 = -1;
    int changingY2 = -1;
    bool expired1 = false;
    bool expired2 = false;

    int winner;

    bool loadGame(int gameIndex);
    bool saveGame(int gameIndex);
    QVector<QString> saveGameList();

private:
    ChamealeonData _dataAccess;

signals:
    void end();
    void refreshTable();
};

#endif // CHAMELEONMODEL_H
