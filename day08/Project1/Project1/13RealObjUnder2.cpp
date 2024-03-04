#include <iostream>
using namespace std;

// Ŭ���� Data�� �䳻�� ���� -����ü
typedef struct Data
{
	int data;
	void (*ShowData)(Data*);	// �Լ� ����Ʈ: ShowData ����Լ� ���� //*�Լ��̸� : �Լ��̸��� ������ �ִ� �ּ�. ������, �Ű����� �̸� ����.
	void (*Add)(Data*, int);    // �Լ� ����Ʈ: Add ����Լ� ����, �Լ��̸� ��ü�� ������ �̹Ƿ� �ּ���. 
} Data; // Data��� �̸����� �θ�����. 


void ShowData(Data* THIS)			// ShowData ����Լ� ���� 
{
	cout << "Data: " << THIS->data << endl;  // This ������ ������ ���ؼ� ����� ����
}
void Add(Data* THIS, int num)		// Add ����Լ� ����
{
	THIS->data += num;       
}


// ������ ����� main �Լ�
int main(void)
{

	// ����ü ������ �Լ��� ������. 
	Data obj1 = { 15, ShowData, Add };		// Data ����ü ���� obj1 ����� �ʱ�ȭ.
	Data obj2 = { 7, ShowData, Add };       // Data ����ü ���� obj2 ����� �ʱ�ȭ.
	obj1.Add(&obj1, 17);		// obj1�� �ּҰ�, int 17
	obj2.Add(&obj2, 9);			// obj2�� �ּҰ�, int 9
	obj1.ShowData(&obj1);		// &obj1 �����Ͱ��� �����͸� �Է����� ����, obj1�� ����Ű�� ������ �� ��� 		
	obj2.ShowData(&obj2);        
	return 0;
};
