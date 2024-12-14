#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int linearSearch(vector<string> v, char target) {
  int find = 0;

  int rows = v.size();
  for (int y = 0; y < v.size(); y++) {
    int cols = v[y].size();
    for (int x = 0; x < v[y].size(); x++){

      // horizontar front
      if (x + 3 <= rows && v[y][x] == target && (v[y][x + 1] == 'M') && (v[y][x + 2] == 'A') && (v[y][x + 3] == 'S')) {
        find++;

      // horizontal back
      } if (v[y][x] == target && (v[y][x - 1] == 'M') && (v[y][x - 2] == 'A') && (v[y][x - 3] == 'S')) {
        find++;

      // vertical up
      } if (y + 3 < cols && v[y][x] == target && (v[y + 1][x] == 'M') && (v[y + 2][x] == 'A') && (v[y + 3][x] == 'S')) {
        find++;

      // vertical down
      } if (y >= 3 && v[y][x] == target && (v[y - 1][x] == 'M') && (v[y - 2][x] == 'A') && (v[y - 3][x] == 'S')) { 
        find++;

      // diagonal up-right
      } if (y + 3 <= cols && v[y][x] == target && (v[y + 1][x + 1] == 'M') && (v[y +  2][x + 2] == 'A') && (v[y + 3][x + 3] == 'S')) {
        find++;

        // diagonal down-right
      } if (y >= 3 && v[y][x] == target && (v[y - 1][x + 1] == 'M') && (v[y - 2][x + 2] == 'A') && (v[y - 3][x + 3] == 'S')) {
        find++;

      // diagonal up-left
      } if (y + 3 < cols && v[y][x] == target && (v[y + 1][x - 1] == 'M') && (v[y + 2][x - 2] == 'A') && (v[y + 3][x - 3] == 'S')) {
        find++;

        // diagonal down-left
      } if (y >= 3 && v[y][x] == target && (v[y - 1][x - 1] == 'M') && (v[y -  2][x - 2] == 'A') && (v[y - 3][x - 3] == 'S')) {
        find++;
      }
    }   
  }
  return find;
}


int main () {

  // Open a text file (input.txt)
  ifstream file("input.txt");
  int total;
  
  // Confirm that the file was open correctly
  if (file.is_open()) {
    vector<string> v;

    // Reading Lines by Lines from a file to vector in C++ STL
    string str;
    char target = 'X';
    while(getline(file, str)) {
      v.push_back(str);
    }
    file.close();
    // Search
    total = linearSearch(v, target);
    cout << total << endl;

    // Print vector
    // copy(v.begin(), v.end(),
    //     ostream_iterator<string>(cout, ""));
  }
  else 
    cout << "Error opening the file";
  return total;  // 2401
}


/*
References: 
- https://www.geeksforgeeks.org/reading-lines-by-lines-from-a-file-to-a-vector-in-cpp-stl/
*/ 