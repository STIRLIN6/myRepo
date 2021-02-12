#ifndef CHAMELEONWIDGET_H
#define CHAMELEONWIDGET_H

#include <QWidget>
#include "chameleonmodel.h"
#include "QPushButton"

#include "loadgamewidget.h"
#include "savegamewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ChameleonWidget; }
QT_END_NAMESPACE

class ChameleonWidget : public QWidget
{
    Q_OBJECT

public:
    ChameleonWidget(QWidget *parent = nullptr);
    ~ChameleonWidget();

    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent* event);

    QPushButton* sizeButton3;
    QPushButton* sizeButton5;
    QPushButton* sizeButton7;

    chameleonmodel* model;

    int selectedX = -1;
    int selectedY = -1;

private:
    Ui::ChameleonWidget *ui;

    QVector<QLineF> _tableGraphics;
    QRectF _chameleonGraphics;

    SaveGameWidget* _saveGameWidget;
    LoadGameWidget* _loadGameWidget;

private slots:
    void endGame();
    void update1();

    void newGame();

    void saveGame();
    void loadGame();
};
#endif // CHAMELEONWIDGET_H
