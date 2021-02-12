#include "chameleonwidget.h"
#include "ui_chameleonwidget.h"

#include "QPainter"
#include "QColor"
#include "QMouseEvent"

#include <QMessageBox>

#include "QApplication"

ChameleonWidget::ChameleonWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChameleonWidget)
{
    ui->setupUi(this);

    model = new chameleonmodel();

    _loadGameWidget = NULL;
    _saveGameWidget = NULL;

    sizeButton3 = new QPushButton(this); // 0, 500;           (500.0/3),600
    sizeButton5 = new QPushButton(this); // (500.0/3), 500;   (500.0*2/3),600
    sizeButton7 = new QPushButton(this); // (500.0*2/3), 500; 500,600

    sizeButton3->setText("3x3");
    sizeButton5->setText("5x5");
    sizeButton7->setText("7x7");

    connect(sizeButton3, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(sizeButton5, SIGNAL(clicked()), this, SLOT(newGame()));
    connect(sizeButton7, SIGNAL(clicked()), this, SLOT(newGame()));

    connect(model, SIGNAL(end()), this, SLOT(endGame()));
    connect(model, SIGNAL(refreshTable()), this, SLOT(update1()));
}

ChameleonWidget::~ChameleonWidget()
{
    if (_loadGameWidget != NULL) delete _loadGameWidget;
    if (_saveGameWidget != NULL) delete _saveGameWidget;
    delete ui;
}

void ChameleonWidget::paintEvent(QPaintEvent *event)
{
    _tableGraphics.clear();

    for (int i = 0; i < model->size; i++) {
        _tableGraphics.append(QLineF(0, (i+1)*500.0/model->size, 500, (i+1)*500.0/model->size));
        _tableGraphics.append(QLineF((i+1)*500.0/model->size, 0, (i+1)*500.0/model->size, 500));
    }

    _chameleonGraphics = QRectF(0.0, 0.0, 500.0/model->size, 500.0/model->size);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.scale(width()/500.0, height()/600.0);

    sizeButton3->setGeometry(0, height()*5/6, width()/3, height()/6);
    sizeButton5->setGeometry(width()/3, height()*5/6, width()/3, height()/6);
    sizeButton7->setGeometry((width()*2/3), height()*5/6, width()/3, height()/6);

    painter.setPen(QPen(Qt::black, 2));

    painter.drawLines(_tableGraphics);

    for (int i = 0; i < model->size; i++) {
        for (int j = 0; j < model->size; j++) {
            if (true || (i != (model->size/2)+1 && j != (model->size/2)+1)) {
                //painter.save();
                if (j != 0) { painter.translate(0 * 500.0 / model->size , 1 * 500.0 / model->size); }

                if ((i != (model->size/2) || j != (model->size/2))) {
                    if (model->fieldColor[i][j] == 1) {
                        painter.fillRect(0.0, 0.0, 500.0/model->size, 500.0/model->size, Qt::green);
                    }
                    else if (model->fieldColor[i][j] == 2) {
                        painter.fillRect(0.0, 0.0, 500.0/model->size, 500.0/model->size, Qt::red);
                    }
                    else {
                        painter.fillRect(0.0, 0.0, 500.0/model->size, 500.0/model->size, Qt::black);
                    }
                }
            }
            if (1 == model->chameleonColor[i][j]) {
                painter.setBrush(Qt::green);
                painter.drawEllipse(_chameleonGraphics);
            }
            else if (2 == model->chameleonColor[i][j]) {
                painter.setBrush(Qt::red);
                painter.drawEllipse(_chameleonGraphics);
            }
            else {
                int rozsi = 56;
            }

        }
        painter.translate(500.0/model->size, -500.0*(model->size-1)/model->size);
    }
}

void ChameleonWidget::mousePressEvent(QMouseEvent *event)
{
    int trueHeight = height()*5/6;

    int x = event->pos().x() * model->size / width();
    int y = event->pos().y() * model->size / trueHeight;

    if (selectedX == -1) {
        selectedX = x;
        selectedY = y;
    }
    else {
        model->move(selectedX, selectedY, x, y);
        selectedX = -1;
        selectedY = -1;
    }
}

void ChameleonWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_N && QApplication::keyboardModifiers() == Qt::ControlModifier) {
        model->init(model->size);
        update();
    }

    if (event->key() == Qt::Key_L && QApplication::keyboardModifiers() == Qt::ControlModifier) {

        if (_loadGameWidget == NULL) {
            _loadGameWidget = new LoadGameWidget();
            connect(_loadGameWidget, SIGNAL(accepted()), this, SLOT(loadGame()));
        }

        _loadGameWidget->setGameList((model->saveGameList()));
        _loadGameWidget->open();
    }

    if (event->key() == Qt::Key_S && QApplication::keyboardModifiers() == Qt::ControlModifier) {
        if (_saveGameWidget == NULL) {
            _saveGameWidget = new SaveGameWidget();
            connect(_saveGameWidget, SIGNAL(accepted()), this, SLOT(saveGame()));
        }

        _saveGameWidget->setGameList(model->saveGameList());
        _saveGameWidget->open();
    }
}

void ChameleonWidget::endGame()
{
    QMessageBox x;
    if (1 == model->winner) {
        x.setText("Green player won");
    }
    else {
        x.setText("Red player won");
    }
    x.exec();
    model->init(model->size);
}

void ChameleonWidget::update1()
{
    update();
}

void ChameleonWidget::newGame()
{
    if (sender() == sizeButton3) {
        model->init(3);
    }
    else if (sender() == sizeButton5) {
        model->init(5);
    }
    else {
        model->init(7);
    }
}

void ChameleonWidget::saveGame()
{
    if (model->saveGame(_saveGameWidget->selectedGame())) {
        update();
        QMessageBox::information(this, trUtf8("Chameleon"), trUtf8("The game has successfully saved!"));
    }
    else {
        QMessageBox::information(this, trUtf8("Chameleon"), trUtf8("There was a problem with saving your game!"));
    }
}

void ChameleonWidget::loadGame()
{
    if (model->loadGame(_loadGameWidget->selectedGame()))
    {
        update();
        QMessageBox::information(this, trUtf8("Chameleon"), trUtf8("Game loaded, next player: ") + ((model->player == 1) ? "Green" : "Red") + "!");
    }
    else
    {
        QMessageBox::warning(this, trUtf8("Chameleon"), trUtf8("Error. Game isn't loaded."));
    }
}
