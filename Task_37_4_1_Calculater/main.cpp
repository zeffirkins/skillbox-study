#include <QApplication>
#include "./ui_calculate.h"
#include "cmake-build-debug/calculateMainWindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculateMainWindow window(nullptr);
    Ui::MainWindow calculate;
    calculate.setupUi(&window);
    window.lineEditNum1 = calculate.lineEdit;
    window.lineEditNum2 = calculate.lineEdit_2;
    window.lineEditAnswer = calculate.lineEdit_3;

    window.resize(200, 100);
    window.show();
    return QApplication::exec();
}
