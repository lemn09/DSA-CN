#include<iostream>
using namespace std;

// Trie Class to implement dictionary

class TrieNode{
    public:
        char data;
        TrieNode **children;
        // for determination of lastChar
        bool isTerminal;

        TrieNode(char ch){
            data= ch;
            // as each node(char) can have max. 26 children
            children= new TrieNode*[26];
            for(int i=0; i<26; i++){
                children[i]= NULL;
            }
            isTerminal= false;
        }

        ~TrieNode(){
            for(int i=0; i<26; i++){
                delete children[i];
            }
            delete []children;
        }
};


class Trie{
    private:
        TrieNode *root;

    public:
        Trie(){
            root= new TrieNode('\0');
        }

    private:

        void insertWord(TrieNode *node, string word){
            // base Case
            if(word.empty()){
               node->isTerminal= true;
                return;
            }


            // Small Calclulation: Search for first char of word
           
            // a-> 0, b->1, c->2(index).......
            int firstCharIndex= word[0] - 'a';
            TrieNode *child;
            
            // if firstChar exits then child= firstChar
            if(node->children[firstCharIndex] != NULL){
                child= node->children[firstCharIndex];
            }
            // else create a new TrieNode with for first Char and connect it with root
            else{      
                child= new TrieNode(word[0]);
                node->children[firstCharIndex]= child;
            }
            
            // recursive call
            
            insertWord(child, word.substr(1));
        }

        bool search(TrieNode *node, string word){
            if(word.empty()){
                return node->isTerminal == true;
            }

            int firstCharIndex= word[0] - 'a';
            if(node->children[firstCharIndex] != nullptr){
                return search(node->children[firstCharIndex], word.substr(1));
            }else{
                return false;
            }
        }

        void removeWord(TrieNode *node, string word){
            if(word.empty()){
                node->isTerminal = false;
                return;
            }

            TrieNode* child= nullptr;
            int firstCharIndex= word[0] - 'a';
            if(node->children[firstCharIndex] != NULL){
                child= node->children[firstCharIndex];
            }else{
                // char of word not found
                return;
            }

            removeWord(child, word.substr(1));
            
            
            // removing useless nodes
            if(child->isTerminal == false){
                for(int i=0; i<26; i++){
                    if(child->children[i] != NULL){
                        return;
                    }
                }
            }
            delete child;
            node->children[firstCharIndex]= NULL;
        }

    public:
        bool search(string word){
            return search(root, word);
        }

        void insertWord(string word){
            // insertWord(root, word);
            insertWord(root, word);
        }

        

        void removeWord(string word){
            removeWord(root, word);
        }
};

int main(){
    Trie t;
    string str= "HelloWorld";
    t.insertWord(str);
    for(int i=0; i<str.length(); i++){
        string word= (str.substr(i));
        cout<<word<<": "<<t.search(word)<<endl;
    }
}