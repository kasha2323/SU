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

                std::cin >> state;
                if(state > 3 || state < 1) {
                    state = 0;
                    std::system("clear");
                } else {
                    break;
                }
            }
        } else if(state == 1) {                                     // Create character
            std::string navn;
            int ad, hp, xp, lvl, spd;

            std::system("clear");
            text = "Name Of Character: ";
            d1.slowPrint(text);
            std::cin >> navn;
            std::cout << std::endl;

            ad = 2;
            hp = 5;
            xp = 0;
            lvl = 1;
            spd = 15;

            d1.insert(navn,ad,hp,xp,lvl,spd);

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
                    std::cout << std::endl;
                }
                std::cin >> helt;
                helte.exec(QString::fromStdString("SELECT ID FROM helt"));
                while (helte.next()) {

                    int ID = helte.value(0).toInt();
                    std::cout << "ID: " << ID << " helt: " << helt << std::endl;
                    if(helt == ID) {
                        hero h(helt);
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

        }
    }





    hero h(2);

    enemy e(2);

    int Hej = 2;
    int Hallo = 3;

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
