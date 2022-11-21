#include "addsalle.h"
#include "ui_addsalle.h"
#include <QMessageBox>

AddSalle::AddSalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSalle)
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

AddSalle::~AddSalle()
{
    delete ui;
}

void AddSalle::on_AddButton_clicked()
{
    QString Cycle,Filiere, Semestre,NumeroSalle ;
    Cycle = ui->Cycle->text();
    Filiere = ui->Filiere->text();
    Semestre = ui->Semestre->text();
    NumeroSalle = ui->NumeroSalle->text();
    if(Cycle=="" || Filiere=="" ||Semestre=="" || NumeroSalle==""){
        QMessageBox::warning(this,"Signup","Veuillez remplir tout les champs s'il vous plaît.");
    }
    else{

//cherche si la salle existe
    auto search = QSqlQuery(db);
    QString searchAcc = {"SELECT Numero_Salle FROM Salle WHERE Numero_Salle='"+NumeroSalle+"'" };
    if(!search.exec(searchAcc))
        qDebug() << "Cannot select";
    int count = 0;
    while(search.next())
        count++;

if(count>=1)
    QMessageBox::warning(this, "Failed", "La salle existe deja!");

else {
        QSqlQuery *qry = new QSqlQuery() ;
        qry->prepare("INSERT INTO Salle (Cycle,Filiere,Semestre,Numero_Salle)" "VALUES (?,?,?,?);");
        qry->addBindValue(Cycle);
        qry->addBindValue(Filiere);
        qry->addBindValue(Semestre);
        qry->addBindValue(NumeroSalle);
        qry->exec();
        QMessageBox::information(this,"valider","La salle a été ajoutée avec succès");
        this->hide();

    }
    }
}

void AddSalle::on_SalleReturn_clicked()
{
    this->hide();
}

