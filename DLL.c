#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count,i=0;
struct node
{
    float m1, m2, m3, avg, tot;
    char usn[10], name[20], dept[20], ph[12];
    struct node *next;
    struct node *prev;
};

typedef struct node *NODE;
NODE first=NULL;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE create_node()
{
    NODE temp;
    temp=getnode();
    printf("\nEntering Students Details %d:\n\n",i+1);
    printf("Enter USN: ");
    scanf("%s",temp->usn);
    printf("Enter name: ");
    scanf("%s",temp->name);
    printf("Enter Department: ");
    scanf("%s",temp->dept);
    printf("Enter first marks: ");
    scanf("%f",&(temp->m1));
    printf("Enter a second marks: ");
    scanf("%f",&(temp->m2));
    printf("Enter a third marks: ");
    scanf("%f",&(temp->m3));
    printf("Enter Phone Number: ");
    scanf("%s",temp->ph);
    temp->prev=NULL;
    temp->next=NULL;
    count++;
    return temp;
}

void disp_delete(NODE temp)
{
    printf("\nThe following student details are deleted: ");
    printf("Student's USN: %s\n",temp->usn);
    printf("Name: %s\n",temp->name);
    printf("Department: %s\n",temp->dept);
    printf("Marks 1: %f\n",temp->m1);
    printf("Marks 2: %f\n",temp->m2);
    printf("Marks 3: %f\n",temp->m3);
    printf("Phone Number: %s\n",temp->ph);
    count--;
}

void insert_begin()
{
    NODE temp;
    temp=create_node();
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        temp->next=first;
        first->prev=temp;
        first=temp;
    }
}

void delete_begin()
{
    NODE temp;
    if(first==NULL)
        printf("\nList is Empty!\n");
    else if(first->next==NULL)
    {
        disp_delete(first);
        free(temp);
        first=NULL;
    }
    else
    {
        temp=first;
        disp_delete(temp);
        first=first->next;
        first->prev=NULL;
        temp->next=NULL;
        free(temp);
        temp=NULL;
    }
}

void insert_rear()
{
    NODE temp,cur;
    temp=create_node();
    if(first==NULL)
    {
        first=temp;
    }
    else
    {
        cur=first;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
}

void delete_rear()
{
    NODE cur, back ;
    if(first==NULL)
    {
        printf("List is empty..!\n");  
    }
    else if(first->next==NULL)
    {
        disp_delete(first);
        free(first);
        first=NULL;
    }
    else
    {
        cur=first;
        while(cur->next!=NULL)
            cur=cur->next;
        disp_delete(cur);
        //cur->prev->next=NULL;
        back=cur->prev;
        back->next=NULL;
        free(cur);
    }
}

void display()
{
    NODE cur;
    //float avg,tot;
    if(first==NULL)
        printf("\nList is empty..!\n");
    else
    {
        cur=first;
        printf("\nThe student details in DLL:\n");
    //tot = cur->m1+cur->m2+cur->m3;
        //avg = tot/3;
           do
        {
        cur->tot = cur->m1+cur->m2+cur->m3;
        cur->avg = cur->tot/3;
        printf("Student's USN: %s\n",cur->usn);
        printf("Name: %s\n",cur->name);
        printf("Department name: %s\n",cur->dept);
        printf("Marks 1: %f\n",cur->m1);
        printf("Marks 2: %f\n",cur->m2);
        printf("Marks 3: %f\n",cur->m3);
        printf("Total Marks: %f\n",cur->tot);
        printf("Average: %f\n",cur->avg);
        printf("Phone Number: %s\n",cur->ph);
            cur = cur->next;
        } while(cur!=NULL);
        //printf("Number of nodes: %d\n",count);
    }
}

int main()
{
    int ch,i,n;
    while(1)
    {
        ch=0;
        printf("\n---------------MENU--------------\n");
        printf("\n1. Create a DLL (N nodes) using end Insertion\n2. Display status & count of nodes\n3. Insertion at rear\n4. Deletion at rear\n5. Insertion at front\n6. Delete at front\n7. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter no of students: ");
                    scanf("%d",&n);
                    for(i=0;i<n;i++) 
                        insert_rear();
                    break;
            case 2: display();      break;
            case 3: insert_rear();  break;
            case 4: delete_rear();  break;
            case 5: insert_begin(); break;
            case 6: delete_begin(); break;
            case 7: return 0;
            default:   
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
   
}
