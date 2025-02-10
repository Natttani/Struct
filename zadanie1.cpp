#include <iostream>
#include <vector>
#include <string>

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
    std::cout << "������� �����-�������������: ";
    std::cin >> phone->manufacturer;
    std::cout << "������� ����� ���������� ������ (��): ";
    std::cin >> phone->memory;
    std::cout << "������� ����: ";
    std::cin >> phone->price;
}

void outputSmartphone(const Smartphone& phone) {
    std::cout << "�������� " << phone.manufacturer << ", ������: " << phone.memory
        << "��, ����: " << phone.price << " ���." << std::endl;
}

void inputLaptop(Laptop* laptop) {
    std::cout << "������� �����-�������������: ";
    std::cin >> laptop->manufacturer;
    std::cout << "������� ������ ����������: ";
    std::cin >> laptop->cpuModel;
    std::cout << "���� �� ������� ����������? (1 - ��, 0 - ���): ";
    std::cin >> laptop->hasGamingGPU;
}

void outputLaptop(const Laptop& laptop) {
    std::cout << "������� " << laptop.manufacturer << ", ���������: " << laptop.cpuModel
        << ", ������� ����������: " << (laptop.hasGamingGPU ? "��" : "���") << std::endl;
}

void createSmartphones(std::vector<Smartphone>& phones) {
    Smartphone* phone = new Smartphone;
    inputSmartphone(phone);
    phones.push_back(*phone);
    delete phone;
}

void createLaptops(std::vector<Laptop>& laptops) {
    Laptop* laptop = new Laptop;
    inputLaptop(laptop);
    laptops.push_back(*laptop);
    delete laptop;
}

int main() {
    std::vector<Smartphone> smartphones;
    std::vector<Laptop> laptops;
    int choice;

    do {
        std::cout << "1. ���� ���������\n2. ���� ��������\n3. ����� ����������\n4. ����� ���������\n0. �����\n�������� ��������: ";
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

