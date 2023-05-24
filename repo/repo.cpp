//
// Created by ionel on 24.05.2023.
//

//
// Created by ionel on 24.05.2023.
//


#include <fstream>
#include "repo.h"

Repository::Repository() {
    this->LoadData();
}

Repository::~Repository() {

}

vector<Item> Repository::getAll() {
    return this->elements;
}

void Repository::LoadData() {
    ifstream inFile(R"(C:\Users\ionel\CLionProjects\t3-laviniadamaris\input.txt)");
    Item CurrentElement;
    this->elements.clear();
    while (inFile >> CurrentElement)
    {
        this->elements.push_back(CurrentElement);
    }
    inFile.close();
}

