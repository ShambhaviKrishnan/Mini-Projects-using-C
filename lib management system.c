//Program to display YCCE Library Management System by P-15: Shambhavi Krishnan

#include<stdio.h>
#include<string.h>

// Maximum number of books in the library
#define MAXIM_BOOKS 10

// Arrays to store book information
char titles[MAXIM_BOOKS][100];
char authors[MAXIM_BOOKS][50];
int years[MAXIM_BOOKS];

int numBooks = 0;

// Function prototypes
void addBook();
void displayLibrary();
// Function to display the library contents
void displayLibrary()
{
printf("\nLibrary Contents :\n");
for (int i = 0; i < numBooks; i++)
{
printf("Title: %s, Author: %s, Year: %d\n",titles[i], authors[i], years[i]);
}
}

int main()
{
// User interaction interface

int choice;
printf("Program to display YCCE Library Management System by P-15: Shambhavi Krishnan");
printf("\n-------------------------------------------------------------------------------");

do
{
printf("\nYCCE Library Management System:\n");
printf("1. Add a book\n");
printf("2. Display the library\n");
printf("3. Exit\n");

printf("Please enter your choice below (1-3): ");
scanf("%d", &choice);

switch (choice)
{
case 1:
if (numBooks < MAXIM_BOOKS)
{
printf("Enter the book title: ");
scanf("%s", titles[numBooks]);

printf("Enter the book author: ");
scanf("%s", authors[numBooks]);

printf("Enter the publication year: ");
scanf("%d", &years[numBooks]);

numBooks++;
printf("Book added to the library successfully.\n");
} else

{
printf("Cannot add more books. Maximum limit reached.\n");
}
break;
case 2:
if (numBooks > 0)
{
displayLibrary();
} else
{
printf("The library is empty.\n");
}
break;
case 3:
printf("Thank you. Exiting the library management system.\n");
printf("Visit us soon!");
break;
default:
printf("Invalid choice. Please enter a number between 1 and 3.\n");
}
}
while(choice != 3);

return 0;
}