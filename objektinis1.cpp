#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
using std::cin;
using std::cout;
using std::left;
using std::right;
using std::setw;
using std::vector;

struct studentas {
    std::string var,pav;
    std::vector<int> paz;
    int egz, rez;
    };

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
    A.rez=0.4*std::accumulate(A.paz.begin(), A.paz.end(), 0.0)/A.paz.size() + 0.6*A.egz;
    grupe.push_back(A);
    A.paz.clear();
    char kl;
    cout << "Ar turite dar studentu? t/n "; cin >> kl;
        if (kl == 'n' || kl == 'N') break;
    }
    
    cout << "Studentu duomenys: \n";
    cout << "|"<< left << setw(15) << "Vardas" << "|"<< left << setw(20) << "Pavarde";
    cout << "|" << right << setw(10) << "Final" << "|\n";
    int br=15+20+10+2;
    cout<<"|";for (int i=0;i<br; i++) cout<<"-"; cout<<"|\n";

    for (auto B : grupe)
    {
        cout << "|"<< left << setw(15) << B.var << "|" << left << setw(20) << B.pav;
        cout << "|" << right << setw(10) << B.rez << "|\n";
        }
    }
