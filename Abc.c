#include<stdio.h>

int main() {
    int marks[3][3] = {{50, 60, 70}, {80, 90, 100}, {30, 40, 50}};
    char names[3][10] = {"Ali", "Bob", "Cat"};
    int student_index, subject_index, total_marks;
    float average_marks;
    
    for(student_index = 0; student_index < 3; student_index++) {
        total_marks = 0;
        for(subject_index = 0; subject_index < 3; subject_index++) {
            total_marks += marks[student_index][subject_index];
        }
        average_marks = total_marks / 3.0;
        
        if(average_marks >= 80)
            printf("%s Grade A avg=%.2f\n", names[student_index], average_marks);
        else if(average_marks >= 60)
            printf("%s Grade B avg=%.2f\n", names[student_index], average_marks);
        else if(average_marks >= 40)
            printf("%s Grade C avg=%.2f\n", names[student_index], average_marks);
        else
            printf("%s Fail avg=%.2f\n", names[student_index], average_marks);
    }
    
    int max_total = 0, topper_index = 0;
    for(student_index = 0; student_index < 3; student_index++) {
        total_marks = 0;
        for(subject_index = 0; subject_index < 3; subject_index++) {
            total_marks += marks[student_index][subject_index];
        }
        if(total_marks > max_total) {
            max_total = total_marks;
            topper_index = student_index;
        }
    }
    
    printf("Topper: %s with total %d\n", names[topper_index], max_total);
    return 0;
}