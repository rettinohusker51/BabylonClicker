//
//  Unit.cpp
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/14.
//
//

#include "Unit.h"
#include "BattleController.h"
#include "UnitNode.h"

Unit::Unit(UnitData* data)
: GameObject(data)
{
    // set attack interval.
    unitNode = new UnitNode(this);
    UnitData* uData = (UnitData*)getObjectData();
    unitNode->schedule(schedule_selector(UnitNode::onScheduleUpdate), uData->getInterval());
}

Unit::~Unit()
{
    unitNode->unscheduleAllSelectors();
    unitNode->release();
}

void Unit::summon() {
    // 召喚された事を通知。ユニットカウントを上げる。
    CCLOG("Unit summon called");
}

bool Unit::canSummon() const {
    for(int i=0; i<UnitData::SACRIFICE_SLOT_NUM; ++i) {
        if (!canSummonAt(i)) {
            return false;
        }
    }
    return true;
}

bool Unit::canSummonAt(int slotID) const{
    if (0>slotID || slotID>UnitData::SACRIFICE_SLOT_NUM) {
        return false;
    }
    UnitData* ud = (UnitData*)objectData;
    int sf = ud->getSacrifice(slotID);
    if (sf == -1) {
        return true;
    }
    else if (sf >= 0) {
        int sfn = ud->getSacrificeNum(slotID);
        Field* fd = BattleController::getInstance()->getField();
        int havingSfn = fd->getSharedUnitData(sf)->getUnitNum();
        if (havingSfn >= sfn) {
            return true;
        }
    }
    return false;
}

void Unit::attack() {
    UnitData* uData = (UnitData*)objectData;
    CCLOG("Attacker name: %s", uData->getName());
    CCLOG("Attacker power: %f", uData->getAttack());
    float attack = uData->getAttack();
    BattleController::getInstance()->getTargetBoss()->damage(attack);
}

void Unit::onAction() {
    CCLOG("Unit onAction called");
    attack();
}

bool Unit::isHoldingNode() const{
    return (unitNode != NULL) ? true : false;
}

void Unit::dump() const{
    ((UnitData*)objectData)->dump();
    CCLOG("unitData RetainCount: %d", objectData->retainCount());
    CCLOG("unitNode RetainCount: %d", unitNode->retainCount());
    CCLOG("isHoldingNode: %d", isHoldingNode());
}