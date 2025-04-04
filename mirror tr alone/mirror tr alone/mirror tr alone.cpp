
/*
if this is gone change in github

let see

*/


#include <iostream>
#include<utility>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "piece.h"

using namespace std;
using namespace sf;

//Variables of rows &columns of the Board
int r = -1, c = -1;
const int Rows = 8;
const int Columns = 10;

//variables to be arguments to the constructor
int p1 = 1, p2 = 2;
pair<int, int>k;
string defl = "deflector", defen = "defender", swit = "switch", kin = "king", las = "laser";
int o1 = 1, o0 = 0, o2 = 2, o3 = 3;

RenderWindow window(VideoMode(1920, 1080), "Laser Chess");

Color backgroundcolor(255, 239, 226, 255);

RectangleShape grid[Rows][Columns];
RectangleShape KillsBoard;

Font font;

Text text1;
Text text2;

Sprite logoo;
Sprite rotatee;
Sprite grd;
Sprite Blueplayer;
Sprite Redplayer;

Texture board;
Texture Rotate;
Texture Blue;
Texture logo;
Texture Red;

struct cell {
	bool isempty = true;
	Vector2f Position;
};
cell table[Rows][Columns];

//
//blue team deflector
piece bdeflector1(defl, o0, p1, k);
piece bdeflector2(defl, o0, p1, k);
piece bdeflector3(defl, o0, p1, k);
piece bdeflector4(defl, o0, p1, k);
piece bdeflector5(defl, o3, p1, k);
piece bdeflector6(defl, o1, p1, k);
piece bdeflector7(defl, o1, p1, k);

//blue team defender
piece bdefender1(defen, o0, p1, k);
piece bdefender2(defen, o0, p1, k);

//blue team switch
piece bswitch1(swit, o0, p1, k);
piece bswitch2(swit, o1, p1, k);

//blue team king
piece bking(kin, o0, p1, k);

//Blue laser
piece blaser(las, o0, p1, k);

//red team deflector
piece rdeflector1(defl, o2, p2, k);
piece rdeflector2(defl, o1, p2, k);
piece rdeflector3(defl, o2, p2, k);
piece rdeflector4(defl, o2, p2, k);
piece rdeflector5(defl, o3, p2, k);
piece rdeflector6(defl, o3, p2, k);
piece rdeflector7(defl, o2, p2, k);

//red team defender
piece rdefender1(defen, o2, p2, k);
piece rdefender2(defen, o2, p2, k);

//red team switch
piece rswitch1(swit, o0, p2, k);
piece rswitch2(swit, o1, p2, k);

//red tem king
piece rking(kin, o0, p2, k);

//Red laser
piece rlaser(las, o0, p2, k);

//colliders for the deflectors of the blue team
RectangleShape bdcollider1(Vector2f(4, 70.5));
RectangleShape bdcollider2(Vector2f(4, 70.5));
RectangleShape bdcollider3(Vector2f(4, 70.5));
RectangleShape bdcollider4(Vector2f(4, 70.5));
RectangleShape bdcollider5(Vector2f(4, 70.5));
RectangleShape bdcollider6(Vector2f(4, 70.5));
RectangleShape bdcollider7(Vector2f(4, 70.5));

//colliders for the deflectors of the red team
RectangleShape rdcollider1(Vector2f(4,70.5));
RectangleShape rdcollider2(Vector2f(4, 70.5));
RectangleShape rdcollider3(Vector2f(4,70.5));
RectangleShape rdcollider4(Vector2f(4, 70.5));
RectangleShape rdcollider5(Vector2f(4, 70.5));
RectangleShape rdcollider6(Vector2f(4, 70.5));
RectangleShape rdcollider7(Vector2f(4, 70.5));

//colliders for the switch of the blue team
RectangleShape bscollider1(Vector2f(5, 70.5));
RectangleShape bscollider2(Vector2f(5, 70.5));

