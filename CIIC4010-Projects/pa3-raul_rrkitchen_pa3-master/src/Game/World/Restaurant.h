//
// Created by joshu on 11/3/2020.
//
#pragma once
#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        //Item* ketchup;
        Item* bacon;
        ofImage floor;
        ofImage door;
        ofImage wall;
        ofImage window;
        ofImage table;
        ofImage chair;
        ofImage sprite;
        ofImage black;
        ofImage inspectorImg;
        ofImage additionalpeople1;
        ofImage additionalpeople2;
        ofImage additionalpeople3;
        ofImage additionalpeople4;
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        int getMoney();
        void setMoney(int money){this->money = money;}
        EntityManager* getEntityManager() {return entityManager;}

};


#endif //APGAMEENGINE_RESTAURANT_H
