#pragma once
#include"includ.h"
#include"Weather.h"

class Service {
public:
    virtual Weather getWeather(const  string& s) = 0;
    virtual ~Service() = default;
};