//
//  main.cpp
//  tetelek
//
//  Created by sdaniel on 13/02/16.
//  Copyright © 2016 Daniel Spindelbauer. All rights reserved.
//


//
// TODO
//  - Choose input method (random array - manual array - array from file)
//  - Make array from file
//  - Figure out why doesn't 8 work, when it has a manual array
//  - Fix 7

#include <iostream>
#include <fstream>
using namespace std;

// Global variables
    // Initiating user input
    int userInput;

    // Initiating array
    int a[10];
    // int a[10]={1,11,314,2,5,5,7,8,14,22}; // Manual array

    // Get size of (global) 'a' array
    int aSize = sizeof(a)/sizeof(a[0]);


    // ifstream readFile("fileInput.txt");
    // ofstream writeFile("fileInput.txt");

// ------------------------


int printA(){
    for (int c=0; c < aSize; c++) {
        // Don't print comma after the last element of the array
        if (aSize-1 != c) {
            cout<<a[c]<<", ";
        } else {
            cout<<a[c]<<endl;
        }
    }
    
    return 0;
}

int osszegzes(){ // 1
    int sum=0;
    for (int i=0; i<aSize; i++) {
        sum+=a[i];
    }
    cout<<"Tomb osszege: "<<sum<<endl;
    
    return 0;
}

int faktorialis(){ // 10
    int fakt;
    cout<<"Hany faktorialis: ";
    cin>>fakt;
    int result=1;
    
    for (int i=2; i<=fakt; i++) {
        result*=i;
    }
    cout<<result<<endl;
    
    return 0;
}

int eldontes(){ // 2
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
    
    return 0;
}

int kivalasztas(){ // 3
    // Bigger than 10
    const int cond=10; // Condition
    int i=0;
    while (a[i]<cond) {
        i++;
    }
    cout<<"10-nel nagyobb elem az "<<i+1<<". elem"<<endl;
    
    return 0;
}

int linearis_kereses(){ // 4
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
    
    return 0;
}

int megszamlalas(){ // 5
    // Bigger than 10
    int sum=0;
    const int cond=10; // Condition
    for (int i=0; i<aSize; i++) {
        if (a[i]>cond) {
            sum++;
        }
    }
    cout<<sum<<" darab 10-nel nagyobb elem van a tombben"<<endl;

    return 0;
}

int maximumkivalasztas(){ // 6
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
    
    return 0;
}

int kivalogatas(){ // 7
    
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
    
    return 0;
}

int buborekrendezes(){ // 8
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
    
    return 0;
}

int kozvetlen_kivalasztas(){ // 9
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
    
    return 0;
}



int fileAction(){ // 11
    
    // ==============
    //      TODO
    // ==============
    
    return 0;
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
    
    // Filling up the 'a' array
    for (int i=0; i<10; i++) {
        // Change this to change the output
        a[i] = rand() % 50 + 1;
    }
    
    // Printing array items
    for (int c=0; c < aSize; c++) {
        // Don't print comma after the last element of the array
        if (aSize-1 != c) {
            cout<<a[c]<<", ";
        } else {
            cout<<a[c]<<endl;
        }
    }

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

