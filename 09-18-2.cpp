/*

STL Maps.

Maps are very similar to sets, being sorted containers, but store
elements in key-value pairs.

*/


#include <iostream>
#include <map>
#include <vector>


// === main ===============================================================
//
// ========================================================================
int main()
{
    std::map<std::string, int> m{ {"Arsen", 99}, {"Đorđe", 66}, {"Lena", 23} };

    m["Arsen"] = 18;
    m["Arsen"] += 10;

    m.erase("Đorđe");

    for (auto const &e : m)
        std::cout << "Name: " << e.first << "\nAge: " << e.second << "\n\n";
}


// === main_old2 ==========================================================
// Again, med deleted this code TOO so I have to write ANOTHER main.
// ========================================================================
int main_old2()
{
    // poor Đorđe will be last, because "Đ" is lexicologically greater than "L" even if it comes before it in Serbian alphabet.
    // you can thank Unicode. don't worry, this works though but his entry is last.
    std::map<std::string, std::vector<int>> grades = {
        {"Arsen", {20, 30, 40}},
        {"Đorđe", {87, 87, 87}},
        {"Lena", {98, 87, 66}}
    };

    // inb4 "isn't this quadratic complexity?"
    // we can also not use reference but then we expend copying the element.
    for (auto const &e : grades)
        for (auto const &v : e.second)
            std::cout << v << " ";

    return 0;
}


// === main_old ===========================================================
// And then Med famously deleted this code.
// ========================================================================
int main_old1()
{
    std::map<int, std::string> emp{{101, "Luka"}, {110, "Bogdan"}, {510, "Saša"}};

    // of course we can use auto as well
    std::map<int, std::string>::iterator it;

    // two ways to print out the map
    for (it = emp.begin(); it != emp.end(); ++it)
    {
        std::cout << "ID: " << it->first << "  "
                  << "Name: " << it->second << "\n\n";
    }

    for (std::pair<int, std::string> e : emp)
    {
        std::cout << "ID: " << e.first << "  "
                  << "Name: " << e.second << "\n\n";
    }

    return 0;
}
