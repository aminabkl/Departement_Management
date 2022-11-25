#include "addprof.h"
#include "ui_addprof.h"
#include <QMessageBox>
addprof::addprof(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addprof)
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

addprof::~addprof()
{
    delete ui;
}

void addprof::on_AddButton_clicked()
{
    QString Nom,Email,Prenom;
    Nom = ui->Nom->text();
    Email = ui->Email->text();
    Prenom= ui->Prenom->text();



    if(Nom=="" || Email=="" || Prenom=="" ){
        QMessageBox::warning(this,"Prof","Veuillez remplir tout les champs s'il vous plaît.");
    }
    else{

//cherche si la salle existe
    auto search = QSqlQuery(db);
    QString searchAcc = {"SELECT Nom FROM Prof WHERE Nom='"+Nom+"'" };
    if(!search.exec(searchAcc))
        qDebug() << "Cannot select";
    int count = 0;
    while(search.next())
        count++;
    if(count>=1)
        QMessageBox::warning(this, "Failed", "Le professeur existe deja!");

    else {
        QSqlQuery *qry = new QSqlQuery() ;
        qry->prepare("INSERT INTO Prof (Nom,Email,Prenom)" "VALUES (?,?,?);");
        qry->addBindValue(Nom);
        qry->addBindValue(Email);
        qry->addBindValue(Prenom);

        qry->exec();
        QMessageBox::information(this,"valider","Le professeur a été ajouté avec succès");
        this->hide();

    }
    }
}

void addprof::on_SalleReturn_clicked()
{
 this->hide();
}
