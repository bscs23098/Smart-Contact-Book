#include<iostream>
#include<string>
#include "Tries.h"

using namespace std;
int main(){
    TriesNodes obj;
    string name = "M Zohaib Sajjad";
    obj.InsertWord(name);
    obj.InsertWord("Ali");
    obj.InsertWord("Zohair");
    obj.InsertWord("Aliha");
    if(obj.search(name)){
        cout<<name <<" is avaliable\n";
    }
    else {
        cout<<name <<" is not avaliable\n";
    }
    string ch;
    cout<<"Enter name : ";
    getline(cin, ch);
    obj.prefixSearch(ch);
    cout<<"\nAll Names:\n";
    obj.displayall();
    if(obj.deleteIt("Zohair")){
        cout<<"Is Deleted\n";
    }
    else {
        cout<<"Is Not Deleted\n";
    }
    return 0;
}