#include "navmenu.h"
#include "ui_navmenu.h"
#include "login.h"
#include "salle.h"
#include "coordinateur.h"
#include "prof.h"
#include <QMessageBox>
#include <QPixmap>

NavMenu::NavMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavMenu)
{
    ui->setupUi(this);

    // LOGO
    QPixmap FstLogo(":/resources/img/FST-Tanger.png");
    int w1 = ui->FstLogo->width();
    int h1 = ui->FstLogo->height();
    ui->FstLogo->setPixmap(FstLogo.scaled(w1,h1,Qt::KeepAspectRatio));

    QPixmap UniLogo(":/resources/img/UAE-Logo.png");
    int w2 = ui->UniLogo->width();
    int h2 = ui->UniLogo->height();
    ui->UniLogo->setPixmap(UniLogo.scaled(w2,h2,Qt::KeepAspectRatio));

    //database coonection
    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/lenovo/Documents/QT/DepartmentDB.db");
        if(!db.open()){
            qDebug()<<"Can't connect to the database !";
        }
        else{
            qDebug()<<"Connected !";
        }

        //Salle Number
            QString SalleNumber;
            auto qrySalle = QSqlQuery(db);
            QString searchSalle = {"SELECT Salle_ID FROM Salle"};
            if(!qrySalle.exec(searchSalle))
                qDebug() << "Cannot select from salle";

            int countSalle=0;
            while(qrySalle.next())
                countSalle++;
            ui->SalleNumber->setText(QString::number(countSalle));

            //Prof Number
            QString ProfNumber;
            auto qryProf = QSqlQuery(db);
            QString searchProf = {"SELECT Prof_ID FROM Prof"};
            if(!qryProf.exec(searchProf))
            qDebug() << "Cannot select from prof";

                int countProf=0;
                while(qryProf.next())
                    countProf++;
                ui->ProfNumber->setText(QString::number(countProf));

                //Salle Number
                    QString CoordNumber;
                    auto qryCoord = QSqlQuery(db);
                    QString searchCoord = {"SELECT Coord_ID FROM Coordinateur"};
                    if(!qryCoord.exec(searchCoord))
                        qDebug() << "Cannot select from coordinateur";

                    int countCoord=0;
                    while(qryCoord.next())
                        countCoord++;
                    ui->CoordNumber->setText(QString::number(countCoord));

}

NavMenu::~NavMenu()
{
    delete ui;
}

void NavMenu::on_GoSalle_clicked()
{

    this->hide();
        Salle Salle;
        Salle.exec();
}


void NavMenu::on_GoProf_clicked()
{

    this->hide();
        prof prof;
       prof.exec();
}
void NavMenu::on_LogoutButton_clicked()
{
    this->hide();
    Login Login;
    Login.exec();
}

void NavMenu::on_GoCoord_clicked()
{
    this->hide();
        Coordinateur Coordinateur;
        Coordinateur.exec();
}

