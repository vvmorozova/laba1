#include "complexnumber.h"
#ifndef OPERATION_H
#define OPERATION_H


class Operation : public Element
{
private:
    int operandQuantity;
    char operationSign;
public:
    Operation(int quantity, char sign);
    bool verifyInput(int quantity, char sign) const;
    int getOperandQuantity() const;
    char getOperationSign() const;
    void setOperandQuantity(int number);
    void setOperationSign(char symbol);
    ~Operation();
};


#endif // OPERATION_H
