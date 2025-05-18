#pragma once
class Progression
{
	double first;
	unsigned int second;

public:
	void Init(double, unsigned int);
	void Read();
	void Show();
	double element(int j);
};