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
