#include "World.h"

void World::buildWorld()
{
	//Player
	jet->Position = XMFLOAT3(0.0f, 0.1f, -30.0f);
	jet->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	//Enemies
	enemy->Position = XMFLOAT3(10.0f, 1.1f, 20.0f);
	enemy->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	enemy2->Position = XMFLOAT3(-10.0f, 1.1f, 20.0f);
	enemy2->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	//Trees
	tree->Position = XMFLOAT3(-10.0f, 1.1f, -20.0f);
	tree->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	tree2->Position = XMFLOAT3(10.0f, 1.1f, -20.0f);
	tree2->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	auto landRitem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&landRitem->World, XMMatrixScaling(2.5f, 1.0f, 2.5f) * XMMatrixTranslation(0.0f, 0.0f, 0.0f));
	landRitem->ObjCBIndex = 0;
	landRitem->Mat = mMaterials["LandMat"].get();
	landRitem->Geo = mGeometries["shapeGeo"].get();
	//landRitem->World = MathHelper::Identity4x4();
	landRitem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	landRitem->IndexCount = landRitem->Geo->DrawArgs["Grid"].IndexCount;
	landRitem->StartIndexLocation = landRitem->Geo->DrawArgs["Grid"].StartIndexLocation;
	landRitem->BaseVertexLocation = landRitem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Opaque].push_back(landRitem.get());
	mAllRitems.push_back(std::move(landRitem));

	//Add player
	jet->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(jet->Scale.x, jet->Scale.y, jet->Scale.z) * XMMatrixTranslation(jet->Position.x, jet->Position.y, jet->Position.z));
	jet->Ritem->ObjCBIndex = 1;
	jet->Ritem->Mat = mMaterials["JetMat"].get();
	jet->Ritem->Geo = mGeometries["shapeGeo"].get();
	jet->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	jet->Ritem->IndexCount = jet->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	jet->Ritem->StartIndexLocation = jet->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	jet->Ritem->BaseVertexLocation = jet->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(jet->Ritem.get());
	mAllRitems.push_back(std::move(jet->Ritem));
	AllEntities.push_back(jet);

	//Add enemy1
	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z) * XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 2;
	enemy->Ritem->Mat = mMaterials["Jet2Mat"].get();
	enemy->Ritem->Geo = mGeometries["shapeGeo"].get();
	enemy->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	enemy->Ritem->IndexCount = enemy->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	enemy->Ritem->StartIndexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	enemy->Ritem->BaseVertexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(enemy->Ritem.get());
	mAllRitems.push_back(std::move(enemy->Ritem));
	AllEntities.push_back(enemy);	

	//Add enemy2
	enemy2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy2->Ritem->World, XMMatrixScaling(enemy2->Scale.x, enemy2->Scale.y, enemy2->Scale.z) * XMMatrixTranslation(enemy2->Position.x, enemy2->Position.y, enemy2->Position.z));
	enemy2->Ritem->ObjCBIndex = 3;
	enemy2->Ritem->Mat = mMaterials["Jet2Mat"].get();
	enemy2->Ritem->Geo = mGeometries["shapeGeo"].get();
	enemy2->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	enemy2->Ritem->IndexCount = enemy2->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	enemy2->Ritem->StartIndexLocation = enemy2->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	enemy2->Ritem->BaseVertexLocation = enemy2->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(enemy2->Ritem.get());
	mAllRitems.push_back(std::move(enemy2->Ritem));
	AllEntities.push_back(enemy2);

	//Add tree1
	tree->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree->Ritem->World, XMMatrixScaling(tree->Scale.x, tree->Scale.y, tree->Scale.z) * XMMatrixTranslation(tree->Position.x, tree->Position.y, tree->Position.z));
	tree->Ritem->ObjCBIndex = 4;
	tree->Ritem->Mat = mMaterials["treeMat"].get();
	tree->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree->Ritem->IndexCount = tree->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree->Ritem->StartIndexLocation = tree->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree->Ritem->BaseVertexLocation = tree->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree->Ritem.get());
	mAllRitems.push_back(std::move(tree->Ritem));
	AllEntities.push_back(tree);

	//Add tree2
	tree2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree2->Ritem->World, XMMatrixScaling(tree2->Scale.x, tree2->Scale.y, tree2->Scale.z) * XMMatrixTranslation(tree2->Position.x, tree2->Position.y, tree2->Position.z));
	tree2->Ritem->ObjCBIndex = 5;
	tree2->Ritem->Mat = mMaterials["treeMat"].get();
	tree2->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree2->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree2->Ritem->IndexCount = tree2->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree2->Ritem->StartIndexLocation = tree2->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree2->Ritem->BaseVertexLocation = tree2->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree2->Ritem.get());
	mAllRitems.push_back(std::move(tree2->Ritem));
	AllEntities.push_back(tree2);

}


void World::Update(const GameTimer& gt)
{
	jet->Update(gt);
	enemy->Update(gt);
	enemy2->Update(gt);

	jet->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(jet->Scale.x, jet->Scale.y, jet->Scale.z) * XMMatrixTranslation(jet->Position.x, jet->Position.y, jet->Position.z));
	jet->Ritem->ObjCBIndex = 1;
	mAllRitems.push_back(std::move(jet->Ritem));

	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z) * XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 2;
	mAllRitems.push_back(std::move(enemy->Ritem));


	enemy2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy2->Ritem->World, XMMatrixScaling(enemy2->Scale.x, enemy2->Scale.y, enemy2->Scale.z) * XMMatrixTranslation(enemy2->Position.x, enemy2->Position.y, enemy2->Position.z));
	enemy2->Ritem->ObjCBIndex = 3;
	mAllRitems.push_back(std::move(enemy2->Ritem));

}
