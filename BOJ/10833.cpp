#include<iostream>

using namespace std;

class SchoolClass {
  public:
    int student;
    int apple;
};

int main() {
  int num;
  cin >> num;
  SchoolClass *data = new SchoolClass[num];
  
  int res=0;
  for(int i=0; i<num; i++) {
    cin >> data[i].student >> data[i].apple;
    res += data[i].apple % data[i].student;
  }

  cout << res << endl;

  return 0;
}