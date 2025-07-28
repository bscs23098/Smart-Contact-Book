#include<iostream>
#include<string>
#include "Tries.h"

using namespace std;
int main(){
    TriesNodes obj;
    string name = "M Zohaib Sajjad";
    obj.InsertWord(name);
    if(obj.search(name)){
        cout<<name <<" is avaliable\n";
    }
    else {
        cout<<name <<" is not avaliable\n";
    }
    return 0;
}