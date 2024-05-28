#ifndef CAVE_H
#define CAVE_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"
#include "vector"

class cave
{
public:
    cave();
    cave(int cave);
    virtual ~cave() {std::cout << "cave destroyed" << std::endl;}

    std::vector<int> enemies();
    int nextEnemy();

    int getGold() {return mGold;}

    std::string getNavn() {return mNavn;}

    int emptyCheck();

private:
    int mCave, mGold;
    std::vector<int> mEnemy = {};
    std::string mNavn;
};


#endif // CAVE_H
