#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("MAI 221_222 2012");
    a.setApplicationName("Schedule");
    MainWindow w;
    w.show();

    return a.exec();
}
