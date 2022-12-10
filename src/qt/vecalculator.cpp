#include "vecalculator.h"

/* Lista de elementos
W_toogles = filtros del grafico
sel_2d y sel_3d = seleccion de dimension
grafico3d = grafico 3d
grafico2d = grafico 2d
 div_post_dim_hide = Division de la parte pre seleccion de dimension y la parte post seleccion de dimension (oculta y deshabilita elementos)

 */


int operacion=0, dimension=0;
float escalar=0;
Vecalculator_vectores Vector1,Vector2,Vector3;// Clase que crea el objeto vectores, contiene un punto inicial, un punto final y dimension
puntos vec1_origen,vec2_origen,vec1_fin,vec2_fin; //Clase que almacena un punto (coordenadas)
vec_result vec_resultado; // Clase encargada de almacenar la información de vector 1 y 2, operaciones, dimension, etc. (también realiza las operaciones)


//Constructor por defecto, además lo usamos para ocultar/mostrar y habilitar/deshabilitar elementos antes de que se genere la interfaz
vecalculator::vecalculator(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::vecalculator)
{
    ui->setupUi(this);
    ui->div_post_dim_hide->setHidden(true);
    ui->widget_placeholder->setHidden(false);
    ui->sel_2D->setDisabled(true);
    ui->W_toogles->setDisabled(true);
    ui->sel_3D->setDisabled(true);
    ui->grafico_3d->setHidden(true);
    vec_visibility(3, false, false, false, true);
}

vecalculator::~vecalculator()
{
    delete ui;
}


// Funcion encargada de restar el punto final con el inicial para obtener un vector con origen 0,0,0 para su posterior uso analitico
puntos resta_puntos(puntos a, puntos b){
    puntos c;
    c.setX(a.getX()-b.getX());
    c.setY(a.getY()-b.getY());
    c.setZ(a.getZ()-b.getZ());
    return c;
}


// 1.suma 2.resta 3.angulo* 4.modulo* 5.componentes* 6.producto cruz 7.producto punto 8.producto escalar* 9.vector unitario*
// Filtra los elementos de la interfaz para mostrar solo los necesarios para la operacion seleccionada
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
            vec_visibility(4, false, false, false, false);

            vec_visibility(2, false, false, false, false);
            vec_visibility(5, false, false, false, false);

            vec_visibility(3, false, false, false, true);
        }else if(op==3) {
            comp_3d = false;
            vec_unico = true;
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(false);
            vec_visibility(1, false, false, false, false);
            vec_visibility(4, false, false, false, false);

            vec_visibility(2, false, false, false, true);
            vec_visibility(5, false, false, false, true);

            vec_visibility(3, false, false, false, true);
        }else if(op==4||op==5||op==9) {
            comp_3d=true;
            vec_unico=true;
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(true);
            vec_visibility(1, false, false, false, false);
            vec_visibility(4, false, false, false, false);

            vec_visibility(2, false, false, false, true);
            vec_visibility(5, false, false, false, true);

            vec_visibility(3, false, false, false, true);
        }else if(op==8) {
            comp_3d = true;
            vec_unico = 2;// 2 significa escalar
            ui->sel_2D->setEnabled(true);
            ui->sel_3D->setEnabled(true);
            vec_visibility(1, false, false, false, false);
            vec_visibility(4, false, false, false, false);

            vec_visibility(2, false, false, false, true);
            vec_visibility(5, false, false, false, true);

            vec_visibility(3, false, false, false, false);
        }else{
            comp_3d=false;
            ui->sel_2D->setDisabled(true);
            ui->sel_3D->setDisabled(true);
            vec_visibility(1, false, false, false, true);
            vec_visibility(4, false, false, false, true);

            vec_visibility(2, false, false, false, true);
            vec_visibility(5, false, false, false, true);

            vec_visibility(3, false, false, false, true);
        }
    }
}


