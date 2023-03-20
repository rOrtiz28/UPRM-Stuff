#pragma once
#include "Client.h"
#include "Burger.h"
#include "Entity.h"


class Inspector : public Client{
    public:
    Inspector(int, int, int, int, ofImage, Burger*);
    ~Inspector();
    void render();

};