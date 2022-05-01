#include "Utils.h"

template<typename Type>
Type peekAndPop(std::queue<Type>& q)
{
	Type peeked;
	peeked = q.front();
	q.pop();
	return peeked;
}