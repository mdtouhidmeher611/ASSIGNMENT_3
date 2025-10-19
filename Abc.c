#include <stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 3

// Function declarations
void calculateAndDisplayGrades(int marks[][NUM_SUBJECTS], char names[][10]);
int calculateTotal(int marks[]);
char determineGrade(float average);
void displayTopper(int marks[][NUM_SUBJECTS], char names[][10]);
void displayHeader();

int main() {
    // Student data: marks for 3 subjects and names
    int marks[NUM_STUDENTS][NUM_SUBJECTS] = {
        {50, 60, 70},  // Ali's marks
        {80, 90, 100}, // Bob's marks
        {30, 40, 50}   // Cat's marks
    };
    char names[NUM_STUDENTS][10] = {"Ali", "Bob", "Cat"};
    
    displayHeader();
    calculateAndDisplayGrades(marks, names);
    printf("\n");
    displayTopper(marks, names);
    
    return 0;
}

// Calculate total marks for a student
int calculateTotal(int marks[]) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += marks[i];
    }
    return total;
}

// Determine grade based on average marks
char determineGrade(float average) {
    if (average >= 80) return 'A';
    if (average >= 60) return 'B';
    if (average >= 40) return 'C';
    return 'F';  // Fail
}

// Display header for the grade report
void displayHeader() {
    printf("========================================\n");
    printf("         STUDENT GRADE REPORT\n");
    printf("========================================\n");
    printf("Name     Total   Average  Grade\n");
    printf("-------- ------- -------- -----\n");
}

// Calculate and display grades for all students
void calculateAndDisplayGrades(int marks[][NUM_SUBJECTS], char names[][10]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int total = calculateTotal(marks[i]);
        float average = total / (float)NUM_SUBJECTS;
        char grade = determineGrade(average);
        printf("%-8s %-7d %-8.2f %c\n", names[i], total, average, grade);
    }
}

// Find and display student with highest total marks
void displayTopper(int marks[][NUM_SUBJECTS], char names[][10]) {
    int maxTotal = 0, topperIndex = 0;
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int total = calculateTotal(marks[i]);
        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = i;
        }
    }
    
    printf("----------------------------------------\n");
    printf(" TOPPER: %s\n", names[topperIndex]);
    printf(" Total Marks: %d\n", maxTotal);
    printf(" Average: %.2f\n", maxTotal / (float)NUM_SUBJECTS);
    printf("========================================\n");
}