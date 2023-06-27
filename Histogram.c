#include<stdio.h>
void main()
{
    int i,n,temp,j, count,freq[20];
    printf("Enter n number required: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the data: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    printf("Sorted list is: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

    printf("\nFrequency in numbers: ");
    for(i=0; i<n; i++)
    {
        count=0;
        for(j=0; j<n; j++)
        {
            if(a[i]==a[j])
            {
                count++;
                freq[j]=0;
            }
        }
        if(a[i]!=0)
        {
            freq[i]=count;
        }
    }
    for(i=0; i<n; i++)
    {
        if(freq[i]!=0)
            printf("%d ",freq[i]);
    }

    printf("\nAsterix form: ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<freq[i]; j++)
        {
            printf("*");
        }
        printf(" ");
    }
}