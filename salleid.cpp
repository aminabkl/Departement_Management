#include "salleid.h"
#include "ui_salleid.h"

SalleID::SalleID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SalleID)
{
    ui->setupUi(this);
}

SalleID::~SalleID()
{
    delete ui;
}
