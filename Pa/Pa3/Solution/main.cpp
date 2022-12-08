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

// Adding two mails to the same district
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

void afterTestcase1()
{
    Mail *m = new Mail(1, "Sample Address 1", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Hash Checking", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Hash Checking", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Hash Checking", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::SaiKung, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(6, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(6, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(6, "Sample Address 14", District::SaiKung, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(6, "Sample Address 3", District::SaiKung, "Hash Checking", "This should result in 9");

    if(m->getAddressHash() == 0 &&
        m1->getAddressHash() == 1 &&
        m2->getAddressHash() == 2 &&
        m3->getAddressHash() == 3 &&
        m4->getAddressHash() == 4 &&
        m5->getAddressHash() == 5 &&
        m6->getAddressHash() == 6 &&
        m7->getAddressHash() == 7 &&
        m8->getAddressHash() == 8 &&
        m9->getAddressHash() == 9)
    {
        cout << "Address Hash Function Verified" << endl;
    }
    else
    {
        cout << "Address Hash Function NOT verified" << endl;
    }
    delete m;
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    delete m6;
    delete m7;
    delete m8;
    delete m9;
}


// Covers adding and printing district based on inorder
void afterTestcase2()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->printDistrict(District::SaiKung, printType::inorder);
    std::cout <<"" << std::endl;
    po->printDistrict(District::CentralAndWestern, printType::inorder);
    delete po;
}


void afterTestcase3()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");

    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->printMailman(District::SaiKung,6, printType::inorder);
    delete po;
}
void afterTestcase4() {
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->printDistrict(District::SaiKung, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::SaiKung, printType::preorder);
    std::cout << "-------" << std::endl;

    po->printDistrict(District::SaiKung, printType::postorder);

    delete po;

}

void afterTestcase5() {
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 1", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 1", District::SaiKung, "Hash Checking 2", "This should result in 0");
    Mail *m2 = new Mail(3, "Sample Address 1", District::SaiKung, "Hash Checking 3", "This should result in 0");
    Mail *m3 = new Mail(4, "Sample Address 1", District::SaiKung, "Hash Checking 4", "This should result in 0");
    Mail *m4 = new Mail(5, "Sample Address 1", District::SaiKung, "Hash Checking 5", "This should result in 0");
    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->printMailman(SaiKung, 0, inorder);
    delete po;
}

void afterTestcase6() {
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::North, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::North, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::North, "Yet Another Street", "This should result in 4");
    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->printDistrict(District::North, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::SaiKung, printType::inorder);
    delete po;

}

void afterTestcase7() {
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::North, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::North, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 3", District::North, "Yet Another Street", "This should result in 4");
    Mail *m6 = new Mail(7, "Sample Address 3", District::CentralAndWestern, "Yet Another Street", "This should result in 4");
    Mail *m7 = new Mail(8, "Sample Address 3", District::WanChai, "Yet Another Street", "This should result in 4");
    Mail *m8 = new Mail(9, "Sample Address 3", District::Kowloon, "Yet Another Street", "This should result in 4");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Yet Another Street", "This should result in 4");
    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);



    po->printDistrict(District::SaiKung, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::North, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::CentralAndWestern, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::WanChai, printType::inorder);
    std::cout << "-------" << std::endl;
    po->printDistrict(District::Kowloon, printType::inorder);
    delete po;

}


