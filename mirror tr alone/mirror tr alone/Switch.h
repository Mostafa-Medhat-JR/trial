#pragma once
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Switch
{
	Sprite twomirror;
	string player;
	char orien;
	char dir[2];



	void motion();

};

