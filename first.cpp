#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#define MAX 3 
enum coefficents {
    coeff_a = 0,
    coeff_b = 1,
    coeff_c = 2,

};

enum condition {
    two_sol = 2,
    one_sol = 1,
    no_sol = -1,
};

int opening();
void read_coeff(double *arr);
enum condition solve_equation(double *arr,  double *x1, double *x2);


int main(){
    double arr[MAX];
    double root_of_the_solve1, root_of_the_solve2;
    root_of_the_solve1 = 0;
    root_of_the_solve2 = 0;

    bool want = true ;

    while(want){
        want = opening();
        if(want){
            printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + c = 0\n");
        
            read_coeff(arr);
            enum condition status =  solve_equation(arr,&root_of_the_solve1, &root_of_the_solve2);
            if(status == two_sol){
                printf("корни уравнения: %ls %ls\n",  root_of_the_solve1, root_of_the_solve2);
            }else if(status == one_sol){
                printf("корень уравнения: %ls\n", root_of_the_solve1);
            }else{
                printf("нет корней\n");
            }
        
        }else{
            want = false ;
        }
    }
}

int opening(){
    char choice = 0;
    printf("хотите решить квадратное уравнение? (y/n)\n");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y'){
        return 1;
    } else {
        return 0;
    }
}

void read_coeff(double *arr){
    printf("напишите значение коэффицента перед х^2\n");
    scanf("%lf", &arr[coeff_a]);
   
    printf("напишите значение коэффицента перед х\n");
    scanf("%lf", &arr[coeff_b]);
    
    printf("напишите значение свободного коэффицента \n");
    scanf("%lf", &arr[coeff_c]);
}



enum condition solve_equation(double *arr, double *x1, double *x2){
    double a = arr[coeff_a];
    double b = arr[coeff_b];
    double c = arr[coeff_c];
    double D = b*b - 4*a*c;

    enum condition result;
    if (D > 0 ){
        
        *x1 = (-b+sqrt(D))/(2*a);
        *x2 = (-b-sqrt(D))/(2*a);
        result = two_sol;
    }else if(D == 0){
        
        *x1 = -b/(2*a);
        *x2 = *x1;
        result = one_sol;
    } else{
        result = no_sol;
    }
    for(int i = 0; i < 3; i++){
        arr[i] = 0; 
    }
    return result;
}