#include <stdio.h> 

int dayNumber(int day, int month, int year) { 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
    year -= month < 3; 
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7; 
} 

char* getMonthName(int monthNumber) { 
    char* month; 
    switch (monthNumber) { 
        case 0: month = "January"; break; 
        case 1: month = "February"; break; 
        case 2: month = "March"; break; 
        case 3: month = "April"; break; 
        case 4: month = "May"; break; 
        case 5: month = "June"; break; 
        case 6: month = "July"; break; 
        case 7: month = "August"; break; 
        case 8: month = "September"; break; 
        case 9: month = "October"; break; 
        case 10: month = "November"; break; 
        case 11: month = "December"; break; 
    } 
    return month; 
} 

// Function to return the number of days in a month 
int numberOfDays(int monthNumber, int year) { 
    if (monthNumber == 0) return 31; // January 
    if (monthNumber == 1) { 
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) 
            return 29; // February (leap year) 
        else 
            return 28; 
    } 
    if (monthNumber == 2) return 31; // March 
    if (monthNumber == 3) return 30; // April 
    if (monthNumber == 4) return 31; // May 
    if (monthNumber == 5) return 30; // June 
    if (monthNumber == 6) return 31; // July 
    if (monthNumber == 7) return 31; // August 
    if (monthNumber == 8) return 30; // September 
    if (monthNumber == 9) return 31; // October 
    if (monthNumber == 10) return 30; // November 
    if (monthNumber == 11) return 31; // December 
} 

void printCalendar(int year) { 
    printf("\t\tCalendar - %d\n\n", year); 
    int days; 
    int current = dayNumber(1, 1, year); 

    for (int i = 0; i < 12; i++) { 
        days = numberOfDays(i, year); 
        printf("\n ------------%s-------------\n", getMonthName(i)); 
        printf(" Sun Mon Tue Wed Thu Fri Sat\n"); 

        for (int k = 0; k < current; k++) 
            printf("    "); 

        for (int j = 1; j <= days; j++) { 
            printf("%4d", j); 

            if (++current > 6) { 
                current = 0; 
                printf("\n"); 
            } 
        } 

        if (current != 0) 
            printf("\n"); 

    } 
} 

int main() { 
    int year = 2024; 
    printCalendar(year); 
    return 0; 
}
