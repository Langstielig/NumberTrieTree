#pragma once
#include <iostream>

using namespace std;

//разобраться с функциями recursiveRemove и recursiveClear

class TrieTree {

	struct TrieNode {
		TrieNode* numbers[10];
		bool isEndOfWord;
		TrieNode() {
			for (int i = 0; i < 10; i++) {
				numbers[i] = nullptr;
				isEndOfWord = false;
			}
		}
	};

	typedef TrieNode* TTrie;

	TTrie root;

public:
	TrieTree(): root(new TrieNode) {}
	~TrieTree() {
		delete root;
	}

	void addNumber(string elem);
	bool isNumber(string elem);
	void recursiveClear(TTrie& p);
	bool addCheck(string elem);
	void recursiveRemove(TTrie& p, string elem, int i, int size);
	void remove(string elem);

};