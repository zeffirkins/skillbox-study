#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>
#include <iostream>


class ColorfulCircle: public QWidget {
Q_OBJECT
public:
    ColorfulCircle() = default;
    ColorfulCircle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void setGreen();
    void setYellow();
    void setRed();

private:
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
};

ColorfulCircle::ColorfulCircle(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mGreenCircle = QPixmap("C:\\Users\\Iurii\\CLionProjects\\Task_36_4_Circle_and_slider\\green_button.png");
    mYellowCircle = QPixmap("C:\\Users\\Iurii\\CLionProjects\\Task_36_4_Circle_and_slider\\yellow_button.png");
    mRedCircle = QPixmap("C:\\Users\\Iurii\\CLionProjects\\Task_36_4_Circle_and_slider\\red_button.png");
    mCurrentCircle = mGreenCircle;

    setGeometry(mCurrentCircle.rect());
}

void ColorfulCircle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(),  mCurrentCircle);
}



QSize ColorfulCircle::sizeHint() const {
    return QSize(100, 100);
}

QSize ColorfulCircle::minimumSizeHint() const {
    return QSize(100, 100);
}

void ColorfulCircle::setGreen() {
    mCurrentCircle = mGreenCircle;
    update();
}

void ColorfulCircle::setYellow() {
    mCurrentCircle = mYellowCircle;
    update();
}

void ColorfulCircle::setRed() {
    mCurrentCircle = mRedCircle;
    update();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget *window = new QWidget;
    window -> setFixedSize(200, 250);
    window -> move (1000, 500);

    ColorfulCircle *circle = new ColorfulCircle(window);

    auto *slider = new QSlider(Qt::Horizontal, window);
    slider -> setMinimum(0);
    slider -> setMaximum(100);

    auto *layout = new QVBoxLayout(window);
    layout -> addWidget(circle);
    layout -> addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, circle,[slider, circle](int newValue) {
        if (newValue >= 0 && newValue <= 33) {
            circle->setGreen();
        }else if (newValue >= 34 && newValue <= 66) {
            circle->setYellow();
        }else if (newValue >= 67 && newValue <= 100) {
            circle->setRed();
        }
    });

    window -> show();
    return app.exec();
}
#include <main.moc>