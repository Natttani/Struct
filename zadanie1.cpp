#include <iostream>
#include <vector>
#include <string>

enum DeviceType {
    SmartphoneType = 1,
    LaptopType,
    ElectronicBookType,
    MonitorType
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

struct ElectronicBook {
    std::string manufacturer;
    int screenSize;
    bool screenBacklight;
};

struct Monitor {
    std::string manufacturer;
    int screenSize;
    double price;
};

void inputSmartphone(Smartphone* phone) { //ввод смартфона
    std::cout << "Введите фирму-производителя: ";
    std::cin >> phone->manufacturer;
    std::cout << "Введите объем встроенной памяти (ГБ): ";
    std::cin >> phone->memory;
    std::cout << "Введите цену: ";
    std::cin >> phone->price;
}

void outputSmartphone(const Smartphone& phone) { //вывод смартфонов
    std::cout << "Смартфон " << phone.manufacturer << ", Память: " << phone.memory
        << "ГБ, Цена: " << phone.price << " руб." << std::endl;
}

void inputLaptop(Laptop* laptop) { //ввод ноутбуков
    std::cout << "Введите фирму-производителя: ";
    std::cin >> laptop->manufacturer;
    std::cout << "Введите модель процессора: ";
    std::cin >> laptop->cpuModel;
    std::cout << "Есть ли игровая видеокарта? (1 - Да, 0 - Нет): ";
    std::cin >> laptop->hasGamingGPU;
}

void outputLaptop(const Laptop& laptop) { //вывод ноутбуков
    std::cout << "Ноутбук " << laptop.manufacturer << ", Процессор: " << laptop.cpuModel
        << ", Игровая видеокарта: " << (laptop.hasGamingGPU ? "Да" : "Нет") << std::endl;
}

void inputElectronicBook(ElectronicBook* electronicBook) { //ввод электронной книги
    std::cout << "Введите фирму-производителя: ";
    std::cin >> electronicBook->manufacturer;
    std::cout << "Введите размер экрана : ";
    std::cin >> electronicBook->screenSize;
    std::cout << "Есть ли подсветка экрана? (1 - Да, 0 - Нет): ";
    std::cin >> electronicBook->screenBacklight;
}

void outputElectronicBook(const ElectronicBook& electronicBook) { //вывод электронной книги
    std::cout << "Электронная книга " << electronicBook.manufacturer << ", Размер экрана: " << electronicBook.screenSize << "Наличие подсветки экрана: " << electronicBook.screenBacklight << std::endl;
}

void inputMonitor(Monitor* monitor) { //ввод монитора
    std::cout << "Введите фирму-производителя: ";
    std::cin >> monitor->manufacturer;
    std::cout << "Введите размер экрана: ";
    std::cin >> monitor->screenSize;
    std::cout << "Введите цену: ";
    std::cin >> monitor->price;
}

void outputMonitor(const Monitor& monitor) { //вывод монитора
    std::cout << "Монитор " << monitor.manufacturer << ", Размер экрана: " << monitor.screenSize
        << "Цена: " << monitor.price << " руб." << std::endl;
}

void createDevice(std::vector<Smartphone>& smartphones, std::vector<Laptop>& laptops, std::vector<ElectronicBook>& electronicbooks, std::vector<Monitor>& monitores) {  //создание устройств
    int deviceType;
    std::cout << "Выберите тип устройства (1 - Смартфон, 2 - Ноутбук, 3 - Электронная книга, 4 - Монитор): ";
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
    else if (deviceType == 3) {
        ElectronicBook electronicbook;
        inputElectronicBook(&electronicbook);
        electronicbooks.push_back(electronicbook);
    }
    else if (deviceType == 4) {
        Monitor monitor;
        inputMonitor(&monitor);
        monitores.push_back(monitor);
    }
    else {
        std::cout << "Неверный выбор устройства." << std::endl;
    }
}

int main() {
    std::vector<Smartphone> smartphones;
    std::vector<Laptop> laptops;
    std::vector<ElectronicBook> electronicbooks;
    std::vector<Monitor> monitores;
    int choice;

    do {
        std::cout << "1. Ввод устройства\n2. Вывод смартфонов\n3. Вывод ноутбуков\n4. Вывод электронных книг\n5. Вывод мониторов\n0. Выход\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: createDevice(smartphones, laptops, electronicbooks, monitores); break; // вызов createDevice для всех типов
        case 2: for (const auto& phone : smartphones) outputSmartphone(phone); break;
        case 3: for (const auto& laptop : laptops) outputLaptop(laptop); break;
        case 4: for (const auto& electronicbook : electronicbooks) outputElectronicBook(electronicbook); break;
        case 5: for (const auto& monitor : monitores) outputMonitor(monitor); break;
        }
    } while (choice != 0);

    return 0;
}

