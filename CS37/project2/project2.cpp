#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Function to calculate the total damage of all enemy bots and the boss
float matrix_power(int botsPower[], int botsCount, float bossPower) {
    float totalDamage = 0;
    for (int i = 0; i < botsCount; i++) {
        totalDamage += botsPower[i];
    }
    totalDamage += bossPower;
    return totalDamage;
}

// Function template to calculate the power needed for micro missiles
template <typename T>
T single_missile_power(T power) {
    if (power <= 15) {
        return 2 * power;
    } else {
        return 5 * power;
    }
}

// Function to load the defense matrix power
void load_dva(float &defenseMatrix, float matrixPowerRequired) {
    if (defenseMatrix < matrixPowerRequired) {
        defenseMatrix = matrixPowerRequired;
    }
}

// Function to load the micro missiles
void load_dva(int &microMissiles, float missilePowerRequired) {
    int missilesNeeded = ceil(missilePowerRequired / 60.0);
    if (missilesNeeded > microMissiles) {
        microMissiles = missilesNeeded;
    }
}

int main() {
    ifstream combatInfo("combat.txt");
    if (!combatInfo.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    int botsCount;
    combatInfo >> botsCount;

    int botsPower[botsCount];
    for (int i = 0; i < botsCount; i++) {
        combatInfo >> botsPower[i];
    }

    float bossPower;
    combatInfo >> bossPower;

    int microMissiles;
    combatInfo >> microMissiles;
    float defenseMatrix;
    combatInfo >> defenseMatrix;

    combatInfo.close();

    float matrixPowerRequired = matrix_power(botsPower, botsCount, bossPower);
    float missilePowerRequired = 0;

    for (int i = 0; i < botsCount; i++) {
        missilePowerRequired += single_missile_power(botsPower[i]);
    }
    missilePowerRequired += single_missile_power(bossPower);

    load_dva(defenseMatrix, matrixPowerRequired);
    load_dva(microMissiles, missilePowerRequired);

    ofstream report("report.txt");
    if (!report.is_open()) {
        cerr << "Error: Unable to create report file." << endl;
        return 1;
    }

    report << "D.Va's Combat Report" << endl;
    report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << "." << endl;
    report << "Loaded mech with " << microMissiles << " micro missiles and the defense matrix with power " << defenseMatrix << "." << endl;
    report << "Ready for combat!" << endl;

    report.close();

    return 0;
}
