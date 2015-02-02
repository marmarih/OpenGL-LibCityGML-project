#include "mainwindow.h"
#include <QApplication>
#include "autotest.h"

int main(int argc, char *argv[])
{
    if(argc>1 && argv[1][0]=='t')
    {
        autoTest::runTests();
        return 0;
    }

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
