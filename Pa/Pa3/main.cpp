// #include <iostream>
// #include "BST_PostOffice.h"

// using namespace std;

// BST_PostOffice *po;
// int mailCount = 1;

// void sendMail()
// {
//     string address = "";
//     int district = 0;
//     string streetName = "";
//     string content = "";
//     cout << "Please enter the address: \n" << endl;
//     cin.clear();
//     cin.sync();
//     cin.ignore();
//     getline(cin, address);
//     cout << "-----------------------------------" << endl;
//     cout << "Please enter the street name: \n" << endl;
//     cin.clear();
//     cin.sync();
//     getline(cin, streetName);
//     cout << "-----------------------------------" << endl;
//     cout << "Please enter the district number: " << endl;
//     cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
//     cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
//     cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
//     cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
//     cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
//     cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

//     cin.clear();
//     cin.sync();
//     string strTemp = "";
//     getline(cin, strTemp);
//     district = stoi( strTemp);
//     cout << "-----------------------------------" << endl;
//     cout << "Please enter the content: \n" << endl;
//     cin.clear();
//     cin.sync();
//     getline(cin, content);
//     Mail *m = new Mail(mailCount, address, District(district), streetName, content);
//     po->addMail(m);
//     cout << "Your mail has been posted!" << endl;
//     cout << "-------------------------------------------------------------------------" << endl;
//     cin.clear();
//     cin.sync();
//     cin.ignore();
// }

// void removeMail()
// {
//     string districtStr;
//     string streetName;
//     string idStr;
//     cout << "Please enter the district number: " << endl;
//     cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
//     cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
//     cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
//     cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
//     cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
//     cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

//     cin.clear();
//     cin.sync();
//     cin.ignore();
//     getline(cin, districtStr);
//     cout << "-----------------------------------" << endl;
//     cout << "Please enter the street name: \n" << endl;
//     cin.clear();
//     cin.sync();
//     getline(cin, streetName);
//     cout << "-----------------------------------" << endl;
//     cout << "Please enter the ID number of the mail item: \n" << endl;
//     cin.clear();
//     cin.sync();
//     getline(cin, idStr);
//     cout << "-----------------------------------" << endl;

//     bool success = po->remove(District(stoi(districtStr)), stoi(idStr), streetName);
//     if(success)
//     {
//         cout << "We have removed the mail item from delivery schedule! \n" << endl;
//         cout << "-----------------------------------" << endl;
//     }
//     else
//     {
//         cout << "We didn't find the mail item in our circulation. Try again. \n" << endl;
//         cout << "-----------------------------------" << endl;
//     }
//     cin.clear();
//     cin.sync();
//     cin.ignore();
// }

// void printForPostOffice( printType type)
// {
//     int district;
//     cout << "Please enter the district number: " << endl;
//     cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
//     cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
//     cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
//     cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
//     cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
//     cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

//     cin.clear();
//     cin.sync();
//     cin.ignore();
//     cin >> district;
//     po->printDistrict(District(district), type);
// }

// void printForPostman(printType type)
// {
//     int district;
//     int cc;
//     cout << "Please enter the district number: " << endl;
//     cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
//     cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
//     cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
//     cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
//     cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
//     cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

//     cin.clear();
//     cin.sync();
//     cin.ignore();
//     cin >> district;
//     cout << "Please enter the courier code: \n" << endl;
//     cin.clear();
//     cin.sync();
//     cin.ignore();
//     cin >> cc;
//     po->printMailman(District(district), cc, type);
// }

// void printPO(printType type)
// {
//     switch (type) {
//         case printType::inorder:
//             po->printInOrder();
//             break;
//         case printType::postorder:
//             po->printPostOrder();
//             break;
//         case printType::preorder:
//             po->printPreOrder();
//             break;
//         default:
//             break;
//     }
// }

// int main()
// {
//     po = new BST_PostOffice;
//     cout << "Welcome to Central Post Office!" << endl;
//     while(true)
//     {
//         cout << "Please choose an option from the list below" << endl;
//         cout << "1) Send a mail item" << endl;
//         cout << "2) Remove a mail item from circulation" << endl;
//         cout << "3) Print the current mail distribution report for district post offices (inorder)" << endl;
//         cout << "4) Print the current mail distribution report for district post offices (postorder)" << endl;
//         cout << "5) Print the current mail distribution report for district post offices (preorder)" << endl;
//         cout << "6) Print the mail courier workload for today (inorder)" << endl;
//         cout << "7) Print the mail courier workload for today (postorder)" << endl;
//         cout << "8) Print the mail courier workload for today (preorder)" << endl;
//         cout << "9) Print the mail system (inorder)" << endl;
//         cout << "10) Print the mail system (postorder)" << endl;
//         cout << "11) Print the mail system (preorder)" << endl;
//         cout << "12) Exit Program" << endl;
//         cout << "-------------------------------------------------------------------------" << endl;

