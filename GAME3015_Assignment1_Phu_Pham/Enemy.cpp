//GAME3015-Assignment1-Phu-Pham
//10/2/2022
//Name: Phu Pham
//ID: 101250748
#include "Enemy.h"

Enemy::Enemy(XMFLOAT3 position, XMFLOAT3 scale)
{
	Position = position;
	Scale = scale;
}

void Enemy::Move(const GameTimer& gt)
{

	if (right) 	//Move right
	{
		Position.x += 0.02f;
	}
	else		//Move left
	{
		Position.x -= 0.02f;
	}
	//Check if past left/right bounds
	if (Position.x >= 50.0f)
	{
		right = false;
	}
	if (Position.x <= -50.0f)
	{
		right = true;
	}

}

void Enemy::Update(const GameTimer& gt)
{
	Move(gt);
}
