

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int totalS;

struct student
{
    string firstname;
    string surname;
    int id;
    int marks[5];
    int sum;
    float gpa;
};

void load();
void addData();
void searchRecord();
void updateRecord();
void viewAll();
void calGPA();
void rankStd();
void genReport();
void searchId();
void searchIdNot();
void searchIdYes();
void upsearchId();
void upsearchIdNot();
void upsearchIdYes(int w);
void success(int a);
void menu();

int main()
{

    int n1;

    cout << "\n\t=============================================================\n";
    cout << "\t        Welcome To Student Gradebook & Result Analyzer\n";
    cout << "\t=============================================================\n\n";

    cout << "\t[0] Load data of students\n";
    cout << "\t[1] Add data of students\n";
    cout << "\t[2] Search Student record\n";
    cout << "\t[3] Update Student record\n";
    cout << "\t[4] View all Student records\n";
    cout << "\t[5] Calculate GPA \n";
    cout << "\t[6] Rank students\n";
    cout << "\t[7] Generate reports\n";
    cout << "\t[8] Exit\n\n";

    cout << "Enter your option: ";
    cin >> n1;

    if (n1 == 0)
    {
        load();
        system("cls");
        cout << "\n\t>>> Data loaded Successfully <<<\n\n";
        main();
    }
    else if (n1 == 1)
    {
        system("cls");
        addData();
    }
    else if (n1 == 2)
    {
        system("cls");
        searchRecord();
    }
    else if (n1 == 3)
    {
        system("cls");
        updateRecord();
    }
    else if (n1 == 4)
    {
        system("cls");
        viewAll();
    }
    else if (n1 == 5)
    {
        system("cls");
        calGPA();
    }
    else if (n1 == 6)
    {
        system("cls");
        rankStd();
    }
    else if (n1 == 7)
    {
        system("cls");
        genReport();
    }
    else if (n1 == 8)
    {
        system("cls");
        cout << "\n\t\t\tThanks You\n";
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        main();
    }

    return 0;
}

void menu()
{
    int choice;
    cout << "\n\t=============================================================\n";
    cout << "\t[1] Back to Main Menu\n\t[2] Exit\n";
    cout << "\t=============================================================\n";
    cout << "Enter your option: ";
    cin >> choice;

    if (choice == 1)
    {
        main();
    }
    else if (choice == 2)
    {
        system("cls");
        cout << "\n\t\t\tThank You\n";
        
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        menu();
    }
}
void load()
{
    totalS = 0;
    student s;
    ifstream loading("student.txt");
    if (!loading)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }
    while (loading >> s.id >> s.firstname >> s.surname)
    {
        for (int i = 0; i < 5; i++)
            loading >> s.marks[i];
        loading >> s.sum >> s.gpa;
        totalS++;
    }

    loading.close();
}

void searchIdYes()
{
    cout << "\n\t=============================================================\n";
    cout << "\t[1] Search Another Record\n\t[2] Main Menu\n";
    cout << "\t=============================================================\n";

    int n4;
    cout << "Enter your option: ";
    cin >> n4;

    if (n4 == 1)
    {
        system("cls");
        searchRecord();
    }
    else if (n4 == 2)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        searchIdYes();
    }
}
void searchIdNot()
{
    system("cls");
    cout << "\n\t=============================================================\n";
    cout << "\t\tRecord Not Found!\n";
    cout << "\t=============================================================\n";
    cout << "\t[1] Research\n\t[2] Main Menu\n";

    int n3;
    cout << "Enter your option: ";
    cin >> n3;

    if (n3 == 1)
    {
        system("cls");
        searchRecord();
    }
    else if (n3 == 2)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        searchIdNot();
    }
}
void searchId()
{
    system("cls");

    cout << "\n\t=============================================================\n";
    cout << "\t\t\tSearch By ID\n";
    cout << "\t=============================================================\n";

    int ide;
    cout << "Enter the ID of student for search: ";
    cin >> ide;
    cout << endl;

    student iden;
    int check = 0;
    ifstream shid("student.txt");
    if (!shid)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }

    while (shid >> iden.id >> iden.firstname >> iden.surname)
    {
        for (int i = 0; i < 5; i++)
        {
            shid >> iden.marks[i];
        }
        shid >> iden.sum >> iden.gpa;
        cout << fixed << setprecision(1);

        if (iden.id == ide)
        {
            check = 1;
            cout << "\n\t>>> Record Found <<<\n";
            cout << "-------------------------------------------------------------------\n";
            cout << " ID\tName\t\tSub1 Sub2 Sub3 Sub4 Sub5  Total  GPA\n";
            cout << "-------------------------------------------------------------------\n";

            cout << iden.id << "\t" << iden.firstname + " " + iden.surname << "\t";
            for (int j = 0; j < 5; j++)
            {
                cout << iden.marks[j] << "   ";
            }
            cout << " " << iden.sum << "    " << iden.gpa << endl;
        }

        if (check == 1)
        {
            shid.close();
            break;
        }
    }

    if (check == 1)
        searchIdYes();
    if (check == 0)
    {
        shid.close();
        system("cls");
        searchIdNot();
    }
}

