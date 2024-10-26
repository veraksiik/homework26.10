#include <iostream>
#include <string>
#include <Windows.h>

class Plant {
public:
    virtual ~Plant() {} // Базовый деструктор объявлен виртуальным
    virtual std::string getFruitType() const = 0;
    virtual std::string getName() const = 0;
};

class Fruit {
public:
    virtual ~Fruit() {} // Базовый деструктор объявлен виртуальным
    virtual std::string getType() const = 0;
};

// Классы наследники растений:
class Shrub : public Plant {
public:
    virtual std::string getName() const override { return "Куст"; }
};

class Tree : public Plant {
public:
    virtual std::string getName() const override { return "Дерево"; }
};

// Классы наследники фруктов:
class Apple : public Fruit {
public:
    virtual std::string getType() const override { return "Яблоко"; }
};

class Pear : public Fruit {
public:
    virtual std::string getType() const override { return "Груша"; }
};

class Blueberry : public Fruit {
public:
    virtual std::string getType() const override { return "Черника"; }
};

class Raspberry : public Fruit {
public:
    virtual std::string getType() const override { return "Малина"; }
};

// Наследники растений с плодами
class AppleTree : public Tree {
public:
    std::string getFruitType() const override { return "Яблоко"; }
};

class PearTree : public Tree {
public:
    std::string getFruitType() const override { return "Груша"; }
};

class BlueberryShrub : public Shrub {
public:
    std::string getFruitType() const override { return "Черника"; }
};

class RaspberryShrub : public Shrub {
public:
    std::string getFruitType() const override { return "Малина"; }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Plant* plants[] = {
        new AppleTree, new PearTree, new BlueberryShrub, new RaspberryShrub
    };

    for (auto plant : plants) {
        std::cout << "Растение: " << plant->getName() << ", Плод: " << plant->getFruitType() << std::endl;
        delete plant;
    }

    system("pause");
    return 0;
}
