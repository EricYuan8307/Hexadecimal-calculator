#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    /*所有按键，信号连接*/
    connect(ui->button_0,SIGNAL(clicked()),this,SLOT(push_button_0()));
    connect(ui->button_1,SIGNAL(clicked()),this,SLOT(push_button_1()));
    connect(ui->button_2,SIGNAL(clicked()),this,SLOT(push_button_2()));
    connect(ui->button_3,SIGNAL(clicked()),this,SLOT(push_button_3()));
    connect(ui->button_4,SIGNAL(clicked()),this,SLOT(push_button_4()));
    connect(ui->button_5,SIGNAL(clicked()),this,SLOT(push_button_5()));
    connect(ui->button_6,SIGNAL(clicked()),this,SLOT(push_button_6()));
    connect(ui->button_7,SIGNAL(clicked()),this,SLOT(push_button_7()));
    connect(ui->button_8,SIGNAL(clicked()),this,SLOT(push_button_8()));
    connect(ui->button_9,SIGNAL(clicked()),this,SLOT(push_button_9()));
    connect(ui->button_point,SIGNAL(clicked()),this,SLOT(push_button_point()));

    connect(ui->button_left,SIGNAL(clicked()),this,SLOT(push_button_left()));   // (
    connect(ui->button_right,SIGNAL(clicked()),this,SLOT(push_button_right())); // )

    connect(ui->button_add,SIGNAL(clicked()),this,SLOT(push_button_add()));       //  +
    connect(ui->button_minus,SIGNAL(clicked()),this,SLOT(push_button_minus()));   //  -
    connect(ui->button_ride,SIGNAL(clicked()),this,SLOT(push_button_ride()));     //  *
    connect(ui->button_divide,SIGNAL(clicked()),this,SLOT(push_button_divide())); //  /
    connect(ui->button_equal,SIGNAL(clicked()),this,SLOT(push_button_equal()));   //  =

    connect(ui->button_AC,SIGNAL(clicked()),this,SLOT(push_button_AC()));
    connect(ui->button_CE,SIGNAL(clicked()),this,SLOT(push_button_CE()));

    /*结构体初始化*/
    put_ctrl.brackets_cnt = 0;
    put_ctrl.update_flag = 0;
    put_ctrl.new_put = "0";
    put_ctrl.old_put = "0";
    ui->put_data->setText(put_ctrl.new_put);
}

Calculator::~Calculator()
{
    delete ui;
}

/*获取操作符优先级*/
int Calculator::Priority(QString data)
{
    int priority;
    if(data == "(")
        priority = 1;
    else if(data == "+" || data == "-")
        priority = 2;
    else if(data == "*" || data == "/")
        priority = 3;
    else if (data == ")")
        priority = 4;
    else
        priority = -1;
    return priority;
}

/*将表达式的数据，操作符分割，依次存入mask_buffer数组中*/
int Calculator::mask_data(QString expression, QString *mask_buffer)
{
    int i,k = 0,cnt = 0;
    QString::iterator p = expression.begin();
    int length = expression.length();
    for(i = 0 ; i < length ; i += cnt,k++)
    {
        cnt = 0;
        if(*p >= '0' && *p <= '9')
        {
            QString temp = *p;
            p ++;
            cnt ++;
            while((*p >= '0' && *p <= '9') || *p == '.')
            {
                temp += *p;
                p++;
                cnt ++;
            }
            mask_buffer[k] = temp;
        }else{
            QString temp = *p;
            p++;
            cnt ++;
            mask_buffer[k] = temp;
        }
    }
    return k;
}

/*将获取到的分割好的表达式数组，转化为逆波兰表达式，存入数组repolish中*/
int Calculator::re_polish(QString *mask_buffer,QString *repolish,int length)
{
    QStack<QString> st2;
    int i = 0;
    for(int j = 0 ; j < length ; j++)
    {
        if(mask_buffer[j] != "(" && mask_buffer[j] != ")" && mask_buffer[j] != "+" && mask_buffer[j] != "-" && mask_buffer[j] != "*" && mask_buffer[j] != "/" )
            repolish[i++] = mask_buffer[j];
        else if(mask_buffer[j] == "("){
            st2.push(mask_buffer[j]);
        }
        else if(mask_buffer[j] == ")"){
            while(st2.top() != "(")
            {
                repolish[i++] = st2.top();
                st2.pop();
            }
            if(st2.top() == "(")
                st2.pop();
        }
        else if(st2.empty() || Priority(mask_buffer[j]) > Priority(st2.top()))
            st2.push(mask_buffer[j]);
        else{
            while(Priority(mask_buffer[j]) <= Priority(st2.top()))
            {
                repolish[i++] = st2.top();
                st2.pop();
                if(st2.empty())
                    break;
            }
            st2.push(mask_buffer[j]);
        }
    }
    while(!st2.empty())
    {
        repolish[i++] = st2.top();
        st2.pop();
    }
    return i;
}

