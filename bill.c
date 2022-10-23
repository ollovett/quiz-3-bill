#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *food;
    double price;
} FoodItem, *PtrToFoodItem;
typedef const FoodItem *PtrToConstFoodItem;

const FoodItem FoodTable[] = {
    {"Salad", 9.95},
    {"Soup", 4.55},
    {"Sandwhich", 13.25},
    {"Pizza", 22.35},
};

int main(int argc, char **argv) {
    char* pass;
    double tax;
    double tip;

    tax = strtod(argv[1], &pass);
    tip = strtod(argv[2], &pass);
    
    // generate random number and use that number to select random food item
    srand(time(0));
    int randomfood = rand() % 4;

    // calculate tax
    tax = FoodTable[randomfood].price * tax;
    
    // calculate tip
    tip = FoodTable[randomfood].price * tip;
    
    // total bill
    double totalbill = FoodTable[randomfood].price + tax + tip;
    
    // print food item and cost, tax, tip, and total bill
    printf("Food Item: %s\n", FoodTable[randomfood].food);
    printf("Tax: %.2f\n", tax);
    printf("Tip: %.2f\n", tip);
    printf("Total Bill: %.2f\n", totalbill);

    return 0;
}
