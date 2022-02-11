#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update(float DeltaTime, FrameResource* Frame)
{
	Entity::Update(DeltaTime, Frame);
}

void Player::Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime)
{
	Entity::Draw(CmdList, DeltaTime);
}
