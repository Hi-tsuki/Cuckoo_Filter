#include "hash_function.h"
#include <ctime>


HashFunction::HashFunction(/* args */)
{
    srand(1);
    for(auto x : {&multiply_, &add_}){
        *x = rand();
        for(int i = 0; i < 3; i++){
            *x = *x << 32;
            *x |= rand();
        }
    }
}

HashFunction::~HashFunction()
{
}

unsigned __int64 HashFunction::gethashvalue(unsigned __int128 putin){
    putin = putin * multiply_ + add_;
    return putin;
}

unsigned __int64 HashFunction::gethashvalue(std::string putin){
    unsigned __int128 intputin = 0;
    for(auto i : putin){
        intputin += (unsigned __int128) i;
    }
    intputin = intputin * multiply_ + add_;
    return intputin;
}

unsigned __int128 HashFunction::getmultiply(){
    return multiply_;
}

