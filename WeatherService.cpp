#include"Servis.h"
#include"JsonService.h"
#include"Service.h"
#include <iostream>

int main() {
    setlocale(LC_ALL,"Russian");
    try {
        JsonService js;
        Weather w = js.getWeather("weather.json");

        // Выводим результат
        w.print();
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
