#ifndef EQUATION_H
#define EQUATION_H


enum coefficents {
    COEFF_A = 0,
    COEFF_B = 1,
    COEFF_C = 2,

};

enum condition {
    TWO_SOL = 2,
    ONE_SOL = 1,
    NO_SOL = -1,
    correct_inp = 3,
    incorrect_inp = 0
};

int programm_opening();
enum condition read_coeff(double *arr);
enum condition read_valid_number(double *arr, const char *promt);
enum condition solve_equation(double *arr,  double *x1, double *x2);
void print_solution(double x1, double x2, enum condition status);
#endif