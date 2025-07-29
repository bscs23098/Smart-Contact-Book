#ifndef TRIES_H
#define TRIES_H
#include <iostream>
#include <string>

using namespace std;

class TriesNodes {
    TriesNodes* children[256];
    bool isEnd;

    void collectSuggestions(string wordSoFar) {
        if (isEnd) {
            cout << wordSoFar << endl;
        }
        for (int i = 0; i < 256; ++i) {
            if (children[i]) {
                char nextChar = static_cast<char>(i);
                children[i]->collectSuggestions(wordSoFar + nextChar);
            }
        }
    }

    bool hasNoChild() const {
        for (int i = 0; i < 256; i++) {
            if (children[i]) return false;
        }
        return true;
    }

    // Returns true if the node should be deleted, false otherwise.
    // Also sets found=true if the word was found and deleted, otherwise found=false.
    bool deleteWord(const string& word, int depth, bool& found) {
        if (depth == word.length()) {
            if (!isEnd) {
                found = false;
                return false;
            }
            isEnd = false;
            found = true;
            return hasNoChild();
        }
        unsigned char index = word[depth];
        if (!children[index]) {
            found = false;
            return false;
        }
        bool shouldDeleteChild = children[index]->deleteWord(word, depth + 1, found);
        if (shouldDeleteChild) {
            delete children[index];
            children[index] = nullptr;
            return !isEnd && hasNoChild();
        }
        return false;
    }

public:
    TriesNodes() : isEnd(false) {
        for (int i = 0; i < 256; i++) {
            children[i] = nullptr;
        }
    }
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
    bool search(const string& world) {
        TriesNodes* node = this;
        for (char ch : world) {
            int index = (unsigned char)ch;
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd;
    }
    void prefixSearch(const string& world) {
        TriesNodes* node = this;
        for (char ch : world) {
            int index = (unsigned char)ch;
            if (!node->children[index]) {
                cout << "No prefix found!\n";
                return;
            }
            node = node->children[index];
        }
        node->collectSuggestions(world);
    }
    void displayall() {
        TriesNodes* node = this;
        for (int i = 0; i < 256; i++) {
            if (node->children[i]) {
                char ch = static_cast<char>(i);
                node->children[i]->collectSuggestions(string(1, ch));
            }
        }
    }
    ~TriesNodes() {
        for (int i = 0; i < 256; ++i) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    bool deleteIt(const string& word) {
        bool found = false;
        deleteWord(word, 0, found);
        return found;
    }
};

#endif