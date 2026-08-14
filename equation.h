#ifndef EQUATION_H
#define EQUATION_H


enum coefficents {
    COEFF_A_INDEX = 0,
    COEFF_B_INDEX = 1,
    COEFF_C_INDEX = 2,

};

enum condition {
    TWO_SOL = 2,
    ONE_SOL = 1,
    NO_SOL = 0,
    correct_inp = 3,
    incorrect_inp = -1
};

int programm_opening();
enum condition read_coeff(double *arr);
enum condition read_valid_number(double *arr, const char *promt);
enum condition solve_quadratic_equation(double *arr,  double *x1, double *x2);
void print_solution(double x1, double x2, enum condition status);
enum condition solve_equation(double *arr_variables, double *x1, double *x2);
#endif