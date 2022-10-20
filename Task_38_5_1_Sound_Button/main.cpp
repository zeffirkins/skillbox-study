#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <iostream>

class ImageButton : public QPushButton {
    Q_OBJECT
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

    public slots:
    void setUp();
    void setDown();
    void play();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;

    QMediaPlayer *player = new QMediaPlayer();
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("C:/Button/ButtonUp.png");
    mButtonDownPixmap = QPixmap("C:/Button/ButtonDown.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());

    player->setMedia(QUrl::fromLocalFile("C:/Button/cli.mp3"));
    player->setVolume(100);

    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
    connect(this, &QPushButton::clicked, this, &ImageButton::play);
}

void ImageButton::play() {
    player->play();
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
    setDown();
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100,this,&ImageButton::setUp);
}

void ImageButton::setUp() {
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(100,100);
    redButton.move(1000,400);
    redButton.show();
    return app.exec();
}
#include "main.moc"
