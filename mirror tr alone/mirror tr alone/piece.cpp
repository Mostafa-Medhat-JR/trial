#include "piece.h"


piece::~piece()
{
}

piece::piece(string t, int orie, int pl, pair<int, int>pos)
{

	this->type = t;
	this->orientation = orie;
	this->player = pl;

	//blue player sprites
	if (this->player == 1) {
		//Sprite for the Deflectors
		if (this->type == "deflector") {
			if (this->orientation == 0) {
				this->tx.loadFromFile("pieces pics/deflector blue.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {

				this->tx.loadFromFile("pieces pics/deflector blue o=1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 2) {

				this->tx.loadFromFile("pieces pics/deflector blue o=2.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 3) {

				this->tx.loadFromFile("pieces pics/deflector blue o= 3.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}
		}

		//Sprite for the Defenders
		else if (this->type == "defender") {

			if (this->orientation == 0) {
				this->tx.loadFromFile("pieces pics/defender blue.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {

				this->tx.loadFromFile("pieces pics/defender blue o=1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);

			}

			else if (this->orientation == 2) {

				this->tx.loadFromFile("pieces pics/defender blue o=2.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);

			}
			else if (this->orientation == 3) {

				this->tx.loadFromFile("pieces pics/defender blue o=3.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}
		}
		//Sprite for the Switches

		else if (this->type == "switch") {


			if (this->orientation == 0) {
				this->tx.loadFromFile("pieces pics/switch blue.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {
				this->tx.loadFromFile("pieces pics/switch blue o= 1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

		}

		//Sprite fot the Kings

		else if (this->type == "king") {

				this->tx.loadFromFile("pieces pics/the king blue.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
		}

	}

	//the Red player sprites
	else if (this->player == 2) {

		//Sprite for the Deflectors
		if (this->type == "deflector") {

			if (this->orientation == 0) {

				this->tx.loadFromFile("pieces pics/deflector red.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {

				this->tx.loadFromFile("pieces pics/deflector red o=1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 2) {

				this->tx.loadFromFile("pieces pics/deflector red o=2.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 3) {

				this->tx.loadFromFile("pieces pics/deflector red o=  3.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

		}

		//Sprite for the Defenders

		else if (this->type == "defender") {


			if (this->orientation == 0) {

				this->tx.loadFromFile("pieces pics/defender red.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {

				this->tx.loadFromFile("pieces pics/defender red o=1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 2) {

				this->tx.loadFromFile("pieces pics/defender red o=2.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 3) {

				this->tx.loadFromFile("pieces pics/defender red o=3.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

		}
		//Sprite for the Switches

		else if (this->type == "switch") {


			if (this->orientation == 0) {

				this->tx.loadFromFile("pieces pics/switch red.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

			else if (this->orientation == 1) {

				this->tx.loadFromFile("pieces pics/switch red o= 1.jpg");
				this->p.setTexture(tx);
				this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
			}

		}

		//Sprite fot the Kings

		else if (this->type == "king") {

			this->tx.loadFromFile("pieces pics/the king red.jpg");
			this->p.setTexture(tx);
			this->p.setOrigin(this->p.getLocalBounds().width / 2, this->p.getLocalBounds().height / 2);
		}


	}

}

void piece::rotate(bool clockwise)
{
	if (clockwise) {
		this->p.rotate(90);
		if (this->type == "deflector"||this->type=="defender") {
			this->orientation += 3;
			this->orientation %= 4;

		}

		
		else if (this->type == "switch"||this->type=="laser") {
			this->orientation += 1;
			this->orientation %= 2;
		}


	}
	else if (clockwise ==false) {
		this->p.rotate(-90);
	
		if (this->type == "deflector" || this->type == "defender") {
			this->orientation += 1;
			this->orientation %= 4;
		}


		else if (this->type == "switch" || this->type == "laser") {
			this->orientation += 1;
			this->orientation %= 2;
		}
	}
}

void piece::motion(int row, int col)
{
	this->position.first = row;

	this->position.second = col;
}

void piece::kill()
{
	this->p.setScale(0, 0);
	this->~piece();
}