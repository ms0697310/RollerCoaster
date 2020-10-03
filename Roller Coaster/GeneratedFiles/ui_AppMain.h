/********************************************************************************
** Form generated from reading UI file 'AppMain.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPMAIN_H
#define UI_APPMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppMainClass
{
public:
    QAction *aExit;
    QAction *aLoadPath;
    QAction *aSavePath;
    QAction *aWorld;
    QAction *aTop;
    QAction *aTrain;
    QAction *aLinear;
    QAction *aCardinal;
    QAction *aCubic;
    QAction *aLine;
    QAction *aTrack;
    QAction *aRoad;
    QAction *aHuman;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupCamera;
    QComboBox *comboCamera;
    QGroupBox *groupCurve;
    QComboBox *comboCurve;
    QGroupBox *groupTrack;
    QComboBox *comboTrack;
    QGroupBox *Curve_GROUP;
    QPushButton *paraadd;
    QPushButton *parasub;
    QGroupBox *groupBox_9;
    QPushButton *rcpzadd_6;
    QPushButton *rcpzsub_6;
    QGroupBox *groupCar;
    QPushButton *car_add;
    QPushButton *car_sub;
    QGroupBox *groupBox_6;
    QPushButton *peopleadd;
    QPushButton *peoplesub;
    QGroupBox *groupBox_7;
    QPushButton *rcpzadd_5;
    QPushButton *rcpzsub_5;
    QGroupBox *groupPlay;
    QPushButton *bPlay;
    QGroupBox *groupCP;
    QPushButton *bAdd;
    QPushButton *bDelete;
    QGroupBox *groupBox;
    QPushButton *rcpxadd;
    QPushButton *rcpxsub;
    QGroupBox *groupBox_2;
    QPushButton *rcpzadd;
    QPushButton *rcpzsub;
    QGroupBox *groupBox_3;
    QPushButton *rcpzadd_2;
    QPushButton *rcpzsub_2;
    QGroupBox *groupBox_4;
    QPushButton *mcpyadd;
    QPushButton *mcpysub;
    QGroupBox *groupBox_5;
    QPushButton *rcpzadd_4;
    QPushButton *rcpzsub_4;
    QGroupBox *group_human_view;
    QPushButton *humanview_up;
    QPushButton *humanview_left;
    QPushButton *humanview_down;
    QPushButton *humanview_right;
    QPushButton *humanview_turn_left;
    QPushButton *humanview_turn_right;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QSlider *sSpeed;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCamera;
    QMenu *menuCurve;
    QMenu *menuTrack;
    QMenu *menuVelocity;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *AppMainClass)
    {
        if (AppMainClass->objectName().isEmpty())
            AppMainClass->setObjectName(QString::fromUtf8("AppMainClass"));
        AppMainClass->resize(1818, 769);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AppMainClass->sizePolicy().hasHeightForWidth());
        AppMainClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        AppMainClass->setFont(font);
        AppMainClass->setLayoutDirection(Qt::LeftToRight);
        AppMainClass->setAutoFillBackground(true);
        AppMainClass->setStyleSheet(QString::fromUtf8(""));
        AppMainClass->setDockNestingEnabled(false);
        aExit = new QAction(AppMainClass);
        aExit->setObjectName(QString::fromUtf8("aExit"));
        aLoadPath = new QAction(AppMainClass);
        aLoadPath->setObjectName(QString::fromUtf8("aLoadPath"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/openfile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aLoadPath->setIcon(icon);
        aLoadPath->setIconVisibleInMenu(true);
        aSavePath = new QAction(AppMainClass);
        aSavePath->setObjectName(QString::fromUtf8("aSavePath"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/savefile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aSavePath->setIcon(icon1);
        aWorld = new QAction(AppMainClass);
        aWorld->setObjectName(QString::fromUtf8("aWorld"));
        aWorld->setCheckable(false);
        aWorld->setChecked(false);
        aTop = new QAction(AppMainClass);
        aTop->setObjectName(QString::fromUtf8("aTop"));
        aTop->setCheckable(true);
        aTrain = new QAction(AppMainClass);
        aTrain->setObjectName(QString::fromUtf8("aTrain"));
        aTrain->setCheckable(true);
        aLinear = new QAction(AppMainClass);
        aLinear->setObjectName(QString::fromUtf8("aLinear"));
        aLinear->setCheckable(false);
        aLinear->setChecked(false);
        aCardinal = new QAction(AppMainClass);
        aCardinal->setObjectName(QString::fromUtf8("aCardinal"));
        aCardinal->setCheckable(true);
        aCubic = new QAction(AppMainClass);
        aCubic->setObjectName(QString::fromUtf8("aCubic"));
        aCubic->setCheckable(true);
        aLine = new QAction(AppMainClass);
        aLine->setObjectName(QString::fromUtf8("aLine"));
        aLine->setCheckable(false);
        aLine->setChecked(false);
        aTrack = new QAction(AppMainClass);
        aTrack->setObjectName(QString::fromUtf8("aTrack"));
        aTrack->setCheckable(true);
        aRoad = new QAction(AppMainClass);
        aRoad->setObjectName(QString::fromUtf8("aRoad"));
        aRoad->setCheckable(true);
        aHuman = new QAction(AppMainClass);
        aHuman->setObjectName(QString::fromUtf8("aHuman"));
        aHuman->setCheckable(true);
        centralWidget = new QWidget(AppMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout->addLayout(mainLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSpacer_5 = new QSpacerItem(117, 117, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        groupCamera = new QGroupBox(centralWidget);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupCamera->sizePolicy().hasHeightForWidth());
        groupCamera->setSizePolicy(sizePolicy2);
        groupCamera->setMinimumSize(QSize(120, 150));
        groupCamera->setMaximumSize(QSize(200, 150));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupCamera->setFont(font1);
        groupCamera->setAutoFillBackground(false);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupCamera->setAlignment(Qt::AlignCenter);
        comboCamera = new QComboBox(groupCamera);
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->setObjectName(QString::fromUtf8("comboCamera"));
        comboCamera->setGeometry(QRect(10, 40, 96, 96));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboCamera->sizePolicy().hasHeightForWidth());
        comboCamera->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        comboCamera->setFont(font2);
        comboCamera->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout->addWidget(groupCamera);

        groupCurve = new QGroupBox(centralWidget);
        groupCurve->setObjectName(QString::fromUtf8("groupCurve"));
        sizePolicy2.setHeightForWidth(groupCurve->sizePolicy().hasHeightForWidth());
        groupCurve->setSizePolicy(sizePolicy2);
        groupCurve->setMinimumSize(QSize(120, 150));
        groupCurve->setMaximumSize(QSize(200, 150));
        groupCurve->setFont(font1);
        groupCurve->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupCurve->setAlignment(Qt::AlignCenter);
        comboCurve = new QComboBox(groupCurve);
        comboCurve->addItem(QString());
        comboCurve->addItem(QString());
        comboCurve->addItem(QString());
        comboCurve->setObjectName(QString::fromUtf8("comboCurve"));
        comboCurve->setGeometry(QRect(10, 40, 96, 96));
        sizePolicy3.setHeightForWidth(comboCurve->sizePolicy().hasHeightForWidth());
        comboCurve->setSizePolicy(sizePolicy3);
        comboCurve->setFont(font2);
        comboCurve->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout->addWidget(groupCurve);

        groupTrack = new QGroupBox(centralWidget);
        groupTrack->setObjectName(QString::fromUtf8("groupTrack"));
        sizePolicy2.setHeightForWidth(groupTrack->sizePolicy().hasHeightForWidth());
        groupTrack->setSizePolicy(sizePolicy2);
        groupTrack->setMinimumSize(QSize(120, 120));
        groupTrack->setMaximumSize(QSize(200, 150));
        groupTrack->setFont(font1);
        groupTrack->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupTrack->setAlignment(Qt::AlignCenter);
        comboTrack = new QComboBox(groupTrack);
        comboTrack->addItem(QString());
        comboTrack->addItem(QString());
        comboTrack->addItem(QString());
        comboTrack->setObjectName(QString::fromUtf8("comboTrack"));
        comboTrack->setGeometry(QRect(10, 40, 96, 96));
        sizePolicy3.setHeightForWidth(comboTrack->sizePolicy().hasHeightForWidth());
        comboTrack->setSizePolicy(sizePolicy3);
        comboTrack->setFont(font2);
        comboTrack->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));
        comboTrack->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(groupTrack);

        Curve_GROUP = new QGroupBox(centralWidget);
        Curve_GROUP->setObjectName(QString::fromUtf8("Curve_GROUP"));
        Curve_GROUP->setMinimumSize(QSize(120, 150));
        Curve_GROUP->setMaximumSize(QSize(200, 150));
        Curve_GROUP->setFont(font1);
        Curve_GROUP->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        Curve_GROUP->setAlignment(Qt::AlignCenter);
        paraadd = new QPushButton(Curve_GROUP);
        paraadd->setObjectName(QString::fromUtf8("paraadd"));
        paraadd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(paraadd->sizePolicy().hasHeightForWidth());
        paraadd->setSizePolicy(sizePolicy2);
        paraadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/AppMain/madd.png"), QSize(), QIcon::Normal, QIcon::Off);
        paraadd->setIcon(icon2);
        parasub = new QPushButton(Curve_GROUP);
        parasub->setObjectName(QString::fromUtf8("parasub"));
        parasub->setGeometry(QRect(10, 90, 100, 44));
        parasub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/AppMain/mdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        parasub->setIcon(icon3);
        groupBox_9 = new QGroupBox(Curve_GROUP);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(110, 70, 120, 150));
        groupBox_9->setMinimumSize(QSize(120, 150));
        groupBox_9->setMaximumSize(QSize(200, 150));
        groupBox_9->setFont(font1);
        groupBox_9->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        rcpzadd_6 = new QPushButton(groupBox_9);
        rcpzadd_6->setObjectName(QString::fromUtf8("rcpzadd_6"));
        rcpzadd_6->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpzadd_6->sizePolicy().hasHeightForWidth());
        rcpzadd_6->setSizePolicy(sizePolicy2);
        rcpzadd_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd_6->setIcon(icon2);
        rcpzsub_6 = new QPushButton(groupBox_9);
        rcpzsub_6->setObjectName(QString::fromUtf8("rcpzsub_6"));
        rcpzsub_6->setGeometry(QRect(10, 90, 100, 44));
        rcpzsub_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub_6->setIcon(icon3);

        horizontalLayout->addWidget(Curve_GROUP);

        groupCar = new QGroupBox(centralWidget);
        groupCar->setObjectName(QString::fromUtf8("groupCar"));
        groupCar->setMinimumSize(QSize(120, 150));
        groupCar->setMaximumSize(QSize(200, 150));
        groupCar->setFont(font1);
        groupCar->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupCar->setAlignment(Qt::AlignCenter);
        car_add = new QPushButton(groupCar);
        car_add->setObjectName(QString::fromUtf8("car_add"));
        car_add->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(car_add->sizePolicy().hasHeightForWidth());
        car_add->setSizePolicy(sizePolicy2);
        car_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        car_add->setIcon(icon2);
        car_sub = new QPushButton(groupCar);
        car_sub->setObjectName(QString::fromUtf8("car_sub"));
        car_sub->setGeometry(QRect(10, 90, 100, 44));
        car_sub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        car_sub->setIcon(icon3);

        horizontalLayout->addWidget(groupCar);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setMinimumSize(QSize(120, 150));
        groupBox_6->setMaximumSize(QSize(200, 150));
        groupBox_6->setFont(font1);
        groupBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupBox_6->setAlignment(Qt::AlignCenter);
        peopleadd = new QPushButton(groupBox_6);
        peopleadd->setObjectName(QString::fromUtf8("peopleadd"));
        peopleadd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(peopleadd->sizePolicy().hasHeightForWidth());
        peopleadd->setSizePolicy(sizePolicy2);
        peopleadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        peopleadd->setIcon(icon2);
        peoplesub = new QPushButton(groupBox_6);
        peoplesub->setObjectName(QString::fromUtf8("peoplesub"));
        peoplesub->setGeometry(QRect(10, 90, 100, 44));
        peoplesub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        peoplesub->setIcon(icon3);
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(110, 70, 120, 150));
        groupBox_7->setMinimumSize(QSize(120, 150));
        groupBox_7->setMaximumSize(QSize(200, 150));
        groupBox_7->setFont(font1);
        groupBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        rcpzadd_5 = new QPushButton(groupBox_7);
        rcpzadd_5->setObjectName(QString::fromUtf8("rcpzadd_5"));
        rcpzadd_5->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpzadd_5->sizePolicy().hasHeightForWidth());
        rcpzadd_5->setSizePolicy(sizePolicy2);
        rcpzadd_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd_5->setIcon(icon2);
        rcpzsub_5 = new QPushButton(groupBox_7);
        rcpzsub_5->setObjectName(QString::fromUtf8("rcpzsub_5"));
        rcpzsub_5->setGeometry(QRect(10, 90, 100, 44));
        rcpzsub_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub_5->setIcon(icon3);

        horizontalLayout->addWidget(groupBox_6);

        groupPlay = new QGroupBox(centralWidget);
        groupPlay->setObjectName(QString::fromUtf8("groupPlay"));
        sizePolicy2.setHeightForWidth(groupPlay->sizePolicy().hasHeightForWidth());
        groupPlay->setSizePolicy(sizePolicy2);
        groupPlay->setMinimumSize(QSize(120, 150));
        groupPlay->setMaximumSize(QSize(200, 150));
        groupPlay->setFont(font1);
        groupPlay->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupPlay->setAlignment(Qt::AlignCenter);
        bPlay = new QPushButton(groupPlay);
        bPlay->setObjectName(QString::fromUtf8("bPlay"));
        bPlay->setGeometry(QRect(10, 40, 96, 96));
        sizePolicy2.setHeightForWidth(bPlay->sizePolicy().hasHeightForWidth());
        bPlay->setSizePolicy(sizePolicy2);
        bPlay->setFont(font2);
        bPlay->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        bPlay->setIcon(icon4);
        bPlay->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(groupPlay);

        groupCP = new QGroupBox(centralWidget);
        groupCP->setObjectName(QString::fromUtf8("groupCP"));
        sizePolicy2.setHeightForWidth(groupCP->sizePolicy().hasHeightForWidth());
        groupCP->setSizePolicy(sizePolicy2);
        groupCP->setMinimumSize(QSize(120, 150));
        groupCP->setMaximumSize(QSize(200, 150));
        groupCP->setFont(font1);
        groupCP->setMouseTracking(false);
        groupCP->setAutoFillBackground(false);
        groupCP->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupCP->setAlignment(Qt::AlignCenter);
        groupCP->setFlat(false);
        groupCP->setCheckable(false);
        bAdd = new QPushButton(groupCP);
        bAdd->setObjectName(QString::fromUtf8("bAdd"));
        bAdd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(bAdd->sizePolicy().hasHeightForWidth());
        bAdd->setSizePolicy(sizePolicy2);
        bAdd->setFont(font2);
        bAdd->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        bAdd->setIcon(icon2);
        bAdd->setIconSize(QSize(14, 14));
        bDelete = new QPushButton(groupCP);
        bDelete->setObjectName(QString::fromUtf8("bDelete"));
        bDelete->setGeometry(QRect(10, 90, 100, 44));
        sizePolicy2.setHeightForWidth(bDelete->sizePolicy().hasHeightForWidth());
        bDelete->setSizePolicy(sizePolicy2);
        bDelete->setFont(font2);
        bDelete->setFocusPolicy(Qt::ClickFocus);
        bDelete->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        bDelete->setIcon(icon3);
        bDelete->setIconSize(QSize(12, 12));

        horizontalLayout->addWidget(groupCP);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(120, 150));
        groupBox->setMaximumSize(QSize(200, 150));
        QPalette palette;
        QBrush brush(QColor(249, 249, 249, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        groupBox->setPalette(palette);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        rcpxadd = new QPushButton(groupBox);
        rcpxadd->setObjectName(QString::fromUtf8("rcpxadd"));
        rcpxadd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpxadd->sizePolicy().hasHeightForWidth());
        rcpxadd->setSizePolicy(sizePolicy2);
        rcpxadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpxadd->setIcon(icon2);
        rcpxadd->setIconSize(QSize(14, 14));
        rcpxsub = new QPushButton(groupBox);
        rcpxsub->setObjectName(QString::fromUtf8("rcpxsub"));
        rcpxsub->setGeometry(QRect(10, 90, 100, 44));
        rcpxsub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpxsub->setIcon(icon3);

        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(120, 150));
        groupBox_2->setMaximumSize(QSize(200, 150));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        rcpzadd = new QPushButton(groupBox_2);
        rcpzadd->setObjectName(QString::fromUtf8("rcpzadd"));
        rcpzadd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpzadd->sizePolicy().hasHeightForWidth());
        rcpzadd->setSizePolicy(sizePolicy2);
        rcpzadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd->setIcon(icon2);
        rcpzsub = new QPushButton(groupBox_2);
        rcpzsub->setObjectName(QString::fromUtf8("rcpzsub"));
        rcpzsub->setGeometry(QRect(10, 90, 100, 44));
        rcpzsub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub->setIcon(icon3);
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(110, 70, 120, 150));
        groupBox_3->setMinimumSize(QSize(120, 150));
        groupBox_3->setMaximumSize(QSize(200, 150));
        groupBox_3->setFont(font1);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        rcpzadd_2 = new QPushButton(groupBox_3);
        rcpzadd_2->setObjectName(QString::fromUtf8("rcpzadd_2"));
        rcpzadd_2->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpzadd_2->sizePolicy().hasHeightForWidth());
        rcpzadd_2->setSizePolicy(sizePolicy2);
        rcpzadd_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd_2->setIcon(icon2);
        rcpzsub_2 = new QPushButton(groupBox_3);
        rcpzsub_2->setObjectName(QString::fromUtf8("rcpzsub_2"));
        rcpzsub_2->setGeometry(QRect(10, 90, 100, 44));
        rcpzsub_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub_2->setIcon(icon3);

        horizontalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(120, 150));
        groupBox_4->setMaximumSize(QSize(200, 150));
        groupBox_4->setFont(font1);
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        mcpyadd = new QPushButton(groupBox_4);
        mcpyadd->setObjectName(QString::fromUtf8("mcpyadd"));
        mcpyadd->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(mcpyadd->sizePolicy().hasHeightForWidth());
        mcpyadd->setSizePolicy(sizePolicy2);
        mcpyadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        mcpyadd->setIcon(icon2);
        mcpysub = new QPushButton(groupBox_4);
        mcpysub->setObjectName(QString::fromUtf8("mcpysub"));
        mcpysub->setGeometry(QRect(10, 90, 100, 44));
        mcpysub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        mcpysub->setIcon(icon3);
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(110, 70, 120, 150));
        groupBox_5->setMinimumSize(QSize(120, 150));
        groupBox_5->setMaximumSize(QSize(200, 150));
        groupBox_5->setFont(font1);
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        rcpzadd_4 = new QPushButton(groupBox_5);
        rcpzadd_4->setObjectName(QString::fromUtf8("rcpzadd_4"));
        rcpzadd_4->setGeometry(QRect(10, 40, 100, 44));
        sizePolicy2.setHeightForWidth(rcpzadd_4->sizePolicy().hasHeightForWidth());
        rcpzadd_4->setSizePolicy(sizePolicy2);
        rcpzadd_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd_4->setIcon(icon2);
        rcpzsub_4 = new QPushButton(groupBox_5);
        rcpzsub_4->setObjectName(QString::fromUtf8("rcpzsub_4"));
        rcpzsub_4->setGeometry(QRect(10, 90, 100, 44));
        rcpzsub_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub_4->setIcon(icon3);

        horizontalLayout->addWidget(groupBox_4);

        group_human_view = new QGroupBox(centralWidget);
        group_human_view->setObjectName(QString::fromUtf8("group_human_view"));
        group_human_view->setEnabled(true);
        group_human_view->setMinimumSize(QSize(150, 150));
        group_human_view->setMaximumSize(QSize(200, 150));
        group_human_view->setFont(font1);
        group_human_view->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);\n"
"border-radius: 5px;"));
        group_human_view->setAlignment(Qt::AlignCenter);
        humanview_up = new QPushButton(group_human_view);
        humanview_up->setObjectName(QString::fromUtf8("humanview_up"));
        humanview_up->setGeometry(QRect(40, 40, 31, 31));
        humanview_up->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/up.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_up->setIcon(icon5);
        humanview_left = new QPushButton(group_human_view);
        humanview_left->setObjectName(QString::fromUtf8("humanview_left"));
        humanview_left->setGeometry(QRect(10, 70, 31, 31));
        humanview_left->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/left.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_left->setIcon(icon6);
        humanview_down = new QPushButton(group_human_view);
        humanview_down->setObjectName(QString::fromUtf8("humanview_down"));
        humanview_down->setGeometry(QRect(40, 100, 31, 31));
        humanview_down->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/down.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_down->setIcon(icon7);
        humanview_right = new QPushButton(group_human_view);
        humanview_right->setObjectName(QString::fromUtf8("humanview_right"));
        humanview_right->setGeometry(QRect(70, 70, 31, 31));
        humanview_right->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/right.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_right->setIcon(icon8);
        humanview_turn_left = new QPushButton(group_human_view);
        humanview_turn_left->setObjectName(QString::fromUtf8("humanview_turn_left"));
        humanview_turn_left->setGeometry(QRect(110, 100, 31, 31));
        humanview_turn_left->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/turn left.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_turn_left->setIcon(icon9);
        humanview_turn_right = new QPushButton(group_human_view);
        humanview_turn_right->setObjectName(QString::fromUtf8("humanview_turn_right"));
        humanview_turn_right->setGeometry(QRect(110, 40, 31, 31));
        humanview_turn_right->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/turn right.ico"), QSize(), QIcon::Normal, QIcon::Off);
        humanview_turn_right->setIcon(icon10);

        horizontalLayout->addWidget(group_human_view);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        sSpeed = new QSlider(centralWidget);
        sSpeed->setObjectName(QString::fromUtf8("sSpeed"));
        sSpeed->setMinimumSize(QSize(1450, 0));
        sSpeed->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	background-color: #505050;\n"
"    height: 3px; \n"
"    margin: 2px 0;\n"
" }\n"
" QSlider::handle:horizontal {\n"
"	image: url(:/AppMain/slider_handle.png);\n"
"	width: 15px;\n"
"	margin: -5px 0;\n"
" }"));
        sSpeed->setSingleStep(1);
        sSpeed->setValue(50);
        sSpeed->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sSpeed);

        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        AppMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1818, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QString::fromUtf8("menuCamera"));
        menuCurve = new QMenu(menuBar);
        menuCurve->setObjectName(QString::fromUtf8("menuCurve"));
        menuTrack = new QMenu(menuBar);
        menuTrack->setObjectName(QString::fromUtf8("menuTrack"));
        menuVelocity = new QMenu(menuBar);
        menuVelocity->setObjectName(QString::fromUtf8("menuVelocity"));
        AppMainClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AppMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppMainClass->setStatusBar(statusBar);
        mainToolBar = new QToolBar(AppMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AppMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCamera->menuAction());
        menuBar->addAction(menuTrack->menuAction());
        menuBar->addAction(menuCurve->menuAction());
        menuBar->addAction(menuVelocity->menuAction());
        menuFile->addAction(aLoadPath);
        menuFile->addAction(aSavePath);
        menuFile->addSeparator();
        menuFile->addAction(aExit);
        menuCamera->addAction(aWorld);
        menuCamera->addAction(aTop);
        menuCamera->addAction(aTrain);
        menuCamera->addAction(aHuman);
        menuCurve->addAction(aLinear);
        menuCurve->addAction(aCardinal);
        menuCurve->addAction(aCubic);
        menuTrack->addAction(aLine);
        menuTrack->addAction(aTrack);
        menuTrack->addAction(aRoad);
        mainToolBar->addAction(aLoadPath);
        mainToolBar->addAction(aSavePath);

        retranslateUi(AppMainClass);

        QMetaObject::connectSlotsByName(AppMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppMainClass)
    {
        AppMainClass->setWindowTitle(QCoreApplication::translate("AppMainClass", "AppMain", nullptr));
        aExit->setText(QCoreApplication::translate("AppMainClass", "Exit", nullptr));
        aLoadPath->setText(QCoreApplication::translate("AppMainClass", "Load Path", nullptr));
        aSavePath->setText(QCoreApplication::translate("AppMainClass", "Save Path", nullptr));
        aWorld->setText(QCoreApplication::translate("AppMainClass", "World", nullptr));
        aTop->setText(QCoreApplication::translate("AppMainClass", "Top", nullptr));
        aTrain->setText(QCoreApplication::translate("AppMainClass", "Train", nullptr));
        aLinear->setText(QCoreApplication::translate("AppMainClass", "Linear", nullptr));
        aCardinal->setText(QCoreApplication::translate("AppMainClass", "Cardinal", nullptr));
        aCubic->setText(QCoreApplication::translate("AppMainClass", "Cubic", nullptr));
        aLine->setText(QCoreApplication::translate("AppMainClass", "Line", nullptr));
        aTrack->setText(QCoreApplication::translate("AppMainClass", "Track", nullptr));
        aRoad->setText(QCoreApplication::translate("AppMainClass", "Road", nullptr));
        aHuman->setText(QCoreApplication::translate("AppMainClass", "Human", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("AppMainClass", "Camera", nullptr));
        comboCamera->setItemText(0, QCoreApplication::translate("AppMainClass", "World", nullptr));
        comboCamera->setItemText(1, QCoreApplication::translate("AppMainClass", "Top", nullptr));
        comboCamera->setItemText(2, QCoreApplication::translate("AppMainClass", "Train", nullptr));
        comboCamera->setItemText(3, QCoreApplication::translate("AppMainClass", "Human", nullptr));

        groupCurve->setTitle(QCoreApplication::translate("AppMainClass", "Curve", nullptr));
        comboCurve->setItemText(0, QCoreApplication::translate("AppMainClass", "Linear", nullptr));
        comboCurve->setItemText(1, QCoreApplication::translate("AppMainClass", "Cardinal", nullptr));
        comboCurve->setItemText(2, QCoreApplication::translate("AppMainClass", "Cubic", nullptr));

        groupTrack->setTitle(QCoreApplication::translate("AppMainClass", "Track", nullptr));
        comboTrack->setItemText(0, QCoreApplication::translate("AppMainClass", "Line", nullptr));
        comboTrack->setItemText(1, QCoreApplication::translate("AppMainClass", "Track", nullptr));
        comboTrack->setItemText(2, QCoreApplication::translate("AppMainClass", "Road", nullptr));

        Curve_GROUP->setTitle(QCoreApplication::translate("AppMainClass", "Curve Para", nullptr));
        paraadd->setText(QString());
        parasub->setText(QString());
        groupBox_9->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd_6->setText(QString());
        rcpzsub_6->setText(QString());
        groupCar->setTitle(QCoreApplication::translate("AppMainClass", "Car", nullptr));
        car_add->setText(QString());
        car_sub->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("AppMainClass", "Human Index", nullptr));
        peopleadd->setText(QString());
        peoplesub->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd_5->setText(QString());
        rcpzsub_5->setText(QString());
        groupPlay->setTitle(QCoreApplication::translate("AppMainClass", "Play", nullptr));
        bPlay->setText(QString());
        groupCP->setTitle(QCoreApplication::translate("AppMainClass", "Ctrl Point", nullptr));
        bAdd->setText(QString());
        bDelete->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP X", nullptr));
        rcpxadd->setText(QString());
        rcpxsub->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd->setText(QString());
        rcpzsub->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd_2->setText(QString());
        rcpzsub_2->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("AppMainClass", "Move CP Y", nullptr));
        mcpyadd->setText(QString());
        mcpysub->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd_4->setText(QString());
        rcpzsub_4->setText(QString());
        group_human_view->setTitle(QCoreApplication::translate("AppMainClass", "Human View", nullptr));
        humanview_up->setText(QString());
        humanview_left->setText(QString());
        humanview_down->setText(QString());
        humanview_right->setText(QString());
        humanview_turn_left->setText(QString());
        humanview_turn_right->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("AppMainClass", "File", nullptr));
        menuCamera->setTitle(QCoreApplication::translate("AppMainClass", "Camera", nullptr));
        menuCurve->setTitle(QCoreApplication::translate("AppMainClass", "Curve", nullptr));
        menuTrack->setTitle(QCoreApplication::translate("AppMainClass", "Track", nullptr));
        menuVelocity->setTitle(QCoreApplication::translate("AppMainClass", "Velocity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppMainClass: public Ui_AppMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPMAIN_H
