#include "../../widgetView/User.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>

User::User(QWidget* p) : QWidget(p) {
    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    QHBoxLayout* nameLayout = new QHBoxLayout{this};
    QHBoxLayout* surnameLayout = new QHBoxLayout{this};
    QHBoxLayout* usernameLayout = new QHBoxLayout{this};
    QHBoxLayout* passwordLayout = new QHBoxLayout{this};
    QLabel* nameLabel = new QLabel{this};
    QLabel* surnameLabel = new QLabel{this};
    QLabel* usernameLabel = new QLabel{this};
    QLabel* passwordLabel = new QLabel{this};
    nameLineEdit = new QLineEdit{this};
    surnameLineEdit = new QLineEdit{this};
    usernameLineEdit = new QLineEdit{this};
    passwordLineEdit = new QLineEdit{this};
    QPushButton* saveButton = new QPushButton{this};

    nameLabel -> setText("Name:  ");
    surnameLabel -> setText("Surname:  ");
    usernameLabel -> setText("Username:  ");
    passwordLabel -> setText("Password:  ");
    saveButton -> setText("Save Credentials");
    
    setLayout(mainLayout);
    nameLayout -> addWidget(nameLabel);
    nameLayout -> addWidget(nameLineEdit);
    mainLayout -> addLayout(nameLayout);
    surnameLayout -> addWidget(surnameLabel);
    surnameLayout -> addWidget(surnameLineEdit);
    mainLayout -> addLayout(surnameLayout);
    usernameLayout -> addWidget(usernameLabel);
    usernameLayout -> addWidget(usernameLineEdit);
    mainLayout -> addLayout(usernameLayout);
    passwordLayout -> addWidget(passwordLabel);
    passwordLayout -> addWidget(passwordLineEdit);
    mainLayout -> addLayout(passwordLayout);
    mainLayout -> addWidget(saveButton);

    setWindowTitle("User Page");
    setWindowFlag(Qt::Window);
    setWindowModality(Qt::WindowModal);
    show();
    QObject::connect(saveButton, &QPushButton::clicked, this, &User::updateCredentials);
}

void User::updateCredentials() try {/*
    bool isSuccessful = true;
    if (usernameLineEdit -> text() != QString::fromStdString(controller -> getCredential("username")) ||
      passwordLineEdit -> text() != QString::fromStdString(controller -> getCredential("password")) ||
      nameLineEdit -> text() != QString::fromStdString(controller -> getCredential("name")) ||
      surnameLineEdit -> text() != QString::fromStdString(controller -> getCredential("surname"))) {
        std::string newuser, olduser, password, name, surname;
        newuser = (usernameLineEdit -> text()).QString::toStdString();
        olduser = (controller -> getCredential("username"));
        password = (passwordLineEdit -> text()).QString::toStdString();
        name = (nameLineEdit -> text()).QString::toStdString();
        surname = (surnameLineEdit -> text()).QString::toStdString();

        isSuccessful = controller -> changeCredentials(newuser, olduser, password, name, surname);
    } else {
        QMessageBox::warning(this, "Change Credentials Error", "Nothing will happen, you didn't modified anything.");
    }
    if (isSuccessful == false) {
        QMessageBox::warning(this, "Change Credentials Error", "The change of credentials failed.\nThere were some problems with loading and/or saving the data.");
    }
    close();*/

} catch(BackendException* e){
    QMessageBox::warning(this, "Login Error", QString::fromStdString(e->getMessage()));
}

void User::setName(QString n) {
    nameLineEdit -> setText(n);
}

void User::setSurname(QString s) {
    surnameLineEdit -> setText(s);
}

void User::setUsername(QString u) {
    usernameLineEdit -> setText(u);
}

void User::setPassword(QString p) {
    passwordLineEdit -> setText(p);
}


/*
passwordLineEdit -> setText(QString::fromStdString(controller -> getCredential("password")));
usernameLineEdit -> setText(QString::fromStdString(controller -> getCredential("username")));
surnameLineEdit -> setText(QString::fromStdString(controller -> getCredential("surname")));
nameLineEdit -> setText(QString::fromStdString(controller -> getCredential("name")));   
*/