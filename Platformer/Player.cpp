/**********************************************************************************
// Player (Código Fonte)
// 
// Criação:     20 Abr 2012
// Atualização: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Define uma classe para o jogador
//
**********************************************************************************/

#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/bird2.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

   
    BBox(new Rect(-1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        +1.0f * tileset->TileWidth() / 2.0f,
        +1.0f * tileset->TileHeight() / 2.0f));

    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);

    uint seqNormal[4] = { 1,2,3,4 };
    uint seqInvert[4] = { 6,7,8,9 };
    
    anim->Add(INVERTED, seqInvert, 4);
    anim->Add(NORMAL, seqNormal, 4);

    
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete tileset;
    delete anim;
    //delete bbox;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    // mantém personagem na posição correta em cima da plataforma
    if (gravity == NORMAL)
        MoveTo(window->CenterX(), obj->Y() - 32);
    else
        MoveTo(window->CenterX(), obj->Y() + 32);
    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();

    // ação da gravidade sobre o personagem
    if (gravity == NORMAL)
        Translate(0, 100 * gameTime);
    else
        Translate(0, -100 * gameTime);

    if (keyCtrl && window->KeyDown(VK_SPACE))
    {
        keyCtrl = false;
        gravity = !gravity;
        // tira player da plataforma para evitar
        // detecção de colisão no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0, -50);
        gravity = !gravity;
    }
    else if (window->KeyUp(VK_SPACE))
    {
        keyCtrl = true;
    }

    // mantém personagem dentro da tela
    if (x + tileset->TileWidth() / 2.0f > window->Width())
        MoveTo(window->Width() - tileset->TileWidth() / 2.0f, y);

    if (x - tileset->TileWidth() / 2.0f < 0)
        MoveTo(tileset->TileWidth() / 2.0f, y);

    if (y + tileset->TileHeight() / 2.0f > window->Height())
        MoveTo(x, window->Height() - tileset->TileHeight() / 2.0f);

    if (y - tileset->TileHeight() / 2.0f < 0)
        MoveTo(x, tileset->TileHeight() / 2.0f);

}

// ---------------------------------------------------------------------------------