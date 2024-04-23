#include <iostream>
#include"Cuckoo_Hash.h"

int main()
{
    Cuckoo_Hash *cuckoohash = new Cuckoo_Hash();
    std::string x, y;
    while(1){
        std::cin>>x>>y;
        if(x == "in"){
            std::cout << cuckoohash->Insert(y) << std::endl;
        }
        else{
            cuckoohash->Search(y);
        }
    }
    return 0;
}