#include <stdio.h>
#include <ctype.h>

#include "grades.h"

#define CHECK_RANGE(val, min, max) (val >= min && val <= max)

/*
    parse an integer left-to-right directly from stdin using Horner's method

    [OUT] int *i  | the parsed integer

    returns 1 on success and 0 on failure

    !!! THIS FUNCTION IS NOT EXPOSED IN THE GRADES HEADER FILE !!!
*/
int GetInteger(int *i)
{
    int c, value = 0;
    int read = 0;   // number of bytes read
    int status = 1; // exit code

    while ((c = getchar()) != '\n')
    {
        if (!isdigit(c))
        {
            status = 0;
        }

        value = value * 10 + (c - '0');
        read++;
    }

    if (!read)
    {
        status = 0;
    }

    *i = value;
    return status;
}

int InputGrades(int *grades)
{
    int n, grade, result;

    // parse the number of students
    while (1)
    {
        printf("Enter the number of students (max %d): ", MAX_STUDENTS);
        result = GetInteger(&n);

        if (result && CHECK_RANGE(n, 1, MAX_STUDENTS))
        {
            break;
        }

        printf("Error: the number of students must be an integer between 1 and %d inclusive\n", MAX_STUDENTS);
    }

    // parse the grade for each student
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            printf("Enter grade for student %d: ", i + 1);
            result = GetInteger(&grade);

            if (result && CHECK_RANGE(grade, 0, 100))
            {
                break;
            }

            printf("Error: the grade must be an integer between 0 and 100 inclusive\n");
        }

        grades[i] = grade;
    }

    return n;
}

float CalculateAverage(int *grades, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += grades[i];
    }

    return sum / (float)n;
}

void DisplayAboveAverage(int *grades, int n, float average)
{
    printf("Students above average:\n");

    for (int i = 0; i < n; i++)
    {
        if (grades[i] > average)
        {
            printf("- Student %d: %d\n", i + 1, grades[i]);
        }
    }
}
