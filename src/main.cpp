#include <QApplication>
#include <QPushButton>
#include "QProcess"
#include "QThread"
#include "new_wight.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);


    new_wight f;
    f.show();

    return QApplication::exec();
}
/*
void create_openocd_program(void) {
    QObject *openocd;

    QString program = "openocd";
    QStringList arguments;
    arguments << "-f" << "D:\\CLionProjects\\STM32H750vbt6\\openocd_config\\stlink-rtt.cfg";


    QProcess process;
    process.start(program, arguments);

    if (process.waitForFinished(5000)) {
        qInfo("finish\n");
        {
            QByteArray qba = process.readAllStandardError();
            auto toUtf16 = QStringDecoder(QStringDecoder::System);
            QString string = toUtf16(qba);
            qDebug("%s\n", string.toStdString().c_str());
        }
        {
            QByteArray qba = process.readAllStandardOutput();
            auto toUtf16 = QStringDecoder(QStringDecoder::System);
            QString string = toUtf16(qba);
            qDebug("%s\n", string.toStdString().c_str());
        }
    } else {
        qInfo("not finish\n");
    }
    QThread::sleep(50);
    process.kill();
}
*/