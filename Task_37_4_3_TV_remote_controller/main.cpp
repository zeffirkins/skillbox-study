#include <QApplication>
#include "remote_controller.h"
#include "./ui_TV_remote.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    remote_controller window(nullptr);
    Ui::MainWindow TV_remote;
    TV_remote.setupUi(&window);
    window.progressBar = TV_remote.progressBar;
    window.lcdNumber = TV_remote.lcdNumber;
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
