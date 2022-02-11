#pragma once

#include "Entity.h"
/// <summary>
/// Player character that will be controllable by the user. Currently, inputs are in progress
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

