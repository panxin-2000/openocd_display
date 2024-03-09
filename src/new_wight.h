//
// Created by panxin on 2024/1/19.
//

#ifndef QT_NEW_WIGHT_H
#define QT_NEW_WIGHT_H

#include <QWidget>
#include "QProcess"
#include    <QTcpSocket>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class new_wight; }
QT_END_NAMESPACE

class new_wight : public QWidget {
    Q_OBJECT

public:
    explicit new_wight(QWidget *parent = nullptr);

    ~new_wight() override;

private:
    QTcpSocket tcpClient;  //socket
    Ui::new_wight *ui;
    QStringList arguments;
    QString program = "openocd";
    QProcess process;
    QFile openocd_log_file;

private
    slots:

    void on_select_cfg_file_clicked();

    void write_stand_error_to_plain_text();

    void write_stand_output_to_plain_text();

    void on_run_program_clicked();

    void on_kill_program_clicked();

    void on_reading_rtt_clicked();

    void on_close_rtt_clicked();

    void onSocketReadyRead();//读取socket传入的数据
};


#endif //QT_NEW_WIGHT_H
