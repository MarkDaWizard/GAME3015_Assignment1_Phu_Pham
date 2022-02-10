#pragma once
#include "SceneNode.h"
#include <memory>
#include "RenderItem.h"
class Entity : public SceneNode
{
public:
	std::unique_ptr<RenderItem> Ritem;

	void setVelocity(XMFLOAT3 velocity);
	void setVelocity(float x, float y);
	XMFLOAT3 getVelocity();

private:
	XMFLOAT3 mVelocity;

};

