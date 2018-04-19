#ifndef ALLTESTUI_H
#define ALLTESTUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>


class alltestui : public QWidget
{
    Q_OBJECT
public:
    static alltestui *newinstance();
    ~alltestui();
    void show();

 private:
    explicit alltestui(QWidget *parent = 0);
    bool construct();
private slots:
    void onalltest();
    
private:
    QLineEdit *m_edit;
    QLineEdit *m_edit1;
    QLineEdit *m_edit2;
    QLineEdit *m_edit3;
    QLineEdit *m_edit4;

    QPushButton *m_button_clear;
    QPushButton *m_button_start;
    
};

#endif // ALLTESTUI_H
