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
const int Menupro(int);
char rndDgit();
void prpLuhn(char[],int);
void Luhn(char[],int);
void chkDgt(char[],int);

int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    int choice;
    const int MIN=1,MAX=4;
    //Show Menu
    CrdCard(choice);
    if(choice==5)
        choice=(rand()%(MAX-MIN+1))+MIN;
    //Get Array Size
    const int SIZE=Menupro(choice);
    char crdCard[SIZE], LuhnCrd[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit"<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    cout<<crdCard<<endl;
    //Process Luhn
    cout<<"The random number with Luhn Encoding, Output Here!"<<endl;
    //Reverse Digits in Array
    for(int i=0;i<SIZE-2;i++){
        LuhnCrd[i]=crdCard[(SIZE-3)-i];
    }
    Luhn(LuhnCrd,SIZE-2);
    cout<<"Complete Random Number: "<<endl<<crdCard;
    //Prepare & Output Checking Digit
    chkDgt(crdCard,SIZE-1);
    cout<<"The Credit Card is Valid!!\n";
    
    //Exit Stage Right
    return 0;
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
        if(i%2==0){
            if(cc[i]<50) cc[i]=(cc[i]*2)%10+42;
            else if(cc[i]>=50 && cc[i]<=52) cc[i]=(cc[i]*2)%10+52; 
            else if(cc[i]==53) cc[i]=49;
            else if(cc[i]==54) cc[i]=51;
            else if(cc[i]==55) cc[i]=53;
            else if(cc[i]==56) cc[i]=55;
            else cc[i]=57;
        }
    }
    //Reverse numbers back to display
    for(int j=n-1;j>-1;j--)
        cout<<cc[j];
    cout<<endl;
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

const int Menupro(int option){
    switch(option){
        case 1:{
            const int MIN=14, MAX=17;
            const int SIZE=(rand()%(MAX-MIN+1))+MIN;
            cout<<"You have chosen Visa."<<endl;
            cout<<"This card has "<<SIZE-1<<" digits"<<endl;
            return SIZE;
        }
        case 2:{
            const int MIN=17, MAX=20;
            const int SIZE=(rand()%(MAX-MIN+1))+MIN;
            cout<<"You have chosen Mastercard"<<endl;
            return SIZE;
        }
        case 3:{
            const int SIZE=16;
            cout<<"You have chosen American Express"<<endl;
            cout<<"This card has "<<SIZE-1<<" digits"<<endl;
            return SIZE;
        }
        case 4:{
            const int SIZE=17;
            cout<<"You have chosen Discover"<<endl;
            cout<<"This card has "<<SIZE-1<<" digits"<<endl;
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
    while(option<1||option>5){
        cout<<"Invalid Entry. Please try again.";
        cin>>option;
    }
    return option;
}    