//colliders for the switch of the red team
RectangleShape rscollider1(Vector2f(5, 70.5));
RectangleShape rscollider2(Vector2f(5, 70.5));
//Blue Shield Defender
RectangleShape bshield1(Vector2f(5, 47));
RectangleShape bshield2(Vector2f(5, 47));
//Red Shield Defender
RectangleShape rshield1(Vector2f(5, 47));
RectangleShape rshield2(Vector2f(5, 47));

//functions defination
void start();
void update();
void piecedraw();
void setpiecepos();
void colliderdrawer();
void setorigincollider();
void setrotatecollider();
void setposcollider();
void boardDraw();
void index(Vector2i mouseposition);


int main()
{
	
	setorigincollider();
	setrotatecollider();
	start();
	setpiecepos();
	while (window.isOpen()) {
		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed)
				window.close();
			if(evnt.type==Event::MouseButtonPressed)
			if (evnt.mouseButton.button==Mouse::Right) {
				bool clockwise = true;
				bool aclock = false;

				bdeflector1.rotate(clockwise);
				bdeflector2.rotate(clockwise);
				bdeflector3.rotate(clockwise);
				bdeflector4.rotate(clockwise);
				bdeflector5.rotate(clockwise);
				bdeflector6.rotate(clockwise);
				bdeflector7.rotate(clockwise);

				rdeflector1.rotate(aclock);
				rdeflector2.rotate(aclock);
			    rdeflector3.rotate(aclock);
				rdeflector4.rotate(aclock);
				rdeflector5.rotate(aclock);
				rdeflector6.rotate(aclock);
				rdeflector7.rotate(-aclock);


				bdefender1.rotate(clockwise);
				bdefender2.rotate(clockwise);

				rdefender1.rotate(aclock);
				rdefender2.rotate(aclock);

				bswitch1.rotate(clockwise);
				bswitch2.rotate(clockwise);

				rswitch1.rotate(aclock);
				rswitch2.rotate(aclock);


				bdcollider1.rotate(90);
				bdcollider2.rotate(90);
				bdcollider3.rotate(90);
				bdcollider4.rotate(90);
				bdcollider5.rotate(90);
				bdcollider6.rotate(90);
				bdcollider7.rotate(90);

				rdcollider1.rotate(-90);
				rdcollider2.rotate(-90);
				rdcollider3.rotate(-90);
				rdcollider4.rotate(-90);
				rdcollider5.rotate(-90);
				rdcollider6.rotate(-90);
				rdcollider7.rotate(-90);

				bscollider1.rotate(90);
				bscollider2.rotate(90);

				rscollider1.rotate(-90);
				rscollider2.rotate(-90);

				bshield1.rotate(90);
				bshield2.rotate(90);

				rshield1.rotate(-90);
				rshield2.rotate(-90);
				cout << bdeflector1.orientation << " " << rdeflector1.orientation << " " << bswitch1.orientation << " " << rswitch1.orientation << endl;
			}
			if (evnt.type == Event::MouseButtonPressed && evnt.mouseButton.button == Mouse::Left) {
				index(Mouse::getPosition(window));
			}
		}

		update();
		window.clear();
		boardDraw();
		piecedraw();
		colliderdrawer();
		window.display();
	}
	return 0;
}

