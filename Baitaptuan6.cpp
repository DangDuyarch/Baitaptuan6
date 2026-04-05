#include <iostream>
#include <string>

using namespace std;

struct File{        //Khai bao cau truc file
    string name;
    double size; 
    long time;   };

struct Node{
    File data;
    Node* next;};