void searchRecord()
{
    cout << "\n\t=============================================================\n";
    cout << "\t\t\t\tSearch Record\n";
    cout << "\t=============================================================\n";

    cout << "\t[1] Search by ID\n\t[2] Main Menu\n";

    int n2;
    cout << "Enter your option: ";
    cin >> n2;

    if (n2 == 1)
    {
        system("cls");
        searchId();
    }
    else if (n2 == 2)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        searchRecord();
    }
}
void upsearchIdNot()
{
    cout << "\n\t=============================================================\n";
    cout << "\t\tRecord Not Found!\n";
    cout << "\t=============================================================\n";
    cout << "\t[1] Research\n\t[2] Main Menu\n";

    int n3;
    cout << "Enter your option: ";
    cin >> n3;

    if (n3 == 1)
    {
        system("cls");
        updateRecord();
    }
    else if (n3 == 2)
    {
        system("cls");
        main();
    }
    else
    {
        system("cls");
        cout << "\n\t>>> Please press the correct option! <<<\n\n";
        upsearchIdNot();
    }
}
void upsearchIdYes(int w)
{
    cout << "\n\t=============================================================\n";
    cout << "\t\t\tRecord Found!\n";
    cout << "\t=============================================================\n";

    student *s = new student[totalS];
    ifstream xyz("student.txt");
    if (!xyz)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }
    int count = 0;     

    while (xyz >> s[count].id >> s[count].firstname >> s[count].surname)
    {
        for (int i = 0; i < 5; i++)
        {
            xyz >> s[count].marks[i];
        }
        xyz >> s[count].sum >> s[count].gpa;
        count++;
    }

    for (int i = 0; i < count; i++)
    {
        if (s[i].id == w)
        {
            cout << "\tID: " << s[i].id << "\n";
            cout << "\tName: " << s[i].firstname << " " << s[i].surname << "\n";
            cout << "\tTotal Marks: " << s[i].sum << "\n";
            cout << "\tGPA: " << s[i].gpa << "\n";
            cout << "\tCurrent Marks: ";
            for (int j = 0; j < 5; j++)
            {
                cout << s[i].marks[j] << " | ";
            }

            cout << "\n";

            int subject, mark;
            cout << "Enter subject number (1-5) to update: ";
            cin >> subject;
            cout << "Enter new marks: ";
            cin >> mark;

            s[i].marks[subject - 1] = mark;
            s[i].sum = 0;
            s[i].gpa = 0;
            for (int k = 0; k < 5; k++)
            {
                s[i].sum += s[i].marks[k];
            }
            s[i].gpa = (static_cast<float>(s[i].sum) / 500.0) * 4.0;
            w=i;
            break;
        }
    }

    xyz.close();
    ofstream out("student.txt");
    if (!out)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }
    for (int i = 0; i < count; i++)
    {
        out << s[i].id << " " << s[i].firstname << " " << s[i].surname << " ";
        for (int j = 0; j < 5; j++)
        {
            out << s[i].marks[j] << " ";
        }

        out << s[i].sum << " " << s[i].gpa << "\n";
    }
    out.close();
    delete[] s;

    success(w);
}

void success(int a)
{
    student *s = new student[totalS];
    ifstream xyz("student.txt");
    if (!xyz)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }
    int count = 0;

    while (xyz >> s[count].id >> s[count].firstname >> s[count].surname)
    {
        for (int i = 0; i < 5; i++)
        {
            xyz >> s[count].marks[i];
        }
        xyz >> s[count].sum >> s[count].gpa;
        count++;
    }

    system("cls");
    cout << "\n\t=============================================================\n";
    cout << "\t\tRecord Updated Successfully!\n";
    cout << "\t=============================================================\n";
    cout << "\tID: " << s[a].id << "\n";
    cout << "\tName: " << s[a].firstname << " " << s[a].surname << "\n";
    cout << "\tTotal Marks: " << s[a].sum << "\n";
    cout << "\tGPA: " << fixed << setprecision(1) << s[a].gpa << "\n";
    cout << "\tMarks: ";
    for (int j = 0; j < 5; j++)
    {
        cout << s[a].marks[j] << " | ";
    }

    cout << "\n";
    int o = 0;
    do
    {
        int n2;
        cout << "\t=============================================================\n";
        cout << "\t[1] Update another record\n\t[2] Main Menu\n";
        cout << "\t=============================================================\n";
        cout << "Enter your option: ";
        cin >> n2;

        if (n2 == 1)
        {
            system("cls");
            searchRecord();
        }
        else if (n2 == 2)
        {
            system("cls");
            main();
        }
        else
        {
            system("cls");
            cout << "\n\t>>> Please press the correct option! <<<\n\n";
            o = 0;
        }

    } while (o == 0);

    delete[] s;
    xyz.close();
}