void start() {

	/*bdcollider1.setFillColor(Color::Green);
	bdcollider2.setFillColor(Color::Green);
	bdcollider3.setFillColor(Color::Green);
	bdcollider4.setFillColor(Color::Green);
	bdcollider5.setFillColor(Color::Green);
	bdcollider6.setFillColor(Color::Green);
	bdcollider7.setFillColor(Color::Green);

	rdcollider1.setFillColor(Color::Green);
	rdcollider2.setFillColor(Color::Green);
	rdcollider3.setFillColor(Color::Green);
	rdcollider4.setFillColor(Color::Green);
	rdcollider5.setFillColor(Color::Green);
	rdcollider6.setFillColor(Color::Green);
	rdcollider7.setFillColor(Color::Green);
	
	bscollider1.setFillColor(Color::Green);
	bscollider2.setFillColor(Color::Green);

	rscollider1.setFillColor(Color::Green);
	rscollider2.setFillColor(Color::Green);*/
	

	bshield1.setFillColor(Color::Black);
	bshield2.setFillColor(Color::Black);
	rshield1.setFillColor(Color::Black);
	rshield2.setFillColor(Color::Black);


	logo.loadFromFile("Board pics/logo.png");
	logoo.setTexture(logo);
	Red.loadFromFile("Board pics/Redplayer.png");
	Redplayer.setTexture(Red);
	Blue.loadFromFile("Board pics/blueplayer.png");
	Blueplayer.setTexture(Blue);
	Blueplayer.setScale(0.12, 0.12);
	Redplayer.setScale(0.12, 0.12);
	logoo.setScale(0.6, 0.6);
	logoo.setPosition(150, 25);
	Redplayer.setPosition(242, 160);
	Blueplayer.setPosition(242, 765);
	board.loadFromFile("Board pics/grid.png");
	grd.setTexture(board);
	grd.setPosition(245, 212);
	font.loadFromFile("Board pics/arial.ttf");
	text1.setFont(font);
	text1.setString("Red Player");
	text1.setFillColor(Color::Red);
	text1.setStyle(Text::Bold);
	text1.setPosition(302, 165);
	text2.setFont(font);
	text2.setString("Blue Player");
	text2.setFillColor(Color(13, 110, 253, 255));
	text2.setStyle(Text::Bold);
	text2.setPosition(302, 768);
	KillsBoard.setSize(Vector2f(68, 820));
	KillsBoard.setOutlineColor(Color::White);
	KillsBoard.setOutlineThickness(2);
	KillsBoard.setPosition(1200, 110);
	KillsBoard.setFillColor(Color(222, 201, 180, 1200));
	Rotate.loadFromFile("Board pics/Rotate.png");
	rotatee.setTexture(Rotate);
	rotatee.setScale(1, 1);
	rotatee.setPosition(480, 820);

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Columns; j++) {
			grid[i][j].setSize(Vector2f(65.4, 65.4));
			grid[i][j].setFillColor(Color(0, 0, 0, 0));
			grid[i][j].setOutlineColor(Color::White);
			grid[i][j].setOutlineThickness(1);
			Vector2f pos((j * 65.4) + 289, (i * 65.4) + 258);
			grid[i][j].setPosition(pos);
			grid[i][j].setOrigin(grid[i][j].getLocalBounds().width / 2, grid[i][j].getLocalBounds().height / 2);
			table[i][j].Position = pos;
			//table[i][j].isempty = true;
		}
	}


}

void update() {
	setposcollider();
}

void piecedraw() {
	window.draw(bdeflector1.p);
	window.draw(bdeflector2.p);
	window.draw(bdeflector3.p);
	window.draw(bdeflector4.p);
	window.draw(bdeflector5.p);
	window.draw(bdeflector6.p);
	window.draw(bdeflector7.p);
	window.draw(bdefender1.p);
	window.draw(bdefender2.p);
	window.draw(bswitch1.p);
	window.draw(bswitch2.p);
	window.draw(bking.p);
	window.draw(rdeflector1.p);
	window.draw(rdeflector2.p);
	window.draw(rdeflector3.p);
	window.draw(rdeflector4.p);
	window.draw(rdeflector5.p);
	window.draw(rdeflector6.p);
	window.draw(rdeflector7.p);
	window.draw(rdefender1.p);
	window.draw(rdefender2.p);
	window.draw(rswitch1.p);
	window.draw(rswitch2.p);
	window.draw(rking.p);
	window.draw(blaser.p);
	window.draw(rlaser.p);
}

