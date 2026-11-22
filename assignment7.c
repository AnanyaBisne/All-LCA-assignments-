#include <stdio.h>
struct Student {
    int roll_no;
    char name[50];
    int marks[3];
    int total;
    float percentage;
};

int main() {
    int n, i, j;


    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of students.\n");
        return 1;
    }

    struct Student s[n];


    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);


        printf("Roll Number: ");
        scanf("%d", &s[i].roll_no);


        printf("Name: ");
        scanf(" %[^\n]s", s[i].name);

        s[i].total = 0;


        printf("Enter marks for 3 subjects:\n");
        for (j = 0; j < 3; j++) {
            printf(" Subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }


        s[i].percentage = (float)s[i].total / 3.0;
    }


    printf("\n================================================================================\n");
    printf("%-10s %-20s %-10s %-10s %-10s %-10s %-10s\n",
           "Roll No", "Name", "Sub 1", "Sub 2", "Sub 3", "Total", "Percentage");
    printf("================================================================================\n");

    for (i = 0; i < n; i++) {
        printf("%-10d %-20s %-10d %-10d %-10d %-10d %-10.2f%%\n",
               s[i].roll_no,
               s[i].name,
               s[i].marks[0],
               s[i].marks[1],
               s[i].marks[2],
               s[i].total,
               s[i].percentage);
    }
    printf("================================================================================\n");

    return 0;
}
