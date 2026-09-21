#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
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

int randPaz() {
    return rand() % 10 + 1;
}

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

void IvestiStudenta(studentas &A) {
    cout << "Vardas: "; cin >> A.var;
    cout << "Pavarde: "; cin >> A.pav;
    A.paz.clear();
    cout << "Iveskite ND pazymius (1-10). Baigti - iveskite -1:\n";
    while (true) {
        int n;
        cout << "  " << A.paz.size() + 1 << "-as: ";
        cin >> n;
        if (n == -1) break;
        if (n < 1 || n > 10) {
            cout << "  Pazymys turi buti nuo 1 iki 10. Bandykite dar karta.\n";
            continue;
        }
        A.paz.push_back(n);
    }
    cout << "Egzaminas (1-10): ";
    while (true) {
        cin >> A.egz;
        if (A.egz >= 1 && A.egz <= 10) break;
        cout << "Pazymys turi buti nuo 1 iki 10. Bandykite dar karta: ";
    }
    A.galutinis_vidurkis = 0.4 * vidurkis(A.paz) + 0.6 * A.egz;
    A.galutinis_mediana = 0.4 * mediana(A.paz) + 0.6 * A.egz;
}

void GeneruotiStudenta(studentas &A) {
    std::string vardai[] = {"Ugne", "Paulius", "Meda", "Mantas", "Erikas",
                            "Greta", "Lukas", "Indre", "Andrius", "Maryte"};
    std::string pavardes[] = {"Segzdaviciute", "Garmasukis", "Plyt", "Jakimas", "Denisenko", "Vilkelyte", "Vaickauskas", "Mamontovas", "Uogyte"};
    A.var = vardai[rand() % 10];
    A.pav = pavardes[rand() % 10];
    A.paz.clear();
    int kiek = rand() % 8 + 3;  
    for (int i = 0; i < kiek; i++) A.paz.push_back(randPaz());
    A.egz = randPaz();
    A.galutinis_vidurkis = 0.4 * vidurkis(A.paz) + 0.6 * A.egz;
    A.galutinis_mediana = 0.4 * mediana(A.paz) + 0.6 * A.egz;
}
    
void output(vector<studentas> &grupe, bool OPvidurkis, bool OPmediana) {
    cout << left << setw(16) << "Vardas" << setw(20) << "Pavarde";
    if (OPvidurkis) cout << right << setw(20) << "Galutinis (Vid.)";
    if (OPmediana) cout << right << setw(20) << "Galutinis (Med.)";
    cout << "\n";

    int br = 36;
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
    srand(time(0));
    
    vector<studentas> grupe;
    int pasirinkti;
    
    while(true) { 
        cout << "\n===== MENIU =====\n";
        cout << "1 - Ivesti studentus\n";
        cout << "2 - Generuoti studentus\n";
        cout << "3 - Spausdinti rezultatus\n";
        cout << "0 - Baigti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkti;

        if (pasirinkti == 0) {
            break;
        }
        else if (pasirinkti == 1) {
            char k;
            do {
                studentas A;
                IvestiStudenta(A);
                grupe.push_back(A);
                cout << "Ar dar yra studentu? (t/n): ";
                cin >> k;
            } while (k == 't' || k == 'T');
        }
        else if (pasirinkti == 2) {
            int n;
            cout << "Kiek studentu? ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                studentas A;
                GeneruotiStudenta(A);
                grupe.push_back(A);
            }
            cout << "Sugeneruota " << n << " studentu.\n";
        }
        else if (pasirinkti == 3) {
            if (grupe.size() == 0) {
                cout << "Sarasas tuscias.\n";
            } else {
                cout << "Is viso:" << grupe.size() << " studentai(-u)\n";
                int v;
                cout << "Rodyti: 1 - Vid., 2 - Med., 3 - abu: ";
                cin >> v;
                bool rv = (v == 1 || v == 3);
                bool rm = (v == 2 || v == 3);
                output(grupe, rv, rm);
            }
        }
        else {
            cout << "Neteisingas pasirinkimas.\n";
        }
    }
    return 0;
}


        
  
