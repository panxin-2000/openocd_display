/********************************************************************************
** Form generated from reading UI file 'new_wight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_WIGHT_H
#define UI_NEW_WIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_wight
{
public:
    QPushButton *select_cfg_file;
    QPushButton *run_program;
    QLabel *label;
    QPlainTextEdit *openocd_result;
    QPushButton *kill_program;
    QPlainTextEdit *rtt_result;
    QPushButton *reading_rtt;
    QPushButton *save_rtt;
    QPushButton *close_rtt;
    QLabel *label_2;
    QSpinBox *spinBox;

    void setupUi(QWidget *new_wight)
    {
        if (new_wight->objectName().isEmpty())
            new_wight->setObjectName(QString::fromUtf8("new_wight"));
        new_wight->resize(633, 584);
        select_cfg_file = new QPushButton(new_wight);
        select_cfg_file->setObjectName(QString::fromUtf8("select_cfg_file"));
        select_cfg_file->setGeometry(QRect(170, 140, 75, 23));
        run_program = new QPushButton(new_wight);
        run_program->setObjectName(QString::fromUtf8("run_program"));
        run_program->setGeometry(QRect(250, 140, 75, 23));
        label = new QLabel(new_wight);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 140, 53, 15));
        openocd_result = new QPlainTextEdit(new_wight);
        openocd_result->setObjectName(QString::fromUtf8("openocd_result"));
        openocd_result->setGeometry(QRect(90, 190, 241, 191));
        kill_program = new QPushButton(new_wight);
        kill_program->setObjectName(QString::fromUtf8("kill_program"));
        kill_program->setGeometry(QRect(340, 140, 75, 23));
        rtt_result = new QPlainTextEdit(new_wight);
        rtt_result->setObjectName(QString::fromUtf8("rtt_result"));
        rtt_result->setGeometry(QRect(330, 190, 241, 191));
        reading_rtt = new QPushButton(new_wight);
        reading_rtt->setObjectName(QString::fromUtf8("reading_rtt"));
        reading_rtt->setGeometry(QRect(420, 140, 75, 23));
        save_rtt = new QPushButton(new_wight);
        save_rtt->setObjectName(QString::fromUtf8("save_rtt"));
        save_rtt->setGeometry(QRect(500, 140, 75, 23));
        close_rtt = new QPushButton(new_wight);
        close_rtt->setObjectName(QString::fromUtf8("close_rtt"));
        close_rtt->setGeometry(QRect(420, 163, 75, 23));
        label_2 = new QLabel(new_wight);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 121, 53, 15));
        spinBox = new QSpinBox(new_wight);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(490, 107, 81, 32));
        spinBox->setSizeIncrement(QSize(0, 0));

        retranslateUi(new_wight);

        QMetaObject::connectSlotsByName(new_wight);
    } // setupUi

    void retranslateUi(QWidget *new_wight)
    {
        new_wight->setWindowTitle(QCoreApplication::translate("new_wight", "new_wight", nullptr));
        select_cfg_file->setText(QCoreApplication::translate("new_wight", "\351\200\211\346\213\251cfg\346\226\207\344\273\266", nullptr));
        run_program->setText(QCoreApplication::translate("new_wight", "\346\211\247\350\241\214\347\250\213\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("new_wight", "openocd", nullptr));
        kill_program->setText(QCoreApplication::translate("new_wight", "\347\273\223\346\235\237\347\250\213\345\272\217", nullptr));
        reading_rtt->setText(QCoreApplication::translate("new_wight", "\350\257\273\345\217\226log", nullptr));
        save_rtt->setText(QCoreApplication::translate("new_wight", "\344\277\235\345\255\230log", nullptr));
        close_rtt->setText(QCoreApplication::translate("new_wight", "\345\205\263\351\227\255log", nullptr));
        label_2->setText(QCoreApplication::translate("new_wight", "\347\253\257\345\217\243\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_wight: public Ui_new_wight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WIGHT_H
