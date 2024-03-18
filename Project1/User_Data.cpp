#include "User_Data.h"
void User_Data::login(const std::string& uname, const std::string& pwd)
{
    if (uname == username && pwd == password)
    {
        isloggined = true;
        std::cout << "Login Thanh Cong!!.." << std::endl;
    }
    else
    {
        std::cout << "Login K Thanh Cong, Check Lai Tai Khoan & Mat Khau.." << std::endl;
    }
}

void User_Data::logout()
{
    isloggined = false;
    std::cout << "Dang Xuat Thanh Cong." << std::endl;
}

void User_Data::changePassword(const std::string& OldPwd, const std::string& newPwd)
{
    if (isloggined && OldPwd == password)
    {
        password = newPwd;
        std::cout << "Doi Mk Thanh Cong.";
    }
    else
    {
        std::cout << "Doi Mk K thanh Cong..";
    }
}

void User_Data::UpdateInfor(const std::string& newInfo)
{
    PersonInfor = newInfo;
    std::cout << "Cap Nhat Thong Tin Thanh Cong.\n";
}

void User_Data::displayInfor()
{
    std::cout << "Username: " << username << std::endl;
    std::cout << "PersonalInfor: " << PersonInfor << std::endl;
    std::cout << "Islogined: " << (isloggined ? "Yes" : "No") << std::endl;
}

bool User_Data::setisLoggined() const
{
    return isloggined;
}

User_Data::~User_Data() {

}