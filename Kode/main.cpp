#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>

#include <cstdlib>

#include <chrono>
#include <thread>

#include "hero.h"
#include "enemy.h"
#include "diverse.h"
#include "cave.h"

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Spil"); // Ret til det schema navn du har valgt
    db.setUserName("sammy");       // Ret brugernavn
    db.setPassword("password");   // Ret password
    db.open();

    diverse d1;
    std::string text;
    int state = 0;
    int helt = 0;

    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        if(state == 0) {                                            // Menu screen
            std::system("clear");
            text = "Welcome To Hero Simulator 3!";
            d1.slowPrint(text);

            std::cout << std::endl;
            while(1) {
                text = "(1) Create Hero";
                d1.slowPrint(text);

                text = "(2) Load Hero";
                d1.slowPrint(text);

                text = "(3) Delete Hero";
                d1.slowPrint(text);

                std::cout << std::endl;
                text = "(0) Exit Game";
                d1.slowPrint(text);

                std::cin >> state;
                std::system("clear");
                if(state == 0) {
                    break;
                }


                if(state > 3 || state < 1) {
                    state = 0;
                } else {
                    break;
                }

            }
            if(state == 0) {
                break;
            }

        } else if(state == 1) {                                     // Create character
            std::string navn;
            int ad, hp, xp, lvl, spd, gold;

            std::system("clear");
            text = "Name Of Character: ";
            d1.slowPrint(text);
            std::cin >> navn;
            std::cout << std::endl;

            ad = 2;
            hp = 10;
            xp = 0;
            lvl = 1;
            spd = 15;
            gold = 0;

            d1.insert(navn,ad,hp,xp,lvl,spd,gold);

            QSqlQuery helte;
            helte.exec(QString::fromStdString("SELECT ID FROM helt"));
            while (helte.next()) {
                int ID = helte.value(0).toInt();
                if (helt<ID) {
                    helt = ID;
                }
            }

            std::cin.ignore();
            state = 4;

        } else if(state == 2) {                                     // Select character
            QSqlQuery helte;
            int i = 0;
            while(i == 0) {
                std::system("clear");
                helte.exec(QString::fromStdString("SELECT * FROM helt"));
                while (helte.next()) {
                    d1.slowPrint("(" + helte.value(1).toString().toStdString() + ")");
                    d1.slowPrint("Name: " + helte.value(0).toString().toStdString());
                    d1.slowPrint("   Attack: " + helte.value(2).toString().toStdString());
                    d1.slowPrint("   Health: " + helte.value(3).toString().toStdString());
                    d1.slowPrint("   Xp: " + helte.value(4).toString().toStdString());
                    d1.slowPrint("   Level: " + helte.value(5).toString().toStdString());
                    d1.slowPrint("   Speed: " + helte.value(6).toString().toStdString());
                    d1.slowPrint("   Gold: " + helte.value(7).toString().toStdString());
                    std::cout << std::endl;
                }
                std::cin >> helt;
                helte.exec(QString::fromStdString("SELECT ID FROM helt"));
                while (helte.next()) {

                    int ID = helte.value(0).toInt();
                    std::cout << "ID: " << ID << " helt: " << helt << std::endl;
                    if(helt == ID) {
                        state = 4;
                        i = 1;
                        break;
                    } else if(helt == 0) {
                        state = 0;
                        i = 1;
                    }
                }
            }
        } else if(state == 3) {                                     // Delete character
            QSqlQuery helte;
            int i = 0;
            while(i == 0) {  // This while loop might not be needed
                std::system("clear");
                helte.exec(QString::fromStdString("SELECT * FROM helt"));
                while (helte.next()) {
                    d1.slowPrint("(" + helte.value(1).toString().toStdString() + ")");
                    d1.slowPrint("Name: " + helte.value(0).toString().toStdString());
                    d1.slowPrint("   Attack: " + helte.value(2).toString().toStdString());
                    d1.slowPrint("   Health: " + helte.value(3).toString().toStdString());
                    d1.slowPrint("   Xp: " + helte.value(4).toString().toStdString());
                    d1.slowPrint("   Level: " + helte.value(5).toString().toStdString());
                    d1.slowPrint("   Speed: " + helte.value(6).toString().toStdString());
                    std::cout << std::endl;
                }
                std::cin >> helt;
                helte.exec(QString::fromStdString("SELECT ID FROM helt"));
                while (helte.next()) {

                    int ID = helte.value(0).toInt();
                    std::cout << "ID: " << ID << " helt: " << helt << std::endl;
                    if(helt == ID) {
                        state = 0;
                        i = 1;
                        d1.del(ID);
                        break;
                    } else if(helt == 0) {
                        state = 0;
                        i = 1;
                    }
                }
            }
        } else if(state == 4) {                                     // Choose what to do
            int path = 0;
            hero h(helt);
            std::system("clear");
            text = "You Have Loaded Character: ";
            d1.slowPrint(text + h.getNavn());

            std::cout << std::endl;

            text = "(1) Fight Enemies";
            d1.slowPrint(text);
            text = "(2) Explore Caves";
            d1.slowPrint(text);
            text = "(3) Enter Shop";
            d1.slowPrint(text);

            // insert future functions

            std::cout << std::endl;

            text = "(0) Back To Menu";
            d1.slowPrint(text);

            std::cin >> path;


            while(1) {
                if(path == 1) {                                     // Choose enemy
                    int enemi = 0;
                    QSqlQuery fjende;
                    int i = 0;

                    std::system("clear");
                    text = "Select Enemy To Fight:";
                    d1.slowPrint(text);
                    fjende.exec(QString::fromStdString("SELECT ID, name FROM fjende ORDER BY ID"));
                    while (fjende.next()) {
                        d1.slowPrint("(" + fjende.value("ID").toString().toStdString() + ")");
                        d1.slowPrint("Name: " + fjende.value("name").toString().toStdString());

                        std::cout << std::endl;
                    }
                    text = "(0) Back To Menu";
                    std::cout << std::endl;
                    d1.slowPrint(text);

                    std::cin >> enemi;

                    if(enemi == 0) {
                        path = 0;
                        break;
                    }

                    enemy e(enemi);

                    std::system("clear");


                    d1.slowPrint(h.getNavn() + " Is Fighthing " + e.getNavn());

                    while (h.getHp() > 0 && e.getHp() > 0 && e.getHp() < 10000) {   //Fight enemy
                        std::cout << std::endl;
                        d1.slowPrint(h.getNavn());
                        d1.slowPrint("   Hp: " + std::to_string(h.getHp()));
                        d1.slowPrint("   Attack: " + std::to_string(h.getAd()));
                        d1.slowPrint(e.getNavn());
                        d1.slowPrint("   Hp: " + std::to_string(e.getHp()));
                        d1.slowPrint("   Attack: " + std::to_string(e.getAd()));
                        if(h.getSpd() >= e.getSpd()) {
                            d1.slowPrint(h.getNavn() + " Hits " + e.getNavn());
                            e.getHit(h.getAd());
                            if(e.getHp() <= 0) {
                                d1.slowPrint(e.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(h.getNavn());
                                d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                std::cout << std::endl;
                                h.setXp(e.getXp());
                                d1.slowPrint("Xp: " + std::to_string(h.getXp()) + "/" + std::to_string(h.getLvl()*1000));
                                d1.slowPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::cin.ignore();
                                continue;
                            }
                            d1.slowPrint(e.getNavn() + " Hits " + h.getNavn());
                            h.getHit(e.getAd());
                            if(h.getHp() <= 0) {
                                d1.slowPrint(h.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(e.getNavn());
                                d1.slowPrint("   Hp Remaining: " + std::to_string(e.getHp()));
                                d1.slowPrint("   Ad: " + std::to_string(e.getAd()));
                                std::cout << std::endl;
                                d1.slowPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::cin.ignore();
                                continue;
                            }

                        } else if(h.getSpd() < e.getSpd()) {
                            d1.slowPrint(e.getNavn() + " Hits " + h.getNavn());
                            h.getHit(e.getAd());
                            if(h.getHp() <= 0) {
                                d1.slowPrint(h.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(e.getNavn());
                                d1.slowPrint("   Hp Remaining: " + std::to_string(e.getHp()));
                                d1.slowPrint("   Ad: " + std::to_string(e.getAd()));
                                std::cout << std::endl;
                                d1.slowPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::cin.ignore();
                                continue;
                            }
                            d1.slowPrint(h.getNavn() + " Hits " + e.getNavn());
                            e.getHit(h.getAd());
                            if(e.getHp() <= 0) {
                                d1.slowPrint(e.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(h.getNavn());
                                d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                std::cout << std::endl;
                                h.setXp(e.getXp());
                                d1.slowPrint("Lvl: " + std::to_string(h.getLvl()));
                                d1.slowPrint("Xp: " + std::to_string(h.getXp()) + "/" + std::to_string(h.getLvl()*1000));
                                d1.slowPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::cin.ignore();
                                continue;
                            }
                        }
                    }
                } else if(path == 2) {                              // Explore caves
                    int caves;
                    QSqlQuery Qcave;
                    std::system("clear");
                    text = "Select Cave To Explore:";
                    d1.slowPrint(text);
                    Qcave.exec(QString::fromStdString("SELECT ID, name FROM grotte ORDER BY ID"));
                    while (Qcave.next()) {
                        d1.slowPrint("(" + Qcave.value("ID").toString().toStdString() + ")");
                        d1.slowPrint("Name: " + Qcave.value("name").toString().toStdString());

                        std::cout << std::endl;
                    }

                    text = "(0) Back To Menu";
                    std::cout << std::endl;
                    d1.slowPrint(text);

                    std::cin >> caves;



                    if(caves == 0) {
                        path = 0;
                        break;
                    }

                    cave c(caves);

                    std::system("clear");

                    d1.slowPrint(h.getNavn() + " Enters The " + c.getNavn());

                    c.enemies();

                    while(1) {
                        int next = c.nextEnemy();
                        //std::cout << h.back() << std::endl;
                        //h.pop_back();

                        enemy e(next);

                        d1.slowPrint("A " + e.getNavn() + " Approaches You");

                        while (h.getHp() > 0 && e.getHp() > 0 && e.getHp() < 10000) {   //Fight enemy
                            std::cout << std::endl;
                            d1.slowPrint(h.getNavn());
                            d1.slowPrint("   Hp: " + std::to_string(h.getHp()));
                            d1.slowPrint("   Attack: " + std::to_string(h.getAd()));
                            d1.slowPrint(e.getNavn());
                            d1.slowPrint("   Hp: " + std::to_string(e.getHp()));
                            d1.slowPrint("   Attack: " + std::to_string(e.getAd()));
                            if(h.getSpd() >= e.getSpd()) {
                                d1.slowPrint(h.getNavn() + " Hits " + e.getNavn());
                                e.getHit(h.getAd());
                                if(e.getHp() <= 0) {
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn() + " Dropped " + std::to_string(e.getGold()) + " Gold");
                                    h.setGold(e.getGold());
                                    d1.slowPrint(h.getNavn() + " Has " + std::to_string(h.getGold()) + " Gold");
                                    std::cout << std::endl;
                                    d1.slowPrint(h.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                    std::cout << std::endl;
                                    d1.slowPrint("Press Enter To Continue");
                                    std::cin.ignore();
                                    std::cin.ignore();
                                    std::system("clear");
                                    continue;
                                }
                                d1.slowPrint(e.getNavn() + " Hits " + h.getNavn());
                                h.getHit(e.getAd());
                                if(h.getHp() <= 0) {
                                    d1.slowPrint(h.getNavn() + " Is Dead");
                                    std::cout << std::endl;
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(e.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(e.getAd()));
                                    std::cout << std::endl;
                                    d1.slowPrint("Press Enter To Continue");
                                    std::cin.ignore();
                                    std::cin.ignore();
                                    path = 2;
                                    caves = 0;
                                    break;
                                }

                            } else if(h.getSpd() < e.getSpd()) {
                                d1.slowPrint(e.getNavn() + " Hits " + h.getNavn());
                                h.getHit(e.getAd());
                                if(h.getHp() <= 0) {
                                    d1.slowPrint(h.getNavn() + " Is Dead");
                                    std::cout << std::endl;
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(e.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(e.getAd()));
                                    std::cout << std::endl;
                                    d1.slowPrint("Press Enter To Continue");
                                    std::cin.ignore();
                                    std::cin.ignore();
                                    path = 2;
                                    caves = 0;
                                    break;
                                }
                                d1.slowPrint(h.getNavn() + " Hits " + e.getNavn());
                                e.getHit(h.getAd());
                                if(e.getHp() <= 0) {
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn() + " Dropped " + std::to_string(e.getGold()) + " Gold");
                                    h.setGold(e.getGold());
                                    d1.slowPrint(h.getNavn() + " Has " + std::to_string(h.getGold()) + " Gold");

                                    std::cout << std::endl;
                                    d1.slowPrint(h.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                    std::cout << std::endl;
                                    d1.slowPrint("Press Enter To Continue");
                                    std::cin.ignore();
                                    std::cin.ignore();
                                    std::system("clear");
                                    continue;
                                }
                            }
                        }

                        if(c.emptyCheck()) {
                            if(h.getHp() > 0) {
                                d1.slowPrint(h.getNavn() + " Successfully Looted " + std::to_string(c.getGold()) + " Gold From The " + c.getNavn());
                                h.setGold(c.getGold());
                                d1.slowPrint(h.getNavn() + " Has " + std::to_string(h.getGold()) + " Gold");
                                std::cout << std::endl;
                                d1.slowPrint(h.getNavn());
                                d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                h.setXp(0);
                                std::cout << std::endl;
                                d1.slowPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::system("clear");
                            }
                            path = 2;
                            caves = 0;
                            state = 4;
                            break;
                        }
                    }

                } else {
                    state = 0;
                    break;
                }
            }
        }
    }

    //for (int i = 0; i < 1000; ++i) {
    //    std::cout << i << std::flush << std::endl;
    //    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    //}


// To Update:

    /*QString update = "UPDATE helt SET lvl = :lvl WHERE ID = :ID";
    QSqlQuery lvl;
    lvl.prepare(update);
    lvl.bindValue(":ID", Hej);
    lvl.bindValue(":lvl", Hallo);

    if (!lvl.exec()) {
        qDebug() << "Failed" << lvl.lastError().text();
    } */

    /*
    QSqlQuery query;
    QString hej = QString::fromStdString("SELECT * FROM helt WHERE ID = " + std::to_string(2));
    query.exec(QString::fromStdString("SELECT * FROM helt WHERE ID = " + std::to_string(2))); // tasks er her navnet pÃ¥ en tabel, ikke et schema
    while (query.next()) {
        QString name = query.value(0).toString();
        int id = query.value(1).toInt();
        std::cout << query.value(0).toString().toStdString() << std::flush << std::endl;
        qDebug() << "Id:" << id << "Name:" << name;

    }
*/
    return 0;
}
