#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };		// int�� �迭����
	int *parr = arr;					// �迭�� �̸��� �ּ��̴�.

	printf("arr �ּ� : %p\n", arr);
	printf("arr ũ�� : %u\n", sizeof(arr));  // int ũ�� : 4 * ���� ���� : 5 = 20 byte
	
	printf("arr[0]�� �ּ� : %p\n", &arr[0]);	// ù��° ���� �ּҰ�
	printf("arr[1]�� �ּ� : %p\n", &arr[1]);	// �ι�° ���� �ּҰ�
	printf("arr + 1: %p\n", arr + 1);			// arr +1 : arr[1]�� �ּҰ��� ������. arr : �迭�� �̸��� �ּ��̹Ƿ�, arr + 1�� �ι�° ���� �ּҰ��� ��Ÿ��	
	//=========================================
	
	printf("parr �ּ� : %p\n", &parr);		// parr������ ������ �ּ� ������ => parr �����ͺ����� �ּ�.
	printf("Parr ������ : %p\n", parr);		// parr�� arr�� ���� = parr�� arr �ּҸ� ���� => �迭 arr�� �ּ�.
	printf("parr + 1: %p\n", parr + 1);		// parr + 1= arr + 1 => arr�� �ι�°���� �ּ�.	
	printf("parr[0]: %d\t   *pa:%d\t   arr[0]:%d\n",parr[0], *parr, arr[0]);	// parr[0] = arr [0] *parr => parr�� ������, �迭�� ù��° �濡 �ִ� ��
	return 0;
}