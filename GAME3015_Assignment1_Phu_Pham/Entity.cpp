#include "Entity.h"

Entity::Entity()	:
	m_MoveSpeed(1.f)
{
	m_Render = true;
}

Entity::~Entity()
{
}

void Entity::Update(float DeltaTime, struct FrameResource* Frame)
{
	SceneNode::Update(DeltaTime, Frame);
}

void Entity::Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime)
{
	SceneNode::Draw(CmdList, DeltaTime);
}
