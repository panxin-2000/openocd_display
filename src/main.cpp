#include <QApplication>
#include <QPushButton>
#include "QThread"
#include "control_wight.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    control_wight f;
    f.show();
    return QApplication::exec();
}