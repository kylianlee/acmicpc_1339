//
// Created by Kylian Lee on 2021/08/19.
//

#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main(){
  map<int, int> word_map;
  set<int, greater<>> num_set;
  for (int i = 0; i < 10; ++i) {
    num_set.insert(i);
  }
  int str_num;
  cin >> str_num;
  for (int i = 0; i < str_num; ++i) {
    string s;
    cin >> s;
    int len = s.length();
    for (int j = 0; j < len; ++j) {
      word_map[s[j]] += pow(10, len - j - 1);
    }
  }
  vector<pair<int, int>> word_vec(word_map.begin(), word_map.end());
  sort(word_vec.begin(), word_vec.end(), cmp);
  auto map_iter = word_vec.begin();
  auto set_iter = num_set.begin();
  int sum = 0;
  while(map_iter != word_vec.end()){
    sum += map_iter->second * (*set_iter);
    map_iter++, set_iter++;
  }
  cout << sum << endl;
  return 0;
}