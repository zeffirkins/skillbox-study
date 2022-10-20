#include "mainwindow.h"
#include <QApplication>
#include <QtGui/QtGui>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QFileDialog>

QImage blurImage(QImage source, int blurRadius) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter,QRectF(), QRectF(0, 0, source.width(), source.height()));

    return result;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    auto *oldLabel = new QLabel;
    auto *newLabel = new QLabel;
    auto *slider = new QSlider(Qt::Horizontal);
    auto *openFileButton = new QPushButton("Open");
    auto *vbox = new QVBoxLayout(window);

    vbox->addWidget (oldLabel, 1);
    vbox->addWidget (newLabel, 1);
    vbox->addWidget (slider, 1);
    vbox->addWidget (openFileButton, 1);

    slider->setMinimum(0);
    slider->setMaximum(10);

    QString filePatch;

    QObject::connect(openFileButton, &QPushButton::clicked, [&filePatch, &oldLabel]() {
        filePatch = QFileDialog::getOpenFileName(nullptr, "Open jpg picture", "C:/", "*.jpg");
        oldLabel->setPixmap(filePatch);
    });

    //QImage sourceImage(filePatch);

    QObject::connect(slider, &QSlider::valueChanged, [newLabel, &filePatch] (int newValue) {
        auto blured = blurImage(QImage(filePatch), newValue);
        newLabel->setPixmap(QPixmap::fromImage(blured).scaled(newLabel->size(), Qt::KeepAspectRatio));
    });

    window->setFixedSize(1280, 900);
    window->show();
    return app.exec();
}
#include "main.moc"
