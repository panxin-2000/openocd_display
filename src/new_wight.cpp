//
// Created by panxin on 2024/1/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_new_wight.h" resolved

#include <QStringConverter>
#include "new_wight.h"
#include "ui_new_wight.h"
#include "QFileDialog"
#include "QThread"

new_wight::new_wight(QWidget *parent) :
        QWidget(parent), ui(new Ui::new_wight) {
    ui->setupUi(this);
}

new_wight::~new_wight() {
    delete ui;
}

void new_wight::on_select_cfg_file_clicked() {
    QString tem = QFileDialog::getOpenFileName();
    if (!tem.isEmpty()) {
        ui->openocd_result->appendPlainText(tem);
        arguments << "-f" << tem;
    }

}

void new_wight::on_run_program_clicked() {
    this->process.start(program, arguments);
    if (process.waitForFinished(5000)) {
        ui->openocd_result->appendPlainText("finish\n");
        {
            QByteArray qba = process.readAllStandardError();
            auto toUtf16 = QStringDecoder(QStringDecoder::System);
            QString string = toUtf16(qba);
            ui->openocd_result->appendPlainText(string);
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
//    QThread::sleep(50);
//    process.kill();
}

void new_wight::on_kill_program_clicked() {
//    this->process.start(program, arguments);
//    if (process.waitForFinished(5000)) {
//        ui->plainTextEdit->appendPlainText("finish\n");
//        {
//            QByteArray qba = process.readAllStandardError();
//            auto toUtf16 = QStringDecoder(QStringDecoder::System);
//            QString string = toUtf16(qba);
//            ui->plainTextEdit->appendPlainText(string);
//        }
//        {
//            QByteArray qba = process.readAllStandardOutput();
//            auto toUtf16 = QStringDecoder(QStringDecoder::System);
//            QString string = toUtf16(qba);
//            qDebug("%s\n", string.toStdString().c_str());
//        }
//    } else {
//        qInfo("not finish\n");
//    }
    QThread::sleep(50);
    process.kill();
}