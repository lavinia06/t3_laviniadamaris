//
// Created by ionel on 24.05.2023.
//



#include <iostream>
#include "GUI.h"
#include "QVBoxLayout"
using namespace std;
#include "QHBoxLayout"
extern int nr;


GUI::GUI(Service &service): service{service} {
    this->init_GUI();
    this->populateList(this->service.getSorted());
    this->connectSignalsAndSlots();
}


void GUI::init_GUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->nameLineEdit = new QLineEdit;
    this->quantityLineEdit = new QLineEdit;

    this->itemsListWidget = new QListWidget{};
    this->itemsListWidget->setFont(buttonsFont);
    this->searchListWidget = new QListWidget{};
    this->searchListWidget->setFont(buttonsFont);

    this->NewListWidget = new QListWidget{};
    this->NewListWidget->setFont(buttonsFont);

    this->restoreButton = new QPushButton("search by category or name");
    this->restoreButton->setFont(buttonsFont);

    this->searchButton = new QPushButton("Show items");
    this->searchButton->setFont(buttonsFont);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(this->itemsListWidget);

    mainLayout->addWidget(this->NewListWidget);
    mainLayout->addWidget(this->restoreButton);
    mainLayout->addWidget(this->nameLineEdit);
    mainLayout->addWidget(this->searchListWidget);
    mainLayout->addWidget(this->quantityLineEdit);
    mainLayout->addWidget(this->searchButton);
    setLayout(mainLayout);

}

GUI::~GUI() {

}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->restoreButton, &QPushButton::clicked, this, &GUI::displayAll);
    QObject::connect(this->searchButton, &QPushButton::clicked, this, &GUI::displayAll1);

}

void GUI::populateList(vector<Item> elements) {
    this->itemsListWidget->clear();
    for(auto & w: elements){
        this->itemsListWidget->addItem(QString::fromStdString(w.getCategory() + "-" + w.getName() + " | " + to_string(w.getQuantity())
        ));
    }
}


void GUI::populateList2(vector<Item> elements) {
    QString name = this->nameLineEdit->text();
    std::string nameStr = name.toStdString();
    this->NewListWidget->clear();
    for (auto& w : elements) {
        if (w.getCategory().find(nameStr) != std::string::npos || w.getName().find(nameStr) != std::string::npos) {
            this->NewListWidget->addItem(
                    QString::fromStdString(w.getCategory() + "-" + w.getName() + " | " + to_string(w.getQuantity())
                    ));
        }
    }
}


void GUI::displayAll() {
    QString name = this->nameLineEdit->text();
    this->populateList2(this->service.getAll());
    this->connectSignalsAndSlots();
}


void GUI::displayAll1() {
    QString name = this->nameLineEdit->text();
    int nameInt = name.toInt();
    this->populateList3(this->service.filterByQuantity());
    this->connectSignalsAndSlots();
}


void GUI::populateList3(vector<Item> elements) {
    QString name = this->quantityLineEdit->text();
    std::string nameStr = name.toStdString();
    this->searchListWidget->clear();
    for (auto &w: elements) {
        if (w.getCategory() == nameStr) {
            this->searchListWidget->addItem(
                    QString::fromStdString(w.getCategory() + "-" + w.getName() + " | " + to_string(w.getQuantity())
                    ));
        }
    }
}
