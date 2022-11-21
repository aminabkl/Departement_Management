#include "salle.h"
#include "ui_salle.h"
#include "login.h"
#include "addsalle.h"
#include "editsalle.h"
#include <QMessageBox>
#include <QDebug>
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

        qry->prepare("SELECT * FROM Salle");
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
    EditSalle EditSalle;
    EditSalle.exec();
}

// Supprimer
void Salle::on_DeleteButton_clicked()
{

}

// chercher dans le tableau
void Salle::on_SearchButton_clicked()
{
    QString SearchValue= "%"+ui->SearchValue->text()+"%";

    if(!SearchValue.isEmpty())
    {
        //define the query on the db and the model
        auto qry = QSqlQuery(db);
        QString select{"SELECT * FROM Salle WHERE "
                       "Salle_ID LIKE '"+SearchValue+"'"
                       "OR Cycle LIKE '"+SearchValue+"'"
                       "OR Filiere LIKE '"+SearchValue+"'"
                       "OR Semestre LIKE '"+SearchValue+"'"
                       "OR Numero_Salle LIKE '"+SearchValue+"'"};

        //execute the query
        if(!qry.exec(select))
            qDebug() << "Cannot select from salle";
        else
        {
            //define the model
            QSqlQueryModel * model = new QSqlQueryModel;
            model->setQuery(std::move(qry));
            ui->SalleTable->setModel(model);
        }
    }
    else
    {
        //define the query on the db and the model
        auto qry = QSqlQuery(db);
        QString select{"SELECT * FROM Salle"};

        //execute the query
        if(!qry.exec(select))
            qDebug() << "Cannot select from salle";

        //define the model
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(std::move(qry));
        ui->SalleTable->setModel(model);
    }
}
