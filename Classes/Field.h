//
//  Field.h
//  BabylonClicker
//
//  Created by Takahiro Kosaka on 2014/08/14.
//
//

#ifndef __BabylonClicker__Field__
#define __BabylonClicker__Field__

#include <iostream>
#include "cocos2d.h"
#include "BaseObject.h"
#include "FieldObject.h"
#include "UnitData.h"

class Field : virtual public BaseObject {
public:
    Field();
    virtual ~Field();
    typedef enum {
        UFT_Attack,
        UFT_Summon,
        UFT_Magic,
        UFT_Enemy,
        UFT_Rebirth,
        UFT_TypeNum
    } UserFieldType;
    typedef enum {
        MFT_Fire,
        MFT_Water,
        MFT_Wood,
        MFT_Shine,
        MFT_Dark,
        MFT_TypeNum
    } MagicFieldType;
    typedef enum {
        FFT_Babylon,
        FFT_Hanaaruki,
        FFT_Maririka,
        FFT_Papillon,
        FFT_TypeNum
    } FamilyFieldType;
    CC_SYNTHESIZE_READONLY(Array*, unitFamilyField, UnitFamilyField);
    CC_SYNTHESIZE_READONLY(Array*, unitMagicField, UnitMagicField);
    CC_SYNTHESIZE_READONLY(Array*, userField, UserField);
    CC_SYNTHESIZE_READONLY(Array*, userMagicField, UserMagicField);
    virtual void dump() const;
    void registUnitFamiryFieldObserver(UnitData* uData);
    void registUnitMagicFieldObserver(UnitData* uData);
    void registUserField(UnitData* uData);
    void registUserMagicField(UnitData* uData);
    bool isHavingSharedUnitData(int objectID);
    void setSharedUnitData(UnitData* uData);
    UnitData* getSharedUnitData(int objectID);
    static FamilyFieldType getFamilyFieldType(const char* name);
    static MagicFieldType getMagicFieldType(const char* name);
private:
    Array* sharedUnitDataArray;
};
#endif /* defined(__BabylonClicker__Field__) */
