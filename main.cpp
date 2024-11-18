//============================================================================
// Name        : nerf.cpp
// Author      : Grant Simpson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "NerfGun.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxAmmoIndex(const vector<NerfGun>& nerfGunVec);
void displayGunInfo(const vector<NerfGun>& nerfGunVec);
void displayMostAmmo(const vector<NerfGun>& nerfGunVec);

int main() {

    vector<NerfGun> nerfGuns;

    // array<int, 5> count(nerfGuns.size(), 0);
    vector<int> count(5, 0);

    nerfGuns.push_back(NerfGun("Model T Nerf", 30, 55));
    nerfGuns.push_back(NerfGun("Harvard Nerf 1", 15, 45));
    nerfGuns.push_back(NerfGun("Nerf++", 50, 115));
    nerfGuns.push_back(NerfGun("Nerfosoft", 60, 110));
    nerfGuns.push_back(NerfGun("iNerf", 45, 90));

    displayGunInfo(nerfGuns);

    /* initialize random seed: */
    srand(static_cast<uint>(time(nullptr)));

    cout << "Shooting nerf guns at random: " << endl;
    cout << "==============================" << endl;

    try {
        int randomIndex;
        // randomly fire nerf guns
        for (int i = 0; i < 200; i++) {
            randomIndex = (rand() % nerfGuns.size() + 1);
            nerfGuns[randomIndex - 1]--;
            count[randomIndex - 1]++;
        }
    } catch (const exception& e) {
        cout << e.what() << '\n';
    }

    // Output how many times each gun was fired
    for (int i = 0; i < nerfGuns.size(); i++)
        cout << nerfGuns[i].getModel() << " fired " << count[i] << " times."
             << endl
             << endl;

    displayMostAmmo(nerfGuns);

    displayGunInfo(nerfGuns);

    cout << "Reloading nerf guns at random: " << endl;
    cout << "===============================" << endl;
    for (int i = 0; i < 5; i++)
        count[i] = 0;
    try {
        int randomIndex;
        // randomly fire nerf guns
        for (int i = 0; i < 20; i++) {
            randomIndex = (rand() % nerfGuns.size() + 1);
            nerfGuns[randomIndex - 1] += randomIndex;
            count[randomIndex - 1]++;
        }
    } catch (const exception& e) {
        cout << e.what() << '\n';
    }

    displayGunInfo(nerfGuns);

    // Output how many times each gun was fired
    for (int i = 0; i < nerfGuns.size(); i++)
        cout << nerfGuns[i].getModel() << " reloaded " << count[i] << " times."
             << endl
             << endl;

    return 0;
}

int maxAmmoIndex(const vector<NerfGun>& nerfGunVec) {
    int maxIndex = 0;
    for (unsigned int i = 0; i < nerfGunVec.size(); i++) {
        if (nerfGunVec[maxIndex] < nerfGunVec[i])
            maxIndex = i;
    }
    return maxIndex;
}

void displayGunInfo(const vector<NerfGun>& nerfGunVec) {
    cout << "Gun info: " << endl;
    cout << "==========" << endl;
    for (auto gun : nerfGunVec)
        cout << gun << endl;
    cout << endl;
}

void displayMostAmmo(const vector<NerfGun>& nerfGunVec) {
    // Compare ammo in gun
    int maxIndex = maxAmmoIndex(nerfGunVec);
    cout << "---------------------------------------" << endl;
    cout << "Gun with most ammunition: ";
    cout << nerfGunVec[maxIndex].getModel() << endl;
    cout << "---------------------------------------" << endl << endl;
}