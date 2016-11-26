//
//  main.cpp
//  MaxHeap
//
//  Created by ZiShane on 2016/11/24.
//  Copyright © 2016年 ZiShane. All rights reserved.
//

#include <iostream>
using namespace std;

#define Max_Heap 100
int heap[Max_Heap] = {'\0'}, current = 0;

bool isEmpty();
bool isFull();
void push(int insert_Num);
int pop();
void print_heap();

int main(int argc, const char * argv[]) {
    
    while (1) {
        system("clear");
        
        cout << "1. insert a number" << endl;
        cout << "2. delete max" << endl;
        cout << "3. print heap" << endl;
        cout << "4. exit program" << endl;
        
        short chose_funs = 0;
        cout << "choose a function you want : ";
        cin >> chose_funs;
        cout << "the number you have chose is " << chose_funs << endl;
        
        int insert_number = 0;
        if (chose_funs == 1) {
            
            if (isFull()) {
                cout << "the heap is FULL!" <<endl;
                continue;
            }
            
            cout << "input a number which you want to add : ";
            cin >> insert_number;
            
            push(insert_number);
            
        } else if (chose_funs == 2) {
            if (isEmpty()) {
                cout << "the heap is EMPTY!" << endl;
                continue;
            }
            
            pop();
            
        } else if (chose_funs == 3) {
            if (isEmpty()) {
                cout << "the heap is EMPTY!" << endl;
                continue;
            }
            
            print_heap();
            
        } else if (chose_funs == 4) {
            break;
            
        } else {
            cout << "Error!!\nPlease input the number at the range of 1-4, Try again" << endl;
            cout << "choose a function you want : ";
            cin >> insert_number;
        }
    }
    
    cout << "ByeBye!" << endl;
    
    return 0;
}

bool isEmpty() {
    if (current > 0)
        return false;
    else
        return true;
}

bool isFull() {
    if (current + 1 > Max_Heap)
        return true;
    else
        return false;
}

void push(int insert_Num) {
    
}

int pop() {
    return heap[current];
}

void print_heap() {

}
