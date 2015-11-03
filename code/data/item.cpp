#include "item.h"
#include <QDebug>

Item::Item(QString name, QString shortDesc, QString detailedDesc, int daysLeft, int hoursLeft, int minutesLeft, Rarity rarityGrade)
{
    itemName            = name;
    shortDescription    = shortDesc;
    detailedDescription = detailedDesc;
    itemRarity          = rarityGrade;

    timeCreated         = QDateTime::currentDateTime();
    timeCreatedEpoch    = timeCreated.toMSecsSinceEpoch();

    timeEnding = timeCreated.addSecs( (daysLeft*86400 + hoursLeft*3600 + minutesLeft * 60) );
    timeEndingEpoch = timeEnding.toMSecsSinceEpoch();

    timeLeftEpoch = timeEndingEpoch - timeCreatedEpoch;
    endingSoon = false;
    userWarned = false;
    userWarned30Min = false;
    userWarned60Min = false;
}

QString Item::getName()
{
    return itemName;
}

QString Item::getShortDescription()
{
    return shortDescription;
}

QString Item::getDetailedDescription()
{
    return detailedDescription;
}

QString Item::getTimeLeft(bool detailedOnDemand)
{
    if(detailedOnDemand || endingSoon)
    {
        timeLeftEpoch = timeEndingEpoch - QDateTime::currentDateTime().toMSecsSinceEpoch();
        int days    = timeLeftEpoch /(1000*60*60*24);
        int hours   = (timeLeftEpoch % (1000*60*60*24) / (1000*60*60));
        int mins    = ((timeLeftEpoch % (1000*60*60*24)) %(1000*60*60) / (1000*60));
        int secs    = (((timeLeftEpoch % (1000*60*60*24)) %(1000*60*60) % (1000*60)) / 1000);

        QString timeLeft(QString::number(days) + QString("d : ") + QString::number(hours) + QString("h : ") + QString::number(mins) + QString("m : ") + QString::number(secs) + QString("s") );
        return timeLeft;
    }
    else if (!endingSoon)
    {
        timeLeftEpoch = timeEndingEpoch - QDateTime::currentDateTime().toMSecsSinceEpoch();
        int days    = timeLeftEpoch /(1000*60*60*24);
        int hours   = (timeLeftEpoch % (1000*60*60*24) / (1000*60*60));
        int mins    = ((timeLeftEpoch % (1000*60*60*24)) %(1000*60*60) / (1000*60));
        QString timeLeft(QString::number(days) + QString("d : ") + QString::number(hours) + QString("h : ") + QString::number(mins) + QString("m"));
        return timeLeft;
    }
    else
        return "N/A";
}

Item::Rarity Item::getItemRarity()
{
    return itemRarity;
}

QString Item::getItemRarityAsString()
{
    switch (itemRarity)
    {
    case Rarity_Normal:
        return "Rarity_Normal";
    case Rarity_Magic:
        return "Rarity_Magic";
    case Rarity_Rare:
        return "Rarity_Rare";
    case Rarity_Set:
        return "Rarity_Set";
    case Rarity_Legendary:
        return "Rarity_Legendary";
    case Rarity_Unknown:
        return "Rarity_Unknown";
    default:
        return "Rarity_Unknown";
    }
}

int Item::updateAndGetRemainingTime()
{
    timeLeftEpoch = timeEndingEpoch - QDateTime::currentDateTime().toMSecsSinceEpoch();
    return timeLeftEpoch;
}

int Item::getTimeLeftInMSecondsSinceEpoch()
{
    return timeLeftEpoch;
}

void Item::setName(QString name)
{
    itemName = name;
}

void Item::setShortDescription(QString desc)
{
    shortDescription = desc;
}

void Item::setDetailedDescription(QString desc)
{
    detailedDescription = desc;
}

void Item::setTimeLeft(QString time)
{
}

void Item::updateRemainingTime()
{
    timeLeftEpoch = timeEndingEpoch - QDateTime::currentDateTime().toMSecsSinceEpoch();
}

void Item::setEndingSoonStatus(bool status)
{
    endingSoon = status;
}

void Item::setUserWarned(bool warned)
{
    userWarned = warned;
}

void Item::setUserWarned30Min(bool warned)
{
    userWarned30Min = warned;
}

void Item::setUserWarned60Min(bool warned)
{
    userWarned60Min = warned;
}

bool Item::isUserWarned()
{
    return userWarned;
}

bool Item::isUserWarned30Min()
{
    return userWarned30Min;
}

bool Item::isUserWarned60Min()
{
    return userWarned60Min;
}
