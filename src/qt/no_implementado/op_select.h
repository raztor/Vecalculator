//
// Created by benjamin on 03-12-22.
//

#ifndef VECALCULATOR_OP_SELECT_H
#define VECALCULATOR_OP_SELECT_H

#include <QWidget>

namespace op_select {
    QT_BEGIN_NAMESPACE
    namespace Ui { class op_select; }
    QT_END_NAMESPACE

    class op_select : public QWidget {
    Q_OBJECT

    public:
        explicit op_select(QWidget *parent = nullptr);

        ~op_select() override;

    private:
        Ui::op_select *ui;
    };
} // op_select

#endif //VECALCULATOR_OP_SELECT_H
