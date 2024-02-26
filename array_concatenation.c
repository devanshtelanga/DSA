#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5},b[5]={6,7,8,9,10},i,j,k[10];
    for(i=0;i<5;i++){
        k[i]=a[i];
    }
    for(i=5,j=0;i<10&&j<5;i++,j++){
     k[i]=b[j];
    } for(i=0;i<10;i++){
        printf("%d",k[i]);
    }}