/* Función encargada de manipular la visibilidad de los widget de vectores
Ejes: true = Deshabilitado, false = Habilitado, Hidden = true -> oculta los elementos deshabilitados
Ocultar deshabilitar el eje x, deshabilita el widget vector completo
vec_visibility(NUMERO_VECTOR, Bool EJEX_BOOLY,BOOLX,BOOLZ,OCULTADO)
 */
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
    if(vec==4) {
        if (!x) {
            ui->widget_vec1->setDisabled(true);
        } else {
            ui->widget_vec1->setEnabled(true);
        }
        if (!y) {
            ui->vec1_eje_y_origen->setDisabled(true);
        } else {
            ui->vec1_eje_y_origen->setEnabled(true);
        }
        if (!z) {
            ui->vec1_eje_z_origen->setDisabled(true);
        } else {
            ui->vec1_eje_z_origen->setEnabled(true);
        }
        if (hidden) {
            ui->widget_vec1->setHidden(true);
        } else {
            ui->widget_vec1->setHidden(false);
        }
    }
    else if(vec==5) {
        if (!x) {
            ui->widget_vec2->setDisabled(true);
        } else {
            ui->widget_vec2->setEnabled(true);
        }
        if (!y) {
            ui->vec2_eje_y_origen->setDisabled(true);
        } else {
            ui->vec2_eje_y_origen->setEnabled(true);
        }
        if (!z) {
            ui->vec2_eje_z_origen->setDisabled(true);
        } else {
            ui->vec2_eje_z_origen->setEnabled(true);
        }
        if (hidden) {
            ui->widget_vec2->setHidden(true);
        } else {
            ui->widget_vec2->setHidden(false);
        }
    }
}


/* Funcion encargada de:
- Manipular visibilidad de elementos de la interfaz
- Manipular visibilidad de los widget vectores
*/
void vecalculator::modo2d(){
    dimension=2;
    ui->W_toogles->setHidden(false);
    ui->W_toogles->setEnabled(false);
    ui->grafico_2d->setHidden(false);
    ui->grafico_3d->setHidden(true);
    ui->div_post_dim_hide->setDisabled(false);
    if(vec_unico==0){
        vec_visibility(1, true, true, false, false);
        vec_visibility(4, true, true, false, false);

        vec_visibility(2, true, true, false, false);
        vec_visibility(5, true, true, false, false);

        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==1){
        vec_visibility(1, true, true, false, false);
        vec_visibility(4, true, true, false, false);

        vec_visibility(2, false, false, false, true);
        vec_visibility(5, false, false, false, true);

        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==2){
        vec_visibility(1, true, true, false, false);
        vec_visibility(4, true, true, false, false);

        vec_visibility(2, false, false, false, true);
        vec_visibility(5, false, false, false, true);

        vec_visibility(3, true, true, false, false);
    }
}


/* Funcion encargada de:
 * - Manipular visibilidad de elementos de la interfaz
 * - Manipular visibilidad de los widget vectores
 */
// Actualmente no se usa, ya que por problemas de rendimiento no se implementó el grafico 3D, solo se usa para ocultar y mostrar elementos
void vecalculator::modo3d(){
    dimension=3;
    ui->div_post_dim_hide->setDisabled(false);
    ui->grafico_2d->setHidden(true);
    ui->W_toogles->setHidden(true);
    ui->grafico_3d->setHidden(false);
    if(vec_unico==0){
        vec_visibility(1, true, true, true, false);
        vec_visibility(4, true, true, true, false);

        vec_visibility(2, true, true, true, false);
        vec_visibility(5, true, true, true, false);

        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==1){
        vec_visibility(1, true, true, true, false);
        vec_visibility(4, true, true, true, false);

        vec_visibility(2, false, false, false, true);
        vec_visibility(5, false, false, false, true);

        vec_visibility(3, false, false, false, true);
    }else if(vec_unico==2) {
        vec_visibility(1, true, true, true, false);
        vec_visibility(4, true, true, true, false);

        vec_visibility(2, false, false, false, true);
        vec_visibility(5, false, false, false, true);

        vec_visibility(3, true, true, true, false);
    }
}


// Funcion encargada de resetear los selectores de dimension al cambiar la operación
// Corrige alguno errores de la interfaz al cambiar de operacion
void vecalculator::reset_dim_select(){
    ui->div_post_dim_hide->setDisabled(true);
    ui->sel_2D->setAutoExclusive(false);
    ui->sel_3D->setAutoExclusive(false);
    ui->sel_2D->setChecked(false);
    ui->sel_3D->setChecked(false);
    ui->sel_2D->setAutoExclusive(true);
    ui->sel_3D->setAutoExclusive(true);
}


// Funcion encargada de iniciar las funciones correspondientes y filtrar la interfaz al cambiar de operacion
void vecalculator::on_sel_op_currentIndexChanged(int index)
{// 1.suma 2.resta 3.angulo 4.modulo 5.componentes 6.producto cruz 7.producto punto 8.producto escalar 9.vector unitario
    operacion = index;
    filtro_op_select(operacion);
    reset_dim_select();
}


// Funcion encargada de iniciar la funcion modo2d al presionar la opcion 2D
void vecalculator::on_sel_2D_pressed()
{
    modo2d();
}


// Funcion encargada de iniciar la funcion modo3d al presionar la opcion 3D
void vecalculator::on_sel_3D_clicked()
{
    modo3d();
}


