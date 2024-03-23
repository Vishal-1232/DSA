#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26]; // A to Z
    bool isTerminalNode;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminalNode = false;
    }
};

class Trie
{
private:
    TrieNode *root;
    void insertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminalNode = true;
            return;
        }

        int index = word[0] - 'A'; // assumption word is in Capital letters
        TrieNode *child;

        if (root->children[index] != NULL) // letter is already present
        {
            child = root->children[index];
        }
        else // letter is absent from trie
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }
    bool searchUtil(TrieNode * root, string word){
        // base case
        if(word.length()==0){
            return root->isTerminalNode;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if(root->children[index] != NULL){ // letter is present in trie
            child = root->children[index];
        }
        else{   // absent 
            return false;
        }

        return searchUtil(child,word.substr(1));
    }
    void deleteWordUtil(TrieNode *root, string word){
        if(word.length() == 0){
            root->isTerminalNode = false;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }else{
            return;
        }

        deleteWordUtil(child,word.substr(1));
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(string word)  // Time Complexity : O(L) , where L is length of given word
    {
        insertUtil(root, word);
    }
    bool searchWord(string word){   // Time Complexity : O(L) , where L is length of given word
        return searchUtil(root,word);
    }
    void deleteWord(string word){
        deleteWordUtil(root,word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertWord("CAT");
    t->insertWord("TIME");
    cout<<"Present or not : "<<t->searchWord("TIME")<<endl;
    cout<<"Deleting word : \n";t->deleteWord("CAT");
    cout<<"Present or not : "<<t->searchWord("CAT")<<endl;
    return 0;
}