#include<iostream>

using namespace std;
#include"menu.h"

Student test1();

int main() {
    Menu menu;

    menu.setFilePath(R"(G:\project\code_place\vs_code_place\StudentManager\StudentInfoManager\StudentInfoManager\StudentDatab.xml)");
    menu.inilizaiton();
    menu.run();
   
    return 0 ;
}

Student test1()
{
    Student a;
    a.setId("1");
    a.setName("LiZhen");
    a.setSex(BOY);

    Course math;
    math.setId("00001");
    math.setName("Math");
    math.setScore(89);

    a.addCourse(math);

    Course english;
    english.setId("00002");
    english.setName("English");
    english.setScore(89);

    a.addCourse(english);

    Course Chinese;
    Chinese.setId("00003");
    Chinese.setName("Chinese");
    Chinese.setScore(89);

    a.addCourse(Chinese);

    return a;
}
