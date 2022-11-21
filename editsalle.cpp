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

void EditSalle::on_AddButton_clicked()
{

}


void EditSalle::on_SalleReturn_clicked()
{
this->hide();
}


void EditSalle::on_SearchButton_clicked()
{

}

