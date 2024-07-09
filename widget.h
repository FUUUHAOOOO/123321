#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:




    void on_button0_clicked();     //Numeric Button Slot Functions
    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_button4_clicked();
    void on_button5_clicked();
    void on_button6_clicked();
    void on_button7_clicked();
    void on_button8_clicked();
    void on_button9_clicked();

    void on_buttonDivide_clicked(); //Operational Button Slot Functions

    void on_buttonMutiply_clicked();

    void on_buttonMinus_clicked();

    void on_buttonPlus_clicked();


    void on_buttonClear_clicked();  //Function Button Slot Functions

    void on_buttonEquals_clicked();

    void on_buttonDot_clicked();

    void on_nag_clicked();

    void on_back_clicked();


private:
    Ui::Widget *ui;
    double currentValue;
    double memoryValue;
    QString nextopr;
    bool wait;
    bool calculate(double rightchar,const QString &nextchar);
    void continueinput(const QString &Value);
    void cal(const QString &ochar1);

    void nag();
    void equals();
    void clear();
    void back();

    void digital0();      // Input function
    void digital1() ;
    void digital2() ;
    void digital3() ;
    void digital4() ;
    void digital5() ;
    void digital6() ;
    void digital7() ;
    void digital8() ;
    void digital9() ;
    void dot() ;


};
#endif // WIDGET_H
