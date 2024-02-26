#include<stdio.h>
int main(){
    int a[5]={1,2,3,4,5};
    int i,k,j;
    for(i=0,k=4;i<2;i++,k--)
    {
        j=a[i];
        a[i]=a[k];
        a[k]=j;
    }
    for(i=0;i<5;i++)
{
    printf("%d",a[i]);

}}