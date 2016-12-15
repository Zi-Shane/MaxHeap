//
//  main.cpp
//  MaxHeap
//
//  Created by ZiShane on 2016/11/24.
//  Copyright © 2016年 ZiShane. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define Max_Heap 100                              //  Heap's capability equal to (Max_Heap - 1),
                                                  //  The first position in the heap is heap[1].
int heap[Max_Heap] = {'\0'}, current = 0;

bool isEmpty();
bool isFull();
void push();
void pop();
void print_heap();

int main() {
    
    cout << "This is a MaxHeap program\n\n" << endl;
    
    string chose_funs = "";
    while (true) {
        cout << "***********************" << endl;
        cout << "1. Insert a number" << endl;
        cout << "2. Delete max" << endl;
        cout << "3. Print heap" << endl;
        cout << "4. Exit program" << endl;
        
        cout << "Choose a function you want : ";
        cin >> chose_funs;
        cout << endl;
        
        //  1. Insert a number
        if (chose_funs == "1\0") {
            push();
            cout << "\n\n";
        }
        //  2. Delete max
        else if (chose_funs == "2\0") {
            pop();
            cout << "\n\n";
        }
        //  3. Print heap
        else if (chose_funs == "3\0") {
            print_heap();
            cout << "\n\n";
        }
        //  4. Exit
        else if (chose_funs == "4\0") {
            cout << "\n\n";
            break;
        }
        //  >4. ERROR
        else {
            cout << "\nError!!\nPlease input the number at the range of 1-4, Try again\n\n";
        }
    }
    
    cout << "ByeBye!" << endl;
    
    return 0;
}



//Heap functions
bool isEmpty() {
    if (current - 1 < 0)
        return true;
    else
        return false;
}

bool isFull() {
    if (current + 1 > Max_Heap - 1)
        return true;
    else
        return false;
}

void push() {
    int insert_Num;
    int i = NULL;
    
    if (isFull()) {
        cout << "The heap is FULL!" << endl;
        return;
    }
    
    cout << "Input a number which you want to add : ";
    cin >> insert_Num;
    if (cin.fail()) {       //  input non-number
        cin.clear();        //  clear error state
        cin.ignore();       //  eat error input in the buffer
        return;
    }
    
    i = ++current;          //  ++current means create a hole,
    //  i means where is the hole
    
    //percolate hole up
    while (i != 1 && insert_Num > heap[i/2]) {
        heap[i] = heap[i/2];        //  parent move down,
        i /= 2;                     //  hole move up
    }
    heap[i] = insert_Num;
}

void pop() {
    int parent = 1, child = 2;
    int temp = NULL;
    
    if (isEmpty()) {
        cout << "The heap is EMPTY!" << endl;
        return;
    }
    
    cout << "Delete the max => " << heap[1] << endl;
    temp = heap[current];         //  store last number
    heap[current--] = '\0';       //  delete the hole
    
    if (current + 1 != 1) {       //  if deleted position IS NOT the only one in the heap
    //slide down hole
    while (child <= current) {
        if (heap[child] < heap[child + 1])      //  find the bigger child
            child++;
        if (temp > heap[child])                 //  last number find correct position
            break;
        heap[parent] = heap[child];             //
        parent = child;                         //  slide down hole
        child *= 2;                             //  find new child
    }
    heap[parent] = temp;          //  put last number into hole
    } else                        //  if delete position IS the only one in the heap
        heap[1] = '\0';
}

void print_heap() {
    if (isEmpty())
        cout << "The heap is EMPTY!" << endl;
    
    cout << "-----------------------" << endl;
    for (int i = 1; heap[i] != '\0' && i < Max_Heap; i++) {
        cout << "Node" << i << "\t->\t" << "Value = " << heap[i] << endl;
    }
    cout << "-----------------------" << endl;
}
