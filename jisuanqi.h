#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_jisuanqi.h"
#include<string>
class jisuanqi : public QMainWindow
{
    Q_OBJECT

public:
    
    jisuanqi(QWidget *parent = nullptr);
    
    ~jisuanqi();
    QString algori(std::string exp);
    bool isOperator(char c);
    double performOperation(double operand1, double operand2, char op);
private slots:
    void on_push0_click();
    void on_push1_click();
    void on_push2_click();
    void on_push3_click();
    void on_push4_click();
    void on_push5_click();
    void on_push6_click();
    void on_push7_click();
    void on_push8_click();
    void on_push9_click();
    void on_pushchu_click();
    void on_pushx_click();
    void on_pushmod_click();
    void on_pushplus_click();
    void on_pushden_click(); 
    void on_pushjian_click();
    void on_pushPoint_click();
    void on_pushC_click();

private:
    Ui::jisuanqiClass ui;
    QString s;
};
