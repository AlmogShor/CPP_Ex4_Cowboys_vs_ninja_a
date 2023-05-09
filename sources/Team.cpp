//
// Created by shora on 9/05/2023.
//

#include "Team.hpp"

// Cowboy_vs_Ninja.cpp
#include "Cowboy_vs_Ninja.h"

// Point class implementation
Point::Point(double x, double y) : x(x), y(y) {}

double Point::distance(const Point &other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

void Point::print() const {
    std::cout << "(" << x << ", " << y << ")";
}

Point Point::moveTowards(const Point &source, const Point &target, double distance) const {
    double total_distance = source.distance(target);
    if (total_distance <= distance) {
        return target;
    }

    double ratio = distance / total_distance;
    double new_x = source.x + ratio * (target.x - source.x);
    double new_y = source.y + ratio * (target.y - source.y);

    return Point(new_x, new_y);
}

// Character class implementation
Character::Character(const std::string &name, const Point &location, int hit_points)
        : name(name), location(location), hit_points(hit_points) {}

bool Character::isAlive() const {
    return hit_points > 0;
}

double Character::distance(const Character &other) const {
    return location.distance(other.location);
}

void Character::hit(int damage) {
    hit_points -= damage;
}

std::string Character::getName() const {
    return name;
}

Point Character::getLocation() const {
    return location;
}

void Character::print() const {
    std::cout << name << " at ";
    location.print();
    std::cout << " with " << hit_points << " HP";
}

// Cowboy class implementation
Cowboy::Cowboy(const std::string &name, const Point &location)
        : Character(name, location, 110), bullets(6) {}

void Cowboy::shoot(Character *enemy) {
    if (!isAlive() || !hasBullets()) {
        return;
    }

    enemy->hit(10);
    bullets--;
}

bool Cowboy::hasBullets() const {
    return bullets > 0;
}

void Cowboy::reload() {
    bullets = 6;
}

// Ninja class implementation
Ninja::Ninja(const std::string &name, const Point &location, int speed, int hit_points)
        : Character(name, location, hit_points), speed(speed) {}

void Ninja::move(const Character *enemy) {
    Point new_location = location.moveTowards(location, enemy->getLocation(), speed);
    location = new_location;
}

void Ninja::slash(Character *enemy) const {
    if (!isAlive() || distance(*enemy) >= 1.0) {
        return;
    }

    enemy->hit(30);
}

// YoungNinja class implementation
YoungNinja::YoungNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 14, 100) {}

// TrainedNinja class implementation
TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 12, 120) {}

// OldNinja class implementation
OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name, location, 8, 150) {}

