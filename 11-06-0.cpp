/*

Hash Tables

There are many different ways to code a hash function.
The simplest is the mod operator.

keys -> value

h(x) = x % size

 8  #  10  [0]
 3  #      [1]
 6  #      [2]
10  #   3  [3]
15  #   4  [4]
 9  #  15  [5]
 4  #   6  [6]
    #      [7]
    #   8  [8]
    #   9  [9]

Hashes are one-way functions; once input is hashed it is not possible to
retrieve the original value.

lambda = n / size

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node *next;

    Node(string k, int v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

    int hash(string key)
    {
        int hash{};
        for (int i = 0; i < key.length(); ++i)
        {
            int asciiValue = hash + key[i];
            hash = hash + asciiValue * 23 % SIZE;
        }

        return hash;
    }

public:
    ~HashTable()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            Node *head = dataMap[i];
            Node *temp = head;

            while (head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    void printTable()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << i << ":" << "\n";
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << " {" << temp->key << ", " << temp->value << "}" << "\n";
                    temp = temp->next;
                }
            }
        }
    }

    void set(string key, int value)
    {
        int index = hash(key);

        Node *newNode = new Node(key, value);

        if (dataMap[index] == nullptr)
            dataMap[index] = newNode;
        else
        {
            Node *temp = dataMap[index];
            while (temp->next != nullptr)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    int get(string key)
    {
        int index = hash(key);

        Node *temp = dataMap[index];

        while (temp != nullptr)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return 0;
    }

    vector<string> keys()
    {
        vector<string> allKeys;

        for (int i = 0; i < SIZE; ++i)
        {
            Node *temp = dataMap[i];
            while (temp != nullptr)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }

        return allKeys;
    }
};

int main()
{
    HashTable *myHash = new HashTable();
    
    myHash->set("nails", 100);
    myHash->set("tile", 80);
    myHash->set("lumber", 300);
    myHash->set("bolts", 150);
    myHash->set("washers", 109);

    vector<string> myKeys = myHash->keys();

    for (auto &e : myKeys)
    {
        cout << e << " ... ";
    }

    return 0;
}