// Funcion encargada de ejecutar las operaciones correspondientes al presionar el boton calcular
void vecalculator::on_B_calcular_clicked(){
    ui->grafico_2d->clearItems();
    Vector1.setOrigen(vec1_origen);// Origen del vector 1
    Vector2.setOrigen(vec2_origen);// Origen del vector 2
    Vector1.setFin(vec1_fin);// Fin del vector 1
    Vector2.setFin(vec2_fin);// Fin del vector 2
    Vector1.setFin_cero(resta_puntos(Vector1.getFin(),Vector1.getOrigen()));// Fin del vector 1 sin origen (origen en 0)
    Vector2.setFin_cero(resta_puntos(Vector2.getFin(),Vector2.getOrigen()));// Fin del vector 2 sin origen (origen en 0)
    std::cout << Vector1.getFin().getX() << " " << Vector1.getFin().getY() << " " << Vector1.getFin().getZ() << std::endl;// cout de depuración
    std::cout << "set fin cero: " << Vector1.getFin_cero().getX() << " " << Vector1.getFin_cero().getY() << " " << Vector1.getFin_cero().getZ() << std::endl;// cout de depuración

    vec_resultado.setVec1(Vector1.getFin_cero());// Seteo de vector 1 para el resultado
    vec_resultado.setVec2(Vector2.getFin_cero());// Seteo de vector 2 para el resultado
    vec_resultado.setEscalar(escalar);// Seteo de escalar para el resultado
    vec_resultado.setDimension(dimension);// Seteo de dimension para el resultado
    vec_resultado.setOperacion(operacion);// Seteo de operacion para el resultado
    vec_resultado.calcular();// Cálculo del resultado
    Vector3.setFin_cero(vec_resultado.getVecFinal());// Seteo del punto final del vector final para el resultado

    // Se encarga de mostrar u ocultar los botones de filtro de capas de la interfaz 2D
    if(dimension==2){
        ui->W_toogles->setHidden(false);
        ui->W_toogles->setDisabled(false);
        vecalculator::makePlot();
    }else if(dimension==3){
        ui->W_toogles->setHidden(true);
        ui->W_toogles->setDisabled(true);
    }
}


// Función encargada de poder copiar la imagen del gráfico al portapapeles
// Luego se puede pegar en cualquier lugar que acepte imágenes con ctrl+v
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


// Función encargada de asignar el valor del vector 1, origen, en x
void vecalculator::on_sel_vec1_x_origen_valueChanged(double arg1)
{
    vec1_origen.setX(arg1);
}


// Funcione encargada de asignar el valor del vector 1, fin, en X
void vecalculator::on_sel_vec1_x_valueChanged(double arg1)
{
    vec1_fin.setX(arg1);
}


// Funcion encargada de asignar el valor del vector 1, origen, en Y
void vecalculator::on_sel_vec1_y_origen_valueChanged(double arg1)
{
    vec1_origen.setY(arg1);
}

// Funcion encargada de asignar el valor del vector 1, fin, en Y
void vecalculator::on_sel_vec1_y_valueChanged(double arg1)
{
    vec1_fin.setY(arg1);
}


// Funcion encargada de asignar el valor del vector 1, origen, en Z
void vecalculator::on_sel_vec1_z_origen_valueChanged(double arg1)
{
    vec1_origen.setZ(arg1);
}


// Funcion encargada de asignar el valor del vector 1, fin, en Z
void vecalculator::on_sel_vec1_z_valueChanged(double arg1)
{
    vec1_fin.setZ(arg1);
}


// Funcion encargada de asignar el valor del vector 2, origen, en X
void vecalculator::on_sel_vec2_x_origen_valueChanged(double arg1)
{
    vec2_origen.setX(arg1);
}


// Funcion encargada de asignar el valor del vector 2, fin, en X
void vecalculator::on_sel_vec2_x_valueChanged(double arg1)
{
    vec2_fin.setX(arg1);
}


// Funcion encargada de asignar el valor del vector 2, origen, en Y
void vecalculator::on_sel_vec2_y_origen_valueChanged(double arg1)
{
    vec2_origen.setY(arg1);
}


// Funcion encargada de asignar el valor del vector 2, fin, en Y
void vecalculator::on_sel_vec2_y_valueChanged(double arg1)
{
    vec2_fin.setY(arg1);
}


// Funcion encargada de asignar el valor del vector 2, origen, en Z
void vecalculator::on_sel_vec2_z_origen_valueChanged(double arg1)
{
    vec2_origen.setZ(arg1);
}


