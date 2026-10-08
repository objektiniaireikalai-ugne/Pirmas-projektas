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
        RusiavimoPasirinkimas(grupe, rusRusis);
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

    cout << "Isvesties failus rusiuoti pagal: 1 - varda, 2 - pavarde, 3 - bala: ";
    int rusRusis;
    cin >> rusRusis;

    int p;
    while (true) {
        cout << "\n===== MENIU =====\n";
        cout << "1 - Ivesti studentus ranka\n";
        cout << "2 - Generuoti faila\n";
        cout << "3 - Generuoti visus 5 failus\n";
        cout << "4 - Nuskaityti is failo\n";
        cout << "5 - Padalinti i grupes\n";
        cout << "6 - Isvesti grupes i failus\n";
        cout << "7 - Spausdinti studentus i ekrana\n";
        cout << "8 - Automatinis testavimas (5 failai)\n";
        cout << "0 - Baigti\n";
        cout << "Pasirinkimas: ";
        if (!(cin >> p)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (p == 0) break;

        else if (p == 1) {
            int n;
            cout << "Kiek studentu? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                studentas A;
                cout << "\nVardas: ";
                cin >> A.var;
                cout << "Pavarde: ";
                cin >> A.pav;
                A.paz.clear();
                cout << "ND pazymiai (baigti - -1):\n";
                while (true) {
                    int x;
                    cin >> x;
                    if (x == -1) break;
                    if (x < 1 || x > 10) { cout << "1-10!\n"; continue; }
                    A.paz.push_back(x);
                }
                cout << "Egzaminas: ";
                cin >> A.egz;
                skaiciuoti(A);
                grupe.push_back(A);
            }
        }

        else if (p == 2) {
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

        else if (p == 3) {
            GeneruotiVisus();
        }

        else if (p == 4) {
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

        else if (p == 5) {
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

        else if (p == 6) {
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

        else if (p == 7) {
            if (grupe.empty()) {
                cout << "Tuscia.\n";
                continue;
            }
            if (grupe.size() > 100) {
                cout << "Demesio: " << grupe.size() << " studentu!\n";
                cout << "Rekomenduojama naudoti 6 punkta (isvesti i faila).\n";
                cout << "Tikrai spausdinti? (t/n): ";
                char k;
                cin >> k;
                if (k != 't' && k != 'T') continue;
            }
            int lim;
            cout << "Kiek rodyti (0 = visus)? ";
            cin >> lim;
            output(grupe, lim);
        }

        else if (p == 8) {
            TestuotiVisus(rusRusis);
        }
    }
    return 0;
}
