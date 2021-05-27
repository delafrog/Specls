/********************************************************************************
** Form generated from reading UI file 'gui_.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI__H
#define UI_GUI__H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Image_Data_File;
    QAction *actionSave_Binary_Data;
    QAction *actionExit;
    QAction *action_1;
    QAction *action;
    QAction *actionAbout;
    QAction *actionAbout_Qt5;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(851, 605);
        QIcon icon;
        icon.addFile(QString::fromUtf8("ImProc.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpen_Image_Data_File = new QAction(MainWindow);
        actionOpen_Image_Data_File->setObjectName(QString::fromUtf8("actionOpen_Image_Data_File"));
        actionSave_Binary_Data = new QAction(MainWindow);
        actionSave_Binary_Data->setObjectName(QString::fromUtf8("actionSave_Binary_Data"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        action_1 = new QAction(MainWindow);
        action_1->setObjectName(QString::fromUtf8("action_1"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt5 = new QAction(MainWindow);
        actionAbout_Qt5->setObjectName(QString::fromUtf8("actionAbout_Qt5"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 851, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu->menuAction());
        menuFile->addAction(actionOpen_Image_Data_File);
        menuFile->addAction(actionSave_Binary_Data);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menu->addAction(action);
        menu->addSeparator();
        menu->addAction(actionAbout);
        menu->addAction(actionAbout_Qt5);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\265\320\272\320\273\321\213", nullptr));
        actionOpen_Image_Data_File->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        actionSave_Binary_Data->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_1->setText(QCoreApplication::translate("MainWindow", "\320\241\321\203\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276 \321\201\321\202\320\276\320\273\320\261\321\206\320\260\320\274", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        actionAbout_Qt5->setText(QCoreApplication::translate("MainWindow", "About Qt5", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI__H
