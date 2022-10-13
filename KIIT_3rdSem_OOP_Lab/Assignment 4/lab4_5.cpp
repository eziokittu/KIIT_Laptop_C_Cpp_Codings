// OOP LAB Assignment 4
// Q5) Create a class which stores name, author and price of
// book. Store information for n number of books. Display
// information of all books in a given proce range using
// friend function

# include <iostream>
using namespace std;

class Book;

class Book{
    private:
        string name;
        string author;
        float price;
        static int count;
    public:
        void GetBook(){
            printf("\n-- For Book %d --\n",GetCount());
            cout<<"Name: "; getline(cin>>ws, name);
            cout<<"Author: "; getline(cin>>ws, author);
            cout<<"Price: "; cin >> price;
            AddCount();
        }
        static int GetCount(){ return count;}
        static void AddCount(){ ++count;}
        friend void DisplayBooks(Book *b, float s, float e);
};

void DisplayBooks(Book *b, float s, float e){
    for (int i=0; i<Book::GetCount(); i++){
        if (b[i].price>=s && b[i].price<=e){
            cout << "Book '"<<b[i].name<<"' by Author '"<<b[i].author; 
            printf("' is Rs %f\n", b[i].price);
        }
    }
}

int Book::count;

int main(){
    int n;
    cout << "How many books? - "; cin >> n;
    Book b[n];
    for (int i=0; i<n; i++){
        b[i].GetBook();
    }

    float s,e;
    cout<<"\n-- Enter price range --\nStart = "; cin >> s;
    cout <<"End = "; cin >> e;
    DisplayBooks(&b[0], s, e);

    return 0;
}