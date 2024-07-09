#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , currentValue(0) //Initialize
    , memoryValue(0)
    , wait(false)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::continueinput(const QString &Value) {//Functions to handle numeric button presses
    if (ui->display->text() == "0" && Value == "0") {  //Ignore successive presses of 0 in the initial state
        return;
    }

    if (wait) {  //If waiting for the next number, clear the display box
        ui->display->clear();
        wait = false;
    }

    ui->display->setText(ui->display->text() + Value);  //Displays the number to continue entering
}
void Widget::digital0() { continueinput("0"); }  //Functions to handle numbers after they have been pressed
void Widget::digital1() { continueinput("1"); }
void Widget::digital2() { continueinput("2"); }
void Widget::digital3() { continueinput("3"); }
void Widget::digital4() { continueinput("4"); }
void Widget::digital5() { continueinput("5"); }
void Widget::digital6() { continueinput("6"); }
void Widget::digital7() { continueinput("7"); }
void Widget::digital8() { continueinput("8"); }
void Widget::digital9() { continueinput("9"); }
void Widget::dot() { continueinput("."); }




void Widget::cal(const QString &operation) {
    if (!nextopr.isEmpty()) {  //If there are operators to be processed, do them first
        if (!calculate(currentValue, nextopr)) {
            clear();
            return;
        }
        ui->display->setText(QString::number(currentValue));
    } else { //Otherwise set the current value to the value in the display box
        currentValue = ui->display->text().toDouble();
    }

   nextopr = operation;  //Waiting for the next data
    wait = true;
}

void Widget::equals() { //calculate
    double ochar = ui->display->text().toDouble();

    if (!calculate(ochar, nextopr)) {
        clear();
        return;
    }

    ui->display->setText(QString::number(currentValue));  //update display
    nextopr.clear();
    wait = false;
}

void Widget::clear() { //reset
    currentValue = 0;
    memoryValue = 0;
    nextopr.clear();
    ui->display->clear();
}

bool Widget::calculate(double rightchar, const QString &nextchar) {  //Execute the corresponding operation according to the operation symbol
    if (nextchar == "+") {
        currentValue += rightchar;
    } else if (nextchar == "-") {
        currentValue -= rightchar;
    } else if (nextchar == "*") {
        currentValue *= rightchar;
    } else if (nextchar == "/") {
        if (rightchar == 0.0)
            return false;
        currentValue /= rightchar;
    }

    return true;
}


void Widget::nag() {  //Take the opposite number, or enter a negative number
    QString text = ui->display->text();
    if (text.startsWith("-")) {
        text.remove(0, 1);  // remove"-"
    } else {
        text.prepend("-");  // add"-"
    }
    ui->display->setText(text);
}

void Widget::back() { //backspace
    QString text = ui->display->text();
    text.chop(1);  // remove the last char
    if (text.isEmpty()) {
        text = "0";  // if no char left, get 0
    }
    ui->display->setText(text);
}

void Widget::on_button0_clicked()
{
    digital0();
}
void Widget::on_button1_clicked()
{
    digital1();
}
void Widget::on_button2_clicked()
{
    digital2();
}
void Widget::on_button3_clicked()
{
    digital3();
}
void Widget::on_button4_clicked()
{
    digital4();
}
void Widget::on_button5_clicked()
{
    digital5();
}
void Widget::on_button6_clicked()
{
    digital6();
}
void Widget::on_button7_clicked()
{
    digital7();
}
void Widget::on_button8_clicked()
{
    digital8();
}
void Widget::on_button9_clicked()
{
    digital9();
}







void Widget::on_buttonDivide_clicked()
{
    cal("/");
}


void Widget::on_buttonMutiply_clicked()
{
   cal("*");
}


void Widget::on_buttonMinus_clicked()
{
  cal("-");
}


void Widget::on_buttonPlus_clicked()
{
   cal("+");
}


void Widget::on_buttonClear_clicked()
{
    clear();
}


void Widget::on_buttonEquals_clicked()
{
    equals();
}


void Widget::on_buttonDot_clicked()
{
    dot();
}


void Widget::on_nag_clicked()
{
    nag();
}


void Widget::on_back_clicked()
{
    back();
}

