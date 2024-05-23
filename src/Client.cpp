#include "Client.h"


void Client::borrowBook(Library* l, Book* b){
  books.push_back(b);

  b->changeStatus();
}

void Client::returnBook(Library* l, Book* b){

  books.erase(books.begin()+ Tools::findIndex(books, b));

  b->changeStatus();
}

void Client::load(Library *lib){
  ifstream file ("client.json");
  string json;

  if (file.is_open()){
    stringstream buffer;
    buffer << file.rdbuf();
    json = buffer.str();
    file.close();
  }else{
    cout << "error"<< endl;
  }

  Document d;
  d.Parse(json.c_str());

  this->name = d["name"].GetString();
  this->surname = d["surname"].GetString();
  this->phone = d["phone"].GetInt();

  const Value& books = d["books"];
  vector<Book*> clientBooks;
  for(int i = 0; i < books.Size(); i++){

    const Value& book = books[i];
    string bookName = book["name"].GetString();
    string bookAuthor = book["author"].GetString();
    string bookIsbn = book["isbn"].GetString();

    const Value& genres = book["genres"];
    vector<string> bookGenres;
    for(int i = 0; i < genres.Size(); i++){
      bookGenres.push_back(genres[i].GetString());
    }

    //oznaczanie ksiazek klienta jako wypozyczone
    vector <Book*> founds = lib->search(bookIsbn, 3);

    if(founds.size() != 0){
      Book *a = founds[0];

      this->borrowBook(lib, a);
    } else {
      cout << "error book not found: " << endl;
      printf("%s %s %s \n", bookName.c_str(), bookAuthor.c_str(), bookIsbn.c_str());
    }
  }
}
void Client::save(){
  ofstream file ("client.json");
  if (file.is_open()){
    Document d;
    d.SetObject();


    //cout << this->books[0]->name << endl;

    Value name;
    name.SetString(this->name.c_str(), this->name.length());

    Value surname;
    surname.SetString(this->surname.c_str(), this->surname.length());

    Value phone(this->phone);

    d.AddMember("name", name, d.GetAllocator());
    d.AddMember("surname", surname, d.GetAllocator());
    d.AddMember("phone", phone, d.GetAllocator());

    Value booksArray(kArrayType);

    for(int j = 0; j < this->books.size(); j++){
      Value book(kObjectType);

      Value bookName;
      bookName.SetString(this->books[j]->name.c_str(), this->books[j]->name.length());
      book.AddMember("name", bookName, d.GetAllocator());

      Value bookAuthor;
      bookAuthor.SetString(this->books[j]->author.c_str(), this->books[j]->author.length());
      book.AddMember("author", bookAuthor, d.GetAllocator());

      Value bookIsbn;
      bookIsbn.SetString(this->books[j]->isbn.c_str(), this->books[j]->isbn.length());
      book.AddMember("isbn", bookIsbn, d.GetAllocator());

      Value genresArray(kArrayType);

        for(int i = 0; i < this->books[j]->genres.size(); i++){
          Value genreValue;
          genreValue.SetString(this->books[j]->genres[i].c_str(), this->books[j]->genres[i].length());
          genresArray.PushBack(genreValue, d.GetAllocator());
        }

      book.AddMember("genres", genresArray, d.GetAllocator());

      booksArray.PushBack(book, d.GetAllocator());
    }

    d.AddMember("books", booksArray, d.GetAllocator());

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);

    d.Accept(writer);
    string json = buffer.GetString();

    file << json;
    file.close();

  }else{
    cout << "error"<< endl;
  }
}
void Client::print(){
  Tools::print(books);
}

