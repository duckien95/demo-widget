#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);
    mywidget window;
    window.show();
    return app.exec();
}