//Funcion encargada de asignar el valor del vector 2, fin, en Z
void vecalculator::on_sel_vec2_z_valueChanged(double arg1)
{
    vec2_fin.setZ(arg1);
}


// Funcion encargada de asignar el valor del escalar
void vecalculator::on_sel_escalar_valueChanged(double arg1)
{
    escalar=arg1;
}


// Funcion encargada de crear el grafico 2D
void vecalculator::makePlot() {
    float x, y, or_x, or_y, min_x, max_x, min_y, max_y;
    x = vec_resultado.getVecFinal().getX();
    y = vec_resultado.getVecFinal().getY();
    std::cout << "x: " << x << " y: " << y << std::endl;
    or_x = 0;//vec_resultado.getVec1().getX();
    or_y = 0;//vec_resultado.getVec1().getY();

    // Lo de abajo se encarga de ver cual es el valor mas chico y mas grande de ambos ejes para así poder generar bien el rango del grafico
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


    // Lo de abajo se encarga de hacer las conversiones necesarias para poder mostrar el resultado de puntos arriba del grafico
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



    // Lo de abajo se encarga de crear las capas para luego ser filtradas en el grafico
    ui->grafico_2d->addLayer("geometrica", ui->grafico_2d->layer("main"), QCustomPlot::limAbove);
    ui->grafico_2d->addLayer("analitica", ui->grafico_2d->layer("main"), QCustomPlot::limAbove);
    ui->grafico_2d->addLayer("Vector1", ui->grafico_2d->layer("main"), QCustomPlot::limAbove);
    ui->grafico_2d->addLayer("Vector2", ui->grafico_2d->layer("main"), QCustomPlot::limAbove);

    QCPItemText *textLabel = new QCPItemText(ui->grafico_2d);

    ui->grafico_2d->setCurrentLayer("geometrica");
    QCPItemLine *R_geometrico = new QCPItemLine(ui->grafico_2d);

    ui->grafico_2d->setCurrentLayer("analitica");
    QCPItemLine *arrow = new QCPItemLine(ui->grafico_2d);

    ui->grafico_2d->setCurrentLayer("Vector1");
    QCPItemLine *V1 = new QCPItemLine(ui->grafico_2d);

    ui->grafico_2d->setCurrentLayer("Vector2");
    QCPItemLine *V2_or = new QCPItemLine(ui->grafico_2d);
    QCPItemLine *V2 = new QCPItemLine(ui->grafico_2d);


    //TODO: implementar colores de vectores y leyenda

    // Lo de abajo se encarga de plotear y hacer interactivo el grafico
    ui->grafico_2d->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                    QCP::iSelectLegend | QCP::iSelectPlottables);

    /*ui->grafico_2d->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->grafico_2d->legend->setFont(legendFont);
    ui->grafico_2d->legend->setSelectedFont(legendFont);
    ui->grafico_2d->legend->setSelectableParts(QCPLegend::spItems);*/


    // Esto se encarga de hacer que el grafico tengo correcto los valores de los ejes
    ui->grafico_2d->xAxis->setRange(min_x, max_x);
    ui->grafico_2d->yAxis->setRange(min_y, max_y);


    // Plotea los valores de los puntos del vector
    textLabel->setPositionAlignment(Qt::AlignTop);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0, 0);
    lbl = (std::string) "P. original: " + "(" + x_str_or + "," + y_str_or + ")" + "     " + "P.final: " + "(" + x_str +
          "," + y_str + ")";
    QString lbl_qt = QString::fromStdString(lbl);
    textLabel->setText(lbl_qt);
    textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
    textLabel->setPen(QPen(Qt::black)); //


    // añade vector analitico a la capa analitica
    arrow->start->setCoords(or_x, or_y);
    arrow->end->setCoords(x, y); // point to (4, 1.6) in x-y-plot coordinates
    arrow->setHead(QCPLineEnding::esSpikeArrow);


    // añade vector geometrico a la capa geometrica
    vec_result geometrico;
    geometrico.setVec1(Vector1.getFin());
    geometrico.setVec2(Vector2.getFin_cero());
    geometrico.setOperacion(operacion);
    geometrico.calcular();

    R_geometrico->start->setCoords(Vector1.getOrigen().getX(), Vector1.getOrigen().getY());
    R_geometrico->end->setCoords(geometrico.getVecFinal().getX(), geometrico.getVecFinal().getY()); // point to (4, 1.6) in x-y-plot coordinates
    R_geometrico->setHead(QCPLineEnding::esSpikeArrow);
    std::cout << "V2: " << Vector2.getOrigen().getX() << " " << Vector2.getOrigen().getY() << " " << Vector2.getFin().getX() << " " << Vector2.getFin().getY() << std::endl;
    // TODO ui->grafico_2d->rescaleAxes();
    ui->grafico_2d->replot();


    // añade el vector 1 a su capa
    V1->start->setCoords(Vector1.getOrigen().getX(), Vector1.getOrigen().getY());
    V1->end->setCoords(Vector1.getFin().getX(), Vector1.getFin().getY()); // point to (4, 1.6) in x-y-plot coordinates
    V1->setHead(QCPLineEnding::esSpikeArrow);
    std::cout << "V1: " << Vector1.getOrigen().getX() << " " << Vector1.getOrigen().getY() << " " << Vector1.getFin().getX() << " " << Vector1.getFin().getY() << std::endl;


    // añade el vector 2 y vector 2 geometrico a su capa
    V2->start->setCoords(Vector2.getOrigen().getX(), Vector2.getOrigen().getY());
    V2->end->setCoords(Vector2.getFin().getX(), Vector2.getFin().getY()); // point to (4, 1.6) in x-y-plot coordinates
    V2->setHead(QCPLineEnding::esSpikeArrow);
    std::cout << "V2: " << Vector2.getOrigen().getX() << " " << Vector2.getOrigen().getY() << " " << Vector2.getFin().getX() << " " << Vector2.getFin().getY() << std::endl;

    V2_or->start->setCoords(Vector1.getFin().getX(), Vector1.getFin().getY());
    V2_or->end->setCoords(geometrico.getVecFinal().getX(), geometrico.getVecFinal().getY()); // point to (4, 1.6) in x-y-plot coordinates
    // point to (4, 1.6) in x-y-plot coordinates
    V2_or->setHead(QCPLineEnding::esSpikeArrow);
    std::cout << "geometrico: " << geometrico.getVecFinal().getX() << " " << geometrico.getVecFinal().getY() << std::endl;
}


