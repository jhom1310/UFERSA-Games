/**********************************************************************************
// Background (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _PLATFORMER_BACKGROUND_H_
#define _PLATFORMER_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xB;                       // posi��o horizontal dos sprites
    Image * imgB;                       // imagem de fundo traseira    
    Sprite * backgB1;                   // pano de fundo din�mico (traseiro 1)
    Sprite * backgB2;                   // pano de fundo din�mico (traseiro 2)

public:
    Background();                       // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------
#endif