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

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE=4;
    int array[SIZE];         //Array of the Code
    int brray[SIZE];         //Array of the Guess
    int black=0,white=0,count=0;
    int guess;
    
    //Intro
    cout<<"Let's play a game of Mastermind. The object of the game is to ";
    cout<<"guess the 4-digit code that is comprised of the numbers 1-6."<<endl;
    fillAry(array,SIZE);
    cout<<"The computer just picked the code. Time for you to guess!"<<endl;
    cout<<"Guess #"<<count+1<<": ";
    cin>>guess;    
    
    //Exit Stage Right!
    return 0;
}

int *fillAry(int *a,const int n){
    //Declare Minimum and Maximum Values to Choose
    const int MIN=1, MAX=6;
    
    for(int i=0;i<n;i++)
        *(a+i)=(rand()%(MAX-MIN+1))+MIN;
    
    return a;
}

