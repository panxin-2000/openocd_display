/********************************************************************************
** Form generated from reading UI file 'new_wight.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_wight
{
public:
    QPushButton *select_cfg_file;
    QPushButton *run_program;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *new_wight)
    {
        if (new_wight->objectName().isEmpty())
            new_wight->setObjectName("new_wight");
        new_wight->resize(633, 584);
        select_cfg_file = new QPushButton(new_wight);
        select_cfg_file->setObjectName("select_cfg_file");
        select_cfg_file->setGeometry(QRect(170, 140, 75, 23));
        run_program = new QPushButton(new_wight);
        run_program->setObjectName("run_program");
        run_program->setGeometry(QRect(250, 140, 75, 23));
        label = new QLabel(new_wight);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 140, 53, 15));
        plainTextEdit = new QPlainTextEdit(new_wight);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(90, 190, 241, 191));

        retranslateUi(new_wight);

        QMetaObject::connectSlotsByName(new_wight);
    } // setupUi

    void retranslateUi(QWidget *new_wight)
    {
        new_wight->setWindowTitle(QCoreApplication::translate("new_wight", "new_wight", nullptr));
        select_cfg_file->setText(QCoreApplication::translate("new_wight", "\351\200\211\346\213\251cfg\346\226\207\344\273\266", nullptr));
        run_program->setText(QCoreApplication::translate("new_wight", "\346\211\247\350\241\214\347\250\213\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("new_wight", "openocd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_wight: public Ui_new_wight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WIGHT_H
