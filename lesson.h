#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <string>
enum lesson_type {LECTURE, PRACTICE, LABORATORY, EXAM};
class Lesson
{
public:
    int number;
    QString title;
    lesson_type type;
    int auditory;
    QString enum_def(int value)
    {
       switch(value)
       {
           case 0: return("Lecture");
           case 1: return("Practice");
           case 2: return("Laboratory");
           case 3: return("Exam");
       }
    }

};
#endif // LESSON_H
