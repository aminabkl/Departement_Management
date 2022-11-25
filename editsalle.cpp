#include "editsalle.h"
#include "ui_editsalle.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

EditSalle::EditSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditSalle)
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

EditSalle::~EditSalle()
{
    delete ui;
}

// Search by Salle_ID
void EditSalle::on_SearchButton_clicked()
{
    QString Salle_ID,Cycle,Filiere,Semestre,NumeroSalle;

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
        else
        {
            if(qry.first())
            {
                Cycle = qry.value(1).toString();
                Filiere = qry.value(2).toString();
                Semestre = qry.value(3).toString();
                NumeroSalle = qry.value(4).toString();
            }
        }
        ui->Cycle->setText(Cycle);
        ui->Filiere->setText(Filiere);
        ui->Semestre->setText(Semestre);
        ui->NumeroSalle->setText(NumeroSalle);

    }
    else QMessageBox::warning(this,"Salle_ID","Veuillez insérer l'ID de la salle!");
}

// Edit data
void EditSalle::on_EditButton_clicked()
{

    QString Salle_ID,Cycle,Filiere,Semestre,NumeroSalle;

    if(!db.isOpen()){
            qDebug()<<"Failed";
            return;
        }

    Salle_ID = ui->Salle_ID->text();
    Cycle = ui->Cycle->text();
    Filiere = ui->Filiere->text();
    Semestre = ui->Semestre->text();
    NumeroSalle = ui->NumeroSalle->text();

    if(Cycle=="" || Filiere=="" ||Semestre=="" || NumeroSalle==""){
        QMessageBox::warning(this,"Salle","Veuillez remplir tout les champs s'il vous plaît.");
    }

    else{
        QSqlQuery *qry = new QSqlQuery() ;
        qry->prepare("UPDATE Salle SET Cycle='"+Cycle+"' ,Filiere ='"+Filiere+"',Semestre ='"+Semestre+"',Numero_Salle='"+NumeroSalle+"' WHERE Salle_ID ='"+Salle_ID+"'");
        qry->exec();
        QMessageBox::information(this,"valider","Salle modifiée avec succès");

        this->hide();
    }
}
void EditSalle::on_SalleReturn_clicked()
{
this->hide();
}
