//
// Created by benjamin on 03-12-22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_op_select.h" resolved

#include "op_select.h"
#include "ui_op_select.h"

namespace op_select {
    op_select::op_select(QWidget *parent) :
            QWidget(parent), ui(new Ui::op_select) {
        ui->setupUi(this);
    }

    op_select::~op_select() {
        delete ui;
    }
} // op_select
