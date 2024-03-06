//
// Created by panxin on 2024/1/19.
//

#ifndef QT_NEW_WIGHT_H
#define QT_NEW_WIGHT_H

#include <QWidget>
#include "QProcess"


QT_BEGIN_NAMESPACE
namespace Ui { class new_wight; }
QT_END_NAMESPACE

class new_wight : public QWidget {
Q_OBJECT

public:
    explicit new_wight(QWidget *parent = nullptr);

    ~new_wight() override;

private:
    Ui::new_wight *ui;
    QStringList arguments;
    QString program = "openocd";
    QProcess process;

private slots:
    void on_select_cfg_file_clicked();
    void on_run_program_clicked();
    void on_kill_program_clicked();

};


#endif //QT_NEW_WIGHT_H
