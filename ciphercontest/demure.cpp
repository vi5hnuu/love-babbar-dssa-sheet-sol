#include <bits/stdc++.h>
using namespace std;


bool startsWith(string &str,string &prefix){
  if(str.length()<prefix.length()){
    return false;
  }

  for(int i=0;i<prefix.length();i++){
    if(prefix[i]!=str[i]){
      return false;
    }
  }
  return true;
}

int main(){
  int p;
  cin>>p;

  vector<string> words;  
  while(p>0){
    p--;

    string op,kind;
    cin>>op>>kind;
    if(op=="Add"){
      words.push_back(kind);
    }else{
      int count=0;
      for(auto &word:words){
        if (startsWith(word,kind)) {
          count++;
        }
      }
      cout<<count<<endl;
    }
    
  }
}