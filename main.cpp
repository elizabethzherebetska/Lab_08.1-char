#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;
int Count(char* s) // s = �������� �� ������� �����
{
	int k = 0,
		pos = 0; // pos = ������� ������� ������
	char* t;
	while (t = strchr(s + pos, ',')) // t = �������� �� '+'
	{
		pos = t - s + 1; // pos = ��������� ������ ���� '+'
		if (pos!=100 && s[pos] == '-') {
			k++;
		}
			
	}
	return k;
}

char* Change(char* s) {
	char* res = new char[strlen(s)]; //������� ���'���
	int k = 0;

	for (int i = 0; i < strlen(s)-1; i++) {
		if (s[i] == ',' && s[i + 1] == '-') {
			res[k] = '*';
			k ++;
			i++;
		}
		else {
			res[k] = s[i];
			k++;
		}
	}
	res[k] = s[strlen(s)-1];
	k++;
	res[k] = '\0';
	return res;

}


int main()
{
	char str[101];
		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of ',-'" << endl;
	cout << "Modified string " << Change(str) << endl;
	return 0;
}