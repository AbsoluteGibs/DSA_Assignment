#pragma once
#include <iostream>
using namespace std;

class Game 
{
private:
	string name;
	string description;
	float price;
public:
	Game ();
	string getName ();
	string getDescription ();
	float getPrice ();
};