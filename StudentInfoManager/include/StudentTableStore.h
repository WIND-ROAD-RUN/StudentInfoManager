#ifndef STUDENTTABLESTORE_H_
#define STUDENTTABLESTORE_H_

#include<pugixml.hpp>
#include<string>
#include"Student.h"

class StudentTableStore {
private:
    std::string m_filePath;
    pugi::xml_document m_doc;
    std::vector<Student> m_studentList;
private:
    bool saveStudentList(const std::vector<Student>& studentList);
    std::vector<Student>  getStudentList() const;
public:
    void setFilePath(const std::string& filePath) { m_filePath = filePath; }
    void setNewFile();
    void inilization();
    void save();
public:
    bool haveStudent(const std::string & id);
    bool haveStudent(const std::string & id , Student & student);
    bool addStudent(const Student& student);
    bool deleteStudent(const std::string& id);
    std::vector<Student> getStudentData() const { return m_studentList; }


};


#endif // !STUDENTTABLEPORTAL_H_

