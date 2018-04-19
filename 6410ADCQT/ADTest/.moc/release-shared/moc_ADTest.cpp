/****************************************************************************
** QADTest meta object code from reading C++ file 'ADTest.h'
**
** Created: Fri Jan 28 23:12:03 2011
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.3.12   edited 2005-10-27 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "../../ADTest.h"
#include <qmetaobject.h>
#include <qapplication.h>
#ifdef QWS
#include <qobjectdict.h>
#endif



const char *QADTest::className() const
{
    return "QADTest";
}

QMetaObject *QADTest::metaObj = 0;

#ifdef QWS
static class QADTest_metaObj_Unloader {
public:
    ~QADTest_metaObj_Unloader()
    {
         if ( objectDict )
             objectDict->remove( "QADTest" );
    }
} QADTest_metaObj_unloader;
#endif

void QADTest::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QADForm::className(), "QADForm") != 0 )
	badSuperclassWarning("QADTest","QADForm");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString QADTest::tr(const char* s)
{
    return qApp->translate( "QADTest", s, 0 );
}

QString QADTest::tr(const char* s, const char * c)
{
    return qApp->translate( "QADTest", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* QADTest::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QADForm::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"QADTest", "QADForm",
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