void setpiecepos(){
	/*
blaser.p.setPosition(grid[7][9].getPosition());

bking.p.setPosition(grid[7][4].getPosition());
bdefender1.p.setPosition(grid[7][3].getPosition());
bdefender2.p.setPosition(grid[7][5].getPosition());
bswitch1.p.setPosition(grid[4][4].getPosition());
bswitch2.p.setPosition(grid[4][5].getPosition());

bdeflector1.p.setPosition(grid[4][2].getPosition());
bdeflector2.p.setPosition(grid[2][3].getPosition());
bdeflector3.p.setPosition(grid[7][2].getPosition());
bdeflector4.p.setPosition(grid[3][9].getPosition());
bdeflector5.p.setPosition(grid[6][7].getPosition());
bdeflector6.p.setPosition(grid[4][9].getPosition());
bdeflector7.p.setPosition(grid[3][2].getPosition());

rlaser.p.setPosition(grid[0][0].getPosition());
rking.p.setPosition(grid[0][5].getPosition());

rdefender1.p.setPosition(grid[0][4].getPosition());
rdefender2.p.setPosition(grid[0][6].getPosition());

rswitch1.p.setPosition(grid[3][5].getPosition());
rswitch2.p.setPosition(grid[3][4].getPosition());

rdeflector1.p.setPosition(grid[0][7].getPosition());
rdeflector2.p.setPosition(grid[2][2].getPosition());
rdeflector3.p.setPosition(grid[4][0].getPosition());
rdeflector4.p.setPosition(grid[3][7].getPosition());
rdeflector5.p.setPosition(grid[4][7].getPosition());
rdeflector6.p.setPosition(grid[3][0].getPosition());
rdeflector7.p.setPosition(grid[5][6].getPosition());
*/


	blaser.p.setPosition(table[7][9].Position);

	bking.p.setPosition(table[7][4].Position);
	bdefender1.p.setPosition(table[7][3].Position);
	bdefender2.p.setPosition(table[7][5].Position);
	bswitch1.p.setPosition(table[4][4].Position);
	bswitch2.p.setPosition(table[4][5].Position);

	bdeflector1.p.setPosition(table[4][2].Position);
	bdeflector2.p.setPosition(table[2][3].Position);
	bdeflector3.p.setPosition(table[7][2].Position);
	bdeflector4.p.setPosition(table[3][9].Position);
	bdeflector5.p.setPosition(table[6][7].Position);
	bdeflector6.p.setPosition(table[4][9].Position);
	bdeflector7.p.setPosition(table[3][2].Position);

	rlaser.p.setPosition(table[0][0].Position);
	rking.p.setPosition(table[0][5].Position);

	rdefender1.p.setPosition(table[0][4].Position);
	rdefender2.p.setPosition(table[0][6].Position);

	rswitch1.p.setPosition(table[3][5].Position);
	rswitch2.p.setPosition(table[3][4].Position);

	rdeflector1.p.setPosition(table[0][7].Position);
	rdeflector2.p.setPosition(table[1][2].Position);
	rdeflector3.p.setPosition(table[4][0].Position);
	rdeflector4.p.setPosition(table[3][7].Position);
	rdeflector5.p.setPosition(table[4][7].Position);
	rdeflector6.p.setPosition(table[3][0].Position);
	rdeflector7.p.setPosition(table[5][6].Position);

}

void colliderdrawer() {
	window.draw(bdcollider1);
	window.draw(bdcollider2);
	window.draw(bdcollider3);
	window.draw(bdcollider4);
	window.draw(bdcollider5);
	window.draw(bdcollider6);
	window.draw(bdcollider7);
	window.draw(rdcollider1);
	window.draw(rdcollider2);
	window.draw(rdcollider3);
	window.draw(rdcollider4);
	window.draw(rdcollider5);
	window.draw(rdcollider6);
	window.draw(rdcollider7);
	/*window.draw(rscollider1);
	window.draw(rscollider2);
	window.draw(bscollider1);
	window.draw(bscollider2);
	*/
	window.draw(bshield1);
	window.draw(bshield2);
	window.draw(rshield1);
	window.draw(rshield2);

}

