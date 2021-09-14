
#include "Winner.h"
#include "Engine.h"
#include "Home.h"


void Winner::Init() {
	backg = new Sprite("Resources/winner.png");
}

void Winner::Finalize() {
	delete backg;
}

void Winner::Update() {

	if (window->KeyDown('H'))
		Engine::Next<Home>();

	if (window->KeyDown(VK_ESCAPE))
		window->Close();

}

void Winner::Draw() {
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::FRONT);
}
