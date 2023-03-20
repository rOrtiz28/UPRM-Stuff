//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

Restaurant::Restaurant() {
    floor.load("images/floort3.jpg"); // Reference: http://www.artwallpaperhi.com/Architecture/floor/textures_wood_floor_oscuro_1920x1080_wallpaper_47297
    wall.load("images/muro.jpeg"); // Reference: https://kylpy.wordpress.com/2013/11/28/el-muro/
    sprite.load("images/sprite.png");
    black.load("images/black.jpeg");
    door.cropFrom(sprite,70,118,40,58);
    table.cropFrom(sprite,23,26,60,59);
    window.cropFrom(sprite,137,207,30,45);
    chair.cropFrom(sprite,105,14,37,75);
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg, ketchupImg,baconImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate
    
    //Added Ingredients
    //ketchupImg.cropFrom(burgerSpriteSheet, 167,18,114,39); //ketchup_Test
    baconImg.cropFrom(burgerSpriteSheet, 170,110,101,37); //Bacon

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");

    //Added Item
    //ketchup = new Item(ketchupImg, "ketchup");
    bacon = new Item(baconImg, "bacon");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg, baconCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    baconCounterImg.cropFrom(counterSheet,192,139,32,45);//Bacon
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, bacon, baconCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    temp.load("images/People/inspectorTemplate.png");
    inspectorImg.cropFrom(temp, 194,0,28,33);
    people.push_back(inspectorImg);

    temp.load("images/People/inspectorTemplate.png");
    additionalpeople1.cropFrom(temp, 99,0,26,34);
    people.push_back(additionalpeople1);

    temp.load("images/People/inspectorTemplate.png");
    additionalpeople2.cropFrom(temp, 2,0,30,34);
    people.push_back(additionalpeople2);
    
    temp.load("images/People/inspectorTemplate.png");
    additionalpeople3.cropFrom(temp, 99,129,26,32);
    people.push_back(additionalpeople3);

    temp.load("images/People/inspectorTemplate.png");
    additionalpeople4.cropFrom(temp, 290,127,27,34);
    people.push_back(additionalpeople4);


}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();
    }
    else if(entityManager->badReview != false){
        setMoney(getMoney() / 2);
        entityManager->setBadReview(false);

    }
    player->tick();
    entityManager->tick();

}

void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);

    vector <Item*> Ingredients = {bacon, cheese, tomato, burger, lettuce};

    int randomIngredient1 = ofRandom(0, 5);
    int randomIngredient2 = ofRandom(0, 5);
    int randomIngredient3 = ofRandom(0, 5);
    // int randomIngredient4 = ofRandom(0, 5);
    // int randomIngredient5 = ofRandom(0, 5);

    Item* ingredients1_random = Ingredients[randomIngredient1];
    Item* ingredients2_random = Ingredients[randomIngredient2];
    Item* ingredients3_random = Ingredients[randomIngredient3];
    // Item* ingredients4_random = Ingredients[randomIngredient4];
    // Item* ingredients5_random = Ingredients[randomIngredient5];

    b->addIngredient(botBread);
    b->addIngredient(ingredients1_random);
    b->addIngredient(ingredients2_random);
    b->addIngredient(ingredients3_random);
    // b->addIngredient(ingredients4_random);
    // b->addIngredient(ingredients5_random);
    b->addIngredient(topBread);
    
    int inspectorDice = ofRandom(0,6);

    if(inspectorDice == 3 || inspectorDice == 1){
        entityManager->addClient(new Inspector(0,50,64,72,people[8], b));
    }
    else{
        entityManager->addClient(new Client(0, 50, 64, 72,people[ofRandom(13)], b));
    }

}
void Restaurant::render() {

    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    door.draw(0,0,78,148);
    wall.draw(66,0,770,120);


    table.draw(200,150,100, 100); //Mesa #1
    chair.draw(125,160,70, 80);
    chair.draw(300,160,70, 80);

    table.draw(600,150,100, 100); //Mesa #2
    chair.draw(525,160,70, 80);
    chair.draw(700,160,70, 80);


    table.draw(200,300,100, 100); //Mesa #3
    chair.draw(125,320,70, 80);
    chair.draw(300,320,70, 80);

    table.draw(600,300,100, 100); //Mesa #4
    chair.draw(525,320,70, 80);
    chair.draw(700,320,70, 80);

    window.draw(100,10,90,90); //Ventanas
    window.draw(300,10,90,90);
    window.draw(500,10,90,90);
    window.draw(700,10,90,90);


    player->render();
    entityManager->render();
    black.draw(ofGetWidth()/2,0,80, 12);
    ofSetColor(0, 255, 0);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth()/2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        if(entityManager->firstClient->getBurger()->equals(player->getBurger())){
            money += entityManager->firstClient->serve(player->getBurger());
        }
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
}

int Restaurant::getMoney() {
    return money;
}
