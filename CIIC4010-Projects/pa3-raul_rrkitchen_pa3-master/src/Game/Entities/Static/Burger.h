//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H

#include "Item.h"
#include "Entity.h"

class Burger {
private:
    int x,y,width,height;
 vector<Item*> ingredients;

public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void removeIngredient(Item *item);
    void render();
    int playerBurgerSize();
    void clear();
    void setY(int y){
        this->y = y;
    }
    
    bool equals(Burger *burger);
};


#endif //APGAMEENGINE_BURGER_H
