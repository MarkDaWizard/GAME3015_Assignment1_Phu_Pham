//GAME3015-Assignment1-Phu-Pham
//10/2/2022
//Name: Phu Pham
//ID: 101250748
#include "World.h"

void World::buildWorld()
{
	//Player
	jet->Position = XMFLOAT3(0.0f, 0.1f, -30.0f);
	jet->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	//Enemies
	wingman1->Position = XMFLOAT3(10.0f, 0.1f, -35.0f);
	wingman1->Scale = XMFLOAT3(0.1f, 1.0f, 0.1f);

	wingman2->Position = XMFLOAT3(-10.0f, 0.1f, -35.0f);
	wingman2->Scale = XMFLOAT3(0.1f, 1.0f, 0.1f);

	//Trees
	tree->Position = XMFLOAT3(-20.0f, 1.1f, 10.0f);
	tree->Scale = XMFLOAT3(0.1f, 1.0f, 0.1f);

	tree2->Position = XMFLOAT3(-10.0f, 1.1f, -20.0f);
	tree2->Scale = XMFLOAT3(0.25f, 1.0f, 0.25f);

	tree3->Position = XMFLOAT3(0.0f, 1.1f, -40.0f);
	tree3->Scale = XMFLOAT3(0.3f, 1.0f, 0.3f);

	tree4->Position = XMFLOAT3(15.0f, 1.1f, -30.0f);
	tree4->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	tree5->Position = XMFLOAT3(20.0f, 1.1f, 0.0f);
	tree5->Scale = XMFLOAT3(0.4f, 1.0f, 0.4f);

	tree6->Position = XMFLOAT3(00.0f, 1.1f, 40.0f);
	tree6->Scale = XMFLOAT3(0.15f, 1.0f, 0.15f);

	//Enemies
	enemy->Position = XMFLOAT3(20.0f, 1.1f, 30.0f);
	enemy->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

	enemy2->Position = XMFLOAT3(-20.0f, 1.1f, 30.0f);
	enemy2->Scale = XMFLOAT3(0.2f, 1.0f, 0.2f);

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
	jet->Ritem->Mat = mMaterials["Jet2Mat"].get();
	jet->Ritem->Geo = mGeometries["shapeGeo"].get();
	jet->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	jet->Ritem->IndexCount = jet->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	jet->Ritem->StartIndexLocation = jet->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	jet->Ritem->BaseVertexLocation = jet->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(jet->Ritem.get());
	mAllRitems.push_back(std::move(jet->Ritem));
	AllEntities.push_back(jet);

	//Add wingman1
	wingman1->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&wingman1->Ritem->World, XMMatrixScaling(wingman1->Scale.x, wingman1->Scale.y, wingman1->Scale.z) * XMMatrixTranslation(wingman1->Position.x, wingman1->Position.y, wingman1->Position.z));
	wingman1->Ritem->ObjCBIndex = 2;
	wingman1->Ritem->Mat = mMaterials["Jet2Mat"].get();
	wingman1->Ritem->Geo = mGeometries["shapeGeo"].get();
	wingman1->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	wingman1->Ritem->IndexCount = wingman1->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	wingman1->Ritem->StartIndexLocation = wingman1->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	wingman1->Ritem->BaseVertexLocation = wingman1->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(wingman1->Ritem.get());
	mAllRitems.push_back(std::move(wingman1->Ritem));
	AllEntities.push_back(wingman1);	

	//Add wingman2
	wingman2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&wingman2->Ritem->World, XMMatrixScaling(wingman2->Scale.x, wingman2->Scale.y, wingman2->Scale.z) * XMMatrixTranslation(wingman2->Position.x, wingman2->Position.y, wingman2->Position.z));
	wingman2->Ritem->ObjCBIndex = 3;
	wingman2->Ritem->Mat = mMaterials["Jet2Mat"].get();
	wingman2->Ritem->Geo = mGeometries["shapeGeo"].get();
	wingman2->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	wingman2->Ritem->IndexCount = wingman2->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	wingman2->Ritem->StartIndexLocation = wingman2->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	wingman2->Ritem->BaseVertexLocation = wingman2->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(wingman2->Ritem.get());
	mAllRitems.push_back(std::move(wingman2->Ritem));
	AllEntities.push_back(wingman2);

	//Add Tree1
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

	//Add Tree2
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

	//Add Tree3
	tree3->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree3->Ritem->World, XMMatrixScaling(tree3->Scale.x, tree3->Scale.y, tree3->Scale.z)* XMMatrixTranslation(tree3->Position.x, tree3->Position.y, tree3->Position.z));
	tree3->Ritem->ObjCBIndex = 6;
	tree3->Ritem->Mat = mMaterials["treeMat"].get();
	tree3->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree3->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree3->Ritem->IndexCount = tree3->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree3->Ritem->StartIndexLocation = tree3->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree3->Ritem->BaseVertexLocation = tree3->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree3->Ritem.get());
	mAllRitems.push_back(std::move(tree3->Ritem));
	AllEntities.push_back(tree3);

	//Add Tree4
	tree4->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree4->Ritem->World, XMMatrixScaling(tree4->Scale.x, tree4->Scale.y, tree4->Scale.z)* XMMatrixTranslation(tree4->Position.x, tree4->Position.y, tree4->Position.z));
	tree4->Ritem->ObjCBIndex = 7;
	tree4->Ritem->Mat = mMaterials["treeMat"].get();
	tree4->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree4->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree4->Ritem->IndexCount = tree4->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree4->Ritem->StartIndexLocation = tree4->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree4->Ritem->BaseVertexLocation = tree4->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree4->Ritem.get());
	mAllRitems.push_back(std::move(tree4->Ritem));
	AllEntities.push_back(tree4);

	//Add Tree5
	tree5->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree5->Ritem->World, XMMatrixScaling(tree5->Scale.x, tree5->Scale.y, tree5->Scale.z)* XMMatrixTranslation(tree5->Position.x, tree5->Position.y, tree5->Position.z));
	tree5->Ritem->ObjCBIndex = 8;
	tree5->Ritem->Mat = mMaterials["treeMat"].get();
	tree5->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree5->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree5->Ritem->IndexCount = tree5->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree5->Ritem->StartIndexLocation = tree5->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree5->Ritem->BaseVertexLocation = tree5->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree5->Ritem.get());
	mAllRitems.push_back(std::move(tree5->Ritem));
	AllEntities.push_back(tree5);

	//Add Tree6
	tree6->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&tree6->Ritem->World, XMMatrixScaling(tree6->Scale.x, tree6->Scale.y, tree6->Scale.z)* XMMatrixTranslation(tree6->Position.x, tree6->Position.y, tree6->Position.z));
	tree6->Ritem->ObjCBIndex = 9;
	tree6->Ritem->Mat = mMaterials["treeMat"].get();
	tree6->Ritem->Geo = mGeometries["shapeGeo"].get();
	tree6->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	tree6->Ritem->IndexCount = tree6->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	tree6->Ritem->StartIndexLocation = tree6->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	tree6->Ritem->BaseVertexLocation = tree6->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(tree6->Ritem.get());
	mAllRitems.push_back(std::move(tree6->Ritem));
	AllEntities.push_back(tree6);

	//Add Enemy1
	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z)* XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 10;
	enemy->Ritem->Mat = mMaterials["JetMat"].get();
	enemy->Ritem->Geo = mGeometries["shapeGeo"].get();
	enemy->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	enemy->Ritem->IndexCount = enemy->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	enemy->Ritem->StartIndexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	enemy->Ritem->BaseVertexLocation = enemy->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(enemy->Ritem.get());
	mAllRitems.push_back(std::move(enemy->Ritem));
	AllEntities.push_back(enemy);

	//Add Enemy2
	enemy2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy2->Ritem->World, XMMatrixScaling(enemy2->Scale.x, enemy2->Scale.y, enemy2->Scale.z)* XMMatrixTranslation(enemy2->Position.x, enemy2->Position.y, enemy2->Position.z));
	enemy2->Ritem->ObjCBIndex = 11;
	enemy2->Ritem->Mat = mMaterials["JetMat"].get();
	enemy2->Ritem->Geo = mGeometries["shapeGeo"].get();
	enemy2->Ritem->PrimitiveType = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	enemy2->Ritem->IndexCount = enemy2->Ritem->Geo->DrawArgs["Grid"].IndexCount;
	enemy2->Ritem->StartIndexLocation = enemy2->Ritem->Geo->DrawArgs["Grid"].StartIndexLocation;
	enemy2->Ritem->BaseVertexLocation = enemy2->Ritem->Geo->DrawArgs["Grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(enemy2->Ritem.get());
	mAllRitems.push_back(std::move(enemy2->Ritem));
	AllEntities.push_back(enemy2);

}


