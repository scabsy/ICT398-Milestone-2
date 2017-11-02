#include "irrlicht.h"
#include "driverChoice.h"
#include "GameObject.h"
#include "Person_Machine.h"
#include "Person_Cardio.h"
#include "Person_FreeWeight.h"
#include "Weight.h"
#include "Treadmill.h"
#include "Machine.h"
#include "Camera.h"
#include "InputReceiver.h"
#include <iostream>

using namespace std;
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

//GLOBAL VARS
IrrlichtDevice* device;
IVideoDriver* driver;
ISceneManager* smgr;
IGUIEnvironment* guienv; 

//ICameraSceneNode* camera;

IAnimatedMeshSceneNode* gym_node;
IAnimatedMeshSceneNode* terrain_node;

ITriangleSelector* selector;

IMesh* meshs;

bool ShowMenu = false;

//FUNCTIONS

enum
{
	ID_IsNotPickable = 0,
	IDFlag_IsPickable = 1 << 0,
	IDFlag_IsHighlightable = 1 << 1
};

int main()
{
	//Initialise simulation
	InputReceiver* input;
	input = new InputReceiver();
	device = createDevice(EDT_OPENGL, dimension2d<u32>(1280, 720), 16, false, false, false, input);
	if (!device)
	{
		return 1;
	}
	
	device->setWindowCaption(L"ICT398 - Slash Studios");
	
	driver = device->getVideoDriver();
	smgr = device->getSceneManager();
	guienv = device->getGUIEnvironment();

	device->getCursorControl()->setVisible(false);

	//END INITIALISATION

	//Add items the scene	
	IGUIImage* endImage;

	//weight rack
	GameObject* weight_rack_0 = new GameObject("./media/weight_rack.obj",vector3df(240,0,0),vector3df(0,-90,0),1.f,true,smgr);
	
	//bench racks
	GameObject* bench_rack1_0 = new GameObject("./media/bench_rack.obj",vector3df(170,0,400),vector3df(0,-90,0),0.75f,true,smgr);
	GameObject* bench_rack1_1 = new GameObject("./media/bench_rack.obj",vector3df(170,0,650),vector3df(0,-90,0),0.75f,true,smgr);
	GameObject* bench_rack1_2 = new GameObject("./media/bench_rack.obj",vector3df(170,0,900),vector3df(0,-90,0),0.75f,true,smgr);

	//weight bench
	GameObject* bench_0 = new GameObject("./media/bench.obj", vector3df(170, 0, 400), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_1 = new GameObject("./media/bench.obj", vector3df(170, 0, 650), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_2 = new GameObject("./media/bench.obj", vector3df(170, 0, 900), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_3 = new GameObject("./media/bench.obj", vector3df(-130, 0, 200), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_4 = new GameObject("./media/bench.obj", vector3df(-130, 0, 350), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_5 = new GameObject("./media/bench.obj", vector3df(-130, 0, 500), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_6 = new GameObject("./media/bench.obj", vector3df(-130, 0, 650), vector3df(0, 90, 0), 0.95f, true, smgr);
	GameObject* bench_7 = new GameObject("./media/bench.obj", vector3df(-130, 0, 800), vector3df(0, 90, 0), 0.95f, true, smgr);

	//large weights
	

	//treadmills
	//GameObject* treadmill_0 = new GameObject("./media/treadmill.obj",vector3df(220,0,-850),vector3df(0,0,0),0.75f,true,smgr);
	//GameObject* treadmill_1 = new GameObject("./media/treadmill.obj",vector3df(120,0,-850),vector3df(0,0,0),0.75f,true,smgr);
	//GameObject* treadmill_2 = new GameObject("./media/treadmill.obj",vector3df(20,0, -850),vector3df(0,0,0),0.75f,true,smgr);
	//GameObject* treadmill_3 = new GameObject("./media/treadmill.obj",vector3df(-80,0,-850),vector3df(0,0,0),0.75f,true,smgr);

	//machines
	GameObject* lat_pull_down_0 = new GameObject("./media/latpulldown.obj",vector3df(10,0,1050),vector3df(0,180,0),0.9f,true,smgr);
	GameObject* lat_pull_down_1 = new GameObject("./media/latpulldown.obj",vector3df(-150,0,1050),vector3df(0,180,0),0.9f,true,smgr);
	GameObject* lat_pull_down_2 = new GameObject("./media/latpulldown.obj",vector3df(-300,0,1050),vector3df(0,180,0),0.9f,true,smgr);

	GameObject* chest_0 = new GameObject("./media/chest.obj",vector3df(-320,0,750),vector3df(0,90,0),0.9f,true,smgr);
	GameObject* chest_1 = new GameObject("./media/chest.obj",vector3df(-320,0,550),vector3df(0,90,0),0.9f,true,smgr);
	GameObject* chest_2 = new GameObject("./media/chest.obj",vector3df(-320,0,350),vector3df(0,90,0),0.9f,true,smgr);

	//ball rack
	GameObject* ball_rack_0 = new GameObject("./media/weight_rack.obj",vector3df(240,0,-350),vector3df(0,-90,0),1.f,true,smgr);

	//exercise balls
	GameObject* ball_0 = new GameObject("./media/ex_ball.obj",vector3df(220,51,-260),vector3df(0,321,0),0.7f,true,smgr);
	GameObject* ball_1 = new GameObject("./media/ex_ball.obj",vector3df(220,51,-325),vector3df(0,334,0),0.8f,true,smgr);
	GameObject* ball_2 = new GameObject("./media/ex_ball.obj",vector3df(220,51,-410),vector3df(0,122,0),.9f,true,smgr);
	//GameObject ball_3("./media/ex_ball.obj",vector3df(220,51,-350),vector3df(0,0,0),1.f,smgr);
	//GameObject ball_4("./media/ex_ball.obj",vector3df(220,51,-350),vector3df(0,0,0),1.f,smgr);

	//desk
	GameObject* desk = new GameObject("./media/desk.obj",vector3df(-55,0,-180),vector3df(0,90,0),1.3f,true,smgr);
	//cout << "Min edge: " << desk.aabb.MinEdge.X << ", " << desk.aabb.MinEdge.Y << ", " << desk.aabb.MinEdge.Z << ", " << endl;
	//cout << "Max edge: " << desk.aabb.MaxEdge.X << ", " << desk.aabb.MaxEdge.Y << ", " << desk.aabb.MaxEdge.Z << ", " << endl;
	
	//People
	//list<Person*> people = list<Person*>();
	//people.push_back(new Person(vector3df(-55, 0, 180),smgr));
	//GameObject* person_G_1 = new GameObject("./media/person_G.obj", vector3df(-55, 0, 180), vector3df(0, 0, 0), .7f, true, smgr, false);
	//GameObject* person_B_1 = new GameObject("./media/person_B.obj", vector3df(-55, 0, 580), vector3df(0, 0, 0), .7f, true, smgr, false);
	
	ITriangleSelector* selector=0;

	IAnimatedMesh* gymMesh = smgr->getMesh("./media/gym.obj");
	IMeshSceneNode* gymN = 0;

	if(gymMesh)
	{
		gymN = smgr->addOctreeSceneNode(gymMesh->getMesh(0),0,IDFlag_IsPickable);
		gymN->setScale(vector3df(1.6f));
		gymN->setPosition(vector3df(-90,0,20));
		for (unsigned int i = 0; i < gymN->getMaterialCount(); i++)
		{
			gymN->getMaterial(i).Lighting=false;
			gymN->getMaterial(i).NormalizeNormals=false;
		}
	}

	if(gymN)
	{
		selector=smgr->createOctreeTriangleSelector(gymN->getMesh(),gymN,128);
		gymN->setTriangleSelector(selector);
	}

	float camSize = 60;
	Camera* camera = new Camera(80.f,.5f,vector3df(-150, 150, 200),smgr,selector);
	camera->CreateAABB(vector3df(-camSize,-camSize,-camSize),vector3df(camSize,camSize,camSize));
	
	
	list<GameObject*> allGOs = list<GameObject*>();
	allGOs.push_back(weight_rack_0);
	allGOs.push_back(bench_0);
	allGOs.push_back(bench_1);
	allGOs.push_back(bench_2);
	allGOs.push_back(bench_3);
	allGOs.push_back(bench_4);
	allGOs.push_back(bench_5);
	allGOs.push_back(bench_6);
	allGOs.push_back(bench_7);
	allGOs.push_back(ball_rack_0);
	allGOs.push_back(desk);

	//people
	vector<vector3df> pm1Locs;
	vector<vector3df> pc1Locs;
	vector<vector3df> pf1Locs;

	pm1Locs.push_back(vector3df(-155, 0, 0));
	//pm1Locs.push_back(vector3df(-154, 0, 0));

	pc1Locs.push_back(vector3df(0, 0, -580));
	pc1Locs.push_back(vector3df(15, 0, 0));
	//pc1Locs.push_back(vector3df(-150, 0, 180));
	
	pf1Locs.push_back(vector3df(0, 0, 780));
	//pf1Locs.push_back(vector3df(0, 0, 781));

	allGOs.push_back(new Person_Machine(pm1Locs, smgr)); 
	allGOs.push_back(new Person_Cardio(pc1Locs, smgr));
	allGOs.push_back(new Person_FreeWeight(pf1Locs, smgr));

	//small weights
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 0 * 30), vector3df(0, 0, 25), 0.020f, true, 0.50f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 1 * 30), vector3df(0, 0, 25), 0.021f, true, 0.53f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 2 * 30), vector3df(0, 0, 25), 0.022f, true, 0.56f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 3 * 30), vector3df(0, 0, 25), 0.023f, true, 0.59f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 4 * 30), vector3df(0, 0, 25), 0.024f, true, 0.62f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 5 * 30), vector3df(0, 0, 25), 0.025f, true, 0.65f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 53, 100 - 6 * 30), vector3df(0, 0, 25), 0.026f, true, 0.68f, smgr));
	
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 0 * 30), vector3df(0, 0, 25), 0.020f, true, 0.50f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 1 * 30), vector3df(0, 0, 25), 0.021f, true, 0.53f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 2 * 30), vector3df(0, 0, 25), 0.022f, true, 0.56f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 3 * 30), vector3df(0, 0, 25), 0.023f, true, 0.59f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 4 * 30), vector3df(0, 0, 25), 0.024f, true, 0.62f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 5 * 30), vector3df(0, 0, 25), 0.025f, true, 0.65f, smgr));
	allGOs.push_back(new Weight("./media/weight_small.obj", vector3df(230, 23, 100 - 6 * 30), vector3df(0, 0, 25), 0.026f, true, 0.68f, smgr));
	
	//large weights
	allGOs.push_back(new Weight("./media/weight_large.obj", vector3df(225, 48, 400), vector3df(0, 90, 0), 0.02f,true, 0.75f, smgr));
	allGOs.push_back(new Weight("./media/weight_large.obj", vector3df(225, 48, 650), vector3df(0, 90, 0), 0.02f, true, 0.85f, smgr));
	allGOs.push_back(new Weight("./media/weight_large.obj", vector3df(225, 48, 900), vector3df(0, 90, 0), 0.02f, true, 0.95f, smgr));

	//treadmills
	allGOs.push_back(new Treadmill("./media/treadmill.obj", vector3df(220, 0, -850), vector3df(0, 0, 0), 0.75f,  true,0.3f, smgr));
	allGOs.push_back(new Treadmill("./media/treadmill.obj", vector3df(120, 0, -850), vector3df(0, 0, 0), 0.75f, true, 0.5f, smgr));
	allGOs.push_back(new Treadmill("./media/treadmill.obj", vector3df(20, 0, -850), vector3df(0, 0, 0), 0.75f, true, 0.7f, smgr));
	allGOs.push_back(new Treadmill("./media/treadmill.obj", vector3df(-80, 0, -850), vector3df(0, 0, 0), 0.75f,  true,0.9f, smgr));

	//machines
	allGOs.push_back(new Machine("./media/latpulldown.obj", vector3df(10, 0, 1050), vector3df(0, 180, 0), 0.9f,  true,0.5f, smgr));
	allGOs.push_back(new Machine("./media/latpulldown.obj", vector3df(-150, 0, 1050), vector3df(0, 180, 0), 0.9f,  true,0.7f, smgr));
	allGOs.push_back(new Machine("./media/latpulldown.obj", vector3df(-300, 0, 1050), vector3df(0, 180, 0), 0.9f,  true,0.9f, smgr));

	allGOs.push_back(new Machine("./media/chest.obj", vector3df(-320, 0, 750), vector3df(0, 90, 0), 0.9f,  true,0.5f, smgr));
	allGOs.push_back(new Machine("./media/chest.obj", vector3df(-320, 0, 550), vector3df(0, 90, 0), 0.9f,  true,0.6f, smgr));
	allGOs.push_back(new Machine("./media/chest.obj", vector3df(-320, 0, 350), vector3df(0, 90, 0), 0.9f,  true,0.9f, smgr));
	//END ADDING ITEMS TO THE SIMULATION
	
	//GAME LOOP
	while (device->run())
	{
		driver->beginScene(true, true, SColor(155, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();

		if(input->IsKeyDown(KEY_KEY_X))
		{
			if(!ShowMenu)
			{		
				endImage = guienv->addImage(rect<int>(440,160,840,560));
				endImage->setImage(driver->getTexture("./media/textures/credits.png"));
				
				ShowMenu=true;
			}
		}

		if(ShowMenu)
		{
			if(input->GetMouseState().LeftButtonDown)
			{
				exit(0);
			}
		}

		

		for (list<GameObject*>::Iterator it = allGOs.begin(); it != allGOs.end(); ++it)
		{
			(*it)->Update(allGOs);
			float distX = ((*it)->GetPosition().X - camera->GetPosition().X);
			float distZ = ((*it)->GetPosition().Z - camera->GetPosition().Z);

			if (distX < 0)
			{
				distX = -distX;
			}
			if (distZ < 0)
			{
				distZ = -distZ;
			}
			//cout << distX << endl;
			if (distX <= 50 && distZ <= 50)
			{
				if (input->IsKeyDown(KEY_KEY_E))
				{
					if (camera->MatchAffordances((*it)))
					{
						(*it)->Interact(camera);
					}
				}
				if (input->IsKeyDown(KEY_KEY_R))
				{
					if (camera->MatchAffordances(new Affordance("insult", 1)))
					{
						((Person*)(*it))->Insult();
					}
				}
				if (input->IsKeyDown(KEY_KEY_F))
				{
					if (camera->MatchAffordances(new Affordance("praise", 1)))
					{
						((Person*)(*it))->Praise();
					}
				}
			}
		}
		
		camera->Update(allGOs);		
	}

	device->drop();
	return 0;
}