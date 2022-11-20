#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::makePlot();
}

MainWindow::MainWindow(float x, float y, float or_x, float or_y)
    : QMainWindow(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setEje_x(x);
    MainWindow::setEje_y(y);
    MainWindow::setOr_x(or_x);
    MainWindow::setOr_y(or_y);
    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot(){
    float x,y,or_x,or_y,min_x,max_x,min_y,max_y;
    x = eje_x;
    y = eje_y;
    or_x = original_x;
    or_y = original_y;

    if(eje_x >= or_x){
        min_x = or_x;
        max_x = eje_x;
    }else if(eje_x < or_x){
        min_x = eje_x;
        max_x = or_x;
    }if(eje_y >= or_y) {
        min_y = or_y;
        max_y = eje_y;
    }else if(eje_y < or_y){
        min_y = eje_y;
        max_y = or_y;
    }

    ui->customplot->xAxis->setRange(min_x, max_x);
    ui->customplot->yAxis->setRange(min_y, max_y);
    // add the arrow:
    QCPItemLine *arrow = new QCPItemLine(ui->customplot);
    arrow->start->setCoords(or_x, or_y);
    arrow->end->setCoords(x, y); // point to (4, 1.6) in x-y-plot coordinates
    arrow->setHead(QCPLineEnding::esSpikeArrow);
}
