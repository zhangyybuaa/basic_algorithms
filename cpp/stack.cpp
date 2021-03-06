//
// Created by sun on 16-9-24.
//

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cassert>
#include <stack>
using namespace std;
///
/// \param seq_in
/// \param seq_out
/// \return seq_out is a valid out-stack sequence                    
bool isValidOutSeq(const string &seq_in, const string &seq_out) {
  stack<char> s;
  int i = 0, j = 0;
  s.push(seq_in[i++]);
  while (j < seq_out.size() && !s.empty()) {
    if (s.top() == seq_out[j]) {
      s.pop();
      j++;
    } else if (i < seq_in.size())
      s.push(seq_in[i++]);
    else return false;
  }
  return i == seq_in.size() && j == seq_out.size() && s.empty();
}

void allValidOutSeq(const string &seq_in, vector<string> &res,string rest, string s, int start) {
  if (s.size() == seq_in.size()) {
    res.push_back(s);
    return;
  }
  if(start<seq_in.size()) {
    rest.push_back(seq_in[start]);
    allValidOutSeq(seq_in, res, rest, s, start+1);
    rest.pop_back();
  }
  if(!rest.empty()){
    s.push_back(rest.back());
    rest.pop_back();
    allValidOutSeq(seq_in, res,rest, s, start);
  }

}
vector<string> allValidOutSeq(const string &seq_in) {
  vector<string> res;
  string s,rest;
  allValidOutSeq(seq_in,res,rest,s,0);
  return  res;
}
int main() {
  cout << isValidOutSeq("ABCDE", "DCEAB") << endl;
  string s;
  stack<int >d;

  for(int i=0;i<9;i++){
    s.push_back(i+'A');
    vector<string> res=allValidOutSeq(s);
    cout<<res.size()<<endl;
  }

//  for(auto & s:res){
//    cout<<s<<endl;
//  }
}