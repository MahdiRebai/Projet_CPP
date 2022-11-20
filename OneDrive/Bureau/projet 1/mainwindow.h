#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "paiement.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QMainWindow>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int mode =1;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_8_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void update_label();
    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
   paiement p;
   QByteArray data;
   Arduino A;


};
#endif // MAINWINDOW_H
