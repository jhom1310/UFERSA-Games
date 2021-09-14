#pragma once

#ifndef _PLATFORMER_GAMEOVER_H_
#define _PLATFORMER_GAMEOVER_H_

#include "Types.h"                      // tipos específicos da engine
#include "Game.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

class Gameover : public Game
{
private:
    Sprite* backg = nullptr;                   // pano de fundo dinâmico (traseiro 2)

public:

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};
// ---------------------------------------------------------------------------------
#endif
