
#include "Home.h"
#include "Engine.h"
#include "Level1.h"

void Home::Init() {
	backg = new Sprite("Resources/background_inicial.png");// definindo funo da tela home
	
														   //animate = new Sprite("Resources/animate.png"); 
	// Pequena animacao na tela para chamar atencao do jogador
}

void Home::Finalize() {
	delete backg;
	delete animate;
}

void Home::Update() {
	// sai do jogo com a tecla ESC
	if (ctrlKeyESC && window->KeyDown(VK_ESCAPE))
	{
		ctrlKeyESC = false;
		window->Close();
	}
	else if (window->KeyUp(VK_ESCAPE))
	{
		ctrlKeyESC = true;
	}

	// passa ao primeiro nível com ENTER
	if (window->KeyDown(VK_RETURN))
		Engine::Next<Level1>();
		//window->Close();
		
}

void Home::Draw()
{
	backg->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}