void World::Update(const GameTimer& gt)
{
	//Updating movement for player, wingmans and enemies
	jet->Update(gt);
	wingman1->Update(gt);
	wingman2->Update(gt);
	enemy->Update(gt);
	enemy2->Update(gt);

	jet->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&jet->Ritem->World, XMMatrixScaling(jet->Scale.x, jet->Scale.y, jet->Scale.z) * XMMatrixTranslation(jet->Position.x, jet->Position.y, jet->Position.z));
	jet->Ritem->ObjCBIndex = 1;
	mAllRitems.push_back(std::move(jet->Ritem));

	wingman1->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&wingman1->Ritem->World, XMMatrixScaling(wingman1->Scale.x, wingman1->Scale.y, wingman1->Scale.z) * XMMatrixTranslation(wingman1->Position.x, wingman1->Position.y, wingman1->Position.z));
	wingman1->Ritem->ObjCBIndex = 2;
	mAllRitems.push_back(std::move(wingman1->Ritem));


	wingman2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&wingman2->Ritem->World, XMMatrixScaling(wingman2->Scale.x, wingman2->Scale.y, wingman2->Scale.z) * XMMatrixTranslation(wingman2->Position.x, wingman2->Position.y, wingman2->Position.z));
	wingman2->Ritem->ObjCBIndex = 3;
	mAllRitems.push_back(std::move(wingman2->Ritem));

	enemy->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy->Ritem->World, XMMatrixScaling(enemy->Scale.x, enemy->Scale.y, enemy->Scale.z) * XMMatrixTranslation(enemy->Position.x, enemy->Position.y, enemy->Position.z));
	enemy->Ritem->ObjCBIndex = 10;
	mAllRitems.push_back(std::move(enemy->Ritem));


	enemy2->Ritem = std::make_unique<RenderItem>();
	XMStoreFloat4x4(&enemy2->Ritem->World, XMMatrixScaling(enemy2->Scale.x, enemy2->Scale.y, enemy2->Scale.z) * XMMatrixTranslation(enemy2->Position.x, enemy2->Position.y, enemy2->Position.z));
	enemy2->Ritem->ObjCBIndex = 11;
	mAllRitems.push_back(std::move(enemy2->Ritem));

}
