#include <iostream>
#include<utility>
#include<string>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include "piece.h"

using namespace std;
using namespace sf;

//variables to be arguments to the constructor
int p1 = 1, p2 = 2;
pair<int, int>k;
string defl = "deflector", defen = "defender", swit = "switch", kin = "king";
int o1 = 1, o0 = 0, o2 = 2, o3 = 3;
//

//
RenderWindow window(VideoMode(1280, 720), "lonely");
//

//blue team deflector
piece bdeflector1(defl, o3, p1, k);
piece bdeflector2(defl, o0, p1, k);
piece bdeflector3(defl, o3, p1, k);
piece bdeflector4(defl, o3, p1, k);
piece bdeflector5(defl, o3, p1, k);
piece bdeflector6(defl, o2, p1, k);
piece bdeflector7(defl, o2, p1, k);

//blue team defender
piece bdefender1(defen, o0, p1, k);
piece bdefender2(defen, o0, p1, k);

//blue team switch
piece bswitch1(swit, o0, p1, k);
piece bswitch2(swit, o1, p1, k);

//blue team king
piece bking(kin, o0, p1, k);

//red team deflector
piece rdeflector1(defl, o3, p2, k);
piece rdeflector2(defl, o0, p2, k);
piece rdeflector3(defl, o3, p2, k);
piece rdeflector4(defl, o3, p2, k);
piece rdeflector5(defl, o3, p2, k);
piece rdeflector6(defl, o2, p2, k);
piece rdeflector7(defl, o2, p2, k);

//red team defender
piece rdefender1(defen, o2, p2, k);
piece rdefender2(defen, o2, p2, k);

//red team switch
piece rswitch1(swit, o0, p2, k);
piece rswitch2(swit, o1, p2, k);

//red tem king
piece rking(kin, o0, p2, k);

//colliders for the deflectors of the blue team

RectangleShape bdcollider1(Vector2f(3, 60.5));
RectangleShape bdcollider2(Vector2f(3, 60.5));
RectangleShape bdcollider3(Vector2f(3, 60.5));
RectangleShape bdcollider4(Vector2f(3, 60.5));
RectangleShape bdcollider5(Vector2f(3, 60.5));
RectangleShape bdcollider6(Vector2f(3, 60.5));
RectangleShape bdcollider7(Vector2f(3, 60.5));

//colliders for the deflectors of the red team
RectangleShape rdcollider1(Vector2f(3,60.5));
RectangleShape rdcollider2(Vector2f(3, 60.5));
RectangleShape rdcollider3(Vector2f(3, 60.5));
RectangleShape rdcollider4(Vector2f(3, 60.5));
RectangleShape rdcollider5(Vector2f(3, 60.5));
RectangleShape rdcollider6(Vector2f(3, 60.5));
RectangleShape rdcollider7(Vector2f(3, 60.5));

//colliders for the switch of the blue team
RectangleShape bscollider1(Vector2f(5, 60.5));
RectangleShape bscollider2(Vector2f(5, 60.5));

//colliders for the switch of the red team
RectangleShape rscollider1(Vector2f(5, 60.5));
RectangleShape rscollider2(Vector2f(5, 60.5));

void start();
void update();
void draw();
void colliderdrawer();
void setorigincollider();
void rotationc(RectangleShape raw);
void setrotatecollider();
void setposcollider();

int main()
{
	setorigincollider();
	setrotatecollider();
	start();
	while (window.isOpen()) {
		Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == evnt.Closed)
				window.close();
			if(evnt.type==Event::MouseButtonPressed)
			if (evnt.mouseButton.button==Mouse::Left) {
				bool clockwise = true;
				bool aclock = false;

				bdeflector1.rotate(clockwise);
				rdeflector1.rotate(aclock);
				bswitch1.rotate(clockwise);
			    bswitch2.rotate(clockwise);
				rswitch1.rotate(clockwise);
				rswitch2.rotate(clockwise);

				bdcollider1.rotate(90);
				rdcollider1.rotate(90);
				bscollider1.rotate(90);
				bscollider2.rotate(90);
				rscollider1.rotate(90);
				rscollider2.rotate(90);

				cout << bdeflector1.orientation << " " << rdeflector1.orientation << " " << bswitch1.orientation << " " << rswitch1.orientation << endl;
			}
		}
		update();
		window.clear();
		draw();
		colliderdrawer();
		window.display();
	}
	return 0;
}

