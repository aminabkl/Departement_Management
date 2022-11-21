#include "editsalle.h"
#include "ui_editsalle.h"
#include <QMessageBox>

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
void EditSalle::on_AddButton_clicked()
{

}


void EditSalle::on_SalleReturn_clicked()
{
this->hide();
}



