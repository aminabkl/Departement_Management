#include "login.h"
#include "ui_login.h"
#include "signup.h"
#include "salle.h"
#include <QMessageBox>
#include <QPixmap>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
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

    // Database connection
    db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/lenovo/Documents/QT/DepartmentDB.db");
        if(!db.open()){
            qDebug()<<"Can't connect to the database !";
        }
        else{
            qDebug()<<"Connected !";
        }
}

Login::~Login()
{
    delete ui;
}
void Login::on_loginButton_clicked()
{
    QString Email, Password;
    Email = ui->email->text();
    Password = ui->password->text();

    if(!db.isOpen()){
            qDebug()<<"Failed";
            return;
        }
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM Login WHERE Email='"+Email+"'and Password='"+Password+"'" )){
        int count=0;
                    while(qry.next()){
                        count++;
                        qDebug()<<count;
                    }
                    if(count==1 ){
                           this->hide();
                               Salle Salle;
                               Salle.exec();
                    }

                   else{
                    QMessageBox::warning(this,"Login","Incorrect, Vérifier votre email ou votre mot de passe");
}
}

}

void Login::on_Signup_Button_clicked()
{
    this->hide();
        Signup Signup;
        Signup.exec();
}
