//
//  UnitField.cpp
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/18.
//
//

#include "UnitField.h"

UnitField::UnitField()
: unitNum(0)
{
}

UnitField::~UnitField()
{
}

void UnitField::dump() const {
    FieldObject::dump();
    CCLOG("unitNum: %d", unitNum);
}

void UnitField::incrementUnitNum() {
    ++unitNum;
}