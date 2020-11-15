#include <iostream>
#include <assert.h>
#include "collection.h"

int testTask1()
{
    ComplexNumber default_constr = ComplexNumber();
    assert(default_constr.getImaginaryIPart()==0 && default_constr.getRealPart()==0);

    ComplexNumber init_constr = ComplexNumber(5, 6.3);
    assert(init_constr.getImaginaryIPart()==6.3 && init_constr.getRealPart()==5);

    ComplexNumber copy_constr = ComplexNumber(init_constr);
    assert(copy_constr.getImaginaryIPart()==6.3 && copy_constr.getRealPart()==5);

    ComplexNumber get_set = ComplexNumber();
    get_set.setRealPart(2);
    assert(get_set.getRealPart()==2);
    get_set.setImaginaryIPart(6);
    assert(get_set.getImaginaryIPart()==6);

    init_constr = init_constr + get_set;
    assert(init_constr.getRealPart()==7 && init_constr.getImaginaryIPart()==12.3);

    default_constr = default_constr - get_set;
    assert(default_constr.getImaginaryIPart()==-6 && default_constr.getRealPart()==-2);

    ComplexNumber mul_num = ComplexNumber(2,0);
    ComplexNumber mul_num2 = ComplexNumber(4,0);
    mul_num = mul_num * mul_num2;
    assert(mul_num.getRealPart()==8 && mul_num.getImaginaryIPart()==0);

    mul_num = mul_num / mul_num2;
    assert(mul_num.getRealPart()==2 && mul_num.getImaginaryIPart()==0);
    std::cout << "Everything is good in part 1!"<< std::endl;
    return 0;
}

int testTask2()
{
    ComplexNumber* cn1 = new ComplexNumber(2,0);
    ComplexNumber* cn2 = new ComplexNumber(-8,4);
    ComplexNumber* cn3 = new ComplexNumber(4,5);
    Collection* stack = new Collection();
    stack->push(cn1);
    assert(stack->getCount()==1);
    stack->push(cn2);
    stack->push(cn3);
    Collection* stack2 = new Collection(*(stack));
    assert(*stack==*stack2);
    ComplexNumber* lst = stack->pop();
    assert(stack!=stack2);
    assert(stack->getCount()==2);
    stack->clear();
    assert(stack->getCount()==0);
    stack2->writeToFile("/home/vasuyan/complexnumber/test.txt");
    Collection* stack3 = Collection::readFromFile("/home/vasuyan/complexnumber/test.txt");
    stack2->printCollection();
    stack3->printCollection();
    assert(*stack3==*stack2);
    std::cout<< "Everything is good in part2!"<< std::endl;
    delete(stack);
    delete(stack2);
    delete(stack3);
    delete(cn1);
    delete(cn2);
    delete(cn3);
    delete(lst);
    return 0;
}

int testTask3()
{

    return 0;
}
