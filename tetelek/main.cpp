//
//  main.cpp
//  tetelek
//
//  Created by sdaniel on 13/02/16.
//  Copyright © 2016 Daniel Spindelbauer. All rights reserved.
//


//
// TODO
//  - Make array from file
//  + Figure out why doesn't 8 work
//  + Fix 7

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

#include <fstream>
using namespace std;

// Global variables/* time */
    // Initiating user input
    int userInput;

    // Initiating array
    int a[10];

    // Get size of (global) 'a' array
    int aSize = sizeof(a)/sizeof(a[0]);

    // Inintiating file handling
    fstream fromFileInput("fileInput.txt");
// ========================================
// ========================================


void manualArray(){
    // Filling up the 'a' array
  //  for (int i=0; i<aSize; i++) {
  //      a[i]=i*2;
  //  }

    a[0]=1; a[1]=11; a[2]=314; a[3]=2; a[4]=5; a[5]=5; a[6]=7; a[7]=8; a[8]=14; a[9]=22;
}

void randomArray(){
    // Initiating randomization
    srand (time(NULL));

    // Filling up the 'a' array
    for (int i=0; i<10; i++) {
        a[i] = rand() % 50 + 1;
    }
}

void fromFileArray(){
    string lineFromFile;

    if (fromFileInput.is_open()){
        while (!fromFileInput.eof()){
            cout << lineFromFile << '\n';
            getline(fromFileInput,lineFromFile);
        }
    } else{
        cout<<"Unable to open file"<<endl;
    }

    // Add lineFromFile to the 'a' array
    for(int i=0;i<aSize*3;i+=3){
        a[i]=lineFromFile.substr(i, 3);
    }

//
//  get input into int and put them into array instead of a var
//
    // Delete comma and space from the end of the elements
    for(int i=0;i<aSize;i++){
        string temp="";
        temp=a[i].substr(1, 1);
        a[i]=stoi(temp);
    }
}

void printA(){ // Prints 'a' array
    for (int c=0; c < aSize; c++) {
        // Don't print comma after the last element of the array
        if (aSize-1 != c) {
            cout<<a[c]<<", ";
        } else {
            cout<<a[c]<<endl;
        }
    }
}

void osszegzes(){ // 1
    int sum=0;
    for (int i=0; i<aSize; i++) {
        sum+=a[i];
    }
    cout<<"Tomb osszege: "<<sum<<endl;
}

void faktorialis(){ // 10
    int fakt;
    cout<<"Hany faktorialis: ";
    cin>>fakt;
    int result=1;

    for (int i=2; i<=fakt; i++) {
        result*=i;
    }
    cout<<result<<endl;
}

void eldontes(){ // 2
    // Bigger than 10
    const int cond=10; // Condition
    int i=0;
    // Search for the correct element
    while(i < aSize && a[i]<cond){
        i++;
    }
    // Insepcting whether it's found it or not
    if(i < aSize){
        cout<<"van benne 10-nel nagyobb elem"<<endl;
    } else {
        cout<<"nincs benne 10-nel nagyobb elem"<<endl;
    }
}

void kivalasztas(){ // 3
    // Bigger than 10
    const int cond=10; // Condition
    int i=0;
    while (a[i]<cond) {
        i++;
    }
    cout<<"10-nel nagyobb elem az "<<i+1<<". elem"<<endl;
}

void linearis_kereses(){ // 4
    // Bigger than 10
    const int cond=10; // Condition
    int i=0;
    while (i<aSize && a[i]<cond) {
        i++;
    }
    if (i<aSize) {
        cout<<"10-nel nagyobb elem az "<<i+1<<". elem"<<endl;
    } else {
        cout<<"Nincs 10-nel nagyobb elem a tombben"<<endl;
    }
}

void megszamlalas(){ // 5
    // Bigger than 10
    int sum=0;
    const int cond=10; // Condition
    for (int i=0; i<aSize; i++) {
        if (a[i]>cond) {
            sum++;
        }
    }
    cout<<sum<<" darab 10-nel nagyobb elem van a tombben"<<endl;
}

void maximumkivalasztas(){ // 6
    // !!! maxPos has to be the same type as the array !!!

    // Initiating the position of the largest element
    int maxPos=a[0];

    // Inspecting array for the largest element
    for (int c=1; c < aSize; c++) {
        // Checking whether the current element is larger than the current largestt
        if (a[maxPos] < a[c]) {
            maxPos=c;
        }
    }
    cout<<"Az elso legnagyobb elem: "<<a[maxPos]<<". Helye: "<<maxPos+1<<endl;
}

void kivalogatas(){ // 7

    // Bigger than 10
    const int cond=10; // Condition

    // Secondary array
    int b[aSize];               // How big should it be?

    int j=-1; // Secondary array's index
    for (int i=0; i<aSize; i++) {
        if (a[i]>cond) {
            j++;
            b[j]=i+1;
        }
    }

    // Printing 'b' array
    // The end var is the 'b' array's counter ('j')
    for (int c=0; c < (j+1); c++) {
        // Don't print comma after the last element of the array
        if (j != c) {
            cout<<b[c]<<", ";
        } else {
            cout<<b[c]<<endl;
        }
    }
}

void buborekrendezes(){ // 8
    int temp;
    for (int i=0; i<aSize-1; i++) {
        for (int j=0; j<aSize-i-1; j++) {
            // Swap two elements if the condition's true
            if (a[j]>a[j+1]) {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }


    // ============= BUG =============
    //
    // ============= BUG =============

    // Printing 'a' array
    printA();
}

void kozvetlen_kivalasztas(){ // 9
    int temp;

    for (int i=0; i<aSize-1; i++) {
        for (int j=i+1; j<aSize; j++) {
            // Swap two elements if the condition's true
            if (a[j]<a[i]) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    // Printing 'a' array
    printA();
}



void fileAction(){ // 11

    // ==============
    //      TODO
    // ==============

}


int chooseInp(){
    // Asking user for input

    cout<<"1. Megadott tomb"<<endl;
    cout<<"2. Veletlen tomb"<<endl;
    cout<<"3. Fajlbol"<<endl;
    cout<<"Forras tipusa: ";
    cin>>userInput;

    return userInput;
}

int userInp(){
    // Asking user for input

    cout<<"Tetel szama: ";
    cin>>userInput;

    return userInput;
}


int main(){
    chooseInp();
    // Choose input method
    switch (userInput) {
        case 1:
            manualArray();
            break;
        case 2:
            randomArray();
            break;
        case 3:
            fromFileArray();
            break;
        default:
            userInp();
            break;
    }

    // Print 'a' array
    printA();

    userInp();
    // Menu for the user input
    switch (userInput) {
        case 1:
            osszegzes();
            break;
        case 2:
            eldontes();
            break;
        case 3:
            kivalasztas();
            break;
        case 4:
            linearis_kereses();
            break;
        case 5:
            megszamlalas();
            break;
        case 6:
            maximumkivalasztas();
            break;
        case 7:
            kivalogatas();
            break;
        case 8:
            buborekrendezes();
            break;
        case 9:
            kozvetlen_kivalasztas();
            break;
        case 10:
            faktorialis();
            break;
        case 11:
            fileAction();
            break;
        default:
            userInp();
            break;
    }

    // STARTS AFTER THIS
    // ------------------

    // Closing file handling
    fromFileInput.close();
    return 0;
}

