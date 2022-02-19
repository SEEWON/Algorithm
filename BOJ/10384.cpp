#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;

int main(void) {
  int T;
  vector <int> v;
  string str;
  string abc="abcdefghijklmnopqrstuvwxyz";
  cin >> T;
  cin.ignore();
  for(int i=0;i<T;i++) {
    int alphabet[26] = {0,};
    int p1=1, p2=1, p3=1;
    getline(cin, str);
    for(int j=0;j<str.length();j++) {
      if((int)abc.find((char)tolower(str[j]))>=0) {
        alphabet[(int)abc.find((char)tolower(str[j]))]++;
      }
    }
    for(int k=0;k<26;k++) {
      if(alphabet[k]<3) p3=0;
      if(alphabet[k]<2) p2=0;
      if(alphabet[k]<1) p1=0;
    }
    if(p3==1) v.push_back(3);
    else if(p2==1) v.push_back(2);
    else if(p1==1) v.push_back(1);
    else v.push_back(0);
  }

  for(int i=0;i<v.size();i++) {
    cout << "Case " << i+1 << ':';
    if(v[i]==3) cout << " Triple pangram!!!" << endl;
    else if(v[i]==2) cout << " Double pangram!!" << endl;
    else if(v[i]==1) cout << " Pangram!" << endl;
    else cout << " Not a pangram" << endl;
  }
  return 0;
}