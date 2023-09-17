#pragma once
#include <QWidget>
#include <QSlider>
#include <QLabel>

class Slider : public QWidget
{
    Q_OBJECT
public:
    Slider(QWidget *parent = nullptr, QColor color = 0xc00000);
    ~Slider();

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void ChangeHue();
    void ChangeSaturation();
    void ChangeLightness();

private:
    QLabel *colorFiller;
    QLabel *colorCode;
    QLabel *hueLabel;
    QLabel *satLabel;
    QLabel *lightnessLabel;
    QSlider *hueSlider;
    QSlider *satSlider;
    QSlider *lightnessSlider;
    QColor m_color;
    void ChangeColorName();
    QString SetPercent(int value);
    void doPainting();

};