/*计算逆波兰表达式值并显示*/
double Calculator::repolish_calculat(QString *repolish,int length)
{
    QStack <double> st;
    for(int m = 0 ; m < length ; m ++)
    {
        if(repolish[m] != "+" && repolish[m] != "-" && repolish[m] != "*" && repolish[m] != "/" )
        {
            st.push(repolish[m].toDouble());
        }
        else
        {
            if(repolish[m] == "+")
            {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if(repolish[m] == "-")
            {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if(repolish[m] == "*")
            {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if(repolish[m] == "/")
            {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();
                if(a != 0)
                   st.push(b/a);
                else
                {
                    ui->display->clear();
                    ui->put_data->setText("0 不能做除数");
                    return -1;
                }
            }
        }
    }
    QString res = QString::number(st.top(),'g',10);
    ui->display->clear();
    ui->put_data->setText(res);
    return st.top();
}

/*表达式计算整合*/
void Calculator::calculate_result(QString expression)
{
    QString mask_buffer[100]={"0"},repolish[100]={"0"};
    int length = mask_data(expression,mask_buffer);
    length = re_polish(mask_buffer,repolish,length);
    double result = repolish_calculat(repolish,length);
}

/*数据按键输入*/
void Calculator::push_button_0()
{
    if(put_ctrl.new_put == "0"){
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 1;
    }
    else
        put_ctrl.new_put += "0";
    ui->put_data->setText(put_ctrl.new_put);
}

void Calculator::push_button_1()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "1";
    else
        put_ctrl.new_put += "1";
    ui->put_data->setText(put_ctrl.new_put);
}

void Calculator::push_button_2()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "2";
    else
        put_ctrl.new_put += "2";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_3()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "3";
    else
        put_ctrl.new_put += "3";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_4()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "4";
    else
        put_ctrl.new_put += "4";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_5()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "5";
    else
        put_ctrl.new_put += "5";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_6()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "6";
    else
        put_ctrl.new_put += "6";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_7()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "7";
    else
        put_ctrl.new_put += "7";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_8()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "8";
    else
        put_ctrl.new_put += "8";
    ui->put_data->setText(put_ctrl.new_put);
}
void Calculator::push_button_9()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "9";
    else
        put_ctrl.new_put += "9";
    ui->put_data->setText(put_ctrl.new_put);
}

void Calculator::push_button_point()
{
    if(put_ctrl.new_put == "0")
        put_ctrl.new_put = "0.";
    else{
        if(-1 == put_ctrl.new_put.indexOf("."))
            put_ctrl.new_put += ".";
    }
    ui->put_data->setText(put_ctrl.new_put);
}

void Calculator::push_button_left()
{
    if(put_ctrl.old_put == "0"){
        put_ctrl.old_put = "(";
        put_ctrl.brackets_cnt ++;
    }
    else{
        put_ctrl.old_put += "(";
        put_ctrl.brackets_cnt ++;
    }
    ui->display->setText(put_ctrl.old_put);
}

void Calculator::push_button_right()
{
    if(put_ctrl.brackets_cnt > 0){
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p != ')')
            put_ctrl.old_put += put_ctrl.new_put;
        put_ctrl.old_put += ")";
        put_ctrl.brackets_cnt --;
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 0;
        ui->display->setText(put_ctrl.old_put);
    }
}
/*+ - * / = 按键输入*/
void Calculator::push_button_add()
{
    if(put_ctrl.old_put == "0"){
        put_ctrl.old_put = put_ctrl.new_put;
        put_ctrl.old_put += "+";
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 0;
    }
    else{
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ){
            if(put_ctrl.new_put == "0"){
                if(put_ctrl.update_flag){
                    put_ctrl.old_put += put_ctrl.new_put;
                    put_ctrl.old_put += "+";
                    put_ctrl.new_put = "0";
                    put_ctrl.update_flag = 0;
                }
            }else{
                put_ctrl.old_put += put_ctrl.new_put;
                put_ctrl.old_put += "+";
                put_ctrl.new_put = "0";
                put_ctrl.update_flag = 0;
            }
        }else if(*p == ')') {
            put_ctrl.old_put += "+";
        }
    }
    ui->display->setText(put_ctrl.old_put);
}

