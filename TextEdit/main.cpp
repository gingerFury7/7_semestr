#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>

#define file "/Users/macbook/Desktop/Учеба/7 сем/Прога/TextEdit/MasterAndMargarita"
using namespace std;

string read(string & name)
{
    stringstream ss;
    string line;
    ifstream in(name);
    if(in.is_open())
    {
        while(getline(in, line))
        {
            ss << line << endl;
        }
    }
    in.close();
    return ss.str();
}

int main()
{

    string file_name = file".txt";
    string text_with_punc = read(file_name);
    string text_witout_punct;
    remove_copy_if(text_with_punc.begin(), text_with_punc.end(),
                   std::back_inserter(text_witout_punct), //Store output
                   [](unsigned char x){return std::ispunct(x);}
    );
    freopen(file".txt", "w", stdout);
    cout << text_witout_punct;
    return 0;
}