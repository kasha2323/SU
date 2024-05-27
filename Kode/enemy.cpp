#include "enemy.h"

enemy::enemy()
{

}
enemy::enemy(int enemy) {
    mKarakter = enemy;
    QSqlQuery query;
    query.exec(QString::fromStdString("SELECT * FROM fjende WHERE ID = " + std::to_string(mKarakter)));
    QString navn;
    while (query.next()) {
        navn = query.value(1).toString();
        mAd = query.value(2).toInt();
        mHp = query.value(3).toInt();
        mXp = query.value(4).toInt();
        mSpd = query.value(5).toInt();
    }

    mNavn = navn.toStdString();
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
