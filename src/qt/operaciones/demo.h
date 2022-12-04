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

private slots:
    void on_sel_op_currentIndexChanged(int index);
private:
    Ui::demo *ui;

};

#endif //VECALCULATOR_DEMO_H
