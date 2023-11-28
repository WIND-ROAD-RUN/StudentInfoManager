#include "Student.h"
#include<algorithm>

bool Student::setCourse(const std::string& id, const Course& course)
{
    if (course.getId()!=id) {
        return false;
    }
    auto targetCourse = std::find_if(m_CourseList.begin(),m_CourseList.end(),
        [id](Course & course) {
            return id == course.getId();
        });
    if (targetCourse==m_CourseList.end()) {
        return false;
    }
    *targetCourse = course;
    return true;
}

bool Student::deleteCourse(const std::string& id)
{
    auto targetCourse = std::find_if(m_CourseList.begin(), m_CourseList.end(),
        [id](Course& course) {
            return id == course.getId();
        });
    if (targetCourse == m_CourseList.end()) {
        return false;
    }
    m_CourseList.erase(targetCourse);
    return true;
}
