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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_wight
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *select_cfg_file;
    QPushButton *run_program;
    QPushButton *kill_program;
    QPushButton *reading_rtt;
    QPushButton *close_rtt;
    QPushButton *save_rtt;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *rtt_result;
    QPlainTextEdit *openocd_result;

    void setupUi(QWidget *new_wight)
    {
        if (new_wight->objectName().isEmpty())
            new_wight->setObjectName(QString::fromUtf8("new_wight"));
        new_wight->setEnabled(true);
        new_wight->resize(613, 398);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(new_wight->sizePolicy().hasHeightForWidth());
        new_wight->setSizePolicy(sizePolicy);
        new_wight->setMaximumSize(QSize(1920, 1080));
        verticalLayout_2 = new QVBoxLayout(new_wight);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(12);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        label = new QLabel(new_wight);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        select_cfg_file = new QPushButton(new_wight);
        select_cfg_file->setObjectName(QString::fromUtf8("select_cfg_file"));

        horizontalLayout->addWidget(select_cfg_file);

        run_program = new QPushButton(new_wight);
        run_program->setObjectName(QString::fromUtf8("run_program"));

        horizontalLayout->addWidget(run_program);

        kill_program = new QPushButton(new_wight);
        kill_program->setObjectName(QString::fromUtf8("kill_program"));

        horizontalLayout->addWidget(kill_program);

        reading_rtt = new QPushButton(new_wight);
        reading_rtt->setObjectName(QString::fromUtf8("reading_rtt"));

        horizontalLayout->addWidget(reading_rtt);

        close_rtt = new QPushButton(new_wight);
        close_rtt->setObjectName(QString::fromUtf8("close_rtt"));

        horizontalLayout->addWidget(close_rtt);

        save_rtt = new QPushButton(new_wight);
        save_rtt->setObjectName(QString::fromUtf8("save_rtt"));

        horizontalLayout->addWidget(save_rtt);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(4, 4, 4, 4);
        rtt_result = new QPlainTextEdit(new_wight);
        rtt_result->setObjectName(QString::fromUtf8("rtt_result"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rtt_result->sizePolicy().hasHeightForWidth());
        rtt_result->setSizePolicy(sizePolicy1);
        rtt_result->setBaseSize(QSize(0, 0));

        horizontalLayout_2->addWidget(rtt_result);

        openocd_result = new QPlainTextEdit(new_wight);
        openocd_result->setObjectName(QString::fromUtf8("openocd_result"));
        openocd_result->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(openocd_result);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 7);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(new_wight);

        QMetaObject::connectSlotsByName(new_wight);
    } // setupUi

    void retranslateUi(QWidget *new_wight)
    {
        new_wight->setWindowTitle(QCoreApplication::translate("new_wight", "new_wight", nullptr));
        label->setText(QCoreApplication::translate("new_wight", "openocd", nullptr));
        select_cfg_file->setText(QCoreApplication::translate("new_wight", "\351\200\211\346\213\251cfg\346\226\207\344\273\266", nullptr));
        run_program->setText(QCoreApplication::translate("new_wight", "\346\211\247\350\241\214\347\250\213\345\272\217", nullptr));
        kill_program->setText(QCoreApplication::translate("new_wight", "\347\273\223\346\235\237\347\250\213\345\272\217", nullptr));
        reading_rtt->setText(QCoreApplication::translate("new_wight", "\350\257\273\345\217\226log", nullptr));
        close_rtt->setText(QCoreApplication::translate("new_wight", "\345\205\263\351\227\255log", nullptr));
        save_rtt->setText(QCoreApplication::translate("new_wight", "\344\277\235\345\255\230log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_wight: public Ui_new_wight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WIGHT_H
