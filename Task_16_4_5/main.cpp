#include <iostream>
#include <sstream>
using namespace std;

int automatics = 0;

enum shield {
    POWER_ENERGY   = 1 << 0,
    POWER_SOCKET   = 1 << 1,
    LIGHT_HOUSE    = 1 << 2,
    LIGHT_OUTSIDE  = 1 << 3,
    HEATING_HOUSE  = 1 << 4,
    HEATING_WATER  = 1 << 5,
    CONDITIONER    = 1 << 6
};

void time (int i) {
    cout << "\nCurrent time is: ";
    if (i < 10) cout << "0" << i;
    else cout << i;
    cout << ":00\n";
}

bool convert_movement (string movementStr) {
    if (movementStr == "yes" || movementStr == "YES" || movementStr == "Yes") {
        return true;
    }else if (movementStr == "no" || movementStr == "NO" || movementStr == "No") {
        return false;
    }
}


bool convert_light (string lightStr) {
    if (lightStr == "on" || lightStr == "ON" || lightStr == "On") {
        return true;
    }else if (lightStr == "off" || lightStr == "OFF" || lightStr == "Off") {
        return false;
    }
}

void checkTempOUT (int tempOUT) {
    if ((tempOUT < 0) && ((automatics & HEATING_WATER) != HEATING_WATER)) {
        automatics |= HEATING_WATER;
        cout << "Water heating is ON\n";
    }else if ((tempOUT > 5) && ((automatics & HEATING_WATER) == HEATING_WATER)) {
        automatics &= ~HEATING_WATER;
        cout << "Water heating is OFF\n";
    }
}

void checkTempIN (int tempIN) {
    if ((tempIN < 22) && ((automatics & HEATING_HOUSE) != HEATING_HOUSE)) {
        automatics |= HEATING_HOUSE;
        cout << "House heating is ON\n";
    }else if ((tempIN >= 25 ) && ((automatics & HEATING_HOUSE) == HEATING_HOUSE)) {
        automatics &= ~HEATING_HOUSE;
        cout << "House heating is OFF\n";
    }
}

void checkConditioner (int tempIN) {
    if ((tempIN >= 30) && ((automatics & CONDITIONER) != CONDITIONER)) {
        automatics |= CONDITIONER;
        cout << "Conditioner is ON\n";
    }else if ((tempIN <= 25 ) && ((automatics & CONDITIONER) == CONDITIONER)) {
        automatics &= ~CONDITIONER;
        cout << "Conditioner is OFF\n";
    }
}

void checkLightOUT (bool movement, int time) {
    if (((time < 5 || time > 16) && movement) && ((automatics & LIGHT_OUTSIDE) != LIGHT_OUTSIDE)) {
        automatics |= LIGHT_OUTSIDE;
        cout << "Light outside is ON\n";
    }else if (((time >= 5 && time <= 16) && !movement) && ((automatics & LIGHT_OUTSIDE) == LIGHT_OUTSIDE)) {
        automatics &= ~LIGHT_OUTSIDE;
        cout << "Light outside is OFF\n";
    }
}

void checkLightIN (bool light) {
    if ((light) && ((automatics & LIGHT_HOUSE) != LIGHT_HOUSE)) {
        automatics |= LIGHT_HOUSE;
        std::cout << "Light in house is ON\n";
    }
    else if (!light && (automatics & LIGHT_HOUSE) == LIGHT_HOUSE) {
        automatics &= ~LIGHT_HOUSE;
        std::cout << "Light in house is OFF\n";
    }
}

void checkTemperatureLight (int time) {
    int startTime = 16;
    int endTime = 20;
    int hightTemperature = 5000;
    int lowTemperature = 2700;

    cout << "In house light temperature is: ";
    if (time < startTime)
        cout << hightTemperature << 'K' << "\n";
    else if (time < endTime)
        cout << hightTemperature - ((hightTemperature - lowTemperature) /
            (endTime - startTime) * (time - startTime)) << 'K' << "\n";
    else
        cout << lowTemperature << 'K' << "\n";
}

int main() {
    const int total_time = 24;

    bool movement, light;
    int tempIN, tempOUT;

    for (int i = 1; i <= 2; i++) {
        cout << "\nDay " << i << ": \n";

        for (int i = 0; i < total_time; i++) {
            time(i);

            cout << "Input temperature IN and OUT house, light in house(on/off) and movement outside(yes/no): \n";
            string sensors;
            getline(cin, sensors);

            stringstream indicators;
            indicators << sensors;

            string movementStr, lightStr;
            indicators >> tempIN >> tempOUT >> lightStr >> movementStr;

            light = convert_light(lightStr);
            movement = convert_movement(movementStr);

            checkTempOUT (tempOUT);
            checkTempIN (tempIN);
            checkConditioner(tempIN);
            checkLightOUT (movement, i);
            checkLightIN (light);
            if (light) checkTemperatureLight (i);
        }
    }
}