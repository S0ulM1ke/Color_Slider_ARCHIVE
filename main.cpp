#include <QApplication>
#include "slider.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Slider window(nullptr, 0xc56c00); //Set your own color here

    window.setWindowTitle("HSL colours slider");
    window.resize(640, 480);
    window.show();


    return app.exec();
}
