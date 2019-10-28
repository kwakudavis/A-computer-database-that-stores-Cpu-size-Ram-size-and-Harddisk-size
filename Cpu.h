#pragma once
class Cpu
{
private:
	unsigned int speed;


public:
	unsigned int getSpeed() { return speed; };

	void setSpeed(unsigned int speed) { this->speed = speed; }
};
