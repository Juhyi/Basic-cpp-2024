#include <iostream>
using namespace std;
/*
* C-Style ���ڿ�
* ���ڿ��� �������� �� ���ڰ� �ٴ´�.
*/
int main()
{
	/*
	int  code = 97;
	cout << code << endl;
	cout << char(code) << endl;
	cout << "==================================" << endl;
	char arr[6] = { 'a', 'b', 'c', 'd','e' };  // ���ڿ� Ÿ���� �迭 ����
	cout << arr << endl;
	cout << "==================================" << endl;
	char arr1[] = { 'a', 'b', 'c', '\0','e' };  // �ι��� :���ڿ��� ���� �˸�
	cout << arr1 << endl;
	cout << sizeof(arr1) << endl;	// ��ü ���� ũ��
	cout << strlen(arr1) << endl;	// ���ڿ��� ũ�� : �ι��� ���� ũ��
	cout << "==================================" << endl;
	char str[] = "string";	 // ���ÿ� �迭�� ���� ����ֱ� ������		// �ڵ����� �ι��ڰ� �ٴ´�
	cout << str << endl;
	cout << sizeof(str) << endl;	// ���ڿ�: �� ���ڰ� ���ѵ� ũ�Ⱑ ����	
	cout << strlen(str) << endl;	// ������ ������ ũ��
	str[0] = 'S';
	cout << str << endl;
	cout << "==================================" << endl;
	const char* pstr = "string";		// ������ �ȵǱ� ������ const �ٿ���
	cout << pstr << endl;				// �����ʹ� �ּҿ� ���� 
	cout << sizeof(pstr) << endl;	// 8	
	cout << strlen(pstr) << endl;	// 6	
	// pstr[0] = 's';    : ���ڿ��� �����ͷ� ����ϴ� ���� ������ �Ұ����ϴ�. 
						

	*/

/*
* C++ -style
*/
string s = "string";
cout << s << endl;
cout << sizeof(s) << endl;	// string Ÿ���� ũ��� �⺻���� 40
// cout << strlen(s) << endl;
cout << s.size() << endl;		// �Է��� ũ�⸦ �˰� ������ ����Լ� s.size() ���

string s1 = "Hongkildon";
cout << s1 << endl;
cout << sizeof(s1) << endl;
cout << s1.size() << endl;		// �Է��� ũ�⸦ �˰� ������ ����Լ� s1.size() ���
cout << s1.capacity() << endl;

string s1 = "Hi";
string s2 = "you";

string s3 = s1 + s2;
cout << s3 << endl;

return 0;

}