#include "deletecoord.h"
#include "ui_deletecoord.h"
#include <QMessageBox>

DeleteCoord::DeleteCoord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteCoord)
{
    ui->setupUi(this);
}

DeleteCoord::~DeleteCoord()
{
    delete ui;
}

void DeleteCoord::on_SearchButton_clicked()
{
    QString Coord_ID;

    Coord_ID = ui->Coord_ID->text();

    if(!Coord_ID.isEmpty()){
        auto qry = QSqlQuery(db);
        QString searchID = {"SELECT * FROM Coordinateur WHERE Coord_ID='"+Coord_ID+"'" };

        if(!qry.exec(searchID.arg(Coord_ID)))
            qDebug() << "Cannot select from coord";

        int count=0;
        while(qry.next())
            count++;

        if(count != 1)
        {
            QMessageBox::warning(this, "Not Found", "Le coordinateur ne se trouve pas!");
            ui->Coord_ID->clear();
        }
        else QMessageBox::information(this, "Found", "Le coordinateur est selectionnée!");
}}


void DeleteCoord::on_DeleteButton_clicked()
{


    QString Coord_ID;

    Coord_ID = ui->Coord_ID->text();
    QSqlQuery *qry = new QSqlQuery() ;
    if(!Coord_ID.isEmpty()){
    qry->prepare("DELETE FROM Coordinateur WHERE Coord_ID = '"+Coord_ID+"'");
    qry->exec();
    QMessageBox::information(this, "Found", "La coordinateur a été supprimé avec succès!");
}
}

void DeleteCoord::on_SalleReturn_clicked()
{

    this->hide();
}

