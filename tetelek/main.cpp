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
//  - Figure out why doesn't 8 work
//  - Fix 7

#include <iostream>
#include <fstream>
using namespace std;

// Global variables
    // Initiating user input
    int userInput;

    // Initiating array
    int a[10];

    // Get size of (global) 'a' array
    int aSize = sizeof(a)/sizeof(a[0]);

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
    // Filling up the 'a' array
    for (int i=0; i<10; i++) {
        a[i] = rand() % 50 + 1;
    }
}

void fromFileArray(){
    // Filling up the 'a' array
    for (int i=0; i<aSize; i++) {
        // Here goes the content of the file
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
    
    // ============= FAILED =============
    //  I don't know what it's doing...
    // ============= FAILED =============
    
    // Bigger than 10
    const int cond=10; // Condition
    
    // Secondary array
                        // How big should it be?
    int b[aSize];
    
    // ============= BUG =============
    // It'll print the trash after the result, because I can't specify its size.
    // ============= BUG =============
    
    // Secondary array's index
    int j=-1;
    for (int i=0; i<aSize; i++) {
        if (a[i]>cond) {
            j++;
            b[j]=i+1;
        }
    }
    
    // Get size of 'b' array
                                // Doesn't know which type the 'b' array will be
    int bSize = sizeof(b)/sizeof(b[0]);
    
    // Printing 'b' array
    for (int c=0; c < bSize; c++) {
        // Don't print comma after the last element of the array
        if (bSize-1 != c) {
            cout<<b[c]<<", ";
        } else {
            cout<<b[c]<<endl;
        }
    }
}

void buborekrendezes(){ // 8
    int temp;
    for (int i=0; i<aSize-1; i++) {
        for (int j=0; j<aSize-i; j++) {
            // Swap two elements if the condition's true
            if (a[j]>a[j+1]) {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    
    
    // ============= BUG =============
    //  Why the f*ck doesn't it print it when it has a manual array?!
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
    // Initiating randomization
    srand (time(NULL));

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
    
    // readFile.close();
    // writeFile.close();
    return 0;
}

