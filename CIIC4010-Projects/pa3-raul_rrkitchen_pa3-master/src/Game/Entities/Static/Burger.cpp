//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push_back(item);
}

void Burger::removeIngredient(Item *item) {
    if(ingredients.size() > 0){
        ingredients.pop_back();
    }
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

bool Burger::equals(Burger *burger){
   vector <Item*> burger1 = this->ingredients;
   vector <Item*> burger2 = burger->ingredients;

   for (int i = 0; i < burger1.size(); i++) {
        int index = 0;
        bool test = false;
        for (int j = 0; j < burger2.size(); j++) {

            if (burger1[i]->name == burger2[j]->name) {
                test = true;
                index = j;
            }
        }

        if (!test){
            return false;
        }
        else {burger2.erase(burger2.begin() + index);}
    }
return true;
    
}

int Burger::playerBurgerSize(){
    vector <Item*> playerBurgerSize = this->ingredients;
    return playerBurgerSize.size();
    
}