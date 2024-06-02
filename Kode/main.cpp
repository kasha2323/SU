#include <QCoreApplication>
#include <QtSql>
#include <QSqlDatabase>
#include <iostream>

#include <math.h>

#include <cstdlib>

#include <chrono>
#include <thread>

#include "hero.h"
#include "enemy.h"
#include "diverse.h"
#include "cave.h"
#include "weapon.h"
#include "shop.h"

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("Spil"); // Ret til det schema navn du har valgt
    db.setUserName("sammy");       // Ret brugernavn
    db.setPassword("password");   // Ret password
    db.open();

    diverse d1;
    weapon w;
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
                    d1.slowPrint("(" + helte.value("ID").toString().toStdString() + ")");
                    d1.slowPrint("Name: " + helte.value("name").toString().toStdString());
                    d1.slowPrint("   Attack: " + helte.value("ad").toString().toStdString());
                    d1.slowPrint("   Health: " + helte.value("hp").toString().toStdString());
                    d1.slowPrint("   Xp: " + helte.value("xp").toString().toStdString());
                    d1.slowPrint("   Level: " + helte.value("lvl").toString().toStdString());
                    d1.slowPrint("   Speed: " + helte.value("spd").toString().toStdString());
                    d1.slowPrint("   Gold: " + helte.value("gold").toString().toStdString());
                    d1.slowPrint("   Mana: " + helte.value("mana").toString().toStdString());
                    std::cout << std::endl;
                }
                std::cin >> helt;
                helte.exec(QString::fromStdString("SELECT ID FROM helt"));
                while (helte.next()) {

                    int ID = helte.value(0).toInt();

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
            d1.slowPrint("You Have Loaded Character " + h.getNavn() + " With The " + w.getName());

            std::cout << std::endl;

            text = "(1) Fight Enemies";
            d1.slowPrint(text);
            text = "(2) Explore Caves";
            d1.slowPrint(text);
            text = "(3) Enter Shop";
            d1.slowPrint(text);
            text = "(4) Choose Weapon";
            d1.slowPrint(text);

            // insert future functions

            std::cout << std::endl;

            text = "(0) Back To Menu";
            d1.slowPrint(text);

            std::cin >> path;


            while(1) {
                if(path == 1) {                                     // Choose enemy
                    h.setHp(0);
                    h.setMana(0);
                    int enemi = 0;
                    QSqlQuery fjende;
                    int i = 0;

                    std::system("clear");
                    text = "Select Enemy To Fight:";
                    d1.slowPrint(text);
                    fjende.exec(QString::fromStdString("SELECT fjende.ID, fjende.name, fjende.typeID, type.name FROM fjende, type WHERE fjende.typeID = type.ID ORDER BY ID"));
                    while (fjende.next()) {
                        d1.slowPrint("(" + fjende.value("fjende.ID").toString().toStdString() + ")");
                        d1.slowPrint("Name: " + fjende.value("fjende.name").toString().toStdString());
                        d1.fastPrint("   Type: " + fjende.value("type.name").toString().toStdString());
                        int type = fjende.value("typeID").toInt();
                        if (w.type(type) == 2) {
                            d1.slowPrint("   Strong Against");
                        } else if (w.type(type) == 0.5) {
                            d1.slowPrint("   Weak Against");
                        }

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

                    double adv = w.type(e.getType());

                    d1.slowPrint(h.getNavn() + " Is Fighthing " + e.getNavn());

                    while (h.getHp() > 0 && e.getHp() > 0 && e.getHp() < 10000) {   //Fight enemy
                        std::cout << std::endl;
                        int i = 1;
                        std::string weaponHit;

                        d1.slowPrint(h.getNavn());
                        d1.fastPrint("   Hp: " + std::to_string(h.getHp()));
                        d1.fastPrint("   Attack: " + std::to_string(h.getAd()));
                        d1.fastPrint("   Mana: " + std::to_string(h.getMana()) + "/" + std::to_string(w.getMana()));
                        if(w.getMana() > h.getMana()) {
                            i = 0;
                            adv = 1;
                            weaponHit = "Fists";
                        } else {
                            h.drainMana(w.getMana());
                            weaponHit = w.getName();
                        }
                        d1.slowPrint(e.getNavn());
                        d1.fastPrint("   Hp: " + std::to_string(e.getHp()));
                        d1.fastPrint("   Attack: " + std::to_string(e.getAd()));



                        if(h.getSpd() >= e.getSpd()) {
                            d1.slowPrint(h.getNavn() + " Hits " + e.getNavn() + " With The " + weaponHit);
                            e.getHit((h.getAd()+w.getDamage()*i)*adv);
                            if(e.getHp() <= 0) {
                                d1.slowPrint(e.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(h.getNavn());
                                d1.fastPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                d1.fastPrint("   Ad: " + std::to_string(h.getAd()));
                                d1.fastPrint("   Weapon: " + std::to_string(w.getDamage()));
                                d1.fastPrint("   Multiplier: " + std::to_string(adv));
                                d1.fastPrint("   Damage: " + std::to_string(static_cast<int>((h.getAd()+w.getDamage()*i)*adv)));
                                std::cout << std::endl;
                                h.setXp(e.getXp());
                                d1.slowPrint("Lvl: " + std::to_string(h.getLvl()));
                                d1.slowPrint("Xp: " + std::to_string(h.getXp()) + "/" + std::to_string(h.getLvl()*1000));
                                d1.fastPrint("Press Enter To Continue");
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
                            d1.slowPrint(h.getNavn() + " Hits " + e.getNavn() + " With The " + weaponHit);
                            e.getHit((h.getAd()+w.getDamage()*i)*adv);
                            if(e.getHp() <= 0) {
                                d1.slowPrint(e.getNavn() + " Is Dead");
                                std::cout << std::endl;
                                std::cout << std::endl;
                                d1.slowPrint(h.getNavn());
                                d1.fastPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                d1.fastPrint("   Ad: " + std::to_string(h.getAd()));
                                d1.fastPrint("   Weapon: " + std::to_string(w.getDamage()));
                                d1.fastPrint("   Multiplier: " + std::to_string(adv));
                                d1.fastPrint("   Damage: " + std::to_string(static_cast<int>((h.getAd()+w.getDamage()*i)*adv)));
                                std::cout << std::endl;
                                h.setXp(e.getXp());
                                d1.slowPrint("Lvl: " + std::to_string(h.getLvl()));
                                d1.slowPrint("Xp: " + std::to_string(h.getXp()) + "/" + std::to_string(h.getLvl()*1000));
                                d1.fastPrint("Press Enter To Continue");
                                std::cin.ignore();
                                std::cin.ignore();
                                continue;
                            }
                        }
                    }
                } else if(path == 2) {                              // Explore caves
                    int caves;
                    h.setHp(0);
                    h.setMana(0);
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

                    while(caves >=1 && caves <= 7) {
                        int next = c.nextEnemy();


                        enemy e(next);
                        double adv = w.type(e.getType());



                        d1.slowPrint("A " + e.getNavn() + " Approaches You");

                        while (h.getHp() > 0 && e.getHp() > 0 && e.getHp() < 10000) {   //Fight enemy
                            std::cout << std::endl;
                            std::string weaponHit;
                            d1.slowPrint(h.getNavn());
                            d1.slowPrint("   Hp: " + std::to_string(h.getHp()));
                            d1.slowPrint("   Attack: " + std::to_string(h.getAd()));
                            d1.slowPrint("   Mana: " + std::to_string(h.getMana()) + "/" + std::to_string(w.getMana()));
                            d1.slowPrint(e.getNavn());
                            d1.slowPrint("   Hp: " + std::to_string(e.getHp()));
                            d1.slowPrint("   Attack: " + std::to_string(e.getAd()));
                            int i = 1;
                            if(w.getMana() > h.getMana()) {
                                i = 0;
                                adv = 1;
                                weaponHit = "Fists";
                            } else {
                                h.drainMana(w.getMana());
                                weaponHit = w.getName();
                            }
                            if(h.getSpd() >= e.getSpd()) {
                                d1.slowPrint(h.getNavn() + " Hits " + e.getNavn() + " With The " + weaponHit);
                                e.getHit((h.getAd()+w.getDamage()*i)*adv);
                                if(e.getHp() <= 0) {
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn() + " Dropped " + std::to_string(e.getGold()) + " Gold");
                                    h.setGold(e.getGold());
                                    d1.slowPrint(h.getNavn() + " Has " + std::to_string(h.getGold()) + " Gold");
                                    std::cout << std::endl;
                                    d1.slowPrint(h.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                    d1.slowPrint("   Weapon: " + std::to_string(w.getDamage()));
                                    d1.slowPrint("   Multiplier: " + std::to_string(adv));
                                    d1.slowPrint("   Damage: " + std::to_string(static_cast<int>((h.getAd()+w.getDamage()*i)*adv)));
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
                                d1.slowPrint(h.getNavn() + " Hits " + e.getNavn() + " With The " + weaponHit);
                                e.getHit((h.getAd()+w.getDamage()*i)*adv);
                                if(e.getHp() <= 0) {
                                    std::cout << std::endl;
                                    d1.slowPrint(e.getNavn() + " Dropped " + std::to_string(e.getGold()) + " Gold");
                                    h.setGold(e.getGold());
                                    d1.slowPrint(h.getNavn() + " Has " + std::to_string(h.getGold()) + " Gold");

                                    std::cout << std::endl;
                                    d1.slowPrint(h.getNavn());
                                    d1.slowPrint("   Hp Remaining: " + std::to_string(h.getHp()));
                                    d1.slowPrint("   Ad: " + std::to_string(h.getAd()));
                                    d1.slowPrint("   Weapon: " + std::to_string(w.getDamage()));
                                    d1.slowPrint("   Multiplier: " + std::to_string(adv));
                                    d1.slowPrint("   Damage: " + std::to_string(static_cast<int>((h.getAd()+w.getDamage()*i)*adv)));
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
                                d1.slowPrint("   Mana: " + std::to_string(h.getMana()) + "/" + std::to_string(w.getMana()));


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
                } else if(path == 3) {
                    int butik;
                    QSqlQuery Qshop;
                    QSqlQuery Qpurchased;
                    QSqlQuery Qrequire;
                    QSqlQuery Qrequire2;
                    std::system("clear");


                        d1.slowPrint("You Enter The Shop With " + std::to_string(h.getGold()) + " Gold:");
                        std::cout << std::endl;
                    while(1) {


                        Qshop.exec(QString::fromStdString("SELECT items.ID, items.name, items.gold, items.damage, type.name, items.ID, items.mana FROM items, type WHERE type.ID = items.typeID ORDER BY ID"));
                        while (Qshop.next()) {
                            std::string ID = Qshop.value("items.ID").toString().toStdString();
                            d1.slowPrint("(" + ID + ")");
                            d1.slowPrint(Qshop.value("items.name").toString().toStdString());
                            d1.fastPrint("   Damage: " + Qshop.value("items.damage").toString().toStdString());
                            d1.fastPrint("   Price: " + Qshop.value("items.gold").toString().toStdString());
                            d1.fastPrint("   Type: " + Qshop.value("type.name").toString().toStdString());
                            d1.fastPrint("   Mana: " + Qshop.value("items.mana").toString().toStdString());

                            Qpurchased.exec(QString::fromStdString("SELECT ID FROM purchased WHERE itemID = " + ID + " AND heltID = " + std::to_string(h.getID())));
                            Qrequire.exec(QString::fromStdString("SELECT ID FROM requirement WHERE itemID = " + ID));
                            if (Qpurchased.next()) {
                                d1.fastPrint("      Purchased");
                            } else if (Qrequire.next()) {
                                Qrequire2.exec(QString::fromStdString("SELECT items.name FROM requirement, items WHERE requirement.itemID = " + ID + " AND requirement.requireID = items.ID"));
                                while (Qrequire2.next()) {
                                    d1.fastPrint("      Requires: " + Qrequire2.value("items.name").toString().toStdString());
                                }

                            }

                            std::cout << std::endl;
                        }


                        std::cout << std::endl;
                        d1.slowPrint("(0) Back To Menu");

                        std::cin >> butik;

                        if(butik == 0) {
                            path = 0;
                            break;
                        }

                        shop s(butik);

                        int guld;
                        Qshop.exec(QString::fromStdString("SELECT gold FROM items WHERE ID = " + std::to_string(butik)));
                        while (Qshop.next()) {
                            guld = Qshop.value("gold").toInt();
                        }




                        if (guld <= h.getGold()) {
                            std::system("clear");

                            int loan = 0;
                            s.insert(h.getID(), loan);
                            h.setGold(loan);
                        } else {
                            std::system("clear");
                            d1.slowPrint("You Can't Buy That With Only " + std::to_string(h.getGold()) + " Gold!");
                        }
                    }
                    if(butik == 0) {
                        path = 0;
                        break;
                    }
                } else if (path==4){

                    int wep;

                    QSqlQuery Qweapon;
                    std::system("clear");
                    text = "Pick One Of Your Weapons:";
                    d1.slowPrint(text);
                    std::cout << std::endl;
                    d1.slowPrint("(0)");
                    d1.slowPrint("Name: Fists");
                    std::cout << std::endl;

                    Qweapon.exec(QString::fromStdString("SELECT items.ID, items.name, items.damage, type.name, items.mana FROM type, items, purchased WHERE type.ID = items.typeID AND items.ID = purchased.itemID AND purchased.heltID = " + std::to_string(h.getID()) + " ORDER BY ID"));
                    while (Qweapon.next()) {
                        d1.slowPrint("(" + Qweapon.value("items.ID").toString().toStdString() + ")");
                        d1.slowPrint("Name: " + Qweapon.value("items.name").toString().toStdString());
                        d1.slowPrint("Damage: " + Qweapon.value("items.damage").toString().toStdString());
                        d1.slowPrint("Type: " + Qweapon.value("type.name").toString().toStdString());
                        d1.slowPrint("Mana: " + Qweapon.value("items.mana").toString().toStdString());


                        std::cout << std::endl;
                    }


                    std::cout << std::endl;


                    std::cin >> wep;

                    Qweapon.exec(QString::fromStdString("SELECT items.ID FROM items, purchased WHERE items.ID = purchased.itemID AND purchased.heltID = " + std::to_string(h.getID())));
                    while (Qweapon.next()) {

                        int ID = Qweapon.value(0).toInt();

                        if(wep == ID) {

                            w.setWeapon(wep);
                            break;
                        } else if(wep == 0) {
                            w.setWeapon(wep);
                            break;
                        }
                    }





                    path = 0;
                    break;

                } else if (path==0){
                    w.setWeapon(0);
                    state = 0;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}
