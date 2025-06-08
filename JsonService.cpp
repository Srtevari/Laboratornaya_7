#include "JsonService.h"
#include <fstream>
#include <exception>
#include "Weather.h"
#include "nlohmann/json.hpp"
using nlohmann::json;
Weather JsonService::getWeather(const string s)
{
    ifstream fin(s);
    if (!fin)
        throw runtime_error("Ошибка открытия файла: " + s);

    json j;
    fin >> j;

    string city = j["name"];
    double lon = j["coord"]["lon"]; 
    double lat = j["coord"]["lat"];
    double temperature = j["main"]["temp"];
    string weather = j["weather"][0]["description"];
    double windSpeed = j["wind"]["speed"];
    int clouds = j["clouds"]["all"]; 

    return Weather(city, lon, lat, temperature, weather, windSpeed, clouds);
}
