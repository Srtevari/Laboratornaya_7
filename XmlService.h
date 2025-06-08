#pragma once
#include "Service.h"
class XmlService :public Service
{
public:
	Weather getWeather(const string& s) override;
	virtual ~XmlService() {};
};
