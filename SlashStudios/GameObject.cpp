#include "GameObject.h"
#include <iostream>

GameObject::GameObject()
{
	//node = 0;
}

GameObject::GameObject(vector3df position, vector3df whd)
{
	node = 0;
	g_position=position;
	CreateAABB(position, whd);
}

//GameObject::GameObject(io::path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, ISceneManager* smgr, bool inside, int AItype)
GameObject::GameObject(path modelPath, vector3df position, vector3df rotation, float scale, bool createCollision, ISceneManager* smgr)
{
	node = 0;

	node = (IAnimatedMeshSceneNode*)smgr->addAnimatedMeshSceneNode(smgr->getMesh(modelPath),0);
	
	SetPosition(position);
	SetRotation(rotation);
	SetScale(scale);
	for (unsigned int i = 0; i < node->getMaterialCount(); i++)
	{
		node->getMaterial(i).Lighting=false;
		node->getMaterial(i).NormalizeNormals=false;
	}
	
	if(createCollision)
		CreateAABB();

}


void GameObject::SetPosition(vector3df newPos)
{
	g_position=newPos;
	node->setPosition(g_position);
}


void GameObject::SetOldPosition(vector3df newOldPos)
{
	g_oldPosition = newOldPos;
}

vector3df GameObject::GetPosition()
{
	if (node != 0)
		return node->getPosition();
	else
		return g_position;
}

void GameObject::SetRotation(vector3df newRot)
{
	g_rotation=newRot;
	node->setRotation(g_rotation);
	//aabb.
}

vector3df GameObject::GetRotation()
{
	return g_rotation;
}

void GameObject::SetScale(float newScale)
{
	g_scale = newScale;
	node->setScale(vector3df(newScale));
}

float GameObject::GetScale()
{
	return g_scale;
}

void GameObject::SetInteractor(GameObject* i)
{
	interactor = i;
}
void GameObject::SetInteractee(GameObject* i)
{
	interactee = i;
}

ISceneNode* GameObject::GetNode()
{
	return node;
}

void GameObject::CreateAABB()
{
	vector3df tmpMin;
	vector3df tmpMax;
	aabbox3df tmpAABB;
	vector3d<f32>* edges = new vector3d<f32>[8];
	tmpMin = ((IAnimatedMeshSceneNode*)node)->getMesh()->getBoundingBox().MinEdge*GetScale();
	tmpMax = ((IAnimatedMeshSceneNode*)node)->getMesh()->getBoundingBox().MinEdge*GetScale();
	aabb=aabbox3df(tmpMin,tmpMax);
	aabb.getEdges(edges);
}

void GameObject::CreateAABB(vector3df position, vector3df whd)
{
	vector3d<f32>* edges = new vector3d<f32>[8];
	vector3df aabbMins = vector3df(position.X - whd.X / 2, position.Y - whd.Y / 2, position.Z - whd.Z / 2);
	vector3df aabbMaxs = vector3df(position.X + whd.X / 2, position.Y + whd.Y / 2, position.Z + whd.Z / 2);

	aabb = aabbox3d<f32>(aabbMins, aabbMaxs);
	aabb.getEdges(edges);
}

void GameObject::Update(list<GameObject*> gos)
{

}

void GameObject::Interact(GameObject* ninteractor)
{

}

bool GameObject::CheckCollision(GameObject* other)
{
	vector3df thisPos = GetPosition();
	vector3df otherPos = other->GetPosition();
	aabbox3df thisAABB = GetAABB();
	aabbox3df otherAABB = other->GetAABB();

	float TxDistBy2 = (thisAABB.MaxEdge.X-thisAABB.MinEdge.X)/2;
	float TyDistBy2 = (thisAABB.MaxEdge.Y-thisAABB.MinEdge.Y)/2;
	float TzDistBy2 = (thisAABB.MaxEdge.Z-thisAABB.MinEdge.Z)/2;
	
	float OxDistBy2 = (otherAABB.MaxEdge.X-otherAABB.MinEdge.X)/2;	
	float OyDistBy2 = (otherAABB.MaxEdge.Y-otherAABB.MinEdge.Y)/2;
	float OzDistBy2 = (otherAABB.MaxEdge.Z-otherAABB.MinEdge.Z)/2;

	if(thisPos.X + TxDistBy2/2<otherPos.X - OxDistBy2/2 || otherPos.X + OxDistBy2/2<thisPos.X - TxDistBy2/2)
	{
		return false;
	}
	//if (thisPos.Y + TyDistBy2 / 2<otherPos.Y - OyDistBy2 / 2 || otherPos.Y + OyDistBy2 / 2<thisPos.Y - TyDistBy2 / 2)
	//{
	//	return false;
	//}
	if(thisPos.Z + TzDistBy2/2<otherPos.Z - OzDistBy2/2 || otherPos.Z + OzDistBy2/2<thisPos.Z - TzDistBy2/2)
	{
		return false;
	}
	return true;
}

void GameObject::AddAffordance(std::string affName, float affVal)
{
	affordances.push_back(new Affordance(affName,affVal));
}

bool GameObject::MatchAffordances(GameObject* other)
{
	for (size_t i = 0; i < affordances.size(); i++)
	{
		for (size_t j = 0; j < other->affordances.size(); j++)
		{
			//cout << affordances[i]->GetName() << ": " << affordances[i]->GetValue() << "    " << other->affordances[j]->GetName() << ": " << other->affordances[j]->GetValue() << endl;
			if (affordances[i]->Compare(other->affordances[j]))
			{
				return true;
			}
		}
	}

	return false;
}