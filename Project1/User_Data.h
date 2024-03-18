/**
 * @ Author: HungHeo
 * @ Create Time: 2024-03-14 11:48:39
 * @ Modified by: Your name
 * @ Modified time: 2024-03-14 13:10:00
 * @ Description:
 */
#pragma once
#include "Common.h"
class User_Data
{
protected:
    std::string username;
    std::string password;
    std::string personinfor;
    bool islogined;

public:
    // CUOC DOI LIEM KHIET CUA TAOOO
    User_Data() {}
    User_Data(const std::string username, const std::string password, const std::string personinfor)
    {
        this->username = username;
        this->password = password;
        this->personinfor = personinfor;
        islogined = false;
    }
    virtual void input()
    {
        std::cout << "Input username: ";
        std::cin >> username;
        std::cout << "Input password: ";
        std::cin >> password;
        std::cout << "Input personinfor: ";
        std::cin >> personinfor;
    }
    virtual void output()
    {
        std::cout << "+-----------------+----------------------+\n";
        std::cout << "| Username        | Personinfor          |\n";
        std::cout << "+-----------------+----------------------+\n";
        std::cout << "| " << std::setw(15) << std::left << username << " | " << std::left <<std::setw(20) << personinfor << " |\n";
        std::cout << "+-----------------+----------------------+\n";
    }
    
    void saveformfile(const std::string& filename)
    {
        std::ofstream os(filename);
        if (os.is_open())
        {
            os << username << std::endl;
            os << password << std::endl;
            os << personinfor << std::endl;
            os.close();
        }
        else
        {
            std::cout << "Can't open file to save!" << std::endl;
        }
    }
    void login()
    {
        if (this->username == username && this->password == password)
        {
            islogined = true;
            std::cout << "Login successfully!" << std::endl;
        }
        else
        {
            std::cout << "Login failed!" << std::endl;
        }
    }
    void logout()
    {
        islogined = false;
        std::cout << "Logout successfully!" << std::endl;
    }
    static User_Data* Creater_User(const std::string username, const std::string password, const std::string personinfor)
    {
        return new User_Data(username, password, personinfor);
    }
    bool getislogined()
    {
        return islogined;
    }
    void changePassword(const std::string newPassword)
    {
        password = newPassword;
        std::cout << "Password changed successfully!" << std::endl;
    }
    void updateInformation(const std::string newInformation)
    {
        personinfor = newInformation;
        std::cout << "Information updated successfully!" << std::endl;
    }
};
