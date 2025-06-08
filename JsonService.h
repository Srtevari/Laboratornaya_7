#pragma once
#include "Service.h"
class JsonService :public Service
{
public:
	virtual Weather getWeather(const string s) override;
	virtual ~JsonService() {};
};


