#include<iostream>
#include<map>
#include<fstream>
#include<time.h>
#include<ctime>
#include<sstream>
#include<vector>
#include<sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;
int main(int argc,char** argv)
{
    map<string,string> m;
    ifstream file;
    file.open("data.txt");
    vector<string> v;
    string word;
    string str;
    string line;
    int i;
    while(file >> word >> str)
    {
        m.insert(make_pair(word,str));
    }
    int valid_sessions=0;
    int prev=-30;
    int j=0;
    int h,mi,h2,m2,s,s2;
    for( map<string,string>::iterator it=m.begin();it!=m.end();++it){
        //cout<<it->first<<" "<<it->second<<endl;
        j++;
        sscanf(it->first.c_str(), "%d:%d:%d", &h, &mi, &s);
        sscanf(it->second.c_str(), "%d:%d:%d", &h2, &m2, &s2);
        int sec=(h*3600)+(mi*60)+s;
        int sec2=(h2*3600)+(m2*60)+s2;
        if((sec-prev) > 30){
            if((sec2-sec) > 60)
            {
                valid_sessions++;
                cout<<j<<" is a valid session"<<endl;
            }
            else if((sec2-sec) < 1)
            {
                //do nothing
            }
        }
        prev=sec2;

    }
    cout<<"\nTotal valid_sessions are= "<<valid_sessions<<endl;

}
