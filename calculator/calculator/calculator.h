#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QDebug>
#include <QStack>

struct put_ctrl_t{
    QString old_put;
    QString new_put;
    int brackets_cnt;
    int update_flag;
};

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

    QString puts;
    struct put_ctrl_t put_ctrl;
private:
    Ui::Calculator *ui;
    int Priority(QString data);
    int mask_data(QString expression, QString *mask_buffer);
    int re_polish(QString *mask_buffer,QString *repolish,int length);
    double repolish_calculat(QString *repolish,int length);
    void calculate_result(QString expression);

private slots:
    void push_button_0();
    void push_button_1();

    void push_button_2();
    void push_button_3();
    void push_button_4();
    void push_button_5();
    void push_button_6();
    void push_button_7();
    void push_button_8();
    void push_button_9();
    void push_button_point();

    void push_button_left();
    void push_button_right();

    void push_button_add();
    void push_button_minus();
    void push_button_ride();
    void push_button_divide();
    void push_button_equal();

    void push_button_CE();
    void push_button_AC();

};

#endif // CALCULATOR_H

