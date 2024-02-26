#include<stdio.h>
int main (){
    int a[2][2];
    int b[2][2];
    int i,j;
    int s[2][2];
     for(i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            scanf("%d",&a[i][j]);
        }}
           for(i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            scanf("%d",&b[i][j]);
        }}
    for(i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            s[i][j]=a[i][j]+b[i][j];
        }
    } 
     for(i=0;i<2;i++)
    {
        for (j=0;j<2;j++){
            printf("%d  ",s[i][j]);
        }}
}