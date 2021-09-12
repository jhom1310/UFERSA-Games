
#include "Level1.h"
#include "Platform.h"
#include "Engine.h"
#include "Home.h"

void Level1::Init() 
{
    // cria cena do jogo
    scene = new Scene();

	backg = new Background();
	scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    int space_between = 150;

    Platform* plat = new Platform(window->Width(), window->CenterY(), SMALL, true);
    scene->Add(plat, STATIC);

    //plat = new Platform(window->Width() + 150 / 2.0f, window->Height(), FIRE, false);
    //plat->MoveTo((window->Width() / 2.0f) + 150, window->Height() - (plat->Height() / 2.0f));
    //scene->Add(plat, STATIC);

    //plat = new Platform(window->Width() / 2.0f, 0 , GALHO, true);
    //plat->MoveTo((window->Width() / 2.0f) + 250, 100);
    //scene->Add(plat, STATIC);
}

void Level1::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (window->KeyDown('B') && onclick) {
        view_bb = !view_bb;
        onclick = false;
    }
    else {
        onclick = true;
    }

    if(window->KeyDown('H'))// reinicia o level
        Engine::Next<Home>();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();
}

void Level1::Draw()
{
    scene->Draw();
    if(view_bb)
        scene->DrawBBox();
}


void Level1::Finalize()
{
    delete scene;
}