void updateRecord()
{
    system("cls");

    cout << "\n\t=============================================================\n";
    cout << "\t\tUpdate Student Record\n";
    cout << "\t=============================================================\n";

    int upd;
    cout << "Enter the ID of student for search: ";
    cin >> upd;

    student s;
    int check = 0;
    ifstream in("student.txt");
    if (!in)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }

    while (in >> s.id >> s.firstname >> s.surname)
    {
        for (int i = 0; i < 5; i++)
            in >> s.marks[i];
        in >> s.sum >> s.gpa;
        if (s.id == upd)
            check = 1;
        if (check == 1)
            break;
    }
    in.close();

    if (check == 1)
    {
        system("cls");
        upsearchIdYes(upd);
    }
    else
    {
        system("cls");
        upsearchIdNot();
    }
}

void viewAll()
{
    cout << "\n==========================================================================================\n";
    cout << "                                All Students Record                                       \n";
    cout << "==========================================================================================\n";
    cout << left << setw(6) << "ID" << setw(20) << "Name" << setw(8) << "Sub1" << setw(8) << "Sub2" << setw(8) << "Sub3" << setw(8) << "Sub4" << setw(8) << "Sub5" << setw(8) << "Total" << setw(8) << "GPA" << endl;

    cout << "------------------------------------------------------------------------------------------\n";

    student s;
    ifstream viw("student.txt");
    if (!viw)
    {
        cout << "Error: student.txt not found!" << endl;
        return;
    }

    cout << fixed << setprecision(1);

    while (viw >> s.id >> s.firstname >> s.surname)
    {
        for (int i = 0; i < 5; i++)
            viw >> s.marks[i];

        viw >> s.sum;

        if (viw.peek() == '\n' || viw.peek() == EOF)
        {
            s.gpa = 0;
        }
        else
        {
            viw >> s.gpa;
        }
        cout << left << setw(6) << s.id << setw(20) << (s.firstname + " " + s.surname);

        for (int j = 0; j < 5; j++)
        {
            cout << setw(8) << s.marks[j];
        }
        cout << setw(8) << s.sum << setw(8) << s.gpa << endl;
    }

    cout << "------------------------------------------------------------------------------------------\n";
    viw.close();
    cout << "\nEnter any key to return to main menu...";
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}

void addData()
{

    system("cls");
    cout << "\t -------------------------------------------------------------\n\n";
    cout << "\t\t Add Students Record \n\n";
    cout << "\t -------------------------------------------------------------\n\n";
    int n2;
    cout << "Enter the number of students to add: ";
    cin >> n2;
    totalS = totalS + n2;
    // cin.ignore();
    int x1 = 1;
    ofstream addFile("student.txt", ios::app);
    if (!addFile)
    {
        cout << "Error: student.txt not found!" << endl;
        return;
    }
    for (int i = 0; i < n2; i++)
    {
        student s;
        cout << "Enter the ID of Student " << x1 << " : ";
        s.sum = 0;
        cin >> s.id;
        cout << "Enter the name of Student " << x1 << " : ";
        cin >> s.firstname;
        cin >> s.surname;

        int x2 = 1;
        for (int j = 0; j < 5; j++)
        {
            while (true)
            {
                cout << "Enter marks of subject " << (j+1) << " (0-100): ";
                cin >> s.marks[j];
                if (s.marks[j] >= 0 && s.marks[j] <= 100)
                {
                    s.sum += s.marks[j];
                    break;
                }
                cout << "Invalid mark! Please enter between 0-100." << endl;
            }
            x2++;
        }

        addFile << s.id << " " << s.firstname << " " << s.surname;
        for (int k = 0; k < 5; k++)
        {
            addFile << " " << s.marks[k] << " ";
        }
        addFile << s.sum << " " << 0.0;
        addFile << endl;

        x1++;
    }
    addFile.close();
    cout << "\n\n ";
    load();
    cout << "\n\t>>> Data added Successfully <<<\n\n";
    cout << "Enter any key to return to main menu...";
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}

