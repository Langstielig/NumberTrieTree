#include "TrieTree.h"

int main() {
	setlocale(LC_ALL, "rus");
	int countOfTests = 0;
	TrieTree phoneBook;
	cout << "������� ���������� ������" << endl;
	cin >> countOfTests;
	for (int i = 0; i < countOfTests; i++) {
		int countOfTelephoneNumbers = 0;
		cout << "������� ���������� ���������� �������" << endl;
		cin >> countOfTelephoneNumbers;
		bool isJoint = true;
		int j = 0;
		while(isJoint && j < countOfTelephoneNumbers) {
			string telephoneNumber;
			cout << "������� �����" << endl;
			cin >> telephoneNumber;
			isJoint = phoneBook.addCheck(telephoneNumber);
			j++;
		}
		if (isJoint)
			cout << "��������� ����� �������� ����������" << endl;
		else
			cout << "���������� ����� �� �������� ����������" << endl;
	}
	return 0;
}