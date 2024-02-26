//Program 1
#include<stdio.h>
int main (){
    int a;
    char c;
    int *ptrin=&a;
    char *ptrchr=&c;
    printf("Address of char = %d\n",ptrchr);
    printf("Adress of int = %d",ptrin);
}