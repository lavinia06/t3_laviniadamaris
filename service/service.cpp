
#include <algorithm>
#include "service.h"

Service::~Service() {

}

vector<Item> Service::getAll() {
    return this->repository.getAll();
}

Service::Service(Repository &repository):repository(repository) {

}

vector<Item> Service::filterByQuantity() {
    std::vector<Item> allEntities = this->repository.getAll();
    std::sort(allEntities.begin(), allEntities.end(), [this](const Item& a, const Item& b) {return a.getQuantity() < b.getQuantity(); });
    return allEntities;
}

//vector<Item> Service::getSorted() {
//    std::vector<Item> allEntities = this->repository.getAll();
//    std::sort(allEntities.begin(), allEntities.end(), [this](const Item& a, const Item& b) {return a.getCategory() < b.getCategory(); });
//    return allEntities;
//}

vector<Item> Service::getSorted() {
    vector<Item> allEntities = this->repository.getAll();
    sort(allEntities.begin(), allEntities.end(), [this](const Item& a, const Item& b) {
        if (a.getCategory() != b.getCategory()) {
            return a.getCategory() < b.getCategory();
        }
        return a.getName() < b.getName();
    });
    return allEntities;
}