void setorigincollider() {

	bdcollider1.setOrigin((bdcollider1.getLocalBounds().width / 2)+5, bdcollider1.getLocalBounds().height / 2);
    bdcollider2.setOrigin((bdcollider2.getLocalBounds().width / 2)+5, bdcollider2.getLocalBounds().height / 2);
	bdcollider3.setOrigin((bdcollider3.getLocalBounds().width / 2)+5, bdcollider3.getLocalBounds().height / 2);
	bdcollider4.setOrigin((bdcollider4.getLocalBounds().width / 2)+5, bdcollider4.getLocalBounds().height / 2);
	bdcollider5.setOrigin((bdcollider5.getLocalBounds().width / 2)-5, bdcollider5.getLocalBounds().height / 2);
	bdcollider6.setOrigin((bdcollider6.getLocalBounds().width / 2)+5, bdcollider6.getLocalBounds().height / 2);
	bdcollider7.setOrigin((bdcollider7.getLocalBounds().width / 2)+5, bdcollider7.getLocalBounds().height / 2);
	rdcollider1.setOrigin((rdcollider1.getLocalBounds().width / 2)-5, rdcollider1.getLocalBounds().height / 2);
	rdcollider2.setOrigin((rdcollider2.getLocalBounds().width / 2)+5, rdcollider2.getLocalBounds().height / 2);
	rdcollider3.setOrigin((rdcollider3.getLocalBounds().width / 2)-5, rdcollider3.getLocalBounds().height / 2);
	rdcollider4.setOrigin((rdcollider4.getLocalBounds().width / 2)-5, rdcollider4.getLocalBounds().height / 2);
	rdcollider5.setOrigin((rdcollider5.getLocalBounds().width / 2)-5, rdcollider5.getLocalBounds().height / 2);
	rdcollider6.setOrigin((rdcollider6.getLocalBounds().width / 2)-5, rdcollider6.getLocalBounds().height / 2);
	rdcollider7.setOrigin((rdcollider7.getLocalBounds().width / 2)-5, rdcollider7.getLocalBounds().height / 2);
	bscollider1.setOrigin((bscollider1.getLocalBounds().width / 2), bscollider1.getLocalBounds().height / 2);
	bscollider2.setOrigin((bscollider2.getLocalBounds().width / 2), bscollider2.getLocalBounds().height / 2);
	rscollider1.setOrigin((rscollider1.getLocalBounds().width / 2), rscollider1.getLocalBounds().height / 2);
	rscollider2.setOrigin((rscollider2.getLocalBounds().width / 2), rscollider2.getLocalBounds().height / 2);

	bshield1.setOrigin((bshield1.getLocalBounds().width / 2)+25, (bshield1.getLocalBounds().height / 2));
	bshield2.setOrigin((bshield2.getLocalBounds().width / 2)+25, (bshield2.getLocalBounds().height / 2));
	rshield1.setOrigin((rshield1.getLocalBounds().width / 2)-25, (rshield1.getLocalBounds().height / 2));
	rshield2.setOrigin((rshield2.getLocalBounds().width / 2)-25, (rshield2.getLocalBounds().height / 2));

}

void setrotatecollider()
{
	bdcollider1.setRotation(45);
	bdcollider2.setRotation(45);
	bdcollider3.setRotation(45);
	bdcollider4.setRotation(45);
	bdcollider5.setRotation(-45);
	bdcollider6.setRotation(-45);
	bdcollider7.setRotation(-45);
	rdcollider1.setRotation(45);
	rdcollider2.setRotation(-45);
	rdcollider3.setRotation(45);
	rdcollider4.setRotation(45);
	rdcollider5.setRotation(-45);
	rdcollider6.setRotation(-45);
	rdcollider7.setRotation(45);
	bscollider1.setRotation(41);
	bscollider2.setRotation(-50);
	rscollider1.setRotation(41);
	rscollider2.setRotation(-50);

	bshield1.setRotation(90);
	bshield2.setRotation(90);
	rshield1.setRotation(90);
	rshield2.setRotation(90);







}

