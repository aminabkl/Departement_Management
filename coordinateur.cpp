#include "coordinateur.h"
#include "ui_coordinateur.h"
#include "login.h"
#include "addcoord.h"
#include "deletecoord.h"
#include "editcoord.h"
#include "navmenu.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>

Coordinateur::Coordinateur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Coordinateur)
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

        qry->prepare("SELECT * FROM Coordinateur");
        qry->exec();
        model->setQuery(std::move(*qry));
        ui->CoordTable->setModel(model);

        qDebug()<<(model->rowCount());
}

Coordinateur::~Coordinateur()
{
    delete ui;
}

void Coordinateur::on_AddButton_clicked()
{

    AddCoord AddCoord;
    AddCoord.exec();

}


void Coordinateur::on_EditButton_clicked()
{

    EditCoord EditCoord;
    EditCoord.exec();
}


void Coordinateur::on_DeleteButton_clicked()
{

    DeleteCoord DeleteCoord;
    DeleteCoord.exec();
}


void Coordinateur::on_SearchButton_clicked()
{    QString SearchValue= "%"+ui->SearchValue->text()+"%";

     if(!SearchValue.isEmpty())
     {
         //define the query on the db and the model
         auto qry = QSqlQuery(db);
         QString select{"SELECT * FROM Coordinateur WHERE "
                        "Coord_ID LIKE '"+SearchValue+"'"
                        "OR Name LIKE '"+SearchValue+"'"
                        "OR Email LIKE '"+SearchValue+"'"
                        "OR Cycle LIKE '"+SearchValue+"'"
                        "OR Filiere LIKE '"+SearchValue+"'"};

         //execute the query
         if(!qry.exec(select))
             qDebug() << "Cannot select from Coordinateur";
         else
         {
             //define the model
             QSqlQueryModel * model = new QSqlQueryModel;
             model->setQuery(std::move(qry));
             ui->CoordTable->setModel(model);
         }
     }
     else
     {
         //define the query on the db and the model
         auto qry = QSqlQuery(db);
         QString select{"SELECT * FROM Coordinateur"};

         //execute the query
         if(!qry.exec(select))
             qDebug() << "Cannot select from Coordinateur";

         //define the model
         QSqlQueryModel * model = new QSqlQueryModel;
         model->setQuery(std::move(qry));
         ui->CoordTable->setModel(model);
     }
 }




void Coordinateur::on_RefreshTable_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db);

    qry->prepare("SELECT * FROM Coordinateur");
    qry->exec();
    model->setQuery(std::move(*qry));
    ui->CoordTable->setModel(model);

    qDebug()<<(model->rowCount());
}


void Coordinateur::on_ReturnMenu_clicked()
{
    this->hide();
    NavMenu NavMenu;
    NavMenu.exec();
}

