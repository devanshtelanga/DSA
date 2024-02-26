#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5},n,i;
    scanf("%d",&n);
    for(i=0;i<5;i++)
    {
        if(a[i]==n)
        printf("%d",i+1);
    }
}