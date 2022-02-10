#include "Aircraft.h"

Aircraft::Aircraft(XMFLOAT3 position, XMFLOAT3 scale)
{
	Position = position;
	Scale = scale;

}

void Aircraft::Move(const GameTimer& gt)
{
	// W key for moving up
	if (d3dUtil::IsKeyDown(0x57))
	{
		Position.z += 0.02f;
	}

	// A key for moving left
	if (d3dUtil::IsKeyDown(0x41))
	{
		Position.x -= 0.02f;
	}

	// S key for moving down
	if (d3dUtil::IsKeyDown(0x53))
	{
		Position.z -= 0.02f;
	}

	// D key for moving right
	if (d3dUtil::IsKeyDown(0x44))
	{
		Position.x += 0.02f;
	}
}

void Aircraft::Update(const GameTimer& gt)
{
	Move(gt);
}
