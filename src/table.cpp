#include <iostream>
#include <table.hpp>
#include <algorithm>

void Table::addOrder(const Order& order) {
    orders.push_back(order);
}

void Table::removeOrder(const Order& order) {
    auto it = std::find(orders.begin(), orders.end(), order);
    if (it != orders.end()) {
        orders.erase(it);
    }
}

void Table::printOrders(int time_or_number) {
    if (time_or_number == 0) {
        std::sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.getTimestamp() < b.getTimestamp();
        });
    } else if (time_or_number == 1) {
        std::sort(orders.begin(), orders.end(), [](const Order& a, const Order& b) {
            return a.getDishes().size() < b.getDishes().size();
        });
    }
    for(size_t i = 0; i < orders.size(); i++) {
        orders[i].print();
    }
}

void Table::modifyOrders(const Order& to_modify, const Dish& to_add, const Dish& to_remove) {
    for (Order& order : orders) {
        if (order == to_modify) {
            order.removeDish(to_remove);
            order.addDish(to_add);
        }
    }
}

void Table::printTotalCosts() {
    int meatCost = 0;
    int nonMeatCost = 0;
    for (const Order& order : orders) {
        for (const Dish& dish : order.getDishes()) {
            if (dish.getType() == DishType::Meat) {
                meatCost += dish.getPrice();
            } else {
                nonMeatCost += dish.getPrice();
            }
        }
    }
    std::cout << "Total meat dishes cost: " << meatCost << std::endl;
    std::cout << "Total vegetarian and vegan dishes cost: " << nonMeatCost << std::endl;
}