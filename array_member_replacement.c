#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5},i;
    for(i=0;i<5;i+=2){
        a[i]=0;
    }
    for(i=0;i<5;i++){
        printf("%d",a[i]);
    }
}