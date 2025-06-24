#include <iostream>
#include <iomanip>
using namespace std;

// Print star-based header
void printHeader() {
    cout << "\n*************************************************\n";
    cout << "         CGPA CALCULATOR FOR CODE ALPHA BY KARTIK         \n";
    cout << "***************************************************\n";
}

// Print star-based footer
void printFooter() {
    cout << "***************************************************\n";
}

// Main CGPA calculator function
void calculateCGPA() {
    int numSemesters;
    cout << "\nEnter number of semesters: ";
    cin >> numSemesters;

    float totalGradePoints = 0;
    int totalCredits = 0;

    for (int sem = 1; sem <= numSemesters; ++sem) {
        int numCourses;
        cout << "\n--- Semester " << sem << " ---" << endl;
        cout << "Enter number of courses: ";
        cin >> numCourses;

        float semesterGradePoints = 0;
        int semesterCredits = 0;

        for (int course = 1; course <= numCourses; ++course) {
            float grade;
            int credits;

            cout << "\nCourse " << course << ":\n";
            cout << "Enter grade (numeric): ";
            cin >> grade;
            cout << "Enter credit hours: ";
            cin >> credits;

            float coursePoints = grade * credits;
            semesterGradePoints += coursePoints;
            semesterCredits += credits;

            cout << fixed << setprecision(2);
            cout << "=> Grade: " << grade
                 << ", Credit Hours: " << credits
                 << ", Grade Points: " << coursePoints << endl;
        }

        float semesterGPA = semesterGradePoints / semesterCredits;
        cout << "\nSemester " << sem << " GPA: "
             << fixed << setprecision(2) << semesterGPA << endl;

        totalGradePoints += semesterGradePoints;
        totalCredits += semesterCredits;
    }

    float finalCGPA = totalGradePoints / totalCredits;
    cout << "\n****************************************" << endl;
    cout << "Final CGPA after " << numSemesters << " semesters: "
         << fixed << setprecision(2) << finalCGPA << endl;
    printFooter();
}

// Main function with simple menu
int main() {
    int choice;

    while (true) {
        printHeader();
        cout << "\n1. Start CGPA Calculation\n";
        cout << "2. Exit\n";
        printFooter();

        cout << "\nEnter your choice (1 or 2): ";
        cin >> choice;

        if (choice == 1) {
            calculateCGPA();
        } else if (choice == 2) {
            cout << "\nThank you for using the CGPA Calculator. Sayonara!\n";
            break;
        } else {
            cout << "\nInvalid choice. Please enter 1 or 2.\n";
        }
    }

    return 0;
}