void afterTestcase8()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");

    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);


    Mail *found = po->find(District::CentralAndWestern, 6, "Hash Checking");
    if(found == m5)
    {
        std::cout << "Found!" << std::endl;
    }
    found = po->find(District::SaiKung, 3, "Another Street");
    if(found == m2)
    {
        std::cout << "Found!" << std::endl;
    }
    delete po;
}
void afterTestcase9()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");

    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);


    bool flag = po->remove(District::CentralAndWestern, 6, "Hash Checking");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }
    flag = po->remove(District::CentralAndWestern, 7, "Hash Checking");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }
    flag = po->remove(District::CentralAndWestern, 8, "Hash Checking");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }

    flag = po->remove(District::CentralAndWestern, 9, "Hash Checking");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }

    flag = po->remove(District::CentralAndWestern, 10, "Hash Checking");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }
    delete po;
}
void afterTestcase10()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");

    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);


    bool flag = po->remove(District::CentralAndWestern, 6, "Non-existing street");
    if(flag == false)
    {
        std::cout << "Successfully Not Removed!" << std::endl;
    }
    flag = po->remove(District::CentralAndWestern, 22, "Hash Checking");
    if(flag == false)
    {
        std::cout << "Successfully Not Removed!" << std::endl;
    }
    flag = po->remove(District::Kowloon, 8, "Non-Existing District");
    if(flag == false)
    {
        std::cout << "Successfully Not Removed!" << std::endl;
    }
    delete po;
}
void afterTestcase11()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");

    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);


    Mail *found = po->find(District::CentralAndWestern, 6, "Non-Existent Street");
    if(found == nullptr)
    {
        std::cout << "Not found!" << std::endl;
    }
    found = po->find(District::SaiKung, 24, "Another Street");
    if(found == nullptr)
    {
        std::cout << "Not found!" << std::endl;
    }
    found = po->find(District::CentralAndWestern, 11, "Another Street");
    if(found == nullptr)
    {
        std::cout << "Not found!" << std::endl;
    }

    delete po;
}
void afterTestcase12()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::North, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::North, "Hash Checking", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::North, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::North, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::North, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::Eastern, "Hash Checking", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::Eastern, "Hash Checking", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::Eastern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::Eastern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::Eastern, "Hash Checking", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::Kowloon, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::Kowloon, "Hash Checking", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::Kowloon, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::Kowloon, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::Kowloon, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::Islands, "Hash Checking", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::Islands, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::Islands, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::ShaTin, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::ShaTin, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::ShaTin, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::KwaiTsing, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::KwaiTsing, "Hash Checking", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::KwaiTsing, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::TaiPo, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::TaiPo, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::TaiPo, "Hash Checking", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::TsuenWan, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::TsuenWan, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::TsuenWan, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::TuenMun, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::TuenMun, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::TuenMun, "Hash Checking", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::YuenLong, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::YuenLong, "Hash Checking", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::YuenLong, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::KwunTong, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::KwunTong, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::ShamShuiPo, "Hash Checking", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::ShamShuiPo, "Hash Checking", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::WongTaiSin, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::YauTsimMong, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::YauTsimMong, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::Southern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::Southern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::WanChai, "Hash Checking", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::WanChai, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::WongTaiSin, "Hash Checking", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printInOrder();
    delete po;
}
void afterTestcase13()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::North, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::North, "Hash Checking", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::North, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::North, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::North, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::Eastern, "Hash Checking", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::Eastern, "Hash Checking", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::Eastern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::Eastern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::Eastern, "Hash Checking", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::Kowloon, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::Kowloon, "Hash Checking", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::Kowloon, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::Kowloon, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::Kowloon, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::Islands, "Hash Checking", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::Islands, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::Islands, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::ShaTin, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::ShaTin, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::ShaTin, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::KwaiTsing, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::KwaiTsing, "Hash Checking", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::KwaiTsing, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::TaiPo, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::TaiPo, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::TaiPo, "Hash Checking", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::TsuenWan, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::TsuenWan, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::TsuenWan, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::TuenMun, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::TuenMun, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::TuenMun, "Hash Checking", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::YuenLong, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::YuenLong, "Hash Checking", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::YuenLong, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::KwunTong, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::KwunTong, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::ShamShuiPo, "Hash Checking", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::ShamShuiPo, "Hash Checking", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::WongTaiSin, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::YauTsimMong, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::YauTsimMong, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::Southern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::Southern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::WanChai, "Hash Checking", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::WanChai, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::WongTaiSin, "Hash Checking", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printPreOrder();
    delete po;
}
void afterTestcase14()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::SaiKung, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::SaiKung, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::SaiKung, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::SaiKung, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::SaiKung, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::North, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::North, "Hash Checking", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::North, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::North, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::North, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::Eastern, "Hash Checking", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::Eastern, "Hash Checking", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::Eastern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::Eastern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::Eastern, "Hash Checking", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::Kowloon, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::Kowloon, "Hash Checking", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::Kowloon, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::Kowloon, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::Kowloon, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::Islands, "Hash Checking", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::Islands, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::Islands, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::Islands, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::ShaTin, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::ShaTin, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::ShaTin, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::ShaTin, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::KwaiTsing, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::KwaiTsing, "Hash Checking", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::KwaiTsing, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::KwaiTsing, "Hash Checking", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::TaiPo, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::TaiPo, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::TaiPo, "Hash Checking", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::TaiPo, "Hash Checking", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::TsuenWan, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::TsuenWan, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::TsuenWan, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::TsuenWan, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::TuenMun, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::TuenMun, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::TuenMun, "Hash Checking", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::TuenMun, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::YuenLong, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::YuenLong, "Hash Checking", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::YuenLong, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::YuenLong, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::KwunTong, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::KwunTong, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::KwunTong, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::ShamShuiPo, "Hash Checking", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::ShamShuiPo, "Hash Checking", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::ShamShuiPo, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::WongTaiSin, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::WongTaiSin, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::YauTsimMong, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::YauTsimMong, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::YauTsimMong, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::Southern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::Southern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::Southern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::WanChai, "Hash Checking", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::WanChai, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::WanChai, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::WongTaiSin, "Hash Checking", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printPostOrder();
    delete po;
}
void afterTestcase15()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::CentralAndWestern, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::CentralAndWestern, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printDistrict(CentralAndWestern, inorder);
    delete po;
}
void afterTestcase16()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::CentralAndWestern, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::CentralAndWestern, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printDistrict(CentralAndWestern, preorder);
    delete po;
}
void afterTestcase17()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 0");
    Mail *m1 = new Mail(2, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 1");
    Mail *m2 = new Mail(3, "Sample Address", District::CentralAndWestern, "Another Street", "This should result in 2");
    Mail *m3 = new Mail(4, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 3");
    Mail *m4 = new Mail(5, "Sample Address 3", District::CentralAndWestern, "Yet Another Street", "This should result in 4");
    Mail *m5 = new Mail(6, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m6 = new Mail(7, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m7 = new Mail(8, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m8 = new Mail(9, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m9 = new Mail(10, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m10 = new Mail(11, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m11 = new Mail(12, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m12 = new Mail(13, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m13 = new Mail(14, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m14 = new Mail(15, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m15 = new Mail(16, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m16 = new Mail(17, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m17 = new Mail(18, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m18 = new Mail(19, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m19 = new Mail(20, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m20 = new Mail(21, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m21 = new Mail(22, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m22 = new Mail(23, "Sample Address 2", District::CentralAndWestern, "Hash Checking", "This should result in 7");
    Mail *m23 = new Mail(24, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m24 = new Mail(25, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m25 = new Mail(26, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m26 = new Mail(27, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m27 = new Mail(28, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m28 = new Mail(29, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m29 = new Mail(30, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m30 = new Mail(31, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m31 = new Mail(32, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m32 = new Mail(33, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m33 = new Mail(34, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m34 = new Mail(35, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m35 = new Mail(36, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m36 = new Mail(37, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m37 = new Mail(38, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m38 = new Mail(39, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m39 = new Mail(40, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m40 = new Mail(41, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m41 = new Mail(42, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m42 = new Mail(43, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m43 = new Mail(44, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m44 = new Mail(45, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m45 = new Mail(46, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m46 = new Mail(47, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m47 = new Mail(48, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m48 = new Mail(49, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m49 = new Mail(50, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m50 = new Mail(51, "Sample Address 6", District::CentralAndWestern, "Another Street", "This should result in 5");
    Mail *m51 = new Mail(52, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m52 = new Mail(53, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m53 = new Mail(54, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m54 = new Mail(55, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m55 = new Mail(56, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m56 = new Mail(57, "Sample Address 6", District::CentralAndWestern, "Hash Checking", "This should result in 5");
    Mail *m57 = new Mail(58, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m58 = new Mail(59, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m59 = new Mail(60, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m60 = new Mail(61, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m61 = new Mail(62, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m62 = new Mail(63, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m63 = new Mail(64, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m64 = new Mail(65, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m65 = new Mail(66, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m66 = new Mail(67, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m67 = new Mail(68, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");
    Mail *m68 = new Mail(69, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m69 = new Mail(70, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m70 = new Mail(71, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m71 = new Mail(72, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m72 = new Mail(74, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m73 = new Mail(75, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m74 = new Mail(76, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m75 = new Mail(77, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m76 = new Mail(78, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m77 = new Mail(79, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m78 = new Mail(80, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m79 = new Mail(81, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m80 = new Mail(82, "Sample Address 4", District::CentralAndWestern, "Hash Checking", "This should result in 6");
    Mail *m81 = new Mail(83, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m82 = new Mail(84, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m83 = new Mail(85, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m84 = new Mail(86, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m85 = new Mail(87, "Sample Address 4", District::CentralAndWestern, "Another Street", "This should result in 6");
    Mail *m86 = new Mail(88, "Sample Address 14", District::CentralAndWestern, "Hash Checking", "This should result in 8");
    Mail *m87 = new Mail(89, "Sample Address 3", District::CentralAndWestern, "Another Street", "This should result in 9");
    Mail *m88 = new Mail(90, "Sample Address 3", District::CentralAndWestern, "Hash Checking", "This should result in 9");
    Mail *m89 = new Mail(73, "Sample Address 14", District::CentralAndWestern, "Another Street", "This should result in 8");


    po->addMail(m);
    po->addMail(m1);
    po->addMail(m2);
    po->addMail(m3);
    po->addMail(m4);
    po->addMail(m5);
    po->addMail(m6);
    po->addMail(m7);
    po->addMail(m8);
    po->addMail(m9);
    po->addMail(m10);
    po->addMail(m11);
    po->addMail(m12);
    po->addMail(m13);
    po->addMail(m14);
    po->addMail(m15);
    po->addMail(m16);
    po->addMail(m17);
    po->addMail(m18);
    po->addMail(m19);
    po->addMail(m20);
    po->addMail(m21);
    po->addMail(m22);
    po->addMail(m23);
    po->addMail(m24);
    po->addMail(m25);
    po->addMail(m26);
    po->addMail(m27);
    po->addMail(m28);
    po->addMail(m29);
    po->addMail(m30);
    po->addMail(m31);
    po->addMail(m32);
    po->addMail(m33);
    po->addMail(m34);
    po->addMail(m35);
    po->addMail(m36);
    po->addMail(m37);
    po->addMail(m38);
    po->addMail(m39);
    po->addMail(m40);
    po->addMail(m41);
    po->addMail(m42);
    po->addMail(m43);
    po->addMail(m44);
    po->addMail(m45);
    po->addMail(m46);
    po->addMail(m47);
    po->addMail(m48);
    po->addMail(m49);
    po->addMail(m50);
    po->addMail(m51);
    po->addMail(m52);
    po->addMail(m53);
    po->addMail(m54);
    po->addMail(m55);
    po->addMail(m56);
    po->addMail(m57);
    po->addMail(m58);
    po->addMail(m59);
    po->addMail(m60);
    po->addMail(m61);
    po->addMail(m62);
    po->addMail(m63);
    po->addMail(m64);
    po->addMail(m65);
    po->addMail(m66);
    po->addMail(m67);
    po->addMail(m68);
    po->addMail(m69);
    po->addMail(m70);
    po->addMail(m71);
    po->addMail(m72);
    po->addMail(m73);
    po->addMail(m74);
    po->addMail(m75);
    po->addMail(m76);
    po->addMail(m77);
    po->addMail(m78);
    po->addMail(m79);
    po->addMail(m80);
    po->addMail(m81);
    po->addMail(m82);
    po->addMail(m83);
    po->addMail(m84);
    po->addMail(m85);
    po->addMail(m86);
    po->addMail(m87);
    po->addMail(m88);
    po->addMail(m89);
    po->printDistrict(CentralAndWestern, postorder);
    delete po;
}


// NEED TO GO UP TO 34
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
        case 18:
            afterTestcase1();
            break;
        case 19:
            afterTestcase2();
            break;
        case 20:
            afterTestcase3();
            break;
        case 21:
            afterTestcase4();
            break;
        case 22:
            afterTestcase5();
            break;
        case 23:
            afterTestcase6();
            break;
        case 24:
            afterTestcase7();
            break;
        case 25:
            afterTestcase8();
            break;
        case 26:
            afterTestcase9();
            break;
        case 27:
            afterTestcase10();
            break;
        case 28:
            afterTestcase11();
            break;
        case 29:
            afterTestcase12();
            break;
        case 30:
            afterTestcase13();
            break;
        case 31:
            afterTestcase14();
            break;
        case 32:
            afterTestcase15();
            break;
        case 33:
            afterTestcase16();
            break;
        case 34:
            afterTestcase17();
            break;
    }
}