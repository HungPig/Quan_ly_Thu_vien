#pragma once
#include "User_Data.h"
#include "Book_Data.h"
class Library_Data : public User_Data
{
private:
	 std::vector<std::string> readerIds;
    std::vector<std::string> readerNames;
    std::vector<std::string> readerContactInfo;
	std::vector<Book_Data> books;
public:
	Library_Data(const std::string &username, const std::string &password, const std::string &personInf) 
		: User_Data(username,password,personInf) {}
	void viewdataList();
	void addReader(const std::string& id, const std::string& name, const std::string& contactinfor);
	void editReaderInfo(const std::string& id, const std::string& newName, const std::string& newContactInfor);
	void searchidpatron(const std::string& id);
	void deleteReader(const std::string &reader);
	void saveformfilepartron(const std::string& filename);
	// ham khac
	void addBook(const std::string& isbn, const std::string& title, const std::string& partron);
	void viewbookList();
	void editbookinfor(const std::string& isbn, const std::string& newTitle, const std::string& newPatron);
	void deleteBook(const std::string& isbn);
	void searchidbook(const std::string& isbn);
	void borrow_book(const std::string& title);
	void return_book(const std::string& title);
	~Library_Data()
	{
		// std::cout << "Destructor of Library_Data" << std::endl;
	}
};

