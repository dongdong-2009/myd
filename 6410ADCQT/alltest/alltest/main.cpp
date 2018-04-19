
#include <QApplication>
#include "alltest.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    alltest *alltest = alltest::newinstance();
    int ret=0;
    if(alltest != NULL)
    {
        alltest->show();
        ret = a.exec();
        delete alltest;
    }

    return ret;
}
