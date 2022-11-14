#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "avis.h"
#include <QMainWindow>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void refresh();
private slots:

    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_tri_pass_clicked();

    void on_tri_cin_clicked();

    void on_tri_nom_clicked();

    void on_recherchecin_cursorPositionChanged(int arg1, int arg2);

    void on_recherchecin_textChanged(const QString &arg1);

    void on_supprimer_2_clicked();

    void on_supprimer_3_clicked();

    void on_rech_textChanged(const QString &arg1);

    void on_supprimer_4_clicked();

    void on_tri_nom_2_clicked();

    void on_ajouter_pressed();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    avis Etmp;

};

#endif // MAINWINDOW_H
