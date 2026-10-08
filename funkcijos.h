#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <string>

double vidurkis(std::vector<int>& paz);
double mediana(std::vector<int> paz);
void skaiciuoti(studentas& A);

bool RusiuotiPagalVarda(const studentas& a, const studentas& b);
bool RusiuotiPagalPavarde(const studentas& a, const studentas& b);
bool RusiuotiPagalBala(const studentas& a, const studentas& b);

int GeneruotiPazymi();
studentas GeneruotiStudenta(int numeris);
void GeneruotiStudentus(std::vector<studentas>& grupe, int kiek);
void GeneruotiFaila(const std::string& failas, int kiek);

bool nuskaitymas(std::vector<studentas>& grupe, const std::string& failas);

void kategorijos(const std::vector<studentas>& grupe,
               std::vector<studentas>& vargsiukai,
               std::vector<studentas>& kietiakiai);
void IsvestiIFaila(const std::string& failas,
                   const std::vector<studentas>& grupe,
                   bool rodytiVid);

void output(const std::vector<studentas>& grupe, int limit);

#endif
