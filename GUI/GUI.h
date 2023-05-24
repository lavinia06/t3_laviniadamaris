//
// Created by ionel on 24.05.2023.
//

#ifndef T3_LAVINIADAMARIS_GUI_H
#define T3_LAVINIADAMARIS_GUI_H
#include "QWidget"
#include "QLineEdit"
#include "QListWidget"
#include "QPushButton"
#include "QLabel"
#include "../service/service.h"
#include "QCheckBox"
#include "QSlider"
#include "QSpinBox"

class GUI: public QWidget {

private:
    Service& service;
    QListWidget* itemsListWidget;
    QListWidget* NewListWidget;
    QListWidget* searchListWidget;
    QPushButton* restoreButton;
    QLineEdit* nameLineEdit;
    QLineEdit* quantityLineEdit;
    void connectSignalsAndSlots();
    QPushButton* searchButton;
    void displayAll();
    void displayAll1();
public:
    GUI(Service& service);
    ~GUI();
    void populateList(vector<Item> elements);
    void populateList2(vector<Item> elements);
    void populateList3(vector<Item> elements);
    void init_GUI();

};

#endif //T3_LAVINIADAMARIS_GUI_H
