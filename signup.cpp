#include "signup.h"
#include "ui_signup.h"
#include "login.h"
#include <QMessageBox>

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
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

Signup::~Signup()
{
    delete ui;
}

void Signup::on_SignupButton_clicked()
{

    QString Username,Email, Password,Verify_pass ;
    Username = ui->Username->text();
    Email = ui->Email->text();
    Password = ui->Password->text();
    Verify_pass = ui->Verify_pass->text();
    if(Username=="" || Email=="" ||Password=="" || Verify_pass==""){
        QMessageBox::warning(this,"Signup","Veuillez remplir tout les champs s'il vous plaît.");
    }
    else{

    //cherche si le compte existe
        auto search = QSqlQuery(db);
        QString searchAcc = {"SELECT Email FROM Login WHERE Email='"+Email+"'" };
        if(!search.exec(searchAcc))
            qDebug() << "Cannot select";
        int count = 0;
        while(search.next())
            count++;

    if(count>=1)
        QMessageBox::warning(this, "Failed", "Compte déjà existant!");

    else {
        if (Password == Verify_pass){
            QSqlQuery *qry = new QSqlQuery() ;
            qry->prepare("INSERT INTO Login (Username,Email,Password)" "VALUES (?,?,?);");
            qry->addBindValue(Username);
            qry->addBindValue(Email);
            qry->addBindValue(Password);
            qry->exec();
            QMessageBox::information(this,"valider","Votre compte a été créé avec succès");
            this->hide();
                Login Login;
                Login.exec();
        }
        else
            QMessageBox::warning(this,"Signup","Mot de passe de vérification n'est pas juste");
    }
}}
void Signup::on_LoginReturn_clicked()
{

    this->hide();
        Login Login;
        Login.exec();
}

