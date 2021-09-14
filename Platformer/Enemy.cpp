
#include "Enemy.h"

// ---------------------------------------------------------------------------------

Enemy::Enemy(uint posX, uint posY, uint typeEnemy)
{
	typeEnemy = typeEnemy;
	switch (typeEnemy) { // define o tipo do inimigo que sera criado
		case FIRE:
			moveEnemy = x;
			
			img = new Image("Resources/BackgFront2.png");
			
			enemy = new Sprite(img);
			copyEnemy = new Sprite(img);
		
			BBox(new Rect(-1.0f * enemy->Width() / 2.0f,
				-1.0f * enemy->Height() / 2.0f,
				+1.0f * enemy->Width() / 2.0f,
				+1.0f * enemy->Height() / 2.0f));

			/*BBox(new Rect(-1.0f * copyEnemy->Width() / 2.0f,
				-1.0f * copyEnemy->Height() / 2.0f,
				+1.0f * copyEnemy->Width() / 2.0f,
				+1.0f * copyEnemy->Height() / 2.0f));*/

			
			break;
		case MACHINE:
			break;
	}

	MoveTo(posX-(enemy->Width()/2), posY); // defino a posicao em que vai ocorrer a colisao, como a posicao e constante basta deixa-lo fixo
	type = ObjectType::ENEMY;
}

// ---------------------------------------------------------------------------------

Enemy::~Enemy()
{
	switch (typeEnemy)
	{
	case FIRE:
		delete img;
		delete enemy;
		delete copyEnemy;
		break;
	case MACHINE:
		break;
	}
}

// -------------------------------------------------------------------------------

void Enemy::Update()
{
	switch (typeEnemy)
	{
		case FIRE: 
			moveEnemy -= 150 * gameTime; 
			
			break;
		case MACHINE:
			break;
	}
	
}
// -------------------------------------------------------------------------------

void Enemy::Draw()
{
	switch (typeEnemy) {
	case FIRE:
		enemy->Draw(moveEnemy, y, Layer::FRONT);
		copyEnemy->Draw(moveEnemy + img->Width(), y, Layer::FRONT);

		// traz pano de fundo de volta para dentro da tela
		if (moveEnemy + img->Width() / 2.0f < 0)
			moveEnemy += img->Width();
		
		break;

	case MACHINE:
		break;
	}
}

// -------------------------------------------------------------------------------