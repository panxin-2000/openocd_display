//
// Created by panxin on 24-4-21.
//

#ifndef OPENOCD_DISPLAY_CONFIG_FILE_H
#define OPENOCD_DISPLAY_CONFIG_FILE_H

#include <QWidget>
#include <QFile>

class Config_file {
public:
    Config_file();

    ~Config_file();

    bool config_file_init(void);

    bool set_RTT_cfg_file_arguments(QString Process_arguments);

    bool set_download_cfg_file_arguments(QString Process_arguments);

    bool set_elf_file_path(QString elf_file_path);

    bool save_log_file_path(QString log_file_path);

    bool save_config_file();

    const QString read_Process_arguments() {
        return Process_arguments;
    };

    const QString read_elf_file_path() {
        return elf_file_path;
    };
    const QString read_log_file_path() {
        return log_file_path;
    };


private:
    QString Process_arguments;
    QString elf_file_path;
    QString log_file_path;
    QFile config_file_file_descriptor;
};

#endif //OPENOCD_DISPLAY_CONFIG_FILE_H
