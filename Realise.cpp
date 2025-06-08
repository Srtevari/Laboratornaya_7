#include"Servis.h"
void parse_json(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия JSON файла: " << filename << endl;
        return;
    }

    json j;
    file >> j;

    cout << "===== JSON данные =====" << endl;
    cout << "Город: " << j["name"] << endl;
    cout << "Температура: " << j["main"]["temp"] << " °C" << endl;
    cout << "Ощущается как: " << j["main"]["feels_like"] << " °C" << endl;
    cout << "Влажность: " << j["main"]["humidity"] << " %" << endl;
    cout << "Давление: " << j["main"]["pressure"] << " гПа" << endl;
    cout << "Скорость ветра: " << j["wind"]["speed"] << " м/с" << endl;
    cout << "Порывы ветра: " << j["wind"].value("gust", 0.0) << " м/с" << endl;
    cout << "Облачность: " << j["clouds"]["all"] << " %" << endl;
    cout << "Осадки за 1ч: " << j["rain"].value("1h", 0.0) << " мм" << endl;
    cout << "Погода: " << j["weather"][0]["description"] << endl;
    cout << endl;
}

void parse_xml(const string& filename) {
    pugi::xml_document doc;
    if (!doc.load_file(filename.c_str())) {
        cerr << "Ошибка чтения XML файла: " << filename << endl;
        return;
    }

    auto current = doc.child("current");
    auto city = current.child("city");
    auto temperature = current.child("temperature");
    auto wind = current.child("wind");
    auto speed = wind.child("speed");
    auto gusts = wind.child("gusts");
    auto direction = wind.child("direction");
    auto weather = current.child("weather");

    cout << "===== XML данные =====" << endl;
    cout << "Город: " << city.attribute("name").value() << endl;
    cout << "Температура: " << temperature.attribute("value").as_double() << " °C" << endl;
    cout << "Ощущается как: " << current.child("feels_like").attribute("value").as_double() << " °C" << endl;
    cout << "Влажность: " << current.child("humidity").attribute("value").as_int() << " %" << endl;
    cout << "Давление: " << current.child("pressure").attribute("value").as_int() << " гПа" << endl;
    cout << "Скорость ветра: " << speed.attribute("value").as_double() << " м/с" << endl;
    cout << "Порывы ветра: " << gusts.attribute("value").as_double() << " м/с" << endl;
    cout << "Направление ветра: " << direction.attribute("name").value() << endl;
    cout << "Облачность: " << current.child("clouds").attribute("value").as_int() << " %" << endl;
    cout << "Осадки: " << current.child("precipitation").attribute("value").as_double() << " мм" << endl;
    cout << "Погода: " << weather.attribute("value").value() << endl;
    cout << endl;
}


