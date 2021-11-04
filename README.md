# blockChainProject
---
1. Sugeneruoti ~1000 tinklo vartotojų (aka user'ių), kurie turėtų bent tris atributus:
vardą,
viešąjį hash raktą (public_key)
tam tikros valiutos atsitiktinį balansą (pvz., nuo 100 iki 1000000 valiutos vienetų).
2. Sugeneruoti ~10000 naujų, į jokį bloką dar neįdėtų, transakcijų pool'ą, o transakcijos turėtų bent šiuos atributus:
transakcijos ID (kitų transakcijos laukų hash'as),
siuntėjas (jo viešasis raktas)
gavėjas (jo viešasis raktas)
suma
3. Iš transakcijų pool'o atsitiktinai pasirinkti 100-ą transakcijų, kurias bandysime įdėti į naują bloką (tarsime, kad naujas blokas talpins apie
100 transakcijų). Reikiama bloko struktūra ir būtini atributai pateikti paveiksle aukščiau.
4. Realizuokite naujų blokų kasimo (angl. mining) Proof-of-Work (PoW) tipo procesą, kurio tikslas yra surasti naujam blokui hash'ą, tenkinantį
Difficulty Targer reikalavimą, t.y., hash'o pradžioje esančių nulių tam tikrą skaičių. Nulių skaičius priklauso nuo Jūsų sukurto hash
funkcijos savybių ir efektyvumo. Paeksperimentuokite, kad tai neužtruktų per ilgai. Kaip matyti, bloko kasimui yra reikalingas transakcijų
Merkle hash'as, kuris taip pat turi būti realizuotas (žr. detalizaciją versijų reikalavimuose).
5. Suradus tokį naujo bloko hash'ą:
į naują bloką priskirtas transakcijas ištrinkite iš transakcijų pool'o;
"įvykdykite" transakcijas, t.y., atnaujinkite tinklo vartotojų balansus;
naują bloką pridėkite prie blockchain grandinės.
6. Kartoti 3-5 žingsnius tol, kol yra laisvų transakcijų. Galima būtų įtraukti ir visus 1-5 žingsnius, tokiu būdu įtraukiant naujų vartotojų ir/ar
transakcijų kūrimą, o ciklą stabdyti naudojantis kitomis logiškomis sąlygomis
---
## Instructions

Run terminal in directory of project file
Terminal command for compiling:
- On Windows ``` mingw32-make main ```
- On Linux, Mac OS ``` make main ```

Terminal command for running:
- On windows ``` ./main ```
- On Linux, Mac OS ``` ./main ```

---
## Versions
v1.0 Is able to mine all blocks and works instantaniously upon running

v2.0 Sometimes has hiccups and the process cuts out when simulating "decentralised" mining
