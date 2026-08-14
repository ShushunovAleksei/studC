#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<stdlib.h>
#include <ctype.h>
#include "equation.h"






int main(){
    double arr_variables[3] = {0};
    double root_solve1, root_solve2;
    root_solve1 = 0;
    root_solve2 = 0;

    bool want_to_solve = programm_opening() ;

    while(want_to_solve){
        printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + coeff_c = 0\n");
        
        enum condition status_vr = read_coeff(arr_variables);
        enum condition status;

        if(status_vr == correct_inp){
            if(arr_variables[COEFF_A_INDEX] != 0){
                status = solve_quadratic_equation(arr_variables, &root_solve1, &root_solve2);
            }else{
                printf("уравнение не квадратное\n");
                status = solve_equation(arr_variables, &root_solve1, &root_solve2);
            }
        }
        
        print_solution(root_solve1, root_solve2, status);
        
        want_to_solve = programm_opening();
        }
    
    return 0;
}

int programm_opening(){
    char user_choice = 0;
    printf("хотите решить квадратное уравнение? (y/n)\n");
    scanf(" %coeff_c", &user_choice);

    while(getchar() != '\n');
    
    if (user_choice == 'y' || user_choice == 'Y'){
        return 1;
    } else {
        return 0;
    }
}

enum condition read_coeff(double *arr_variables){
    const char *promts[3] = {
        "введите коэффицент перед x^2",
        "введите коэффицент перед x",
        "введите свободный коэффицент"
    };
    int status_in_proc;
    for(int i = 0; i < 3; ++i){
        enum condition status_in_proc = read_valid_number(&arr_variables[i], promts[i]);
        if(status_in_proc == incorrect_inp){
            return status_in_proc; 
        }
    }
    return correct_inp;
}


enum condition solve_quadratic_equation(double *arr_variables, double *x1, double *x2){
    double coeff_a = arr_variables[COEFF_A_INDEX];
    double coeff_b = arr_variables[COEFF_B_INDEX];
    double coeff_c = arr_variables[COEFF_C_INDEX];
    double D = coeff_b*coeff_b - 4*coeff_a*coeff_c;

    enum condition result;
    if (D > 0 ){
        
        *x1 = (-coeff_b+sqrt(D))/(2*coeff_a);
        *x2 = (-coeff_b-sqrt(D))/(2*coeff_a);
        result = TWO_SOL;
    }else if(D == 0){
        
        *x1 = -coeff_b/(2*coeff_a);
        *x2 = *x1;
        result = ONE_SOL;
    } else{
        result = NO_SOL;
    }
    for(int i = 0; i < 3; i++){
        arr_variables[i] = 0; 
    }
    return result;
}

void print_solution(double x1, double x2, enum condition status){
    switch(status){
        case  TWO_SOL:
            printf("корни уравнения: %lf %lf\n",  x1, x2);
            break;
        case ONE_SOL:
            printf("корень уравнения: %lf\n", x1);
            break;
        case incorrect_inp:
            printf("некорректный ввод\n");
            break;
        case NO_SOL:
            printf("нет корней\n");
            break;
        default:
            printf("неизвестный статус\n");
            break;
    }
}

        
enum condition read_valid_number(double *value,  const char *promt){
    printf("%s\n", promt);
    double number = 0;
    char buffer[100] = {0};
    char *endword = 0;

    fgets(buffer, sizeof(buffer), stdin);
    if(buffer[0] == '\n' || buffer[0] == '\0'){
        printf("пустой ввод\n");
        return incorrect_inp;
    }else {
        number = strtod(buffer, &endword);

        if(*endword != '\0' && *endword != '\n'){
            printf("некорректный ввод\n");
            return incorrect_inp;
        }
        *value = number;
        return correct_inp;
    }
}

enum condition solve_equation(double *arr_variables, double *x1, double *x2){
    double coeff_b = arr_variables[COEFF_B_INDEX];
    double coeff_c = arr_variables[COEFF_C_INDEX];
    if(coeff_b == 0){
        return NO_SOL;
    }else{
        *x1 = *x2 = (-coeff_c)/coeff_b ;
        return ONE_SOL;
    }
}