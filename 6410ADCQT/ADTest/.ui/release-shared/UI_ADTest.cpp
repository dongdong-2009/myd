/****************************************************************************
** Form implementation generated from reading ui file 'UI_ADTest.ui'
**
** Created: Fri Jan 28 23:12:03 2011
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#include "UI_ADTest.h"

#include <qlabel.h>
#include <qlineedit.h>
#include <qlayout.h>
#include <qvariant.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/* 
 *  Constructs a QADForm which is a child of 'parent', with the 
 *  name 'name' and widget flags set to 'f' 
 */
QADForm::QADForm( QWidget* parent,  const char* name, WFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
	setName( "QADForm" );
    resize( 480, 272 ); 
    setMaximumSize( QSize( 480, 272 ) );
    setCaption( tr( "ADTest" ) );

    TextLabel1 = new QLabel( this, "TextLabel1" );
    TextLabel1->setGeometry( QRect( 130, 50, 180, 25 ) ); 
    TextLabel1->setText( tr( "Tesistance  Value" ) );

    m_value = new QLineEdit( this, "m_value" );
    m_value->setGeometry( QRect( 140, 110, 150, 33 ) ); 

    // tab order
}

/*  
 *  Destroys the object and frees any allocated resources
 */
QADForm::~QADForm()
{
    // no need to delete child widgets, Qt does it all for us
}

