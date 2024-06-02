#include "weapon.h"

weapon::weapon()
{
    mWeapon = 0;
    mDamage = 0;
    mType = 0;
    mName = "Fists";
    mGold = 0;
    mMana = 0;
}


int weapon::getGold() {
    return mGold;
}
int weapon::getDamage() {
    return mDamage;
}
int weapon::getType() {
    return mType;
}
std::string weapon::getName() {
    return mName;
}
int weapon::getWeapon() {
    return mWeapon;
}
void weapon::setWeapon(int weapon) {
    mWeapon = weapon;
    if (mWeapon > 0) {
        QSqlQuery query;
        query.exec(QString::fromStdString("SELECT items.name, items.damage, type.ID, items.gold, items.mana FROM items, type WHERE type.ID = items.typeID AND " + std::to_string(mWeapon) + " = items.ID ORDER BY ID"));
        while (query.next()) {
            mDamage = query.value("items.damage").toInt();
            mName = query.value("items.name").toString().toStdString();
            mType = query.value("type.ID").toInt();
            mGold = query.value("items.gold").toInt();
            mMana = query.value("items.mana").toInt();
        }
    } else {
        mDamage = 0;
        mName = "Fists";
        mType = 0;
        mGold = 0;
        mMana = 0;
    }
}
int weapon::getMana() {
    return mMana;
}

double weapon::type(int eType) {
    QSqlQuery type;
    type.exec(QString::fromStdString("SELECT typeStrongID, typeWeakID FROM typeStrong WHERE ID = " + std::to_string(mType)));
    while (type.next()) {
        int w = type.value("typeWeakID").toInt();
        int s = type.value("typeStrongID").toInt();
        if (eType == w) {
            return 0.5;
        } else if (eType == s) {
            return 2;
        }
    }
    return 1;
}
