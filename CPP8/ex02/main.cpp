#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

static void printMutantStack(const MutantStack<int>& stack)
{
	MutantStack<int>::const_iterator it;

	for (it = stack.begin(); it != stack.end(); ++it)
		std::cout << *it << std::endl;
}

static void testStackInterface()
{
	MutantStack<int> stack;

	stack.push(5);
	stack.push(17);
	std::cout << "top: " << stack.top() << std::endl;
	stack.pop();
	std::cout << "size: " << stack.size() << std::endl;
	stack.push(3);
	stack.push(5);
	stack.push(737);
	stack.push(0);
	printMutantStack(stack);
}

static void testCopyAndBaseType()
{
	MutantStack<int> original;
	MutantStack<int> copy;
	std::stack<int> base;

	original.push(1);
	original.push(2);
	copy = original;
	base = original;
	std::cout << "copy top: " << copy.top() << std::endl;
	std::cout << "base top: " << base.top() << std::endl;
}

static void testAgainstList()
{
	MutantStack<int> mutant;
	std::list<int> list;
	MutantStack<int>::iterator mutantIt;
	std::list<int>::iterator listIt;

	mutant.push(5);
	mutant.push(17);
	mutant.push(3);
	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	mutantIt = mutant.begin();
	listIt = list.begin();
	while (mutantIt != mutant.end() && listIt != list.end())
	{
		if (*mutantIt != *listIt)
			std::cout << "containers differ" << std::endl;
		++mutantIt;
		++listIt;
	}
	if (mutantIt == mutant.end() && listIt == list.end())
		std::cout << "containers match" << std::endl;
}

int main()
{
	testStackInterface();
	testCopyAndBaseType();
	testAgainstList();
	return 0;
}