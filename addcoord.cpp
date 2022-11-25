#include "addcoord.h"
#include "ui_addcoord.h"
#include <QMessageBox>

AddCoord::AddCoord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCoord)
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

AddCoord::~AddCoord()
{
    delete ui;
}

void AddCoord::on_AddButton_clicked()
{
    QString NameCoord,Email,Cycle,Filiere ;
    Cycle = ui->Cycle->text();
    Filiere = ui->Filiere->text();
    NameCoord = ui->NameCoord->text();
    Email = ui->Email->text();
    if(NameCoord=="" ||Email=="" ||  Cycle=="" || Filiere==""){
        QMessageBox::warning(this,"Coord","Veuillez remplir tout les champs s'il vous plaît.");
    }
    else{}

//cherche si la salle existe
    auto search = QSqlQuery(db);
    QString searchCoord = {"SELECT Name FROM Coordinateur WHERE Name='"+NameCoord+"'" };
    if(!search.exec(searchCoord))
        qDebug() << "Cannot select";
    int count = 0;
    while(search.next())
        count++;
    if(count>=1)
        QMessageBox::warning(this, "Failed", "Le coordinateur existe deja!");

    else {
        QSqlQuery *qry = new QSqlQuery() ;
        qry->prepare("INSERT INTO Coordinateur (Name,Email,Cycle,Filiere)" "VALUES (?,?,?,?);");
        qry->addBindValue(NameCoord);
        qry->addBindValue(Email);
        qry->addBindValue(Cycle);
        qry->addBindValue(Filiere);
        qry->exec();
        QMessageBox::information(this,"valider","La coordinateur a été ajoutée avec succès");
        this->hide();

    }
}


void AddCoord::on_CoordReturn_clicked()
{

}

