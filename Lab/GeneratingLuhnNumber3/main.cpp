/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on March 18, 2017, 6:00 PM
 * Purpose: Collect Stats on Valid/Invalid Credit Cards w/ Transpositions and
 *                  Flips
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int CrdCard(int &);
int SIZEpro(int);
void genCC(int,int[],int);
char rndDgit();
void prpLuhn(int,int[],int);
int Luhn(int[],int);
void chckDgt(int,int [],int);
void prntAry(int[],int);
void trnspse(int[],int);
void flipDgt(int[],int);
bool validCC(int[],int);

int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Initialize Counters
    int nLoops=0,count=0;
    //Declare Variables
    //Show Menu
    int choice=CrdCard(choice);
    int temp=choice;
    const int MIN=1,MAX=4;
    if(temp==5){
        temp=(rand()%(MAX-MIN+1))+MIN;
        cout<<"I have randomly chosen option "<<temp<<"."<<endl;
    } 
    else temp;
    do{
    temp;
    bool valid;
    //Get Array Size & Declare Array
    int SIZE=SIZEpro(temp);
    int crdCard[SIZE];
    //Prepare for Luhn encoding
    genCC(temp,crdCard,SIZE);
    //Transpose 2 Random Digits
    trnspse(crdCard,SIZE);
    //Flip 2 Random Digits
    flipDgt(crdCard,SIZE);
    //See if Card is still Valid
    valid=validCC(crdCard,SIZE);
    //Count Valid/Invalid Occurrences
    if(valid==false){
        count++;
    }
    nLoops++;
    }while(nLoops<10000);
    //Collect Stats
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Percentage of Invalid Cards: "<<(count/10000.0)*100<<"%"<<endl;
    cout<<"Percentage of Valid Cards: "<<((1-(count/10000.0))*100)<<"%"<<endl;
    
    //Exit Stage Right
    return 0;
}

bool validCC(int a[],int n){
    int val,sum;
    sum=Luhn(a,n);
//    cout<<sum<<endl;
    sum%10==0?val=true:val=false;
    return val;
}

void trnspse(int a[],int n){
    int MIN=0,MAX=n-2;
    
    //Transpose Digits
    for(int i=0;i<2;i++){
        int x=(rand()%(MAX+1));
        int y=x+1;
        //Swap
        a[x]=a[x]^a[y];
        a[y]=a[x]^a[y];
        a[x]=a[x]^a[y];
//        cout<<"Transposed: \n";
        prntAry(a,n);
    }
}

void flipDgt(int a[],int n){
    int MIN=0,MAX=n-1;
    
    //Perform Swap
    for(int i=0;i<2;i++){
        int x=(rand()%(MAX+1));
        int y=(rand()%(MAX+1));
        //Prevent the Same Random Number from Occurring
        while(x==y){
            y=(rand()%(MAX+1));
        }
        a[x]=a[x]^a[y];
        a[y]=a[x]^a[y];
        a[x]=a[x]^a[y];
//        cout<<"Swapped: \n";
        prntAry(a,n);
    }
}

void prpLuhn(int type,int cc[],int n){
    int start;
    switch(type){
        case 1:{
            cc[0]=4;
            start=1;
        }break;
        case 2:{
            int MIN=1,MAX=5;
            cc[0]=5,cc[1]=(rand()%(MAX-MIN+1))+MIN;
            start=2;
        }break;
        case 3:{
            int MIN=0,MAX=1;
            cc[0]=3;
            (rand()%MAX+1)==0?cc[1]=4:cc[1]=7;
            start=2;
        }break;
        case 4:{
            cc[0]=6,cc[1]=0,cc[2]=1,cc[3]=1;
            start=4;
        }break;
    }
    //Create a random cc in prep for Luhn checksum
    for(int i=start;i<n;i++){
        cc[i]=rndDgit();
    }
}

char rndDgit(){
    return rand()%10;
}

int Luhn(int cc[], int n){
    int card[n];
    int total=0;
    int num1,num2,temp;
    for(int i=0;i<n;i++){
        if(n%2==0){
            if(i%2==1){
                temp=cc[i]*2;
                num1=temp%10;
                num2=(temp-num1)/10;
                card[i]=num1+num2;
            }
            else{
                card[i]=cc[i];
            }
        }
        else if(n%2==1){
            if(i%2==0){
                temp=cc[i]*2;
                num1=temp%10;
                num2=(temp-num1)/10;
                card[i]=num1+num2;
            }
            else{
                card[i]=cc[i];
            }
        }
    }

    //Add all numbers
    for(int i=0;i<n;i++){
        total+=card[i];
    }
    return total;
}

void chckDgt(int s,int a[],int n){
    int Luhn=0;
    //Calculate Luhn Digit
    Luhn=(s*9)%10;
    
    //Input Luhn Digit in Array
    for(int i=n;i<n+1;i++){
        a[n]=Luhn;
    }
}

void prntAry(int cc[], int size){
    for(int i=0;i<size;i++){
        cc[i];
    }
//    cout<<endl;
    
}

void genCC(int option,int a[],int n){
    int sum;
//    cout<<"A random number created in Prep for Luhn Digit: "<<endl;
    prpLuhn(option,a,n-1);
    //Output the preLuhn credit card
    prntAry(a,n-1);
    
    //Now create a function that fills the last digit
    //using the Luhn Algorithm
    sum=Luhn(a,n-1);
    chckDgt(sum,a,n-1);
    
//    cout <<"Card number with Luhn Digit: " <<endl;
    prntAry(a,n);
}

int SIZEpro(int option){
    switch(option){
        case 1:{
            const int MIN=13, MAX=16;
            int SIZE=(rand()%(MAX-MIN+1))+MIN;
//            cout<<"You have chosen Visa."<<endl;
//            cout<<"This card has "<<SIZE<<" digits"<<endl;
            return SIZE;
        }
        case 2:{
            const int MIN=16, MAX=19;
            const int SIZE=(rand()%(MAX-MIN+1))+MIN;
//            cout<<"You have chosen Mastercard"<<endl;
//            cout<<"This card has "<<SIZE<<" digits"<<endl;
            return SIZE;
        }
        case 3:{
            const int SIZE=15;
//            cout<<"You have chosen American Express"<<endl;
//            cout<<"This card has "<<SIZE<<" digits"<<endl;
            return SIZE;
        }
        case 4:{
            const int SIZE=16;
//            cout<<"You have chosen Discover"<<endl;
//            cout<<"This card has "<<SIZE<<" digits"<<endl;
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