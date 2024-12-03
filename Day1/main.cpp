#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

int main () {

  // Open a text file (input.txt)
  ifstream file("input.txt");
  
  // Confirm that the file was open correctly
  if (file.is_open()) {

    int a, b;
  
    // Create two int vectors to store the columns values
    vector<int> col1, col2;

    while (file >> a >> b) {
      col1.push_back(a); // Add a value to the end of a vector
      col2.push_back(b);
    }

    file.close(); // Close file

    sort(col1.begin(), col1.end()); // Sort values so that the smallest ones
    sort(col2.begin(), col2.end()); // are align in both columns
    
    
    int diff_ab = 0;
    size_t size(col1.size()); // Get the colum size

    // Iterate through all elements of both columns and
    // sum the difference between each pair values
    for (int i = 0; i < size; i++) {
      diff_ab += abs(col1[i] - col2[i]); // Return the absolute value
    }

    cout << diff_ab << endl; //1341714
  }
  else 
    cout << "Error opening the file";
  return 0; 
}