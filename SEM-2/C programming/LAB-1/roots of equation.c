#include <stdio.h>
int main()
{
    int d,k,n,i,j,small,temp;
    scanf("%d",&n);
    int a[n];
    for (k=1;k<=n;k++){
        scanf("%d",&a[k]);
    }
    for (i=1;i<=n;i++) {
        small=i;
        for(j=i+1;j<=n;j++) {
            if (a[j]<a[small]) {
            small=j; }
        temp=a[i];
        a[i]=a[small];
        a[small]=temp;
        }
    }
    scanf("%d",&d);
    printf("%d",a[d]);
return 0;
}
