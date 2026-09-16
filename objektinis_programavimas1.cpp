#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;

struct studentas {
    std::string var,pav;
    std::vector<int> paz;
    int egz, rez;
    };

int main(){
    studentas A;
    std::cout << "Įveskite vardą: "; cin >> A.var;
    std::cout << "Įveskite pavardę: "; cin >> A.pav;
    while (true){
        int n; char kl;
        std::cout << "Įveskite sem. paz.: "; cin >> n; A.paz.push_back(n);
        cout << "Ar studentas turi dar pažymių? t/n "; cin >> kl;
        if (kl == 'n' || kl == 'N') break;
        }
    std::cout << "Įveskite egzaminą: "; cin >> A.egz;
    cout << "Studento duomenys: \n";
    cout << left << setw(15) << A.var << left << setw(20) << A.pav;
    for (int sk : A.paz) cout << right << setw(5) << sk;
    cout << right << setw(10) << A.egz;
    }
