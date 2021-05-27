/********************************************************************************
** Form generated from reading UI file 'gui_plot_param.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_PLOT_PARAM_H
#define UI_GUI_PLOT_PARAM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorbox.h"

QT_BEGIN_NAMESPACE

class Ui_PltPrmWnd
{
public:
    QGroupBox *ActivePlot_groupBox;
    QWidget *ActPltClr_widget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *ChanelId_label;
    QSpinBox *ChanedId_spinBox;
    QSpacerItem *horizontalSpacer;
    QLabel *PlotColor_label;
    ColorBox *PlotColor_widget;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *Approx_tab;
    QGroupBox *Approx_groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ApproxType_label;
    QComboBox *ApproxType_comboBox;
    QSpacerItem *horizontalSpacer_3;
    QLabel *ApproxPrm_label;
    QTableWidget *ApproxPrm_tableWidget;
    QWidget *Select_tab;
    QGroupBox *Select_groupBox;
    QLabel *SelectedRegion_label;
    QTableWidget *SelectedData_tableWidget;
    QTableWidget *CurrentSelected_tableWidget;
    QLabel *SelectedData_label;
    QWidget *Data_tab;
    QTableWidget *Data_tableWidget;
    QPushButton *Data2Table_pushButton;

    void setupUi(QWidget *PltPrmWnd)
    {
        if (PltPrmWnd->objectName().isEmpty())
            PltPrmWnd->setObjectName(QString::fromUtf8("PltPrmWnd"));
        PltPrmWnd->resize(415, 595);
        QIcon icon;
        icon.addFile(QString::fromUtf8("graph2.png"), QSize(), QIcon::Normal, QIcon::Off);
        PltPrmWnd->setWindowIcon(icon);
        ActivePlot_groupBox = new QGroupBox(PltPrmWnd);
        ActivePlot_groupBox->setObjectName(QString::fromUtf8("ActivePlot_groupBox"));
        ActivePlot_groupBox->setGeometry(QRect(0, 10, 371, 61));
        ActivePlot_groupBox->setAutoFillBackground(false);
        ActivePlot_groupBox->setFlat(false);
        ActPltClr_widget = new QWidget(ActivePlot_groupBox);
        ActPltClr_widget->setObjectName(QString::fromUtf8("ActPltClr_widget"));
        ActPltClr_widget->setGeometry(QRect(280, 30, 51, 21));
        horizontalLayoutWidget = new QWidget(ActivePlot_groupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 361, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ChanelId_label = new QLabel(horizontalLayoutWidget);
        ChanelId_label->setObjectName(QString::fromUtf8("ChanelId_label"));

        horizontalLayout->addWidget(ChanelId_label);

        ChanedId_spinBox = new QSpinBox(horizontalLayoutWidget);
        ChanedId_spinBox->setObjectName(QString::fromUtf8("ChanedId_spinBox"));
        ChanedId_spinBox->setMaximum(3);

        horizontalLayout->addWidget(ChanedId_spinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PlotColor_label = new QLabel(horizontalLayoutWidget);
        PlotColor_label->setObjectName(QString::fromUtf8("PlotColor_label"));

        horizontalLayout->addWidget(PlotColor_label);

        PlotColor_widget = new ColorBox(horizontalLayoutWidget);
        PlotColor_widget->setObjectName(QString::fromUtf8("PlotColor_widget"));
        PlotColor_widget->setMinimumSize(QSize(50, 20));

        horizontalLayout->addWidget(PlotColor_widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tabWidget = new QTabWidget(PltPrmWnd);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 80, 411, 511));
        Approx_tab = new QWidget();
        Approx_tab->setObjectName(QString::fromUtf8("Approx_tab"));
        Approx_groupBox = new QGroupBox(Approx_tab);
        Approx_groupBox->setObjectName(QString::fromUtf8("Approx_groupBox"));
        Approx_groupBox->setGeometry(QRect(10, 10, 391, 451));
        Approx_groupBox->setFlat(true);
        Approx_groupBox->setCheckable(true);
        Approx_groupBox->setChecked(true);
        verticalLayoutWidget = new QWidget(Approx_groupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 381, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(verticalLayoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayoutWidget_2 = new QWidget(widget_2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 381, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ApproxType_label = new QLabel(horizontalLayoutWidget_2);
        ApproxType_label->setObjectName(QString::fromUtf8("ApproxType_label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ApproxType_label->sizePolicy().hasHeightForWidth());
        ApproxType_label->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(ApproxType_label);

        ApproxType_comboBox = new QComboBox(horizontalLayoutWidget_2);
        ApproxType_comboBox->addItem(QString());
        ApproxType_comboBox->addItem(QString());
        ApproxType_comboBox->addItem(QString());
        ApproxType_comboBox->setObjectName(QString::fromUtf8("ApproxType_comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ApproxType_comboBox->sizePolicy().hasHeightForWidth());
        ApproxType_comboBox->setSizePolicy(sizePolicy1);
        ApproxType_comboBox->setEditable(false);
        ApproxType_comboBox->setMaxCount(3);
        ApproxType_comboBox->setIconSize(QSize(16, 16));

        horizontalLayout_2->addWidget(ApproxType_comboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        ApproxPrm_label = new QLabel(widget_2);
        ApproxPrm_label->setObjectName(QString::fromUtf8("ApproxPrm_label"));
        ApproxPrm_label->setGeometry(QRect(30, 30, 171, 20));
        ApproxPrm_tableWidget = new QTableWidget(widget_2);
        if (ApproxPrm_tableWidget->columnCount() < 3)
            ApproxPrm_tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ApproxPrm_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ApproxPrm_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ApproxPrm_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (ApproxPrm_tableWidget->rowCount() < 9)
            ApproxPrm_tableWidget->setRowCount(9);
        ApproxPrm_tableWidget->setObjectName(QString::fromUtf8("ApproxPrm_tableWidget"));
        ApproxPrm_tableWidget->setGeometry(QRect(20, 50, 341, 351));
        ApproxPrm_tableWidget->setRowCount(9);
        ApproxPrm_tableWidget->setColumnCount(3);
        ApproxPrm_tableWidget->horizontalHeader()->setVisible(true);
        ApproxPrm_tableWidget->horizontalHeader()->setDefaultSectionSize(110);
        ApproxPrm_tableWidget->horizontalHeader()->setHighlightSections(true);
        ApproxPrm_tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        ApproxPrm_tableWidget->verticalHeader()->setVisible(false);
        ApproxPrm_tableWidget->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout->addWidget(widget_2);

        tabWidget->addTab(Approx_tab, QString());
        Select_tab = new QWidget();
        Select_tab->setObjectName(QString::fromUtf8("Select_tab"));
        Select_groupBox = new QGroupBox(Select_tab);
        Select_groupBox->setObjectName(QString::fromUtf8("Select_groupBox"));
        Select_groupBox->setGeometry(QRect(10, 10, 371, 491));
        Select_groupBox->setFlat(false);
        Select_groupBox->setCheckable(true);
        Select_groupBox->setChecked(true);
        SelectedRegion_label = new QLabel(Select_groupBox);
        SelectedRegion_label->setObjectName(QString::fromUtf8("SelectedRegion_label"));
        SelectedRegion_label->setGeometry(QRect(20, 30, 141, 16));
        SelectedData_tableWidget = new QTableWidget(Select_groupBox);
        if (SelectedData_tableWidget->columnCount() < 2)
            SelectedData_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        SelectedData_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        SelectedData_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        if (SelectedData_tableWidget->rowCount() < 1024)
            SelectedData_tableWidget->setRowCount(1024);
        SelectedData_tableWidget->setObjectName(QString::fromUtf8("SelectedData_tableWidget"));
        SelectedData_tableWidget->setGeometry(QRect(30, 170, 321, 301));
        SelectedData_tableWidget->setRowCount(1024);
        SelectedData_tableWidget->setColumnCount(2);
        SelectedData_tableWidget->horizontalHeader()->setMinimumSectionSize(37);
        SelectedData_tableWidget->horizontalHeader()->setDefaultSectionSize(133);
        CurrentSelected_tableWidget = new QTableWidget(Select_groupBox);
        if (CurrentSelected_tableWidget->columnCount() < 2)
            CurrentSelected_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        CurrentSelected_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        CurrentSelected_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        if (CurrentSelected_tableWidget->rowCount() < 2)
            CurrentSelected_tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        CurrentSelected_tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        CurrentSelected_tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        CurrentSelected_tableWidget->setObjectName(QString::fromUtf8("CurrentSelected_tableWidget"));
        CurrentSelected_tableWidget->setGeometry(QRect(20, 50, 331, 91));
        CurrentSelected_tableWidget->setRowCount(2);
        CurrentSelected_tableWidget->setColumnCount(2);
        CurrentSelected_tableWidget->horizontalHeader()->setMinimumSectionSize(37);
        CurrentSelected_tableWidget->horizontalHeader()->setDefaultSectionSize(110);
        SelectedData_label = new QLabel(Select_groupBox);
        SelectedData_label->setObjectName(QString::fromUtf8("SelectedData_label"));
        SelectedData_label->setGeometry(QRect(30, 150, 251, 16));
        tabWidget->addTab(Select_tab, QString());
        Data_tab = new QWidget();
        Data_tab->setObjectName(QString::fromUtf8("Data_tab"));
        Data_tableWidget = new QTableWidget(Data_tab);
        if (Data_tableWidget->columnCount() < 2)
            Data_tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Data_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Data_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        if (Data_tableWidget->rowCount() < 65536)
            Data_tableWidget->setRowCount(65536);
        Data_tableWidget->setObjectName(QString::fromUtf8("Data_tableWidget"));
        Data_tableWidget->setGeometry(QRect(40, 40, 321, 441));
        Data_tableWidget->setRowCount(65536);
        Data_tableWidget->setColumnCount(2);
        Data_tableWidget->horizontalHeader()->setMinimumSectionSize(37);
        Data_tableWidget->horizontalHeader()->setDefaultSectionSize(128);
        Data2Table_pushButton = new QPushButton(Data_tab);
        Data2Table_pushButton->setObjectName(QString::fromUtf8("Data2Table_pushButton"));
        Data2Table_pushButton->setGeometry(QRect(60, 10, 271, 23));
        tabWidget->addTab(Data_tab, QString());

        retranslateUi(PltPrmWnd);

        tabWidget->setCurrentIndex(0);
        ApproxType_comboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PltPrmWnd);
    } // setupUi

    void retranslateUi(QWidget *PltPrmWnd)
    {
        PltPrmWnd->setWindowTitle(QCoreApplication::translate("PltPrmWnd", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        ActivePlot_groupBox->setTitle(QCoreApplication::translate("PltPrmWnd", "\320\220\320\272\321\202\320\270\320\262\320\275\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        ChanelId_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\230\320\275\320\264\320\265\320\272\321\201  \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        PlotColor_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\246\320\262\320\265\321\202 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
        Approx_groupBox->setTitle(QCoreApplication::translate("PltPrmWnd", "\320\220\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\321\217", nullptr));
        ApproxType_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\242\320\270\320\277 \320\260\320\277\320\277\321\200\320\276\321\201\320\272\320\270\320\274\320\260\321\206\320\270\320\270:", nullptr));
        ApproxType_comboBox->setItemText(0, QCoreApplication::translate("PltPrmWnd", "\320\233\320\270\320\275\320\265\320\271\320\275\320\260\321\217     y  = A*x + B", nullptr));
        ApproxType_comboBox->setItemText(1, QCoreApplication::translate("PltPrmWnd", "\320\223\320\260\321\203\321\201\321\201\320\276\320\262\320\260\321\217     y  = A*exp(-((x-B)/C)^2) + D*x + E", nullptr));
        ApproxType_comboBox->setItemText(2, QCoreApplication::translate("PltPrmWnd", "\320\233\320\276\321\200\320\265\320\275\321\206\320\265\320\262\320\260\321\217  y  = A/( (x-B)^2 + C^2) + D*x +E ", nullptr));

        ApproxType_comboBox->setCurrentText(QCoreApplication::translate("PltPrmWnd", "\320\233\320\270\320\275\320\265\320\271\320\275\320\260\321\217     y  = A*x + B", nullptr));
        ApproxPrm_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\260\320\277\320\277\321\200\320\276\321\201\320\272\320\270\320\274\320\260\321\206\320\270\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = ApproxPrm_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("PltPrmWnd", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = ApproxPrm_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("PltPrmWnd", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = ApproxPrm_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("PltPrmWnd", "\320\237\320\276\320\263\321\200\320\265\321\210\320\275\320\276\321\201\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Approx_tab), QCoreApplication::translate("PltPrmWnd", "\320\220\320\277\320\277\321\200\320\276\320\272\321\201\320\270\320\274\320\260\321\206\320\270\321\217", nullptr));
        Select_groupBox->setTitle(QCoreApplication::translate("PltPrmWnd", "\320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\265 \320\272\321\203\321\200\321\201\320\276\321\200\320\276\320\274", nullptr));
        SelectedRegion_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\260\321\217 \320\276\320\261\320\273\320\260\321\201\321\202\321\214:", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = SelectedData_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("PltPrmWnd", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = SelectedData_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("PltPrmWnd", "Y1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = CurrentSelected_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("PltPrmWnd", "X", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = CurrentSelected_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("PltPrmWnd", "Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = CurrentSelected_tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("PltPrmWnd", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = CurrentSelected_tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("PltPrmWnd", "\320\232\320\276\320\275\320\265\321\207\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260", nullptr));
        SelectedData_label->setText(QCoreApplication::translate("PltPrmWnd", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\320\276\320\274 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275\320\265 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Select_tab), QCoreApplication::translate("PltPrmWnd", "\320\232\321\203\321\200\321\201\320\276\321\200\320\275\321\213\320\265 \320\262\321\213\320\261\320\276\321\200\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = Data_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("PltPrmWnd", "X1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = Data_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("PltPrmWnd", "Y1", nullptr));
        Data2Table_pushButton->setText(QCoreApplication::translate("PltPrmWnd", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265 \320\263\321\200\320\260\321\204\320\270\320\272\320\260 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Data_tab), QCoreApplication::translate("PltPrmWnd", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PltPrmWnd: public Ui_PltPrmWnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_PLOT_PARAM_H
