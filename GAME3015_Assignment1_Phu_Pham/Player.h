//GAME3015-Assignment1-PhuPham
//Name:Phu Pham
//ID:101250748
//Last Updated: 11/2/2022
#pragma once

#include "Entity.h"
/// <summary>
/// Player class, derived from entity
/// </summary>
class Player	:
	public Entity
{
public:
	Player();
	~Player();

public:
	virtual void Update(float DeltaTime, struct FrameResource* Frame);
	virtual void Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime);
};

