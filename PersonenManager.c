#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char vereinName[31];
    char vereinThema[21];
} TClub;

typedef struct {
    char vorname[20];
    char nachname[20];
    int geburtsjahr;
    float gewicht;
    float groesse;
    TClub lieblingsVerein;
} TPerson;

TPerson family[4];

int compareByBirthYear(const void *a, const void *b) {
    return ((TPerson*)a)->geburtsjahr - ((TPerson*)b)->geburtsjahr;
}

int compareByWeight(const void *a, const void *b) {
    return ((TPerson*)a)->gewicht - ((TPerson*)b)->gewicht;
}

int compareBygroesse(const void *a, const void *b) {
    return ((TPerson*)a)->groesse - ((TPerson*)b)->groesse;
}

void initFamily() {

    strcpy(family[0].vorname, "John");
    strcpy(family[0].nachname, "Doe");
    family[0].geburtsjahr = 1981;
    family[0].gewicht = 91;
    family[0].groesse = 196;
    strcpy(family[0].lieblingsVerein.vereinName, "FCB");
    strcpy(family[0].lieblingsVerein.vereinThema, "Fußball");

    strcpy(family[1].vorname, "Jane");
    strcpy(family[1].nachname, "Doe");
    family[1].geburtsjahr = 1980;
    family[1].gewicht = 64;
    family[1].groesse = 178;
    strcpy(family[1].lieblingsVerein.vereinName, "Schweiz");
    strcpy(family[1].lieblingsVerein.vereinThema, "Ski");

    strcpy(family[2].vorname, "Jack");
    strcpy(family[2].nachname, "Doe");
    family[2].geburtsjahr = 2008;
    family[2].gewicht = 40;
    family[2].groesse = 163;
    strcpy(family[2].lieblingsVerein.vereinName, "FCB");
    strcpy(family[2].lieblingsVerein.vereinThema, "Fussball");

    strcpy(family[3].vorname, "Judy");
    strcpy(family[3].nachname, "Doe");
    family[3].geburtsjahr = 2015;
    family[3].gewicht = 30;
    family[3].groesse = 124;
    strcpy(family[3].lieblingsVerein.vereinName, "FCB");
    strcpy(family[3].lieblingsVerein.vereinThema, "Fussball");
}

void printPerson(TPerson person) {
    printf("Vorname: %s\n", person.vorname);
    printf("Nachname: %s\n", person.nachname);
    printf("Geburtsjahr: %d\n", person.geburtsjahr);
    printf("Gewicht: %.1f kg\n", person.gewicht);
    printf("Größe: %.1f cm\n", person.groesse);
    printf("Lieblingsverein: %s\n", person.lieblingsVerein.vereinName);
    printf("Vereinsthema: %s\n", person.lieblingsVerein.vereinThema);
    printf("\n");
}

void printFamily() {
    for (int i = 0; i < 4; i++) {
        printPerson(family[i]);
    }
}

void sortFamily(int (*compareFunction)(const void *, const void *)) {
    qsort(family, 4, sizeof(TPerson), compareFunction);
}

int main() {
    initFamily();
    printf("Unsortierte Familie:\n");
    printFamily();

    int choice;
    printf("Wähle ein Sortierkriterium:\n");
    printf("1. Nach Geburtsjahr\n");
    printf("2. Nach Gewicht\n");
    printf("3. Nach Grösse\n");
    scanf("%d", &choice);

    if (choice == 1) {
        sortFamily(compareByBirthYear);
    } else if (choice == 2) {
        sortFamily(compareByWeight);
    } else if (choice == 3) {
        sortFamily(compareBygroesse);
    } else {
        printf("Ungültige Auswahl.\n");
        return 1;
    }

    printf("Familie sortiert:\n");
    printFamily();

    return 0;
}