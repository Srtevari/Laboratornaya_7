#pragma once
#include "Service.h"

class JsonService :public Service
{
public:
	Weather getWeather(const  string& s);
	virtual ~JsonService() = default;
};


