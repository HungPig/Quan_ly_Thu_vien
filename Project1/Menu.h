#pragma once
#include "User_Data.h"
#include "Library_Data.h"
#include "GiaoDien.h"
int menu()
{
    // Hienthi();
    User_Data* user = User_Data::Creater_User("admin", "admin", "admin");
    Library_Data library("libUsername", "libPassword", "libPersonInf");
    do
    {
        system("cls");
        ShowCur(false);
        ThongTinChung();
        SetColor(WHITE);
        gotoxy(84, 6);
        std::cout << "1. Login" << std::endl;
        gotoxy(84, 7);
        std::cout << "2. Exit" << std::endl;
        int choose;
        gotoxy(84, 8);
        std::cout << "Enter Your Choice: ";
        std::cin >> choose;
        switch (static_cast<TATCA_NGUOIDUNG>(choose))
        {
        case LOGIN:
        {
            user->input();
            user->saveformfile("user.txt");
            user->login();
            if (user->getislogined())
            {
                bool exit = false;

                while (!exit)
                {
                    system("cls");
                    gotoxy(40, 10);
                    for (int i = 40; i <= 170; i++)
                    {
                        if (i == 40)
                            putchar(201);
                        else if (i == 170)
                            putchar(187);
                        else
                            putchar(205);
                    }
                    for (int i = 11; i <= 25; i++)
                    {
                        gotoxy(40, i);
                        putchar(186);
                        gotoxy(170, i);
                        putchar(186);
                    }
                    gotoxy(40, 26);
                    for (int i = 40; i <= 170; i++)
                    {
                        if (i == 40)
                            putchar(200);
                        else if (i == 170)
                            putchar(188);
                        else
                            putchar(205);
                    }
                    TextColor(14);

                    gotoxy(41, 11);
                    std::cout << "      XXXX               XXXX                  000000000000000             ZZZZZZZZZZZZZZZZZZZZZ        XXXXXXXXXXXXXXXXXXXX";
                    gotoxy(41, 12);
                    std::cout << "      XXXX               XXXX                 00000000000                  ZZZZZ                        XXXXXXXXXXXXXXXXXXXX";
                    gotoxy(41, 13);
                    std::cout << "      XXXX               XXXX               XXXXXXXXX                      ZZZZZ                        XXXX            0000";
                    gotoxy(41, 14);
                    std::cout << "      XXXX               XXXX               00000000                       ZZZZZ                        XXXX            XXXX";
                    gotoxy(41, 15);
                    std::cout << "      XXXX               XXXX                   00000000                   ZZZZZ                        XXXX            XXXX";
                    gotoxy(41, 16);
                    std::cout << "      XXXX               XXXX                      00000000                ZZZZZZZZZZZZZZZZZZZZZZ       XXXX            XXXX";
                    gotoxy(41, 17);
                    std::cout << "      XXXX               XXXX                          000000000           ZZZZZZZZZZZZZZZZZZZZZZ       XXXXXXXXXXXXXXXXXXXX";
                    gotoxy(41, 18);
                    std::cout << "      XXXX               XXXX                            000000000         ZZZZZ                        XXXXXXXXXXXXXXXXX   ";
                    gotoxy(41, 19);
                    std::cout << "      XXXX               XXXX                             000000000        ZZZZZ                        XXXX          XXXXX ";
                    gotoxy(41, 20);
                    std::cout << "      XXXX               XXXX                           000000000          ZZZZZ                        XXXX           XXXXX";
                    gotoxy(41, 21);
                    std::cout << "      XXXX               XXXX                          00000000            ZZZZZ                        XXXX            XXXXX";
                    gotoxy(41, 22);
                    std::cout << "      XXXXXXXXXXXXXXXXXXXXXXX                  00000000000000              ZZZZZZZZZZZZZZZZZZZZZZZ      XXXX             XXXXX";
                    TextColor(12);
                    gotoxy(41, 25);
                    std::cout << "                                                           BY: TEAM-3-DTU";
                    TextColor(6);
					gotoxy(105, 30);
                    // ToMauMenuCon();
                    TextColor(6);
                    gotoxy(105, 30);
                    std::cout << ">> USER MENU <<";
                    gotoxy(100, 30);
                    std::cout << "     ";
                    TextColor(7);
                    gotoxy(105, 32);
                    std::cout << "1. Change Password";
                    gotoxy(100, 32);
                    std::cout << "     ";
                    gotoxy(105, 34);
                    std::cout << "2. Update Info";
                    gotoxy(100, 34);
                    std::cout << "     ";
                    gotoxy(105, 36);
                    std::cout << "3. Loguot";
                    gotoxy(100, 36);
                    std::cout << "     ";
                    gotoxy(105, 38);
                    std::cout << "4. Display User";
                    gotoxy(100, 38);
                    std::cout << "     ";
                    gotoxy(105, 40);
                    std::cout << "5. Manager Patron";
                    gotoxy(100, 40);
                    std::cout << "     ";
                    gotoxy(105, 42);
                    std::cout << "6. Manager Book";
                    gotoxy(100, 42);
                    std::cout << "     ";
                    gotoxy(105, 44);
                    std::cout << "7. Borrow Books (loi)";
                    gotoxy(100, 44);
                    std::cout << "     ";
                    gotoxy(105, 46);
                    std::cout << "8. Return Books (loi)";
                    gotoxy(100, 46);
                    std::cout << "     ";
                    int user_choice;
                    gotoxy(105, 50);
                    std::cout << "Enter Your Choice: ";
                    std::cin >> user_choice;
                    switch (static_cast<NGUOI_DUNG_NHAP>(user_choice))
                    {
                    case CHANGE_PASSWORD:
                    {
                        char ch;
                        std::string newpwd;
                        do
                        {
                            system("cls");
                            setFontSize(30);
                            gotoxy(40, 7);
                            std::cout << "<< CHANGE PASSWORD >>";
                            std::cout << std::endl;
                            gotoxy(40, 10);
                            std::cout << "Enter New Password: ";
                            std::cin >> newpwd;
                            user->changePassword(newpwd);
                            user->saveformfile("user.txt");
                            setFontSize(30);
                            std::cout << "Press ESC to go back to the menu or any other key to change the password again.";
                            ch = _getch();  // _getch() function gets the character from the keyboard
                        } while (ch != 27); // 27 is the ASCII value of ESC
                        setFontSize(16);
                        break;
                    }
                    case UPDATE_INFOR:
                    {
                        char ch;
                        std::string newinfor;
                        do
                        {
                            system("cls");
                            setFontSize(30);
                            gotoxy(40, 7);
                            std::cout << "<< UPDATE INFORMATION >>";
                            std::cout << std::endl;
                            gotoxy(40, 10);
                            std::cout << "Enter New Info: ";
                            std::cin.ignore();
                            std::getline(std::cin, newinfor);
                            user->updateInformation(newinfor);
                            std::cout << "Change User to " << newinfor << " successfully!" << std::endl;
                            setFontSize(30);
                            std::cout << "Press ESC to go back to the menu or any other key to change the infor again.";
                            ch = _getch();
                        } while (ch != 27);
                        setFontSize(16);
                        break;
                    }
                    case LOGOUT:
                    {
                        user->logout();
                        exit = true;
                        std::cout << "Exiting....\n";
                        break;
                    }
                    case DISPLAY_USER:
                    {
                        char ch;
                        do
                        {
                            system("cls");
                            setFontSize(30);
                            gotoxy(40, 7);
                            std::cout << "<< USER INFORMATION >>";
                            std::cout << std::endl;
                            user->output();
                            setFontSize(30);
                            std::cout << "Press ESC to go back to the menu or any other key to display the user again.";
                            ch = _getch();
                            setFontSize(30);
                        } while (ch != 27);
                        setFontSize(16);
                        break;
                    }
                    case MANAGER_PARTRON:
                    {
                        bool exit_mana_partron = false;
                        while (!exit_mana_partron)
                        {
                            system("cls");
                            gotoxy(40, 10);
                            for (int i = 40; i <= 170; i++)
                            {
                                if (i == 40)
                                    putchar(201);
                                else if (i == 170)
                                    putchar(187);
                                else
                                    putchar(205);
                            }
                            for (int i = 11; i <= 25; i++)
                            {
                                gotoxy(40, i);
                                putchar(186);
                                gotoxy(170, i);
                                putchar(186);
                            }
                            gotoxy(40, 26);
                            for (int i = 40; i <= 170; i++)
                            {
                                if (i == 40)
                                    putchar(200);
                                else if (i == 170)
                                    putchar(188);
                                else
                                    putchar(205);
                            }
                            TextColor(14);
                            gotoxy(41, 11);
                            std::cout << "      XXXX               XXXX                  000000000000000             ZZZZZZZZZZZZZZZZZZZZZ        XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 12);
                            std::cout << "      XXXX               XXXX                 00000000000                  ZZZZZ                        XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 13);
                            std::cout << "      XXXX               XXXX               XXXXXXXXX                      ZZZZZ                        XXXX            0000";
                            gotoxy(41, 14);
                            std::cout << "      XXXX               XXXX               00000000                       ZZZZZ                        XXXX            XXXX";
                            gotoxy(41, 15);
                            std::cout << "      XXXX               XXXX                   00000000                   ZZZZZ                        XXXX            XXXX";
                            gotoxy(41, 16);
                            std::cout << "      XXXX               XXXX                      00000000                ZZZZZZZZZZZZZZZZZZZZZZ       XXXX            XXXX";
                            gotoxy(41, 17);
                            std::cout << "      XXXX               XXXX                          000000000           ZZZZZZZZZZZZZZZZZZZZZZ       XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 18);
                            std::cout << "      XXXX               XXXX                            000000000         ZZZZZ                        XXXXXXXXXXXXXXXXX   ";
                            gotoxy(41, 19);
                            std::cout << "      XXXX               XXXX                             000000000        ZZZZZ                        XXXX          XXXXX ";
                            gotoxy(41, 20);
                            std::cout << "      XXXX               XXXX                           000000000          ZZZZZ                        XXXX           XXXXX";
                            gotoxy(41, 21);
                            std::cout << "      XXXX               XXXX                          00000000            ZZZZZ                        XXXX            XXXXX";
                            gotoxy(41, 22);
                            std::cout << "      XXXXXXXXXXXXXXXXXXXXXXX                  00000000000000              ZZZZZZZZZZZZZZZZZZZZZZZ      XXXX             XXXXX";
                            TextColor(12);
                            gotoxy(41, 25);
                            std::cout << "                                                           BY: TEAM-3-DTU";
                            TextColor(6);
                            gotoxy(105, 30);
                            gotoxy(105, 32);
                            std::cout << ">> MANAGE PATRON MENU <<";
                            gotoxy(100, 32);
                            std::cout << "     ";
                            TextColor(7);
                            gotoxy(105, 34);
                            std::cout << "1. View Patron";
                            gotoxy(100, 34);
                            std::cout << "     ";
                            gotoxy(105, 36);
                            std::cout << "2. Add Patron";
                            gotoxy(100, 36);
                            std::cout << "     ";
                            gotoxy(105, 38);
                            std::cout << "3. Edit Patron";
                            gotoxy(100, 38);
                            std::cout << "     ";
                            gotoxy(105, 40);
                            std::cout << "4. Delete Patron";
                            gotoxy(100, 40);
                            std::cout << "     ";
                            gotoxy(105, 42);
                            std::cout << "5. Search By ID";
                            gotoxy(100, 42);
                            std::cout << "     ";
                            gotoxy(105, 44);
                            std::cout << "6. Back To User Data Menu";
                            gotoxy(100, 44);
                            std::cout << "     ";
                            int library_choice;
                            gotoxy(105, 46);
                            std::cout << "Enter Your Choice: ";
                            std::cin >> library_choice;

                            switch (static_cast<MANAGE_PARTRON_MENU>(library_choice))
                            {
                            case VIEW_PARTRON:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< VIEW PATRON >>";
                                    std::cout << std::endl;
                                    library.viewdataList();
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to view the partron again.";
                                    ch = _getch();
                                    setFontSize(30);
                                } while (ch != 27);
                                setFontSize(16);
                                break;
                            }
                            case ADD_PARTRON:
                            {
                                char ch;
                                std::string id, name, contactinfor;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< ADD PATRON >>";
                                    std::cout << std::endl;
                                    std::cout << "Enter Patron ID: ";
                                    std::cin >> id;
                                    std::cout << "Enter Patron Name: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, name);
                                    std::cout << "Enter Patron Contact Info: ";
                                    std::getline(std::cin, contactinfor);
                                    library.addReader(id, name, contactinfor);
                                    library.saveformfilepartron("patron.txt");
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to add the partron again.";
                                    ch = _getch();
                                } while (ch != 27);
                                setFontSize(16);
                                break;
                            }
                            case EDIT_PARTRON:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< EDIT PATRON >>";
                                    std::cout << std::endl;
                                    std::string id, newname, newcontactinfor;
                                    std::cout << "Enter Patron ID to edit: ";
                                    std::cin >> id;
                                    std::cout << "Enter New Name: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, newname);
                                    std::cout << "Enter New Contact Info: ";
                                    std::getline(std::cin, newcontactinfor);
                                    library.editReaderInfo(id, newname, newcontactinfor);
                                    library.saveformfilepartron("patron.txt");
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to edit the partron again.";
                                    ch = _getch();
                                } while (ch != 27);
                                setFontSize(16);
                                break;
                            }
                            case DELETE_PARTRON:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< DELETE PATRON >>";
                                    std::cout << std::endl;
                                    std::string delete_partron;
                                    std::cout << "Enter Patron ID to delete: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, delete_partron);
                                    library.deleteReader(delete_partron);
                                    library.saveformfilepartron("patron.txt");
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to delete the partron again.";
                                    ch = _getch();
                                } while (ch != 27);
                                setFontSize(16);
                                break;
                            }
                            case SEARCH_BY_ID:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< SEARCH BY ID >>";
                                    std::cout << std::endl;
                                    std::string id;
                                    std::cout << "Enter Patron ID to search: ";
                                    std::cin >> id;
                                    library.searchidpatron(id);
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to search the partron again.";
                                    ch = _getch();
                                } while (ch != 27);
                                setFontSize(16);
                                break;
                            }
                            case BACK_TO_USER_DATA_MENU:
                            {
                                exit_mana_partron = true;
                                break;
                            }
                            default:
                                std::cout << "Invalid Choice. Try Again.\n";
                                break;
                            }
                        }
                        break;
                    }
                    case MANAGER_BOOK:
                    {
                        bool exit_mana_book = false;
                        while (!exit_mana_book)
                        {
                            system("cls");
                            gotoxy(40, 10);
                            for (int i = 40; i <= 170; i++)
                            {
                                if (i == 40)
                                    putchar(201);
                                else if (i == 170)
                                    putchar(187);
                                else
                                    putchar(205);
                            }
                            for (int i = 11; i <= 25; i++)
                            {
                                gotoxy(40, i);
                                putchar(186);
                                gotoxy(170, i);
                                putchar(186);
                            }
                            gotoxy(40, 26);
                            for (int i = 40; i <= 170; i++)
                            {
                                if (i == 40)
                                    putchar(200);
                                else if (i == 170)
                                    putchar(188);
                                else
                                    putchar(205);
                            }
                            TextColor(14);

                            gotoxy(41, 11);
                            std::cout << "      XXXX               XXXX                  000000000000000             ZZZZZZZZZZZZZZZZZZZZZ        XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 12);
                            std::cout << "      XXXX               XXXX                 00000000000                  ZZZZZ                        XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 13);
                            std::cout << "      XXXX               XXXX               XXXXXXXXX                      ZZZZZ                        XXXX            0000";
                            gotoxy(41, 14);
                            std::cout << "      XXXX               XXXX               00000000                       ZZZZZ                        XXXX            XXXX";
                            gotoxy(41, 15);
                            std::cout << "      XXXX               XXXX                   00000000                   ZZZZZ                        XXXX            XXXX";
                            gotoxy(41, 16);
                            std::cout << "      XXXX               XXXX                      00000000                ZZZZZZZZZZZZZZZZZZZZZZ       XXXX            XXXX";
                            gotoxy(41, 17);
                            std::cout << "      XXXX               XXXX                          000000000           ZZZZZZZZZZZZZZZZZZZZZZ       XXXXXXXXXXXXXXXXXXXX";
                            gotoxy(41, 18);
                            std::cout << "      XXXX               XXXX                            000000000         ZZZZZ                        XXXXXXXXXXXXXXXXX   ";
                            gotoxy(41, 19);
                            std::cout << "      XXXX               XXXX                             000000000        ZZZZZ                        XXXX          XXXXX ";
                            gotoxy(41, 20);
                            std::cout << "      XXXX               XXXX                           000000000          ZZZZZ                        XXXX           XXXXX";
                            gotoxy(41, 21);
                            std::cout << "      XXXX               XXXX                          00000000            ZZZZZ                        XXXX            XXXXX";
                            gotoxy(41, 22);
                            std::cout << "      XXXXXXXXXXXXXXXXXXXXXXX                  00000000000000              ZZZZZZZZZZZZZZZZZZZZZZZ      XXXX             XXXXX";
                            TextColor(12);
                            gotoxy(41, 25);
                            std::cout << "                                                           BY: TEAM-3-DTU";
                            TextColor(6);
                            gotoxy(105, 30);
                            TextColor(6);
                            gotoxy(105, 32);
                            std::cout << ">> MANAGE BOOK MENU <<";
                            gotoxy(100, 32);
                            std::cout << "     ";
                            TextColor(7);
                            gotoxy(105, 34);
                            std::cout << "1. View Book";
                            gotoxy(100, 34);
                            std::cout << "     ";
                            gotoxy(105, 36);
                            std::cout << "2. Add Book";
                            gotoxy(100, 36);
                            std::cout << "     ";
                            gotoxy(105, 38);
                            std::cout << "3. Edit Book";
                            gotoxy(100, 38);
                            std::cout << "     ";
                            gotoxy(105, 40);
                            std::cout << "4. Delete Book";
                            gotoxy(100, 40);
                            std::cout << "     ";
                            gotoxy(105, 42);
                            std::cout << "5. Search Book By ID";
                            gotoxy(100, 42);
                            std::cout << "     ";
                            gotoxy(105, 44);
                            std::cout << "6. Back To User Data Menu";
                            gotoxy(100, 44);
                            std::cout << "     ";
                            int book_choice;
                            gotoxy(105, 46);
                            std::cout << "Enter Your Choice: ";
                            std::cin >> book_choice;
                            switch (static_cast<MANAGE_BOOK_MENU>(book_choice))
                            {
                            case VIEW_BOOK:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< VIEW BOOK >>";
                                    std::cout << std::endl;
                                    library.viewbookList();
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to view the book again.";
                                    ch = _getch();
                                } while (ch != 27); // 27 is the ASCII value of ESC
                                setFontSize(16);
                                break;
                            }
                            case ADD_BOOK:
                            {
                                char ch;
                                std::string id, title, patron;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< ADD BOOK >>";
                                    std::cout << std::endl;
                                    std::cout << "Id: ";
                                    std::cin >> id;
                                    std::cout << "Title: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, title);
                                    std::cout << "Patron: ";
                                    std::getline(std::cin, patron);
                                    library.addBook(id, title, patron);
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to view the book again.";
                                    ch = _getch();
                                } while (ch != 27); // 27 is the ASCII value of ESC
                                setFontSize(16);
                                break;
                            }
                            case EDIT_BOOK:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< EDIT BOOK >>";
                                    std::cout << std::endl;
                                    std::string id, newtitle, newpatron;
                                    std::cout << "Enter Book ID to edit: ";
                                    std::cin >> id;
                                    std::cout << "Enter New Title: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, newtitle);
                                    std::cout << "Enter New Patron: ";
                                    std::getline(std::cin, newpatron);
                                    library.editbookinfor(id, newtitle, newpatron);
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to edit the book again.";
                                    ch = _getch();
                                } while (ch != 27); // 27 is the ASCII value of ESC
                                setFontSize(16);
                                break;
                            }
                            case DELETE_BOOK:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< DELETE BOOK >>";
                                    std::cout << std::endl;
                                    std::string delete_book;
                                    std::cout << "Enter Book ID to delete: ";
                                    std::cin.ignore();
                                    std::getline(std::cin, delete_book);
                                    library.deleteBook(delete_book);
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to delete the book again.";
                                    ch = _getch();
                                } while (ch != 27); // 27 is the ASCII value of ESC
                                setFontSize(16);
                                break;
                            }
                            case SEARCH_BY_ID:
                            {
                                char ch;
                                do
                                {
                                    system("cls");
                                    setFontSize(30);
                                    gotoxy(40, 7);
                                    std::cout << "<< SEARCH BY ID >>";
                                    std::cout << std::endl;
                                    std::string id;
                                    std::cout << "Enter Book ID to search: ";
                                    std::cin >> id;
                                    library.searchidbook(id);
                                    setFontSize(30);
                                    std::cout << "Press ESC to go back to the menu or any other key to search the book again.";
                                    ch = _getch();
                                } while (ch != 27); // 27 is the ASCII value of ESC
                                setFontSize(16);
                                break;
                            }
                            case BACK_TO_USER_DATA_MENU:
                            {
                                exit_mana_book = true;
                                break;
                            }
                            default:
                                std::cout << "Invalid Choice. Try Again.\n";
                                break;
                            }
                        }
                        break;
                    }
                    case BORROW_BOOK:
                    {
                        char ch;
                        do
                        {
                            system("cls");
                            setFontSize(30);
                            gotoxy(40, 7);
                            std::cout << "<< BORROW BOOK >>";
                            std::cout << std::endl;
                            std::string title;
                            std::cout << "Enter Book Title: ";
                            std::cin.ignore();
                            std::getline(std::cin, title);
                            library.borrow_book(title);
                            setFontSize(30);
                            std::cout << "Press ESC to go back to the menu or any other key to search the book again.";
                            ch = _getch();
                        } while (ch != 27);
                        setFontSize(16);
                        break;
                    }
                    case RETURN_BOOK:
                    {
                        char ch;
                        do
                        {
                            system("cls");
                            setFontSize(30);
                            gotoxy(40, 7);
                            std::cout << "<< RETURN BOOK >>";
                            std::cout << std::endl;
                            std::string title;
                            std::cout << "Enter Book Title: ";
                            std::cin.ignore();
                            std::getline(std::cin, title);
                            library.return_book(title);
                            setFontSize(30);
                            std::cout << "Press ESC to go back to the menu or any other key to search the book again.";
                            ch = _getch();
                        } while (ch != 27);
                        setFontSize(16);
                        break;
                    }
                    case NGUOIDUNG_USER_EXIT:
                        std::cout << "Exiting...\n";
                        return 0;
                    default:
                        std::cout << "Invalid Choice. Try Again.\n";
                        return 0;
                        break;
                    }
                }
            }
            break;
        }
        case ALL_NGUOIDUNG_EXIT:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid Choice. Try Again.\n";
            break;
        }
    } while (!true);
}