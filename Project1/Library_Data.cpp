#include "Library_Data.h"

void Library_Data::saveformfilepartron(const std::string& filename)
{
	std::ofstream os(filename);
	if (os.is_open())
	{
		for (int i = 0; i < readerIds.size(); i++)
		{
			os << readerIds[i] << std::endl;
			os << readerNames[i] << std::endl;
			os << readerContactInfo[i] << std::endl;
		}
		os.close();
	}
	else
	{
		std::cout << "Can't open file to save!" << std::endl;
	}
}
void Library_Data::viewdataList()
{
	std::cout << std::endl;
	std::cout << "+----------------------------------------------+\n";
	std::cout << "|         >>    VIEW LIST PARTRON    <<        |\n";
	std::cout << "+----------------------------------------------+\n";
	std::cout << "| ID                 | Name       | Infor      |\n";
	std::cout << "+----------------------------------------------+\n";
	for (auto it = readerIds.begin(); it != readerIds.end(); it++)
	{
		int i = std::distance(readerIds.begin(), it);
		std::cout << "| " << std::left << std::setw(18) << *it << " | " << std::left << std::setw(10) << readerNames[i] << " | " << std::left << std::setw(10) << readerContactInfo[i] << " | \n";
	}
	std::cout << "+----------------------------------------------+\n";
}

void Library_Data::addReader(const std::string& id, const std::string& name, const std::string& contactinfor)
{
	readerIds.push_back(id);
	readerNames.push_back(name);
	readerContactInfo.push_back(contactinfor);
	std::cout << "Add Patron successfully..\n";
}

void Library_Data::editReaderInfo(const std::string& id, const std::string& newName, const std::string& newContactInfor)
{
	for (auto it = readerIds.begin(); it != readerIds.end(); ++it)
	{
		if (*it == id)
		{
			int i = std::distance(readerIds.begin(), it);
			readerNames[i] = newName;
			readerContactInfo[i] = newContactInfor;
			std::cout << "EDIT SUCCESFULLY...\n";
		}
	}
}

void Library_Data::searchidpatron(const std::string& id)
{
	std::cout << std::endl;
	std::cout << "+----------------------------------------------+\n";
	std::cout << "|         >>    FOUND LIST PARTRON    <<       |\n";
	std::cout << "+----------------------------------------------+\n";
	std::cout << "| ID                 | Name       | Infor      |\n";
	std::cout << "+----------------------------------------------+\n";

	for (auto it = readerIds.begin(); it != readerIds.end(); ++it)
	{
		if (*it == id)
		{
			int i = std::distance(readerIds.begin(), it);
			std::cout << "| " << std::left << std::setw(18) << *it << " | " << std::left << std::setw(10) << readerNames[i] << " | " << std::left << std::setw(10) << readerContactInfo[i] << " | \n";
		}
		else {
			std::cout << "No reader with ID " << id << " found.\n";
		}
	}
	std::cout << "+----------------------------------------------+\n";
}
// ham data_book
void Library_Data::deleteReader(const std::string& reader)
{
	for (std::vector<std::string>::iterator it = readerIds.begin(); it != readerIds.end(); ++it)
	{
		if (*it == reader)
		{
			int i = std::distance(readerIds.begin(), it);
			readerIds.erase(readerIds.begin() + i);
			readerNames.erase(readerNames.begin() + i);
			readerContactInfo.erase(readerContactInfo.begin() + i);
			std::cout << "delete partron successfuly\n";
			return;
		}
		else {
			std::cout << "ID readers not found " << reader << "!\n";
		}
	}
}
void Library_Data::viewbookList()
{
	std::cout << std::endl;
	std::cout << "+----------------------------------------------+\n";
	std::cout << "|         >>    VIEW LIST BOOK    <<           |\n";
	std::cout << "+----------------------------------------------+\n";
	std::cout << "| ID                 | Name       | Author     |\n";
	std::cout << "+----------------------------------------------+\n";
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		std::cout << "| " << std::setw(18) << std::left <<it->getISBN() << " | " << std::setw(10) << std::left <<it->getTitle() << " | " << std::setw(10) << std::left << it->getPartron() << " |\n";
	}
	std::cout << "+----------------------------------------------+\n";
}
void Library_Data::addBook(const std::string& isbn, const std::string& title, const std::string& patron)
{
	Book_Data newBook(isbn, title, patron);
	books.push_back(newBook);
	std::cout << "Book added successfully!" << std::endl;
}
void Library_Data::editbookinfor(const std::string& isbn, const std::string& newTitle, const std::string& newPatron) {
	for (Book_Data& book : books) {
		if (book.getISBN() == isbn) {
			book.setTitle(newTitle);
			book.setPatron(newPatron);
			break;
		}
	}
}
void Library_Data::deleteBook(const std::string& isbn) {
	// Assuming books is a std::vector<Book_Data> that stores all the books in the library
	for (auto it = books.begin(); it != books.end(); ++it) {
		if (it->getISBN() == isbn) {
			books.erase(it);
			break;
		}
	}
}
void Library_Data::searchidbook(const std::string& isbn) 
{
	std::cout << std::endl;
	std::cout << "+----------------------------------------------+\n";
	std::cout << "|         >>    VIEW FIND BOOK    <<           |\n";
	std::cout << "+----------------------------------------------+\n";
	std::cout << "| ID                 | Name       | Author     |\n";
	std::cout << "+----------------------------------------------+\n";
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		if (it->getISBN() == isbn)
		{
			std::cout << "| " << std::setw(18) << std::left << it->getISBN() << " | " << std::setw(10) << std::left << it->getTitle() << " | " << std::setw(10) << std::left << it->getPartron() << " |\n";
		}
	}
	std::cout << "+----------------------------------------------+\n";
}

void Library_Data::borrow_book(const std::string& title)
{
	//gpt
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		if (it->getTitle() == title && !it->isAvailable())
		{
			it->isAvailable() == true;
			std::cout << "Book: " << title << " Borrwed Successfully..\n";
		}
		else {
			std::cout << "Book: " << title << " was Not available..\n";
		}
	}
}

void Library_Data::return_book(const std::string& title)
{
	// gpt
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		if (it->getTitle() == title && !it->isAvailable())
		{
			it->isAvailable() == false;
			std::cout << "Book: " << title << " Returned Successfully..\n";
		}
		else
		{
			std::cout << "Book: " << title << " was Not available..\n";
		}
	}
}
// Path: Project1/Library_Data.h