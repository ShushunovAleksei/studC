#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<stdlib.h>
#include <ctype.h>



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



int main(){
    double arr[3] = {0};
    double root_solve1, root_solve2;
    root_solve1 = 0;
    root_solve2 = 0;

    bool want_to_solve = programm_opening() ;

    while(want_to_solve){
        printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + c = 0\n");
        
        enum condition status = read_coeff(arr);

        if(status == correct_inp){
            status = solve_equation(arr, &root_solve1, &root_solve2);
        }
        
        print_solution(root_solve1, root_solve2, status);
        
        want_to_solve = programm_opening();
        }
    
    return 0;
}

int programm_opening(){
    char user_choice = 0;
    printf("хотите решить квадратное уравнение? (y/n)\n");
    scanf(" %c", &user_choice);

    while(getchar() != '\n');
    
    if (user_choice == 'y' || user_choice == 'Y'){
        return 1;
    } else {
        return 0;
    }
}

enum condition read_coeff(double *arr){
    const char *promts[3] = {
        "введите коэффицент перед x^2",
        "введите коэффицент перед x",
        "введите свободный коэффицент"
    };
    int status_in_proc;
    for(int i = 0; i < 3; ++i){
        enum condition status_in_proc = read_valid_number(&arr[i], promts[i]);
        if(status_in_proc == incorrect_inp){
        return status_in_proc; 
        }
    }
    return correct_inp;
}


enum condition solve_equation(double *arr, double *x1, double *x2){
    double a = arr[COEFF_A];
    double b = arr[COEFF_B];
    double c = arr[COEFF_C];
    double D = b*b - 4*a*c;

    enum condition result;
    if (D > 0 ){
        
        *x1 = (-b+sqrt(D))/(2*a);
        *x2 = (-b-sqrt(D))/(2*a);
        result = TWO_SOL;
    }else if(D == 0){
        
        *x1 = -b/(2*a);
        *x2 = *x1;
        result = ONE_SOL;
    } else{
        result = NO_SOL;
    }
    for(int i = 0; i < 3; i++){
        arr[i] = 0; 
    }
    return result;
}

void print_solution(double x1, double x2, enum condition status){
        if(status == TWO_SOL){
            printf("корни уравнения: %lf %lf\n",  x1, x2);
        }else if(status == ONE_SOL){
            printf("корень уравнения: %lf\n", x1);
        }else if(status == incorrect_inp){
            printf("некорректный ввод\n");
        }else{
            printf("нет корней\n");
        }
}

        
enum condition read_valid_number(double *value,  const char *promt){
    printf("%s\n", promt);
    double number = 0;
    char buffer[100] = {0};
    char *endword;
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