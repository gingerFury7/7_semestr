# include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>

#include "List.h"
#include "BinaryTree.h"

#define file_to_read "/Users/macbook/Desktop/Учеба/7 сем/Прога/5_BinaryTree/MasterAndMargarita"
#define file_to_write "/Users/macbook/Desktop/Учеба/7 сем/Прога/5_BinaryTree/result"
using namespace std;

int test()
{
    cout << "amountOfWords\tbinaryTree\tlist\n";
    vector<string> words;
    string word;
    while(cin >> word)
    {
        words.push_back(word);
    }
    List list;
    binaryTree Tree;
    int last = 0;
    for(int i = 0; i < words.size(); i++)
    {
        Tree.insert(words[i]);
        list.insert(words[i]);
        if(list.size() != Tree.size())
        {
            return 1;
        }
        if(list.size() != last)
        {
            cout << list.size() << "\t" << Tree.treeCompare << "\t" << list.listCompare << "\n";
            last = list.size();
        }
    }
    return 0;
}

int main()
{
    freopen(file_to_read".txt", "r", stdin);
    freopen(file_to_write".txt", "w", stdout);
    test();
    return 0;
}

