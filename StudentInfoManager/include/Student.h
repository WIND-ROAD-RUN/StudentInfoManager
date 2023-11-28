#ifndef STUDENT_H_
#define STUDENT_H_

#include"Indenty.h"
#include"Course.h"
#include<vector>

const int BOY = true;
const int GIRL = false;


class Student
    :public Indenty {
private:
    std::vector<Course> m_CourseList;
    bool m_sex{ 1 };
public:
    bool getSex() const{ return m_sex; }
    void setSex(bool sex) { m_sex = sex; }
    
    void clearCourse() { m_CourseList.clear(); }
    std::vector<Course> getCourseList() const { return m_CourseList; }
    void addCourse(const Course& course) { m_CourseList.push_back(course); }
    bool setCourse(const std::string & id,const Course& course);
    bool deleteCourse(const std::string & id);
};




#endif // !STUDENT_H_
