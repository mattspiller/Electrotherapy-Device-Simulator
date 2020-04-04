//Matthew Spiller
//Last Edit: April 1, 2020

#include "battery.h"
#include <QString>

Battery::Battery()
{
    batteryLevel = 100; //represents battery percentage
    powerLevel = 0; //by default powerLevel starts at 0.
    rateOfBatteryLoss = 100; //seconds per battery loss of 1% (default 100 seconds per 1% loss at power level 1 [will change as power level increases])
}

int Battery::getBatteryLevel() //returns the current battery level percentage (getter)
{
    return this->batteryLevel;
}

int Battery::getPowerLevel() //returns the current power level of treatment (getter)
{
    return this->powerLevel;
}

QString Battery::getPowerLevelString() //returns the power level as a string, allowing changes in power level to be displayed
{
    QString s = "Power Level: ";
    s.append(QString::number(powerLevel));
    return s;
}

int Battery::getRateOfBatteryLoss() //returns the rate of battery loss (getter)
{
    return this->rateOfBatteryLoss;
}

//reduceBatteryLevel() likely called from electrode class as the electrode is responsible for running the timer when skin contact is made
void Battery::reduceBatteryLevel() //reduce the battery level by 1% (should get run by after some x seconds of treatment)
{
    if(batteryLevel > 1) //if battery level is greater than 1%
    {
        batteryLevel--; //then reduce the battery level by 1%
    }
    else //the battery level is at 1%
    {
        batteryLevel = 0; //the battery level must equal 0
        stopTreatment(); //since the battery is dead, the treatment must stop
    }
}

void Battery::increasePowerLevel() //increases the power level by a value of 1.
{
    if(powerLevel < 100) //only increase power level if it is less than maximum (100)
    {
        powerLevel++;
        rateOfBatteryLoss -= 1;
    }
}

void Battery::decreasePowerLevel() //decreases the power level by a value of 1.
{
    if(powerLevel > 1) //only decreases power level if it is greater than minimum (1)
    {
        powerLevel--;
        rateOfBatteryLoss += 1;
    }
}

void Battery::startTreatment() //begins at lowest power level, battery begins to deplete
{
    powerLevel = 1; //start treatment on lowest active power level
}

void Battery::stopTreatment() //sets power level to 0, battery stops depleting
{
    powerLevel = 0; //stop treatment
    rateOfBatteryLoss = 100; //rate of battery loss is reset to 100.
}
