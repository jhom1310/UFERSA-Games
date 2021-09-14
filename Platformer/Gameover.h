#pragma once

#ifndef _PLATFORMER_GAMEOVER_H_
#define _PLATFORMER_GAMEOVER_H_

#include "Types.h"                      // tipos espec�ficos da engine
#include "Game.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

class Gameover : public Game
{
private:
    Sprite* backg = nullptr;                   // pano de fundo din�mico (traseiro 2)

public:

    void Init();                    // inicializa��o
    void Update();                  // atualiza��o
    void Draw();                    // desenho
    void Finalize();                // finaliza��o
};
// ---------------------------------------------------------------------------------
#endif
