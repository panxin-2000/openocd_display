#include <QApplication>
#include <QPushButton>
#include "QThread"
#include "new_wight.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    new_wight f;
    f.show();
    return QApplication::exec();
}