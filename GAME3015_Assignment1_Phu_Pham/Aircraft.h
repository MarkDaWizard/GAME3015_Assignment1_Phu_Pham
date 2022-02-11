//GAME3015-Assignment1-PhuPham
//Name:Phu Pham
//ID:101250748
//Last Updated: 11/2/2022

#pragma once

#include "Entity.h"

/// <summary>
/// Enemy class, derived from Entity
/// </summary>
class Aircraft	:
	public Entity
{
public:
	Aircraft();
	~Aircraft();

private:
	float	m_Dir;

public:
	virtual void Update(float DeltaTime, struct FrameResource* Frame);
	virtual void Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime);
};