void start() {

	bdeflector1.p.setPosition(50, 650);
	bdeflector2.p.setPosition(150,650 );
	bdeflector3.p.setPosition(250, 650);
	bdeflector4.p.setPosition(350, 650);
	bdeflector5.p.setPosition(450, 650);
	bdeflector6.p.setPosition(550, 650);
	bdeflector7.p.setPosition(650, 650);
	bdefender1.p.setPosition(750, 650);
	bdefender2.p.setPosition(850, 650);
	bswitch1.p.setPosition(950, 650);
	bswitch2.p.setPosition(1050, 650);
	bking.p.setPosition(650, 380);
	rdeflector1.p.setPosition(1000, 30);
	rdeflector2.p.setPosition(1000,120);
	rdeflector3.p.setPosition(1000, 190);
	rdeflector4.p.setPosition(1000, 260);
	rdeflector5.p.setPosition(1000, 330);
	rdeflector6.p.setPosition(1000, 400);
	rdeflector7.p.setPosition(1000, 470);
	rdefender1.p.setPosition(70, 550);
	rdefender2.p.setPosition(140,550 );
	rswitch1.p.setPosition(210, 550);
	rswitch2.p.setPosition(280, 550);
	rking.p.setPosition(350, 550);

	bdcollider1.setFillColor(Color::Green);
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
	rscollider2.setFillColor(Color::Green);

}

void update() {
	setposcollider();
}

void draw() {
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
	window.draw(rscollider1);
	window.draw(rscollider2);
	window.draw(bscollider1);
	window.draw(bscollider2);
}

void setorigincollider() {

	bdcollider1.setOrigin(bdcollider1.getLocalBounds().width / 2, bdcollider1.getLocalBounds().height / 2);
    bdcollider2.setOrigin(bdcollider2.getLocalBounds().width / 2, bdcollider2.getLocalBounds().height / 2);
	bdcollider3.setOrigin(bdcollider3.getLocalBounds().width / 2, bdcollider3.getLocalBounds().height / 2);
	bdcollider4.setOrigin(bdcollider4.getLocalBounds().width / 2, bdcollider4.getLocalBounds().height / 2);
	bdcollider5.setOrigin(bdcollider5.getLocalBounds().width / 2, bdcollider5.getLocalBounds().height / 2);
	bdcollider6.setOrigin(bdcollider6.getLocalBounds().width / 2, bdcollider6.getLocalBounds().height / 2);
	bdcollider7.setOrigin(bdcollider7.getLocalBounds().width / 2, bdcollider7.getLocalBounds().height / 2);
	rdcollider1.setOrigin(rdcollider1.getLocalBounds().width / 2, rdcollider1.getLocalBounds().height / 2);
	rdcollider2.setOrigin(rdcollider2.getLocalBounds().width / 2, rdcollider2.getLocalBounds().height / 2);
	rdcollider3.setOrigin(rdcollider3.getLocalBounds().width / 2, rdcollider3.getLocalBounds().height / 2);
	rdcollider4.setOrigin(rdcollider4.getLocalBounds().width / 2, rdcollider4.getLocalBounds().height / 2);
	rdcollider5.setOrigin(rdcollider5.getLocalBounds().width / 2, rdcollider5.getLocalBounds().height / 2);
	rdcollider6.setOrigin(rdcollider6.getLocalBounds().width / 2, rdcollider6.getLocalBounds().height / 2);
	rdcollider7.setOrigin(rdcollider7.getLocalBounds().width / 2, rdcollider7.getLocalBounds().height / 2);
	bscollider1.setOrigin(bscollider1.getLocalBounds().width / 2, bscollider1.getLocalBounds().height / 2);
	bscollider2.setOrigin(bscollider2.getLocalBounds().width / 2, bscollider2.getLocalBounds().height / 2);
	rscollider1.setOrigin(rscollider1.getLocalBounds().width / 2, rscollider1.getLocalBounds().height / 2);
	rscollider2.setOrigin(rscollider2.getLocalBounds().width / 2, rscollider2.getLocalBounds().height / 2);

}

void rotationc(RectangleShape raw) {
	raw.rotate(90);
}

void setrotatecollider()
{
	bdcollider1.setRotation(-45);
	bdcollider2.setRotation(45);
	bdcollider3.setRotation(-45);
	bdcollider4.setRotation(-45);
	bdcollider5.setRotation(-45);
	bdcollider6.setRotation(45);
	bdcollider7.setRotation(45);
	rdcollider1.setRotation(-45);
	rdcollider2.setRotation(45);
	rdcollider3.setRotation(-45);
	rdcollider4.setRotation(-45);
	rdcollider5.setRotation(-45);
	rdcollider6.setRotation(45);
	rdcollider7.setRotation(45);
	bscollider1.setRotation(41);
	bscollider2.setRotation(-50);
	rscollider1.setRotation(41);
	rscollider2.setRotation(-50);
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
	
}
