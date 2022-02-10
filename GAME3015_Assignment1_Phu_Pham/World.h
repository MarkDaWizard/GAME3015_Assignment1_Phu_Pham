#pragma once
#include <string>
#include <map>
#include <vector>
#include "Aircraft.h"
#include "Wingman.h"
//GAME3015-Assignment1-Phu-Pham
//10/2/2022
//Name: Phu Pham
//ID: 101250748
#include "Enemy.h"
class World
{
public:
	std::vector<Entity*> AllEntities;

	std::map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;
	std::map<std::string, std::unique_ptr<Material>> mMaterials;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;
	// Render items divided by PSO.
	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	//Player Class
	Aircraft* jet = new Aircraft();

	//Wingman Class
	Wingman* wingman1 = new Wingman();
	Wingman* wingman2 = new Wingman();

	//Enemy Class
	Enemy* enemy = new Enemy();
	Enemy* enemy2 = new Enemy();

	// Reusing wingman class for trees
	Wingman* tree = new Wingman();
	Wingman* tree2 = new Wingman();
	Wingman* tree3 = new Wingman();
	Wingman* tree4 = new Wingman();
	Wingman* tree5 = new Wingman();
	Wingman* tree6 = new Wingman();
	void buildWorld();

	void Update(const GameTimer& gt);
};

