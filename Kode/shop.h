#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QCoreApplication>
#include "string.h"

class shop
{
public:
    shop();
    shop(int item);
    virtual ~shop() {std::cout << std::endl;}

    void insert(int hero, int &gold);

private:
    int mItem;
};

#endif // SHOP_H
