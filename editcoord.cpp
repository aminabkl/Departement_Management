#include "editcoord.h"
#include "ui_editcoord.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

EditCoord::EditCoord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCoord)
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

EditCoord::~EditCoord()
{
    delete ui;
}

void EditCoord::on_SearchButton_clicked()
   {
        QString Coord_ID,Cycle,Filiere,Name,Email;

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
            else
            {
                if(qry.first())
                {
                    Name = qry.value(1).toString();
                    Email = qry.value(2).toString();
                    Cycle = qry.value(3).toString();
                    Filiere = qry.value(4).toString();
                }
            }
            ui->Name->setText(Name);
            ui->Email->setText(Email);
            ui->Cycle->setText(Cycle);
            ui->Filiere->setText(Filiere);

        }
        else QMessageBox::warning(this,"Coord_ID","Veuillez insérer l'ID du coordinateur!");
    }



void EditCoord::on_EditButton_clicked()
{
    QString Coord_ID,Cycle,Filiere,Name,Email;

    if(!db.isOpen()){
            qDebug()<<"Failed";
            return;
        }

    Name = ui->Name->text();
    Email = ui->Email->text();
    Coord_ID = ui->Coord_ID->text();
    Cycle = ui->Cycle->text();
    Filiere = ui->Filiere->text();

    if(Name=="" ||Email=="" || Cycle=="" || Filiere=="" ){
        QMessageBox::warning(this,"Coord","Veuillez remplir tout les champs s'il vous plaît.");
    }

    else{
        QSqlQuery *qry = new QSqlQuery() ;
        qry->prepare("UPDATE Coordinateur SET Name='"+Name+"',Email ='"+Email+"', Cycle='"+Cycle+"' ,Filiere ='"+Filiere+"' WHERE Coord_ID ='"+Coord_ID+"'");
        qry->exec();
        QMessageBox::information(this,"valider","Cordinateur modifiée avec succès");

        this->hide();
    }
}


void EditCoord::on_SalleReturn_clicked()
{
    this->hide();
}

