
#include "Gameover.h"
#include "Engine.h"
#include "Home.h"


void Gameover::Init() {
	backg = new Sprite("Resources/gameover.png");
}

void Gameover::Finalize() {
	delete backg;
}

void Gameover::Update() {

	if (window->KeyDown('H'))
		Engine::Next<Home>();
	
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

}

void Gameover::Draw() {
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::FRONT);
}
