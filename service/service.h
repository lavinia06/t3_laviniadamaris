//
// Created by ionel on 24.05.2023.
//

#ifndef T3_LAVINIADAMARIS_SERVICE_H
#define T3_LAVINIADAMARIS_SERVICE_H
#include "../repo/repo.h"

class Service {

private:
    Repository& repository;

public:
    Service(Repository& repository);
    ~Service();
    vector<Item> getAll();
    vector<Item>filterByQuantity();
    vector<Item> getSorted();


};
#endif //T3_LAVINIADAMARIS_SERVICE_H
