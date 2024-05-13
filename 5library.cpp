#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book
{
    string title;
    string author;
    string ISBN;
    bool available;
};

struct Borrower
{
    string name;
    vector<Book> borrowedBooks;
};

struct Transaction
{
    Book book;
    Borrower borrower;
    string date;
    bool returned;
};

vector<Book> books;
vector<Borrower> borrowers;
vector<Transaction> transactions;

void addBook()
{
    Book book;
    cout << "Enter book title: ";
    getline(cin, book.title);
    cout << "Enter book author: ";
    getline(cin, book.author);
    cout << "Enter book ISBN: ";
    getline(cin, book.ISBN);
    book.available = true;
    books.push_back(book);
}

void searchBook()
{
    string query;
    cout << "Enter book title, author, or ISBN: ";
    getline(cin, query);
    for (const auto &book : books)
    {
        if (book.title == query || book.author == query || book.ISBN == query)
        {
            cout << "Book found: " << book.title << " by " << book.author << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void checkoutBook()
{
    int bookIndex;
    int borrowerIndex;
    cout << "Enter book index: ";
    cin >> bookIndex;
    cout << "Enter borrower index: ";
    cin >> borrowerIndex;
    if (bookIndex > 0 && bookIndex <= books.size() && borrowerIndex > 0 && borrowerIndex <= borrowers.size())
    {
        Book book = books[bookIndex - 1];
        Borrower borrower = borrowers[borrowerIndex - 1];
        if (book.available)
        {
            book.available = false;
            borrower.borrowedBooks.push_back(book);
            Transaction transaction;
            transaction.book = book;
            transaction.borrower = borrower;
            transaction.date = "Current Date"; // Replace with current date
            transaction.returned = false;
            transactions.push_back(transaction);
        }
        else
        {
            cout << "Book is not available." << endl;
        }
    }
    else
    {
        cout << "Invalid book or borrower index." << endl;
    }
}

void returnBook()
{
    int bookIndex;
    int borrowerIndex;
    cout << "Enter book index: ";
    cin >> bookIndex;
    cout << "Enter borrower index: ";
    cin >> borrowerIndex;
    if (bookIndex > 0 && bookIndex <= books.size() && borrowerIndex > 0 && borrowerIndex <= borrowers.size())
    {
        Book book = books[bookIndex - 1];
        Borrower borrower = borrowers[borrowerIndex - 1];
        for (auto it = borrower.borrowedBooks.begin(); it != borrower.borrowedBooks.end(); ++it)
        {
            if (it->title == book.title)
            {
                borrower.borrowedBooks.erase(it);
                book.available = true;
                for (auto &transaction : transactions)
                {
                    if (transaction.book.title == book.title && transaction.borrower.name == borrower.name)
                    {
                        transaction.returned = true;
                        break;
                    }
                }
                break;
            }
        }
    }
    else
    {
        cout << "Invalid book or borrower index." << endl;
    }
}

void calculateFines()
{
    for (auto &transaction : transactions)
    {
        if (!transaction.returned)
        {
            // Calculate fine based on current date and transaction date
            // Replace with actual fine calculation logic
            cout << "Fine: $" << 10.0 << endl; // Replace with actual fine amount
        }
    }
}

int main()
{
    while (true)
    {
        cout << "Library Management System" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Checkout Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Calculate Fines" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            checkoutBook();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            calculateFines();
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
        cin.ignore(); // Ignore newline character
    }
    return 0;
}