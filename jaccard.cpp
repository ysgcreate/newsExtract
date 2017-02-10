#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <ctype.h>
#include <algorithm>
#include <locale>
#include <sstream>
#include <set>
using namespace std;

class Jaccard {//中文要判断acsill码，大于127，占两个字节
public:
  Jaccard (string a,string b){
    this->s_a=a;
    this->s_b=b;
    this->ornums=0;
    this->andnums=0;
  }
  void reSetString(string a,string b){
    this->s_a=a;
    this->s_b=b;
    this->ornums=0;
    this->andnums=0;
  }
  float simility(){
    int i;int len_a=this->s_a.length();
    //first string a
    for(i=0;i<len_a;i++){//gap is 3
      string t;
      if (this->s_a[i]&this->x) {
        t=this->s_a.substr(i,3);
        i=i+2;
      }else{
        t=this->s_a.substr(i,1);
      }
      if (words_item.find(t)==words_item.end()) {
        words_item[t]=1;
        this->ornums++;
      }
    }
    //other string b
    int len_b=this->s_b.length();
    for (size_t i = 0; i < len_b; i++) {
      string t;
      if (this->s_b[i]&this->x) {
        t=this->s_b.substr(i,3);
        i=i+2;
      }else{
        t=this->s_b.substr(i,1);
      }
      if (words_item.find(t)!=words_item.end()&&words_item[t]==1) {
        this->andnums++;
        words_item[t]=3;
      }if(words_item.find(t)==words_item.end()){
        words_item[t]=2;
        this->ornums++;
      }
    }
    //cout<<this->andnums<<endl;
    //cout<<this->ornums<<endl;
    return (1.0*this->andnums)/this->ornums;
  }
private:
  string s_a;
  string s_b;
  map<string,int> words_item;//一个中文占三个字节
  int x=0x80;//judge ascill
  int ornums;
  int andnums;
};
int main(int argc, char const *argv[]) {
  string a;
  string b;
  cin>>a;
  cin>>b;
  Jaccard* ja=new Jaccard(a,b);
  cout<<ja->simility()<<endl;
  return 0;
}
