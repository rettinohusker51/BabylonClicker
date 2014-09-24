//
//  Test.cpp
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/14.
//
//

#include "Test.h"
#include "GameController.h"
#include "ItemFactory.h"
#include "MagicFactory.h"
#include "UnitFactory.h"
#include "BossFactory.h"
#include "Item.h"
#include "BattleController.h"
#include "Unit.h"
#include "User.h"
#include "Magic.h"
#include "cocos2d.h"
#include "UnitDataFactory.h"
#include "UnitData.h"
#include "GameConfig.h"

USING_NS_CC;

Test::Test()
{
}

Test::~Test()
{
}

void Test::run() {
    
    CCLOG("******Settings******");
    User* user = BattleController::getInstance()->getField()->getUser();
    
    CCLOG("******UnitDataFactory class******");
    GameConfig* config = GameController::getInstance()->getConfig();
    config->dump();
    
    CCLOG("******User class******");
    user->dump();
    
    CCLOG("******Unit class******");
    UnitCage* cage = BattleController::getInstance()->getActiveUnitCage();
    UnitFactory* ufact = new UnitFactory();
    Unit* unit1 = (Unit*)ufact->create(0);
    Unit* unit2 = (Unit*)ufact->create(1);
    Unit* unit5 = (Unit*)ufact->create(2);
    Unit* unit3 = (Unit*)ufact->create(4);
    Unit* unit4 = (Unit*)ufact->create(5);
    unit2->dump();
    unit1->summon();
    unit2->dump();
    unit2->summon();
    unit3->summon();
    unit4->summon();
    unit5->summon();
    cage->dump();
    CC_SAFE_RELEASE(ufact);
    
    CCLOG("******Item class******");
    
    CCLOG("******Magic class******");
    
    CCLOG("******BattleController class******");
    
    CCLOG("******Field class******");
    Field* field = BattleController::getInstance()->getField();
    field->dump();
    
    CCLOG("******Summon******");
    Array* ar =BattleController::getInstance()->getActiveUnitCage()->getUnitArray();
    Object* it;
    CCARRAY_FOREACH(ar, it) {
        Unit* unit = dynamic_cast<Unit*>(it);
        CCLOG("%s can summon?: %d",unit->getObjectData()->getName(), unit->canSummon());
    }
}