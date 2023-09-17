#include "slider.h"
#include <QHBoxLayout>
#include <QString>
#include <QPainter>
#include <QDebug>
#include <iostream>

Slider::Slider(QWidget *parent, QColor color)
    : QWidget(parent)
{
    m_color = color;

    QGridLayout *gbox = new QGridLayout(this);

    colorFiller = new QLabel (this);
    gbox->addWidget(colorFiller, 0, 0, 1, 2);

    colorCode = new QLabel(m_color.name(), this);
    colorCode->setFixedHeight(15);
    colorCode->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    gbox->addWidget(colorCode, 1, 0, 1, 2);

    hueSlider = new QSlider(Qt::Horizontal, this);
    hueSlider->setMaximum(100000);
    hueSlider->setMinimum(0);
    hueSlider->setValue(m_color.hslHueF()*100000);
    gbox->addWidget(hueSlider, 2, 0);

    hueLabel = new QLabel("Hue: " + QString::number(m_color.hueF()), this);
    hueLabel->setIndent(20);
    hueLabel->setMaximumHeight(15);
    hueLabel->setFixedWidth(150);
    gbox->addWidget(hueLabel, 2, 1);

    satSlider = new QSlider(Qt::Horizontal, this);
    satSlider->setMaximum(100);
    satSlider->setMinimum(0);
    satSlider->setValue(m_color.hslSaturationF()*100);
    gbox->addWidget(satSlider, 3, 0);

    satLabel = new QLabel("Saturation: " + SetPercent(satSlider->value()), this);
    satLabel->setFixedWidth(150);
    satLabel->setIndent(20);
    satLabel->setMaximumHeight(15);
    gbox->addWidget(satLabel, 3, 1);

    lightnessSlider = new QSlider(Qt::Horizontal, this);
    lightnessSlider->setMaximum(100);
    lightnessSlider->setMinimum(0);
    lightnessSlider->setValue(m_color.lightnessF()*100);
    gbox->addWidget(lightnessSlider, 4, 0);

    lightnessLabel = new QLabel("Lightness: " + SetPercent(lightnessSlider->value()), this);
    lightnessLabel->setFixedWidth(150);
    lightnessLabel->setMaximumHeight(15);
    lightnessLabel->setIndent(20);
    gbox->addWidget(lightnessLabel, 4, 1);

    connect(hueSlider, &QSlider::valueChanged, this, &Slider::ChangeHue);

    connect(satSlider, &QSlider::valueChanged, this, &Slider::ChangeSaturation);

    connect(lightnessSlider, &QSlider::valueChanged, this, &Slider::ChangeLightness);

}

Slider::~Slider()
{
    delete colorFiller;
    delete colorCode;
    delete hueLabel;
    delete satLabel;
    delete lightnessLabel;
    delete hueSlider;
    delete satSlider;
    delete lightnessSlider;
}

void Slider::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doPainting();
}

void Slider::doPainting()
{
    QPainter painter(this);

    painter.setPen(QColor(0xd4d4d4));
    painter.setBrush(QBrush(m_color));
    painter.drawRect((this->width()/2) - (colorFiller->width() / 2), 15, colorFiller->width(), colorFiller->height());

}

void Slider::ChangeHue()
{
    m_color.setHslF(hueSlider->value()/100000.0, m_color.hslSaturationF(), m_color.lightnessF());
    hueLabel->setText("Hue: " + QString::number(m_color.hueF()));
    ChangeColorName();
    this->update();
}

void Slider::ChangeSaturation()
{
    m_color.setHslF(m_color.hslHueF(), satSlider->value()/100.0, m_color.lightnessF());
    satLabel->setText("Stauration: " + SetPercent(satSlider->value()));
    ChangeColorName();
    this->update();
}

void Slider::ChangeLightness()
{
    m_color.setHslF(m_color.hslHueF(), m_color.hslSaturationF(), lightnessSlider->value()/100.0);
    lightnessLabel->setText("Lightness: " + SetPercent(lightnessSlider->value()));
    ChangeColorName();
    this->update();
}

void Slider::ChangeColorName()
{

    colorCode->setText(m_color.name());
}

QString Slider::SetPercent(int value)
{
    return QString::number(value) + "%";
}



