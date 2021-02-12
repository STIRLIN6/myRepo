#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "QVector"
#include "QPushButton"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    bool endOfGame();
    void restart();

private:
    Ui::GameWindow *ui;
    QVector<QVector<QPushButton*>> gameBoard;

    bool firstPlayer = true;
    int firstPlayerScore = 0;
    int secondPlayerScore = 0;



public slots:
    void increaser();
};
#endif // GAMEWINDOW_H
