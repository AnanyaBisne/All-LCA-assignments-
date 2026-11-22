#include <stdio.h>


int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int getFirstDayOfYear(int year) {
    int d = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 1;
    return d % 7;
}

void printCalendar(int year) {
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    int startingDay = getFirstDayOfYear(year);

    printf("\n------------------- CALENDAR - %d -------------------\n", year);

    for (int month = 0; month < 12; month++) {

        printf("\n  ------------ %s -------------\n", months[month]);
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");


        int dayOfWeek;
        for (dayOfWeek = 0; dayOfWeek < startingDay; dayOfWeek++) {
            printf("     ");
        }


        for (int day = 1; day <= daysInMonth[month]; day++) {
            printf("%5d", day);


            if (++dayOfWeek > 6) {
                printf("\n");
                dayOfWeek = 0;
            }
        }


        if (dayOfWeek != 0) {
            printf("\n");
        }


        startingDay = dayOfWeek;
    }
}

int main() {
    int year;

    printf("Enter a year: ");
    if (scanf("%d", &year) != 1 || year < 1) {
        printf("Invalid input. Please enter a valid positive year.\n");
        return 1;
    }

    printCalendar(year);

    return 0;
}
