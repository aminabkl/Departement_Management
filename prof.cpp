#include "prof.h"
#include "ui_prof.h"
#include "addprof.h"
#include "deleteprof.h"
#include "editprof.h"
#include "navmenu.h"
#include "navmenu.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

prof::prof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::prof)
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


        // Affichage de la salle juste apres avoir acceder a la fenetre
        if(!db.isOpen()){
                qDebug()<<"Failed";
                return;
            }

        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery(db);

        qry->prepare("SELECT * FROM Prof");
        qry->exec();
        model->setQuery(std::move(*qry));
        ui->ProfTable->setModel(model);

        qDebug()<<(model->rowCount());
}

prof::~prof()
{
    delete ui;
}

void prof::on_AddButton_clicked()
{
    addprof addprof;
    addprof.exec();
}

void prof::on_EditButton_clicked()
{
    editprof editprof;
    editprof.exec();
}

void prof::on_DeleteButton_clicked()
{
    deleteprof deleteprof;
    deleteprof.exec();
}

void prof::on_SearchButton_clicked()
{
    QString SearchValue= "%"+ui->SearchValue->text()+"%";

    if(!SearchValue.isEmpty())
    {
        //define the query on the db and the model
        QSqlDatabase db;
        auto qry = QSqlQuery(db);
        QString select{"SELECT * FROM Prof WHERE "
                       "Prof_ID LIKE '"+SearchValue+"'"
                       "OR Nom LIKE '"+SearchValue+"'"
                       "OR Email LIKE '"+SearchValue+"'"
                       "OR Prenom LIKE '"+SearchValue+"'"};

        //execute the query
        if(!qry.exec(select))
            qDebug() << "Cannot select from salle";
        else
        {
            //define the model
            QSqlQueryModel * model = new QSqlQueryModel;
            model->setQuery(std::move(qry));
            ui->ProfTable->setModel(model);
        }
    }
    else
    {
        //define the query on the db and the model
        QSqlDatabase db;
        auto qry = QSqlQuery(db);
        QString select{"SELECT * FROM Prof"};

        //execute the query
        if(!qry.exec(select))
            qDebug() << "Cannot select from Prof";

        //define the model
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(std::move(qry));
        ui->ProfTable->setModel(model);
    }
}

void prof::on_RefreshTable_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlDatabase db;
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("SELECT * FROM Prof");
    qry->exec();
    model->setQuery(std::move(*qry));
    ui->ProfTable->setModel(model);

    qDebug()<<(model->rowCount());
}

void prof::on_ReturnMenu_clicked()
{
    this->hide();
    NavMenu NavMenu;
    NavMenu.exec();
}
