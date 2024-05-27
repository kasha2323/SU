#ifndef DIVERSE_H
#define DIVERSE_H

#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"


class diverse
{
public:
    diverse();

    void slowPrint(std::string text);

    void insert(std::string navn, int ad, int hp, int xp, int lvl, int spd, int gold);

    void del(int ID);
};

#endif // DIVERSE_H
