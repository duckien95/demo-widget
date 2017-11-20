#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QList>
#include <QMainWindow>

namespace Ui {
class mywidget;
}

class Scribble;

class mywidget : public QMainWindow
{
    Q_OBJECT

public:
    //explicit mywidget(QWidget *parent = 0);
    //~mywidget();
    mywidget();
protected:
//    void closeEvent(QCloseEvent *event) override;

private slots:
//    void open();
//    void save();
//    void penColor();
//    void penWidth();
//    void about();

private:
    void createActions();
    void createMenus();
//    bool maybeSave();
//    bool saveFile(const QByteArray &fileFormat);


    Scribble *scribble;

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    //Ui::mywidget *ui;
};

#endif
