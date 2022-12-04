//
// Created by benjamin on 03-12-22.
//

#ifndef VECALCULATOR_DEMO_H
#define VECALCULATOR_DEMO_H

#include <QWidget>
#include <QMainWindow>

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

private slots:
    void on_sel_op_currentIndexChanged(int index);
    void on_sel_2D_pressed();
    void on_sel_3D_clicked();

private:
    Ui::demo *ui;
    int dim;
    int vec_unico;
    bool comp_3d;

};

#endif //VECALCULATOR_DEMO_H
