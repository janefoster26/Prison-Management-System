#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int prisonID;
    char name[100];
    int age;
    char nationality[100];
    char criminaloffence[100];
    char sentence[100];
    struct node *next;
};
//various function prototypes
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
struct node *insertval(struct node *,struct node *);

int main() {
    FILE *fp;
    struct node *n;
    char ch[100],pass[50];
    n = (struct node*)malloc(sizeof(struct node));
A:  printf("\nEnter password: ");
    scanf("%s",&pass);
 if(strcmp(pass,"jailer")==0)
 {
    fp=fopen("prisoner.txt","r");
    if(fp!=NULL)
    {
        printf("Records opened\n");
        while(fscanf(fp,"%d %s %d %s %s %s",&n->prisonID,n->name,&n->age,n->nationality,n->criminaloffence,n->sentence)!=EOF)
        {
            start =insertval(start,n);//insertval copies value from temporary node to the linked list and returns the start of that list.
        }
        fclose(fp);

    }
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Enter details of various criminals");
        printf("\n 2: Display the entire list");
        printf("\n 3: Add the data of only one criminal in the database");
        printf("\n 4: Delete the record of a particular criminal");
        printf("\n 5: Delete the entire database");
        printf("\n 6: Sort the criminals according to their age");
        printf("\n 7: EXIT");
        printf("\n\n Enter your option :");
        scanf("%d", &option);
        switch(option)// case menu to offer user choice of operation of this program.
        {
            case 1: start = create_ll(start);
                    printf("\n LINKED LIST CREATED");
                    break;
            case 2: start = display(start);
                    break;
            case 3: start = insert_end(start);
                    break;
            case 4: start = delete_node(start);
                    break;
            case 5: start = delete_list(start);
                    printf("\n LINKED LIST DELETED");
                    break;
            case 6: start = sort_list(start);
                    break;
            case 7: break;
        }
    }
    while(option !=7);
    if(option==7)
    {
        FILE *ffp;
        ffp=fopen("prisoner.txt","w");
        struct node *curr;
        curr = start;
        while(curr != NULL)//current pointer used print data from linked list into the file.
        {
             fprintf(ffp,"\t %d %s %d %s %s %s", curr->prisonID,curr->name,curr->age,curr->nationality,curr->sentence,curr->criminaloffence);
             curr = curr -> next;
        }
        system("cls");
        printf("\n\t\tRecords updated!");
        fclose(ffp);
    }
 }
 else
 {
     printf("\nPassword Incorrect");
     goto A;
 }
getch();
return 0;
}

// A code to take data entry from the user as long as s/he wishes.
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int n;
    printf("\n Enter -1 to end otherwise 0: ");
    scanf("%d",&n);
    while(n!=-1)
    {

        struct node *new_node;
        new_node = (struct node*)malloc(sizeof(struct node));
        system("cls");
        printf("\n Enter the prisonID :");
        scanf("%d", &new_node->prisonID);
        fflush(stdin);
        printf("\nEnter name: ");
        gets(new_node->name);
        fflush(stdin);
        printf("\nAge: ");
        scanf("%d",&new_node->age);
        fflush(stdin);
        printf("\nNationality: ");
        gets(new_node->nationality);
        fflush(stdin);
        printf("\nSentence: ");
        gets(new_node->sentence);
        fflush(stdin);
        printf("\nCriminal Offense: \n");
        gets(new_node->criminaloffence);
        fflush(stdin);
        if(start==NULL)
        {
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
            ptr->next = new_node;
            new_node->next=NULL;
        }
         system("cls");
         printf("\n Enter -1 to end:");
         scanf("%d",&n);

    }
return start;
}

//This will display the list on the screen
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    system("cls");
    while(ptr != NULL)
    {
        printf("\tPrison ID:%d\n\tName: %s\n\tAge: %d\n\tNationality:  %s\n\tSentence: %s\n\tCriminalOffense: %s \n", ptr -> prisonID,ptr->name,ptr->age,ptr->nationality,ptr->sentence,ptr->criminaloffence);
        ptr = ptr -> next;
        printf("\n");
    }
return start;
}

//A simple function to enter values into the linked list in the end.
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    system("cls");
      printf("\n Enter the prisonID :");
        scanf("%d", &new_node->prisonID);
        fflush(stdin);
        printf("\nEnter name: ");
        gets(new_node->name);
        fflush(stdin);
        printf("\nAge: ");
        scanf("%d",&new_node->age);
        fflush(stdin);
        printf("\nNationality: ");
        gets(new_node->nationality);
        fflush(stdin);
        printf("\nSentence: ");
        gets(new_node->sentence);
        fflush(stdin);
        printf("\nCriminal Offense: \n");
        gets(new_node->criminaloffence);
        fflush(stdin);

    if(start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        new_node -> next = NULL;
        ptr = start;
        while(ptr -> next != NULL)
        ptr = ptr -> next;
        ptr -> next = new_node;
    }

    return start;
}

//A function that inserts a node passed as argument into the linked list
struct node *insertval(struct node *start,struct node *n)
{
    struct node *ptr,*new_node;
    int num;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->prisonID=n->prisonID;
    strcpy(new_node->name,n->name);
    new_node->age=n->age;
    strcpy(new_node->nationality,n->nationality);//copying the data from temporary node to nod of the list.
    strcpy(new_node->sentence,n->sentence);
    strcpy(new_node->criminaloffence,n->criminaloffence);
    if(start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
    }
    else
    {
        new_node->next = NULL;
        ptr = start;
        while(ptr -> next != NULL)
        ptr = ptr -> next;
        ptr -> next = new_node;

    }
    return start;
}

//A function to delete the first entry of the database
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}

//A function to delete an individual's record
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n Enter the prisonID of the prisoner whose record has to be deleted : ");
    scanf("%d", &val);
    ptr = start;
    if(ptr -> prisonID == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while(ptr -> prisonID != val)
        {
            preptr = ptr;
            ptr = ptr -> next;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        return start;
    }
}

//Function that deletes all the records
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr != NULL)
        {
            printf("\nData of prisoner with ID %d deleted!", ptr -> prisonID);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
return start;
}

//Sorting function
struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;char set[100];
    ptr1 = start;
    while(ptr1 -> next != NULL)//selection sort of the linked list using age as a parameter.
    {
        ptr2 = ptr1 -> next;
        while(ptr2 != NULL)//comparing and swapping loop of the list in which data is swapped.
        {
            if(ptr1 -> age > ptr2 -> age)
            {
                temp = ptr1 -> age;
                ptr1 -> age = ptr2 -> age;
                ptr2 -> age = temp;
                temp=ptr1->prisonID;
                ptr1->prisonID=ptr2->prisonID;
                ptr2->prisonID=temp;
                strcpy(set,ptr1->nationality);
                strcpy(ptr1->nationality,ptr2->nationality);
                strcpy(ptr2->nationality,set);
                strcpy(set,ptr1->sentence);
                strcpy(ptr1->sentence,ptr2->sentence);
                strcpy(ptr2->sentence,set);
                strcpy(set,ptr1->criminaloffence);
                strcpy(ptr1->criminaloffence,ptr2->criminaloffence);
                strcpy(ptr2->criminaloffence,set);
                strcpy(set,ptr1->name);
                strcpy(ptr1->name,ptr2->name);
                strcpy(ptr2->name,set);
            }
            ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
return start;
}
