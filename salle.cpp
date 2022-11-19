#include "salle.h"
#include "ui_salle.h"
#include "login.h"
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
}

Salle::~Salle()
{
    delete ui;
}

void Salle::on_LoadButton_clicked()
{
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


void Salle::on_LogoutButton_clicked()
{
    this->hide();
            Login Login;
            Login.exec();
}

