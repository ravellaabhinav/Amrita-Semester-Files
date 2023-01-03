
#include<stdio.h>
#include<string.h>

int incr(int i){
    static int count = 0;
    count += i;
    return count;
}

void main(){
    int i,j,a;
    for(i=0;i<5;i++){
        j = incr(i);
        printf("%d ",j);
}