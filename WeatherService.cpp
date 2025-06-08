#include"Servis.h"
#include"JsonService.h"
#include"Service.h"
#include <iostream>
#include"XmlService.h"
int main() {
    setlocale(LC_ALL,"Russian");
    try {
        XmlService xs;
        Weather s = xs.getWeather("weather.xml");

        JsonService js;
        Weather w = js.getWeather("weather.json");
        w.print();
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
}
