#ifndef TRIES_H
#define TRIES_H
#include <iostream>
#include <string>

using namespace std;

class TriesNodes{
    TriesNodes* children[256];
    bool isEnd;
    void collectSuggestions(string wordSoFar) {
        if (this->isEnd) {
            cout << wordSoFar << endl;
        }
        for (int i = 0; i < 256; ++i) {
            if (this->children[i]) {
                char nextChar = static_cast<char>(i);
                this->children[i]->collectSuggestions(wordSoFar + nextChar);
            }
        }
    }
    bool deleteWord(TriesNodes* node,string word,int depth){
        if(node==nullptr){ return false; }
        if(depth == word.length() ){
            if(!node->isEnd) { return false;}
            node->isEnd=false;
            return node->hasNoChild();
        }
        char ch=word[depth];
        int index = static_cast<unsigned char>(ch);
        bool shouldDeleteChild = deleteWord(node->children[index], word, depth + 1);        
        if (shouldDeleteChild) {
            delete node->children[index];
            node->children[index] = nullptr;
            return !node->isEnd && node->hasNoChild();
        }
        return false;
    }
    bool hasNoChild() const {
        for(int i=0;i<256;i++){
            if(children[i]) return false;
        }
        return true;
    }
public:
    TriesNodes():isEnd(false) {  
        for (int i =0;i<256;i++){
            children[i]=nullptr;    
        }
    }
    // add world 
     void InsertWord(const string& world) {
        TriesNodes* node = this;
        for (char ch : world) {
            int index = (unsigned char)ch;
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
            int index = (unsigned char)ch;
            if (!node->children[index]){
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
    void prefixSearch(const string& world){
        TriesNodes* node = this;
        for (char ch: world){
            int index = (unsigned char) ch;
            if (!node->children[index]){
                cout<<"No prefix found!\n";
            }
            node = node->children[index];
        }
        node->collectSuggestions(world);
    }
    void displayall(){
        TriesNodes * node = this;
        for(int  i=0;i<256;i++){
            if(node->children[i]){
                char ch = static_cast<char>(i);
                node->children[i]->collectSuggestions(string(1,ch));
            }
        }
    }
    ~TriesNodes() {
    for (int i = 0; i < 256; ++i) {
        if (children[i]) {
            delete children[i]; // Recursively deletes all children
        }
    }
    }
    bool deleteIt(const string& word){
        return deleteWord(this,word,0);
    }

};

#endif