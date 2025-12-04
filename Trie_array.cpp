#include "includes.h"

using namespace std;

class Trie {
    Trie* root[26];
    bool isEnd = 0;
public:
    Trie() {
        for(int i = 0; i < 26; i++){
            root[i] = nullptr;
        }
    }

    void insert(string word) {
        if(word.empty()){
            isEnd = 1;
        }
        else{
            if(root[word[0] - 'a'] == nullptr){
                root[word[0] - 'a'] = new Trie();
                if(word.size() == 1) {
                    root[word[0] - 'a']->isEnd = 1;
                    return;
                }
            }
            Trie* child = root[word[0] - 'a'];
            for(int i = 1; i < word.size(); i++){
                if(child->root[word[i] - 'a'] == nullptr){
                    child->root[word[i] - 'a'] = new Trie;
                }
                child = child->root[word[i] - 'a'];
            }
            child->isEnd = 1;
        }
    }

    bool search(string word) {
        if(word.empty()){return isEnd;}

        Trie*child = root[word[0] - 'a'];
        if(!child){
            return 0;
        }
        for(int i = 1; i < word.size(); i++){
            if(child->root[word[i] - 'a'] == nullptr)
                return 0;
            child = child->root[word[i] - 'a'];
        }
        return child->isEnd;
    }

    bool startsWith(string prefix) {
        //app
        if(prefix.empty())
            return isEnd;
        Trie* child = root[prefix[0] - 'a'];
        if(child){
            for(int i = 1; i < prefix.size(); i++){
                if(child->root[prefix[i] - 'a'] == nullptr)
                    return 0;
                child = child->root[prefix[i] - 'a'];
            }
            return child? 1 : 0;
        } else {
            return 0;
        }
    }
};



int main(){
    Trie* trie = new Trie();
    trie->insert("apple");
    trie->startsWith("app");
    return 0;
};
