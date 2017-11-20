

#include <QtWidgets>

#include "mywidget.h"
#include "ui_mywidget.h"
#include "scribble.h"

//mywidget::mywidget(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::mywidget)
//{
//    ui->setupUi(this);
//}

//mywidget::~mywidget()
//{
//    delete ui;
//}

//! [0]
mywidget::mywidget()
{
    scribble = new Scribble;
    setCentralWidget(scribble);

    createActions();
    createMenus();

    setWindowTitle(tr("Scribble"));
    resize(500, 500);
}
//! [0]

//void mywidget::closeEvent(QCloseEvent *event)

//{
//    if (maybeSave()) {
//        event->accept();
//    } else {
//        event->ignore();
//    }
//}

void mywidget::createMenus()

{
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addAction(penColorAct);
    optionMenu->addAction(penWidthAct);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
}

void mywidget::createActions()

{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    foreach (QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());

        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        saveAsActs.append(action);
    }

    printAct = new QAction(tr("&Print..."), this);
    connect(printAct, SIGNAL(triggered()), scribble, SLOT(print()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    penColorAct = new QAction(tr("&Pen 1..."), this);
    connect(penColorAct, SIGNAL(triggered()), this, SLOT(penColor()));

    penWidthAct = new QAction(tr("Pen 2..."), this);
    connect(penWidthAct, SIGNAL(triggered()), this, SLOT(penWidth()));

    clearScreenAct = new QAction(tr("&Pen 3"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()),
            scribble, SLOT(clearImage()));

    aboutAct = new QAction(tr("&About 1"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About 2"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

