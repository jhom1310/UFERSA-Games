#pragma once

#ifndef _PLATFORMER_ENEMY_H_
#define _PLATFORMER_ENEMY_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------
enum EnemyType{FIRE, MACHINE};

class Enemy : public Object
{
private:
    float moveEnemy;   
    Image* img = nullptr;
    Sprite* enemy = nullptr;
    Sprite* copyEnemy = nullptr;
    int typeEnemy;

public:
    Enemy(float posX, float posY, uint typeEnemy);                       // construtor
    ~Enemy();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif