#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qcustomplot.h"
#include <QMainWindow>
#include <iostream>
#include <string>
#include "operaciones.h"
#include <sstream>
#include <iomanip>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(float x, float y, float or_x, float or_y);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setEje_x(float x);
    void setEje_y(float y);
    void setOr_x(float or_x);
    void setOr_y(float or_y);

private slots:
    void makePlot();

private:
    Ui::MainWindow *ui;
    float eje_x;
    float eje_y;
    float original_x;
    float original_y;
};
#endif // MAINWINDOW_H
