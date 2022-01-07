#include<bits/stdc++.h>
using namespace std;

#define MAX 256
#define MAX_WORD_LEN 500

using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*>children ;
    bool terminal;
    int c=1;

    Node(char d){
        data = d;
        terminal=false;



    }
};
class Trie{
    Node* root;


public:
    Trie(){
        root = new Node('\0');
        int cnt = 0;



    }
    void insert(char *w){


        Node* temp=root;
        for(int i=0;w[i]!='\0';i++){

            char ch=w[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
                temp->c++;

            }
            else{
                Node* n = new Node(ch);
                temp->children[ch]=n;
                temp=n;


            }

        }

        temp->terminal=true;

    }
    bool find(char *w){
        Node* temp = root;
        for(int i=0;w[i]!='\0';i++){
            char ch = w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp=temp->children[ch];

            }
        }
        return temp->terminal;
    }

    void print(Node*root){
        for(int i =0;i<128;++i) {
            if (root->children[i]) {
                cout << char(i) << " " << root->children[i]->c << endl;
                print(root->children[i]);

            }
        }

    }
    void findpre(Node*root,char prefix[],int ind){

        if(root==NULL){
            return;
        }
        if(root->c==1){
            prefix[ind] = '\0';
            cout << prefix << " ";
            return;
        }
        for (int i=0; i<MAX; i++)
        {
            if (root->children[i] != NULL)
            {
                prefix[ind] = i;
                findpre(root->children[i], prefix, ind+1);
            }
        }


    }
    void findPrefixes(char arr[], int n)
    {
        // Construct a Trie of all words

        root->c = 0;


        // Create an array to store all prefixes
        char prefix[MAX_WORD_LEN];

        // Print all prefixes using Trie Traversal
        findpre(root, prefix, 0);
    }

};
int main() {
    Trie t;
    char words[][10]={"zebra", "dog", "duck", "dove"};

    int n = sizeof(words)/sizeof(words[0]);
    for(int i=0;i<4;i++){
        t.insert(words[i]);

    }
    t.findPrefixes(*words,n);


    return 0;
}