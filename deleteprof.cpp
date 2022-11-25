#include "deleteprof.h"
#include "ui_deleteprof.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
deleteprof::deleteprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteprof)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//        db.setDatabaseName("/home/nadia/Bureau/QT1/DepartmentDB.db");
    db.setDatabaseName("C:/Users/lenovo/Documents/QT/DepartmentDB.db");
        if(!db.open()){
            qDebug()<<"Can't connect to the database !";
        }
        else{
            qDebug()<<"Connected !";
        }

}

deleteprof::~deleteprof()
{
    delete ui;
}

void deleteprof::on_DeleteButton_clicked()
{
    QString Prof_ID;

    Prof_ID = ui->Prof_ID->text();
    QSqlQuery *qry = new QSqlQuery() ;
    if(!Prof_ID.isEmpty()){
    qry->prepare("DELETE FROM Prof WHERE Prof_ID = '"+Prof_ID+"'");
    qry->exec();
    QMessageBox::information(this, "Found", "La salle a été supprimée avec succès!");
}
}

void deleteprof::on_SalleReturn_clicked()
{
    this->hide();
}

void deleteprof::on_SearchButton_clicked()
{
    QString Prof_ID;

    Prof_ID = ui->Prof_ID->text();

    if(!Prof_ID.isEmpty()){
        auto qry = QSqlQuery(db);
        QString searchID = {"SELECT * FROM Prof WHERE Prof_ID='"+Prof_ID+"'" };

        if(!qry.exec(searchID.arg(Prof_ID)))
            qDebug() << "Cannot select from prof";

        int count=0;
        while(qry.next())
            count++;

        if(count != 1)
        {
            QMessageBox::warning(this, "Not Found", "Le professeur ne se trouve pas!");
            ui->Prof_ID->clear();
        }
        else QMessageBox::information(this, "Found", "Le professeur est selectionné!");
}
}
