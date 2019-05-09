/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_game;
    QAction *actionHelp;
    QAction *actionMusic;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *login;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *page_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *user;
    QLabel *username;
    QVBoxLayout *verticalLayout_4;
    QPushButton *startNew;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *hit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *hold;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_9;
    QLCDNumber *lcdNumber;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *disconnect;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *bet10;
    QPushButton *bet25;
    QPushButton *bet50;
    QListWidget *hand;
    QWidget *page_3;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_9;
    QPushButton *disconnect_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_5;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(490, 368);
        actionNew_game = new QAction(MainWindow);
        actionNew_game->setObjectName(QStringLiteral("actionNew_game"));
        actionNew_game->setEnabled(false);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionHelp->setEnabled(true);
        actionMusic = new QAction(MainWindow);
        actionMusic->setObjectName(QStringLiteral("actionMusic"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("max-width: 400;\n"
"max-height: 208;"));

        horizontalLayout->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(1, 10);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font: 10pt MS Shell Dlg;\n"
"color: white;"));

        verticalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFrame(true);

        verticalLayout->addWidget(lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(page);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QLatin1String("font: 10pt MS Shell Dlg;\n"
"color: white;"));

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        spinBox = new QSpinBox(page);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setStyleSheet(QStringLiteral("font: 10pt MS Shell Dlg"));
        spinBox->setKeyboardTracking(false);
        spinBox->setMinimum(100);
        spinBox->setMaximum(1000);
        spinBox->setSingleStep(50);

        horizontalLayout_2->addWidget(spinBox);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(2, 3);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(2, 2);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        login = new QPushButton(page);
        login->setObjectName(QStringLiteral("login"));
        login->setStyleSheet(QStringLiteral("font: 10pt MS Shell Dlg"));

        verticalLayout_2->addWidget(login);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 5);
        verticalLayout_3->setStretch(1, 5);

        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_2 = new QGridLayout(page_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        user = new QLabel(page_2);
        user->setObjectName(QStringLiteral("user"));
        user->setStyleSheet(QLatin1String("font: 10pt 'MS Shell Dlg';\n"
"color: white;"));

        horizontalLayout_5->addWidget(user);

        username = new QLabel(page_2);
        username->setObjectName(QStringLiteral("username"));
        username->setStyleSheet(QLatin1String("font: 11pt MS Shell Dlg;\n"
"color: white;"));

        horizontalLayout_5->addWidget(username);

        horizontalLayout_5->setStretch(1, 2);

        verticalLayout_6->addLayout(horizontalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        startNew = new QPushButton(page_2);
        startNew->setObjectName(QStringLiteral("startNew"));
        startNew->setStyleSheet(QStringLiteral("font: 10pt MS Shell Dlg"));

        verticalLayout_4->addWidget(startNew);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        hit = new QPushButton(page_2);
        hit->setObjectName(QStringLiteral("hit"));
        hit->setStyleSheet(QStringLiteral("font: 10pt 'MS Shell Dlg'"));

        horizontalLayout_6->addWidget(hit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        hold = new QPushButton(page_2);
        hold->setObjectName(QStringLiteral("hold"));
        hold->setStyleSheet(QStringLiteral("font: 10pt 'MS Shell Dlg'"));

        horizontalLayout_7->addWidget(hold);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 5);

        horizontalLayout_13->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_10->addItem(verticalSpacer_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_10->addItem(verticalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);

        lcdNumber = new QLCDNumber(page_2);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setStyleSheet(QLatin1String(" max-height: 25px;\n"
" min-height: 25px;\n"
"\n"
"background-image:  url(\"cards/moneyBackground.png\");\n"
"color: white;"));
        lcdNumber->setFrameShape(QFrame::WinPanel);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_12->addWidget(lcdNumber);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 3);

        verticalLayout_7->addLayout(horizontalLayout_12);


        horizontalLayout_13->addLayout(verticalLayout_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);

        disconnect = new QPushButton(page_2);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        disconnect->setCursor(QCursor(Qt::PointingHandCursor));
        disconnect->setStyleSheet(QLatin1String(" border-style:  solid;\n"
" border-width: 3px;\n"
" border-radius: 27px;\n"
" border-color:  black;\n"
" max-width: 50px;\n"
" max-height: 50px;\n"
" min-width: 50px;\n"
" min-height: 50px;\n"
"\n"
"background-image:  url(\"cards/red_disconnect_felt.jpg\");\n"
"color: white;\n"
"border-color: white;\n"
"font: 15pt 'MS Shell Dlg'"));

        horizontalLayout_9->addWidget(disconnect);


        verticalLayout_5->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        bet10 = new QPushButton(page_2);
        bet10->setObjectName(QStringLiteral("bet10"));
        bet10->setCursor(QCursor(Qt::PointingHandCursor));
        bet10->setStyleSheet(QLatin1String(" border-style:  solid;\n"
" border-width: 3px;\n"
" border-radius: 27px;\n"
" min-width: 55px;\n"
" min-height: 55px;"));

        horizontalLayout_8->addWidget(bet10);

        bet25 = new QPushButton(page_2);
        bet25->setObjectName(QStringLiteral("bet25"));
        bet25->setCursor(QCursor(Qt::PointingHandCursor));
        bet25->setStyleSheet(QLatin1String(" border-style:  solid;\n"
" border-width: 3px;\n"
" border-radius: 27px;\n"
" min-width: 55px;\n"
" min-height: 55px;"));

        horizontalLayout_8->addWidget(bet25);

        bet50 = new QPushButton(page_2);
        bet50->setObjectName(QStringLiteral("bet50"));
        bet50->setCursor(QCursor(Qt::PointingHandCursor));
        bet50->setStyleSheet(QLatin1String(" border-style:  solid;\n"
" border-width: 3px;\n"
" border-radius: 27px;\n"
" min-width: 55px;\n"
" min-height: 55px;"));

        horizontalLayout_8->addWidget(bet50);


        verticalLayout_5->addLayout(horizontalLayout_8);


        horizontalLayout_13->addLayout(verticalLayout_5);


        verticalLayout_8->addLayout(horizontalLayout_13);

        hand = new QListWidget(page_2);
        hand->setObjectName(QStringLiteral("hand"));
        hand->setStyleSheet(QLatin1String("QListView::item:hover {\n"
"    background-image: url(\"cards/blank.png\")\n"
"}"));
        hand->setResizeMode(QListView::Adjust);
        hand->setUniformItemSizes(true);

        verticalLayout_8->addWidget(hand);


        gridLayout_2->addLayout(verticalLayout_8, 0, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_3 = new QGridLayout(page_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        textBrowser = new QTextBrowser(page_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setAutoFillBackground(false);
        textBrowser->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(textBrowser);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        disconnect_2 = new QPushButton(page_3);
        disconnect_2->setObjectName(QStringLiteral("disconnect_2"));
        disconnect_2->setCursor(QCursor(Qt::PointingHandCursor));
        disconnect_2->setStyleSheet(QLatin1String(" border-style:  solid;\n"
" border-width: 3px;\n"
" border-radius: 27px;\n"
" border-color:  black;\n"
" max-width: 50px;\n"
" max-height: 50px;\n"
" min-width: 50px;\n"
" min-height: 50px;\n"
"\n"
"background-image:  url(\"cards/red_disconnect_felt.jpg\");\n"
"color: white;\n"
"font: 15pt 'MS Shell Dlg';\n"
"border-color: white;"));

        verticalLayout_9->addWidget(disconnect_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_5);

        verticalLayout_9->setStretch(0, 1);
        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(2, 1);

        horizontalLayout_11->addLayout(verticalLayout_9);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        horizontalLayout_4->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 490, 26));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionNew_game);
        menuMenu->addAction(actionHelp);
        menuMenu->addAction(actionMusic);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        hand->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionNew_game->setText(QApplication::translate("MainWindow", "New game ", Q_NULLPTR));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "Ctrl+H", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionMusic->setText(QApplication::translate("MainWindow", "Music", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionMusic->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Username:</span></p></body></html>", Q_NULLPTR));
        lineEdit->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Money:</span></p></body></html>", Q_NULLPTR));
        login->setText(QApplication::translate("MainWindow", "Log in", Q_NULLPTR));
        user->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">User:</span></p></body></html>", Q_NULLPTR));
        username->setText(QString());
        startNew->setText(QApplication::translate("MainWindow", "Deal again", Q_NULLPTR));
        hit->setText(QApplication::translate("MainWindow", "Hit", Q_NULLPTR));
        hold->setText(QApplication::translate("MainWindow", "Hold", Q_NULLPTR));
        disconnect->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bet10->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bet10->setText(QString());
#ifndef QT_NO_TOOLTIP
        bet25->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bet25->setText(QString());
#ifndef QT_NO_TOOLTIP
        bet50->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bet50->setText(QString());
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:600; color:#a80f01;\">INSTRUCTIONS</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:16pt; font-weight:600; color:#a80f01;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-blo"
                        "ck-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">2-10 have the value they are</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">A has value of 11 or 1, depending on your current total</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">J,K,Q have value of 10</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">You can bet 10, 25 or 50, once per round. (just click on the chip)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:2px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Hit - you get one card</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Hold - wait for everyone to finish</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Deal again - new round</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Goal"
                        ": to be the closest one to 21 in sum.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:2px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        disconnect_2->setText(QApplication::translate("MainWindow", "Back", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
