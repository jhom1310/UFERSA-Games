
#include "Level1.h"
#include "Platform.h"

void Level1::Init() 
{
    // cria cena do jogo
    scene = new Scene();

	backg = new Background();
	scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    Platform* plat = new Platform(window->Width() / 2.0f, window->Height(), LARGE);
    scene->Add(plat, STATIC);

    plat = new Platform(0, 0, LARGE); // esse objeto é adicionado como forma de deixar independente o player
    plat->MoveTo(0, -plat->Height()+1); // coloca o elemento em uma posicao 1 na altura
    scene->Add(plat, STATIC);

    onclick = false;
    view_BB = false;
}

void Level1::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    if (window->KeyDown('B') && onclick) {
        view_BB = !view_BB;
        onclick = false;
    }
    else {
        onclick = true;
    }

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();
}

void Level1::Draw()
{
    scene->Draw();
    if(view_BB)
        scene->DrawBBox();
}


void Level1::Finalize()
{
    delete scene;
}