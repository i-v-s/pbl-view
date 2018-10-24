#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
QT_CHARTS_USE_NAMESPACE
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void stop();
    void on_pushButton_clicked();
    void readData();
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_buttonStop_clicked();

private:
    QTimer stopTimer;
    uint staticValue, staticMin, staticMax, staticStep;
    qint64 staticDelay, staticNext;
    qreal minX, maxX, minForce, maxForce, minVoltage, maxVoltage;
    QLineSeries *forceSeries, *voltageSeries;
    QSerialPort port;
    QChart *chart;
    QAbstractAxis *axisX, *axisForce, *axisVoltage;
    Ui::MainWindow *ui;
    void append(qreal x, qreal force, qreal voltage);
    void setOut(uint out);
};

#endif // MAINWINDOW_H