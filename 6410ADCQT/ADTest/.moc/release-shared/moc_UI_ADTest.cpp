/****************************************************************************
** QADForm meta object code from reading C++ file 'UI_ADTest.h'
**
** Created: Fri Jan 28 23:12:04 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../.ui/release-shared/UI_ADTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QADForm::className() const
{
    return "QADForm";
}

QMetaObject *QADForm::metaObj = 0;

#ifdef QWS
static class QADForm_metaObj_Unloader {
public:
    ~QADForm_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QADForm" );
    }
} QADForm_metaObj_unloader;
#endif

void QADForm::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("QADForm","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QADForm::tr(const char* s)
{
    return qApp->translate( "QADForm", s, 0 );
}

QString QADForm::tr(const char* s, const char * c)
{
    return qApp->translate( "QADForm", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QADForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QADForm", "QWidget",
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
