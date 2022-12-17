/*
Реализовать класс оболочку Number
для числового типа float
Реализовать методы сложения
и деления
Создать производный класс Real
в котором реализовать метод возведения
в произвольную степень
и метод для вычисления логарифма числа*/
#include <iostream>
class Number
{
protected:
	float value_;
public:
	Number(const float& value) :value_(value) {};
	Number operator+(const Number& other)
	{
		return Number(value_ + other.value_);
	}

	Number operator/(const Number& other)
	{
		return Number(value_ / other.value_);
	}
};

class Real :public Number
{
public:
	Real();
	Real(float number) :Number(number)
	{}
	Real& operator=(const Real& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Real& rhs);

	float getLn()
	{
		return log(value_);
	};
	float degree(float power)
	{
		return pow(value_, power);
	};
};
int main()
{
	Real a(4);
	std::cout << a.degree(5);
	return 0;
}