//         string i = "";
//         int x = 0;
//         bool exitFlag = false;
//         cin >> i;
//         // A quick note on how try-catch works:
//         // If anything within a try block throws an error, then catch block starts to work, handling the error instead
//         // of throwing a runtime error and shutting off the program.

//         // see https://en.cppreference.com/w/cpp/language/try_catch for more details
//         try
//         {
//             x = stoi(i);
//         }
//         catch (...)
//         {
//             cout << "Please enter a valid request." << endl;
//             cout << "-------------------------------------------------------------------------" << endl;
//             continue;
//         }

//         switch (x) {
//             case 1:
//                 sendMail();
//                 break;
//             case 2:
//                 removeMail();
//                 break;
//             case 3:
//                 printForPostOffice(printType::inorder);
//                 break;
//             case 4:
//                 printForPostOffice(printType::postorder);
//                 break;
//             case 5:
//                 printForPostOffice(printType::preorder);
//                 break;
//             case 6:
//                 printForPostman(printType::inorder);
//                 break;
//             case 7:
//                 printForPostman(printType::postorder);
//                 break;
//             case 8:
//                 printForPostman(printType::preorder);
//                 break;
//             case 9:
//                 printPO(printType::inorder);
//                 break;
//             case 10:
//                 printPO(printType::postorder);
//                 break;
//             case 11:
//                 printPO(printType::preorder);
//                 break;
//             case 12:
//                 exitFlag = true;
//                 break;
//             default:
//                 break;
//         }

//         if(exitFlag)
//         {
//             cout << "Thank you for visiting the Central Post Office. Goodbye!" <<endl;
//             break;
//         }
//     }
//     return 0;
// }

//
// Created by Yigit Sen on 16/11/2022.
//
#include <iostream>
#include "BST_PostOffice.h"
using namespace std;
void testcase1()
{
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    if(m->getAddressHash() == 2)
    {
        cout << "Address Hash Function Verified" << endl;
    }
    else
    {
        cout << "Address Hash Function NOT verified" << endl;
    }
    delete m;
}


// Covers adding and printing district based on inorder
void testcase2()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    po->printDistrict(District::SaiKung, printType::inorder);
    delete po;
}

// Covers adding and printing based on mailman
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase3()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    po->printMailman(District::SaiKung,2, printType::inorder);
    delete po;

}

// Adding two mails to the the same district
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase4()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address, Sai Kung Town", District::SaiKung, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    delete po;

}

// Adding two mails to the same mailman
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase5()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::SaiKung, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    delete po;

}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase6()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    po->printDistrict(District::CentralAndWestern,printType::inorder);
    po->printInOrder();
    delete po;

}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase7()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);

    po->printDistrict(District::SaiKung,printType::inorder);
    po->printDistrict(District::CentralAndWestern,printType::inorder);
    po->printInOrder();
    delete po;
}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase8()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail * find = po->find(District::CentralAndWestern, 4, "Sample");
    if(find == m4)
    {
        std::cout << "Pointers Match!" << std::endl;
    }
    delete po;
}
void testcase9()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    bool flag = po->remove(District::CentralAndWestern, 4, "Sample");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }
    delete po;
}

void testcase10()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    bool flag = po->remove(District::SaiKung, 4, "Sample");
    if(flag == false)
    {
        std::cout << "Successfully Not Removed!" << std::endl;
    }
    delete po;
}

void testcase11()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail * flag = po->find(District::CentralAndWestern, 4, "Sample 2");
    if(flag == nullptr)
    {
        std::cout << "Successfully Not Found!" << std::endl;
    }
    delete po;
}

void testcase12()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);


    po->printInOrder();
    delete po;
}


void testcase13()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printPreOrder();
    delete po;
}
void testcase14()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printPostOrder();
    delete po;
}


void testcase15()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::inorder);
    delete po;
}

void testcase16()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::preorder);
    delete po;
}
void testcase17()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::postorder);
    delete po;
}


int main()
{
    int testcase = 0;
    cin >> testcase;
    switch(testcase)
    {
        case 1:
            testcase1();
            break;
        case 2:
            testcase2();
            break;
        case 3:
            testcase3();
            break;
        case 4:
            testcase4();
            break;
        case 5:
            testcase5();
            break;
        case 6:
            testcase6();
            break;
        case 7:
            testcase7();
            break;
        case 8:
            testcase8();
            break;
        case 9:
            testcase9();
            break;
        case 10:
            testcase10();
            break;
        case 11:
            testcase11();
            break;
        case 12:
            testcase12();
            break;
        case 13:
            testcase13();
            break;
        case 14:
            testcase14();
            break;
        case 15:
            testcase15();
            break;
        case 16:
            testcase16();
            break;
        case 17:
            testcase17();
            break;
    }
}