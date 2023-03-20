#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	bool badReview = false;
	void setBadReview(bool badReview){this->badReview = badReview;}
	int LeaveClient = 0;
	bool YouLost = false;
	bool Lives = false;

};