//============================================================================
// Name        : nerf.cpp
// Author      : Grant Simpson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "NerfGun.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    vector<NerfGun> nerfGuns;

    nerfGuns.push_back(NerfGun("Model T Nerf", 30, 55));
    nerfGuns.push_back(NerfGun("Harvard Nerf 1", 15, 35));
    nerfGuns.push_back(NerfGun("Nerf++", 50, 130));
    nerfGuns.push_back(NerfGun("Nerfosoft", 60, 110));
    nerfGuns.push_back(NerfGun("iNerf", 45, 90));

    for (auto gun : nerfGuns)
        cout << gun << endl;

    cout << endl;
    //  string model = "Foo";
    //  int range = 10;
    //  int capacity = 55;
    //
    //  NerfGun ng(model, range, capacity);
    //
    //  cout << ng << endl;
    //
    //  ng.fire();
    //  cout << ng << endl;
    //
    //  ng.reload(1);
    //  cout << ng << endl;
    //
    //  --ng;
    //  cout << ng << endl;
    //
    //  ng += 1;
    //  cout << ng << endl;

    return 0;
}
