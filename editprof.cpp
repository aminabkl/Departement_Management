#include "editprof.h"
#include "ui_editprof.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

editprof::editprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editprof)
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

editprof::~editprof()
{
    delete ui;
}

void editprof::on_EditButton_clicked()
{
    QString Prof_ID,Nom,Prenom,Email;

        if(!db.isOpen()){
                qDebug()<<"Failed to open database";
                return;
            }

        Prof_ID = ui->Prof_ID->text();
        Nom = ui->Nom->text();
        Prenom = ui->Prenom->text();
        Email = ui->Email->text();

        if(Nom=="" ||Prenom=="" || Email==""){
            QMessageBox::warning(this,"Prof","Veuillez remplir tout les champs s'il vous plaît.");
        }

        else{
            QSqlQuery *qry = new QSqlQuery() ;
            qry->prepare("UPDATE Prof SET Nom='"+Nom+"',Prenom ='"+Prenom+"', Email='"+Email+"' WHERE Prof_ID ='"+Prof_ID+"'");
            qry->exec();
            QMessageBox::information(this,"valider","Le professeur a été modifiée avec succès");

            this->hide();
        }
}

void editprof::on_SalleReturn_clicked()
{
this->hide();
}



void editprof::on_SearchButton_clicked()
{

         QString Prof_ID,Nom,Prenom,Email;

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
                 QMessageBox::warning(this, "Not Found", "Le prof ne se trouve pas!");
                 ui->Prof_ID->clear();
             }
             else
             {
                 if(qry.first())
                 {
                     Nom = qry.value(1).toString();
                     Prenom = qry.value(2).toString();
                     Email = qry.value(3).toString();
                 }
             }
             ui->Nom->setText(Nom);
             ui->Prenom->setText(Prenom);
             ui->Email->setText(Email);

         }
         else QMessageBox::warning(this,"Prof_ID","Veuillez insérer l'ID du prof!");

}
