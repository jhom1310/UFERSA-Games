/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 02 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _PLATFORMER_PLATFORM_H_
#define _PLATFORMER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

enum PLATTYPES { SMALL, LARGE, GALHO };

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
    Sprite * platform = nullptr;        // sprite da plataforma
    bool moving;

public:
    Platform(float posX, float posY, uint platType,bool move);    
    ~Platform();

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
    int Height();
    int Width();
}; 

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline



inline int Platform::Height() { return platform->Height(); }
inline int Platform::Width() { return platform->Width(); }

// ---------------------------------------------------------------------------------

#endif