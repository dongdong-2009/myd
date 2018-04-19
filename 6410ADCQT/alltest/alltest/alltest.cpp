#include "alltest.h"


alltest::alltest(QWidget *parent)
{

}

bool alltest::construct()
{
    m_ui = alltestui::newinstance();
    return (m_ui != NULL);

}

alltest *alltest::newinstance()
{
    alltest *ret = new alltest();
    if((ret == NULL) || (!ret->construct()))
    {
        delete ret;
        ret = NULL;
    }
    return ret;

}

void alltest::show()
{
    m_ui->show();

}
alltest::~alltest()
{
    delete m_ui;
}
