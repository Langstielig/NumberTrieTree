#include "TrieTree.h"

int main() {
	setlocale(LC_ALL, "rus");
	int countOfTests = 0;
	TrieTree phoneBook;
	cout << "Введите количество тестов" << endl;
	cin >> countOfTests;
	for (int i = 0; i < countOfTests; i++) {
		int countOfTelephoneNumbers = 0;
		cout << "Введите количество телефонных номеров" << endl;
		cin >> countOfTelephoneNumbers;
		bool isJoint = true;
		int j = 0;
		while(isJoint && j < countOfTelephoneNumbers) {
			string telephoneNumber;
			cout << "Введите номер" << endl;
			cin >> telephoneNumber;
			isJoint = phoneBook.addCheck(telephoneNumber);
			j++;
		}
		if (isJoint)
			cout << "Телефонна книга является совместной" << endl;
		else
			cout << "Телефонная книга не является совместной" << endl;
	}
	return 0;
}