#ifndef COURSE_H_
#define COURSE_H_

#include"Indenty.h"

class Course
    :public Indenty {
private:
    double m_score;

public:
    void setScore(double score) { m_score = score; }
    double  getScore() const { return m_score; }
};



#endif // !COURSE_H_
