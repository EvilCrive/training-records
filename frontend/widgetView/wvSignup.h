#ifndef WVSIGNUP_H
#define WVSIGNUP_H

#include <QWidget>
#include <QLineEdit>

class WV_Signup : public QWidget {
    Q_OBJECT
private :
    QLineEdit* username;
    QLineEdit* password;
public :
    WV_Signup(QWidget* = nullptr);
};

#endif
