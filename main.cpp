#include <QtGlobal>
#if QT_VERSION < 0x050000
#include <QtGui>
#else
#include <QtWidgets>
#endif

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QPushButton quitButton("Quit");
    QLineEdit textline1;
    QLineEdit textline2;


    QObject::connect(&textline1,SIGNAL(textChanged(QString)),&textline2,SLOT(setText(QString)));
    QObject::connect(&textline2,SIGNAL(textChanged(QString)),&textline1,SLOT(setText(QString)));
    QObject::connect(&quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout layout;
    layout.addWidget(&textline1);
    layout.addWidget(&textline2);
    layout.addWidget(&quitButton);

    QWidget window;
    window.setLayout(&layout);

    window.show();

    /*QWidget *widget = new QWidget;

    widget->show();*/

    return app.exec();
}
