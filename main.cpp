#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "src/table.hpp"
#include "src/order.hpp"
#include "src/dish.hpp"


int main() {
    Dish dish1("Steak", Dish::Type::Meat, 25);
    Dish dish2("Salad", Dish::Type::Vegetarian, 10);
    Dish dish3("Vegan Burger", Dish::Type::Vegan, 15);
    Dish dish4("Chicken Soup", Dish::Type::Meat, 12);

    Order order1(1);
    order1.addDish(dish1);
    order1.addDish(dish2);

    Order order2(2);
    order2.addDish(dish3);
    order2.addDish(dish4);

    Table table;
    table.addOrder(order1);
    table.addOrder(order2);

    // Modify orders: replace dish2 with dish3 in order1
    table.modifyOrders(order1, dish2, dish3);

    // Print orders sorted by time
    std::cout << "Orders sorted by time:" << std::endl;
    table.printOrders(0);

    // Print orders sorted by number of dishes
    std::cout << "Orders sorted by number of dishes:" << std::endl;
    table.printOrders(1);

    // Print total costs separated by dish types
    std::cout << "Total costs:" << std::endl;
    table.printTotalCosts();

    return 0;
}
