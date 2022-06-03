//
// Created by Iurii on 25.05.2022.
//

#ifndef TASK_37_4_1_CALCULATER_CALCULATEMAINWINDOW_H
#define TASK_37_4_1_CALCULATER_CALCULATEMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CalculateMainWindow : public QMainWindow {
    Q_OBJECT

public:
    float number1 = 0, number2 = 0, answer;
    QString num1, num2, ans;
    QLineEdit* lineEditNum1 = nullptr;
    QLineEdit* lineEditNum2 = nullptr;
    QLineEdit* lineEditAnswer = nullptr;

    CalculateMainWindow(QWidget* parent = nullptr) : QMainWindow(parent) {}

public slots:

    void addiction() {
        num1 = lineEditNum1->text();
        num2 = lineEditNum2->text();
        number1 = num1.toFloat();
        number2 = num2.toFloat();
        answer = number1 + number2;
        ans = QString::number(answer);
        lineEditAnswer->setText(ans);
    };

    void subtraction() {
        num1 = lineEditNum1->text();
        num2 = lineEditNum2->text();
        number1 = num1.toFloat();
        number2 = num2.toFloat();
        answer = number1 - number2;
        ans = QString::number(answer);
        lineEditAnswer->setText(ans);
    };

    void multiplication() {
        num1 = lineEditNum1->text();
        num2 = lineEditNum2->text();
        number1 = num1.toFloat();
        number2 = num2.toFloat();
        answer = number1 * number2;
        ans = QString::number(answer);
        lineEditAnswer->setText(ans);
    };

    void division() {
        num1 = lineEditNum1->text();
        num2 = lineEditNum2->text();
        number1 = num1.toFloat();
        number2 = num2.toFloat();
        if (number2 == 0) {
            lineEditAnswer->setText("Error!");
        }else {
            answer = number1 / number2;
            QString ans = QString::number(answer);
            lineEditAnswer->setText(ans);
        }
    };
};

#endif //TASK_37_4_1_CALCULATER_CALCULATEMAINWINDOW_H
