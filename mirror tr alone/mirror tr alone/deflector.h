#pragma once
#include<string>
using namespace std;
#include<SFML/Graphics.hpp>
using namespace sf;
class deflector
{
	Sprite  onemirror;
	string player;
		bool dead;
		char dir[2];


		void motion();


};

