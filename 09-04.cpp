/*

This is merely a continuation of 08-28.

*/

#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    int id;
    Student *next;
    Student *prev;
    Student(string name, int id)
    {
        this->id = id;
        this->name = name;
        next = nullptr;
        prev = nullptr;
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
            newStudent->prev = tail;
            tail = tail->next;
        }

        length++;
    }

    void deleteLast()
    {
        // if (length > 0)
        if (head != nullptr)
        {
            Student *tmp = tail;
            /*while (tmp->next != tail)
            {
                tmp = tmp->next;
            }*/
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            length--;
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
            head->prev = newStudent;
            head = newStudent;
        }
        length++;
    }

    void deleteFirst()
    {
        Student *tmp = head;

        if (length > 0)
        {
            head = head->next;
            if (head) head->prev = nullptr;
            delete tmp;
            length--;
        }
        else
        {
            cout << "Nothing to delete." << endl;
        }
    }

    Student *getIndex(int idx)
    {
        if (idx < 0 || idx >= length)
        {
            return nullptr;
        }

        Student *tmp;
        if (idx < length / 2)
        {
            tmp = head;
            for (int i = 0; i < idx; i++)
            {
                tmp = tmp->next;
            }
        }
        else
        {
            tmp = tail;
            for (int i = length - 1; i > idx; i--)
            {
                tmp = tmp->prev;
            }
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
        Student *before = getIndex(idx - 1);
        Student *after = before->next;

        newStudent->prev = before;
        newStudent->next = after;
        before->next = newStudent;
        after->prev = newStudent;
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

        Student *tmp = getIndex(idx);
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;

        delete tmp;
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
    StudentList *stud = new StudentList("Irena", 100);
    stud->insertLast("Maja", 101);
    stud->insert(2, "Marko", 104);
    stud->insertLast("Sofija", 108);
    stud->insertFirst("Nikola", 99);
    stud->insert(4, "Dezodorantska krema za noge", 106);
    stud->insert(4, "Aleksandr", 105);
    stud->deleteStudent(5);
    stud->deleteStudent(3);
    stud->insert(3, "Magdalena", 102);
    stud->reverseList();

    stud->print();
    delete stud;
    return 0;
}
