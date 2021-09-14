

//---------------------Bibliotecas----------------------

#include "Level1.h"
#include "Platform.h"
#include "Engine.h"
#include "Home.h"
#include "Enemy.h"
#include "Player.h"
#include "Gameover.h"
#include "Winner.h"

//------------------------------------------------------

void Level1::Init() 
{
    // cria cena do jogo
    scene = new Scene();
 
	backg = new Background();
	//scene->Add(backg, STATIC);

    player = new Player();
    scene->Add(player, MOVING);

    Enemy* enemy = new Enemy(window->Width(), window->Height() - 10, EnemyType::FIRE);
    scene->Add(enemy, STATIC);
    
    int spaceBetween = 150; // media dos espacos entre os objetos que aparecem na tela

    int bufferPositionX = window->Width();

    Platform* plat = new Platform(bufferPositionX, window->CenterY()+85, PLATTYPES::SMALL, true);
    scene->Add(plat, STATIC);

    bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, 40 , PLATTYPES::GALHO, true);
    scene->Add(plat, STATIC);

    bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, window->CenterY() + 85, PLATTYPES::SMALL, true);
    scene->Add(plat, STATIC);
    
    //bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, 40, PLATTYPES::GALHO, true);
    scene->Add(plat, STATIC);

    bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, window->CenterY() + 30, PLATTYPES::LARGE, true);
    scene->Add(plat, STATIC);

    bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, window->CenterY() + 85, PLATTYPES::SMALL, true);
    scene->Add(plat, STATIC);

    //bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, 40, PLATTYPES::GALHO, true);
    scene->Add(plat, STATIC);

    bufferPositionX += plat->Width() + spaceBetween;

    plat = new Platform(bufferPositionX, window->CenterY() + 85, PLATTYPES::SMALL, true);
    scene->Add(plat, STATIC);
}

void Level1::Update()
{
    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();
    backg->Update();

    if (window->KeyDown('B') && onclick) {
        view_bb = !view_bb;
        onclick = false;
    }
    else if (window->KeyDown('B')) {
        onclick = true;
    }

    // retornao ao menu com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        Engine::Next<Home>();
    else if (player->CollidedEnemy())
        Engine::Next<Gameover>();
    else if (player->Score()>=10)
        Engine::Next<Winner>();
}

void Level1::Draw()
{
    backg->Draw();
    scene->Draw();
    if(view_bb)
        scene->DrawBBox();
}


void Level1::Finalize()
{
    delete backg;
    delete scene;
}