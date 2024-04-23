#ifndef CUCKOO_FILTER_CUCKOO_HASH_H
#define CUCKOO_FILTER_CUCKOO_HASH_H


#include <iostream>
#include <vector>
#include <map>
#include "hash_function.h"

class Cuckoo_Hash
{
private:
    /* data */
    std::map<unsigned __int64,unsigned __int64> cuckoo_map;
    HashFunction* cuckoo_hash = new HashFunction();
    HashFunction* fingerprint = new HashFunction();
public:
    Cuckoo_Hash(/* args */);
    ~Cuckoo_Hash();
    unsigned __int64 get_hash_value(std::string element);
    bool Insert(unsigned __int64 hashplace, unsigned __int64 fingerprint);
    bool Insert(std::string element);
    bool Search(std::string element);
};

#endif