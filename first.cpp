#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#define MAX 100 

int opening();
void coeff_a(double *arr, int index);
void coeff_b(double *brr, int index);
void coeff_c(double *crr, int index);
void solution(double *arr, double *brr, double *crr, int index);

int main() 
{
    int s = 1;
    int p = 0;
    int count = 0;
    double arr[MAX];
    double brr[MAX];
    double crr[MAX];
    bool want = true ;

    while(want){
        s = opening();
        if(s == 1){
        printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + c = 0\n");
        coeff_a(arr, count);
        coeff_b(brr, count);
        coeff_c(crr, count);
        solution(arr, brr, crr, count);
        count++ ;
        }else{
            want = false ;
        }
    }
}

int opening()
{
    char choice = 0;
    printf("хотите решить квадратное уравнение? (y/n)\n");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y'){
        return 1;
    } else {
        return 0;
    }
}

void coeff_a(double *arr, int index){
    printf("напишите значение коэффицента перед х^2\n");
    scanf("%lf", &arr[index]);
}

void coeff_b(double *brr, int index){
    printf("напишите значение коэффицента перед х\n");
    scanf("%lf", &brr[index]);
}

void coeff_c(double *crr, int index){
    printf("напишите значение свободного коэффицента \n");
    scanf("%lf", &crr[index]);
}

void solution(double *arr, double *brr, double *crr, int index){
    double a = arr[index];
    double b = brr[index];
    double c = crr[index];
    double D = b*b - 4*a*c;
    if (D > 0 ){
        printf("корни уравнения: %lf %lf\n", (-b+sqrt(D)/(2*a)), (-b-sqrt(D)/(2*a)));
    }else if(D == 0){
        printf("корень уравнения: %lf\n", -b/(2*a));
    } else{
        printf("нет корней\n");
    }
}