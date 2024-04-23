#include "hero.h"
#include "random"

hero::hero()
{

}
hero::hero(int hero) {
    mKarakter = hero;
    QSqlQuery query;
    query.exec(QString::fromStdString("SELECT * FROM helt WHERE ID = " + std::to_string(mKarakter)));
    QString navn;
    while (query.next()) {
        navn = query.value(0).toString();
        mAd = query.value(2).toInt();
        mHp = query.value(3).toInt();
        mXp = query.value(4).toInt();
        mLvl = query.value(5).toInt();
        mSpd = query.value(6).toInt();
    }

    mNavn = navn.toStdString();
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
    if(mXp >= mLvl*500) {
        mXp-=mLvl*500;
        ++mLvl;

        std::random_device ran;
        std::uniform_int_distribution<int> R1(1,2);
        std::uniform_int_distribution<int> R2(2,5);
        setAd(R1(ran));
        setHp(R2(ran));
        setSpd(R1(ran));
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

    std::cout << "Navn: "<< mNavn << std::endl <<
                 "Attack: " << mAd << std::endl <<
                 "Health: " << mHp << std::endl <<
                 "Xp: " << mXp << std::endl <<
                 "Level: " << mLvl << std::endl <<
                 "Speed: " << mSpd << std::endl;
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
