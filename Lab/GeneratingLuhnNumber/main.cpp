/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on February 28, 2017, 8:35 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
void chkDgt(char[],int);

int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=12;
    char crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    Luhn(crdCard,SIZE-2);
    cout<<crdCard;
    chkDgt(crdCard,SIZE-1);
    cout<<"The Credit Card is Valid!!\n";
    
    //Exit Stage Right
    return 0;
}

void chkDgt(char cc[],int n){
    int sum=0;
    int digit;
    for(int i=0;i<n;i++){
        cc[i];
        sum+=cc[i];
    }
    digit=(sum*9)%10;
    cout<<digit<<endl;
}

void Luhn(char cc[],int n){ 
    int sum=0;
    //Call Credit Card Number
    for(int i=0;i<n;i++){
        cc[i];
        if(i%2==1){
            if(cc[i]<50) cc[i]=(cc[i]*2)%10+42;
            else if(cc[i]>=50&&cc[i]<=52) cc[i]=(cc[i]*2)%10+52; 
            else if(cc[i]==53) cc[i]=49;
            else if(cc[i]==54) cc[i]=51;
            else if(cc[i]==55) cc[i]=53;
            else if(cc[i]==56) cc[i]=55;
            else cc[i]=57;
        }
    }
    
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

void prpLuhn(char cc[],int n){
    //Create a random cc in prep for Luhn checksum
    for(int i=0;i<n;i++){
        cc[i]=rndDgit();
    }
    //Put null terminator at the end
    for(int i=n;i<=n+1;i++){
        cc[i]='\0';
    }
}

char rndDgit(){
    return rand()%10+48;
}



