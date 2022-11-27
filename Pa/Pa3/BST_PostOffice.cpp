//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

// TODO: Constructors and Destructors
// std::cout << "========AAA=======" << std::endl;
// TIP: root will be nullptr at first, and we'll add a node once we try to add a mail object.
BST_PostOffice::BST_PostOffice()
{
    root = nullptr;
}

BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail)
{
    district = mail->getDistrict();
    left = nullptr;
    right = nullptr;
    mailman[mail->getAddressHash()].addMail(mail);
}

BST_PostOffice::~BST_PostOffice()
{
    delete root;
}

BST_PostOffice_Node::~BST_PostOffice_Node()
{
    if (right != nullptr)
        delete right;
    if (left != nullptr)
        delete left;
}

// TODO: Accessor functions.
BST_PostOffice *BST_PostOffice_Node::getLeftBST() const
{
    return left;
}

BST_PostOffice *BST_PostOffice_Node::getRightBST() const
{
    return right;
}

District BST_PostOffice_Node::getDistrict() const
{
    return district;
}

// TODO: Given a district, id and street name, find the mail object.
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->getDistrict() == dist)
    {

        return root->find(id, streetName);
    }
    else if (dist < root->getDistrict())
    {
        if (root->getLeftBST() != nullptr)
        {

            return root->getLeftBST()->find(dist, id, streetName);
        }
    }
    else
    {
        if (root->getRightBST() != nullptr)
        {
            return root->getRightBST()->find(dist, id, streetName);
        }
    }
    return nullptr;
}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{

    for (int i = 0; i < HASH_MODULO; ++i)
    {

        if (mailman[i].find(id, streetName) != nullptr)
        {
            // std::cout << "Test: "  << std::endl;
            return mailman[i].find(id, streetName);
        }
    }
    return nullptr;
}

// TODO: Given a district, id and street name, remove the mail object from the
// system.
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{
    if (root != nullptr)
    {
        if (root->getDistrict() == dist)
        {

            return root->remove(id, streetName);
        }
        else if (root->getDistrict() > dist)
        {
            if (root->getLeftBST() != nullptr)
            {
                return root->getLeftBST()->remove(dist, id, streetName);
            }
        }
        else
        {
            if (root->getRightBST() != nullptr)
            {
                return root->getRightBST()->remove(dist, id, streetName);
            }
        }
    }
    return false;
}

bool BST_PostOffice_Node::remove(int id, std::string streetName)
{

    if (this->find(id, streetName) != nullptr)
    {
        // // std::cout << "sss: "  << std::endl;
        // this->find(id, streetName);
        return true;
    }
    return false;
}

// TODO: Add mail to the system
void BST_PostOffice::addMail(Mail *mail)
{
    if (mail != nullptr)
    {
        if (root != nullptr)
        {
            if (root->getDistrict() == mail->getDistrict())
            {
                root->addMail(mail);
            }
            else if (mail->getDistrict() < root->getDistrict())
            {
                if (root->getLeftBST() != nullptr)
                {
                    root->getLeftBST()->addMail(mail);
                }
                else
                {
                    root->left = new BST_PostOffice;
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
                    root->right = new BST_PostOffice;
                    root->getRightBST()->addMail(mail);
                }
            }
        }
        else
        {

            root = new BST_PostOffice_Node(mail);
        }
    }
}

void BST_PostOffice_Node::addMail(Mail *mail)
{

    mailman[mail->getAddressHash()].addMail(mail);
}

// TODO: Given a district, print all of the data in it.
// TIP: Print style depends on type.
void BST_PostOffice::printDistrict(District dist, printType type) const
{

    if (root != nullptr)
    {
        if (root->getDistrict() == dist)
        {
            std::cout << "The District Mail Report for district " << dist << std::endl;
            root->print(type);
        }
        else if (root->getDistrict() > dist)
        {

            if (root->getLeftBST() != nullptr)
            {

                root->getLeftBST()->printDistrict(dist, type);
            }
        }
        else
        {
            if (root->getRightBST() != nullptr)
            {

                root->getRightBST()->printDistrict(dist, type);
            }
        }
    }
}

void BST_PostOffice_Node::print(printType type) const
{

    if (type == inorder)
    {
        for (int i = 0; i < HASH_MODULO; i++)
        {
            std::cout << "For Mailman " << i << std::endl;
            mailman[i].printInOrder();
        }
    }
    else if (type == postorder)
    {
        for (int i = 0; i < HASH_MODULO; i++)
        {
            std::cout << "For Mailman " << i << std::endl;
            mailman[i].printPostOrder();
        }
    }
    else
    {
        for (int i = 0; i < HASH_MODULO; i++)
        {
            std::cout << "For Mailman " << i << std::endl;
            mailman[i].printPreOrder();
        }
    }
}

// TODO: Given a district and ID of the mailman, print all mail in it
// TIP: Print style depends on type - see the header file
void BST_PostOffice::printMailman(District district, int i, printType type) const
{
    if (root != nullptr)
    {
        if (root->getDistrict() == district)
        {
            root->printMailman(i, type);
        }
        else if (root->getDistrict() < district)
        {
            if (root->getLeftBST() != nullptr)
            {
                root->getLeftBST()->printMailman(district, i, type);
            }
        }
        else
        {
            if (root->getRightBST() != nullptr)
            {
                root->getRightBST()->printMailman(district, i, type);
            }
        }
    }
}

void BST_PostOffice_Node::printMailman(int i, printType type) const
{

    if (type == inorder)
    {
        mailman[i].printInOrder();
    }
    else if (type == postorder)
    {
        mailman[i].printPostOrder();
    }
    else
    {
        mailman[i].printPreOrder();
    }
}

// TODO: Other print functions.
void BST_PostOffice::printInOrder() const
{
    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printInOrder();
    }
    if (root != nullptr)
    {
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < HASH_MODULO; i++)
        {
            root->mailman[i].printInOrder();
        }
        // root->print(inorder);
    }

    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printInOrder();
    }
}

void BST_PostOffice::printPostOrder() const
{
    if (root == nullptr)
        return;
    
    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printPostOrder();
    }

    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printPostOrder();
    }
    if (root != nullptr)
    {
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < HASH_MODULO; i++)
        {
            root->mailman[i].printPostOrder();
        }
        // root->print(inorder);
    }
}

void BST_PostOffice::printPreOrder() const
{
     if (root == nullptr)
        return;
    if (root != nullptr)
    {
        std::cout << "BST Node for District: " << root->getDistrict() << std::endl;
        for (int i = 0; i < HASH_MODULO; i++)
        {
            root->mailman[i].printPreOrder();
        }
        // root->print(inorder);
    }
    if (root->getLeftBST() != nullptr)
    {
        root->getLeftBST()->printPreOrder();
    }

    if (root->getRightBST() != nullptr)
    {
        root->getRightBST()->printPreOrder();
    }
   
}