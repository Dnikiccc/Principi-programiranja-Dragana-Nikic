#include <stdio.h>

#define MAX_STUDENTS 10

int ocjene[MAX_STUDENTS];
int brojStudenata = 0;

void unosOcjena() {
    printf("Unesite broj studenata (1-10): ");
    scanf("%d", &brojStudenata);

    if (brojStudenata < 1 || brojStudenata > MAX_STUDENTS) {
        printf("Greska: Broj studenata mora biti izmedju 1 i 10.\n");
        return;
    }

    for (int i = 0; i < brojStudenata; i++) {
        do {
            printf("Unesite ocjenu za studenta %d (izmedju 5 i 10): ", i + 1);
            scanf("%d", &ocjene[i]);
            if (ocjene[i] < 5 || ocjene[i] > 10) {
                printf("Greska: Ocjena mora biti izmedju 5 i 10.\n");
            }
        } while (ocjene[i] < 5 || ocjene[i] > 10); 
    }
}

void prikaziProsjek() {
    if (brojStudenata == 0) {
        printf("Nema unesenih ocjena.\n");
        return;
    }

    int suma = 0;
    for (int i = 0; i < brojStudenata; i++) {
        suma += ocjene[i];
    }

    printf("Prosjecna ocjena: %.2f\n", (float)suma / brojStudenata);
}

void prikaziNajboljeINajlosije() {
    if (brojStudenata == 0) {
        printf("Nema unesenih ocjena.\n");
        return;
    }

    int max = ocjene[0], min = ocjene[0];
    for (int i = 1; i < brojStudenata; i++) {
        if (ocjene[i] > max) max = ocjene[i];
        if (ocjene[i] < min) min = ocjene[i];
    }

    printf("Najbolja ocjena: %d\nNajlosija ocjena: %d\n", max, min);
}

int main() {
    int izbor;

    do {
        printf("\n*******************************\n");
        printf(" Sistem ocjenjivanja\n");
        printf("*******************************\n");
        printf("1. Unos ocjena studenata\n");
        printf("2. Prikaz prosjecne ocjene\n");
        printf("3. Prikaz najbolje i najlosije ocjene\n");
        printf("0. Izlaz\n");
        printf("*******************************\n");
        printf("Unesite opciju: ");
        scanf("%d", &izbor);

        switch (izbor) {
            case 1:
                unosOcjena();
                break;
            case 2:
                prikaziProsjek();
                break;
            case 3:
                prikaziNajboljeINajlosije();
                break;
            case 0:
                printf("Izlaz iz programa.\n");
                break;
            default:
                printf("Nepostojeca opcija. Pokusajte ponovo.\n");
        }
    } while (izbor != 0);

    return 0;
}
