#pragma once
#include <iostream>
#include "dish.hpp"
#include <chrono>



class Order {
    private:

        std::vector<Dish> dishes;
        int table_id;
        std::chrono::system_clock::time_point timestamp;

    public:
        Order();
        Order(int table_id);
        void addDish(Dish dish);
        void removeDish(Dish dish);
        void print();

        const std::vector<Dish>& getDishes() const;
        int getTableNumber() const;
        std::chrono::system_clock::time_point getTimestamp() const;
        int getTotalCost();
        bool operator==(const Order& other) const;
};
