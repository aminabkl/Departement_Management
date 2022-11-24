#include "navmenu.h"
#include "ui_navmenu.h"
#include "login.h"
#include "salle.h"
#include <QMessageBox>
#include <QPixmap>

NavMenu::NavMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavMenu)
{
    ui->setupUi(this);

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
        auto qry = QSqlQuery(db);
        QString searchID = {"SELECT Salle_ID FROM Salle"};
        if(!qry.exec(searchID))
            qDebug() << "Cannot select from salle";

        int count=0;
        while(qry.next())
            count++;
        ui->SalleNumber->setText(QString::number(count));

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

//    this->hide();
//        Signup Signup;
//        Signup.exec();
}


void NavMenu::on_LogoutButton_clicked()
{
    this->hide();
    Login Login;
    Login.exec();
}

