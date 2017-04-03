/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 3, 2017, 3:00 PM
 * Purpose:  Using General Hashing Functions
 */

//System Libraries Here
#include <iostream>
#include <string>
using namespace std;

//User Libraries Here
#include "GeneralHashFunctions.h"

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare String Literal
    const std::string key="Then out spake brave Horatius,\n"
                     "     The Captain of the Gate:\n"
                     "     To every man upon this earth\n"
                     "     Death cometh soon or late.\n"
                     "     And how can man die better\n"
                     "     Than facing fearful odds,\n"
                     "     For the ashes of his fathers,\n"
                     "     And the temples of his gods.\n";
    
    //Output Hash Values
    std::cout<<"General Purpose Hash Function Algorithm"<<std::endl;
    std::cout<<"--------------------------------------"<<std::endl;
    std::cout<<"Key: "<<key<<std::endl;
    std::cout<<  " 1. RS-Hash Function Value:   "<<RSHash(key)<<std::endl;
    std::cout << " 2. JS-Hash Function Value:   " << JSHash  (key) << std::endl;
    std::cout << " 3. PJW-Hash Function Value:  " << PJWHash (key) << std::endl;
    std::cout << " 4. ELF-Hash Function Value:  " << ELFHash (key) << std::endl;
    std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
    std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
    std::cout << " 7. DJB-Hash Function Value:  " << DJBHash (key) << std::endl;
    std::cout << " 8. DEK-Hash Function Value:  " << DEKHash (key) << std::endl;
    std::cout << " 9. FNV-Hash Function Value:  " << FNVHash (key) << std::endl;
    std::cout << "10. BP-Hash Function Value:   " << BPHash  (key) << std::endl;
    std::cout << "11. AP-Hash Function Value:   " << APHash  (key) << std::endl;

    //Exit
    return 0;
}