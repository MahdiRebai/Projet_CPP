/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *mmmm;
    QTabWidget *Ajouter;
    QWidget *reclamation_2;
    QGroupBox *groupBox;
    QLineEdit *Num_avis;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Nom;
    QLabel *label_3;
    QLineEdit *Objet;
    QLabel *label_6;
    QPushButton *annuler;
    QLineEdit *Reclamation;
    QPushButton *ajouter;
    QPushButton *modifier;
    QGroupBox *groupBox_2;
    QPushButton *tri_nom;
    QPushButton *tri_cin;
    QPushButton *tri_pass;
    QPushButton *actualiser;
    QGroupBox *groupBox_7;
    QLineEdit *rech;
    QLabel *label_10;
    QTableView *tab_c;
    QPushButton *supprimer_3;
    QPushButton *supprimer_4;
    QPushButton *tri_nom_2;
    QGroupBox *groupBox_3;
    QPushButton *supprimer;
    QLineEdit *le_cin_sup;
    QLabel *label_11;
    QWidget *tab_2;
    QLabel *label_20;
    QLineEdit *etat_civil;
    QLabel *label_21;
    QLineEdit *profession;
    QLabel *label_24;
    QLabel *label_22;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *nature;
    QLabel *label_14;
    QDateEdit *date_infra;
    QLineEdit *condamnation;
    QLineEdit *amende;
    QLabel *label_15;
    QLineEdit *ref_infra;
    QPushButton *ajouter_cas;
    QPushButton *afficher_cas;
    QTableView *tabcas;
    QPushButton *modifiercas;
    QGroupBox *groupBox_4;
    QLabel *label_16;
    QLineEdit *lineEdit_3;
    QPushButton *sup_cas;
    QLabel *label_23;
    QLineEdit *idc;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *tab;
    QWidget *hlkjl;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1001, 561);
        mmmm = new QWidget(MainWindow);
        mmmm->setObjectName(QStringLiteral("mmmm"));
        Ajouter = new QTabWidget(mmmm);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(0, 0, 1001, 511));
        Ajouter->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        Ajouter->setTabShape(QTabWidget::Triangular);
        reclamation_2 = new QWidget();
        reclamation_2->setObjectName(QStringLiteral("reclamation_2"));
        groupBox = new QGroupBox(reclamation_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 10, 441, 331));
        groupBox->setStyleSheet(QLatin1String("color: rgb(255,255,255);\n"
"border-color: rgb(255, 255, 255);\n"
""));
        Num_avis = new QLineEdit(groupBox);
        Num_avis->setObjectName(QStringLiteral("Num_avis"));
        Num_avis->setGeometry(QRect(90, 60, 113, 20));
        Num_avis->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"selection-background-color: rgb(255, 170, 255);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 71, 20));
        QFont font;
        font.setFamily(QStringLiteral("Nirmala UI"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border-color: rgb(121, 121, 121);\n"
"font: 8pt \"Orator Std\";\n"
"font: 75 8pt \"Nirmala UI\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 81, 16));
        label_2->setStyleSheet(QLatin1String("\n"
"color: rgb(255, 255, 255);"));
        Nom = new QLineEdit(groupBox);
        Nom->setObjectName(QStringLiteral("Nom"));
        Nom->setGeometry(QRect(90, 90, 113, 20));
        Nom->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 120, 47, 14));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        Objet = new QLineEdit(groupBox);
        Objet->setObjectName(QStringLiteral("Objet"));
        Objet->setGeometry(QRect(90, 120, 113, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 71, 16));
        label_6->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setGeometry(QRect(240, 220, 75, 23));
        annuler->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0) ;"));
        Reclamation = new QLineEdit(groupBox);
        Reclamation->setObjectName(QStringLiteral("Reclamation"));
        Reclamation->setGeometry(QRect(90, 170, 113, 20));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(40, 220, 75, 23));
        ajouter->setStyleSheet(QStringLiteral("color:rgb(40, 40, 40);"));
        modifier = new QPushButton(groupBox);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(130, 270, 101, 23));
        modifier->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        Nom->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        Objet->raise();
        label_6->raise();
        annuler->raise();
        Reclamation->raise();
        Num_avis->raise();
        ajouter->raise();
        modifier->raise();
        groupBox_2 = new QGroupBox(reclamation_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(510, 10, 451, 331));
        groupBox_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        tri_nom = new QPushButton(groupBox_2);
        tri_nom->setObjectName(QStringLiteral("tri_nom"));
        tri_nom->setGeometry(QRect(40, 300, 75, 23));
        tri_nom->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        tri_cin = new QPushButton(groupBox_2);
        tri_cin->setObjectName(QStringLiteral("tri_cin"));
        tri_cin->setGeometry(QRect(160, 300, 101, 23));
        tri_cin->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        tri_pass = new QPushButton(groupBox_2);
        tri_pass->setObjectName(QStringLiteral("tri_pass"));
        tri_pass->setGeometry(QRect(310, 300, 131, 23));
        tri_pass->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        actualiser = new QPushButton(groupBox_2);
        actualiser->setObjectName(QStringLiteral("actualiser"));
        actualiser->setGeometry(QRect(550, 150, 75, 23));
        actualiser->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(40, 30, 371, 80));
        groupBox_7->setAutoFillBackground(false);
        groupBox_7->setStyleSheet(QStringLiteral(""));
        rech = new QLineEdit(groupBox_7);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(130, 30, 113, 20));
        rech->setStyleSheet(QStringLiteral("selection-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 30, 101, 20));
        label_10->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        tab_c = new QTableView(groupBox_2);
        tab_c->setObjectName(QStringLiteral("tab_c"));
        tab_c->setGeometry(QRect(80, 120, 291, 121));
        supprimer_3 = new QPushButton(groupBox_2);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(370, 170, 75, 23));
        supprimer_3->setStyleSheet(QStringLiteral("color :rgb(0,0,0)"));
        supprimer_4 = new QPushButton(groupBox_2);
        supprimer_4->setObjectName(QStringLiteral("supprimer_4"));
        supprimer_4->setGeometry(QRect(370, 200, 75, 23));
        supprimer_4->setStyleSheet(QStringLiteral("color :rgb(0,0,0)"));
        tri_nom_2 = new QPushButton(groupBox_2);
        tri_nom_2->setObjectName(QStringLiteral("tri_nom_2"));
        tri_nom_2->setGeometry(QRect(370, 230, 75, 23));
        tri_nom_2->setStyleSheet(QStringLiteral("color:rgb(170, 0, 0);"));
        groupBox_3 = new QGroupBox(reclamation_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(90, 370, 821, 81));
        groupBox_3->setStyleSheet(QStringLiteral("color :rgb(255, 255, 255)"));
        supprimer = new QPushButton(groupBox_3);
        supprimer->setObjectName(QStringLiteral("supprimer"));
        supprimer->setGeometry(QRect(680, 30, 75, 23));
        supprimer->setStyleSheet(QStringLiteral("color :rgb(0,0,0)"));
        le_cin_sup = new QLineEdit(groupBox_3);
        le_cin_sup->setObjectName(QStringLiteral("le_cin_sup"));
        le_cin_sup->setGeometry(QRect(250, 30, 113, 20));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 30, 71, 20));
        label_11->setStyleSheet(QStringLiteral("color :rgb(255, 255, 255)"));
        Ajouter->addTab(reclamation_2, QString());
        groupBox_2->raise();
        groupBox->raise();
        groupBox_3->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(80, 50, 47, 14));
        etat_civil = new QLineEdit(tab_2);
        etat_civil->setObjectName(QStringLiteral("etat_civil"));
        etat_civil->setGeometry(QRect(150, 50, 113, 20));
        label_21 = new QLabel(tab_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 80, 61, 16));
        profession = new QLineEdit(tab_2);
        profession->setObjectName(QStringLiteral("profession"));
        profession->setGeometry(QRect(150, 80, 113, 20));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(60, 110, 81, 16));
        label_22 = new QLabel(tab_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 200, 141, 20));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 300, 91, 20));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(100, 320, 47, 14));
        nature = new QLineEdit(tab_2);
        nature->setObjectName(QStringLiteral("nature"));
        nature->setGeometry(QRect(150, 310, 113, 20));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(110, 350, 47, 14));
        date_infra = new QDateEdit(tab_2);
        date_infra->setObjectName(QStringLiteral("date_infra"));
        date_infra->setGeometry(QRect(150, 340, 110, 22));
        condamnation = new QLineEdit(tab_2);
        condamnation->setObjectName(QStringLiteral("condamnation"));
        condamnation->setGeometry(QRect(150, 110, 181, 71));
        amende = new QLineEdit(tab_2);
        amende->setObjectName(QStringLiteral("amende"));
        amende->setGeometry(QRect(150, 200, 181, 71));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(70, 380, 81, 20));
        ref_infra = new QLineEdit(tab_2);
        ref_infra->setObjectName(QStringLiteral("ref_infra"));
        ref_infra->setGeometry(QRect(150, 380, 113, 20));
        ajouter_cas = new QPushButton(tab_2);
        ajouter_cas->setObjectName(QStringLiteral("ajouter_cas"));
        ajouter_cas->setGeometry(QRect(180, 430, 75, 23));
        ajouter_cas->setFocusPolicy(Qt::TabFocus);
        ajouter_cas->setContextMenuPolicy(Qt::DefaultContextMenu);
        ajouter_cas->setAutoFillBackground(false);
        ajouter_cas->setAutoDefault(false);
        afficher_cas = new QPushButton(tab_2);
        afficher_cas->setObjectName(QStringLiteral("afficher_cas"));
        afficher_cas->setGeometry(QRect(970, 40, 121, 23));
        tabcas = new QTableView(tab_2);
        tabcas->setObjectName(QStringLiteral("tabcas"));
        tabcas->setGeometry(QRect(630, 80, 481, 261));
        modifiercas = new QPushButton(tab_2);
        modifiercas->setObjectName(QStringLiteral("modifiercas"));
        modifiercas->setGeometry(QRect(1050, 350, 75, 23));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(630, 400, 501, 80));
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 40, 101, 16));
        lineEdit_3 = new QLineEdit(groupBox_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(130, 40, 113, 20));
        sup_cas = new QPushButton(groupBox_4);
        sup_cas->setObjectName(QStringLiteral("sup_cas"));
        sup_cas->setGeometry(QRect(280, 40, 75, 23));
        label_23 = new QLabel(tab_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(66, 20, 61, 20));
        label_23->setStyleSheet(QStringLiteral("font: 87 8pt \"Segoe UI Black\";"));
        idc = new QLineEdit(tab_2);
        idc->setObjectName(QStringLiteral("idc"));
        idc->setGeometry(QRect(150, 20, 113, 20));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1050, 380, 75, 23));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 430, 75, 23));
        Ajouter->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Ajouter->addTab(tab, QString());
        hlkjl = new QWidget();
        hlkjl->setObjectName(QStringLiteral("hlkjl"));
        Ajouter->addTab(hlkjl, QString());
        MainWindow->setCentralWidget(mmmm);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1001, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Ajouter->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "<i>Num_avis\n"
