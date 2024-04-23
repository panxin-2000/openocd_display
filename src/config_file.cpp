//
// Created by panxin on 24-4-21.
//

#include <QTextStream>
#include "config_file.h"

bool Config_file::config_file_init() {


}


Config_file::Config_file() {
    this->config_file_file_descriptor.setFileName("/home/panxin/.config/openocd-display");
    if (this->config_file_file_descriptor.exists()) {
        //存在
        if (!config_file_file_descriptor.open(QIODevice::ReadOnly)) {
            qInfo("create openocd_log_file error\n");
        } else {
            //成功打开
            QTextStream in(&config_file_file_descriptor);
            QString line_1 = in.readLine();
            this->RTT_cfg_file_arguments = line_1;
            QString line_2 = in.readLine();
            this->elf_file_path = line_2;
            QString line_3 = in.readLine();
            this->elf_cfg_file_arguments = line_3;
            this->config_file_file_descriptor.close();
        }
    } else {
        //不存在

    }
}

Config_file::~Config_file() {


}

bool Config_file::set_RTT_cfg_file_arguments(QString Process_arguments) {
    this->RTT_cfg_file_arguments = Process_arguments;
    this->save_config_file();
}

bool Config_file::set_elf_file_path(QString elf_file_path) {
    this->elf_file_path=elf_file_path;
    this->save_config_file();
}

bool Config_file::set_download_cfg_file_arguments(QString Process_arguments) {
    this->elf_cfg_file_arguments=Process_arguments;
    this->save_config_file();
}

bool Config_file::save_log_file_path(QString log_file_path) {

    this->save_config_file();
}

bool Config_file::save_config_file() {
    config_file_file_descriptor.open(QIODevice::WriteOnly | QIODeviceBase::Text);
    //成功打开
    QTextStream out(&config_file_file_descriptor);
    out << RTT_cfg_file_arguments << "\n";
    out << elf_file_path << "\n";
    out << elf_cfg_file_arguments << "\n";

    this->config_file_file_descriptor.close();

}