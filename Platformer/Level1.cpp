

//---------------------Bibliotecas----------------------

#include "Level1.h"
#include "Platform.h"
#include "Engine.h"
#include "Home.h"
#include "Enemy.h"

//------------------------------------------------------

void Level1::Init() 
{
    // cria cena do jogo
    scene = new Scene();
 
	backg = new Background();
	scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    int space_between = 150;

    Platform* plat = new Platform(window->Width(), window->CenterY()+75, LARGE, true);
    scene->Add(plat, STATIC);

    Enemy* enemy = new Enemy(window->Width(), window->Height()-75, EnemyType::FIRE);
    scene->Add(enemy, STATIC);

    plat = new Platform(window->Width() + 300, 100 , GALHO, true);
    scene->Add(plat, STATIC);

    
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
    else if (window->KeyDown('B')){
        onclick = true;
    }
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