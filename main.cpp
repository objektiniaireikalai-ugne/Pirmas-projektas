#include "funkcijos.h"
#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::chrono;

double sek(steady_clock::time_point p1, steady_clock::time_point p2) {
    return duration<double>(p2 - p1).count();
}

void RusiavimoPasirinkimas(vector<studentas>& grupe, int pasirinkimas) {
    if (pasirinkimas == 1)      sort(grupe.begin(), grupe.end(), RusiuotiPagalVarda);
    else if (pasirinkimas == 2) sort(grupe.begin(), grupe.end(), RusiuotiPagalPavarde);
    else                        sort(grupe.begin(), grupe.end(), RusiuotiPagalBala);
}

void TestuotiFaila(const string& failas, int rusRusis, int kartai) {
    double sumN = 0, sumR = 0, sumD = 0, sumV = 0, sumK = 0, sumViso = 0;
    int n = 0;

    for (int k = 0; k < kartai; k++) {
        vector<studentas> grupe, vargsiukai, kietiakiai;

        auto visoP = steady_clock::now();

        auto t1 = steady_clock::now();
        if (!nuskaitymas(grupe, failas)) {
            cout << failas << " - nerastas\n";
            return;
        }
        auto t2 = steady_clock::now();
        sumN += sek(t1, t2);
        n = grupe.size();

        auto t3 = steady_clock::now();
        rusiuotiPasirinktai(grupe, rusRusis);
        auto t4 = steady_clock::now();
        sumR += sek(t3, t4);

        auto t5 = steady_clock::now();
        kategorijos(grupe, vargsiukai, kietiakiai);
        auto t6 = steady_clock::now();
        sumD += sek(t5, t6);

        auto t7 = steady_clock::now();
        IsvestiIFaila("vargsiukai_test.txt", vargsiukai, true);
        auto t8 = steady_clock::now();
        sumV += sek(t7, t8);

        auto t9 = steady_clock::now();
        IsvestiIFaila("kietiakiai_test.txt", kietiakiai, true);
        auto t10 = steady_clock::now();
        sumK += sek(t9, t10);

        auto visoPab = steady_clock::now();
        sumViso += sek(visoP, visoPab);
    }

    cout << failas << " (" << n << "):\n";
    cout << "  Nuskaitymas: " << (sumN / kartai) << " s\n";
    cout << "  Rusiavimas:  " << (sumR / kartai) << " s\n";
    cout << "  Dalijimas:   " << (sumD / kartai) << " s\n";
    cout << "  Vargsiuku isvedimas: " << (sumV / kartai) << " s\n";
    cout << "  Kietiaku isvedimas:  " << (sumK / kartai) << " s\n";
    cout << "  Viso testo:  " << (sumViso / kartai) << " s\n\n";
}

void TestuotiVisus(int rusRusis) {
    string failai[] = {
        "studentai1000.txt",
        "studentai10000.txt",
        "studentai100000.txt",
        "studentai1000000.txt",
        "studentai10000000.txt"
    };
    for (int i = 0; i < 5; i++) {
        TestuotiFaila(failai[i], rusRusis, 3);
    }
}

void GeneruotiVisus() {
    string failai[] = {
        "studentai1000.txt",
        "studentai10000.txt",
        "studentai100000.txt",
        "studentai1000000.txt",
        "studentai10000000.txt"
    };
    int kiekiai[] = { 1000, 10000, 100000, 1000000, 10000000 };

    for (int i = 0; i < 5; i++) {
        auto t1 = steady_clock::now();
        GeneruotiFaila(failai[i], kiekiai[i]);
        auto t2 = steady_clock::now();
        cout << failai[i] << ": " << sek(t1, t2) << " s\n";
    }
}

int main() {
    vector<studentas> grupe, vargsiukai, kietiakiai;

    cout << "Rusiuoti pagal: 1 - varda, 2 - pavarde, 3 - bala: ";
    int rusRusis;
    cin >> rusRusis;

    int p;
    while (true) {
        cout << "\n===== MENIU =====\n";
        cout << "1 - Generuoti faila\n";
        cout << "2 - Generuoti visus 5 failus\n";
        cout << "3 - Nuskaityti is failo\n";
        cout << "4 - Padalinti i grupes\n";
        cout << "5 - Isvesti i grupiu failus\n";
        cout << "6 - Testavimas\n";
        cout << "0 - Baigti\n";
        cout << "Pasirinkimas: ";
        if (!(cin >> p)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (p == 0) break;

        else if (p == 1) {
            string f;
            int n;
            cout << "Failas: ";
            cin >> f;
            cout << "Kiek: ";
            cin >> n;
            auto t1 = steady_clock::now();
            GeneruotiFaila(f, n);
            auto t2 = steady_clock::now();
            cout << sek(t1, t2) << " s\n";
        }

        else if (p == 2) {
            GeneruotiVisus();
        }

        else if (p == 3) {
            string f;
            cout << "Failas: ";
            cin >> f;
            auto t1 = steady_clock::now();
            bool ok = nuskaitymas(grupe, f);
            auto t2 = steady_clock::now();
            if (!ok) {
                cout << "Nerastas failas.\n";
            } else {
                cout << grupe.size() << " studentai, "
                     << sek(t1, t2) << " s\n";
            }
        }

        else if (p == 4) {
            if (grupe.empty()) {
                cout << "Tuscia.\n";
                continue;
            }
            auto t1 = steady_clock::now();
            RusiavimoPasirinkimas(grupe, rusRusis);
            kategorijos(grupe, vargsiukai, kietiakiai);
            auto t2 = steady_clock::now();
            cout << "Vargsiukai: " << vargsiukai.size()
                 << ", kietiakiai: " << kietiakiai.size()
                 << ", laikas: " << sek(t1, t2) << " s\n";
        }

        else if (p == 5) {
            if (vargsiukai.empty() && kietiakiai.empty()) {
                cout << "Tuscia.\n";
                continue;
            }
            auto t1 = steady_clock::now();
            IsvestiIFaila("vargsiukai.txt", vargsiukai, true);
            IsvestiIFaila("kietiakiai.txt", kietiakiai, true);
            auto t2 = steady_clock::now();
            cout << sek(t1, t2) << " s\n";
        }

        else if (p == 6) {
            TestuotiVisus(rusRusis);
        }
    }
    return 0;
}
