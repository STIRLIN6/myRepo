#ifndef CHAMEALEONDATA_H
#define CHAMEALEONDATA_H

#include <QObject>
#include "QVector"


class ChamealeonData : public QObject
{
    Q_OBJECT
public:
    explicit ChamealeonData(QObject *parent = nullptr);

    QVector<QString> saveGameList() const;

    bool loadGame(int gameIndex, QVector<int> &saveGameData);
    bool saveGame(int gameIndex, int &player, QVector<QVector<int>> &fields, QVector<QVector<int>> &chameleons);

signals:

};

#endif // CHAMEALEONDATA_H
