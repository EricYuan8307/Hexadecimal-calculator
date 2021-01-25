/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QPushButton *button_1;
    QPushButton *button_7;
    QPushButton *button_4;
    QPushButton *button_2;
    QPushButton *button_5;
    QPushButton *button_8;
    QPushButton *button_6;
    QPushButton *button_3;
    QPushButton *button_9;
    QPushButton *button_point;
    QPushButton *button_0;
    QPushButton *button_left;
    QPushButton *button_right;
    QPushButton *button_ride;
    QPushButton *button_divide;
    QPushButton *button_add;
    QPushButton *button_CE;
    QPushButton *button_minus;
    QPushButton *button_AC;
    QPushButton *button_equal;
    QLineEdit *display;
    QLineEdit *put_data;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QStringLiteral("Calculator"));
        Calculator->resize(920, 720);
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(308, 166, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(284, 298, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        button_1 = new QPushButton(groupBox);
        button_1->setObjectName(QStringLiteral("button_1"));
        button_1->setGeometry(QRect(30, 130, 41, 31));
        button_7 = new QPushButton(groupBox);
        button_7->setObjectName(QStringLiteral("button_7"));
        button_7->setGeometry(QRect(30, 210, 41, 31));
        button_4 = new QPushButton(groupBox);
        button_4->setObjectName(QStringLiteral("button_4"));
        button_4->setGeometry(QRect(30, 170, 41, 31));
        button_2 = new QPushButton(groupBox);
        button_2->setObjectName(QStringLiteral("button_2"));
        button_2->setGeometry(QRect(80, 130, 41, 31));
        button_5 = new QPushButton(groupBox);
        button_5->setObjectName(QStringLiteral("button_5"));
        button_5->setGeometry(QRect(80, 170, 41, 31));
        button_8 = new QPushButton(groupBox);
        button_8->setObjectName(QStringLiteral("button_8"));
        button_8->setGeometry(QRect(80, 210, 41, 31));
        button_6 = new QPushButton(groupBox);
        button_6->setObjectName(QStringLiteral("button_6"));
        button_6->setGeometry(QRect(130, 170, 41, 31));
        button_3 = new QPushButton(groupBox);
        button_3->setObjectName(QStringLiteral("button_3"));
        button_3->setGeometry(QRect(130, 130, 41, 31));
        button_9 = new QPushButton(groupBox);
        button_9->setObjectName(QStringLiteral("button_9"));
        button_9->setGeometry(QRect(130, 210, 41, 31));
        button_point = new QPushButton(groupBox);
        button_point->setObjectName(QStringLiteral("button_point"));
        button_point->setGeometry(QRect(30, 250, 41, 31));
        button_0 = new QPushButton(groupBox);
        button_0->setObjectName(QStringLiteral("button_0"));
        button_0->setGeometry(QRect(80, 250, 41, 31));
        button_left = new QPushButton(groupBox);
        button_left->setObjectName(QStringLiteral("button_left"));
        button_left->setGeometry(QRect(130, 250, 41, 31));
        button_right = new QPushButton(groupBox);
        button_right->setObjectName(QStringLiteral("button_right"));
        button_right->setGeometry(QRect(180, 250, 41, 31));
        button_ride = new QPushButton(groupBox);
        button_ride->setObjectName(QStringLiteral("button_ride"));
        button_ride->setGeometry(QRect(180, 210, 41, 31));
        button_divide = new QPushButton(groupBox);
        button_divide->setObjectName(QStringLiteral("button_divide"));
        button_divide->setGeometry(QRect(230, 210, 41, 31));
        button_add = new QPushButton(groupBox);
        button_add->setObjectName(QStringLiteral("button_add"));
        button_add->setGeometry(QRect(180, 170, 41, 31));
        button_CE = new QPushButton(groupBox);
        button_CE->setObjectName(QStringLiteral("button_CE"));
        button_CE->setGeometry(QRect(180, 130, 41, 31));
        button_minus = new QPushButton(groupBox);
        button_minus->setObjectName(QStringLiteral("button_minus"));
        button_minus->setGeometry(QRect(230, 170, 41, 31));
        button_AC = new QPushButton(groupBox);
        button_AC->setObjectName(QStringLiteral("button_AC"));
        button_AC->setGeometry(QRect(230, 130, 41, 31));
        button_equal = new QPushButton(groupBox);
        button_equal->setObjectName(QStringLiteral("button_equal"));
        button_equal->setGeometry(QRect(230, 250, 41, 31));
        display = new QLineEdit(groupBox);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(10, 40, 281, 41));
        display->setStyleSheet(QStringLiteral("font: 9pt \"Sans Serif\";"));
        put_data = new QLineEdit(groupBox);
        put_data->setObjectName(QStringLiteral("put_data"));
        put_data->setGeometry(QRect(10, 80, 281, 41));

        gridLayout->addWidget(groupBox, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(283, 278, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(308, 146, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        Calculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calculator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 920, 26));
        Calculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Calculator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Calculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Calculator->setStatusBar(statusBar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Calculator", "Calculator", Q_NULLPTR));
        button_1->setText(QApplication::translate("Calculator", "1", Q_NULLPTR));
        button_7->setText(QApplication::translate("Calculator", "7", Q_NULLPTR));
        button_4->setText(QApplication::translate("Calculator", "4", Q_NULLPTR));
        button_2->setText(QApplication::translate("Calculator", "2", Q_NULLPTR));
        button_5->setText(QApplication::translate("Calculator", "5", Q_NULLPTR));
        button_8->setText(QApplication::translate("Calculator", "8", Q_NULLPTR));
        button_6->setText(QApplication::translate("Calculator", "6", Q_NULLPTR));
        button_3->setText(QApplication::translate("Calculator", "3", Q_NULLPTR));
        button_9->setText(QApplication::translate("Calculator", "9", Q_NULLPTR));
        button_point->setText(QApplication::translate("Calculator", ".", Q_NULLPTR));
        button_0->setText(QApplication::translate("Calculator", "0", Q_NULLPTR));
        button_left->setText(QApplication::translate("Calculator", "(", Q_NULLPTR));
        button_right->setText(QApplication::translate("Calculator", ")", Q_NULLPTR));
        button_ride->setText(QApplication::translate("Calculator", "*", Q_NULLPTR));
        button_divide->setText(QApplication::translate("Calculator", "/", Q_NULLPTR));
        button_add->setText(QApplication::translate("Calculator", "+", Q_NULLPTR));
        button_CE->setText(QApplication::translate("Calculator", "CE", Q_NULLPTR));
        button_minus->setText(QApplication::translate("Calculator", "-", Q_NULLPTR));
        button_AC->setText(QApplication::translate("Calculator", "AC", Q_NULLPTR));
        button_equal->setText(QApplication::translate("Calculator", "=", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
