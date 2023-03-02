#ifndef GRADECAL_GRADECLASSES_H
#define GRADECAL_GRADECLASSES_H


// Directives
#include <string>
#include <array>
// ----------------------------------------------------------------------------


// Student Class
class Student {

private:
    std::string fullName;
    int gradeLevel;
    std::string major;

public:
    Student();
    void setFullName();
    void setMajor();
    void setGradeLevel();
    std::string getFullName() const;
    std::string getMajor() const;
    int getGradeLevel() const;
};
// ----------------------------------------------------------------------------


// Grade Class
class Grade {

private:
    std::array<int, 10> gradeArray;
    int lowestGrade;
    int lowestQuiz;
    int finalGrade;
    char finalLetterGrade;

public:
    static void quitGrading (int);
    void setGradeArray();
    void setLowestGrade(int);
    void setLowestQuiz (int);
    void setFinalGrade();
    void setFinalLetterGrade();
    static int getGrade();
    int getFinalGrade () const;
    char getFinalLetterGrade() const;
    int getLowestGrade() const;
    int getLowestQuiz() const;
};
// ----------------------------------------------------------------------------


#endif //GRADECAL_GRADECLASSES_H
