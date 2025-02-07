#include <stdio.h>
#include <stdlib.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int last, stuckCounter = 0;
    
    while (studentsSize > 0 && sandwichesSize > 0) {

        if(students[0] == sandwiches[0]){
            memmove(students, students + 1, (studentsSize - 1) * sizeof(int));
            memmove(sandwiches, sandwiches + 1, (sandwichesSize - 1) * sizeof(int));
            sandwichesSize--;
            studentsSize--;
            stuckCounter = 0;
        }
        else {
            last = *students;
            memmove(students, students + 1, (studentsSize - 1) * sizeof(int));
            students[studentsSize - 1] = last;
            stuckCounter++;
            if (stuckCounter == studentsSize)
                return studentsSize;
        }
    }

    return studentsSize;
}

int main() {
    int* students = malloc(sizeof(int) * 100);
    int* sandwiches = malloc(sizeof(int) * 100);
    int studentsSize = 0, sandwichesSize = 0;

    printf("Type the student's: ");
    while(1) {
        scanf("%d", &students[studentsSize]);
        if (students[studentsSize] != 0 && students[studentsSize] != 1) break;
        studentsSize++;
    }

    printf("Now, type the student's orders: ");
    while(1) {
        scanf("%d", &sandwiches[sandwichesSize]);
        if (sandwiches[sandwichesSize] != 0 && sandwiches[sandwichesSize] != 1) break;
        sandwichesSize++;
    }

    if(studentsSize == sandwichesSize) {
        studentsSize = countStudents(students, studentsSize, sandwiches, sandwichesSize);
        printf("Number of students who couldn't eat: %d\n", studentsSize);
    }

    free(students);
    free(sandwiches);

    return 0;
}