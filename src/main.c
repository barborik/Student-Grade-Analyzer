#include <stdio.h>
#include <stdlib.h>

#include "grades.h"

int main(void)
{
    float average;
    int grades[MAX_STUDENTS], n;

    n = InputGrades(grades);
    average = CalculateAverage(grades, n);
    printf("\nAverage grade: %.2f\n\n", average);
    DisplayAboveAverage(grades, n, average);

    return EXIT_SUCCESS;
}
