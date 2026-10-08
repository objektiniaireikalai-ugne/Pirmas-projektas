#include "funkcijos.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

double vidurkis(vector<int> paz) {
    if (paz.size() == 0) return 0;
    double s = 0;
    for (int i = 0; i < paz.size(); i++) s = s + paz[i];
    return s / paz.size();
}

double mediana(vector<int> paz) {
    if (paz.size() == 0) return 0;
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    return paz[n/2];
}

void skaiciuoti(studentas& A) {
    A.galutinis_vidurkis = 0.4 * vidurkis(A.paz) + 0.6 * A.egz;
    A.galutinis_mediana = 0.4 * mediana(A.paz) + 0.6 * A.egz;
}

bool RusiuotiPagalVarda(const studentas& a, const studentas& b) {
    return a.var < b.var;
}

bool RusiuotiPagalPavarde(const studentas& a, const studentas& b) {
    return a.pav < b.pav;
}

bool RusiuotiPagalBala(const studentas& a, const studentas& b) {
    return a.galutinis_vidurkis < b.galutinis_vidurkis;
}


static mt19937 gen(random_device{}());
static uniform_int_distribution<> dist(1, 10);

int GeneruotiPazymi() {
    return dist(gen);
}

studentas GeneruotiStudenta(int numeris) {
    studentas A;
    A.var = "Vardas" + to_string(numeris);
    A.pav = "Pavarde" + to_string(numeris);
    A.paz.clear();

    int kiek = dist(gen) % 8 + 3;
    for (int i = 0; i < kiek; i++) {
        A.paz.push_back(GeneruotiPazymi());
    }
    A.egz = GeneruotiPazymi();
    skaiciuoti(A);
    return A;
}

void GeneruotiStudentus(vector<studentas>& grupe, int kiek) {
    grupe.clear();
    grupe.reserve(kiek);
    for (int i = 0; i < kiek; i++) {
        grupe.push_back(GeneruotiStudenta(i + 1));
    }
}

void GeneruotiFaila(const string& failas, int kiek) {
    ofstream out(failas.c_str());
    out << left << setw(16) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        out << right << setw(6) << ("ND" + to_string(i));
    }
    out << right << setw(6) << "Egz." << "\n";

    for (int i = 0; i < kiek; i++) {
        studentas A = GeneruotiStudenta(i + 1);
        out << left << setw(16) << A.var << setw(20) << A.pav;
        for (int j = 0; j < 15; j++) {
            out << right << setw(6) << GeneruotiPazymi();
        }
        out << right << setw(6) << GeneruotiPazymi() << "\n";
    }
}

bool nuskaitymas(vector<studentas>& grupe, const string& failas) {
    ifstream in(failas.c_str());
    if (!in) return false;

    grupe.clear();
    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        istringstream ss(eilute);
        studentas A;
        if (!(ss >> A.var >> A.pav)) continue;

        A.paz.clear();
        int x;
        while (ss >> x) A.paz.push_back(x);
        if (A.paz.size() == 0) continue;

        A.egz = A.paz[A.paz.size() - 1];
        A.paz.pop_back();

        skaiciuoti(A);
        grupe.push_back(A);
    }
    return true;
}

void kategorijos(const vector<studentas>& grupe,
                 vector<studentas>& nabageliai,
                 vector<studentas>& kietiakai) {
    nabageliai.clear();
    kietiakai.clear();

    for (int i = 0; i < (int)grupe.size(); i++) {
        if (grupe[i].galutinis_vidurkis < 5.0) {
            nabageliai.push_back(grupe[i]);
        } else {
            kietiakai.push_back(grupe[i]);
        }
    }
}


void IsvestiIFaila(const string& failas, const vector<studentas>& grupe, bool rodytiVid) {
    ofstream out(failas.c_str());

    out << left << setw(16) << "Vardas" << setw(20) << "Pavarde" << right << setw(20) << "Galutinis" << "\n";

    out << fixed << setprecision(2);
    for (int i = 0; i < (int)grupe.size(); i++) {
        out << left << setw(16) << grupe[i].var << setw(20) << grupe[i].pav << right << setw(20);
        if (rodytiVid) {
            out << grupe[i].galutinis_vidurkis;
        } else {
            out << grupe[i].galutinis_mediana;
        }
        out << "\n";
    }
}

void output(const vector<studentas>& grupe, int limit) {
    cout << left << setw(16) << "Vardas" << setw(20) << "Pavarde";
    cout << right << setw(20) << "Galutinis" << "\n";

    int br = 56;
    for (int i = 0; i < br; i++) cout << "-";
    cout << "\n";

    int n = (int)grupe.size();
    if (limit > 0 && limit < n) n = limit;

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << left << setw(16) << grupe[i].var
             << setw(20) << grupe[i].pav
             << right << setw(20) << grupe[i].galutinis_vidurkis;
        cout << "\n";
    }
}
