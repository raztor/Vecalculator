//
// Created by benjamin on 03-12-22.
//

#ifndef VECALCULATOR_DEMO_H
#define VECALCULATOR_DEMO_H

#include <QWidget>
#include <QMainWindow>
#include <iostream>
//#include <string>
//#include <sstream>
#include <iomanip>
#include "../include/vec_result.h"
#include "qcustomplot.h"
#include "ui_demo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class demo; }
QT_END_NAMESPACE

class demo : public QMainWindow
{
Q_OBJECT

public:
    demo(QWidget *parent = nullptr);
    ~demo();
    void filtro_op_select(int op);
    void reset_dim_select();
    void modo2d();
    void modo3d();
    void vec_visibility(int vec, bool x, bool y, bool z, bool hidden);

    // Grafica 2D
    void setEje_x(float x);
    void setEje_y(float y);
    void setOr_x(float or_x);
    void setOr_y(float or_y);

private slots:
    //Grafica 2D
    void makePlot();

    void on_B_calcular_clicked();

    void on_sel_op_currentIndexChanged(int index);
    void on_sel_2D_pressed();
    void on_sel_3D_clicked();

    void on_sel_vec1_x_valueChanged(double arg1);
    void on_sel_vec1_y_valueChanged(double arg1);
    void on_sel_vec1_z_valueChanged(double arg1);

    void on_sel_vec2_x_valueChanged(double arg1);
    void on_sel_vec2_y_valueChanged(double arg1);
    void on_sel_vec2_z_valueChanged(double arg1);
    void on_sel_escalar_valueChanged(double arg1);


private:
    Ui::demo *ui;
    int dim;
    int vec_unico;
    bool comp_3d;

    //Grafica 2D
    float eje_x;
    float eje_y;
    float original_x;
    float original_y;

};

#endif //VECALCULATOR_DEMO_H
