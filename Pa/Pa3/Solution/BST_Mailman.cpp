//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

BST_Mailman_Node::BST_Mailman_Node(Mail *mail) {
    mailPtr[0] = mail;
    for(int i = 1; i < 100; ++i)
    {
        mailPtr[i] = nullptr;
    }
    currentMailsStored++;
    streetName = mail->getStreetName();
    right = new BST_Mailman;
    left = new BST_Mailman;
}

void BST_Mailman_Node::addMail(Mail *mail)
{
    //ASSUMPTION: WE WILL NEVER STORE MORE THAN 100 ITEMS IN THE ARRAY!

    mailPtr[currentMailsStored] = mail;
    currentMailsStored++;
}
BST_Mailman * BST_Mailman_Node::getRightBST() const
{
    return right;
}
BST_Mailman * BST_Mailman_Node::getLeftBST() const
{
    return left;
}
void BST_Mailman::addMail(Mail *mail)
{
    if(root == nullptr)
    {
        root = new BST_Mailman_Node(mail);
    }
    else if (root->getStreetName() > mail->getStreetName())
    {
        root->getLeftBST()->addMail(mail);
    }
    else if (root->getStreetName() < mail->getStreetName())
    {
        root -> getRightBST()->addMail(mail);
    }
    else if(root-> getStreetName() == mail -> getStreetName())
    {
        root->addMail(mail);
    }
}

BST_Mailman::BST_Mailman()
{
    root = nullptr;
}
//Removing mail is equal to delivering it - hence, we can delete the mail pointer.
//hint: keep Find function, use it and delete it.
bool BST_Mailman::remove(int id, std::string streetName)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root->getStreetName() == streetName)
    {
        return root->remove(id);
    }
    else if(root->getStreetName() > streetName)
    {
        return root->getLeftBST()->remove(id, streetName);
    }
    else if(root->getStreetName() < streetName)
    {
        return root->getRightBST()->remove(id, streetName);
    }
    return false;
}

bool BST_Mailman_Node::remove(int id)
{
    for (int i = 0; i < 100; ++i) {
        if(mailPtr[i] != nullptr)
        {
            if(mailPtr[i]->getId() == id)
            {
                delete mailPtr[i];
                mailPtr[i] = nullptr;
                return true;
            }
        }
    }
    return false;
}

Mail * BST_Mailman::find(int id, std::string streetName)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root->getStreetName() == streetName)
    {
        return root->find(id);
    }
    else if(root->getStreetName() > streetName)
    {
        return root->getLeftBST()->find(id, streetName);
    }
    else if(root->getStreetName() < streetName)
    {
        return root->getRightBST()->find(id, streetName);
    }
    return nullptr;
}

Mail *BST_Mailman_Node::find(int id)
{
    for (int i = 0; i < 100; ++i) {
        if(mailPtr[i] != nullptr)
        {
            if(mailPtr[i]->getId() == id)
            {
                return mailPtr[i];
            }
        }
    }
    return nullptr;
}

BST_Mailman::~BST_Mailman()
{
    delete root;
}

BST_Mailman_Node::~BST_Mailman_Node()
{
    for (int i = 0; i < 100; ++i) {
        if(mailPtr[i] != nullptr)
        {
            delete mailPtr[i];
            mailPtr[i] = nullptr;
        }
    }
    delete right;
    right = nullptr;
    delete left;
    left = nullptr;
}

void BST_Mailman_Node::print() const
{
    std::cout << "BST Node for Street: " << streetName << std::endl;
    for (int i = 0; i < currentMailsStored; ++i) {
        if(mailPtr[i] != nullptr)
        {
            mailPtr[i]->printMail();
        }
    }
}

std::string BST_Mailman_Node::getStreetName() const
    {
        return streetName;
    }

void BST_Mailman::printInOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        root->getLeftBST()->printInOrder();
        root->print();
        root->getRightBST()->printInOrder();
    }
}

void BST_Mailman::printPostOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        root->getLeftBST()->printPostOrder();
        root->getRightBST()->printPostOrder();
        root->print();
    }
}

void BST_Mailman::printPreOrder() const
{
    if(root == nullptr)
    {
    }
    else
    {
        root->print();
        root->getLeftBST()->printPreOrder();
        root->getRightBST()->printPreOrder();
    }
}



