#include <QApplication> // Most important lib in QT
#include <iostream>
#include <QLabel>

int main(int argc, char* argv[]){
    // Create application object
    QApplication app(argc, argv);

    QLabel *label = new QLabel("Hello World");
    label->setWindowTitle("This is a title");
    label->resize(400, 400);
    std::cout << "Hello world" << std::endl;

    label->show();
    return app.exec();
}
