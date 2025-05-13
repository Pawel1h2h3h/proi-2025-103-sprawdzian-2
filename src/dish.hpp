#pragma once

#include <string>

enum class DishType { Vegan, Vegetarian, Meat };

class Dish {
    private:
        std::string name;
        DishType type;
        int price;
    public:
        Dish();
        Dish(const std::string& name_, DishType type_, int price_);

        std::string getName() const;
        DishType getType() const;
        int getPrice() const;

        void setType(DishType new_type);
        void setName(std::string new_name);
        void setPrice(int new_price);

        void info() const;

        bool operator==(const Dish& other) const;
};