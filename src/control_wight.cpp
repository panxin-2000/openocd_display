//
// Created by panxin on 2024/1/19.
//

// You may need to build the project (run Qt uic code generator) to get "ui_new_wight.h" resolved

#include <QStringConverter>
#include <QArgument>
#include "control_wight.h"
#include "ui_control_wight.h"
#include "QFileDialog"
#include "QThread"
#include <QRegularExpression>
#include <iostream>


control_wight::control_wight(QWidget *parent) :
        QWidget(parent), ui(new Ui::control_wight) {
    ui->setupUi(this);
    ui->rtt_result->setReadOnly(true);
//    ui->rtt_result->setFont(true);
    ui->openocd_result->setReadOnly(true);
    ui->rtt_result->setStyleSheet("background: #000000;");

//    this->tcpClient.
    connect(&this->tcpClient, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
    connect(&this->process, SIGNAL(readyReadStandardError()), this,
            SLOT(write_stand_error_to_plain_text()));
    connect(&this->process, SIGNAL(readyReadStandardOutput()), this,
            SLOT(write_stand_output_to_plain_text()));

//仔细看了看Cheetah-Software这个工程，很少用到connect函数，原因和项目的任务是有关的。
//    control_wight::connect(parent, SIGNAL(port_send(int)), parent, SLOT(on_reading_rtt_clicked(int)));

}

control_wight::~control_wight() {
    delete ui;
}

void control_wight::on_select_RTT_cfg_file_clicked() {
    QString tem = QFileDialog::getOpenFileName();
    if (!tem.isEmpty()) {
        //如果被选择的文件名不是空的，就添加到configFile
        configFile.set_RTT_cfg_file_arguments(tem);
    }
}

void control_wight::on_select_download_cfg_file_clicked() {
    QString tem = QFileDialog::getOpenFileName();
    if (!tem.isEmpty()) {
        //如果被选择的文件名不是空的，就添加到configFile
        configFile.set_download_cfg_file_arguments(tem);
    }
}

void control_wight::on_select_download_file_clicked() {
    QString tem = QFileDialog::getOpenFileName();
    if (!tem.isEmpty()) {
        //如果被选择的文件名不是空的，就添加到configFile
        configFile.set_elf_file_path(tem);
    }
}


void control_wight::write_stand_error_to_plain_text() {
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
            qInfo() << number;
            tcpClient.connectToHost("127.0.0.1", (quint16) number);
        }
    } else {
        //没有匹配到，但是是每行都会去判断，所以不能输出错误信息
    }
}

