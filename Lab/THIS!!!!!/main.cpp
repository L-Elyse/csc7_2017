/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 10, 2017, 3:15 PM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int CrdCard(int &);
void genCC(int, char[], int);
const int SIZEpro(int);
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
void chkDgt(char[],int);

int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    int choice, x;
    const int MIN=1,MAX=4;
    //Show Menu
    CrdCard(choice);
    if(choice==5)
        choice=(rand()%(MAX-MIN+1))+MIN;
    //Get Array Size
    x=SIZEpro(choice);
    const int SIZE=x;
    char LuhnCrd[SIZE];
    //Test to see if Valid
    genCC(choice,LuhnCrd,SIZE);
    
    //Exit Stage Right
    return 0;
}

void genCC(int option, char LuhnCC[],int size){
    //Prepare for Luhn encoding
    prpLuhn(LuhnCC,size-2);
    //Output the preLuhn credit card
    cout<<LuhnCC<<endl;
    //Process Luhn
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    Luhn(LuhnCC,size-2);
    cout<<LuhnCC;
    //Prepare & Output Checking Digit
    chkDgt(LuhnCC,size-2);
    cout<<endl<<size;
}

void chkDgt(char cc[],int n){
    int digit, sum=0;
    for(int i=0;i<n;i++){
        cc[i];
        sum+=cc[i];
    }
    digit=(sum*9)%10;
    cout<<digit<<endl;
}

void Luhn(char cc[],int n){
    //Call Credit Card Number
    for(int i=0;i<n;i++){
        cc[i];
        if(i%2==1){
            if(cc[i]<50) cc[i]=(cc[i]*2)%10+42;
            else if(cc[i]>=50 && cc[i]<=52) cc[i]=(cc[i]*2)%10+52; 
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

const int SIZEpro(int option){
    int start;
    switch(option){
        case 1:{
            const int MIN=13, MAX=16;
            const int SIZE=(rand()%(MAX-MIN+1))+MIN;
            return SIZE;
        }
        case 2:{
            const int MIN=16, MAX=19;
            const int SIZE=(rand()%(MAX-MIN+1))+MIN;
            return SIZE;
        }
        case 3:{
            const int SIZE=15;
            return SIZE;
        }
        case 4:{
            const int SIZE=16;
            return SIZE;
        }
    }
}

int CrdCard(int &option){
    cout<<"Which credit card would you like to choose?"<<endl;
    cout<<"1. Visa"<<endl;
    cout<<"2. Mastercard"<<endl;
    cout<<"3. American Express"<<endl;
    cout<<"4. Discover"<<endl;
    cout<<"5. All (Random)"<<endl;
    cin>>option;
    return option;
} 