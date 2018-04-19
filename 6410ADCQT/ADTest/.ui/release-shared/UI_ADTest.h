/****************************************************************************
** Form interface generated from reading ui file 'UI_ADTest.ui'
**
** Created: Fri Jan 28 22:31:09 2011
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef QADFORM_H
#define QADFORM_H

#include <qvariant.h>
#include <qwidget.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class QLabel;
class QLineEdit;

class QADForm : public QWidget
{ 
    Q_OBJECT

public:
    QADForm( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QADForm();

    QLabel* TextLabel1;
    QLineEdit* m_value;

};

#endif // QADFORM_H