"</i>", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<i>Nom\n"
"", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "<i>Objet<i>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<i>Reclamation<i>", Q_NULLPTR));
        annuler->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "afficher ", Q_NULLPTR));
        tri_nom->setText(QApplication::translate("MainWindow", "trier(objet)", Q_NULLPTR));
        tri_cin->setText(QApplication::translate("MainWindow", "trier(reclamtion)", Q_NULLPTR));
        tri_pass->setText(QApplication::translate("MainWindow", "trier(nom)", Q_NULLPTR));
        actualiser->setText(QApplication::translate("MainWindow", "actualiser", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "recherche", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<i>Entrer Num_avis<i>", Q_NULLPTR));
        supprimer_3->setText(QApplication::translate("MainWindow", "Actualiser", Q_NULLPTR));
        supprimer_4->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tri_nom_2->setText(QApplication::translate("MainWindow", "QRCode", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "supprimer ", Q_NULLPTR));
        supprimer->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<i>Num_avis<i>", Q_NULLPTR));
        Ajouter->setTabText(Ajouter->indexOf(reclamation_2), QApplication::translate("MainWindow", "Citoyen", Q_NULLPTR));
        label_20->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "profession :", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "condamnation :", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "amende (sujet et montant):", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", " Infraction :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "nature :", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "date", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "ref Infraction", Q_NULLPTR));
        ajouter_cas->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        afficher_cas->setText(QApplication::translate("MainWindow", "afficher l'existant", Q_NULLPTR));
        modifiercas->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "supprimer un casier judiciaire", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "donner l'identifiant:", Q_NULLPTR));
        sup_cas->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "identifiant:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "imp", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "statistique", Q_NULLPTR));
        Ajouter->setTabText(Ajouter->indexOf(tab_2), QApplication::translate("MainWindow", "Casier judiciaire", Q_NULLPTR));
        Ajouter->setTabText(Ajouter->indexOf(tab), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
        Ajouter->setTabText(Ajouter->indexOf(hlkjl), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
