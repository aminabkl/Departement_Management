#include "editsalle.h"
#include "ui_editsalle.h"

EditSalle::EditSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSalle)
{
    ui->setupUi(this);
}

EditSalle::~EditSalle()
{
    delete ui;
}
