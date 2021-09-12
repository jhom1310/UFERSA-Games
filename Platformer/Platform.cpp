/**********************************************************************************
// Platform (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType, bool move)
{
    if (platType == LARGE) {
        platform = new Sprite("Resources/tronco2.png");
    }
    else if (platType == SMALL) {
        platform = new Sprite("Resources/tronco.png");
    }
    else if (platType == GALHO) {
        platform = new Sprite("Resources/galho.png");
    }
    else {
        platform = new Sprite("Resources/BackgFront2.png");
    }
    
 
    BBox(new Rect(-1.0f * platform->Width() / 2.0f,
        -1.0f * platform->Height() / 2.0f,
        +1.0f * platform->Width() / 2.0f,
        +1.0f * platform->Height() / 2.0f));

    move_x = 0;

    moving = move;

    MoveTo(posX, posY);
    type = object;
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;  
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    if(moving)
        Translate(-200.0f * gameTime, 0);

    if (x < 0)
        MoveTo(window->Width()+30, y);
}
// -------------------------------------------------------------------------------

void Platform::Draw()
{
    platform->Draw(x, y, z);
}

// -------------------------------------------------------------------------------