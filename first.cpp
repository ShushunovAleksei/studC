#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<stdlib.h>
#include <ctype.h>


#define MAX 3 
enum coefficents {
    COEFF_A = 0,
    COEFF_B = 1,
    COEFF_C = 2,

};

enum condition {
    TWO_SOL = 1,
    ONE_SOL = 0,
    NO_SOL = -1,
};

int programm_opening();
void read_coeff(double *arr);
bool read_valid_number(double *arr, const char *promt);
enum condition solve_equation(double *arr,  double *x1, double *x2);
void print_solution(double x1, double x2, enum condition status);



int main(){
    double arr[MAX];
    double root_solve1, root_solve2;
    root_solve1 = 0;
    root_solve2 = 0;

    bool want_to_solve = true ;

    while(want_to_solve){
        want_to_solve = programm_opening();
        if(want_to_solve){
            printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + c = 0\n");
        
            read_coeff(arr);
            enum condition status =  solve_equation(arr, &root_solve1, &root_solve2);
            print_solution(root_solve1, root_solve2, status);
        
        }
        }
    
    return 0;
}

int programm_opening(){
    char user_choice = 0;
    printf("хотите решить квадратное уравнение? (y/n)\n");
    scanf(" %c", &user_choice);
    
    if (user_choice == 'y' || user_choice == 'Y'){
        return 1;
    } else {
        return 0;
    }
}

void read_coeff(double *arr){
     read_valid_number(&arr[COEFF_A], "введите коэффицент перед x^2");
     read_valid_number(&arr[COEFF_B], "введите коэффицент перед x");
     read_valid_number(&arr[COEFF_C], "введите свободный коэффицент");
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
        }else{
            printf("нет корней\n");
        }
}
        
bool read_valid_number(double *value,  const char *promt){
    char buffer[100] = {0};
    char *point_to_the_end; 
    double number = 0;
    while(true){
        printf("%s", promt);
        fgets(buffer, sizeof(buffer), stdin);

        if(buffer[0] == '\0' || buffer[0] == '\n'){
            printf("пустой ввод\n");
            continue;
        }

        number = strtod(buffer, &point_to_the_end);

        while(*point_to_the_end != '\0' && *point_to_the_end != '\n'){
            if(!isspace(*point_to_the_end)){
                printf("ошибка ввода\n");
                break;
            }
            point_to_the_end++;
            }
        if(*point_to_the_end != '\0' || *point_to_the_end != '\n'){
            
            continue; 
        }
}
    *value = number;
    return true;
}