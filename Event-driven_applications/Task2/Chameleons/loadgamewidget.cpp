#include "loadgamewidget.h"
#include "QMessageBox"

LoadGameWidget::LoadGameWidget(QWidget *parent) : SaveGameWidget(parent)
{
    setWindowTitle("Chameleons - Load");

    disconnect(_okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(_okButton, SIGNAL(clicked()), this, SLOT(okButton_Clicked()));
}

void LoadGameWidget::okButton_Clicked()
{
    if (_listWidget->currentItem()->text() == "Empty") {
        QMessageBox::warning(this, trUtf8("Chameleons"), trUtf8("There is no game selected!"));
        return;
    }

    accept();
}
