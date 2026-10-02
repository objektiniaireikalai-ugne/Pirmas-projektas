#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <string>

double vidurkis(const std::vector<int>& paz);
double mediana(std::vector<int> paz);
void skaiciuoti(Studentas& A);
bool rusiuoti(const Studentas& a, const Studentas& b);

int GeneruotiPazymi();
Studentas GeneruotiStudenta(int numeris);
void GeneruotiStudentus(std::vector<Studentas>& grupe, int kiek);
void GeneruotiFaila(const std::string& failas, int kiek);

bool nuskaitymas(std::vector<Studentas>& grupe, const std::string& failas);

void kategorijos(const std::vector<Studentas>& grupe,
               std::vector<Studentas>& vargsiukai,
               std::vector<Studentas>& kietiakiai);
void IsvestiIFaila(const std::string& failas,
                   const std::vector<Studentas>& grupe,
                   bool rodytiVid);

void output(const std::vector<Studentas>& grupe, int limit);

#endif
