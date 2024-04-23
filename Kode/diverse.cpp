#include "diverse.h"

#include <chrono>
#include <thread>

diverse::diverse()
{

}

void diverse::slowPrint(std::string text) {
    for(char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << std::endl;
}

void diverse::insert(std::string navn, int ad, int hp, int xp, int lvl, int spd) {
    QSqlQuery insert;
    insert.prepare("INSERT INTO helt (name, ID, ad, hp, xp, lvl, spd) VALUES (:name, :ID, :ad, :hp, :xp, :lvl, :spd)");
    insert.bindValue(":name", QString::fromStdString(navn));
    insert.bindValue(":ID", 0);
    insert.bindValue(":ad", ad);
    insert.bindValue(":hp", hp);
    insert.bindValue(":xp", xp);
    insert.bindValue(":lvl", lvl);
    insert.bindValue(":spd", spd);

    if (!insert.exec()) {
        qDebug() << "Failed" << insert.lastError().text();
    }

    slowPrint("Character " + navn + " Created");
    slowPrint("Press Enter To Continue");
}

void diverse::del(int ID) {
    QSqlQuery del;
    del.prepare("DELETE FROM helt WHERE ID = :ID");
    del.bindValue(":ID", ID);

    if (!del.exec()) {
        qDebug() << "Failed" << del.lastError().text();
    }

    slowPrint("Character Deleted");
    slowPrint("Press Enter To Continue");
}