/* TODO: añadir output del resultado
 *
 *
 *
 *
 *
 *
 *
 *
 * */


// Se encarga de filtrar la capa analitica
void vecalculator::on_T_analitica_stateChanged(int arg1)
{
    std::cout << "on_T_analitica_stateChanged" << std::endl;
    if(arg1==0){
        ui->grafico_2d->layer("analitica")->setVisible(false);
        ui->grafico_2d->layer("analitica")->replot();
        std::cout << "on_T_analitica_stateChanged: 0" << std::endl;
    }else{
        ui->grafico_2d->layer("analitica")->setVisible(true);
        ui->grafico_2d->layer("analitica")->replot();
        std::cout << "on_T_analitica_stateChanged: 1" << std::endl;
    }

}


// Se encarga de filtrar la capa geometrica
void vecalculator::on_T_geometrica_stateChanged(int arg1)
{
    std::cout << "on_T_analitica_stateChanged" << std::endl;
    if(arg1==0){
        ui->grafico_2d->layer("geometrica")->setVisible(false);
        ui->grafico_2d->layer("geometrica")->replot();
        std::cout << "on_T_Geometrica_stateChanged: 0" << std::endl;
    }else{
        ui->grafico_2d->layer("geometrica")->setVisible(true);
        ui->grafico_2d->layer("geometrica")->replot();
        std::cout << "on_T_Geometrica_stateChanged: 1" << std::endl;
    }

}


// Se encarga de filtrar la capa de vector 1
void vecalculator::on_T_vector1_stateChanged(int arg1)
{
    std::cout << "on_T_vector1_stateChanged" << std::endl;
    if(arg1==0){
        ui->grafico_2d->layer("Vector1")->setVisible(false);
        ui->grafico_2d->layer("Vector1")->replot();
        std::cout << "on_T_vector1_stateChanged: 0" << std::endl;
    }else{
        ui->grafico_2d->layer("Vector1")->setVisible(true);
        ui->grafico_2d->layer("Vector1")->replot();
        std::cout << "on_T_vector1_stateChanged: 1" << std::endl;
    }

}


// Se encarga de filtrar la capa de vector 2
void vecalculator::on_T_vector2_stateChanged(int arg1)
{
    std::cout << "on_T_vector2_stateChanged" << std::endl;
    if(arg1==0){
        ui->grafico_2d->layer("Vector2")->setVisible(false);
        ui->grafico_2d->layer("Vector2")->replot();
        std::cout << "on_T_vector2_stateChanged: 0" << std::endl;
    }else{
        ui->grafico_2d->layer("Vector2")->setVisible(true);
        ui->grafico_2d->layer("Vector2")->replot();
        std::cout << "on_T_vector2_stateChanged: 1" << std::endl;
    }
}

