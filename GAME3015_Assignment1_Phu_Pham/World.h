#pragma once

#include "Entity.h"
#include "Player.h"
#include "Aircraft.h"

/// <summary>
/// World.h and World.cpp scripts are where the game scene is built and rendered.
/// </summary>

class World
{
public:
	World();
	~World();

public:
	SceneNode* m_RootNode;

	std::map<std::string, std::unique_ptr<Material>> mMaterials;
	std::list<SceneNode*>	m_RenderList;
	std::unique_ptr<MeshGeometry>	m_Mesh;

	Entity* Terrain1= new Entity;
	Entity* Terrain2 = new Entity;


	Entity* Wingman1 = new Player;
	Entity* Wingman2 = new Player;

	Aircraft* Enemy = new Aircraft;
	Player* player = new Player;

	void buildWorld(ID3D12Device* Device, ID3D12GraphicsCommandList* CmdList);

	void Update(float DeltaTime, struct FrameResource* Frame);
	void Draw(ID3D12GraphicsCommandList* CmdList, ID3D12DescriptorHeap* Desc,
		UINT DescSize, struct FrameResource* Frame, float DeltaTime);
};

