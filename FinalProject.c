/*
-------------------------------------------------------------------------------------
PROGRAM INFO:
Program: FinalProject.c
Date: 23/04/2020
Autor: Felipe SG
-------------------------------------------------------------------------------------
Change-log
-------------------------------------------------------------------------------------
|       Date        |   Programmer   |                   Changelog                   | 
    Apr-23-2020         Felipe SG                   First Version  1.0         

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 10

struct person 
{
    char FirstName [150];
    char LastName [150];
    float Salary;
	struct person* next;
};
struct person *start, *current, *last;
struct person * loadLinkedLists();
void DataLinkedLists(struct person *current);
struct person *move;
int Counter = 0, count = 0;

struct person s[size];

//Data to be inserted
char nameF[10][250] = {"Felipe", "Tiago", "Fran", "Rejane", "Flock", "Tris", "Jane", "John", "Marco", "Opera", };
char sunF[10][250] = {"Gil", "Trooper", "Ciconetto", "Gill", "Gone", "Something", "Mary", "Smith", "Polo", "Browser"};
float wage[10] = {100.00,150.00,800.00,50.00,65.00,600.00,980.00,440.00,120.00,875.00};

int main ()
{
    system("clear");
    menu();
}

// Menus 
menu()
{
    int option;
    system("clear");
    printf("\nWelcome to my last test\n");
    printf("\nSTUDENT: Felipe Souza Gil\n");
    printf("\n-----------------------\n");
    printf("\nMENU\n");
    printf("\n[1] Use LINKED LISTS to Load data\n");
    printf("\n[2] Use POINTERS to Load data\n");
    printf("\n[3] Quit!\n");
    scanf("%d", &option);


    switch (option)
    {
        case 1:
        loadLinkedLists();
        break;

        case 2:
        fill_the_array();
        break;

        case 3:
        system("clear");
        puts("\nThank you! Have a great day\n");
        puts("\nExiting...\n");
        exit(0);
        break;

        default:
        break;
    }
}
menuLinkedList()
{
    int option;
    puts("\nMENU\n");
    puts("\n USING LINKED LISTS\n");
    puts("\n[1] Display the highest value");
    puts("\n[2] Display all values");
    puts("\n[3] Go back to main menu");
    scanf("%d", &option);
    
    switch (option)
    {
        case 1:
        system("clear");
        DisHiValueLL();
        break;

        case 2:
        system("clear");
        DisplayLinkedList();
        break;

        case 3:
        system("clear");
        menu();
        break;

        default:
        break;

    }
}
menuPointers()
{
    int option;
    puts("\nMENU\n");
    puts("\n USING POINTERS\n");
    puts("\n[1] Display the highest value");
    puts("\n[2] Display all values");
    puts("\n[3] Go back to main menu");
    scanf("%d", &option);
    
    switch (option)
    {
        case 1:
        DisHiValueARR();
        break;

        case 2:
        PrintArray();
        break;

        case 3:
        system("clear");
        menu();
        break;

        default:
        break;

    }
}

// Using Linked Lists to fill the array
struct person *loadLinkedLists()
{
    int ch;
    system("clear");
    int limit= 0;
    int iss = 0;

    while (iss < 10)
    {
        if (count == 0)
        {
            
            //set up first node. assign start
            current = (struct person *)malloc(sizeof(struct person));
            if (current == NULL)
            {
                puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                exit(1);
            }
            start = current;
            DataLinkedLists(current);
            count++;
            Counter++;
            current->next = 0;
            last = current;
        }
        else
        {
            //set up next node. link to last node
            current = (struct person *)malloc(sizeof(struct person));
            if (current == NULL)
            {
                puts("MEMORY ALLOCATION ERROR. Node1. Exiting...");
                exit(1);
            }
            DataLinkedLists(current);
            current->next = 0;
            last->next = current;
            last = current;
            count++;
            Counter++;
                     
        }
        iss++;
    }    
    
    count = 0;
    menuLinkedList();
}
void DataLinkedLists(struct person *current)
{
    //Name reading and saving
    if (Counter == 0)
    {   
        strcpy(current->FirstName, nameF[Counter]); 
    }
    else
    {   
        strcpy(current->FirstName, nameF[Counter]); 
    }
    //Last Name reading and saving  
    if (Counter == 0)
    {   
        strcpy(current->LastName, sunF[Counter]); 
    }
    else
    {
        strcpy(current->LastName, sunF[Counter]); 
    }

    //Wage reading and saving
    if (Counter == 0)
    {   
        current->Salary = wage[Counter];
    }
    else
    {
        current->Salary = wage[Counter];
    }         
}
DisplayLinkedList()
{
    //This function uses linked list to print all values
    char ch;
    move = start;
    while(move->next !=NULL)
    {
        puts("\n----------------------------------!");
        printf("First Name: %s\n", move->FirstName); 
        printf("Last Name: %s\n", move->LastName);
        printf("Salary $: %.2f\n", move->Salary); 

        move = move->next;
    }
    puts("\n----------------------------------!");
    printf("First Name: %s\n", move->FirstName); 
    printf("Last Name: %s\n", move->LastName);
    printf("Salary $: %.2f\n", move->Salary); 
    puts("\n----------------------------------!");
    
    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    system("clear");
    menuLinkedList();
}
DisHiValueLL()
{
    float tempo=0;
    char ch, name[150], lastname[150];
    move = start;
    int index;
    while(move->next !=NULL)
    {
        if (move->Salary > tempo)
        {
            system("clear");
            puts("\n----------------------------------!");
            tempo = move->Salary;
            printf("\nFirst Name: %s\n", move->FirstName ); 
            printf("\nLast Name: %s\n", move->LastName ); 
            printf("\nSalary: %.2f\n", move->Salary); 
        }
        move = move->next;
    }
    puts("\n----------------------------------!");
    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    system("clear");
    menuLinkedList();
}

// Using Pointers to fill the array 
fill_the_array()
{
    char ch;
    for (int i=0; i<10; i++)
    {
        strcpy(s[i].FirstName,nameF[i] );
        strcpy(s[i].LastName, sunF[i]);
        s[i].Salary = wage[i];
    }
    system("clear");
    menuPointers();
}
PrintArray()
{
    char ch;
    system("clear");
    for (int i=0; i<10; i++)
    {
        puts("\n----------------------------------!");
        printf("%s\n", s[i].FirstName);
        printf("%s\n", s[i].LastName);
        printf("%.2f\n", s[i].Salary);
    }
    puts("\n----------------------------------!");
    puts("\nPress any key to go back to menu!\n");
    while ( ( ch = getchar() ) != '\n' && ch != EOF ); 
    getchar();
    system("clear");
    menuPointers();
}
DisHiValueARR()
