/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xB = x;

    // carrega imagens
    imgB = new Image("Resources/BackgBack21.png");

    // cria sprites do plano de fundo
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete imgB;    
    delete backgB1;
    delete backgB2;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
    xB -= 150 * gameTime;
}

// -------------------------------------------------------------------------------

void Background::Draw()
{

    // desenha prédios mais distantes
    backgB1->Draw(xB, y, Layer::LOWER);
    backgB2->Draw(xB + imgB->Width(), y, Layer::LOWER);
    
    // traz pano de fundo de volta para dentro da tela
    if (xB + imgB->Width()/2.0f < 0)
        xB += imgB->Width();
}

// -------------------------------------------------------------------------------