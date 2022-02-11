//GAME3015-Assignment1-PhuPham
//Name:Phu Pham
//ID:101250748
//Last Updated: 11/2/2022
#include "Entity.h"

Entity::Entity()	:
	m_MoveSpeed(0.5f)
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
