//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

// TODO: Constructors and Destructors
BST_Mailman::BST_Mailman()
{
    root = nullptr;
}

BST_Mailman_Node::BST_Mailman_Node(Mail *mail)
{
    streetName = mail->getStreetName();
    mailPtr[currentMailsStored] = mail;
    currentMailsStored++;
    right = nullptr;
    left = nullptr;
}

BST_Mailman::~BST_Mailman()
{
    delete root;
}

BST_Mailman_Node::~BST_Mailman_Node()
{
    if (right != nullptr)
        delete right;
    if (left != nullptr)
        delete left;
}

// TODO: Getters
std::string BST_Mailman_Node::getStreetName() const
{
    return streetName;
}

BST_Mailman *BST_Mailman_Node::getRightBST() const
{
    return right;
}

BST_Mailman *BST_Mailman_Node::getLeftBST() const
{

    return left;
}

// TODO add mail to the array mailPtr[] - NOTE: WE WILL NEVER ASK YOU TO
//  PUT TOO MANY MAILS. (a max of MAX_NUM_MAILS add_mail calls)
void BST_Mailman::addMail(Mail *mail)
{

    if (mail != nullptr)
    {
        if (root != nullptr)
        {
            if (root->getStreetName() == mail->getStreetName())
            {
                root->addMail(mail);
            }
            else if (mail->getStreetName() < root->getStreetName())
            {
                if (root->getLeftBST() != nullptr)
                {
                    root->getLeftBST()->addMail(mail);
                }
                else
                {
                    root->left = new BST_Mailman;
                    root->getLeftBST()->addMail(mail);
                }
            }
            else
            {
                if (root->getRightBST() != nullptr)
                {

                    root->getRightBST()->addMail(mail);
                }
                else
                {
                    root->right = new BST_Mailman;
                    root->getRightBST()->addMail(mail);
                }
            }
        }
        else
        {

            root = new BST_Mailman_Node(mail);
        }
    }
}

void BST_Mailman_Node::addMail(Mail *mail)
{
    mailPtr[currentMailsStored] = mail;
    currentMailsStored++;
}

// TODO: Remove a mail, given its street name and ID
bool BST_Mailman::remove(int id, std::string streetName)
{
    if (root->getStreetName() == streetName)
    {
        return root->remove(id);
    }
    else
    {
        if (streetName < root->getStreetName())
        {
            return root->getLeftBST()->remove(id, streetName);
        }
        else
        {
            return root->getRightBST()->remove(id, streetName);
        }
    }
}

bool BST_Mailman_Node::remove(int id)
{
    for (int i = 0; i < currentMailsStored; ++i)
    {
        if (mailPtr[i]->getId() == id)
        {
            delete mailPtr[i];
            mailPtr[i] = nullptr;
            currentMailsStored--;
            return true;
        }
    }
    return false;
}

// TODO: Find a mail item, given its street name and ID
Mail *BST_Mailman::find(int id, std::string streetName)
{

    if (root == nullptr)
    {

        return nullptr;
    }
    if (root->currentMailsStored > 0)
    {
        if (root->getStreetName() == streetName)
        {
            return root->find(id);
        }
    }

    else
    {
        if (streetName < root->getStreetName())
        {
            return root->getLeftBST()->find(id, streetName);
        }
        else
        {
            return root->getRightBST()->find(id, streetName);
        }
    }
    return nullptr;
}

Mail *BST_Mailman_Node::find(int id)
{

    for (int i = 0; i < MAX_NUM_MAILS; ++i)
    {

        if (mailPtr[i] != nullptr)
            if (mailPtr[i]->getId() == id)
            {
                return mailPtr[i];
            }
    }
    return nullptr;
}

// TODO: Print functions. See example outputs for the necessary formats.
void BST_Mailman::printInOrder() const
{

    if (root == nullptr)
    {
        return;
    }

    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printInOrder();
    }
    std::cout << "BST Node for Street: " << root->getStreetName() << std::endl;
    root->print();
    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printInOrder();
    }
}

void BST_Mailman::printPostOrder() const
{
    if (root == nullptr)
    {
        return;
    }
   
    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printPostOrder();
    }

    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printPostOrder();
    }
     std::cout << "BST Node for Street: " << root->getStreetName() << std::endl;
    root->print();
}

void BST_Mailman::printPreOrder() const
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << "BST Node for Street: " << root->getStreetName() << std::endl;
    root->print();
    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printPreOrder();
    }

    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printPreOrder();
    }
    
}

void BST_Mailman_Node::print() const
{

    for (int i = 0; i < currentMailsStored; ++i)
    {

        if (mailPtr[i] != nullptr)
        {
            // std::cout << "BST Node for Street: " << mailPtr[i]->getStreetName() << std::endl;

            mailPtr[i]->printMail();
        }
    }
}
