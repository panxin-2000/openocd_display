//
// Created by panxin on 2024/1/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_new_wight.h" resolved

#include <QStringConverter>
#include <QArgument>
#include "new_wight.h"
#include "ui_new_wight.h"
#include "QFileDialog"
#include "QThread"
#include <QRegularExpression>


new_wight::new_wight(QWidget *parent) :
        QWidget(parent), ui(new Ui::new_wight) {
    ui->setupUi(this);
//    this->tcpClient.
    connect(&this->tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(&this->process, SIGNAL(readyReadStandardError()), this,
            SLOT(write_stand_error_to_plain_text()));
    connect(&this->process, SIGNAL(readyReadStandardOutput()), this,
            SLOT(write_stand_output_to_plain_text()));
//    new_wight::connect(parent, SIGNAL(port_send(int)), parent, SLOT(on_reading_rtt_clicked(int)));

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

void new_wight::write_stand_error_to_plain_text() {
    QByteArray qba = process.readAllStandardError();
    auto toUtf16 = QStringDecoder(QStringDecoder::System);
    QString string = toUtf16(qba);
    ui->openocd_result->appendPlainText(string);
    int ab = string.indexOf("for rtt connections");
    if (ab >= 0) {
        QRegularExpression rx("[0-9]+");
        QRegularExpressionMatch match = rx.match(string);
        if (match.hasMatch()) {
            QString matched = match.captured(0);
            int number = matched.split(" ")[0].toInt();
            //下一步需要发射一个信号去执行读取log的按钮接口
            qInfo()<<number;

            tcpClient.connectToHost("127.0.0.1", (quint16) number);

        }
    } else {
        //没有匹配到，但是是每行都会去判断，所以不能输出错误信息
    }
}

void new_wight::write_stand_output_to_plain_text() {
    QByteArray qba = process.readAllStandardOutput();
    auto toUtf16 = QStringDecoder(QStringDecoder::System);
    QString string = toUtf16(qba);
    ui->openocd_result->appendPlainText(string);
    //能正常执行到这里就可以判断执行是成功的。
    //识别是否包含for rtt connections
    int ab = string.indexOf("for rtt connections");
    if (ab >= 0) {
        QRegularExpression rx("[0-9]+");
        QRegularExpressionMatch match = rx.match(string);
        if (match.hasMatch()) {
            QString matched = match.captured(0);
            int number = matched.split(" ")[0].toInt();
            //下一步需要发射一个信号去执行读取log的按钮接口
            qInfo()<<number;

            tcpClient.connectToHost("127.0.0.1", (quint16) number);
            if (!openocd_log_file.open(QIODevice::WriteOnly)) {
                qInfo("create openocd_log_file error\n");
            }
            this->openocd_log_file.close();
        }
    } else {
        //没有匹配到，但是是每行都会去判断，所以不能输出错误信息
    }


}

void new_wight::on_run_program_clicked() {

    this->process.start(program, arguments);

    QProcess::ProcessState openocd_status = this->process.state();
    if (openocd_status == QProcess::NotRunning) {
        //The process is not running
        qInfo("The process is not running");

    } else if ((openocd_status == QProcess::Starting) || (openocd_status == QProcess::Running)) {
        //The process is starting, but the program has not yet been invoked.
        QDateTime dateTime = QDateTime::currentDateTime();
        QString string = dateTime.toString("yyyy-MM-dd-hh-mm-ss");
        this->openocd_log_file.setFileName(string);
    }
}

void new_wight::on_kill_program_clicked() {
    this->process.kill();
    qInfo("killed openocd process\n");
}

void new_wight::on_reading_rtt_clicked() {
    tcpClient.connectToHost("127.0.0.1", 9010);
}

void new_wight::on_close_rtt_clicked() {
    if (tcpClient.state() == QAbstractSocket::ConnectedState)
        tcpClient.disconnectFromHost();
}

void new_wight::onSocketReadyRead() {//readyRead()信号槽函数
    while (tcpClient.canReadLine()) {
        QString string = tcpClient.readLine();
        ui->rtt_result->appendPlainText(string);
        if (!openocd_log_file.open(QIODevice::Append)) {
            qInfo("create openocd_log_file error\n");
        }
        QByteArray strBytes = string.toUtf8();//转换为字节数组
        this->openocd_log_file.write(strBytes, strBytes.length());  //写入文件
        this->openocd_log_file.close();
    }

//        openocd_log_file.
//        this->openocd_log_file.  //添加在文件后添加语句的内容。

}