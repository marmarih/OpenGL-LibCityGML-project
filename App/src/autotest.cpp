#include "autotest.h"

using namespace std;

autoTest::autoTest()
{
}

void autoTest::runTests()
{
    char *_argv[0];

    camTest camT;
    cgmlTest cgmlT;
    glwidgetTest glwT;

    QTest::qExec(&camT,0,_argv);
    QTest::qExec(&cgmlT,0,_argv);
    QTest::qExec(&glwT,0,_argv);
}
