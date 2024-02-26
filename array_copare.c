#include<stdio.h>
int main(){
    int i,j=0,a[4]={1,2,3,4};
    int b[4]={2,3,4,5};
    for(i=0;i<4;i++){
        if(a[i]==b[i])
        j++;
    }
    if(j==4){printf("Arrays are equal");}
    else printf("arrays are not equal");
}