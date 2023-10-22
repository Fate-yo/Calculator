#include "jisuanqi.h"
#include <stack>

 

jisuanqi::jisuanqi(QWidget *parent): QMainWindow(parent){
    ui.setupUi(this);
    connect(ui.push0,&QPushButton::clicked, this, &jisuanqi::on_push0_click);
    connect(ui.push1, &QPushButton::clicked, this, &jisuanqi::on_push1_click);
    connect(ui.push2, &QPushButton::clicked, this, &jisuanqi::on_push2_click);
    connect(ui.push3, &QPushButton::clicked, this, &jisuanqi::on_push3_click);
    connect(ui.push4, &QPushButton::clicked, this, &jisuanqi::on_push4_click);
    connect(ui.push5, &QPushButton::clicked, this, &jisuanqi::on_push5_click);
    connect(ui.push6, &QPushButton::clicked, this, &jisuanqi::on_push6_click);
    connect(ui.push7, &QPushButton::clicked, this, &jisuanqi::on_push7_click);
    connect(ui.push8, &QPushButton::clicked, this, &jisuanqi::on_push8_click);
    connect(ui.push9, &QPushButton::clicked, this, &jisuanqi::on_push9_click);
    connect(ui.pushplus, &QPushButton::clicked, this, &jisuanqi::on_pushplus_click);
    connect(ui.pushchu, &QPushButton::clicked, this, &jisuanqi::on_pushchu_click);
    connect(ui.pushjian, &QPushButton::clicked, this, &jisuanqi::on_pushjian_click);
    connect(ui.pushx, &QPushButton::clicked, this, &jisuanqi::on_pushx_click);
    connect(ui.pushden, &QPushButton::clicked, this, &jisuanqi::on_pushden_click);
    connect(ui.pushmod, &QPushButton::clicked, this, &jisuanqi::on_pushmod_click);
    connect(ui.pushC, &QPushButton::clicked, this, &jisuanqi::on_pushC_click);
    connect(ui.pushpoint, &QPushButton::clicked, this, &jisuanqi::on_pushPoint_click);
}

jisuanqi::~jisuanqi()
{
  
}
void jisuanqi::on_push0_click() {
    s += '0';
    ui.display->setText(s);
}
void jisuanqi::on_push1_click() {
    s += '1';
    ui.display->setText(s);
}
void jisuanqi::on_push2_click() {
    s += '2';
    ui.display->setText(s);
}
void jisuanqi::on_push3_click() {
    s += '3';
    ui.display->setText(s);
}
void jisuanqi::on_push4_click() {
    s += '4';
    ui.display->setText(s);
}
void jisuanqi::on_push5_click() {
    s += '5';
    ui.display->setText(s);
}
void jisuanqi::on_push6_click() {
    s += '6';
    ui.display->setText(s);
}
void jisuanqi::on_push7_click() {
    s += '7';
    ui.display->setText(s);
}
void jisuanqi::on_push8_click() {
    s += '8';
    ui.display->setText(s);
}
void jisuanqi::on_push9_click() {
    s += '9';
    ui.display->setText(s);
}
void jisuanqi::on_pushplus_click() {
    s += '+';
    ui.display->setText(s);
}
void jisuanqi::on_pushjian_click() {
    s += '-';
    ui.display->setText(s);
}
void jisuanqi::on_pushx_click() {
    s += 'x';
    ui.display->setText(s);
}
void jisuanqi::on_pushchu_click() {
    s += '/';
    ui.display->setText(s);
}
void jisuanqi::on_pushmod_click() {
    s += '%';
    ui.display->setText(s);
}
void jisuanqi::on_pushC_click() {
    s = "";
    ui.display->setText("");
}
void jisuanqi::on_pushPoint_click() {
    s += ".";
    ui.display->setText(s);
}
void jisuanqi::on_pushden_click() {
   
     QString ans = jisuanqi::algori(s.toStdString()); 
     s = "";
     ui.display->setText(ans);
   
    
   
}
bool jisuanqi::isOperator(char c) {
    return (c == '+' || c == '-' || c == 'x' || c == '/' || c == '%');
}

double jisuanqi::performOperation(double operand1, double operand2, char op)
{
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case 'x':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '%':
        return fmod(operand1, operand2);
    default:
        return 0.0; // Return a default value for invalid operators
    }
}
QString jisuanqi::algori(std::string expression) {
    std::stack<double> operandStack;
    std::stack<char> operatorStack;
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (std::isspace(c)) {
            // Ignore spaces
            continue;
        }

        if (std::isdigit(c) || (c == '.' && !operandStack.empty()) || (c == '-' && (i == 0 || !std::isdigit(expression[i - 1])))) {
            // If the current character is a digit, decimal point, or negative sign
            std::string numStr;
            while (std::isdigit(c) || c == '.' || (c == '-' && numStr.empty())) {
                numStr += c;
                if (i < expression.length() - 1) {
                    c = expression[++i];
                }
                else {
                    break;
                }
            }
            double num = std::stod(numStr);
            operandStack.push(num);
        }

        if (isOperator(c)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) &&
                ((c != 'x' && c != '/') || (operatorStack.top() == 'x' || operatorStack.top() == '/'))) {
                char op = operatorStack.top();
                operatorStack.pop();
                if (operandStack.size() < 2) {
                    return "Invalid expression"; // Return an error message
                }
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();
                double result = performOperation(operand1, operand2, op);
                operandStack.push(result);
            }
            operatorStack.push(c);
        }
    }

    while (!operatorStack.empty()) {
        char op = operatorStack.top();
        operatorStack.pop();
        if (operandStack.size() < 2) {
            return "Invalid expression"; // Return an error message
        }
        double operand2 = operandStack.top();
        operandStack.pop();
        double operand1 = operandStack.top();
        operandStack.pop();
        double result = performOperation(operand1, operand2, op);
        operandStack.push(result);
    }

    if (operandStack.size() != 1 || !operatorStack.empty()) {
        return "Invalid expression"; // Return an error message
    }
    double finalResult = operandStack.top();
    std::string result = std::to_string(finalResult);
    while (result.size())if (result.back() == '0'||result.back()=='.') result.pop_back(); else break;
    return QString::fromStdString(result);
}