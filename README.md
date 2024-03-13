# Student-Grade-Analyzer
C Programming Task

![Buhler Group logo](buhler.png)

### About
This repository hosts a project designed as part of the selection process for Bühler Prague. The core functionality of this project is to process student grades, calculate their average and list the students that performed above the average. It aims to showcase programming practices and the ability to work with the C programming language.

### Building
The only user side dependency of this project is a compiler. Using gcc (MinGW) you will be able to successfully compile this project on Windows and POSIX systems.  
To build the project simply run ```make``` in the root directory. Two directories will be created, ```obj``` containing intermediate object files and ```bin``` containing the binary executable.

### Usage
Simply run the binary executable in a shell and follow the prompts. The complete output of the program might look like this:

```
Enter the number of students (max 50): 6
Enter grade for student 1: 74
Enter grade for student 2: 92
Enter grade for student 3: 65
Enter grade for student 4: 88
Enter grade for student 5: 76
Enter grade for student 6: 81

Average grade: 79.33

Students above average:
- Student 2: 92
- Student 4: 88
- Student 6: 81
```