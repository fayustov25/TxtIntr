#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath> // Для функций sin, cos и константы M_PI

void printHelp() {
    std::cout << "Баллистический калькулятор (Вариант 15)\n";
    std::cout << "Использование: calculator -o <операция> <угол_в_градусах> <начальная_скорость>\n";
    std::cout << "Поддерживаемые операции:\n";
    std::cout << "  height  - максимальная высота подъема (м)\n";
    std::cout << "  range   - дальность полета (м)\n";
    std::cout << "Пример: ./calculator -o height 45 20\n";
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printHelp();
        return 0;
    }

    std::string operation = "";
    std::vector<double> numbers;

    // Разбор аргументов командной строки
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        if (arg == "-o" || arg == "--operation") {
            if (i + 1 < argc) {
                operation = argv[++i]; 
            }
        } else {
            numbers.push_back(std::atof(arg.c_str())); // Преобразуем строку в число
        }
    }

    // Для нашего варианта строго нужно 2 операнда (угол и скорость)
    if (operation.empty() || numbers.size() != 2) {
        std::cerr << "Ошибка: неверные аргументы. Нужна операция и ровно 2 числа.\n\n";
        printHelp();
        return 1;
    }

    double angle_deg = numbers[0];
    double speed = numbers[1];
    
    // Перевод угла из градусов в радианы
    double angle_rad = angle_deg * M_PI / 180.0;
    double g = 9.8; // Ускорение свободного падения

    if (operation == "height") {
        // Формула высоты: H = (v^2 * sin^2(a)) / (2g)
        double height = (speed * speed * std::pow(std::sin(angle_rad), 2)) / (2 * g);
        std::cout << "Максимальная высота подъема: " << height << " м\n";
    } 
    else if (operation == "range") {
        // Формула дальности: S = (v^2 * sin(2a)) / g
        double range = (speed * speed * std::sin(2 * angle_rad)) / g;
        std::cout << "Дальность полета: " << range << " м\n";
    } 
    else {
        std::cerr << "Ошибка: неизвестная операция '" << operation << "'\n";
        return 1;
    }

    return 0;
}
