#include "deletesalle.h"
#include "ui_deletesalle.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

DeleteSalle::DeleteSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteSalle)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/lenovo/Documents/QT/DepartmentDB.db");
        if(!db.open()){
            qDebug()<<"Can't connect to the database !";
        }
        else{
            qDebug()<<"Connected !";
        }
}

DeleteSalle::~DeleteSalle()
{
    delete ui;
}

void DeleteSalle::on_SearchButton_clicked()
{
    QString Salle_ID;

    Salle_ID = ui->Salle_ID->text();

    if(!Salle_ID.isEmpty()){
        auto qry = QSqlQuery(db);
        QString searchID = {"SELECT * FROM Salle WHERE Salle_ID='"+Salle_ID+"'" };

        if(!qry.exec(searchID.arg(Salle_ID)))
            qDebug() << "Cannot select from salle";

        int count=0;
        while(qry.next())
            count++;

        if(count != 1)
        {
            QMessageBox::warning(this, "Not Found", "La salle ne se trouve pas!");
            ui->Salle_ID->clear();
        }
}
}


void DeleteSalle::on_DeleteButton_clicked()
{

    QString Salle_ID;

    Salle_ID = ui->Salle_ID->text();
    QSqlQuery *qry = new QSqlQuery() ;
    if(!Salle_ID.isEmpty()){
    qry->prepare("DELETE FROM Salle WHERE Salle_ID = '"+Salle_ID+"'");
    qry->exec();
    QMessageBox::information(this, "Found", "La salle a été supprimée avec succès!");
}
}

void DeleteSalle::on_SalleReturn_clicked()
{

    this->hide();
}

