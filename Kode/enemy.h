#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"


class enemy
{
public:
    enemy();
    enemy(int enemy);
    virtual ~enemy() {std::cout << "enemy destroyed" << std::endl;}

    int getAd();

    int getHp();

    int getXp();

    int getSpd();

    std::string getNavn();

    void getHit(int av);

private:
    int mKarakter, mAd, mHp, mXp, mSpd;
    std::string mNavn;
};

#endif // ENEMY_H
