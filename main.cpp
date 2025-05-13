#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "src/table.hpp"
#include "src/order.hpp"
#include "src/dish.hpp"

int main() {
    Table table;

    // Sample dishes
    Dish dish1("Steak",    DishType::Meat,       25);
    Dish dish2("Salad",    DishType::Vegetarian, 10);
    Dish dish3("Vegan Burger", DishType::Vegan,  15);
    Dish dish4("Chicken Soup", DishType::Meat,    12);

    // Create orders
    Order order1(1);
    order1.addDish(dish1);
    order1.addDish(dish2);

    Order order2(2);
    order2.addDish(dish3);
    order2.addDish(dish4);

    // Add orders to table
    table.addOrder(order1);
    table.addOrder(order2);

    // Print initial orders
    std::cout << "Initial orders sorted by time:\n";
    table.printOrders(0);

    std::cout << "\nInitial orders sorted by number of dishes:\n";
    table.printOrders(1);

    // Modify order1: replace Salad with Vegan Burger
    std::cout << "\nModify order1 (table 1): replace Salad with Vegan Burger\n";
    table.modifyOrders(order1, dish2, dish3);
    table.printOrders(0);

    // Print total costs
    std::cout << "\nTotal costs:\n";
    table.printTotalCosts();

    // Remove order1
    std::cout << "\nRemove order1 (table 1)\n";
    table.removeOrder(order1);
    table.printOrders(0);

    return 0;
}
