#include "Tools.h"

void Tools::print(vector<Book*> b) {
  for(int i = 0; i < b.size(); i++){
    cout << *b[i] << endl;
  }
}

void Tools::printWithNumbers(vector<Book*> b) {
  for(int i = 0; i < b.size(); i++){
    cout << i + 1 << ". " << *b[i] << endl;
  }
}

string Tools::toLowerCase(string a){
  for(int i = 0; i < a.length(); i++){
    a[i] = tolower(a[i]);
  }
  return a;
}

bool Tools::contains(string a, string b){

  if(b.length() == 0){
    return true;
  }

  for(int i = 0; i < a.length() - b.length() + 1; ++i) {
    bool found = true;

    for(int j = 0; j < b.length(); ++j){

      if(a[i + j] != b[j]){
        found = false;
        break;
      }
    }
    if(found){
      cout << a << " "<< b << endl;
      return true;
    }
  }
  cout << a << " "<< b << endl;
  return false;
}

bool Tools::equals(string a, string b){
  if(a.length() != b.length()){
    return false;
  }
  for(int i = 0; i < a.length(); i++){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

int Tools::findIndex(vector<Book*> books, Book* b){

  for(int i = 0; i < books.size(); i++){
    if(books[i] == b){
      return i;
    }
  }
  return -1;
}
