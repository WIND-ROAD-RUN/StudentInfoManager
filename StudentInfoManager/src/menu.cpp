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

            printf("\n��ӭ�ٴ�ʹ�ã�����\n");      //�˳�����
            printf("\n������Զ��˳����򣡣���\n");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            return;
        default:
            printf("����ȷ����ѡ��:");
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

    printf("            ��ӭ����ѧ����Ϣ����ϵͳ                      ");

    printf("*\n*");

    printf("������ϵͳ�ṩ�Ĳ�����                                    ");

    printf("*\n*                                                          *\n*");

    printf("  1.��ʾ����ѧ����Ϣ                                      ");

    printf("*\n*");

    printf("  2.����ѧ����Ϣ                                          ");

    printf("*");


    printf("\n*");
    printf("                                                          *\n");
    printf("*                                                          ");
    printf("*\n*");

    printf("           ע�⣺���������Ž�����һ����ѡ�񣨰���0�˳���");

    printf("*\n*");
    printf("***********************************************************\n");

    printf("���������ѡ�");
}

int Menu::get_number()
{
    int op;
    while (scanf("%d", &op) != 1) {
        printf("���������֣�");
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
    printf("\n����ѧ������Խ��в鿴�ɼ���Ϣ,����0�����ϼ��˵���\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
            printf("\n����ѧ������Խ��в鿴�ɼ���Ϣ,����0�����ϼ��˵���\n");
        }
        else {
            printf("����ȷ����ѧ��:");
        }

    }
}

void Menu::show_studentTableHead()
{

    printf("----------------------------------------\n");
    printf("%-10s|%-10s|%-15s\n", "ѧ��", "����", "�Ա�");
    printf("----------------------------------------\n");
}

void Menu::show_studentTableTail()
{
    for (const auto & student:m_store.getStudentData()) {
        printf("%-10s", student.getId().c_str());
        printf("%-12s", student.getName().c_str());
        if (student.getSex()) {
            printf("%-10s\n", "��");
        }
        else {
            printf("%-10s\n", "Ů");
        }
    }
}

void Menu::show_Course(const std::vector<Course>& courseList)
{
    int choice;

    system("cls");
    show_courseTableHead();
    show_courseTableTail(courseList);
    printf("\n����0�����ϼ��˵���\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
    printf("%-10s|%-10s|%-15s\n", "�γ̴���", "�γ���", "�ɼ�");
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
    printf("\n����ѡ��ʵ�в���,����0�����ϼ��˵���\n");
    while (1) {
        choice = get_number();

        if (choice == 0) {
            printf("\n������Զ��˳��˲˵�������\n");
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
            printf("����ȷ����ѡ��:\n");
        }

    }
}

void Menu::show_operate_menu()
{
    printf("************************************************************\n");
    printf("*");

    printf("              ����ѧ����Ϣ                                ");

    printf("*\n*");

    printf("������ϵͳ�ṩ�Ĳ�����                                   ");

    printf(" *\n*                                                          *\n*");

    printf("  1.����µ�ѧ��                                          ");

    printf("*\n*");

    printf("  2.ɾ��ѧ��                                              ");

    printf("*");
    printf("                                                          *\n");
    printf("*                                                          ");
    printf("*\n*");

    printf("           ע�⣺���������Ž�����һ����ѡ�񣨰���0�˳���");

    printf("*\n*");
    printf("***********************************************************\n");

    printf("���������ѡ�");
}

void Menu::add_student()
{
    using namespace std;
    Student newStu;
    int id;

    cout << "������ѧ����ѧ��: " << endl;
    id = get_number();
    string temp = std::to_string(id);
    if (m_store.haveStudent(temp)) {
        cout << "�Ѵ��ڸ�ѧ����������ѡ�����."<<endl;
        return;
    }

    newStu.setId(temp);
    cout << "������ѧ��������: " << endl;
    cin >> temp;
    newStu.setName(temp);

    cout << "������ѧ�����Ա�0Ϊ���ԣ���������ΪŮ�ԣ�: " << endl;
    int sex = get_number();
    if (sex) {
        newStu.setSex(BOY);
    }
    else {
        newStu.setSex(GIRL);
    }

    int choice;
    while (1) {
        printf("\n��������γ̳ɼ���Ϣ,����0ֹͣ����γ���Ϣ,����ֵ������γ���Ϣ��\n");
        choice = get_number();

        if (choice == 0) {
            printf("\n������Զ����棡����\n");
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

            cout << "�γ�id:" << endl;
            cin >> temp;
            course.setId(temp);

            cout << "�γ���:" << endl;
            cin >> temp;
            course.setName(temp);

            cout << "�γ̳ɼ�:" << endl;
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
        printf("���������֣�");
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

    cout << "������Ҫɾ��ѧ����ѧ��: " << endl;
    id = get_number();
    string temp = std::to_string(id);
    if (!m_store.haveStudent(temp)) {
        cout << "���Ѵ��ڸ�ѧ����������ѡ�����." << endl;
        return;
    }

    
    m_store.deleteStudent(temp);

    printf("\nɾ���ɹ�������Զ����棡����\n");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
}
