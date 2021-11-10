/*
ternary converter
only works with values between -364 and 364
*/

#include <iostream>
#include <cmath>
using namespace std;

void ternaryConverter(int x, int ternary[]){
    //x is the value to be converted
    //y is the value to be returned
    string y = "------";
    bool neg = false;

    if(x < 0){
        neg = true;
    }

    //first int if number is > 243
    if(abs(x) >= 243){
        ternary[0] = 1;
        x = abs(x) - 243;
    }

    //next is more than 81
    if(abs(x) >= 81){
        ternary[1] = 1;
        x = abs(x) - 81;
        if(x >= 81){
            ternary[1] = 2;
            x = x - 81;
        }
    }

    //more than 27
    if(abs(x) >= 27){
        ternary[2] = 1;
        x = abs(x) - 27;
        if(x >= 27){
            ternary[2] = 2;
            x = x -27;
        }
    }

    //more than 9
    if(abs(x) >= 9){
        ternary[3] = 1;
        x = abs(x) - 9;
        if(x >= 9){
            ternary[3] = 2;
            x = x - 9;
        }
    }

    //more than 3
    if(abs(x) >= 3){
        ternary[4] = 1;
        x = abs(x) - 3;
        if(x >= 3){
            ternary[4] = 2;
            x = x - 3;
        }
    }

    //more than 1 leftover
    if(abs(x) >= 1){
        ternary[5] = 1;
        x = abs(x) - 1;
        if(x == 1){
            ternary[5] = 2;
        }
    }

    cout << "Un-Balanced { ";
    for(int i = 0; i < 6; i++){
        cout << ternary[i] << " ";
    }
    cout << "}" << endl;

    
    //now we convert ternary(0, 1, 2) into balenced ternary (-1, 0, 1)
    for(int i = 5; i >= 0; i--){
        if(ternary[i] == 3){
            ternary[i] = 0;
            ternary[i-1] = ternary[i-1] + 1;
        }else if(ternary[i] == 2){
            ternary[i] = -1;
            ternary[i-1] = ternary[i-1] + 1;
        }
    }
    
    
    //if intial number was neg we invert all the signs
    if(neg == true){
        for(int i = 0; i < 6; i++){
            if(ternary[i] == 1){
                ternary[i] = -1;
            }else if(ternary[i] == -1){
                ternary[i] = 1;
            }
        }
    }
}


//test
//print array 
void printArray(int s, int alpha[]){
    cout << "Balanced { ";
    for(int i = 0; i < s; i++){
        cout << alpha[i] << " ";
    }
    cout << "}" << endl;
}


int main(){
    //vars
    int x;
    int ternary[6] = {0, 0, 0, 0, 0, 0};

    //user input
    cout << "Enter a number between -364 and 364 or -999 to quit: ";
    cin >> x;

    while(x != -999){
        ternaryConverter(x, ternary);

        //test 
        printArray(6, ternary);

        //reseting the array
        for(int i = 0; i < 6; i++){
            ternary[i] = 0;
        }

        //user input
        x = 0;
        cout << "Enter a number between -364 and 364 or -999 to quit: ";
        cin >> x;
    }

}