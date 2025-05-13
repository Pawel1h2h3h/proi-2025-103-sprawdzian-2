#pragma once

#include <vector>
#include "order.hpp"
#include "dish.hpp"

class Table {
private:
    std::vector<Order> orders;
public:
    void addOrder(const Order& order);
    void removeOrder(const Order& order);
    void modifyOrders(const Order& to_modify, const Dish& to_add, const Dish& to_remove);
    void printOrders(int time_or_number);
    void printTotalCosts();
};