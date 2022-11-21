#include "salle.h"
#include "ui_salle.h"
#include "login.h"
#include "addsalle.h"
#include <QMessageBox>
#include <QSqlQueryModel>

Salle::Salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salle)
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


        // Affichage de la salle juste apres avoir acceder a la fenetre
        if(!db.isOpen()){
                qDebug()<<"Failed";
                return;
            }

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT Cycle, Filiere, Semestre, Numero_Salle FROM Salle");
        qry->exec();
        model->setQuery(std::move(*qry));
        ui->SalleTable->setModel(model);

        qDebug()<<(model->rowCount());



}

Salle::~Salle()
{
    delete ui;
}



void Salle::on_LogoutButton_clicked()
{
    this->hide();
    Login Login;
    Login.exec();
}

// Ajouter
void Salle::on_AddButton_clicked()
{
            AddSalle AddSalle;
            AddSalle.exec();
}

// Modifier
void Salle::on_EditButton_clicked()
{

}

// Supprimer
void Salle::on_DeleteButton_clicked()
{

}

