#ifndef __GRADES_
#define __GRADES_

#define MAX_STUDENTS 50

/*
    handles all the input logic for parsing student grades

    [OUT] int *grades   | array of grades with the size of MAX_STUDENTS

    returns the number of students
*/
int InputGrades(int *grades);

/*
    calculates the average grade

    [IN] int *grades    | array of grades with valid data of size [n]
    [IN] int n          | number of students

    returns the calculated average grade
*/
float CalculateAverage(int *grades, int n);

/*
    displays students that reached an above average grade

    [IN] int *grades    | array of grades with valid data of size [n]
    [IN] int n          | number of students
    [IN] float average  | average grade
*/
void DisplayAboveAverage(int *grades, int n, float average);

#endif
