#pragma once
#include"includ.h"
class Weather {
public:
    string city; 
    double lon;
    double lat;
    double temperature;
    string weather;
    double windSpeed;
    int clouds;

    Weather(const string& cityName,
        double longitude,
        double latitude,
        double temp,
        const string& weatherDesc,
        double wind,
        int cloudiness)
        : city(cityName),
        lon(longitude),
        lat(latitude),
        temperature(temp),
        weather(weatherDesc),
        windSpeed(wind),
        clouds(cloudiness)
    {
    }

    void print() const {
        cout << "Погода в городе " << city << ":\n"
            << "  Координаты: [" << lat << ", " << lon << "]\n"
            << "  Температура: " << temperature << " °C\n"
            << "  Описание: " << weather << "\n"
            << "  Скорость ветра: " << windSpeed << " м/с\n"
            << "  Облачность: " << clouds << " %\n";
    }
};

