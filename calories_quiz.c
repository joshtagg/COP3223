
#include <stdio.h>

#define CALS_PROTEIN 4
#define CALS_CARB 4
#define CALS_FAT 9

int main() {
    int total, protein, carbs, fat;

    printf("How many grams of protein did you eat?\n");
    scanf("%d", &protein);

    printf("How many grams of carbohydrates did you eat?\n");
    scanf("%d", &carbs);

    printf("How many grams of fat did you eat?\n");
    scanf("%d", &fat);

    total = protein * CALS_PROTEIN + carbs * CALS_CARB + fat * CALS_FAT;

    printf("You ate %d calories of food.\n", total);

    return 0;
}
