#pragma once
#include "SceneNode.h"
#include "FrameResource.h"

/// <summary>
/// Game elements in the world.
/// </summary>
class Entity	:
	public SceneNode
{
	friend class World;

public:
	Entity();
	~Entity();
		
protected:
	float	m_MoveSpeed;

public:
	virtual void Update(float DeltaTime, struct FrameResource* Frame);
	virtual void Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime);
};

