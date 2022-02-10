#pragma once
#include "Entity.h"
#include "Common/d3dUtil.h"
#include "Common/GameTimer.h"
class Aircraft : public Entity
{
public:
	Aircraft() {};
	Aircraft(XMFLOAT3 position, XMFLOAT3 scale);
	void Move(const GameTimer& gt);

	void Update(const GameTimer& gt);
};

