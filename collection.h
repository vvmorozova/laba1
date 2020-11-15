#ifndef COLLECTION_H
#define COLLECTION_H
#include "complexnumber.h"

class Collection {
private:
    class ElementNode {
    private:
        ComplexNumber *value;
        ElementNode* next;
    public:
        ElementNode(ComplexNumber* number=nullptr, ElementNode* next=nullptr);
        ComplexNumber *getValue() const;
        ElementNode* getNext() const;
        ~ElementNode();
    };
    ElementNode* last{nullptr};
    int count{0};
public:
    Collection() = default;
    Collection(Collection &col);
    void push(ComplexNumber*);
    ComplexNumber* pop();
    ComplexNumber* peek() const;
    bool operator==(const Collection& col) const;
    bool operator!=(const Collection& col) const;
    int getCount() const;
    void clear();
    void printCollection();
    static Collection *readFromFile(std::string filepath);
    void writeToFile(std::string filepath) const;
    ~Collection();
};


#endif // COLLECTION_H
