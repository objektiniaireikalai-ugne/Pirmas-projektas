#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::vector;

struct studentas {
    std::string var,pav;
    std::vector<int> paz;
    int egz;
    double galutinis_vidurkis;
    double galutinis_mediana;
};

double vidurkis(std::vector<int> paz) {
    if (paz.size() == 0) return 0;
    double s=0;
    for (int i=0; i<paz.size(); i++) s=s+paz[i];
    return s/paz.size();
}

double mediana(std::vector<int> paz) {
    if (paz.size() == 0) return 0;
    std::sort(paz.begin(), paz.end());
    int n=paz.size();
    if (n%2==0) return (paz[n/2-1] + paz[n/2]) / 2.0;
    return paz[n/2];
}

void output(vector<studentas> &grupe, bool OPvidurkis, bool OPmediana) {
    cout << left << setw(16) << "Vardas" << setw(20) << "Pavarde";
    if (OPvidurkis) cout << right << setw(20) << "Galutinis (Vid.)";
    if (OPmediana) cout << right << setw(20) << "Galutinis (Med.)";
    cout << "\n";

    int br = 36
    if (OPvidurkis) br = br+20;
    if (OPmediana) br = br+20;
    for (int i=0; i<br; i++) cout << "-";
    cout << "\n";

    cout << std::fixed << std::setprecision(2);
    for (int i=0; i<grupe.size(); i++) {
        cout << left << setw(16) << grupe[i].var << setw(20) << grupe[i].pav;
        if (OPvidurkis) cout << right << setw(20) << grupe[i].galutinis_vidurkis;
        if (OPmediana) cout << right << setw(20) << grupe[i].galutinis_mediana;
        cout << "\n";
    }
}

int main(){
    studentas A;
    vector<studentas> grupe;
    while(true)
    {       
    std::cout << "Iveskite varda: "; cin >> A.var;
    std::cout << "Iveskite pavarde: "; cin >> A.pav;
    while (true){
        int n; char kl;
        std::cout << "Iveskite sem. paz.: "; cin >> n; A.paz.push_back(n);
        cout << "Ar studentas turi dar pazymiu? t/n "; cin >> kl;
        if (kl == 'n' || kl == 'N') break;
        }
    std::cout << "Iveskite egzamina: "; cin >> A.egz;
    A.galutinis_vidurkis = 0.4 * vidurkis(A.paz) + 0.6 * A.egz;
    A.galutinis_mediana = 0.4 * mediana(A.paz) + 0.6 * A.egz;
    grupe.push_back(A);
    A.paz.clear();
    char kl;
    cout << "Ar turite dar studentu? t/n "; cin >> kl;
        if (kl == 'n' || kl == 'N') break;
    }

    output(grupe, true, false);
    }
