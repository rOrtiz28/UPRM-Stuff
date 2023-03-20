#include "EntityManager.h"
#include "Inspector.h"

void EntityManager::tick(){
    for(int i=0; i<entities.size(); i++){
        entities[i]->tick();
    }
    if(firstClient != nullptr){
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeLeavingClients(){
    Client* tempClient = nullptr;
    while(firstClient != nullptr && firstClient->isLeaving){

        if(firstClient->getPatience() == 0){
            LeaveClient++;
        }

        if(dynamic_cast<Inspector*>(firstClient) != nullptr && firstClient->getPatience() == 0){
            badReview = true;
        }
        if(LeaveClient == 10){
            cout<<"Leave"<<endl;
             YouLost = true;
        }
        if(Lives != false){
            LeaveClient = 0;
        }

        tempClient = firstClient->nextClient;
        delete firstClient;
        firstClient = tempClient;
    }
}
void EntityManager::render(){
    for(int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}

void EntityManager::addClient(Client* c){
    if(firstClient == nullptr){
        firstClient = c;
    }else{
        Client* tempClient = firstClient;
        tempClient->setY(tempClient->getY()+80);
        while(tempClient->nextClient!=nullptr){
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY()+80);

        }
        tempClient->nextClient = c;
    }
}