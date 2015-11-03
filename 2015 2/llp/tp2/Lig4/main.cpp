#include "Lig4.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    while(1){
        Lig4 w;
        w.show();
        a.exec();

        if(!w.restart)
            break;
    }

    return 0;
}
