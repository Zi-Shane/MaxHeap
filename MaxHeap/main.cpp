//
//  main.cpp
//  MaxHeap
//
//  Created by ZiShane on 2016/11/24.
//  Copyright © 2016年 ZiShane. All rights reserved.
//

#include <iostream>
using namespace std;

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
            cout << "input a number which you want to add : ";
            cin >> insert_number;
            //insert()
        } else if (chose_funs == 2) {
            //delete()
        } else if (chose_funs == 3) {
            //print_heap()
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
