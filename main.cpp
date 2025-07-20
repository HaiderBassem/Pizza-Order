#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    float ToppingsPrice = 5.0;
    float CrustTypePrice = 10.0;
    float SizePrice = 10.0;

    MainWindow w(ToppingsPrice, CrustTypePrice, SizePrice);
    w.show();
    return a.exec();
}
