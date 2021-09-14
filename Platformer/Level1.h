#pragma once

#ifndef _PLATFORMER_LEVEl1_H_
#define _PLATFORMER_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Background* backg = nullptr;       // background
    Scene* scene = nullptr;       // gerenciador de cena
    Player* player = nullptr;

    bool onclick = false;
    bool view_bb = false;

    //bool viewBBox = false;          // habilita visualização da bounding box
    //bool ctrlKeyB = false;          // controle da tecla B

public:

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif