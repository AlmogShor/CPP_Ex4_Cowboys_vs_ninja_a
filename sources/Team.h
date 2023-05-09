//
// Created by shora on 9/05/2023.
//

#pragma once

#pragma once

#include <iostream>
#include <cmath>
#include <string>

class Point {
public:
    Point(double x, double y);

    double distance(const Point &other) const;

    void print() const;

    Point moveTowards(const Point &source, const Point &target, double distance) const;

private:
    double x;
    double y;
};

class Character {
public:
    Character(const std::string &name, const Point &location, int hit_points);

    bool isAlive() const;

    double distance(const Character &other) const;

    void hit(int damage);

    std::string getName() const;

    Point getLocation() const;

    void print() const;

protected:
    std::string name;
    Point location;
    int hit_points;
};

class Cowboy : public Character {
public:
    Cowboy(const std::string &name, const Point &location);

    void shoot(Character *enemy);

    bool hasBullets() const;

    void reload();

private:
    int bullets;
};

class Ninja : public Character {
public:
    Ninja(const std::string &name, const Point &location, int speed, int hit_points);

    void move(const Character *enemy);

    void slash(Character *enemy) const;

protected:
    int speed;
};

class YoungNinja : public Ninja {
public:
    YoungNinja(const std::string &name, const Point &location);
};

class TrainedNinja : public Ninja {
public:
    TrainedNinja(const std::string &name, const Point &location);
};

class OldNinja : public Ninja {
public:
    OldNinja(const std::string &name, const Point &location);
};

class Team {
private:
    std::vector<Fighter *> fighters;
    Fighter *leader;

public:
    Team(Fighter *leader);

    ~Team();

    void add(Fighter *fighter);

    void attack(Team *enemy);

    bool stillAlive();

    void print();
};

class Team2 {
private:
    std::vector<Fighter *> fighters;
    Fighter *leader;

public:
    Team2(Fighter *leader);

    ~Team2();

    void add(Fighter *fighter);

    void attack(Team2 *enemy);

    bool stillAlive();

    void print();
};

class SmartTeam {
private:
    std::vector<Fighter *> fighters;
    Fighter *leader;

public:
    SmartTeam(Fighter *leader);

    ~SmartTeam();

    void add(Fighter *fighter);

    void attack(SmartTeam *enemy);

    bool stillAlive();

    void print();
};
