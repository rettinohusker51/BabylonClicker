//
//  GameObjectFactory.cpp
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/14.
//
//

#include "GameObjectFactory.h"

GameObjectFactory::GameObjectFactory()
{
}

GameObjectFactory::~GameObjectFactory()
{
}

GameObject* GameObjectFactory::create(){
    GameObject* obj = createObject(0);
    return obj;
}