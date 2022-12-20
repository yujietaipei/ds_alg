#include <iostream>
#include "hashtable.hpp"

using namespace std;

int main(void){
    //initialize a hashtable
    node** table = init_hashtable(2);
    string a("abc");
    string b("def");
    string c("ghi");

    //insert two strings into map
    insert(table, a);
    insert(table, b);

    std::cout << "Does ""abc"" exist in map ? " << lookup(table, a) << std::endl;
    std::cout << "Does ""def"" exist in map ? " << lookup(table, b) << std::endl;
    std::cout << "Does ""ghi"" exist in map ? " << lookup(table, c) << std::endl;

    return 0;
}