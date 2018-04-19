#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fs.h>
#include <errno.h>
#include <string.h>
#include <qlineedit.h>
#include <qmessagebox.h>


#include "alltestui.h"

alltestui::alltestui(QWidget *parent) :
    QWidget(parent)
{
}

alltestui* alltestui::newinstance()
{
    alltestui *ret = new alltestui();
    if(NULL == ret || !ret->construct())
    {
        delete ret;
        ret = NULL;


    }
    return ret;
}
alltestui::~alltestui()
{}
void alltestui::show()
{
    QWidget::show();
printf("show\r\n");
}
bool alltestui::construct()
{
    bool ret = true;
    m_edit = new QLineEdit(this);
     printf("construct\r\n");
    if(m_edit!= NULL)
    {
        m_edit->move(10,10);
        m_edit->resize(240,30);
        m_edit->setReadOnly(true);
    }
    else
    {
        ret = false;
    }
    m_edit1 = new QLineEdit(this);
     printf("construct\r\n");
    if(m_edit1!= NULL)
    {
        m_edit1->move(10,50);
        m_edit1->resize(240,30);
        m_edit1->setReadOnly(true);
    }
    else
    {
        ret = false;
    }

    m_edit2 = new QLineEdit(this);
     printf("construct\r\n");
    if(m_edit2!= NULL)
    {
        m_edit2->move(10,90);
        m_edit2->resize(240,30);
        m_edit2->setReadOnly(true);
    }
    else
    {
        ret = false;
    }

    m_edit3 = new QLineEdit(this);
     printf("construct\r\n");
    if(m_edit3!= NULL)
    {
        m_edit3->move(10,130);
        m_edit3->resize(240,30);
        m_edit3->setReadOnly(true);
    }
    else
    {
        ret = false;
    }
    m_edit4 = new QLineEdit(this);
     printf("construct\r\n");
    if(m_edit4!= NULL)
    {
        m_edit4->move(10,170);
        m_edit4->resize(240,30);
        m_edit4->setReadOnly(true);
    }
    else
    {
        ret = false;
    }
    m_button_clear = new QPushButton(this);
    if(m_button_clear != NULL)
    {
        m_button_clear->move(10,220);
        m_button_clear->resize(40,40);
        m_button_clear->setText("clear");
        connect(m_button_clear,SIGNAL(clicked()),this,SLOT(onalltest()));
    }
    else
    {
        ret = false;
    }

    m_button_start = new QPushButton(this);
    if(m_button_start != NULL)
    {
        m_button_start->move(100,220);
        m_button_start->resize(40,40);
        m_button_start->setText("start");
        connect(m_button_start,SIGNAL(clicked()),this,SLOT(onalltest()));
    }
    else
    {
        ret = false;
    }
    return ret;
}
void alltestui::onalltest()
{
        printf("button clicked\r\n");
    QPushButton *button = dynamic_cast<QPushButton*>(sender());

    if(button != NULL)
    {
        QString buttontext = button->text();
        if(buttontext == "clear")
        {
            printf("clear clicked\r\n");
            m_edit->setText("");
            m_edit1->setText("");
            m_edit2->setText("");
            m_edit3->setText("");
            m_edit4->setText("");
        }
        else if(buttontext == "start")
        {
            QString m_edit_text = m_edit->text();
            QString m_edit1_text = m_edit1->text();
            QString m_edit2_text = m_edit2->text();
            QString m_edit3_text = m_edit3->text();
            QString m_edit4_text = m_edit4->text();
            int ge,shi,bai,qian,num;

            printf("start clicked\r\n");
         //   m_edit->setText("start");
            int fd = ::open("/dev/adc",0);
            if(fd < 0)
            {
                return;
            }
            char buffer[20]="";
            int len = ::read(fd,buffer,(sizeof buffer));
            if(len > 0)
            {

                m_edit->setText(buffer);
                /*if(len == 4)
                {
                    qian = buffer[0] - '0';
                    bai = buffer[1] - '0';
                    shi = buffer[2] - '0';
                    ge = buffer[3] - '0';
                }
                if(len == 3)
                {
                    qian = 0;
                    bai = buffer[0] - '0';
                    shi = buffer[1] - '0';
                    ge = buffer[2] - '0';
                }
                if(len == 2)
                {
                    qian = 0;
                    bai = 0;
                    shi = buffer[0] - '0';
                    ge = buffer[1] - '0';
                }
                if(len == 1)
                {
                    qian = 0;
                    bai = 0;
                    shi = 0;
                    ge = buffer[0] - '0';
                }
                num = (qian * 1000 + bai * 100 + shi * 10 + ge)*3.3*1000/1024;*/
                num = atoi(buffer);
                 printf("num = %d\r\n",num);
                num = num*3.3*1000/1024;
                if(num>=1000)
                {
                    buffer[0] = num/1000 + '0';
                    buffer[1] = 0x2e;
                    buffer[2] = num/100%10 + '0';
                    buffer[3] = num/10%10 + '0';
                    buffer[4] = num%10 + '0';
                    buffer[5] = '\0';
                }
                else
                {
                    buffer[0] = '0';
                    buffer[1] = 0x2e;
                    buffer[2] = num/100%10 + '0';
                    buffer[3] = num/10%10 + '0';
                    buffer[4] = num%10 + '0';
                    buffer[5] = '\0';
                }

                m_edit1->setText(buffer);
                m_edit2->setText(m_edit1_text);
                m_edit3->setText(m_edit2_text);
                m_edit4->setText(m_edit3_text);
            }
            ::close(fd);
        }
    }

}
