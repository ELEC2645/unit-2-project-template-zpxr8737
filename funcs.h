#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//MENU ITEM FUNCTIONS
void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);
void menu_item_5(void);

// MENU SYSTEM FUNCTIONS
void main_menu(void);
int get_user_input(void);
void select_menu_item(int input);
void print_main_menu(void);
void go_back_to_main(void);

// HELPER FUNCTIONS
void save_result_val(const char *label, double value);
void load_results(void);
void print_bar_graph(const char *label, double value);

#endif