#include "coordinateur.h"
#include "ui_coordinateur.h"

Coordinateur::Coordinateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Coordinateur)
{
    ui->setupUi(this);
}

Coordinateur::~Coordinateur()
{
    delete ui;
}
