#include <stdio.h>
void main()
{
    int n,temp=0,i,j,num[30];
    printf("Enter no of inputs: ");
    scanf("%d",&n);
    printf("Enter number between 0-100: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
    }
    printf("Sorted List:\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(num[i]>=0 && num[i]<20)
        {
            printf("Group 1:\n");
            //for(i=0; i<n; i++)
                printf("%d\n",num[i]);
        }
        else if(num[i]>=20 && num[i]<40)
        {
            printf("Group 2:\n");
            //for(i=0; i<n; i++)
                printf("%d\n",num[i]);
        }
        else if(num[i]>=40 && num[i]<60)
        {
            printf("Group 3:\n");
            //for(i=0; i<n; i++)
                printf("%d\n",num[i]);
        }
        else if(num[i]>=60 && num[i]<80)
        {
            printf("Group 4:\n");
            //for(i=0; i<n; i++)
                printf("%d\n",num[i]);
        }
        else if(num[i]>=80 && num[i]<100)
        {
            printf("Group 5:\n");
            //for(i=0; i<n; i++)
                printf("%d\n",num[i]);
        }
        else
            printf("\nInvalid Number!");
    }
    //return 0;
}