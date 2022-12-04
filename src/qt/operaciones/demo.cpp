//
// Created by benjamin on 03-12-22.
//


#include "demo.h"
#include "ui_demo.h"
#include <iostream>

int operacion=0, dimension=0;

demo::demo(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::demo)
{
    ui->setupUi(this);
    ui->div_post_dim_hide->setHidden(true);
    ui->widget_placeholder->setHidden(false);
    ui->sel_2D->setDisabled(true);
    ui->sel_3D->setDisabled(true);
    vec_visibility(3, false, false, false, true);
    
}

demo::~demo()
{
    delete ui;
}

// 1.suma 2.resta 3.angulo* 4.modulo* 5.componentes* 6.producto cruz 7.producto punto 8.producto escalar* 9.vector unitario*
void demo::filtro_op_select(int op){
    std::cout<<"prueba"<<std::endl;
    if(op==0){
        comp_3d=false;
        ui->sel_2D->setDisabled(true);
        ui->sel_3D->setDisabled(true);
        ui->div_post_dim_hide->setHidden(true);
        ui->widget_placeholder->setHidden(false);
    }else{
        ui->div_post_dim_hide->setDisabled(false);
        ui->div_post_dim_hide->setHidden(false);
        ui->widget_placeholder->setHidden(true);
        if(op==1||op==2||op==6||op==7) {
            comp_3d = true;
            vec_unico = false;
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(true);
            vec_visibility(1, false, false, false, false);
            vec_visibility(2, false, false, false, false);
            vec_visibility(3, false, false, false, true);
        }else if(op==3) {
            comp_3d = false;
            vec_unico = true;
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(false);
            vec_visibility(1, false, false, false, false);
            vec_visibility(2, false, false, false, true);
            vec_visibility(3, false, false, false, true);
        }else if(op==4||op==5||op==9) {
            comp_3d=true;
            vec_unico=true;
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(true);
            vec_visibility(1, false, false, false, false);
            vec_visibility(2, false, false, false, true);
            vec_visibility(3, false, false, false, true);
        }else if(op==8) {
            comp_3d = true;
            vec_unico = 2;// 2 significa escalar
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(true);
            vec_visibility(1, false, false, false, false);
            vec_visibility(2, false, false, false, true);
            vec_visibility(3, false, false, false, false);
        }else{
            comp_3d=false;
            ui->sel_2D->setDisabled(true);
            ui->sel_3D->setDisabled(true);
            vec_visibility(1, false, false, false, true);
            vec_visibility(2, false, false, false, true);
            vec_visibility(3, false, false, false, true);
        }
    }
}

void demo::vec_visibility(int vec, bool x, bool y, bool z, bool hidden){
    if(vec==1){
        if(!x){
            ui->widget_vec1->setDisabled(true);
        }else{
            ui->widget_vec1->setEnabled(true);
        }
        if(!y){
            ui->vec1_eje_y->setDisabled(true);
        }else{
            ui->vec1_eje_y->setEnabled(true);
        }
        if(!z){
            ui->vec1_eje_z->setDisabled(true);
        }else{
            ui->vec1_eje_z->setEnabled(true);
        }if(hidden) {
            ui->widget_vec1->setHidden(true);
        }else{
            ui->widget_vec1->setHidden(false);
        }
    }else if(vec==2){
        if(!x){
            ui->widget_vec2->setDisabled(true);
        }else{
            ui->widget_vec2->setEnabled(true);
        }
        if(!y){
            ui->vec2_eje_y->setDisabled(true);
        }else{
            ui->vec2_eje_y->setEnabled(true);
        }
        if(!z){
            ui->vec2_eje_z->setDisabled(true);
        }else{
            ui->vec2_eje_z->setEnabled(true);
        }if(hidden) {
            ui->widget_vec2->setHidden(true);
        }else{
            ui->widget_vec2->setHidden(false);
        }
    }else if(vec==3){
        if(!x){
            ui->widget_escalar->setDisabled(true);
        }else{
            ui->widget_escalar->setEnabled(true);
        }if(hidden) {
            ui->widget_escalar->setHidden(true);
    }else{
            ui->widget_escalar->setHidden(false);
        }
    }
}

void demo::modo2d(){
    dimension=2;
    ui->div_post_dim_hide->setDisabled(false);
    if(vec_unico==0){
        vec_visibility(1, true, true, false, false);
        vec_visibility(2, true, true, false, false);
        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==1){
        vec_visibility(1, true, true, false, false);
        vec_visibility(2, false, false, false, true);
        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==2){
        vec_visibility(1, true, true, false, false);
        vec_visibility(2, false, false, false, true);
        vec_visibility(3, true, true, false, false);
    }
}

void demo::modo3d(){
    dimension=3;
    ui->div_post_dim_hide->setDisabled(false);
    if(vec_unico==0){
        vec_visibility(1, true, true, true, false);
        vec_visibility(2, true, true, true, false);
        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==1){
        vec_visibility(1, true, true, true, false);
        vec_visibility(2, false, false, false, true);
        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==2) {
        vec_visibility(1, true, true, true, false);
        vec_visibility(2, false, false, false, true);
        vec_visibility(3, true, true, true, false);
    }
}

void demo::reset_dim_select(){
    ui->div_post_dim_hide->setDisabled(true);
    ui->sel_2D->setAutoExclusive(false);
    ui->sel_3D->setAutoExclusive(false);
    ui->sel_2D->setChecked(false);
    ui->sel_3D->setChecked(false);
    ui->sel_2D->setAutoExclusive(true);
    ui->sel_3D->setAutoExclusive(true);
}
// TODO: obtener los valores de los vectores y conectar las funciones
void demo::on_sel_op_currentIndexChanged(int index)
{// 1.suma 2.resta 3.angulo 4.modulo 5.componentes 6.producto cruz 7.producto punto 8.producto escalar 9.vector unitario
    operacion = index;
    filtro_op_select(operacion);
    reset_dim_select();
}

void demo::on_sel_2D_pressed()
{
    std::cout<<"on2d"<<std::endl;
    modo2d();
}

void demo::on_sel_3D_clicked()
{
    modo3d();
}
