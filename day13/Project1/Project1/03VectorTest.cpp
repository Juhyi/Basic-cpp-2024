/*
* vector ��ü�� �����ϰ� ������ �Է� ������ ���� ���Ϳ� �����ϰ� ����� ����Ͻÿ�.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v;	// int Ÿ���� vector ����
	int sum = 0;

	
	while (true) {
		int inKey;
		
		cout << "���ڸ� �Է��ϼ��� : " << endl;
		cin >> inKey;

		v.push_back(inKey);		// �Է��� ���������� ���Ϳ� ����
		for (int i = 0; i < v.size(); i++) {
			cout << v.at(i) << endl;
		}
		sum += inKey;
		float average = sum / v.size();		// ���
		cout << "���: " << average << endl;

		if (!inKey) {
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
	}
	
	return 0;
}


