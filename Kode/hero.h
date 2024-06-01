#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"

class hero
{
public:
    hero();
    hero(int hero);
    virtual ~hero() {std::cout << "hero destroyed" << std::endl;}

    int getAd();
    void setAd(int ad);

    int getHp();
    void setHp(int hp);

    int getXp();
    void setXp(int xp);

    int getLvl();

    int getSpd();
    void setSpd(int spd);

    std::string getNavn();

    void getHit(int av);

    int getGold();
    void setGold(int gold);

    int getID();

    int getMana();
    void setMana(int mana);
    void drainMana(int mana);


private:
    int mKarakter, mAd, mHp, mXp, mLvl, mSpd, mGold, mMana;
    std::string mNavn;
};

#endif // HERO_H
