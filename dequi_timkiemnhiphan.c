#include<stdio.h>

int search(int *a, int n1, int n, int k)
{
    if(k<a[0] || k>a[n-1])
        return 0;
    int m = (n1+n)/2;
    if(k == a[m-1])
        return m;
    if(k < a[m])
        return search(a,0,m,k);
    return search(a,m+1,n,k);
}

int main()
{
    int a[] = {10,11,12,13,14,15,16,17,18,19};
    int n = sizeof(a)/sizeof(int);
    int k;
    printf("Nhap k: ");
    scanf("%d",&k);
    int m = search(a,0,n,k);
    if(m == 0)
        printf("\nKo tim thay k");
    else
        printf("Tim thay k o vi tri thu: %d",m);

    printf("\n-----------------------\n");
    return 0;
}
