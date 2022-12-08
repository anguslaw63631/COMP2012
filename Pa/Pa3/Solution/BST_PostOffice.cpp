//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

void BST_PostOffice::addMail(Mail *mail)
{
    if(root == nullptr)
    {
        root = new BST_PostOffice_Node(mail);
    }
    else if(root->getDistrict() == mail->getDistrict())
    {
        root->addMail(mail);
    }
    else if(root -> getDistrict() < mail->getDistrict())
    {
        root->getRightBST()->addMail(mail);
    }
    else if(root->getDistrict() > mail->getDistrict())
    {
        root->getLeftBST()->addMail(mail);
    }
}
void BST_PostOffice_Node::addMail(Mail *mail)
{
    mailman[mail->getAddressHash()].addMail(mail);
}
BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail)
{
    addMail(mail);
    district = mail->getDistrict();
    right = new BST_PostOffice;
    left = new BST_PostOffice;
}
BST_PostOffice * BST_PostOffice_Node::getLeftBST() const
{
    return left;
}
BST_PostOffice * BST_PostOffice_Node::getRightBST() const
{
    return right;
}
BST_PostOffice::BST_PostOffice() {root = nullptr;}
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{
    if(root == nullptr)
    {
        return false;
    }
    else if(root->getDistrict() == dist)
    {
        return root->remove(id, streetName);
    }
    else if(root->getDistrict() > dist)
    {
        return root->getLeftBST()->remove(dist, id, streetName);
    }
    else if(root->getDistrict() < dist)
    {
        return root->getRightBST()->remove(dist, id, streetName);
    }
    return false;
}
bool BST_PostOffice_Node::remove(int id, std::string streetName)
{
    for (int i = 0; i < 10; ++i) {
        if(mailman[i].remove(id, streetName) == true)
            return true;
    }
    return false;
}
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    else if(root->getDistrict() == dist)
    {
        return root->find(id, streetName);
    }
    else if(root->getDistrict() > dist)
    {
        return root->getLeftBST()->find(dist, id, streetName);
    }
    else if(root->getDistrict() < dist)
    {
        return root->getRightBST()->find(dist, id, streetName);
    }
    return nullptr;
}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{
    for (int i = 0; i < 10; ++i) {
        Mail *temp = mailman[i].find(id, streetName);
        if (temp != nullptr) {
            return temp;
        }
    }
    return nullptr;
}


void BST_PostOffice::printInOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        root->getLeftBST()->printInOrder();
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < 10; ++i) {
            root->mailman[i].printInOrder();
        }
        root->getRightBST()->printInOrder();
    }
}

void BST_PostOffice::printPostOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        root->getLeftBST()->printPostOrder();
        root->getRightBST()->printPostOrder();
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < 10; ++i) {
            root->mailman[i].printPostOrder();
        }
    }
}



void BST_PostOffice::printPreOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < 10; ++i) {
            root->mailman[i].printPreOrder();
        }
        root->getLeftBST()->printPreOrder();
        root->getRightBST()->printPreOrder();
    }
}

BST_PostOffice::~BST_PostOffice() {
    delete root;
}
BST_PostOffice_Node::~BST_PostOffice_Node() {
    delete left;
    delete right;
}

void BST_PostOffice::printDistrict(District dist, printType type) const
{
    if(root == nullptr)
    {
//        std::cout << "No mail for the district yet" << std::endl; - CANCELLED
    }
    else if(root->getDistrict() == dist)
    {
        //print here
        std::cout << "The District Mail Report for district "<< dist << std::endl;
        root->print(type);
    }
    else if(root->getDistrict() > dist)
    {
        return root->getLeftBST()->printDistrict(dist, type);
    }
    else if(root->getDistrict() < dist)
    {
        return root->getRightBST()->printDistrict(dist, type);
    }

}

void BST_PostOffice::printMailman(District district, int i, printType type) const
{
    if(root == nullptr)
    {
//        std::cout << "No mail for the district yet" << std::endl; - CANCELLEd
    }
    else if(root->getDistrict() == district)
    {
        //print here
        root->printMailman(i, type);
    }
    else if(root->getDistrict() > district)
    {
        return root->getLeftBST()->printMailman(district, i, type);
    }
    else if(root->getDistrict() < district)
    {
        return root->getRightBST()->printMailman(district, i, type);
    }



}

void BST_PostOffice_Node::print(printType type) const
{
    switch(type)
    {
        case 1:
            for (int i = 0; i < 10; ++i) {
                std::cout << "For Mailman " << i << std::endl;
                mailman[i].printInOrder();
            }
            break;
        case 2:
            for (int i = 0; i < 10; ++i) {
                std::cout << "For Mailman " << i << std::endl;
                mailman[i].printPostOrder();
            }
            break;
        case 3:
            for (int i = 0; i < 10; ++i) {
                std::cout << "For Mailman " << i << std::endl;
                mailman[i].printPreOrder();
            }
            break;
        default: break;
    }
}

District BST_PostOffice_Node::getDistrict() const {

        return district;

}

void BST_PostOffice_Node::printMailman(int i, printType type) const {
    switch (type) {
        case printType::inorder:
            mailman[i].printInOrder();
            break;
        case printType::postorder:
            mailman[i].printPostOrder();
            break;
        case printType::preorder:
            mailman[i].printPreOrder();
            break;
        default:
            break;
    }
}
