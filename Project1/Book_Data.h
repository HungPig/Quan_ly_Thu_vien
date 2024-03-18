#include "User_Data.h"
class Book_Data
{
private:
    std::string isbn; 
    std::string title;
    std::string parton;
    bool isBorrow;
/// <summary>
///  HAHAHAHAHAHAAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
/// </summary>
public:
    Book_Data(const std::string& isbn, const std::string& title, const std::string& partron)
    {
        this->isbn = isbn;
        this->title = title;
        this->parton = partron;
        isBorrow = false;
    }
    const std::string& getISBN()
    {
        return isbn;
    }

    const std::string& getTitle()
    {
        return title;
    }

    const std::string& getPartron()
    {
        return parton;
    }

    // Setters
    void setISBN(const std::string& newIsbn)
    {
        isbn = newIsbn;
    }

    void setTitle(const std::string& newTitle)
    {
        title = newTitle;
    }

    void setPatron(const std::string& newPatron)
    {
        parton = newPatron;
    }

    // Borrow and return book
    bool isAvailable() const {
        return !isBorrow;
    }
    // muon sach
    void Borrow_book() {
        isBorrow = true;
    }
    void Return_book() {
        isBorrow = false;
    }
    ~Book_Data() {}
};