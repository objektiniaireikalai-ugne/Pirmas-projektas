#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <vector>
#include <list>
#include <string>

double vidurkis(std::vector<int> paz);
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
bool nuskaitymas(std::list<studentas>& grupe, const std::string& failas);

void kategorijos(std::vector<studentas>& grupe,
               std::vector<studentas>& vargsiukai,
               std::vector<studentas>& kietiakai);

void kategorijos(const std::list<studentas>& grupe,
                std::list<studentas>& vargsiukai,
                std::list<studentas>& kietiakai);

void IsvestiIFaila(const std::string& failas,
                  const std::vector<studentas>& grupe,
                  bool rodytiVid);

void IsvestiIFaila(const std::string& failas,
                  const std::list<studentas>& grupe,
                  bool rodytiVid);

void output(const std::vector<studentas>& grupe, int limit, bool rodytiVid, bool rodytiMed);

void split_1_vector(std::vector<studentas>& grupe, std::vector<studentas>& v, std::vector<studentas>& k);
void split_1_list(std::list<studentas>& grupe, std::list<studentas>& v, std::list<studentas>& k);

#endif
