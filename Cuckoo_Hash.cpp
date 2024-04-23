#include"Cuckoo_Hash.h"

Cuckoo_Hash::Cuckoo_Hash(/* args */)
{
}

Cuckoo_Hash::~Cuckoo_Hash()
{
}

unsigned __int64 Cuckoo_Hash::get_hash_value(std::string element){
    return cuckoo_hash->gethashvalue(element);
}

bool Cuckoo_Hash::Insert(std::string element){
    unsigned __int64 hashplace, element_fingerprint;
    hashplace = cuckoo_hash->gethashvalue(element);
    element_fingerprint = fingerprint->gethashvalue(element);
    if(cuckoo_map.count(hashplace)){
        Insert(hashplace^(*cuckoo_map.find(hashplace)).second,(*cuckoo_map.find(hashplace)).second);
        (*cuckoo_map.find(hashplace)).second = element_fingerprint;
    }
    else{
        cuckoo_map.insert({hashplace,element_fingerprint});
    }
    return true;
}

bool Cuckoo_Hash::Insert(unsigned __int64 hashplace, unsigned __int64 fingerprint){
    if(cuckoo_map.count(hashplace)){
        Insert(hashplace^(*cuckoo_map.find(hashplace)).second,(*cuckoo_map.find(hashplace)).second);
    }
    (*cuckoo_map.find(hashplace)).second;
    return true;
}

bool Cuckoo_Hash::Search(std::string element){
    unsigned __int64 hashplace = cuckoo_hash->gethashvalue(element);
    unsigned __int64 element_fingerprint = fingerprint->gethashvalue(element);
    if((*cuckoo_map.find(hashplace)).second == element_fingerprint || (*cuckoo_map.find(hashplace^element_fingerprint)).second == element_fingerprint){
        return true;
    }
    else{
        return false;
    }
}
