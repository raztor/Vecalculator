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
    std::stringstream x_stream;
    std::stringstream y_stream;
    x_stream << std::fixed << std::setprecision(2) << x;
    std::string x_str = x_stream.str();
    y_stream << std::fixed << std::setprecision(2) << y;
    std::string y_str = y_stream.str();

    std::stringstream x_stream_or;
    std::stringstream y_stream_or;
    x_stream_or << std::fixed << std::setprecision(2) << original_x;
    std::string x_str_or = x_stream_or.str();
    y_stream_or << std::fixed << std::setprecision(2) << original_y;
    std::string y_str_or = y_stream_or.str();

    std::string lbl;
    std::string lbl_or;

    //poner if else para agrandar y achicar plano

    ui->customplot->setInteraction(QCP::iRangeZoom, true);
    ui->customplot->setInteraction(QCP::iRangeDrag, true);
    ui->customplot->setInteraction(QCP::iSelectPlottables, true);

    ui->customplot->xAxis->setRange(min_x, max_x);
    ui->customplot->yAxis->setRange(min_y, max_y);
    QCPItemText *textLabel = new QCPItemText(ui->customplot);
    textLabel->setPositionAlignment(Qt::AlignTop);
    textLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
    textLabel->position->setCoords(0.5, 0);
    lbl = (std::string)"Final: " + "(" + x_str + "," + y_str + ")";
    QString lbl_qt = QString::fromStdString(lbl);
    textLabel->setText(lbl_qt);
    textLabel->setFont(QFont(font().family(), 16)); // make font a bit larger
    textLabel->setPen(QPen(Qt::black)); //

    // add the arrow:
    QCPItemLine *arrow = new QCPItemLine(ui->customplot);
    arrow->start->setCoords(or_x, or_y);
    arrow->end->setCoords(x, y); // point to (4, 1.6) in x-y-plot coordinates
    arrow->setHead(QCPLineEnding::esSpikeArrow);
}
