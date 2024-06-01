#include "shop.h"
#include "diverse.h"
#include "weapon.h"
#include "hero.h"

shop::shop()
{

}

shop::shop(int item) {
    mItem = item;
}

void shop::insert(int hero, int &gold) {
    QSqlQuery insert;

    QSqlQuery Qpur;

    QSqlQuery Qcheck;

    QSqlQuery Qreq;

    diverse d;


    Qpur.exec(QString::fromStdString("SELECT ID FROM purchased WHERE itemID = " + std::to_string(mItem) + " AND heltID = " + std::to_string(hero)));
    if (Qpur.next()) {
        d.slowPrint("This Item Has Already Been Purchased");
        return;
    }

    Qcheck.exec(QString::fromStdString("SELECT ID FROM requirement WHERE itemID = " + std::to_string(mItem)));
    if (Qcheck.next()) {
        Qreq.exec(QString::fromStdString("SELECT requirement.ID FROM requirement, purchased, items WHERE requirement.requireID = items.ID AND items.ID = purchased.itemID AND requirement.itemID = " + std::to_string(mItem) + " AND purchased.heltID = " + std::to_string(hero)));
        if (!Qreq.next()) {
            d.slowPrint("You Can't Buy That");
            return;
        } else {
            QSqlQuery del;
            int i = 0;
            del.exec(QString::fromStdString("SELECT purchased.itemID FROM requirement, purchased, items WHERE requirement.requireID = items.ID AND items.ID = purchased.itemID AND requirement.itemID = " + std::to_string(mItem) + " AND purchased.heltID = " + std::to_string(hero)));
            while (del.next()) {
                i = del.value("purchased.itemID").toInt();
            }
            del.prepare("DELETE FROM purchased WHERE purchased.itemID = :itemID AND purchased.heltID = :heltID");
            del.bindValue(":itemID", i);
            del.bindValue(":heltID", hero);

            if (!del.exec()) {
                qDebug() << "Failed" << del.lastError().text();
            }
        }
    }

    weapon w;
    w.setWeapon(mItem);
    d.slowPrint("You Have Succesfully Bought The " + w.getName());

    gold -= w.getGold();


    insert.prepare("INSERT INTO purchased (itemID, heltID) VALUES (:itemID, :heltID)");
    insert.bindValue(":itemID", mItem);
    insert.bindValue(":heltID", hero);
    if (!insert.exec()) {
        qDebug() << "Failed" << insert.lastError().text();
    }
    return;
}
