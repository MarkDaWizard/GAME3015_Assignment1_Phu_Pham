#pragma once

#include "Entity.h"

/// <summary>
/// A plane that will act as an enemy character
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

