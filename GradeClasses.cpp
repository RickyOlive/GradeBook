#include "GradeClasses.h"
#include <array>
#include <iostream>
#include <cmath>


// Student Method Definitions
// ----------------------------------------------------------------------------


/**
 * Constructor that sets default major to
 * computer science and grade level to 10 (sophomore)
 */
Student::Student() {
    this->major = "Computer Science";
    this->gradeLevel = 10;
}

/**
 * Gathers input for full name
 */
void Student::setFullName() {

    std::cout << "Enter your full name (Ex. John Doe): ";
    std::getline(std::cin, fullName);

}

/**
 * Gathers input for major
 */
void Student::setMajor() {
    std::cout << "Enter your major (Ex. Computer Science): ";
    std::getline(std::cin, major);
}

/**
 * Gathers input for grade level
 */
void Student::setGradeLevel() {
    std::cout << "Enter grade level (Ex. '9' if you are in 9th grade"
                 " or '12' if you are in 12th grade): ";

    std::cin >> gradeLevel;
}


/**
 * Gets full name
 * @return full name
 */
std::string Student::getFullName() const{
    return fullName;
}

/**
 * Gets major
 * @return major
 */
std::string Student::getMajor() const{
    return major;
}

/**
 * Gets grade level
 * @return grade level
 */
int Student::getGradeLevel() const {
    return gradeLevel;
}
// ----------------------------------------------------------------------------


// Grade Method Definitions
// ----------------------------------------------------------------------------

/**
 * Controls the messages that show when the program quits
 * @param quitControl
 */
void Grade::quitGrading(int quitControl) {
    switch (quitControl) {
        case -1:
            std::cout << "An error occurred, please try again\n";
            exit(-1);
            break;
        case 1:
            std::cout << "Sorry you had to quit early. "
                         "Thank you for using our product!\n";
            exit(1);
            break;
        default:
            std::cout << "Thank you for using our product!\n";
            break;
    }
}

/**
 * Populates the array with grade values as well as keeping
 * track of the lowest quiz and grade
 */
void Grade::setGradeArray() {
    // Tells user which grade they are entering
    std::cout << "Quiz 1 ";

    // Holds the current lowest num
    float lowestNum = getGrade();

    float numPlacer = 0;

    // this keeps track of the quiz number that corresponds with the
    // lowest score removed
    int lowestQuizTracker = 1;

    for (int i = 0; i < gradeArray.size(); i++) {

        // Tells user which grade they are entering
        std::cout << "Quiz " << i + 2 << " ";

        // This holds the valid user input, so it can later
        // be compared to the current lowest value
        numPlacer = getGrade();

        // picks which numbers to insert into array while leaving the lowest
        // number out
        if (lowestNum > numPlacer) {
            gradeArray[i] = lowestNum;
            lowestNum = numPlacer;
            lowestQuizTracker = i + 2;
        }
        else {
            gradeArray[i] = numPlacer;
        }
    }

    setLowestGrade(lowestNum);
    setLowestQuiz(lowestQuizTracker);
}

/**
 * Sets lowest grade to the lowestGrade member
 * @param lowest grade score
 */
void Grade::setLowestGrade(int lowestNum) {
    lowestGrade = lowestNum;
}

/**
 * Sets the lowestQuiz member to the quiz that had the lowest score
 * @param lowestQuizTracker
 */
void Grade::setLowestQuiz(int lowestQuizTracker) {
    lowestQuiz = lowestQuizTracker;
}

/**
 * Sets the finalGrade member to the average score
 */
void Grade::setFinalGrade() {
    int total = 0;
    for (int i = 0; i < gradeArray.size(); i++) {
        total += gradeArray[i];
    }
    finalGrade = int(total / gradeArray.size());
}

/**
 * Sets finalLetterGrade member to the letter
 * representation of the average score
 */
void Grade::setFinalLetterGrade() {
    char letterGrade;
    // standard grade point chart
    if (finalGrade >= 90) {
        letterGrade = 'A';
    }
    else if (finalGrade >= 80 && finalGrade < 90) {
        letterGrade = 'B';
    }
    else if (finalGrade >= 70 && finalGrade < 80) {
        letterGrade = 'C';
    }
    else if (finalGrade >= 60 && finalGrade < 70) {
        letterGrade = 'D';
    }
    else {
        letterGrade = 'F';
    }

    finalLetterGrade = letterGrade;
}

/**
 * Gets grade and validates it before storing in grade array
 * @return
 */
int Grade::getGrade() {
    // instructs user to enter grade and stores it in enteredGrade
    float enteredGrade = 0.0;
    std::cout << "Enter grade: ";
    std::cin >> enteredGrade;

    // Validates input, ensures that grades will fall between 0 - 100
    if (enteredGrade < 0 || enteredGrade > 100) {
        quitGrading(-1);
    }

    // updates the var with truncated grade
    enteredGrade = std::trunc(enteredGrade);


    // determines if user wants to continue or end early
    std::string continueControl;
    std::cout << "Would you like to continue? "
                 "(if not enter 'n', otherwise enter any key): ";
    std::cin >> continueControl;

    // if the user wants to quit then 1 is passed to the quiControl func
    if (continueControl == "n" || continueControl == "N") {
        quitGrading(1);
    }

    return enteredGrade;
}

/**
 * Gets Final Grade score
 * @return
 */
int Grade::getFinalGrade() const {
    return finalGrade;
}

/**
 * Gets letter representation of final grade score
 * @return
 */
char Grade::getFinalLetterGrade() const {
    return finalLetterGrade;
}

/**
 * Gets the lowest grade score
 * @return
 */
int Grade::getLowestGrade() const {
    return lowestGrade;
}

/**
 * Gets the quiz with the lowest grade
 * @return
 */
int Grade::getLowestQuiz() const {
    return lowestQuiz;
}

// ----------------------------------------------------------------------------






