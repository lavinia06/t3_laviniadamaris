//
// Created by ionel on 24.05.2023.
//

#ifndef T3_LAVINIADAMARIS_REPO_H
#define T3_LAVINIADAMARIS_REPO_H
#include "../domain/domain.h"
#include <string>
#include <vector>
using namespace std;

class Repository {

private:
    vector<Item> elements;
    void LoadData();

public:
    Repository();
    ~Repository();
    vector<Item> getAll();

};
#endif //T3_LAVINIADAMARIS_REPO_H
