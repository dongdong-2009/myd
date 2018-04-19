#if !defined (__MAIN_FORM_H__)
# define __MAIN_FORM_H__

#include <qwidget.h>
#include <qlcdnumber.h>
#include <UI_ADTest.h> 

#define ADCDEVICE   "/dev/adc"

class QADTest: public QADForm
{
 Q_OBJECT
public:
    QADTest(QWidget * parent = 0, const char * name = 0, WFlags f = WType_TopLevel); 
    virtual ~QADTest(){}
protected:
    void timerEvent (QTimerEvent *);
};

#endif

