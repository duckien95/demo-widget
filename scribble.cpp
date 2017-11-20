#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif

#include "scribble.h"

//! [0]
Scribble::Scribble(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
//    modified = false;
//    scribbling = false;
//    myPenWidth = 1;
//    myPenColor = Qt::blue;
}
