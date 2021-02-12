#include "chamealeondata.h"

#include <QFile>

#include <QDateTime>
#include <QFileInfo>

#include "QTextStream"

#include <QDebug>

ChamealeonData::ChamealeonData(QObject *parent) : QObject(parent)
{

}

QVector<QString> ChamealeonData::saveGameList() const
{
    QVector<QString> result(5);
    for (int i = 0; i < 5; i++) {
        if (QFile::exists("game" + QString::number(i) + ".sav")) {
            QFileInfo info("game"+ QString::number(i) + ".sav");
            result[i] = "[" + QString::number(i + 1) + "] " + info.lastModified().toString("yyyy.MM.dd HH:mm:ss");
        }
    }
    return result;
}

bool ChamealeonData::loadGame(int gameIndex, QVector<int> &saveGameData)
{
    QFile file("game" + QString::number(gameIndex) + ".sav");
    if (!file.open(QFile::ReadOnly)) {
        return false;
    }

    QTextStream stream(&file);

    saveGameData.resize(2);
    saveGameData[0] = stream.readLine().toInt();
    saveGameData[1] = stream.readLine().toInt();

    saveGameData.resize((saveGameData[0]*saveGameData[0])*2+2);

    for (int i = 0; i < saveGameData[0]*saveGameData[0]*2; i++) {
        saveGameData[i+2] = stream.readLine().toInt();
    }

    qDebug() << saveGameData.size() << endl;
    /*fields.resize(size);
    chameleons.resize(size);
    for (int i = 0; i < size; i++) {
        fields[i].resize(size);
        chameleons[i].resize(size);
    }

    player = stream.readLine().toInt();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fields[i][j] = stream.readLine().toInt();
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            chameleons[i][j] = stream.readLine().toInt();
        }
    }*/

    file.close();

    return true;
}

bool ChamealeonData::saveGame(int gameIndex, int &player, QVector<QVector<int> > &fields, QVector<QVector<int> > &chameleons)
{
    QFile file("game" + QString::number(gameIndex) + ".sav");
    if (!file.open(QFile::WriteOnly)) {
        return false;
    }

    QTextStream stream(&file);
    stream << fields.size() << endl;
    stream << player << endl;
    for (int i = 0; i < fields.size(); i++) {
        for (int j = 0; j < fields.size(); j++) {
            stream << fields[i][j] << endl;
        }
    }
    for (int i = 0; i < fields.size(); i++) {
        for (int j = 0; j < fields.size(); j++) {
            stream << chameleons[i][j] << endl;
        }
    }

    file.close();

    return true;
}
