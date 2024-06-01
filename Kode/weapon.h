#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"


class weapon
{
public:
    weapon();
    virtual ~weapon() {std::cout << std::endl;}

    int getGold();
    int getDamage();
    int getType();
    std::string getName();
    int getWeapon();
    void setWeapon(int weapon);

    double type(int eType);

    int getMana();

private:
    int mWeapon, mDamage, mType, mGold, mMana;
    std::string mName;
};

#endif // WEAPON_H
