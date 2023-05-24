//
// Created by ionel on 24.05.2023.
//

#ifndef T3_LAVINIADAMARIS_DOMAIN_H
#define T3_LAVINIADAMARIS_DOMAIN_H
using namespace std;
#include <string>
#include <vector>

class Item{
private:
    string category;
    string name;
    int quantity;
public:
    Item(const string &category, const string &name, int quantity);
    Item();
    static vector<string> tokenize(string str, char delimiter);

    friend istream& operator>>(istream& input, Item& item);

    const string &getCategory() const;

    void setCategory(const string &category);

    const string &getName() const;

    void setName(const string &name);

    int getQuantity() const;

    void setQuantity(int quantity);
};
#endif //T3_LAVINIADAMARIS_DOMAIN_H
