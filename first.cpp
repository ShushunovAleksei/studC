#include <stdio.h>
#include <math.h>
#include <stdbool.h>


#define MAX 3 

int opening();
void read_coeff(double *arr, int index);

void print_solution(double *arr,  int index);

int main() 
{
    
    
    int count = 0;
    double arr[MAX];
    
    bool want = true ;

    while(want){
        want = opening();
        if(want){
        printf("задайте коэффиценты квадратного уравнения вида: ax^2 + bx + c = 0\n");
        read_coeff(arr, count);
        
        print_solution(arr, count);
        
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

void read_coeff(double *arr, int index){
    printf("напишите значение коэффицента перед х^2\n");
    scanf("%lf", &arr[index]);
    printf("напишите значение коэффицента перед х\n");
    scanf("%lf", &arr[index+1]);
    printf("напишите значение свободного коэффицента \n");
    scanf("%lf", &arr[index+2]);
}



void print_solution(double *arr,  int index){
    double a = arr[index];
    double b = arr[index+1];
    double c = arr[index+2];
    double D = b*b - 4*a*c;
    if (D > 0 ){
        printf("корни уравнения: %lf %lf\n", (-b+sqrt(D)/(2*a)), (-b-sqrt(D)/(2*a)));
    }else if(D == 0){
        printf("корень уравнения: %lf\n", -b/(2*a));
    } else{
        printf("нет корней\n");
    }
    for(int i = 0; i < 3; i++){
        arr[i] = 0; 
    }
}