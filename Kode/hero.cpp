#include "hero.h"
#include "random"

hero::hero()
{

}
hero::hero(int hero) {
    mKarakter = hero;
    QSqlQuery query;
    query.exec(QString::fromStdString("SELECT * FROM helt WHERE ID = " + std::to_string(mKarakter)));
    while (query.next()) {
        mNavn = query.value("name").toString().toStdString();
        mAd = query.value("ad").toInt();
        mHp = query.value("hp").toInt();
        mXp = query.value("xp").toInt();
        mLvl = query.value("lvl").toInt();
        mSpd = query.value("spd").toInt();
        mGold = query.value("gold").toInt();
    }
}

int hero::getAd() {
    return mAd;
}
void hero::setAd(int ad) {
    mAd += ad;
    QString updateAd = "UPDATE helt SET ad = :ad WHERE ID = :ID";
    QSqlQuery Qad;
    Qad.prepare(updateAd);
    Qad.bindValue(":ID", mKarakter);
    Qad.bindValue(":ad", mAd);

    if (!Qad.exec()) {
        qDebug() << "Failed" << Qad.lastError().text();
    }
}

int hero::getHp() {
    return mHp;
}
void hero::setHp(int hp) {
    QSqlQuery iHp;
    iHp.exec(QString::fromStdString("SELECT hp FROM helt WHERE ID = " + std::to_string(mKarakter)));
    while (iHp.next()) {
        mHp = iHp.value(0).toInt();
    }
    mHp += hp;
    QString updateHp = "UPDATE helt SET hp = :hp WHERE ID = :ID";
    QSqlQuery Qhp;
    Qhp.prepare(updateHp);
    Qhp.bindValue(":ID", mKarakter);
    Qhp.bindValue(":hp", mHp);

    if (!Qhp.exec()) {
        qDebug() << "Failed" << Qhp.lastError().text();
    }
}

int hero::getXp() {
    return mXp;
}
void hero::setXp(int xp) {
    mXp+=xp;
    while(mXp >= mLvl*1000) {
        mXp-=mLvl*1000;
        ++mLvl;

        std::random_device ran;
        std::uniform_int_distribution<int> R3(0,2);
        setAd(1);
        setHp(2);
        setSpd(R3(ran));
        QString updateLvl = "UPDATE helt SET lvl = :lvl WHERE ID = :ID";
        QSqlQuery Qlvl;
        Qlvl.prepare(updateLvl);
        Qlvl.bindValue(":ID", mKarakter);
        Qlvl.bindValue(":lvl", mLvl);

        if (!Qlvl.exec()) {
            qDebug() << "Failed" << Qlvl.lastError().text();
        }
        std::cout << "Lvl up!" << std::endl;
    }
    QString updateXp = "UPDATE helt SET xp = :xp WHERE ID = :ID";
    QSqlQuery Qxp;
    Qxp.prepare(updateXp);
    Qxp.bindValue(":ID", mKarakter);
    Qxp.bindValue(":xp", mXp);

    if (!Qxp.exec()) {
        qDebug() << "Failed" << Qxp.lastError().text();
    }

    /*std::cout << "Navn: "<< mNavn << std::endl <<
                 "Attack: " << mAd << std::endl <<
                 "Health: " << mHp << std::endl <<
                 "Xp: " << mXp << std::endl <<
                 "Level: " << mLvl << std::endl <<
                 "Speed: " << mSpd << std::endl;*/
}

int hero::getLvl() {
    return mLvl;
}

int hero::getSpd() {
    return mSpd;
}
void hero::setSpd(int spd) {
    mSpd += spd;
    QString updateSpd = "UPDATE helt SET spd = :spd WHERE ID = :ID";
    QSqlQuery Qspd;
    Qspd.prepare(updateSpd);
    Qspd.bindValue(":ID", mKarakter);
    Qspd.bindValue(":spd", mSpd);

    if (!Qspd.exec()) {
        qDebug() << "Failed" << Qspd.lastError().text();
    }
}



std::string hero::getNavn() {
    return mNavn;
}

void hero::getHit(int av) {
    mHp -= av;
}

int hero::getGold() {
    return mGold;
}
void hero::setGold(int gold) {
    mGold += gold;
    QString updateGold = "UPDATE helt SET gold = :gold WHERE ID = :ID";
    QSqlQuery Qgold;
    Qgold.prepare(updateGold);
    Qgold.bindValue(":ID", mKarakter);
    Qgold.bindValue(":gold", mGold);

    if (!Qgold.exec()) {
        qDebug() << "Failed" << Qgold.lastError().text();
    }
}
