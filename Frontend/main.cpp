//HEADERS
#include "constants.h"
#include "mainwindow.h"

//QT
#include <QApplication>

int main(int argc, char *argv[]) //At some point organize the #includes
{
    QApplication app(argc, argv);
    MainWindow window {};
    window.resize(constant::WIDTH, constant::HEIGHT);
    window.show();
    return app.exec();
}
