//
// Created by ionel on 24.05.2023.
//

#include <string>
#include "domain.h"
#include <sstream>

Item::Item(const string &category, const string &name, int quantity)
        : category(category), name(name), quantity(quantity) {}

Item::Item() {

}

const string &Item::getCategory() const {
    return category;
}

void Item::setCategory(const string &category) {
    Item::category = category;
}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int quantity) {
    Item::quantity = quantity;
}

vector<string> Item::tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

istream &operator>>(istream &input, Item &item) {
    string line;
    getline(input, line);
    vector<string> tokens = Item::tokenize(line, '|');
    if(tokens.size() != 3)
        return input;
    item.category = tokens[0];
    item.name = tokens[1];
    item.quantity = stoi(tokens[2]);

    return input;
}
