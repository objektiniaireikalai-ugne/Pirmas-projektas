# Studentų pažymių skaičiavimo programa

Objektinio programavimo kurso darbas. Programa leidžia surinkti studentų namų darbų ir egzamino pažymius ir apskaičiuoja studento galutinį balą. Galimi pasirinkimai - įvesti pažymius ranka, sugeneruoti atsitiktinai arba nuskaityti iš failo. Galutinio balo skaičiavimas atliekamas dviem būdais - pagal namų darbų vidurkį ir pagl jų medianą.

## Galutinio balo formulės

- **galutinis (vid.)** = 0.4 × namų darbų vidurkis + 0.6 × egzaminas
- **galutinis (med.)** = 0.4 × namų darbų mediana + 0.6 × egzaminas

## Turinys

- [Reikalavimai ir paleidimas](#reikalavimai-ir-paleidimas)
- [Naudojimas](#naudojimas)
- [Duomenų failo formatas](#duomenų-failo-formatas)
- [Klaidų tikrinimas](#klaidų-tikrinimas)
- [Versijos (releases)](#versijos-releases)

## Naudojimas

Paleidus programą rodomas meniu:

```text
===== MENIU =====
1 - Ivesti studentus 
2 - Generuoti studentus
3 - Nuskaityti studentus is failo
4 - Spausdinti rezultatus
5 - Sugeneruoti testavimo faila
0 - Baigti
```

**1 – Įvesti studentus** – prašoma ranka įvesti vardą ir pavardę, po to vedami namų darbų pažymiai (įvedimas baigiamas įvedus `-1`), tada įvedamas egzamino pažymys. Programa tikrina, kad pažymys būtų intervale [1; 10].

**2 – Generuoti studentus** – vartotojas nurodo studentų skaičių, programa sukuria studentus su atsitiktiniais vardais, pavardėmis, pažymiais.

**3 – Nuskaityti studentus iš failo** – prašoma failo pavadinimo (pvz., `kursiokai.txt`). Paskutinis eilutės skaičius laikomas egzamino pažymiu, visi prieš jį – namų darbais.

**4 – Spausdinti rezultatus** – studentai surikiuojami abėcėlės tvarka pagal pavardę ir išvedami lentele. Galima pasirinkti rodyti vidurkį, medianą arba abu. Jei studentų daugiau nei 50, rodomi tik pirmi 50.

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

## Klaidų tikrinimas

Programa apsaugota nuo neteisingo vartotojo įvedimo ir neegzistuojančių failų:

- **Raidė vietoj skaičiaus** (pvz., `s` vietoj pažymio ar meniu punkto) – srautas išvalomas (`cin.clear()`, `cin.ignore()`), rodomas klaidos pranešimas ir prašoma įvesti iš naujo. Programa nenulūžta.

- **Pažymys ne intervale [1; 10]** – rodomas pranešimas „Pazymys turi buti nuo 1 iki 10" ir prašoma įvesti iš naujo.

- **Neįvesta nė vieno namų darbų** – `vidurkis()` ir `mediana()` funkcijos grąžina 0, jei pažymių sąrašas tuščias. Dalyba iš nulio neįvyksta, galutinis balas apskaičiuojamas tik iš egzamino (0.6 × egzaminas).

- **Failas neegzistuoja** – rodomas pranešimas „Nepavyko atidaryti" ir grįžtama į meniu.

- **Nežinomas meniu pasirinkimas** – rodomas pranešimas „Neegzistuoja toks pasirinkimas" ir meniu rodomas iš naujo.

## Versijos (releases)

Kiekviena versija turi atskirą žymą (tag) ir atskirą release'ą GitHub'e.

| Versija | Šaka | Trumpai |
|---------|------|---------|
| v.pradinė | v.pradinė | Duomenų įvedimas ranka ir generavimas, vidurkis ir mediana, rezultatų lentelė |
| v0.1 | v0.1 | Skaitymas iš failo, rikiavimas pagal pavardę, testavimo failų generavimas |
| v0.2 | v0.2 | Kodo refactoring'as į atskirus failus, skirstymas į dvi grupes, rūšiavimas pagal pasirinkimą, efektyvumo tyrimai |

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

- **Duomenų skaitymas iš failo (`nuskaitymas()`):** vartotojas pats nurodo failo pavadinimą, tad programa nėra pririšta prie vieno konkretaus failo. Eilutė skaidoma per `istringstream`, paskutinis skaičius traktuojamas kaip egzaminas.
- **Rikiavimas pagal pavardę** prieš išvedimą (`std::sort` su `rusiuoti()` funkcija).
- **Testavimo failų generavimas (`GeneruotiFaila()`):** vartotojas nurodo failo pavadinimą ir studentų skaičių, programa sukuria failą su atsitiktiniais duomenimis pagal pateiktą formatą.
- **Limitas spausdinimui:** kai sąraše daugiau nei 50 studentų, rodomi tik pirmi 50 įrašų – kad su `studentai100000.txt` ar `studentai1000000.txt` išvestis liktų įskaitoma.
- **Įvesties klaidų tikrinimas:** pridėti `cin.clear()` ir `cin.ignore()` apsaugai nuo neteisingo įvedimo (raidė vietoj skaičiaus). Programa rodo klaidų pranešimus ir prašo įvesti iš naujo – nenulūžta.
- **Apsauga nuo dalybos iš nulio:** jei studentas neturi nė vieno namų darbų pažymio, `vidurkis()` ir `mediana()` grąžina 0, o galutinis balas skaičiuojamas tik iš egzamino.

### v0.2

**Kas nauja, palyginti su v0.1:**

- **Kodo refactoring'as** – kodas išskaidytas į kelis failus pagal atsakomybes:
  - `studentas.h` – struktūra `studentas`
  - `funkcijos.h` – visų funkcijų deklaracijos
  - `funkcijos.cpp` – visų funkcijų realizacijos
  - `main.cpp` – pagrindinė programa su meniu
- **Atsitiktinių skaičių generavimas perkeltas į `<random>` biblioteką** – naudojamas `std::mt19937` generatorius ir `std::uniform_int_distribution<>`. Tai modernesnis ir kokybiškesnis sprendimas už seną `rand()`.
- **Skirstymas į dvi grupes** pagal galutinį balą:
  - **vargšiukai** – galutinis balas < 5.0
  - **kietiakiai** – galutinis balas >= 5.0
- **Rūšiavimas pagal naudotojo pasirinkimą** – trys variantai:
  - pagal vardą (`RusiuotiPagalVarda`)
  - pagal pavardę (`RusiuotiPagalPavarde`)
  - pagal galutinį balą (`RusiuotiPagalBala`)
- **Išvedimas į du atskirus failus** – `vargsiukai.txt` ir `kietiakiai.txt` (arba su testavimo priesaga).
- **Automatinis testavimas** – programa sugeneruoja 5 skirtingo dydžio failus ir kiekvieną testuoja 3 kartus, pateikdama laikų vidurkį.
- **Laiko matavimas** atliekamas kiekvienam etapui atskirai:
  - failų generavimas
  - nuskaitymas iš failo
  - rūšiavimas
  - dalijimas į dvi grupes
  - vargšiukų išvedimas į failą
  - kietiakų išvedimas į failą
- **Efektyvumo tyrimai** atlikti su 5 failais (1 000 – 10 000 000 įrašų) ir aprašyti šio README skyriuje „Efektyvumo tyrimai".

## Efektyvumo tyrimai

Testavimas atliktas su 5 skirtingo dydžio failais – 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų. Kiekvienas testas kartotas **3 kartus**, pateikiamas **laikų vidurkis**.

### Failų generavimo laikai

| Failas | Įrašų skaičius | Generavimo laikas |
|--------|---------------:|------------------:|
| studentai1000.txt | 1 000 | 0.016 s |
| studentai10000.txt | 10 000 | 0.044 s |
| studentai100000.txt | 100 000 | 0.461 s |
| studentai1000000.txt | 1 000 000 | 4.574 s |
| studentai10000000.txt | 10 000 000 | 48.486 s |

### Programos veikimo laikai

| Įrašai | Nuskaitymas | Rūšiavimas | Dalijimas | Vargšiukų išv. | Kietiakų išv. | Viso |
|-------:|------------:|-----------:|----------:|---------------:|--------------:|-----:|
| 1 000 | 0.008 s | 0.001 s | 0.0005 s | 0.002 s | 0.002 s | 0.014 s |
| 10 000 | 0.059 s | 0.008 s | 0.004 s | 0.009 s | 0.010 s | 0.090 s |
| 100 000 | 0.529 s | 0.097 s | 0.034 s | 0.051 s | 0.086 s | 0.798 s |
| 1 000 000 | 5.321 s | 1.435 s | 0.403 s | 0.557 s | 0.812 s | 8.529 s |
| 10 000 000 | 60.937 s | 19.427 s | 8.860 s | 7.328 s | 9.535 s | 106.087 s |

### Išvados

- **Nuskaitymas iš failo** yra lėčiausias etapas – užima apie 60–70 % viso testo laiko. Tai susiję su eilutės skaidymu per `istringstream` ir skaičių konvertavimu.
- **Rūšiavimas** užima apie 15–20 % viso laiko. Naudojamas `std::sort` (introsort algoritmas) su vidutiniu O(n log n) sudėtingumu.
- **Dalijimas į dvi grupes** – greičiausias etapas (apie 5–8 %), nes tai tiesiog vienas perėjimas per vektorių.
- **Išvedimas į failus** užima apie 10–15 % laiko. Vargšiukų išvedimas paprastai šiek tiek greitesnis, nes vargšiukų paprastai būna mažiau (maždaug 30–40 % studentų).
- **Laikas auga tiesiškai** – 10 kartų daugiau įrašų → maždaug 10–12 kartų ilgesnis laikas. Tai rodo, kad algoritmai efektyvūs.
- **Didžiausias failas (10M įrašų)** buvo apdorotas per ~106 s. Programos resursų naudojimas išlieka priimtinas net ir su labai dideliais duomenų kiekiais.
