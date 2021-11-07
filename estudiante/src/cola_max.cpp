/**
 * @file cola_max.cpp
 * @brief Main function to test the ADT of MaxQueue
 * @authors Álvaro Jesús Baena Rosino \n Alejandro Torres Martínez
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "maxqueue.h"

using namespace std;

int main(int argc, char *argv[]){

    // // Run the current exercise
    MaxQueue<int> queue;
    ifstream in;
    if (argv[1][0] == '.' && argv[1][1] == '/' || argv[1][0] == '/') { // Additional functionality: You can test the queue with a plain text file, apart from the default args entry
        in.open(argv[1]);
        if(in.good()) {
            while(!in.eof()) {
                string aux;
                in >> aux;
                if (aux[0] == '.'){
                    cout << queue.front() << endl;
                    queue.pop();
                } else {
                    queue.push_back(stoi(aux));
                }
            }
        } else {
            cerr << "Invalid file" << endl;
        }
    } else {
        for(int i = 1; i < argc; i++){
            if (argv[i][0] == '.'){
                cout << queue.front() << endl;
                queue.pop();
            } else {
                queue.push_back(atoi(argv[i]));
            }
        }
    }
    in.close();
    return 0;
}
