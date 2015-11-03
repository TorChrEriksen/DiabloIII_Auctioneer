#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QTime>
#include <QDateTime>

class Item
{

public:
    enum Rarity
    {
        Rarity_Normal,
        Rarity_Magic,
        Rarity_Rare,
        Rarity_Set,
        Rarity_Legendary,
        Rarity_Unknown
    };

public:
    Item(QString name, QString shortDesc = "", QString detailedDesc = "", int daysLeft = 0, int hoursLeft = 0, int minutesLeft = 0, Rarity rarityGrade = Rarity_Unknown);
    QString getName();
    QString getShortDescription();
    QString getDetailedDescription();
    QString getTimeLeft(bool detailedOnDemand = false);
    Rarity getItemRarity();
    QString getItemRarityAsString();

    int updateAndGetRemainingTime();
    int getTimeLeftInMSecondsSinceEpoch();

    void setName(QString name);
    void setShortDescription(QString desc);
    void setDetailedDescription(QString desc);
    void setTimeLeft(QString time);

    void updateRemainingTime();
    void setEndingSoonStatus(bool status);
    void setUserWarned(bool warned);
    void setUserWarned30Min(bool warned);
    void setUserWarned60Min(bool warned);

    bool isUserWarned();
    bool isUserWarned30Min();
    bool isUserWarned60Min();
private:
    QString itemName;
    QString shortDescription;
    QString detailedDescription;
    Rarity itemRarity;

    QDateTime timeCreated;
    QDateTime timeEnding;
    qint64 timeCreatedEpoch;
    qint64 timeEndingEpoch;
    qint64 timeLeftEpoch;

    // flag if the auction is ending soon!
    bool endingSoon;
    bool userWarned, userWarned30Min, userWarned60Min;
};

#endif // ITEM_H
