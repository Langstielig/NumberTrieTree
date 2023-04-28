#include "TrieTree.h"

void TrieTree::addNumber(string elem) {
	TTrie newNumber = root;
	int index;
	int numberSize = elem.size();
	for (int i = 0; i < numberSize; i++) {
		index = elem[i] - '0';
		if (newNumber->numbers[index] == nullptr) {
			newNumber->numbers[index] = new TrieNode;
		}
		newNumber->isEndOfWord = false;
		newNumber = newNumber->numbers[index];
	}
	newNumber->isEndOfWord = true;
}

bool TrieTree::isNumber(string elem) {
	bool flag = true;
	TTrie newNumber = root;
	int i = 0;
	int numberSize = elem.size();
	int index;
	while (flag && i < numberSize) {
		index = elem[i] - '0';
		if (newNumber->numbers[index] == nullptr)
			flag = false;
		else {
			newNumber = newNumber->numbers[index];
			i++;
		}
	}
	if (newNumber->isEndOfWord != true)
		flag = false;
	return flag;
}

void TrieTree::recursiveClear(TTrie& p) {
	for (int i = 0; i < 10; i++) {
		if (p->numbers[i] != nullptr)
			recursiveClear(p->numbers[i]);
	}
	for (int i = 0; i < 10; i++) {
		delete p->numbers[i];
		p->numbers[i] = nullptr;
	}
}

void TrieTree::recursiveRemove(TTrie& p, string elem, int i, int size) {
	int index = elem[i] - '0';
	if (i < size)
		recursiveRemove(p->numbers[index], elem, i + 1, size);
	if (i == size)
		p->isEndOfWord = false;
	bool flag = true;
	for (int i = 0; i < 10; i++)
		if (p->numbers[i] != nullptr)
			flag = false;
	if (flag)
		for (int i = 0; i < 10; i++) {
			delete p->numbers[i];
			p->numbers[i] = nullptr;
		}
}

void TrieTree::remove(string elem) {
	if (isNumber(elem))
		recursiveRemove(root, elem, 0, elem.size());
}

bool TrieTree::addCheck(string elem) {
	bool isBeginingOfNumber = true;
	TTrie newNumber = root;
	int i = 0;
	int numberSize = elem.size();
	int index;
	while (isBeginingOfNumber && i < numberSize && newNumber->isEndOfWord == false) {
		index = elem[i] - '0';
		if (newNumber->numbers[index] == nullptr)
			isBeginingOfNumber = false;
		else {
			newNumber = newNumber->numbers[index];
			i++;
		}
	}
	addNumber(elem);
	return !isBeginingOfNumber;
}