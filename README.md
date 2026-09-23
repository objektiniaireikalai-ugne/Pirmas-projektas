# Studentų pažymių skaičiavimo programa

Objektinio programavimo kurso darbas. Programa leidžia surinkti studentų namų darbų ir egzamino pažymius ir apskaičiuoja studento galutinį balą. Galimi pasirinkimai - įvesti pažymius ranka, sugeneruoti atsitiktinai arba nuskaityti iš failo. Galutinio balo skaičiavimas atliekamas dviem būdais - pagal namų darbų vidurkį ir pagl jų medianą.

## Galutinio balo formulės

- **galutinis (vid.)** = 0.4 × namų darbų vidurkis + 0.6 × egzaminas
- **galutinis (med.)** = 0.4 × namų darbų mediana + 0.6 × egzaminas

## Turinys

- [Reikalavimai ir paleidimas](#reikalavimai-ir-paleidimas)
- [Naudojimas](#naudojimas)
- [Duomenų failo formatas](#duomenų-failo-formatas)
- [Versijos (releases)](#versijos-releases)

## Naudojimas

Paleidus programą rodomas meniu:

```text
===== MENIU =====
1 - Ivesti studentus ranka
2 - Generuoti studentus atsitiktinai
3 - Nuskaityti studentus is failo
4 - Spausdinti rezultatus
5 - Sugeneruoti testavimo faila
0 - Baigti darba
```

**1 – Įvesti studentus ranka** – prašoma vardo ir pavardės, po to vedami namų darbų pažymiai (įvedimas baigiamas įvedus `-1`), tada įvedamas egzamino pažymys. Programa tikrina, kad pažymys būtų intervale [1; 10].

**2 – Generuoti studentus atsitiktinai** – vartotojas nurodo studentų skaičių, programa sukuria studentus su atsitiktiniais vardais, pavardėmis, pažymiais.

**3 – Nuskaityti studentus iš failo** – prašoma failo pavadinimo (pvz., `kursiokai.txt`). Paskutinis eilutės skaičius laikomas egzamino pažymiu, visi prieš jį – namų darbais.

**4 – Spausdinti rezultatus** – studentai surikiuojami pagal pavardę ir išvedami lentele. Galima pasirinkti rodyti vidurkį, medianą arba abu. Jei studentų daugiau nei 50, rodomi tik pirmi 50.

**5 – Sugeneruoti testavimo failą** – vartotojas nurodo failo pavadinimą ir studentų skaičių, programa sukuria failą su atsitiktiniais duomenimis.

## Duomenų failo formatas

Pirma failo eilutė – antraštė (ji praleidžiama). Toliau kiekviena eilutė aprašo vieną studentą:

```text
Vardas          Pavarde                 ND1   ND2   ND3   ND4   ND5   Egz.
Jonas           Jonaitis                  8     9     7    10     6     9
Petras          Petraitis                 5     6     4     7     8     6
Ona             Onaityte                 10    10     9     9    10    10
```
Namų darbų pažymių skaičius iš anksto nėra žinomas – skaitomi visi eilutėje esantys skaičiai, o paskutinis iš jų priskiriamas egzaminui. Stulpelių skaičius skirtingose eilutėse gali skirtis, skiriamieji simboliai – bet koks tarpų kiekis.

## Versijos (releases)

Kiekviena versija turi atskirą žymą (tag) ir atskirą release'ą GitHub'e.

| Versija | Šaka | Trumpai |
|---------|------|---------|
| v.pradinė | v.pradinė | Duomenų įvedimas ranka ir generavimas, vidurkis ir mediana, rezultatų lentelė |
| v0.1 | v0.1 | Skaitymas iš failo, rikiavimas pagal pavardę, testavimo failų generavimas |

### v.pradinė

Pirmoji veikianti programos versija.

**Funkcionalumas:**

- Struktūra `studentas` (vardas, pavardė, `vector<int> paz`, egzaminas) ir `vector<studentas> grupe`.

- Namų darbų pažymių skaičius nėra žinomas iš anksto – įvedimas baigiamas įvedus `-1`.

- Galimybė atsitiktinai sugeneruoti tiek namų darbų, tiek egzamino pažymius (`rand()`).

- Galutinio balo skaičiavimas pagal vidurkį (`vidurkis()`) ir pagal medianą (`mediana()`), rezultatas pateikiamas dviejų skaitmenų po kablelio tikslumu.

- Rezultatų išvedimas sulygiuota lentele naudojant `<iomanip>` (`setw`, `left`, `right`, `fixed`, `setprecision`).

- Įvesties klaidų tikrinimas (pvz.: pažymys ne intervale [1; 10]).

- Funkcijos suskirstytos pagal atsakomybes: `IvestiStudenta()`, `GeneruotiStudenta()`, `output()`, `vidurkis()`, `mediana()`.

**Apribojimai:**

- Duomenis galima įvesti tik ranka arba sugeneruoti – failų skaitymo nėra.

- Visas sąrašas visada išvedamas iš karto, todėl su dideliu kiekiu studentų išvestis tampa neperskaitoma.

### v0.1

**Kas nauja, palyginti su v.pradinė:**

- Duomenų skaitymas iš failo (`nuskaitymas()`): vartotojas pats nurodo failo pavadinimą, tad programa nėra pririšta prie vieno konkretaus failo. Eilutė skaidoma per `istringstream`, paskutinis skaičius traktuojamas kaip egzaminas.

- Rikiavimas pagal pavardę prieš išvedimą (`std::sort` su `rusiuoti()` funkcija).

- Testavimo failų generavimas (`GeneruotiFaila()`): vartotojas nurodo failo pavadinimą ir studentų skaičių, programa sukuria failą su atsitiktiniais duomenimis pagal pateiktą formatą.

- Limitas spausdinimui: kai sąraše daugiau nei 50 studentų, rodomi tik pirmi 50 įrašų – kad su `studentai100000.txt` ar `studentai1000000.txt` išvestis liktų įskaitoma.

- Testavimo failai: `studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt` – skirtingo dydžio testavimui.
