#include "collection.h"
#include <iostream>
#include <fstream>

Collection::ElementNode::ElementNode(ComplexNumber* number, ElementNode* next){
    this->value = number;
    this->next=next;
}

 ComplexNumber* Collection::ElementNode::getValue() const{
     return this->value;
 }

 Collection::ElementNode* Collection::ElementNode::getNext() const{
     return this->next;
 }

 Collection::ElementNode::~ElementNode(){
    this->next=nullptr;
    this->value=nullptr;
 }

 Collection::Collection(Collection& col){
    Collection::ElementNode* curr = col.last;
    Collection::ElementNode* mass[col.getCount()];
    for (int i=col.getCount()-1;curr!=nullptr;i--)
    {
        mass[i]=curr;
        curr=curr->getNext();
    }
    this->last=nullptr;
    for (int i=0;i<col.getCount();i++)
    {
        this->last= new Collection::ElementNode(new ComplexNumber(*(mass[i]->getValue())),this->last);
    }
    this->count=col.getCount();
 }

 void Collection::push(ComplexNumber* number)
 {
     if (this->count==0) this->last=nullptr;
     Collection::ElementNode* node = new Collection::ElementNode(number,this->last);
     this->last = node;
     count++;
 }

 ComplexNumber *Collection::pop()
 {
     ComplexNumber* number = last->getValue();
     Collection::ElementNode* curr=last->getNext();
     delete(this->last);
     this->last = curr;
     this->count--;
     return number;
 }

 ComplexNumber* Collection::peek() const
 {
     return new ComplexNumber(*(this->last->getValue()));
 }

 bool Collection::operator==(const Collection &col) const
 {
     if (this->count!=col.getCount()) return false;
     Collection::ElementNode* col_curr = col.last;
     Collection::ElementNode* this_curr = this->last;
     while(col_curr!=nullptr)
     {
         if (*(col_curr->getValue())!=*(this_curr->getValue())) return false;
         col_curr = col_curr->getNext();
         this_curr = this_curr->getNext();
     }
     return true;
 }

 bool Collection::operator!=(const Collection &col) const
 {
     return !operator==(col);
 }

 int Collection::getCount() const
 {
     return this->count;
 }

 void Collection::clear()
 {

     if (this->last->getNext()==nullptr)
     {
         delete(this->last->getValue());
         delete(this->last);
         this->count=0;
         this->last=nullptr;
     }
     else
     {
         Collection::ElementNode* curr = this->last;
         while(curr!=nullptr)
         {
             curr=curr->getNext();
             delete(last->getValue());
             delete(last);
             count--;
             last=curr;

         }
     }
 }

 void Collection::printCollection()
 {
     Collection::ElementNode* curr = this->last;
     if (this->count!=0)
     {
         while (curr!=nullptr)
         {
             std::cout << curr->getValue()->toString()<<" ";
             curr = curr->getNext();
         }
         std::cout <<std::endl;
     }
 }

 Collection *Collection::readFromFile(std::string filepath)
 {
     Collection *stack = nullptr;
     std::ifstream rd;
     rd.open(filepath);
     int edge =4,i=0;
     std::string* array = new std::string[edge];
     if (rd.is_open())
     {
         while (getline(rd, array[i]))
         {
            if (i+1==edge)
            {
                std::string tmp[edge];
                for (int j=0;j<edge;j++) tmp[j]=array[j];
                delete [] array;
                edge*=4;
                array = new std::string[edge];
                for (int j=0;j<edge/4;j++) array[j]=tmp[j];
            }
            i++;
         }
         if (i==0) return stack;
         stack = new Collection();
         for (int j=i-1;j>=0;j--)
         {
             stack->push(ComplexNumber::fromString(array[j]));
         }
         delete [] array;

     }
     rd.close();
     return stack;
 }

 void Collection::writeToFile(std::string filepath) const
 {
     Collection::ElementNode* curr = this->last;
     std::ofstream wrt;
     wrt.open(filepath);
     if (wrt.is_open())
     {
         while(curr!=nullptr)
         {
             wrt << curr->getValue()->toString() << std::endl;
             curr = curr->getNext();
         }
     }
     wrt.close();
 }

 Collection::~Collection()
 {
     clear();
 }

