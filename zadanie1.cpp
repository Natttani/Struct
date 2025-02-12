#include <iostream>
#include <vector>
#include <string>

enum DeviceType {
    SmartphoneType = 1,
    LaptopType,
    ElectronicBookType
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

void inputSmartphone(Smartphone* phone) { //���� ���������
    std::cout << "������� �����-�������������: ";
    std::cin >> phone->manufacturer;
    std::cout << "������� ����� ���������� ������ (��): ";
    std::cin >> phone->memory;
    std::cout << "������� ����: ";
    std::cin >> phone->price;
}

void outputSmartphone(const Smartphone& phone) { //����� ����������
    std::cout << "�������� " << phone.manufacturer << ", ������: " << phone.memory
        << "��, ����: " << phone.price << " ���." << std::endl;
}

void inputLaptop(Laptop* laptop) { //���� ���������
    std::cout << "������� �����-�������������: ";
    std::cin >> laptop->manufacturer;
    std::cout << "������� ������ ����������: ";
    std::cin >> laptop->cpuModel;
    std::cout << "���� �� ������� ����������? (1 - ��, 0 - ���): ";
    std::cin >> laptop->hasGamingGPU;
}

void outputLaptop(const Laptop& laptop) { //����� ���������
    std::cout << "������� " << laptop.manufacturer << ", ���������: " << laptop.cpuModel
        << ", ������� ����������: " << (laptop.hasGamingGPU ? "��" : "���") << std::endl;
}

void inputElectronicBook(ElectronicBook* electronicBook) { //���� ����������� �����
    std::cout << "������� �����-�������������: ";
    std::cin >> electronicBook->manufacturer;
    std::cout << "������� ������ ������ : ";
    std::cin >> electronicBook->screenSize;
    std::cout << "���� �� ��������� ������? (1 - ��, 0 - ���): ";
    std::cin >> electronicBook->screenBacklight;
}

void outputElectronicBook(const ElectronicBook& electronicBook) { //����� ����������� �����
    std::cout << "����������� ����� " << electronicBook.manufacturer << ", ������ ������: " << electronicBook.screenSize << "������� ��������� ������: " << electronicBook.screenBacklight << std::endl;
}

void createDevice(std::vector<Smartphone>& smartphones, std::vector<Laptop>& laptops, std::vector<ElectronicBook>& electronicbooks) {  //�������� ���������
    int deviceType;
    std::cout << "�������� ��� ���������� (1 - ��������, 2 - �������, 3 - ����������� �����): ";
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
    else {
        std::cout << "�������� ����� ����������." << std::endl;
    }
}

int main() {
    std::vector<Smartphone> smartphones;
    std::vector<Laptop> laptops;
    std::vector<ElectronicBook> electronicbooks;
    int choice;

    do {
        std::cout << "1. ���� ����������\n2. ����� ����������\n3. ����� ���������\n4. ����� ����������� ����\n0. �����\n�������� ��������: ";
        std::cin >> choice;

        switch (choice) {
        case 1: createDevice(smartphones, laptops, electronicbooks); break; // ����� createDevice ��� ���� �����
        case 2: for (const auto& phone : smartphones) outputSmartphone(phone); break;
        case 3: for (const auto& laptop : laptops) outputLaptop(laptop); break;
        case 4: for (const auto& electronicbook : electronicbooks) outputElectronicBook(electronicbook); break;
        }
    } while (choice != 0);

    return 0;
}

