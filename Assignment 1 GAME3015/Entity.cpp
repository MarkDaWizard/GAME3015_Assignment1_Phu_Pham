#include "Entity.h"


	void Entity::setVelocity(XMFLOAT3 velocity) 
	{
		mVelocity = velocity; 
	}

	void Entity::setVelocity(float x, float y) 
	{ 
		mVelocity.x = x, mVelocity.y = y; 
	}

	XMFLOAT3 Entity::getVelocity() 
	{ 
		return mVelocity;
	}




