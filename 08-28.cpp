#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int id;
    Student *next;
    Student(string name, int id)
    {
        this->id = id;
        this->name = name;
        next = nullptr;
    }
};

class StudentList
{
private:
    Student *head;
    Student *tail;
    int length;

public:
    StudentList(string name, int id)
    {
        Student *newStudent = new Student(name, id);
        head = newStudent;
        tail = newStudent;
        length = 1;
    }

    ~StudentList()
    {
        Student *tmp = head;
        while (head)
        {
            head = head->next;
            delete tmp;
            tmp = head;
        }

        cout << "\n\n\nHeap alloc'd data has been freed.\n\n";
    }

    void print()
    {
        Student *tmp = head;

        int idx = 0;

        while (tmp)
        {
            cout << "The index of this node is " << idx << endl;
            cout << "The student name is " << tmp->name << endl;
            cout << "The student ID is " << tmp->id << "\n" << endl;

            tmp = tmp->next;
            idx++;
        }
    }

    void getLength()
    {
        cout << "The length of the list is " << length << "\n" << endl;
    }

    void insertLast(string name, int id)
    {
        Student *newStudent = new Student(name, id);

        if (head == nullptr)
        {
            head = newStudent;
            tail = newStudent;
        }
        else
        {
            tail->next = newStudent;
            tail = tail->next;
        }

        length++;
    }

    void deleteLast()
    {
        // if (length > 0)
        if (head != nullptr)
        {
            Student *tmp = head;
            while (tmp->next != tail)
            {
                tmp = tmp->next;
            }
            delete tail;
            tail = tmp;
            tail->next = nullptr;
        }
        else
        {
            cout << "Nothing to delete." << endl;
        }
    }

    void insertFirst(string name, int id)
    {
        Student *newStudent = new Student(name, id);

        if (length == 0)
        {
            head = newStudent;
            tail = newStudent;
        }
        else
        {
            newStudent->next = head;
            head = newStudent;
        }
    }

    void deleteFirst()
    {
        Student *tmp = head;

        if (length > 0)
        {
            head = head->next;
        }
        if (tmp)
        {
            delete tmp;
        }
    }

    Student *getIndex(int idx)
    {
        if (idx < 0 || idx >= length)
        {
            return nullptr;
        }

        Student *tmp = head;

        for (int i = 0; i < idx; i++)
        {
            tmp = tmp->next;
        }

        return tmp;
    }

    bool set(int idx, string name, int id)
    {
        Student *tmp = getIndex(idx);

        if (tmp)
        {
            tmp->name = name;
            tmp->id = id;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool insert(int idx, string name, int id)
    {
        if (idx < 0 || idx > length)
        {
            return false;
        }

        if (idx == 0)
        {
            insertFirst(name, id);
            return true;
        }
        else if (idx == length)
        {
            insertLast(name, id);
            return true;
        }

        Student *newStudent = new Student(name, id);
        Student *tmp = getIndex(idx);

        newStudent->next = tmp->next;
        tmp->next = newStudent;
        length++;

        return true;
    }

    void deleteStudent(int idx)
    {
        if (idx < 0 || idx > length)
        {
            return;
        }

        if (idx == 0)
        {
            return deleteFirst();
        }
        if (idx == length - 1)
        {
            return deleteLast();
        }

        Student *follow = getIndex(idx - 1);
        Student *lead = follow->next;

        follow->next = lead->next;
        delete lead;
        length--;
    }

    void reverseList()
    {
        if (length < 2)
        {
            return;
        }
        
        Student *cur = head->next;
        // first condition
        tail->next = head;
        head->next = nullptr;

        while (cur != tail)
        {
            Student tmp = *cur;
            cur->next = tail->next;
            tail->next = cur;
            cur = tmp.next;
        }

        Student *tmp = head;
        head = tail;
        tail = tmp;
    }
};


int main()
{
    StudentList *myStudent = new StudentList("Josip", 1234);

    myStudent->insertLast("Mira", 298347);
    myStudent->insert(1, "Stjepan", 90);
    myStudent->insertLast("Novak", 238);
    myStudent->insertFirst("Svetlana", 283);
    myStudent->insertFirst("Strahinja", 8);

    myStudent->print();

    myStudent->deleteLast();

    myStudent->reverseList();

    myStudent->print();

    delete myStudent;

    return 0;
}
