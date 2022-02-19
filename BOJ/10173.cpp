#include<iostream>
#include<string>
#include<cctype>
#include<vector>

using namespace std;

int main (){
  string str;
  vector <int> v;

  while (1) {
    getline(cin, str);
    if(str=="EOI") break;
    for(int i=0;i<str.length();i++) {
      str[i] = toupper(str[i]);
    }
    if((int)str.find("NEMO")>=0) v.push_back(1);
    else v.push_back(0);
  }

  for(int i=0;i<v.size();i++) {
    if(v[i]==1) cout << "Found" << endl;
    else cout << "Missing" << endl;
  }

  return 0;
}