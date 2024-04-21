/********************************************************************************
** Form generated from reading UI file 'control_wight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEW_WIGHT_H
#define UI_NEW_WIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_new_wight
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *select_cfg_file;
    QPushButton *pushButton;
    QPushButton *run_program;
    QPushButton *kill_program;
    QPushButton *reading_rtt;
    QPushButton *close_rtt;
    QPushButton *save_rtt;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QCheckBox *ASSERT_check_box;
    QCheckBox *ERROR_check_box;
    QCheckBox *WARN_check_box;
    QCheckBox *INFO_check_box;
    QCheckBox *DEBUG_check_box;
    QCheckBox *VERBOSE__check_box;
    QHBoxLayout *horizontalLayout_2;
    QPlainTextEdit *openocd_result;
    QPlainTextEdit *rtt_result;

    void setupUi(QWidget *new_wight)
    {
        if (new_wight->objectName().isEmpty())
            new_wight->setObjectName(QString::fromUtf8("control_wight"));
        new_wight->setEnabled(true);
        new_wight->resize(936, 732);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(new_wight->sizePolicy().hasHeightForWidth());
        new_wight->setSizePolicy(sizePolicy);
        new_wight->setMaximumSize(QSize(1920, 1080));
        gridLayout = new QGridLayout(new_wight);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
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

        pushButton = new QPushButton(new_wight);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

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

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(10);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(10, 10, 10, 10);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        ASSERT_check_box = new QCheckBox(new_wight);
        ASSERT_check_box->setObjectName(QString::fromUtf8("ASSERT_check_box"));

        horizontalLayout_4->addWidget(ASSERT_check_box);

        ERROR_check_box = new QCheckBox(new_wight);
        ERROR_check_box->setObjectName(QString::fromUtf8("ERROR_check_box"));

        horizontalLayout_4->addWidget(ERROR_check_box);

        WARN_check_box = new QCheckBox(new_wight);
        WARN_check_box->setObjectName(QString::fromUtf8("WARN_check_box"));

        horizontalLayout_4->addWidget(WARN_check_box);

        INFO_check_box = new QCheckBox(new_wight);
        INFO_check_box->setObjectName(QString::fromUtf8("INFO_check_box"));

        horizontalLayout_4->addWidget(INFO_check_box);

        DEBUG_check_box = new QCheckBox(new_wight);
        DEBUG_check_box->setObjectName(QString::fromUtf8("DEBUG_check_box"));

        horizontalLayout_4->addWidget(DEBUG_check_box);

        VERBOSE__check_box = new QCheckBox(new_wight);
        VERBOSE__check_box->setObjectName(QString::fromUtf8("VERBOSE__check_box"));

        horizontalLayout_4->addWidget(VERBOSE__check_box);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(4, 4, 4, 4);
        openocd_result = new QPlainTextEdit(new_wight);
        openocd_result->setObjectName(QString::fromUtf8("openocd_result"));
        openocd_result->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(openocd_result);

        rtt_result = new QPlainTextEdit(new_wight);
        rtt_result->setObjectName(QString::fromUtf8("rtt_result"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rtt_result->sizePolicy().hasHeightForWidth());
        rtt_result->setSizePolicy(sizePolicy1);
        rtt_result->setBaseSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(12);
        rtt_result->setFont(font);

        horizontalLayout_2->addWidget(rtt_result);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(new_wight);

        QMetaObject::connectSlotsByName(new_wight);
    } // setupUi

    void retranslateUi(QWidget *new_wight)
    {
        new_wight->setWindowTitle(QCoreApplication::translate("control_wight", "control_wight", nullptr));
        label->setText(QCoreApplication::translate("control_wight", "openocd", nullptr));
        select_cfg_file->setText(QCoreApplication::translate("control_wight", "\351\200\211\346\213\251cfg\346\226\207\344\273\266", nullptr));
        pushButton->setText(QCoreApplication::translate("control_wight", "\351\200\211\346\213\251\344\270\213\350\275\275\347\232\204\346\226\207\344\273\266", nullptr));
        run_program->setText(QCoreApplication::translate("control_wight", "\346\211\247\350\241\214openocd\347\250\213\345\272\217", nullptr));
        kill_program->setText(QCoreApplication::translate("control_wight", "\347\273\223\346\235\237\347\250\213\345\272\217", nullptr));
        reading_rtt->setText(QCoreApplication::translate("control_wight", "\350\257\273\345\217\226log", nullptr));
        close_rtt->setText(QCoreApplication::translate("control_wight", "\345\205\263\351\227\255log", nullptr));
        save_rtt->setText(QCoreApplication::translate("control_wight", "\344\277\235\345\255\230log", nullptr));
        ASSERT_check_box->setText(QCoreApplication::translate("control_wight", "ASSERT", nullptr));
        ERROR_check_box->setText(QCoreApplication::translate("control_wight", "ERROR", nullptr));
        WARN_check_box->setText(QCoreApplication::translate("control_wight", "WARN", nullptr));
        INFO_check_box->setText(QCoreApplication::translate("control_wight", "INFO", nullptr));
        DEBUG_check_box->setText(QCoreApplication::translate("control_wight", "DEBUG", nullptr));
        VERBOSE__check_box->setText(QCoreApplication::translate("control_wight", "VERBOSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class new_wight: public Ui_new_wight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEW_WIGHT_H
