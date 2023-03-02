// Dev: Richard Olive
// COP 3003 - CRN 15050 - Programming II
// Takes the scores of 11 quizzes, drops the lowest grade, and outputs the
// average of the quiz grades.
// Sprint #3
// ----------------------------------------------------------------------------

// Directives
#include <iostream>
#include "GradeClasses.h"
// ----------------------------------------------------------------------------


int main() {

    // Declared a variable of type Staudent
    Student student;

    // Gathers the Full-Name, Grade-Level, and Major for the student and
    // assigns it to the appropriate members in class
    student.setFullName();


    // checks if default student info is correct
    std::string studentInfoCheck;
    std::cout << "Current major: " << student.getMajor() <<
    "\nCurrent Grade Level: " << student.getGradeLevel() <<
    "\n\nIs this correct? (if not enter 'n', otherwise enter any key): ";
    std::cin >> studentInfoCheck;

    // if not correct then it allows the user to update their info
    if (studentInfoCheck == "n" || studentInfoCheck == "N") {
        student.setMajor();
        std::cin.ignore(1000, '\n');
        student.setGradeLevel();
    }

    // Declaration of grade variable that inherits grade class
    Grade grade;

    // gathers the grades and stores them into array and
    // calculates the final grade and letter grade
    grade.setGradeArray();
    grade.setFinalGrade();
    grade.setFinalLetterGrade();

    // what the user sees when the loop finishes successfully
    std::cout << "\n\nGrade " << grade.getLowestQuiz() << ": " << grade.getLowestGrade()
              << "%; dropped\n";
    std::cout << student.getFullName()<<  ", your final grade is a " <<
              grade.getFinalGrade() << "%, which translates to a '"
              << grade.getFinalLetterGrade()
              << "'" << std::endl;

    grade.quitGrading(0);

    return 0;
}
