/**********************************************************************************
// Platform (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Platform.h"

// ---------------------------------------------------------------------------------

Platform::Platform(float posX, float posY, uint platType)
{
    platform = new Sprite("Resources/BackgFront2.png");

 
    BBox(new Rect(-1.0f * platform->Width() / 2.0f,
        -1.0f * platform->Height() / 2.0f,
        +1.0f * platform->Width() / 2.0f,
        +1.0f * platform->Height() / 2.0f));

    MoveTo(posX, posY);
}

// ---------------------------------------------------------------------------------

Platform::~Platform()
{
    delete platform;
   // delete bbox;
    
}

// -------------------------------------------------------------------------------

void Platform::Update()
{
    Translate(-200.0f * gameTime, 0);
    // desenha prédios mais próximos
    platform->Draw(xF, y, Layer::MIDDLE);
    platform->Draw(xF + platform->Width(), window->Height()/2.0f, Layer::MIDDLE);

   // traz pano de fundo de volta para dentro da tela
   if (xF + platform->Width()/2.0f < 0)
       xF += platform->Width();
    
}

// -------------------------------------------------------------------------------
