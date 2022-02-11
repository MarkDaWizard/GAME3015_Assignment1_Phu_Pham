#include "Aircraft.h"

Aircraft::Aircraft()
{
	m_MoveSpeed = 50.f;
	m_Dir = 1.f;
}

Aircraft::~Aircraft()
{
}

void Aircraft::Update(float DeltaTime, FrameResource* Frame)
{
	Entity::Update(DeltaTime, Frame);

	m_Pos.x += m_MoveSpeed * m_Dir * DeltaTime;

	if (m_Pos.x >= 45.f)
	{
		m_Pos.x = 45.f;
		m_Dir = -1.f;
	}

	else if (m_Pos.x <= -45.f)
	{
		m_Pos.x = -45.f;
		m_Dir = 1.f;
	}
}

void Aircraft::Draw(ID3D12GraphicsCommandList* CmdList, float DeltaTime)
{
	Entity::Draw(CmdList, DeltaTime);
}
