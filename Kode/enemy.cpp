#include "enemy.h"

enemy::enemy()
{

}
enemy::enemy(int enemy) {
    mKarakter = enemy;
    QSqlQuery query;
    query.exec(QString::fromStdString("SELECT * FROM fjende WHERE ID = " + std::to_string(mKarakter)));
    while (query.next()) {
        mNavn = query.value("name").toString().toStdString();
        mAd = query.value("ad").toInt();
        mHp = query.value("hp").toInt();
        mXp = query.value("xp").toInt();
        mSpd = query.value("spd").toInt();
        mGold = query.value("gold").toInt();
        mType = query.value("typeID").toInt();
    }
}

int enemy::getAd() {
    return mAd;
}

int enemy::getHp() {
    return mHp;
}

int enemy::getXp() {
    return mXp;
}

int enemy::getSpd() {
    return mSpd;
}

std::string enemy::getNavn() {
    return mNavn;
}

void enemy::getHit(int av) {
    mHp -= av;
}

int enemy::getGold() {
    return mGold;
}

int enemy::getType() {
    return mType;
}
