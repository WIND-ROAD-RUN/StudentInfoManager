#include "menu.h"

void Menu::run()
{
    int choice;
    system("cls");
    show_menu_first();
    while (1) {
        choice = get_number();
        switch (choice) {
        case 1:
            show_studentInfo();
            system("cls");
            show_menu_first();
            break;
        case 2:
            show_operate_studentData();
            system("cls");
            show_menu_first();
            break;
        case 0:

            m_store.save();

            printf("\n欢迎再次使用！！！\n");      //退出程序
            printf("\n三秒后自动退出程序！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        default:
            printf("请正确输入选项:");
            break;
        }
    }
}

void Menu::setBackground()
{
    system("color f0");
}

void Menu::show_menu_first()
{
    printf("************************************************************\n");
    printf("*");

    printf("            欢迎进入学生信息管理系统                      ");

    printf("*\n*");

    printf("以下是系统提供的操作：                                    ");

    printf("*\n*                                                          *\n*");

    printf("  1.显示所有学生信息                                      ");

    printf("*\n*");

    printf("  2.操作学生信息                                          ");

    printf("*");


    printf("\n*");
    printf("                                                          *\n");
    printf("*                                                          ");
    printf("*\n*");

    printf("           注意：输入相关序号进入下一操作选择（按下0退出）");

    printf("*\n*");
    printf("***********************************************************\n");

    printf("请输入你的选项：");
}

int Menu::get_number()
{
    int op;
    while (scanf("%d", &op) != 1) {
        printf("请输入数字：");
        while (getchar() != '\n')
            continue;
    }
    return op;
}

void Menu::show_studentInfo()
{
    int choice;

    system("cls");
    show_studentTableHead();
    show_studentTableTail();
    printf("\n输入学生编号以进行查看成绩信息,输入0返回上级菜单：\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
        Student targetStu;
        if (m_store.haveStudent(std::to_string(choice), targetStu)) {
            show_Course(targetStu.getCourseList());
            system("cls");
            show_studentTableHead();
            show_studentTableTail();
            printf("\n输入学生编号以进行查看成绩信息,输入0返回上级菜单：\n");
        }
        else {
            printf("请正确输入学号:");
        }

    }
}

void Menu::show_studentTableHead()
{

    printf("----------------------------------------\n");
    printf("%-10s|%-10s|%-15s\n", "学号", "姓名", "性别");
    printf("----------------------------------------\n");
}

void Menu::show_studentTableTail()
{
    for (const auto & student:m_store.getStudentData()) {
        printf("%-10s", student.getId().c_str());
        printf("%-12s", student.getName().c_str());
        if (student.getSex()) {
            printf("%-10s\n", "男");
        }
        else {
            printf("%-10s\n", "女");
        }
    }
}

void Menu::show_Course(const std::vector<Course>& courseList)
{
    int choice;

    system("cls");
    show_courseTableHead();
    show_courseTableTail(courseList);
    printf("\n输入0返回上级菜单：\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
        
    }
    
}

void Menu::show_courseTableHead()
{
    printf("----------------------------------------\n");
    printf("%-10s|%-10s|%-15s\n", "课程代码", "课程名", "成绩");
    printf("----------------------------------------\n");

}

void Menu::show_courseTableTail(const std::vector <Course>& courseList)
{
    for (const auto& course : courseList) {
        printf("%-10s", course.getId().c_str());
        printf("%-12s", course.getName().c_str());
        printf("%-12.2lf\n", course.getScore());
    }
}

void Menu::show_operate_studentData()
{
    int choice;

    system("cls");
    show_operate_menu();
    printf("\n输入选项实行操作,输入0返回上级菜单：\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n三秒后自动退出此菜单！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        }
        
        if (choice==1) {
            add_student();
            system("cls");
            show_operate_menu();
        }
        else if (choice ==2) {
            delete_student();
            system("cls");
            show_operate_menu();
        }
        else {
            printf("请正确输入选项:\n");
        }

    }
}

void Menu::show_operate_menu()
{
    printf("************************************************************\n");
    printf("*");

    printf("              操作学生信息                                ");

    printf("*\n*");

    printf("以下是系统提供的操作：                                   ");

    printf(" *\n*                                                          *\n*");

    printf("  1.添加新的学生                                          ");

    printf("*\n*");

    printf("  2.删除学生                                              ");

    printf("*");
    printf("                                                          *\n");
    printf("*                                                          ");
    printf("*\n*");

    printf("           注意：输入相关序号进入下一操作选择（按下0退出）");

    printf("*\n*");
    printf("***********************************************************\n");

    printf("请输入你的选项：");
}

void Menu::add_student()
{
    using namespace std;
    Student newStu;
    int id;

    cout << "请输入学生的学号: " << endl;
    id = get_number();
    string temp = std::to_string(id);
    if (m_store.haveStudent(temp)) {
        cout << "已存在该学生，请重新选择操作."<<endl;
        return;
    }

    newStu.setId(temp);
    cout << "请输入学生的名字: " << endl;
    cin >> temp;
    newStu.setName(temp);

    cout << "请输入学生的性别（0为男性，其他数字为女性）: " << endl;
    int sex = get_number();
    if (sex) {
        newStu.setSex(BOY);
    }
    else {
        newStu.setSex(GIRL);
    }

    int choice;
    while (1) {
        printf("\n现在输入课程成绩信息,输入0停止输入课程信息,其他值则输入课程信息：\n");
        choice = get_number();

        if (choice == 0) {
            printf("\n三秒后自动保存！！！\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            break;
        }
        else {
            Course course;
            string temp;

            cout << "课程id:" << endl;
            cin >> temp;
            course.setId(temp);

            cout << "课程名:" << endl;
            cin >> temp;
            course.setName(temp);

            cout << "课程成绩:" << endl;
            double score = get_double();
            course.setScore(score);

            newStu.addCourse(course);
        }

    }
    m_store.addStudent(newStu);

}

double Menu::get_double()
{
    double op;
    while (scanf("%lf", &op) != 1) {
        printf("请输入数字：");
        while (getchar() != '\n')
            continue;
    }
    return op;
}

void Menu::delete_student()
{
    using namespace std;
    Student newStu;
    int id;

    cout << "请输入要删除学生的学号: " << endl;
    id = get_number();
    string temp = std::to_string(id);
    if (!m_store.haveStudent(temp)) {
        cout << "不已存在该学生，请重新选择操作." << endl;
        return;
    }

    
    m_store.deleteStudent(temp);

    printf("\n删除成功三秒后自动保存！！！\n");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
}
