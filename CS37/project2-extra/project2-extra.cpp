#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

// Declaring Battle Class
class Battle {
    friend class Mech;

private:
    int botsPower[10];
    int botsCount;
    float bossPower;

public:
    Battle(int botsPower[], int botsCount, float bossPower);

    float matrix_power();
};

// Declaring Mech Class
class Mech {
private:
    float defenseMatrix;
    int microMissiles;

public:
    Mech(float defenseMatrix = 100.0, int microMissiles = 10);

    static float micro_missile(const Battle& battle);
    void load(float matrixPowerRequired, float missilePowerRequired);

    float getDefenseMatrix() const;
    int getMicroMissiles() const;
};

// Defining Battle Class
Battle::Battle(int botsPower[], int botsCount, float bossPower) : botsCount(botsCount), bossPower(bossPower) {
    copy_n(botsPower, botsCount, this->botsPower);
}

float Battle::matrix_power() {
    float totalDamage = 0;
    for (int i = 0; i < this->botsCount; i++) {
        totalDamage += this->botsPower[i];
    }
    totalDamage += this->bossPower;
    return totalDamage;
}

// Defining Mech Class
Mech::Mech(float defenseMatrix, int microMissiles) : defenseMatrix(defenseMatrix), microMissiles(microMissiles) {}

float Mech::micro_missile(const Battle& battle) {
    float botPower = 0;
    for (int i = 0; i < battle.botsCount; i++) {
        botPower += battle.botsPower[i];
    }
    return (2 * botPower + 5 * battle.bossPower);
}

void Mech::load(float matrixPowerRequired, float missilePowerRequired) {
    if (matrixPowerRequired > this->defenseMatrix) {
        this->defenseMatrix = matrixPowerRequired;
    }
    int missilesNeeded = ceil(missilePowerRequired / 60.0);
    if (missilesNeeded > this->microMissiles) {
        this->microMissiles = missilesNeeded;
    }
}

float Mech::getDefenseMatrix() const {
    return this->defenseMatrix;
}

int Mech::getMicroMissiles() const {
    return this->microMissiles;
}


int main() {
//TODO: Open and read file
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

    combatInfo.close();

//Initialize battle and dva
    Battle dvaBattle(botsPower, botsCount, bossPower);
    Mech dva;

//Calculate power needed
    float matrixPowerRequired = dvaBattle.matrix_power();
    float missilePowerRequired = dva.micro_missile(dvaBattle);

//Load D.Va
    dva.load(matrixPowerRequired, missilePowerRequired);

//TODO: Open and write results to file
    ofstream report("report.txt");
    if (!report.is_open()) {
        cerr << "Error: Unable to create report file." << endl;
        return 1;
    }

    // Write the combat report
    report << "D.Va's Combat Report" << endl;
    report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << "." << endl;
    report << "Loaded mech with " << dva.getMicroMissiles() << " micro missiles and the defense matrix with power " << dva.getDefenseMatrix() << "." << endl;
    report << "Ready for combat!" << endl;

    report.close();

    return 0;
}
