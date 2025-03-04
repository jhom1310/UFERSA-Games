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

Platform::Platform(uint posX, uint posY, uint platType, bool move)
{
    if (platType == LARGE) {
        platform = new Sprite("Resources/tronco2.png");
        BBox(new Rect((-1.0f * platform->Width() / 2.0f)+10,
            (-1.0f * platform->Height() / 2.0f) + 15,
            (+1.0f * platform->Width() / 2.0f)-10,
            +1.0f * platform->Height() / 2.0f));
    }
    else if (platType == SMALL) {
        platform = new Sprite("Resources/tronco.png");
        BBox(new Rect((-1.0f * platform->Width() / 2.0f) + 10,
            (-1.0f * platform->Height() / 2.0f)+15,
            (+1.0f * platform->Width() / 2.0f)-10,
            +1.0f * platform->Height() / 2.0f));
    }
    else if (platType == GALHO) {
        platform = new Sprite("Resources/galho1.png");
        BBox(new Rect(-1.0f * platform->Width() / 2.0f,
            -1.0f * platform->Height() / 2.0f,
            +1.0f * platform->Width() / 2.0f,
            +1.0f * platform->Height() / 2.0f));
    }
    
 
    

    moving = move;

    MoveTo(posX, posY);
    type = ObjectType::BLOCK;
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
        Translate(-160.0f * gameTime, 0);

    if (x < 0)
        MoveTo(window->Width(), y);
}
// -------------------------------------------------------------------------------

void Platform::Draw()
{
    platform->Draw(x, y, z);
}

// -------------------------------------------------------------------------------