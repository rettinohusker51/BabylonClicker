//
//  ItemFactory.cpp
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/14.
//
//

#include "ItemFactory.h"
#include "Item.h"
#include "ItemDataFactory.h"
#include "ItemData.h"

ItemFactory::ItemFactory()
{
}

ItemFactory::~ItemFactory()
{
}

GameObject* ItemFactory::createObject(int objectID) {
    ItemDataFactory* idFactory = new ItemDataFactory("itemData.plist");
    ItemData* iData = (ItemData*)idFactory->create(objectID);
    Item* item = new Item(iData);
    return item;
}