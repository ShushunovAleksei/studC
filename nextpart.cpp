#include<stdio.h>

int strlenv2( char *line);
void reading_line(char *popa);
void strppi(char *line1 , char *line2);
void strcapp(char *line_bfr1, char *line_bfr2, char *line_aftr);
int strcmp2(char *line1, char *line2);
int main(){
    
    char str[1000] = {};

    
    printf("введите строку символов\n");
    reading_line(str);
    int count;
    count = strlenv2( str);
    printf("%d\n", count);
}

int strlenv2( char *line){
    int i ;
    for( i = 0; line[i] != '\0' && line[i] != '\n' ; i ++);
    return i; 

}
void reading_line(char *popa){
    fgets(popa , sizeof(popa) , stdin );
}

void strppi(char *line1, char *line2){
    int i, j ;
    i = 0;
    j = 0;
    while(line1[i] != '\0' && line1[i] != '\n'){
        line2[j] = line1[i];
        i ++;
        j ++;    
    }
    line2[j] = '\0' ;
}
void strcapp(char *line_bfr1, char *line_bfr2, char *line_aftr){
    int i, j, k;
    j = k = 0;
    for( i = 0; line_bfr1[i] != '\0'  && line_bfr1[i] != '\n'; i++, j++){
        line_aftr[j] = line_bfr1[i] ;
    }
    while(line_bfr2[k] != '\0' && line_bfr2[k] != '\n'){
        line_aftr[j] = line_bfr2[k]; 
        k++ ;
        j++ ;
    }
    line_aftr[j] = '\0' ;
}

int strcmp2(char *line1, char *line2){
    int i, j;
    i = 0;
    j = 0;
    while(line1[i] == line2[j] && line1[i] != '\0' && line2[j] != '\0'){
        i++;
        j++;
    }
    int result = 0;
    result = line1[i] - line2[j] ;
    if(result > 0){
        printf("первая строка больше второй\n");
        return 1;
    }else if(result < 0){
        printf("вторая строка больше первой\n");
        return -1;
    }else {
    printf("строки равны\n");
    return 0;
    }
}