void Calculator::push_button_minus()
{
    if(put_ctrl.old_put == "0"){
        put_ctrl.old_put = put_ctrl.new_put;
        put_ctrl.old_put += "-";
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 0;
    }
    else{
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ){
            if(put_ctrl.new_put == "0"){
                if(put_ctrl.update_flag || *p == '('){
                    put_ctrl.old_put += put_ctrl.new_put;
                    put_ctrl.old_put += "-";
                    put_ctrl.new_put = "0";
                    put_ctrl.update_flag = 0;
                }
            }else{
                put_ctrl.old_put += put_ctrl.new_put;
                put_ctrl.old_put += "-";
                put_ctrl.new_put = "0";
                put_ctrl.update_flag = 0;
            }
        }else if(*p == ')') {
            put_ctrl.old_put += "-";
        }
    }
    ui->display->setText(put_ctrl.old_put);
}

void Calculator::push_button_ride()
{
    if(put_ctrl.old_put == "0"){
        put_ctrl.old_put = put_ctrl.new_put;
        put_ctrl.old_put += "*";
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 0;
    }
    else{
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ){
            if(put_ctrl.new_put == "0"){
                if(put_ctrl.update_flag){
                    put_ctrl.old_put += put_ctrl.new_put;
                    put_ctrl.old_put += "*";
                    put_ctrl.new_put = "0";
                    put_ctrl.update_flag = 0;
                }
            }else{
                put_ctrl.old_put += put_ctrl.new_put;
                put_ctrl.old_put += "*";
                put_ctrl.new_put = "0";
                put_ctrl.update_flag = 0;
            }
        }else if(*p == ')') {
            put_ctrl.old_put += "*";
        }
    }
    ui->display->setText(put_ctrl.old_put);
}

void Calculator::push_button_divide()
{
    if(put_ctrl.old_put == "0"){
        put_ctrl.old_put = put_ctrl.new_put;
        put_ctrl.old_put += "/";
        put_ctrl.new_put = "0";
        put_ctrl.update_flag = 0;
    }
    else{
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ){
            if(put_ctrl.new_put == "0"){
                if(put_ctrl.update_flag){
                    put_ctrl.old_put += put_ctrl.new_put;
                    put_ctrl.old_put += "/";
                    put_ctrl.new_put = "0";
                    put_ctrl.update_flag = 0;
                }
            }else{
                put_ctrl.old_put += put_ctrl.new_put;
                put_ctrl.old_put += "/";
                put_ctrl.new_put = "0";
                put_ctrl.update_flag = 0;
            }
        }else if(*p == ')') {
            put_ctrl.old_put += "/";
        }
    }
    ui->display->setText(put_ctrl.old_put);
}

void Calculator::push_button_equal()
{
    if(put_ctrl.old_put == "0"){
        push_button_AC();
        return;
    }
    else{
        QString::iterator p = put_ctrl.old_put.end()-1;
        if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '(' ){
            put_ctrl.old_put += put_ctrl.new_put;
            if(put_ctrl.brackets_cnt > 0){
                for(int i = 0 ; i < put_ctrl.brackets_cnt ; i++)
                    put_ctrl.old_put += ")";
            }
            put_ctrl.new_put = "0";
            put_ctrl.update_flag = 0;
        }else if(*p == ')') {
            if(put_ctrl.brackets_cnt > 0){
                for(int i = 0 ; i < put_ctrl.brackets_cnt ; i++)
                    put_ctrl.old_put += ")";
            }
            put_ctrl.new_put = "0";
            put_ctrl.update_flag = 0;
        }
    }
    calculate_result(put_ctrl.old_put);
    put_ctrl.old_put = "0";
    put_ctrl.brackets_cnt = 0;
    put_ctrl.update_flag = 0;
    put_ctrl.new_put = "0";
}

void Calculator::push_button_CE()
{
    put_ctrl.old_put = "0";
    ui->display->clear();
}

void Calculator::push_button_AC()
{
    put_ctrl.old_put = "0";
    put_ctrl.new_put = "0";
    put_ctrl.brackets_cnt = 0;
    put_ctrl.update_flag = 0;
    ui->display->clear();
    ui->put_data->setText(put_ctrl.new_put);
}

