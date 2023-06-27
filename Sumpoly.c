#include <stdio.h>
#include <stdlib.h> 

struct node {
    float coeff; 
    int expx, expy, expz; 
    struct node* link;
};

struct node* insert(struct node* head, float co, int ex, int ey, int ez) 
{
    struct node* temp; 
    struct node* newP = malloc (sizeof(struct node)); 
    newP->coeff = co; 
    newP->expx = ex;
    newP->expy = ey;
    newP->expz = ez;
    newP->link = NULL;

    //If there is no node in the list OR given exponent is 
//than the first node exponent 
    if(head == NULL || ex > head->expx || ey > head->expy || ez > head->expz) 
    {
        newP->link = head; 
        head = newP; 
    }
    else 
    { 
        temp = head; 
        while(temp->link != NULL && temp->link->expx >= ex && temp->link->expy >= ey && temp->link->expz >= ez) 
            temp = temp->link; 
        newP->link = temp->link; 
        temp->link = newP; 
    }
    return head; 
}

struct node* create(struct node* head)
{ 
    int n, i; 
    float coeff; 
    int expx, expy, expz; 

    printf("Enter the number of terms: "); 
    scanf("%d", &n); 

    for(i=0; i<n; i++) 
    {
        printf("Enter the coefficient for term %d: ", i+1);
        scanf("%f", &coeff); 

        printf("Enter the x-exponent for term %d: ", i+1); 
        scanf("%d", &expx); 
        
        printf("Enter the y-exponent for term %d: ", i+1); 
        scanf("%d", &expy); 
        
        printf("Enter the z-exponent for term %d: ", i+1); 
        scanf("%d", &expz); 

        head = insert(head, coeff, expx, expy, expz); 
    }
    return head; 
}

void print(struct node* head)
{ 
    if(head == NULL) 
        printf("No Polynomial is present!"); 
    else {
        struct node* temp = head; 
        while(temp != NULL)
        {
            printf("(%.1fx^%dy^%dz^%d)", temp->coeff, temp->expx, temp->expy, temp->expz); 
            temp = temp->link; 
            if(temp!=NULL) 
                printf(" + "); 
            else printf("\n");
        }
    }
}

void polyAdd(struct node* head1, struct node* head2)
{ 
    struct node* ptr1 = head1; 
    struct node* ptr2 = head2; 
    struct node* head3 = NULL; 
    while(ptr1!=NULL && ptr2!=NULL)
    { 
        if(ptr1->expx == ptr2->expx && ptr1->expy == ptr2->expy && ptr1->expz == ptr2->expz)
        {
            head3 = insert(head3, ptr1->coeff+ptr2->coeff, ptr1->expx, ptr1->expy, ptr1->expz); 
            ptr1 = ptr1->link; 
            ptr2 = ptr2->link;
        } 
        else if(ptr1->expx > ptr2->expx)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expx, ptr1->expy, ptr1->expz); 
            ptr1 = ptr1->link; 
        } 
        
        else if(ptr1->expx < ptr2->expx)
        {
         head3 = insert(head3, ptr2->coeff, ptr2->expx, ptr2->expy, ptr2->expz); 
         ptr2 = ptr2->link; 
        }
    
         else if(ptr1->expy > ptr2->expy)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expx, ptr1->expy, ptr1->expz); 
            ptr1 = ptr1->link; 
        } 
        
         else if(ptr1->expy < ptr2->expy)
        {
         head3 = insert(head3, ptr2->coeff, ptr2->expx, ptr2->expy, ptr2->expz); 
         ptr2 = ptr2->link; 
        }
        
        else if(ptr1->expz > ptr2->expz)
        {
            head3 = insert(head3, ptr1->coeff, ptr1->expx, ptr1->expy, ptr1->expz); 
            ptr1 = ptr1->link; 
        } 
        
        else if(ptr1->expz < ptr2->expz)
        {
         head3 = insert(head3, ptr2->coeff, ptr2->expx, ptr2->expy, ptr2->expz); 
         ptr2 = ptr2->link; 
        }
        
    }

    while(ptr1!=NULL)
    {  
        head3 = insert(head3, ptr1->coeff, ptr1->expx, ptr1->expy, ptr1->expz); 
        ptr1 = ptr1->link; 
    }
    while(ptr2!=NULL) 
    {
        head3 = insert(head3, ptr2->coeff, ptr2->expx, ptr2->expy, ptr2->expz); 
        ptr2 = ptr2->link;
    } 
    printf("\nAdded polynomial is: "); 
    print(head3);
} 

int main() 
{
    struct node* head1 = NULL; 
    struct node* head2 = NULL; 
    printf("Enter the First polynomial\n\n "); 
    head1 = create(head1); 
    printf("Enter the second polynomial\n\n "); 
    head2 = create(head2); 

    polyAdd(head1, head2); 
    return 0; 

}
