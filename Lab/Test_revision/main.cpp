#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
int CrdCard(int &);
const int SIZEpro(int);
char rndDgit();
void prpLuhn(int[],int);
void Luhn(int[],int);
void outAry(int[],int);

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int choice;
    const int MIN=1,MAX=4;
    //Show Menu
    CrdCard(choice);
    if(choice==5)
        choice=(rand()%(MAX-MIN+1))+MIN;
    //Get Array Size & Declare Array
    const int SIZE=SIZEpro(choice);
    int crdCard[SIZE];
    //Prepare for Luhn encoding
    cout<<"A random number created in Prep for Luhn Digit: "<<endl;
    prpLuhn(crdCard,SIZE-2);
    //Output the preLuhn credit card
    //cout<<crdCard<<endl;
    outAry(crdCard, SIZE-2);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    Luhn(crdCard,SIZE-2);
    
    cout <<"Card number with Luhn Digit: " <<endl;
    outAry(crdCard,SIZE-1);
    
    //Exit Stage Right
    return 0;
}

void prpLuhn(int cc[],int n){
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
    return rand()%10;
}

void Luhn(int cc[], int n){
    int cardNum[n];
    int digit=0;
    for(int i = 0; i < n; i++){
        //For every other element
        if(n%2==0){
            if(i%2 != 0){
                //Double the value
                int temp = cc[i]*2;
                //cout <<"Doubled: " <<cc[i] <<" to " <<temp <<endl;

                //Find the digits
                int d1 = temp%10;
                int d2 = (temp-d1)/10;

                //Sum the digits
                cardNum[i] = d1+d2;
                //cout <<"Digit sum: " <<cardNum[i] <<endl;
            }
            else{
                //Copy card contents
                cardNum[i] = cc[i];
            }
        }
        else if(n%2==1){
            if(i%2 == 0){
                //Double the value
                int temp = cc[i]*2;
                //cout <<"Doubled: " <<cc[i] <<" to " <<temp <<endl;

                //Find the digits
                int d1 = temp%10;
                int d2 = (temp-d1)/10;

                //Sum the digits
                cardNum[i] = d1+d2;
                //cout <<"Digit sum: " <<cardNum[i] <<endl;
            }
            else{
                //Copy card contents
                cardNum[i] = cc[i];
            }
        }
    }
    
    //Sum the digits
    int total = 0;
    for(int i = 0; i < n; i++){
        total += cardNum[i];
    }
    //cout <<"Total sum: " <<total <<endl;
    
    //Calculate check digit
    digit = (total*9)%10;
    
    //cout <<"Final digit: " <<digit <<endl;
    
    //Insert final value to original array
    for(int i = n; i < n+1; i++){
        cc[n] = digit;
    }
    
}

void outAry(int cc[], int size){
    //Output array
    for(int i = 0; i < size; i++){
        cout <<cc[i];
    }
    cout <<endl;
    
}

const int SIZEpro(int option){
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