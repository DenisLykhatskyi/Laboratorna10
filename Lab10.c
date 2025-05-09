#include <stdio.h>

void ввестиМасив(int масив[], int розмір, int номерМасиву) {
    printf("Введіть %d цілих чисел для масиву %d:\n", розмір, номерМасиву);
    for (int i = 0; i < розмір; ++i) {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &масив[i]);
    }
}

void проаналізуватиМасив(int масив[], int розмір, int поріг, int номерМасиву) {
    long long сумаМенших = 0;
    int кількістьМенших = 0;

    for (int i = 0; i < розмір; ++i) {
        if (масив[i] < поріг) {
            сумаМенших += масив[i];
            кількістьМенших++;
        }
    }

    printf("\nРезультати для масиву %d:\n", номерМасиву);
    printf("Сума елементів, менших за %d: %lld\n", поріг, сумаМенших);
    printf("Кількість елементів, менших за %d: %d\n", поріг, кількістьМенших);

    if (кількістьМенших > 0) {
        double середнєЗначення = (double)сумаМенших / кількістьМенших;
        printf("Середнє значення цих елементів: %.2f\n", середнєЗначення);
    } else {
        printf("Середнє значення цих елементів: 0.00 (оскільки немає елементів, менших за %d)\n", поріг);
    }
}

int main() {
    int поріг;

    printf("Введіть порогове число: ");
    scanf("%d", &поріг);

    for (int i = 0; i < 3; ++i) {
        int розмірМасиву;
        printf("\nДля масиву %d:\n", i + 1);
        printf("Введіть кількість елементів: ");
        scanf("%d", &розмірМасиву);

        if (розмірМасиву > 0) {
            int поточнийМасив[розмірМасиву];
            ввестиМасив(поточнийМасив, розмірМасиву, i + 1);
            проаналізуватиМасив(поточнийМасив, розмірМасиву, поріг, i + 1);
        } else {
            printf("Розмір масиву повинен бути більшим за 0. Обробка масиву %d пропущена.\n", i + 1);
        }
    }

    return 0;
}