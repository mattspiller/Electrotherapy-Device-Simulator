#ifndef BATTERY_H
#define BATTERY_H

#include <QString>

class Battery
{
private:
    int batteryLevel;
    int powerLevel;
    int rateOfBatteryLoss;

public:
    Battery();
    int getBatteryLevel();
    int getPowerLevel();
    QString getPowerLevelString();
    int getRateOfBatteryLoss();
    void reduceBatteryLevel();
    void increasePowerLevel();
    void decreasePowerLevel();
    void startTreatment();
    void stopTreatment();
};

#endif // BATTERY_H
