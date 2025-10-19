#include<stdio.h>

#define NUM_STUDENTS 3
#define NUM_SUBJECTS 3

void calculateAndDisplayGrades(int marks[][NUM_SUBJECTS], char names[][10]);
int calculateTotalMarks(int student_marks[]);
char determineGrade(float average);
void findAndDisplayTopper(int marks[][NUM_SUBJECTS], char names[][10]);

int main() {
    int marks[NUM_STUDENTS][NUM_SUBJECTS] = {{50, 60, 70}, {80, 90, 100}, {30, 40, 50}};
    char names[NUM_STUDENTS][10] = {"Ali", "Bob", "Cat"};
    
    calculateAndDisplayGrades(marks, names);
    findAndDisplayTopper(marks, names);
    
    return 0;
}

int calculateTotalMarks(int student_marks[]) {
    int total = 0;
    for(int subject_index = 0; subject_index < NUM_SUBJECTS; subject_index++) {
        total += student_marks[subject_index];
    }
    return total;
}

char determineGrade(float average) {
    if(average >= 80) return 'A';
    else if(average >= 60) return 'B';
    else if(average >= 40) return 'C';
    else return 'F';
}

void calculateAndDisplayGrades(int marks[][NUM_SUBJECTS], char names[][10]) {
    int total_marks;
    float average_marks;
    char grade;
    
    for(int student_index = 0; student_index < NUM_STUDENTS; student_index++) {
        total_marks = calculateTotalMarks(marks[student_index]);
        average_marks = total_marks / (float)NUM_SUBJECTS;
        grade = determineGrade(average_marks);
        
        printf("%s Grade %c avg=%.2f\n", names[student_index], grade, average_marks);
    }
}

void findAndDisplayTopper(int marks[][NUM_SUBJECTS], char names[][10]) {
    int max_total = 0;
    int topper_index = 0;
    int current_total;
    
    for(int student_index = 0; student_index < NUM_STUDENTS; student_index++) {
        current_total = calculateTotalMarks(marks[student_index]);
        
        if(current_total > max_total) {
            max_total = current_total;
            topper_index = student_index;
        }
    }
    
    printf("Topper: %s with total %d\n", names[topper_index], max_total);
}