#include "mainwindow.h"
#include <QtWebEngineWidgets/QWebEngineView>
#include <QApplication>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *htmlEdit = new QPlainTextEdit;
    auto *webView = new QWebEngineView;
    auto *hbox = new QHBoxLayout(window);

    hbox->addWidget(htmlEdit, 1);
    hbox->addWidget(webView, 1);

    QObject::connect(htmlEdit, &QPlainTextEdit::textChanged, [webView, htmlEdit] () {
        auto htmlToEdit = htmlEdit->toPlainText();
        webView->setHtml(htmlToEdit);
    });

    window->setFixedSize(1280,720);
    window->show();
    return app.exec();
}
#include "main.moc"
