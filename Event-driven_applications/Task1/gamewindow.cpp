#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "QMessageBox" //?

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    this->setGeometry(250,250,250,250);

    this->gameBoard.resize(5);

    for (int i = 0; i < 5; i ++) {
        this->gameBoard[i].resize(5);

        for (int j = 0; j < 5; j++) {
            this->gameBoard[i][j] = new QPushButton(this);
            this->gameBoard[i][j]->setGeometry(i*50, j*50, 45, 45);
            this->gameBoard[i][j]->setText("0");
            this->gameBoard[i][j]->setVisible(true);

            this->gameBoard[i][j]->setStyleSheet("* { background-color: rgb(115,115,115) }");

            connect(this->gameBoard[i][j], SIGNAL(clicked()), this, SLOT(increaser()));
        }
    }
}

void GameWindow::increaser()
{
    int local_i;
    int local_j;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (sender() == this->gameBoard[i][j]) {
                local_i = i;
                local_j = j;
            }
        }
    }

    //onmaga
    if (4 > this->gameBoard[local_i][local_j]->text().toInt()) {
        if (3 == this->gameBoard[local_i][local_j]->text().toInt()) {
            if(firstPlayer) { firstPlayerScore++; this->gameBoard[local_i][local_j]->setStyleSheet("* { background-color: rgb(255,125,100) }"); }
            else { secondPlayerScore++; this->gameBoard[local_i][local_j]->setStyleSheet("* { background-color: rgb(100,125,255) }"); }
        }
        this->gameBoard[local_i][local_j]->setText(QString::number(this->gameBoard[local_i][local_j]->text().toInt()+1));
    }

    //balra
    if (0 < local_i) {
        if (4 > this->gameBoard[local_i-1][local_j]->text().toInt()) {
            if (3 == this->gameBoard[local_i-1][local_j]->text().toInt()) {
                if(firstPlayer) { firstPlayerScore++; this->gameBoard[local_i-1][local_j]->setStyleSheet("* { background-color: rgb(255,125,100) }"); }
                else { secondPlayerScore++; this->gameBoard[local_i-1][local_j]->setStyleSheet("* { background-color: rgb(100,125,255) }"); }
            }
            this->gameBoard[local_i-1][local_j]->setText(QString::number(this->gameBoard[local_i-1][local_j]->text().toInt()+1));
        }
    }

    //jobbra
    if (4 > local_i) {
        if (4 > this->gameBoard[local_i+1][local_j]->text().toInt()) {
            if (3 == this->gameBoard[local_i+1][local_j]->text().toInt()) {
                if(firstPlayer) { firstPlayerScore++; this->gameBoard[local_i+1][local_j]->setStyleSheet("* { background-color: rgb(255,125,100) }"); }
                else { secondPlayerScore++; this->gameBoard[local_i+1][local_j]->setStyleSheet("* { background-color: rgb(100,125,255) }"); }
            }
            this->gameBoard[local_i+1][local_j]->setText(QString::number(this->gameBoard[local_i+1][local_j]->text().toInt()+1));
        }
    }

    //folfele
    if (0 < local_j) {
        if (4 > this->gameBoard[local_i][local_j-1]->text().toInt()) {
            if (3 == this->gameBoard[local_i][local_j-1]->text().toInt()) {
                if(firstPlayer) { firstPlayerScore++; this->gameBoard[local_i][local_j-1]->setStyleSheet("* { background-color: rgb(255,125,100) }"); }
                else { secondPlayerScore++; this->gameBoard[local_i][local_j-1]->setStyleSheet("* { background-color: rgb(100,125,255) }"); }
            }
            this->gameBoard[local_i][local_j-1]->setText(QString::number(this->gameBoard[local_i][local_j-1]->text().toInt()+1));
        }
    }

    //lefele
    if (4 > local_j) {
        if (4 > this->gameBoard[local_i][local_j+1]->text().toInt()) {
            if (3 == this->gameBoard[local_i][local_j+1]->text().toInt()) {
                if(firstPlayer) { firstPlayerScore++; this->gameBoard[local_i][local_j+1]->setStyleSheet("* { background-color: rgb(255,125,100) }"); }
                else { secondPlayerScore++; this->gameBoard[local_i][local_j+1]->setStyleSheet("* { background-color: rgb(100,125,255) }"); }
            }
            this->gameBoard[local_i][local_j+1]->setText(QString::number(this->gameBoard[local_i][local_j+1]->text().toInt()+1));
        }
    }

    //valtakoztatjuk a jatekosokat
    firstPlayer = !firstPlayer;

    if (endOfGame()) {
        QMessageBox theEnd;

        if (firstPlayerScore > secondPlayerScore) {
            theEnd.setText("Red player won with " + QString::number(firstPlayerScore) + " points.");
        }
        else {
            theEnd.setText("Blue player won with " + QString::number(secondPlayerScore) + " points.");
        }

        theEnd.exec();

        //RESTART
        restart();
    }
}

GameWindow::~GameWindow()
{
    delete ui;
}

bool GameWindow::endOfGame()
{
    bool end = true;

    for (int i = 0; i < 5 && end == true; i++) {
        for (int j = 0; j < 5 && end == true; j++) {
            if (4 != this->gameBoard[i][j]->text().toInt()) {
                end = false;
            }
        }
    }

    return end;
}

void GameWindow::restart() {

    for (int i = 0; i < 5; i ++) {
        for (int j = 0; j < 5; j++) {
            this->gameBoard[i][j]->setText("0");
            this->gameBoard[i][j]->setStyleSheet("* { background-color: rgb(115,115,115) }");
        }
    }

    firstPlayer = true;
    firstPlayerScore = 0;
    secondPlayerScore = 0;
}

