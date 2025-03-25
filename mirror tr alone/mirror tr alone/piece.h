#pragma once
#include<string>
#include<SFML/Graphics.hpp>
#include<utility>
using namespace std;
using namespace sf;

class piece
{

public:
	//Destructor
	~piece();

	//Constructor
	piece(string t,int orie,int pl,pair<int,int>pos);

	//Sprite for the pieces
	Sprite p;

	//Texture for the pieces
	Texture tx;

	//Chose the type for the pieces
	string type;

	//the first player declared as 1 and the secound player declared as 2
	int player;

    //
	int orientation;
	//
	pair<int, int> position;

	//fn for pieces to rotate
	void rotate(bool clockwise);

	//fn move for the pieces
	void motion(int row,int col);

	//keep this fn for now
	void kill();

};
