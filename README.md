# Studentų pažymių skaičiavimo programa

Objektinio programavimo kurso darbas. Programa leidžia surinkti studentų namų darbų ir egzamino pažymius ir apskaičiuoja studento galutinį balą. Galimi pasirinkimai - įvesti pažymius ranka, sugeneruoti atsitiktinai arba nuskaityti iš failo. Galutinio balo skaičiavimas atliekamas dviem būdais - pagal namų darbų vidurkį ir pagal jų medianą.

## Galutinio balo formulės

- **galutinis (vid.)** = 0.4 × namų darbų vidurkis + 0.6 × egzaminas
- **galutinis (med.)** = 0.4 × namų darbų mediana + 0.6 × egzaminas

## Turinys

- [Reikalavimai ir paleidimas](#reikalavimai-ir-paleidimas)
- [Naudojimas](#naudojimas)
- [Duomenų failo formatas](#duomenų-failo-formatas)
- [Klaidų tikrinimas](#klaidų-tikrinimas)
- [Versijos (releases)](#versijos-releases)
- [Efektyvumo tyrimai](#efektyvumo-tyrimai)

## Reikalavimai ir paleidimas

Norint sukompiliuoti ir paleisti programą, reikalingas C++ kompiliatorius (palaikantis C++17 standartą, pvz., GCC, Clang, MSVC) ir **CMake** įrankis.

### Diegimas naudojant CMake (Bet kuriai OS)

1. Nuklonuokite repozitoriją arba atsisiųskite ją kaip ZIP failą.
2. Terminale (arba komandinėje eilutėje) atidarykite projekto aplanką ir įvykdykite šias komandas:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build . --config Release

## Naudojimas

Paleidus programą rodomas meniu:

```text
===== MENIU =====
1 - Ivesti studentus
2 - Generuoti faila
3 - Generuoti visus 5 failus
4 - Nuskaityti studentus is failo
5 - Padalinti i grupes
6 - Isvesti grupes i failus
7 - Spausdinti studentus i ekrana
8 - Automatinis testavimas (5 failai)
0 - Baigti
```

**1 – Įvesti studentus** – prašoma ranka įvesti vardą ir pavardę, po to vedami namų darbų pažymiai (įvedimas baigiamas įvedus `-1`), tada įvedamas egzamino pažymys. Programa tikrina, kad pažymys būtų intervale [1; 10].

**2 – Generuoti failą** – sugeneruoja vieną failą su nurodytu studentų skaičiumi.

**3 – Generuoti visus 5 failus** – automatiškai sugeneruoja 5 testavimo failus (nuo 1 000 iki 10 000 000 įrašų).

**4 – Nuskaityti studentus iš failo** – nuskaito studentus iš nurodyto failo.

**5 – Padalinti į grupes** – surūšiuoja studentus ir padalina juos į „vargšiukus“ (< 5.0) ir „kietiakus“ (>= 5.0)

**6 – Išvesti į failus** – išsaugo abi grupes į atskirus failus.

**7 – Spausdinti į ekraną** – išveda studentus lentele.

**8 – Automatinis testavimas** – atlieka spartos matavimus su `std::vector` ir `std::list` konteineriais naudojant 5 failus.

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

- **Raidė vietoj skaičiaus** – srautas išvalomas (`cin.clear()`, `cin.ignore()`), rodomas klaidos pranešimas ir prašoma įvesti iš naujo. Programa nenulūžta.

- **Pažymys ne intervale [1; 10]** – rodomas pranešimas ir prašoma įvesti iš naujo.

- **Neįvesta nė vieno namų darbų** – `vidurkis()` ir `mediana()` funkcijos grąžina 0, jei pažymių sąrašas tuščias. Dalyba iš nulio neįvyksta, galutinis balas apskaičiuojamas tik iš egzamino (0.6 × egzaminas).

- **Failas neegzistuoja** – rodomas pranešimas „Nepavyko atidaryti" ir grįžtama į meniu.

## Versijos (releases)

Kiekviena versija turi atskirą žymą (tag) ir atskirą release'ą GitHub'e.

| Versija | Šaka | Trumpai |
|---------|------|---------|
| v.pradinė | v.pradinė | Duomenų įvedimas ranka, vidurkis ir mediana, rezultatų lentelė |
| v0.1 | v0.1 | Skaitymas iš failo, rikiavimas, testavimo failų generavimas |
| v0.2 | v0.2 | Kodo refactoring'as į failus, skirstymas į grupes, rūšiavimas pagal pasirinkimą, efektyvumo tyrimai|
| v0.3 | v0.3 | `std::list` konteinerio palyginimas su `std::vector`, adreso išvedimas|


### v.pradinė

Pirmoji veikianti programos versija. Duomenų įvedimas ranka, rezultatų skaičiavimas ir išvedimas į ekraną.

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
  - **kietiakai** – galutinis balas >= 5.0
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

### v0.3

- Pridėtas `std::list` konteinerio palyginimas su `std::vector`.
- Realizuotas funkcijų perkrovimas (overloading) abiems konteineriams.
- Rankinio įvedimo metu išvedamas objekto adresas atmintyje (`&A`).

## Efektyvumo tyrimai

Testavimas atliktas su 5 skirtingo dydžio failais – 1 000, 10 000, 100 000, 1 000 000 ir 10 000 000 įrašų. Kiekvienas testas kartotas **3 kartus**, pateikiamas **laikų vidurkis**.

### Testavimo sistemos parametrai:
- **CPU**: Intel Core i5-1035G1 @ 1.00GHz
- **RAM**: 8.0 GB DDR4
- **Diskas**: SSD NVMe 256 GB

### Failų generavimo laikai

| Failas | Įrašų skaičius | Generavimo laikas |
|--------|---------------:|------------------:|
| studentai1000.txt | 1 000 | 0.016 s |
| studentai10000.txt | 10 000 | 0.044 s |
| studentai100000.txt | 100 000 | 0.461 s |
| studentai1000000.txt | 1 000 000 | 4.574 s |
| studentai10000000.txt | 10 000 000 | 48.486 s |

### Tyrimas v0.2: `std::vector` konteineris

| Įrašai | Nuskaitymas | Rūšiavimas | Dalijimas | Vargšiukų išv. | Kietiakų išv. | Viso |
|-------:|------------:|-----------:|----------:|---------------:|--------------:|-----:|
| 1 000 | 0.008 s | 0.001 s | 0.0005 s | 0.002 s | 0.002 s | 0.014 s |
| 10 000 | 0.059 s | 0.008 s | 0.004 s | 0.009 s | 0.010 s | 0.090 s |
| 100 000 | 0.529 s | 0.097 s | 0.034 s | 0.051 s | 0.086 s | 0.798 s |
| 1 000 000 | 5.321 s | 1.435 s | 0.403 s | 0.557 s | 0.812 s | 8.529 s |
| 10 000 000 | 60.937 s | 19.427 s | 8.860 s | 7.328 s | 9.535 s | 106.087 s |

### v0.2 Išvados

- **Nuskaitymas iš failo** yra lėčiausias etapas – užima apie 60–70 % viso testo laiko. Tai susiję su eilutės skaidymu per `istringstream` ir skaičių konvertavimu.
- **Rūšiavimas** užima apie 15–20 % viso laiko. Naudojamas `std::sort` su vidutiniu O(n log n) sudėtingumu.
- **Dalijimas į dvi grupes** – greičiausias etapas (apie 5–8 %), nes tai tiesiog vienas perėjimas per vektorių.
- **Išvedimas į failus** užima apie 10–15 % laiko.
- **Laikas auga tiesiškai** – 10 kartų daugiau įrašų → maždaug 10–12 kartų ilgesnis laikas. Tai rodo, kad algoritmai efektyvūs.
- **Didžiausias failas (10M įrašų)** buvo apdorotas per ~106 s. Programos resursų naudojimas išlieka priimtinas net ir su labai dideliais duomenų kiekiais.

## Tyrimas v0.3 (Konteinerių palyginimas): `std::vector` vs `std::list`

Tyrimo tikslas – išmatuoti, kaip programos sparta priklauso nuo naudojamo konteinerio.

### Rezultatai su `std::vector`

| Įrašai | Nuskaitymas | Rūšiavimas | Dalijimas | Vargšiukų išv. | Kietiakų išv. | Viso |
|-------:|------------:|-----------:|----------:|---------------:|--------------:|-----:|
| 1 000 | 0.0065 s | 0.0008 s | 0.0003 s | 0.0015 s | 0.0013 s | 0.0107 s |
| 10 000 | 0.0528 s | 0.0082 s | 0.0030 s | 0.0062 s | 0.0074 s | 0.0779 s |
| 100 000 | 0.4986 s | 0.0876 s | 0.0346 s | 0.0531 s | 0.0784 s | 0.7525 s |
| 1 000 000 | 5.6337 s | 1.4595 s | 0.4262 s | 0.6961 s | 1.0415 s | 9.2573 s |
| 10 000 000 | 55.493 s | 18.600 s | 9.0731 s | 7.3728 s | 10.351 s | 100.891 s |

### Rezultatai su `std::list`

| Įrašai | Nuskaitymas | Rūšiavimas | Dalijimas | Vargšiukų išv. | Kietiakų išv. | Viso |
|-------:|------------:|-----------:|----------:|---------------:|--------------:|-----:|
| 1 000 | 0.0062 s | 0.0002 s | 0.0003 s | 0.0018 s | 0.0019 s | 0.0105 s |
| 10 000 | 0.0604 s | 0.0040 s | 0.0036 s | 0.0069 s | 0.0124 s | 0.0875 s |
| 100 000 | 0.6077 s | 0.0683 s | 0.0471 s | 0.0650 s | 0.1065 s | 0.8949 s |
| 1 000 000 | 7.6566 s | 1.0397 s | 0.6317 s | 0.7147 s | 0.9549 s | 10.998 s |
| 10 000 000 | 55.090 s | 12.360 s | 7.7955 s | 6.9762 s | 11.069 s | 93.291 s |

<img width="391" height="594" alt="vector1" src="https://github.com/user-attachments/assets/0a09e056-b76c-4b84-8a4c-d473ab7af64b" />
<img width="376" height="382" alt="vector2" src="https://github.com/user-attachments/assets/1f19fb97-f26e-4517-9f8f-5d37867a60f5" />
<img width="417" height="610" alt="list1" src="https://github.com/user-attachments/assets/99ed24ce-732c-4d9d-b575-b1d297377b98" />
<img width="450" height="375" alt="list2" src="https://github.com/user-attachments/assets/43a730d5-a7d7-4bcb-8734-41b99d72c377" />

### Išvados

- **Nuskaitymas iš failo** – abu konteineriai veikia beveik identiškai, nes duomenų skaitymas labiausiai priklauso nuo disko (SSD) greičio, o ne nuo konteinerio tipo.
- **Rūšiavimas** – tai pati įdomiausia vieta. Su mažesniais duomenų kiekiais `std::vector` rūšiuoja greičiau. Tačiau su 10 000 000 įrašų `std::list` rūšiavimas (12.36 s) buvo **ženkliai greitesnis** nei `std::vector` (18.60 s). Tai nutinka todėl, kad mūsų `studentas` struktūra yra „sunki“ (turi du `string` ir vieną `vector`). `std::sort` (vector atveju) turi fiziškai perkelti visus šiuos didelius objektus atmintyje, o `std::list::sort` tiesiog sukeičia rodykles (pointerius) į atminties vietas. Esant dideliam duomenų kiekiui, rodyklių perstūmimas pasirodė efektyvesnis už objektų kopijavimą.
- **Dalijimas į grupes** – `std::list` taip pat buvo šiek tiek greitesnis (7.79 s prieš 9.07 s), nes dalijimo metu vėlgi perkėlinėjami rodyklės, o ne fiziškai kopijuojami dideli struktūros objektai.
- **Išvedimas į failus** – `std::vector` veikė šiek tiek greičiau (mažiau laiko sąnaudų ieškant elemento, nes jie atmintyje guli ištisai), bet skirtumas nedidelis.
- **Bendras laikas** – nors `vector` yra greitesnis su mažais duomenimis, su 10M įrašų `std::list` bendrai apdorojo duomenis greičiau (93.29 s prieš 100.89 s) dėl sparčiau atlikto rūšiavimo.

## v1.0 – Dalijimo strategijų optimizavimas

### Strategijų aprašymas

Tyrimo metu buvo realizuotos ir palygintos trys skirtingos studentų dalijimo į dvi kategorijas strategijos:

**1 strategija (Du nauji konteineriai):**
Studentai yra tiesiog nukopijuojami iš pradinio konteinerio į du naujus: `vargsiukai` ir `kietiakiai`. Pradinis konteineris lieka nepakitęs. 
*Šios strategijos trūkumas:* Ji yra neefektyvi atminties atžvilgiu, nes kiekvienas studentas atmintyje egzistuoja du kartus (originaliame sąraše ir viename iš naujų).

**2 strategija (Vienas naujas konteineris ir trynimas):**
Studentai, kurių balas < 5.0, yra nukopijuojami į `vargsiukai` konteinerį ir **ištrinami** iš pradinio. Po šio veiksmo pradiniame konteineryje lieka tik kietiakiai. 
*Šios strategijos privalumas:* Efektyvus atminties naudojimas. 
*Trūkumas:* Trynimas (`erase`) yra labai „skausmingas“ `std::vector` konteineriui, nes ištrinus elementą, visi likę elementai turi būti pastumti atmintyje. Tuo tarpu `std::list` trynimą atlieka akimirksniu.

**3 strategija (Optimizuota su STL algoritmais):**
Ši strategija – tai 2 strategijos patobulinimas, panaudojant efektyvius C++ standartinės bibliotekos (STL) algoritmus.
*   **`std::vector` atveju:** Panaudotas `std::partition` algoritmas, kuris per vieną ėjimą (O(N)) suskirsto vektorių į dvi dalis (vargšiukus priekyje, kietiakius gale). Tada vargsiukai nukopijuojami ir ištrinami vienu `erase` metodu. Tai leidžia išvengti lėto trynimo ciklo viduje.
*   **`std::list` atveju:** Panaudotas specialus `splice` metodas, kuris „perkelia“ atminties mazgus iš vieno sąrašo į kitą net nekopijuodamas studentų duomenų. Tai užima O(1) laiko.

### Testavimo rezultatai

**Rezultatai su `std::vector`**

| Įrašai | 1 strategija | 2 strategija | 3 strategija |
|-------:|-------------:|-------------:|-------------:|
| 1 000 | 0.00026 s | 0.01194 s | 0.00015 s |
| 10 000 | 0.00214 s | 1.11708 s | 0.00278 s |
| 100 000 | 0.01993 s | **117.681 s** | 0.01989 s |
| 1 000 000 | 0.18632 s | *(praleista)* | 0.21806 s |
| 10 000 000 | 2.72218 s | *(praleista)* | 11.7826 s |

**Rezultatai su `std::list`**

| Įrašai | 1 strategija | 2 strategija | 3 strategija |
|-------:|-------------:|-------------:|-------------:|
| 1 000 | 0.00057 s | 0.00017 s | 0.00009 s |
| 10 000 | 0.00312 s | 0.00293 s | 0.00131 s |
| 100 000 | 0.02862 s | 0.01920 s | 0.00947 s |
| 1 000 000 | 0.31070 s | 0.20922 s | 0.09863 s |
| 10 000 000 | 5.18789 s | 12.5937 s | 17.2927 s |

<img width="540" height="804" alt="13896b4e-0276-4802-8710-fdda7c7c5dcf" src="https://github.com/user-attachments/assets/a111a1bf-aff8-412f-8bfc-85ef58aadd7f" />
<img width="537" height="181" alt="2375c9e0-3588-4d43-b012-ee50e6fa2a8d" src="https://github.com/user-attachments/assets/b8b09416-6ce4-4ea8-95a1-5c236c3ca0cc" />

### Išvados

1. **Kodėl `Vector` 2 strategija yra katastrofiška?** 
   `std::vector` atmintyje elementus laiko ištisai. Ištrinant elementą iš vidurio, kompiuteris turi fiziškai pastumti visus likusius elementus į kairę (O(N) sudėtingumas). Su 100 000 įrašų tai užtruko beveik 118 sekundžių, todėl su 1 000 000 būtų užtrukę valandas. Ši strategija vektoriui yra visiškai netinkama.

2. **Kodėl `List` yra greitas su mažesniais duomenimis?** 
   `std::list` elementai sujungti rodyklėmis. Ištrynus elementą, tiesiog panaikinama rodyklė (O(1) sudėtingumas). Todėl 2 strategija liste veikia akimirksniu (pvz., 1M įrašų – vos 0.2 s).

3. **Netikėtas rezultatas su 10 milijonų įrašų (Cache atminties įtaka):** 
   Su 10M įrašų matome labai įdomų reiškinį:
   * `[Vector] 1 strategija` (2.72 s) buvo ženkliai greitesnė už 3 strategiją (11.78 s). Tai paaiškinama procesoriaus cache atmintimi – nuoseklus duomenų kopijavimas yra labai optimizuotas, o `std::partition` atlieka daug vietos keitimų, sukeliančių daug cache praleidimų (cache misses).
   * Panašiai ir liste: `[List] 3 strategija` su `splice` (17.29 s) tapo lėčiausia, pralaimėjusi net 1-ai strategijai (5.18 s). Rodyklių „vaikymasis“ milžiniškoje išmėtytoje atmintyje yra lėtas procesas.

4. **Bendras optimizavimas:** 
   Jei duomenų nedaug (iki 100k), 3 strategija yra akivaizdžiai geriausia. Tačiau su milžinišku duomenų kiekiu (10M) paprastas duomenų kopijavimas (1 strategija) gali netikėtai laimėti prieš sudėtingus algoritmus. Tai parodo, kad optimizavimas visada turi būti pagrįstas realiais testais, o ne aklu taisyklių taikymu.
