#ifndef CUCKOO_FILTER_HASH_FUNCTION_H
#define CUCKOO_FILTER_HASH_FUNCTION_H

#include<random>
#include<string>

class HashFunction
{
private:
    unsigned __int128 multiply_, add_;
public:
    HashFunction(/* args */);
    ~HashFunction();
    unsigned __int64 gethashvalue(unsigned __int128 putin);
    unsigned __int64 gethashvalue(std::string putin);
    unsigned __int128 getmultiply();
    
};


#endif