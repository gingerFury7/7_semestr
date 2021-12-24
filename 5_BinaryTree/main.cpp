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

#define file_to_read "MonteChristo"
#define file_to_write "result"
using namespace std;

int test()
{
    //уникальных слов - 25649
    //log(25649) = 14.65
    cout << "amount_of_words\tbinary_tree\tskip_list\n";
    vector<string> words;
    string word;
    while(cin >> word)
    {
        words.push_back(word);
    }
//    SkipList lst(15, 0.5);
    List list;
    BinaryTree Tree;
    int last = 0;
    for(int i=0; i<words.size(); i++)
    {
        Tree.insert(words[i]);
        list = sortedInsert(list);
//        if(list.size != Tree.size())
//        {
//            return 1;
//        }
        if(lst.skip_list_size != last)
        {
            cout << lst.skip_list_size << "\t" << Tree.treeCompare << "\t" << lst.compare << "\n";
            last = lst.skip_list_size;
        }
        cout << Tree.treeCompare << "\n";
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

