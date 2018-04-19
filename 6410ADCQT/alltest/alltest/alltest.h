#ifndef ALLTEST_H
#define ALLTEST_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <alltestui.h>


/*
namespace Ui {
class Widget;
}
*/

class alltest
{

    
private:
    alltestui *m_ui;

    explicit alltest(QWidget *parent = 0);


    bool construct();



    
public:
    static alltest* newinstance();
    void show();
    ~alltest();
};

#endif // WIDGET_H
