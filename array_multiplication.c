#include<stdio.h>
int main (){
    int a[5]={1,2,3,4,5};
    int b,s=1 ; 
    for (b=0;b<5;b++){
        s*=a[b];
    }
    printf("%d",s);
}