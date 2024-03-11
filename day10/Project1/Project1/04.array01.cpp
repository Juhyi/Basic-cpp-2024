#include <iostream>

int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };		// int형 배열선언
	int *parr = arr;					// 배열의 이름은 주소이다.

	printf("arr 주소 : %p\n", arr);
	printf("arr 크기 : %u\n", sizeof(arr));  // int 크기 : 4 * 방의 갯수 : 5 = 20 byte
	
	printf("arr[0]의 주소 : %p\n", &arr[0]);	// 첫번째 방의 주소값
	printf("arr[1]의 주소 : %p\n", &arr[1]);	// 두번째 방의 주소값
	printf("arr + 1: %p\n", arr + 1);			// arr +1 : arr[1]의 주소값과 동일함. arr : 배열의 이름은 주소이므로, arr + 1은 두번째 방의 주소값을 나타냄	
	//=========================================
	
	printf("parr 주소 : %p\n", &parr);		// parr포인터 변수에 주소 연산자 => parr 포인터변수의 주소.
	printf("Parr 데이터 : %p\n", parr);		// parr에 arr을 대입 = parr에 arr 주소를 대입 => 배열 arr의 주소.
	printf("parr + 1: %p\n", parr + 1);		// parr + 1= arr + 1 => arr의 두번째방의 주소.	
	printf("parr[0]: %d\t   *pa:%d\t   arr[0]:%d\n",parr[0], *parr, arr[0]);	// parr[0] = arr [0] *parr => parr의 데이터, 배열의 첫번째 방에 있는 값
	return 0;
}