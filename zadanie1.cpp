#include <iostream>
#include <vector>
#include <string>

enum DeviceType {
    SmartphoneType = 1,
    LaptopType
};

struct Smartphone {
    std::string manufacturer;
    int memory;
    double price;
};

struct Laptop {
    std::string manufacturer;
    std::string cpuModel;
    bool hasGamingGPU;
};

void inputSmartphone(Smartphone* phone) {
    std::cout << "Введите фирму-производителя: ";
    std::cin >> phone->manufacturer;
    std::cout << "Введите объем встроенной памяти (ГБ): ";
    std::cin >> phone->memory;
    std::cout << "Введите цену: ";
    std::cin >> phone->price;
}

void outputSmartphone(const Smartphone& phone) {
    std::cout << "Смартфон " << phone.manufacturer << ", Память: " << phone.memory
        << "ГБ, Цена: " << phone.price << " руб." << std::endl;
}

void inputLaptop(Laptop* laptop) {
    std::cout << "Введите фирму-производителя: ";
    std::cin >> laptop->manufacturer;
    std::cout << "Введите модель процессора: ";
    std::cin >> laptop->cpuModel;
    std::cout << "Есть ли игровая видеокарта? (1 - Да, 0 - Нет): ";
    std::cin >> laptop->hasGamingGPU;
}

void outputLaptop(const Laptop& laptop) {
    std::cout << "Ноутбук " << laptop.manufacturer << ", Процессор: " << laptop.cpuModel
        << ", Игровая видеокарта: " << (laptop.hasGamingGPU ? "Да" : "Нет") << std::endl;
}

void createDevice(std::vector<Smartphone& phones, std::vector<Laptop>& laptops)
    int deviceType;
std::cout << "Выберите тип устройства (1 - Смартфон, 2 - Ноутбук): ";
std::cin >> deviceType;

if (deviceType == 1) {
    Smartphone phone;
    inputSmartphone(&phone);
    smartphones.push_back(phone);
}
else if (deviceType == 2) {
    Laptop laptop;
    inputLaptop(&laptop);
    laptops.push_back(laptop);
}
else {
    std::cout << "Неверный выбор устройства." << std::endl;
}

int main() {
    std::vector<Smartphone> smartphones;
    std::vector<Laptop> laptops;
    int choice;

    do {
        std::cout << "1. Ввод смартфона\n2. Ввод ноутбука\n3. Вывод смартфонов\n4. Вывод ноутбуков\n0. Выход\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: createSmartphones(smartphones); break;
        case 2: createLaptops(laptops); break;
        case 3: for (const auto& phone : smartphones) outputSmartphone(phone); break;
        case 4: for (const auto& laptop : laptops) outputLaptop(laptop); break;
        }
    } while (choice != 0);

    return 0;
}

