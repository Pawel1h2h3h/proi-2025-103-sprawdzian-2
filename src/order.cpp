#include <iostream>
#include <algorithm>
#include <chrono>
#include "dish.hpp"
#include "order.hpp"


Order::Order() {

}

Order::Order(int table_id_)
  : timestamp(std::chrono::system_clock::now()), table_id(table_id_)
{
}

void Order::addDish(Dish dish) {
    dishes.push_back(dish);
}

void Order::removeDish(Dish dish) {
    auto it = std::find(dishes.begin(), dishes.end(), dish);
    if (it != dishes.end()) {
        dishes.erase(it);
    }
}

const std::vector<Dish>& Order::getDishes() const {
    return dishes;
}

int Order::getTableNumber() const {
    return table_id;
}

std::chrono::system_clock::time_point Order::getTimestamp() const {
    return timestamp;
}

int Order::getTotalCost() {
    int total = 0;
    for (const auto& dish : dishes) {
        total += dish.getPrice();
    }
    return total;
}

bool Order::operator==(const Order& other) const {
    return table_id == other.table_id && timestamp == other.timestamp;
}

void Order::print() {
    for (const auto& dish : dishes) {
        std::cout << dish.getName() << " - " << dish.getPrice() << std::endl;
    }
}