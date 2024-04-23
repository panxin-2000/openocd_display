//
// Created by panxin on 2024/1/19.
//

#ifndef QT_CONTROL_WIGHT_H
#define QT_CONTROL_WIGHT_H

#include <QWidget>
#include <QProcess>
#include <QTcpSocket>
#include <QFile>
#include "config_file.h"


QT_BEGIN_NAMESPACE
namespace Ui { class control_wight; }
QT_END_NAMESPACE

class control_wight : public QWidget {
Q_OBJECT


public:
    explicit control_wight(QWidget *parent = nullptr);

    ~control_wight() override;

private:

    QTcpSocket tcpClient;  //socket
    Ui::control_wight *ui;
    QString program = "openocd";
    QProcess process;
    QFile openocd_log_file;
    Config_file configFile;

signals:

    void port_send(int port);


public slots:
  /*
     *
     */
    void write_stand_error_to_plain_text();

    void write_stand_output_to_plain_text();

public slots:
/*
 * 当选择cfg文件的按钮后会调用该函数中的内容
 */
    void on_select_RTT_cfg_file_clicked();

    void on_select_download_cfg_file_clicked();

    void on_select_download_file_clicked();

    void on_download_elf_program_clicked();

//    void on_run_program_clicked();

    void on_kill_program_clicked();

    void on_reading_rtt_clicked();

    void on_close_rtt_clicked();

    void onSocketReadyRead();//读取socket传入的数据
};


#endif //QT_CONTROL_WIGHT_H
