#include "funkcijos.h"
#include <algorithm>

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
    A.galVid = 0.4 * vidurkis(A.nd) + 0.6 * A.egz;
    A.galMed = 0.4 * mediana(A.nd) + 0.6 * A.egz;
}

bool rusiuoti(const Studentas& a, const Studentas& b) {
    return a.pav < b.pav;
}


#include <random>
#include <fstream>
#include <iomanip>

static std::mt19937 gen(std::random_device{}());
static std::uniform_int_distribution<> dist(1,10);

int GeneruotiPazymi() {
    return dist(gen);
}

Studentas GeneruotiStudenta(int numeris) {
    Studentas A;
    A.var = "Vardas" + std::to_string(numeris);
    A.pav = "Pavarde" + std::to_string(numeris);
    A.nd.clear();

    int kiek = dist(gen) % 8 + 3;
    for (int i=0; i<kiek; i++) {
        A.nd.push_back(GeneruotiPazymi());
    }
    A.egz = GeneruotiPazymi();
    skaiciuoti(A);
    return A;
)

void GeneruotiStudentus(std::vector<Studentas>& grupe, int kiek) {
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
