#include "StudentTableStore.h"

void StudentTableStore::setNewFile()
{
    m_doc.load_file(m_filePath.c_str());
    m_doc.append_child("StudentTableStore");
    m_doc.save_file(m_filePath.c_str());
}

void StudentTableStore::inilization()
{
    m_doc.load_file(m_filePath.c_str());
    m_studentList = getStudentList();
}

void StudentTableStore::save()
{
    saveStudentList(m_studentList);
}

bool StudentTableStore::haveStudent(const std::string& id)
{
    auto result = std::find_if(m_studentList.begin(),m_studentList.end(),
        [id](Student student) {
            return student.getId() == id;
        });
    return result == m_studentList.end() ? false : true;
}

bool StudentTableStore::haveStudent(const std::string& id, Student& student)
{
    auto result = std::find_if(m_studentList.begin(), m_studentList.end(),
        [id](Student s) {
            return s.getId() == id;
        });

    if (result ==m_studentList.end()) {
        return false;
    }
    else {
        student = *result;
        return true;
    }
}

bool StudentTableStore::addStudent(const Student& student)
{
    if (haveStudent(student.getId())) {
        return false;
    }
    else {
        m_studentList.push_back(student);
    }

}

bool StudentTableStore::deleteStudent(const std::string& id)
{
    if (haveStudent(id)) {
        auto result = std::find_if(m_studentList.begin(),m_studentList.end(),
            [id](const Student & student) {
                return id == student.getId();
            });
        m_studentList.erase(result);
    }
    else {
        return false;
    }
}

bool StudentTableStore::saveStudentList(const std::vector<Student>& studentList)
{
    auto StudentTableStoreNode = m_doc.child("StudentTableStore");
    StudentTableStoreNode.remove_children();

    for (const auto & student : studentList) {
        auto StudentNode = StudentTableStoreNode.append_child("Student");
        StudentNode.append_attribute("Id").set_value(student.getId().c_str());
        
        auto StudentNameNode = StudentNode.append_child("Name");
        StudentNameNode.text().set(student.getName().c_str());

        auto StudentSexNode = StudentNode.append_child("Sex");
        StudentSexNode.text().set(student.getSex());

        auto CourseListNode = StudentNode.append_child("CourseList");
        for (const auto & course : student.getCourseList()) {
            auto CourseNode = CourseListNode.append_child("Course");
            CourseNode.append_attribute("Id").set_value(course.getId().c_str());

            auto CourseNameNode = CourseNode.append_child("Name");
            CourseNameNode.text().set(course.getName().c_str());

            auto CourseScoreNode= CourseNode.append_child("Score");
            CourseScoreNode.text().set(course.getScore());

        }

    }

    auto result = m_doc.save_file(m_filePath.c_str());
    
    if (result) {
        return true;
    }
    else {
        return false;
    }

}

std::vector<Student> StudentTableStore::getStudentList() const
{
    std::vector<Student> result;
    auto StudentTableStoreNode = m_doc.child("StudentTableStore");
    for (const auto & studentNode: StudentTableStoreNode.children()) {
        Student student;

        std::string id;
        id = studentNode.attribute("Id").as_string();
        student.setId(id);

        auto StudentNameNode = studentNode.child("Name");
        std::string StudentName = StudentNameNode.text().as_string();
        student.setName(StudentName);

        auto StudentSexNode = studentNode.child("Sex");
        bool StudentSex = StudentSexNode.text().as_bool();
        student.setSex(StudentSex);
        for (const auto  & courseNode: studentNode.child("CourseList").children()) {
            Course course;
            course.setId(courseNode.attribute("Id").as_string());
            course.setName(courseNode.child("Name").text().as_string());
            course.setScore(courseNode.child("Score").text().as_double());
            
            student.addCourse(course);
        }

        result.push_back(student);

    }

    return result;
}
