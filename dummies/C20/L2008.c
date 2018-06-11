#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct typical {
    int value;
    struct typical *next;
};

struct typical *first;
struct typical *current;
struct typical *new;

int menu(void);
void add(void);
void show(void);
void delete(void);
struct typical *create(void);

int main()
{
    int choice='\0';
    first=NULL;

    while(choice!='Q')
    {
        choice=menu();
        switch (choice)
        {
            case 'S':
                show();
                break;
            case 'A':
                add();
                break;
            case 'R':
                delete();
                break;
            case 'Q':
                break;
            default:
                break;
        }
    }
    return(0);
}

int menu(void)
{
    int ch;
    printf("S)how, A)dd, R)emove, Q)uit: ");
    ch=getchar();
    while(getchar()!='\n');

    return(toupper(ch));
}

void add(void)
{
    if(first==NULL)
    {
        first=create();
        current=first;
    }
    else
    {
        current=first;
        while(current->next)
            current=current->next;
        new=create();
        current->next=new;
        current=new;
    }
    printf("Type a value: ");
    scanf("%d",&current->value);
    current->next=NULL;
    while(getchar()!='\n');
}

void show(void)
{
    int count=1;
    if(first==NULL)
    {
        puts("Nothing to show");
        return;
    }
    puts("Showing all records:");
    current=first;
    while(current)
    {
        printf("Record %d: %d\n",count,current->value);
        current=current->next;
        count++;
    }
}

void delete(void)
{
    struct typical *previous;
    int r,c;

    if(first==NULL)
    {
        puts("No records to remove");
        return;
    }
    puts("Choose a record to remove:");
    show();
    printf("Record: ");
    scanf("%d",&r);
    while(getchar()!='\n');

    c=1;
    current=first;
    previous=NULL;
    while(c!=r)
    {
        if(current==NULL)
        {
            puts("Record not found");
            return;
        }
        previous=current;
        current=current->next;
        c++;
    }
    if(previous==NULL)
        first=current->next;
    else
        previous->next=current->next;
    printf("Record %d removed.\n",r);
    free(current);
}

struct typical *create(void)
{
    struct typical *a;
    if(a==NULL)
    {
        puts("Some kind of malloc() error");
        exit(1);
    }
    return(a);
}
