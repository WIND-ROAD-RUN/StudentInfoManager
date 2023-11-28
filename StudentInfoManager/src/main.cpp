#include<iostream>

using namespace std;
#include"menu.h"

int main() {
    Menu menu;

    menu.setFilePath(R"(StudentDatab.xml)");
    menu.inilizaiton();
    menu.run();
   
    return 0 ;
}

