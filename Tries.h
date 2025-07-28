#ifndef TRIES_H
#define TRIES_H
#include <iostream>
#include <string>

using namespace std;

class TriesNodes{
    TriesNodes* children[26];
    bool isEnd;
public:
    TriesNodes():isEnd(false) {  
        for (int i =0;i<26;i++){
            children[i]=nullptr;    
        }
    }
    // add world 
     void InsertWord(const string& world) {
        TriesNodes* node = this;
        for (char ch : world) {
            if (!isalpha(ch)) continue;
            int index = tolower(ch) - 'a';
            if (index < 0 || index >= 26) continue; 
            if (!node->children[index]) {
                node->children[index] = new TriesNodes();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    bool search(const string& world){
        TriesNodes* node = this;
        for (char ch: world){
            if(!isalpha(ch)){ continue; }
            int index = tolower(ch) - 'a';
            if(index < 0 || index >= 26) return false;
            if (!node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
   

};

#endif