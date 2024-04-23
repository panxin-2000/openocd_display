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

    //elf_cfg_file_arguments 的设置和读取

    bool set_download_cfg_file_arguments(QString Process_arguments);

    const QString read_set_download_cfg_file_arguments(){
        return elf_cfg_file_arguments;
    }
    //RTT_cfg_file_arguments 的设置和读取

    bool set_RTT_cfg_file_arguments(QString Process_arguments);

    const QString read_RTT_cfg_file_arguments() {
        return RTT_cfg_file_arguments;
    };

    //elf_file_arguments 的设置和读取

    bool set_elf_file_path(QString elf_file_path);

    const QString read_elf_file_path() {
        return elf_file_path;
    };



    bool save_log_file_path(QString log_file_path);

    bool save_config_file();

    const QString read_log_file_path() {
        return log_file_path;
    };


private:
    QString RTT_cfg_file_arguments;
    QString elf_cfg_file_arguments;
    QString elf_file_path;
    QString log_file_path;
    QFile config_file_file_descriptor;
};

#endif //OPENOCD_DISPLAY_CONFIG_FILE_H
