#include<stdio.h>

int strlenv2( char *line);
void reading_line(char *popa);

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
    for( i = 0; line[i] != 0 && line[i] != '\n' ; i ++);
    return i; 

}
void reading_line(char *popa){
    fgets(popa , sizeof(popa) , stdin );
}
