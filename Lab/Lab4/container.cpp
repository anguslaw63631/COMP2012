#include "container.h"
#include <iostream>

void Container::addObject(Object *object)   //Task 1&3
{
    if(_num_object >= MAX_OBJECT_NUM || object->getSize().x+object->getPosition().x > this->_size.x || object->getSize().y+object->getPosition().y > this->_size.y ){
        cout<<"The object "<<object->getName()<<" is too large and cannot be added to "<<this->_name<<endl;
        return;
    }
    object->setParent(this);
    _objects[_num_object++] = object;
}

void Container::display() const //Task 1
{
    std::cout << "\nContainer";
    this->displayBasic();
    std::cout <<"\n\t\t";
    if(_num_object>0)
    std::cout<<"#objects: "<<_num_object<<endl;

    for(int i=0;i<_num_object;i++){
        _objects[i]->display();
    }
}

Container::Container() 
{
    for (int i = 0; i < MAX_OBJECT_NUM; i++)
        _objects[i] = nullptr;

    _num_object = 0;
}

Container::~Container()  //Task 1
{
    cout<<"\nDestructing Container "<< getName();
    for(int i=0;i<_num_object;i++){
        if(_objects[i] != nullptr)
        delete _objects[i];
    }
}