#include "vecalculator.h"

int operacion=0, dimension=0;
float escalar=0;
vec vector1 = NULL_VEC, vector2 = NULL_VEC, result_vec=NULL_VEC;// Inicializacion de los vectores con valor 0

vec_result vec_resultado;

vecalculator::vecalculator(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::vecalculator)
{
    ui->setupUi(this);
    ui->div_post_dim_hide->setHidden(true);
    ui->widget_placeholder->setHidden(false);
    ui->sel_2D->setDisabled(true);
    ui->sel_3D->setDisabled(true);
    vec_visibility(3, false, false, false, true);
    
}

vecalculator::~vecalculator()
{
    delete ui;
}

// 1.suma 2.resta 3.angulo* 4.modulo* 5.componentes* 6.producto cruz 7.producto punto 8.producto escalar* 9.vector unitario*
void vecalculator::filtro_op_select(int op){
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

void vecalculator::vec_visibility(int vec, bool x, bool y, bool z, bool hidden){
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

void vecalculator::modo2d(){
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

void vecalculator::modo3d(){
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

void vecalculator::reset_dim_select(){
    ui->div_post_dim_hide->setDisabled(true);
    ui->sel_2D->setAutoExclusive(false);
    ui->sel_3D->setAutoExclusive(false);
    ui->sel_2D->setChecked(false);
    ui->sel_3D->setChecked(false);
    ui->sel_2D->setAutoExclusive(true);
    ui->sel_3D->setAutoExclusive(true);
}
// TODO: obtener los valores de los vectores y conectar las funciones
void vecalculator::on_sel_op_currentIndexChanged(int index)
{// 1.suma 2.resta 3.angulo 4.modulo 5.componentes 6.producto cruz 7.producto punto 8.producto escalar 9.vector unitario
    operacion = index;
    filtro_op_select(operacion);
    reset_dim_select();
}

void vecalculator::on_sel_2D_pressed()
{
    modo2d();
}

void vecalculator::on_sel_3D_clicked()
{
    modo3d();
}

void vecalculator::on_B_calcular_clicked(){
    ui->grafico_2d->clearItems();
    vec_resultado.setVec1(vector1);
    vec_resultado.setVec2(vector2);
    vec_resultado.setEscalar(escalar);
    vec_resultado.setDimension(dimension);
    vec_resultado.setOperacion(operacion);
    vec_resultado.calcular();
    result_vec=vec_resultado.getVecFinal();
    vecalculator::makePlot();
}

void vecalculator::on_B_descargar_clicked() {
    QPixmap pixmap = ui->grafico_2d->grab();
    QImage image = pixmap.toImage();
    Q_ASSERT(!image.isNull());
    QApplication::clipboard()->setImage(image, QClipboard::Clipboard);
    QMessageBox::information(
            this,
            tr("Vecalculator"),
            tr("La imagen fue copiada al portapapeles.") );
}


void vecalculator::on_sel_vec1_x_valueChanged(double arg1)
{
    vector1.eje_x=arg1;
}

void vecalculator::on_sel_vec1_y_valueChanged(double arg1)
{
    vector1.eje_y=arg1;
}

void vecalculator::on_sel_vec1_z_valueChanged(double arg1)
{
    vector1.eje_z=arg1;
}

void vecalculator::on_sel_vec2_x_valueChanged(double arg1)
{
    vector2.eje_x=arg1;
}

void vecalculator::on_sel_vec2_y_valueChanged(double arg1)
{
    vector2.eje_y=arg1;
}

void vecalculator::on_sel_vec2_z_valueChanged(double arg1)
{
    vector2.eje_z=arg1;
}

void vecalculator::on_sel_escalar_valueChanged(double arg1)
{
    escalar=arg1;
}


void vecalculator::makePlot() {
    // Lo de abajo se encarga de ver cual es el valor mas chico y mas grande de ambos ejes para así poder generar bien el rango del grafico
    float x, y, or_x, or_y, min_x, max_x, min_y, max_y;
    x = vec_resultado.getVecFinal().eje_x;
    y = vec_resultado.getVecFinal().eje_y;
    or_x = vec_resultado.getVec1().eje_x;
    or_y = vec_resultado.getVec1().eje_y;

    if (x >= or_x) {
        min_x = or_x;
        max_x = x;
    } else if (x < or_x) {
        min_x = x;
        max_x = or_x;
    }
    if (y >= or_y) {
        min_y = or_y;
        max_y = y;
    } else if (y < or_y) {
        min_y = y;
        max_y = or_y;
    }
    std::stringstream x_stream;
    std::stringstream y_stream;
    x_stream << std::fixed << std::setprecision(2) << x;
    std::string x_str = x_stream.str();
    y_stream << std::fixed << std::setprecision(2) << y;
    std::string y_str = y_stream.str();

    std::stringstream x_stream_or;
    std::stringstream y_stream_or;
    x_stream_or << std::fixed << std::setprecision(2) << or_x;
    std::string x_str_or = x_stream_or.str();
    y_stream_or << std::fixed << std::setprecision(2) << or_y;
    std::string y_str_or = y_stream_or.str();

    std::string lbl;
    std::string lbl_or;

    // Todo lo de abajo esta encargado de plotear y hacer el grafico interactivo


    ui->grafico_2d->setInteraction(QCP::iRangeZoom, true);
    ui->grafico_2d->setInteraction(QCP::iRangeDrag, true);
    ui->grafico_2d->setInteraction(QCP::iSelectPlottables, true);

    // Esto se encarga de hacer que el grafico tengo correcto los valores de los ejes

    ui->grafico_2d->xAxis->setRange(min_x, max_x);
    ui->grafico_2d->yAxis->setRange(min_y, max_y);
    QCPItemText *textLabel = new QCPItemText(ui->grafico_2d);
    textLabel->setPositionAlignment(Qt::AlignTop);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    // Esto es para asignar el texto de coordenadas
    textLabel->position->setCoords(0, 0);
    lbl = (std::string) "P. original: " + "(" + x_str_or + "," + y_str_or + ")" + "     " + "P.final: " + "(" + x_str +
          "," + y_str + ")";
    QString lbl_qt = QString::fromStdString(lbl);
    textLabel->setText(lbl_qt);
    textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
    textLabel->setPen(QPen(Qt::black)); //

    // add the arrow:
    QCPItemLine *arrow = new QCPItemLine(ui->grafico_2d);
    arrow->start->setCoords(or_x, or_y);
    arrow->end->setCoords(x, y); // point to (4, 1.6) in x-y-plot coordinates
    arrow->setHead(QCPLineEnding::esSpikeArrow);
    ui->grafico_2d->replot();
}

//TODO: añadir output del resultado
//TODO: añadir grafico 3d