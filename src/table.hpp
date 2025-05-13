#include <iostream>
#include "order.hpp"
#include <ctime>
#pragma once


class Table {
    private:
        std::vector<Order> orders;
    public:
        void addOrder(Order);
        void removeOrder(Order);
        void modifyOrders(const Order& to_modify, const Dish& to_add, const Dish& to_remove);

        void printOrders(int time_or_number);
        void printTotalCosts();
        void modifyOrders(Order to_modify, Dish to_add, Dish to_remove);
        void printTotalCosts();
        #include <iostream>
};