void setposcollider()
{
	bdcollider1.setPosition(bdeflector1.p.getPosition());
	bdcollider2.setPosition(bdeflector2.p.getPosition());
	bdcollider3.setPosition(bdeflector3.p.getPosition());
	bdcollider4.setPosition(bdeflector4.p.getPosition());
	bdcollider5.setPosition(bdeflector5.p.getPosition());
	bdcollider6.setPosition(bdeflector6.p.getPosition());
	bdcollider7.setPosition(bdeflector7.p.getPosition());
	rdcollider1.setPosition(rdeflector1.p.getPosition());
	rdcollider2.setPosition(rdeflector2.p.getPosition());
	rdcollider3.setPosition(rdeflector3.p.getPosition());
	rdcollider4.setPosition(rdeflector4.p.getPosition());
	rdcollider5.setPosition(rdeflector5.p.getPosition());
	rdcollider6.setPosition(rdeflector6.p.getPosition());
	rdcollider7.setPosition(rdeflector7.p.getPosition());
	bscollider1.setPosition(bswitch1.p.getPosition());
	bscollider2.setPosition(bswitch2.p.getPosition());
	rscollider1.setPosition(rswitch1.p.getPosition());
	rscollider2.setPosition(rswitch2.p.getPosition());
	bshield1.setPosition(bdefender1.p.getPosition());
	bshield2.setPosition(bdefender2.p.getPosition());
	rshield1.setPosition(rdefender1.p.getPosition());
	rshield2.setPosition(rdefender2.p.getPosition());
}

pair<int, int> getCellIndex(Vector2i mouseposition) {
	float cellSize = grid[0][0].getSize().x;
	if (mouseposition.y > 225 && mouseposition.y < 745 && mouseposition.x > 258 && mouseposition.x < 914) {
		r = (mouseposition.y - 226) / cellSize;
		c = (mouseposition.x - 257) / cellSize;
		return { r, c };
	}
}

void index(Vector2i mouseposition) {
	pair<int, int> mouseclick = getCellIndex(mouseposition); 
	static int prev_r = -1, prev_c = -1;

	if (r != prev_r || c != prev_c) {
		cout << mouseclick.first << " " << mouseclick.second << endl;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Columns; j++) {
				grid[i][j].setFillColor(Color(0, 0, 0, 0));
			}
		}

		if (r >= 0 && r < Rows && c >= 0 && c < Columns) {
			if (r - 1 >= 0&& table[r][c].isempty == true)grid[r - 1][c].setFillColor(Color::Green);
			if (r + 1 < Rows&& table[r][c].isempty == true) grid[r + 1][c].setFillColor(Color::Green);
			if (c - 1 >= 0&& table[r][c].isempty == true) grid[r][c - 1].setFillColor(Color::Green);
			if (c + 1 < Columns&& table[r][c].isempty == true) grid[r][c + 1].setFillColor(Color::Green);
			if (r - 1 >= 0 && c - 1 >= 0&& table[r][c].isempty == true) grid[r - 1][c - 1].setFillColor(Color::Green);
			if (r - 1 >= 0 && c + 1 < Columns&& table[r][c].isempty == true) grid[r - 1][c + 1].setFillColor(Color::Green);
			if (r + 1 < Rows && c - 1 >= 0&& table[r][c].isempty == true) grid[r + 1][c - 1].setFillColor(Color::Green);
			if (r + 1 < Rows && c + 1 < Columns&& table[r][c].isempty == true) grid[r + 1][c + 1].setFillColor(Color::Green);
			
		}

		prev_r = r;
		prev_c = c;
	}
}

void boardDraw() {

	window.clear(backgroundcolor);
	window.draw(logoo);
	window.draw(Blueplayer);
	window.draw(Redplayer);
	window.draw(grd);
	window.draw(text1);
	window.draw(text2);
	window.draw(KillsBoard);
	window.draw(rotatee);
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Columns; j++)
		{
			window.draw(grid[i][j]);
		}
	}
}