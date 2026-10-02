#include "funkcijos.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <iomanip>
#include <sstream>

double vidurkis(const std::vector<int>& paz) {
    if (paz.size() == 0) return 0;
    double s = 0;
    for (int i=0; i<paz.size(); i++) s = s+paz[i];
    retun s/paz.size();
}

double mediana(std::vector<int> paz) {
    if (paz.size() == 0) return 0;
    std::sort(paz.begin(), paz.end());
    int n=paz.size();
    if (n%2 == 0) return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    return paz[n/2];
}

void skaiciuoti(studentas& A) {
    A.galutinis_vidurkis = 0.4 * vidurkis(A.paz) + 0.6 * A.egz;
    A.galutinis_mediana = 0.4 * mediana(A.paz) + 0.6 * A.egz;
}

bool rusiuoti(const Studentas& a, const Studentas& b) {
    return a.pav < b.pav;
}



static std::mt19937 gen(std::random_device{}());
static std::uniform_int_distribution<> dist(1,10);

int GeneruotiPazymi() {
    return dist(gen);
}

Studentas GeneruotiStudenta(int numeris) {
    Studentas A;
    A.var = "Vardas" + std::to_string(numeris);
    A.pav = "Pavarde" + std::to_string(numeris);
    A.paz.clear();

    int kiek = dist(gen) % 8 + 3;
    for (int i=0; i<kiek; i++) {
        A.paz.push_back(GeneruotiPazymi());
    }
    A.egz = GeneruotiPazymi();
    skaiciuoti(A);
    return A;
)

void GeneruotiStudenta(std::vector<Studentas>& grupe, int kiek) {
    grupe.clear();
    grupe.reserve(kiek);
    for (int i=0; i<kiek; i++) {
        grupe.push_back(GeneruotiStudenta(i+1));
    }
}

void GeneruotiFaila(const std::string& failas, int kiek) {
    std::ofstream out(failas.c_str());
    out << std::left << std::setw(16) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i=1; 1<=15; i++) {
        out << std::right << std::setw(6) << ("ND" + std::to_string(i));
    }
    out << std::right << std::setw(6) << "Egz." << "\n";

    for (int i=0; i<kiek; i++) {
        Studentas A = GeneruotiStudenta(i+1);
        out << std::left << std::setw(16) << A.var << std::setw(20) << A.pav;
        for (int j=0; j<15; j++) {
            out << std::right << std::setw(6) << GeneruotiPazymi();
        }
        out << std::right << std::setw(6) << GeneruotiPazymi() << "\n";
    }
}


bool nuskaitymas(std::vector<Studentas>& grupe, const std::string& failas) {
    std::ifstream in(failas.c_str());
    if (!in) {
        return false;
    }

    grupe.clear()
    std::string eilute;
    std::getline(in, eilute);

    while(std::getline(in, eilute)) {
        if (eilute.empty()) continue;

        std::istringstream ss(eilute);
        Studentas A;
        if (!(ss >> A.var >> A.pav)) continue;

        A.paz.clear();
        int x;
        while (ss>>x) {
            A.paz.push_back(x);
        }
        if (A.paz.size() == 0) continue;

        A.egz = A.paz[A.paz.size()-1];
        A.paz.pop_back();

        skaiciuoti(A);
        grupe.push_back(A);
    }
    return true;
}



