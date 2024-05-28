#include "cave.h"
#include <random>
#include <algorithm>

cave::cave()
{

}

cave::cave(int cave) {
    mCave = cave;
    QSqlQuery query;
    query.exec(QString::fromStdString("SELECT name, gold FROM grotte WHERE ID = " + std::to_string(mCave)));
    while (query.next()) {
        mNavn = query.value("name").toString().toStdString();
        mGold = query.value("gold").toInt();
    }


}

std::vector<int> cave::enemies() {
    QSqlQuery enemies;
    enemies.exec(QString::fromStdString("SELECT fjendeID FROM iGrotten WHERE grotteID = " + std::to_string(mCave)));
    while (enemies.next()) {
        mEnemy.push_back(enemies.value(0).toInt());
    }
    return mEnemy;
}

int cave::nextEnemy() {             // Fix shuffle //
    /*std::random_device ran;
    std::uniform_int_distribution<int> R3(1,3);
    std::shuffle(std::begin(mEnemy), std::end(mEnemy), R3(ran));*/
    if (mEnemy.empty()) {
        return 0;
    }
    int x = mEnemy.back();
    mEnemy.pop_back();
    return x;
}

int cave::emptyCheck() {
    return mEnemy.empty();
}
