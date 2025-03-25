#pragma once
#include<string>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class defender
{
	Sprite wall;
	string player;
	bool dead;
	char dir[2];


	void motion();

};

