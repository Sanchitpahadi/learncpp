#include"main.hpp"

#include<map>

int main()
{
    std::map<std::string,int> m;

    m["apple"] = 5;

    m.insert({"banana",3});

    m.insert_or_assign("apple",10);

    m.emplace("cheerry",8);
    
    m.try_emplace("date" , 2);

    m.find("apple");    
    m.count("apple");   
    m.at("apple");      
    
    return 0;
}