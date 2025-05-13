#include <iostream>
#include <dish.hpp>

Dish::Dish()
  : name(""), type(DishType::Vegetarian), price(0)
{}


Dish::Dish(const std::string& name_, DishType type_, int price_)
  : name(name_), type(type_), price(price_)
{
}


std::string Dish::getName() const {
    return name;
}

DishType Dish::getType() const {
    return type;
}

int Dish::getPrice() const {
    return price;
}

void Dish::setType(DishType new_type) {
    type = new_type;
}

void Dish::setName(std::string new_name) {
    name = new_name;
}

void Dish::setPrice(int new_price) {
    price = new_price;
}

bool Dish::operator==(const Dish& other) const {
    return name == other.name && type == other.type && price == other.price;
}

void Dish::info() const {
    std::cout << name << " ("
              << (type == DishType::Meat    ? "Meat" :
                  type == DishType::Vegan   ? "Vegan" :
                  type == DishType::Vegetarian ? "Vegetarian" : "Unknown")
              << "): " << price << std::endl;
}