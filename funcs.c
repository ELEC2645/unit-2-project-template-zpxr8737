#include "funcs.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Helper functions for file saving and graphing

void save_result_val(const char *label, double value) {
    FILE *fp = fopen("results.txt", "a");
    if (!fp) {
        printf("Error: cannot open results.txt\n");
        return;
    }
    fprintf(fp, "%s: %.4f\n", label, value);
    fclose(fp);
    printf("[Saved: %s]\n", label);
}

void load_results(void) {
    FILE *fp = fopen("results.txt", "r");
    if (!fp) {
        printf("No saved results found.\n\n");
        return;
    }

    printf("\n--- Saved Results ---\n");
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    printf("---------------------\n\n");
    fclose(fp);
}

void print_bar_graph(const char *label, double value) {
    printf("%s | ", label);
    int len = (int)value;
    if (len < 0) len = 0;
    if (len > 60) len = 60; // max width
    for (int i = 0; i < len; i++) printf("#");
    printf(" (%.2f)\n", value);
}

// MENU SYSTEM
void main_menu(void) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input);
}

int get_user_input(void) {
    int input;
    printf("\nSelect item: ");
    scanf("%d", &input);
    return input;
}

void select_menu_item(int input) {
    switch (input) {
        case 1: menu_item_1(); break;
        case 2: menu_item_2(); break;
        case 3: menu_item_3(); break;
        case 4: menu_item_4(); break;
        case 5: menu_item_5(); break;
        case 6: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

void print_main_menu(void) {
    printf("\n----------- Engineering Tools Menu -----------\n");
    printf("1. Resistor Colour Code Decoder\n");
    printf("2. Basic Circuit Analyzer (Series/Parallel)\n");
    printf("3. Engineering Unit Converter\n");
    printf("4. AI Circuit Assistant\n");
    printf("5. Linear Algebra Library\n");
    printf("6. Exit\n");
    printf("---------------------------------------------\n");
}

void go_back_to_main(void) {
    char input;
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        scanf(" %c", &input);
    } while (input != 'b' && input != 'B');
    main_menu();
}

// MENU ITEM 1
void menu_item_1(void) {
    printf("\n>> Menu 1: Resistor Colour Code Decoder\n");

    char band1[10], band2[10], multiplier[10];
    int d1, d2, mul;

    printf("Enter band 1 colour (Black=0, Brown=1...): ");
    scanf("%s", band1);
    printf("Enter band 2 colour: ");
    scanf("%s", band2);
    printf("Enter multiplier band: ");
    scanf("%s", multiplier);

    d1 = atoi(band1);
    d2 = atoi(band2);
    mul = atoi(multiplier);

    float resistance = ((d1 * 10) + d2) * pow(10, mul);

    printf("Resistance = %.2f ohms\n", resistance);

    go_back_to_main();
}

// MENU ITEM 2
void menu_item_2(void) {
    printf("\n>> Menu 2: Basic Circuit Analyzer\n");

    int choice;
    float r1, r2, total;

    printf("1. Series\n2. Parallel\nSelect mode: ");
    scanf("%d", &choice);

    printf("Enter R1: ");
    scanf("%f", &r1);

    printf("Enter R2: ");
    scanf("%f", &r2);

    if (choice == 1) {
        total = r1 + r2;
        printf("Total Series Resistance = %.2f ohms\n", total);
    } else {
        total = (r1 * r2) / (r1 + r2);
        printf("Total Parallel Resistance = %.2f ohms\n", total);
    }

    go_back_to_main();
}

// MENU ITEM 3
void menu_item_3(void) {
    printf("\n>> Menu 3: Engineering Unit Converter\n");

    int choice;
    float value;

    printf("1. Hz to rad/s\n2. rad/s to Hz\nSelect: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%f", &value);

    if (choice == 1) {
        printf("%.2f Hz = %.2f rad/s\n", value, value * 2 * M_PI);
    } else {
        printf("%.2f rad/s = %.2f Hz\n", value, value / (2 * M_PI));
    }

    go_back_to_main();
}

// MENU ITEM 4 
void menu_item_4(void) {
    printf("\n>> Menu 4: AI Circuit Assistant\n");

    int choice;

    printf("1. Concept Tutor\n");
    printf("2. Solve a Basic Circuit Problem (Ohm’s Law)\n");
    printf("3. Formula Lookup & Calculator\n");
    printf("4. Component Identifier\n");
    printf("5. Study / Exam Prep Mode\n");
    printf("Select: ");
    scanf("%d", &choice);

    // ---------------- Concept Tutor ----------------
    if (choice == 1) {
        int topic;
        printf("\nConcept Tutor:\n");
        printf("1. Series & Parallel Resistors\n");
        printf("2. Kirchhoff’s Laws\n");
        printf("3. Capacitors & Inductors\n");
        printf("4. Impedance (AC circuits)\n");
        printf("Select topic: ");
        scanf("%d", &topic);

        switch (topic) {
            case 1:
                printf("Series: R_total = R1 + R2 + ...\n");
                printf("Parallel: 1/R_total = 1/R1 + 1/R2 + ...\n");
                break;
            case 2:
                printf("KVL: Sum of voltages in a loop = 0\n");
                printf("KCL: Sum of currents entering a node = sum leaving\n");
                break;
            case 3:
                printf("Capacitor stores energy in an electric field.\n");
                printf("Inductor stores energy in a magnetic field.\n");
                break;
            case 4:
                printf("Impedance Z = R + jX\n");
                printf("Xc = 1/(2πfC),  Xl = 2πfL\n");
                break;
            default:
                printf("Invalid topic.\n");
        }
    }

    // ---------------- Solve OHM's Law ----------------
    else if (choice == 2) {
        float v, r;
        printf("\nEnter Voltage (V): ");
        scanf("%f", &v);
        printf("Enter Resistance (R): ");
        scanf("%f", &r);
        printf("Current I = %.3f A\n", v / r);
    }

    // ------------ Formulas-----------
    else if (choice == 3) {
        int f;
        float val1, val2;

        printf("\nFormula Lookup & Calculator:\n");
        printf("1. Power (P = VI)\n");
        printf("2. Capacitive Reactance (Xc = 1/(2πfC))\n");
        printf("3. Inductive Reactance (Xl = 2πfL)\n");
        printf("4. Voltage Divider\n");
        printf("Select: ");
        scanf("%d", &f);

        switch (f) {
            case 1:
                printf("Enter Voltage: ");
                scanf("%f", &val1);
                printf("Enter Current: ");
                scanf("%f", &val2);
                printf("Power = %.3f W\n", val1 * val2);
                break;

            case 2:
                printf("Enter Frequency (Hz): ");
                scanf("%f", &val1);
                printf("Enter Capacitance (F): ");
                scanf("%f", &val2);
                printf("Xc = %.3f ohms\n", 1.0 / (2 * 3.14159f * val1 * val2));
                break;

            case 3:
                printf("Enter Frequency (Hz): ");
                scanf("%f", &val1);
                printf("Enter Inductance (H): ");
                scanf("%f", &val2);
                printf("Xl = %.3f ohms\n", 2 * 3.14159f * val1 * val2);
                break;

            case 4:
                printf("Enter Vin: ");
                scanf("%f", &val1);
                float r1, r2;
                printf("Enter R1: "); scanf("%f", &r1);
                printf("Enter R2: "); scanf("%f", &r2);
                printf("Vout = %.3f V\n", val1 * (r2 / (r1 + r2)));
                break;

            default:
                printf("Invalid selection.\n");
        }
    }

    // ---------------- Component Identifier ----------------
    else if (choice == 4) {
        int c;
        printf("\nComponent Identifier:\n");
        printf("1. LED\n");
        printf("2. Diode\n");
        printf("3. Transistor (NPN/PNP)\n");
        printf("4. Capacitor Polarity\n");
        printf("Select component: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("LED: Forward drop ≈ 1.8–3.3V. Use a series resistor!\n");
                printf("ASCII Diagram: [ +|>|- ]\n");
                break;
            case 2:
                printf("Diode: Allows current in one direction.\n");
                printf("ASCII: |>| symbol\n");
                break;
            case 3:
                printf("NPN: Arrow OUT. PNP: Arrow IN.\n");
                break;
            case 4:
                printf("Electrolytic capacitors have a marked NEGATIVE stripe.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    }

    // ---------------- Study Mode ----------------
    else if (choice == 5) {
        int q, ans, score = 0;

        printf("\nStudy Mode: 3 Random Questions\n");

        // Q1
        printf("\n1) What is Ohm’s Law?\n");
        printf("1: V = IR   2: P = VI\n");
        scanf("%d", &ans);
        if (ans == 1) score++;

        // Q2
        printf("\n2) Capacitive reactance decreases when:\n");
        printf("1: Frequency increases   2: Frequency decreases\n");
        scanf("%d", &ans);
        if (ans == 1) score++;

        // Q3
        printf("\n3) KCL applies to:\n");
        printf("1: Voltage in loops   2: Current at nodes\n");
        scanf("%d", &ans);
        if (ans == 2) score++;

        printf("\nYour Score: %d / 3\n", score);
    }

    

    go_back_to_main();
}


// MENU ITEM 5
void menu_item_5(void) {
    printf("\n>> Menu 5: Linear Algebra Library\n");

    int choice;
    printf("1. Matrix Addition (2x2)\n");
    printf("2. Matrix Multiplication (2x2)\n");
    printf("3. Matrix Division (A × B^-1, 2x2)\n");
    printf("4. Determinant (2x2)\n");
    printf("Select: ");
    scanf("%d", &choice);

    float a[2][2], b[2][2], result[2][2];
    float det;

    if (choice == 1) {
        printf("Enter Matrix A (2x2): ");
        scanf("%f %f %f %f", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
        printf("Enter Matrix B (2x2): ");
        scanf("%f %f %f %f", &b[0][0], &b[0][1], &b[1][0], &b[1][1]);

        result[0][0] = a[0][0] + b[0][0];
        result[0][1] = a[0][1] + b[0][1];
        result[1][0] = a[1][0] + b[1][0];
        result[1][1] = a[1][1] + b[1][1];

        printf("Result (A + B):\n%.2f %.2f\n%.2f %.2f\n",
               result[0][0], result[0][1], result[1][0], result[1][1]);
    }

    else if (choice == 2) {
        printf("Enter Matrix A (2x2): ");
        scanf("%f %f %f %f", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
        printf("Enter Matrix B (2x2): ");
        scanf("%f %f %f %f", &b[0][0], &b[0][1], &b[1][0], &b[1][1]);

        result[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
        result[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
        result[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
        result[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];

        printf("Result (A × B):\n%.2f %.2f\n%.2f %.2f\n",
               result[0][0], result[0][1], result[1][0], result[1][1]);
    }

    else if (choice == 3) {
        printf("Enter Matrix A (2x2): ");
        scanf("%f %f %f %f", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
        printf("Enter Matrix B (2x2): ");
        scanf("%f %f %f %f", &b[0][0], &b[0][1], &b[1][0], &b[1][1]);

        det = b[0][0]*b[1][1] - b[0][1]*b[1][0];

        if(det == 0) {
            printf("Matrix B has no inverse. Division impossible.\n");
        } else {
            float invB[2][2];
            invB[0][0] =  b[1][1]/det;
            invB[0][1] = -b[0][1]/det;
            invB[1][0] = -b[1][0]/det;
            invB[1][1] =  b[0][0]/det;

            result[0][0] = a[0][0]*invB[0][0] + a[0][1]*invB[1][0];
            result[0][1] = a[0][0]*invB[0][1] + a[0][1]*invB[1][1];
            result[1][0] = a[1][0]*invB[0][0] + a[1][1]*invB[1][0];
            result[1][1] = a[1][0]*invB[0][1] + a[1][1]*invB[1][1];

            printf("Result (A × B^-1):\n%.2f %.2f\n%.2f %.2f\n",
                   result[0][0], result[0][1], result[1][0], result[1][1]);
        }
    }

    else if (choice == 4) {
        printf("Enter Matrix A (2x2): ");
        scanf("%f %f %f %f", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
        det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
        printf("Determinant = %.2f\n", det);
    }

    go_back_to_main();
}
