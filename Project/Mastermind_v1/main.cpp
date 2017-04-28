/* 
 * File:   main.cpp
 * Author: Laurie Guimont
 * Created on April 13, 2017, 11:23 PM
 * Purpose: Mastermind AI
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototypes
int *fillAry(int *,const int);
int *guesAry(int *,int,const int);
int compare(int *,int *,int);
void *prntAry(int *,const int);
int search(int *,int *,const int,int);
bool check(int *,int *,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=4;
    int array[SIZE];         //Array of the Code
    int brray[SIZE];         //Array of the Guess
    int count=0;
    int guess;
    
    //Intro
    cout<<"Let's play a game of Mastermind. The object of the game is to ";
    cout<<"guess the 4-digit code that is comprised of the numbers 1-6."<<endl;
    fillAry(array,SIZE);
    cout<<"The computer just picked the code. Time for you to guess!"<<endl;
    
    //Start Guessing
    do{
    cout<<"Guess #"<<count+1<<": ";
    cin>>guess;    
    
    //Put Guess in an Array
    guesAry(brray,guess,SIZE);
    compare(array,brray,SIZE);
    count++;
    }while(count<7);
    
    prntAry(array,SIZE);
    
    //Exit Stage Right!
    return 0;
}

bool check(int *a,int *b,int temp,int i){
    int index=0;
    bool found=false;
    while(index<=i&&!found){
        if(b[temp]==a[index])
            found=true;
        index++;
    }
    return found;
}

int search(int *a,int *b,const int n,int i){  //linear search
    int index=0;
    int position=-1;
    bool found=false;
    while(index<n&&!found){
        if(b[i]==b[index]){
            found=true;
            position=index;
        }
        index++;
    }
    return position;
} 

void *prntAry(int *a,const int n){
    for(int i=0;i<n;i++)
        cout<<*(a+i)<<" ";
}

int compare(int *a,int *b,const int n){
    int black=0,white=0;
    int count=0;
    
    for(int i=0;i<n;i++){
        if(b[i]==a[i])
            black++;
        else if(b[i]!=a[i]){
            for(int j=0;j<n;j++){
                if(b[i]==a[j]){
                    if(count<1){
                        int temp=search(a,b,n,i);
                        bool shemp=true;
                        shemp=check(a,b,temp,i);
                        if(temp<0&&shemp!=true)
                            white++;
                    }
                }
            }                                
        }
        count=0;
    }
    
    cout<<"Black: "<<black<<endl;
    cout<<"White: "<<white<<endl;
}


int *guesAry(int *b,int a,const int n){    
    //Fill Guess Array
    *(b+0)=a/1000;
    *(b+1)=(a/100)-(*(b+0)*10);
    *(b+2)=(a/10)-(*(b+0)*100)-(*(b+1)*10);
    *(b+3)=a%10;
    
    return b;
}

int *fillAry(int *a,const int n){
    //Declare Minimum and Maximum Values to Choose
    const int MIN=1, MAX=6;
    
    for(int i=0;i<n;i++){
        *(a+i)=(rand()%(MAX-MIN+1))+MIN;
        cout<<*(a+i)<<" ";
    }
    
    return a;
}