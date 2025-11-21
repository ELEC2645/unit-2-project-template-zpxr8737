#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funcs.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// FUNCTION PROTOTYPES
void main_menu_with_features(void);
void example_calc(void);
void run_tests(void);
void load_results(void);

// AUTOMATED TESTS

#define RUN_TESTS 1

double test_add(double a, double b) {
    return a + b;
}

void run_tests() {
    printf("\n===== AUTOMATED TESTS =====\n");

    double r = test_add(3, 4);
    printf("Test add(3,4) → %.2f  [%s]\n",
           r, (r == 7 ? "PASS" : "FAIL"));

    double r2 = test_add(5, 5);
    printf("Test add(5,5) → %.2f  [%s]\n",
           r2, (r2 == 11 ? "PASS" : "FAIL"));

    printf("===========================\n\n");
}

// MAIN MENU 

void main_menu_with_features(void) {
    if (RUN_TESTS) run_tests();
    load_results();

    while (1) {
        print_main_menu();
        int choice = get_user_input();
        select_menu_item(choice);
    }
}

// EXAMPLE CALCULATION 

void example_calc(void) {
    double angle = M_PI / 4;
    double sine_val = sin(angle);

    printf("\nExample Calculation: sin(pi/4) = %.4f\n", sine_val);

    save_result_val("sin(pi/4)", sine_val);
    print_bar_graph("Sine Value", sine_val * 50);
}

// MAIN FUNCTION 

int main() {
    printf("=== Engineering Tools Program ===\n");

    example_calc(); // file saving, graphing
    main_menu_with_features(); // run full menu system

    return 0;
}
