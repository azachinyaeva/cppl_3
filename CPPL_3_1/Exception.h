#pragma once
#include <iostream>

class ArrException : public std::domain_error {

public:
	ArrException(const std::string& message);

};
