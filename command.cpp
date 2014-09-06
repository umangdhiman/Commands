#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string x;
    std::string s,s1;
    int n,i,j,k,l=0,r=0;
    cin>>n;
    vector<string> a(n);
    a.clear();
    cin.ignore();
    for(i=0;i<n;i++){
        s.clear();
        std::getline(std::cin,s);
        r=0;
        l=0;
        if(s=="pwd"){
            for(j=0;j<a.size();j++)
                cout<<"/"<<a[j];
            cout<<"/\n";
        }
        else{
            if(s[3]!='.'&&s[4]!='.'&&s[0]=='c'&&s[1]=='d'){
                s.erase(0,3);
                if(s[0]=='/'){
                    s.erase(0,1);
                    a.clear();
                }
            }
            if(s[0]=='c'&&s[1]=='d'&&s[3]=='.'&&s[4]=='.'){
                a.pop_back();
                s.erase(0,6);
            }
            for(k=0;k<s.size();k++){
                l++;
                if(s[k]=='/'){
                    s1=s.substr(r,l-1);
                    a.push_back(s1);
                    r=k+1;
                    l=0;
                }
                if(s[k+1]=='\0'&&s[k]!='.'){
                    s1=s.substr(r,l);
                    a.push_back(s1);
                    r=k+1;
                    l=0;
                }
                if(((k+2)<s.size())&&s[k+1]=='.'&&s[k]=='.'&&s[k+2]=='/'){
                    a.pop_back();
                    k=k+2;
                    r=k+1;
                    l=0;
                }
                if(s[k+1]=='.'&&s[k]=='.'&&s[k+2]=='\0'){
                    a.pop_back();
                }
            }
        }
    }
    return 0;
}