void calGPA()
{
    student grade;
    system("cls");

    cout << "\n\t=============================================================\n";
    cout << "\t\tCalculate GPA of Students\n";
    cout << "\t=============================================================\n";

    ifstream gpaa("student.txt");
    ofstream newFile("new.txt");
    if (!gpaa)
    {
        cout << "Error: student.txt not found!\n";
        return;
    }
    if (!newFile)
    {
        cout << "Error: new.txt not found!\n";
        return;
    }

    while (gpaa >> grade.id >> grade.firstname >> grade.surname)
    {
        for (int i = 0; i < 5; i++)
        {
            gpaa >> grade.marks[i];
        }
        gpaa >> grade.sum >> grade.gpa;
        grade.gpa = (static_cast<float>(grade.sum) / 500.0) * 4.0;

        newFile << grade.id << " " << grade.firstname << " " << grade.surname << " ";
        for (int j = 0; j < 5; j++)
        {
            newFile << grade.marks[j] << " ";
        }
        newFile << grade.sum << " " << grade.gpa << "\n";
    }

    gpaa.close();
    newFile.close();
    remove("student.txt");
    rename("new.txt", "student.txt");
    viewAll();
    menu();
}

void rankStd()
{
    student *r = new student[totalS];
    int count = 0;

    ifstream rankR("student.txt");
    if (!rankR)
    {
        cout << "Error: student.txt not found!" << endl;
        return;
    }
    while (rankR >> r[count].id >> r[count].firstname >> r[count].surname)
    {
        for (int i = 0; i < 5; i++)
        {
            rankR >> r[count].marks[i];
        }
        rankR >> r[count].sum >> r[count].gpa;
        count++;
    }
    rankR.close();

    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (r[i].sum < r[j].sum)
                swap(r[i], r[j]);

    system("cls");
    cout << "\n\t=============================================================\n";
    cout << "\t\tStudents Ranked by Marks\n";
    cout << "\t=============================================================\n";

    cout << left << setw(8) << "Rank" << setw(8) << "ID" << setw(25) << "Name" << setw(10) << "Total" << setw(8) << "GPA" << endl;
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        string fullName = r[i].firstname + " " + r[i].surname;
        cout << left << setw(8) << (i + 1) << setw(8) << r[i].id << setw(25) << fullName << setw(10) << r[i].sum << setw(8) << r[i].gpa << "\n";
    }

    delete[] r;
    cout << "-------------------------------------------------------------\n";
    cout << "\nEnter any key to return to main menu...";
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}

void genReport()
{
    cout << "\n\t=============================================================\n";
    cout << "\t    Student Performance Report\n";
    cout << "\t=============================================================\n";
    cout << "\n-------------------------------------------------------------\n";

    student *s = new student[totalS];
    ifstream rep("student.txt");
    if (!rep)
    {
        cout << "Error: student.txt not found!" << endl;
        return;
    }
    int count = 0;

    while (rep >> s[count].id >> s[count].firstname >> s[count].surname)
    {
        for (int i = 0; i < 5; i++)
            rep >> s[count].marks[i];
        rep >> s[count].sum >> s[count].gpa;
        count++;
    }

    int index = 0;
    for (int i = 0; i < count; i++)
        if (s[i].gpa > s[index].gpa)
            index = i;

    float avg = 0;
    int pass = 0, fail = 0;
    for (int i = 0; i < count; i++)
    {
        avg += s[i].gpa;
        if (s[i].gpa >= 2.0)
            pass++;
        else
            fail++;
    }
    avg /= count;

    cout << fixed << setprecision(1);
    cout << "Total Students: " << count << "\n";
    cout << "Average GPA:    " << avg << "\n";
    cout << "Total Pass:     " << pass << "\n";
    cout << "Total Fail:     " << fail << "\n";

    cout << "\nTopper Details:\n";
    cout << "ID:           " << s[index].id << "\n";
    cout << "Name:         " << s[index].firstname << " " << s[index].surname << "\n";
    cout << "Total Marks:  " << s[index].sum << "\n";
    cout << "GPA:          " << s[index].gpa << "\n";

    delete[] s;
    rep.close();
    cout << "-------------------------------------------------------------\n";
    cout << "\nEnter any key to return to main menu...";
    cin.ignore();
    cin.get();
    system("cls");
    menu();
}
