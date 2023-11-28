#ifndef MENU_H_
#define MENU_H_

#pragma warning(disable:4996)

#include"StudentTableStore.h"
#include"Student.h"
#include"Course.h"
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>

class Menu {
private:
    std::string m_filePath;
    StudentTableStore m_store;
private:
    void setConsole();
    void show_menu_first();
    int get_number();
private:
    void show_studentInfo();
    void show_studentTableHead();
    void show_studentTableTail();

    void show_Course(const std::vector<Course> & courseList);

    void show_courseTableHead();
    void show_courseTableTail(const std::vector <Course>& courseList);
private:
    void show_operate_studentData();
    void show_operate_menu();
    void add_student();
    double get_double();
    void delete_student();

public:
    void setFilePath(const std::string& filePath) { m_filePath = filePath; }
    void inilizaiton() { m_store.setFilePath(m_filePath); m_store.inilization(); setConsole();}

public:
    void run();




};


#endif // !MENU_H_
