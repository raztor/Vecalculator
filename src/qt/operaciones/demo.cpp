//
// Created by benjamin on 03-12-22.
//


#include "demo.h"
#include "ui_demo.h"

int operacion=0, dimension=0;

demo::demo(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::demo)
{
    ui->setupUi(this);
    ui->div_post_dim_hide->setDisabled(true);
    
}

demo::~demo()
{
    delete ui;
}


void demo::on_sel_op_currentIndexChanged(int index)
{
    // 1.suma 2.resta 3.angulo 4.modulo 5.componentes 6.producto cruz 7.producto punto 8.producto escalar 9.vector unitario
    operacion = index;


}

