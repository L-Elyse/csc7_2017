/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 3, 2017, 3:00 PM
 * Purpose:  Using General Hashing Functions
 */

#ifndef GENERALHASHFUNCTIONS_H
#define GENERALHASHFUNCTIONS_H

//System Library
#include <string>

typedef unsigned int (*HashFunction)(const std::string&);

//Function Prototypes
unsigned int RSHash  (const std::string& str);
unsigned int JSHash  (const std::string& str);
unsigned int PJWHash (const std::string& str);
unsigned int ELFHash (const std::string& str);
unsigned int BKDRHash(const std::string& str);
unsigned int SDBMHash(const std::string& str);
unsigned int DJBHash (const std::string& str);
unsigned int DEKHash (const std::string& str);
unsigned int BPHash  (const std::string& str);
unsigned int FNVHash (const std::string& str);
unsigned int APHash  (const std::string& str);

#endif /* GENERALHASHFUNCTIONS_H */