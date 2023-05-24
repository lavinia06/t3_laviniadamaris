#include <iostream>
#include "repo/repo.h"
#include "service/service.h"
#include "GUI/GUI.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    Repository repository;
    Service service(repository);
    GUI gui(service);

    gui.show();

    return a.exec();
}