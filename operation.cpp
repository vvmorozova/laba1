#include "operation.h"

Operation::Operation(int quantity, char sign)
{
    this->operandQuantity=quantity;
    this->operationSign=sign;
}

bool Operation::verifyInput(int quantity, char sign) const
{
    if (quantity>1 && sign=='=') return false;
    else return true;
}

int Operation::getOperandQuantity() const
{
    return this->operandQuantity;
}

char Operation::getOperationSign() const
{
    return this->operationSign;
}

void Operation::setOperandQuantity(int number)
{
    this->operandQuantity=number;
}

void Operation::setOperationSign(char symbol)
{
    this->operationSign=symbol;
}

Operation::~Operation()
{
    operandQuantity=0;
    operationSign='0';
}