void control_wight::write_stand_output_to_plain_text() {
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
            qInfo() << number;

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

void control_wight::on_reading_rtt_clicked() {
//配置要执行的命令以及参数
    QStringList arguments;
    arguments.clear();
    QString tem = configFile.read_RTT_cfg_file_arguments();
    if (!tem.isEmpty()) {
        arguments << "-f" << tem;
        this->process.start(program, arguments);
        QProcess::ProcessState openocd_status = this->process.state();
        if (openocd_status == QProcess::NotRunning) {
            //The process is not running
            qInfo("The process is not running");

        } else if ((openocd_status == QProcess::Starting) || (openocd_status == QProcess::Running)) {
            //The process is starting, but the program has not yet been invoked.
            QDateTime dateTime = QDateTime::currentDateTime();
            QString string = dateTime.toString("yyyy-MM-dd-hh-mm-ss") + ".log";
            this->openocd_log_file.setFileName(string);
        }
    } else {
        qInfo("openocd process no arguments\n");
    }
}

void control_wight::on_kill_program_clicked() {
    this->process.kill();
    qInfo("killed openocd process\n");
}


void control_wight::on_download_elf_program_clicked() {
//    /usr/bin/openocd -f /home/panxin/CLionProjects/stm32_log_example/openocd_config/stm32h750vbt6.cfg
//    -c "program \"/home/panxin/CLionProjects/stm32_log_example/cmake-build-debug/stm32_log_example.elf\""
//    -c reset -c shutdown    QStringList arguments;
    QString cfg_file = configFile.read_set_download_cfg_file_arguments();
    if (cfg_file.isEmpty()) {
        qInfo("cfg_file.isEmpty()\n");
        return;
    }
    QString download_file = configFile.read_elf_file_path();
    if (download_file.isEmpty()) {
        qInfo("download_file.isEmpty()\n");
        return;
    }
    QString download_program = "/usr/bin/openocd -f " + cfg_file + " -c \"program \\\"" + download_file + "\\\"\"" +
    " -c reset -c shutdown";
    qInfo("%s\n", download_program.toStdString().data());
    system(download_program.toStdString().data());
}

//void control_wight::on_reading_rtt_clicked() {
//    tcpClient.connectToHost("127.0.0.1", 9010);
//}

void control_wight::on_close_rtt_clicked() {
    if (tcpClient.state() == QAbstractSocket::ConnectedState)
        tcpClient.disconnectFromHost();
}

void control_wight::onSocketReadyRead() {//readyRead()信号槽函数
    while (tcpClient.canReadLine()) {
        QString string = tcpClient.readLine();
        if (!openocd_log_file.open(QIODevice::Append)) {
            qInfo("create openocd_log_file error\n");
        }
        QByteArray strBytes = string.toUtf8();//转换为字节数组
        this->openocd_log_file.write(strBytes, strBytes.length());  //写入文件
        this->openocd_log_file.close();
        //
        QString tem_033 = "\033[";
//        QChar tem_00 = '\033';
//        int a = string.compare(tem_033, Qt::CaseInsensitive);
        int a = string.indexOf(tem_033, Qt::CaseInsensitive);
        if (a >= 0) {
            QString tem = string.mid(2, 2);
            bool tem_bool = false;
            uint color = tem.toUInt(&tem_bool, 10);
            QTextCharFormat tem_QTextCharFormat;
            switch (color) {//VT100颜色表
                case 30:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::black)));
                    break;
                case 31:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::red)));
                    break;
                case 32:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::green)));
                    break;
                case 33:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::yellow)));
                    break;
                case 34:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::blue)));
                    break;
                case 35:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::yellow)));
                    break;
                case 36:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::cyan)));
                    break;
                case 37:
                    tem_QTextCharFormat.setForeground(QBrush(QColor(Qt::white)));
                    break;
                default:
                    break;
            }
//            tem_QTextCharFormat.setBackground(QBrush(QColor(Qt::black)));
            ui->rtt_result->mergeCurrentCharFormat(tem_QTextCharFormat);
            int b = string.indexOf(tem_033, 8, Qt::CaseInsensitive);
            string = string.mid(8, b - 7);
        }

        //先存储原始数据

        //首先需要搞清楚控制台显示颜色的规则
        //然后再去分割字符，分清楚那些是现实颜色的字符，那些是需要显示的字符，那些是表示颜色或者控制行的字符
//        u"\033[32;22mD/main            [41025] range time 548\033[0m\r\n"
//        u"\033[35;22mA/main            [43349] range time 139\033[0m\r\n"
//u"\033[33;22mW/main            [44373] range time 493\033[0m\r\n"
//u"\033[36;22mI/main            [44610] range time 236\033[0m\r\n"
//u"\033[34;22mV/main            [45596] range time 560\033[0m\r\n"
//还差一个应该是stm程序错误导致的没有现实出来

//        不同的设置不同的颜色或者其他的内容
        //分割字符，


        //颜色搞定了，然后还有其他的问题，比如文字大小，有些特殊字符不应该显示，还有就是光标会一直向末尾跳动（这个可能变成只读之后会好）
        //字体也是需要更改的，特殊字符不现实暂时搞定了
        //可以通过qtdesigner设置字体和文字大小

        ui->rtt_result->appendPlainText(string);
        ui->rtt_result->moveCursor(QTextCursor::End);
        ui->rtt_result->textCursor().deletePreviousChar();


    }

//        openocd_log_file.
//        this->openocd_log_file.  //添加在文件后添加语句的内容。

}