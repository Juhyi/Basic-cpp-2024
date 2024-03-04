#include <iostream>
using namespace std;

// 클래스 Data를 흉내낸 영역 -구조체
typedef struct Data
{
	int data;
	void (*ShowData)(Data*);	// 함수 포인트: ShowData 멤버함수 선언 //*함수이름 : 함수이름을 가지고 있는 주소. 포인터, 매개변수 이름 생략.
	void (*Add)(Data*, int);    // 함수 포인트: Add 멤버함수 선언, 함수이름 자체가 포인터 이므로 주소임. 
} Data; // Data라는 이름으로 부르겠음. 


void ShowData(Data* THIS)			// ShowData 멤버함수 정의 
{
	cout << "Data: " << THIS->data << endl;  // This 포인터 변수를 통해서 멤버에 접근
}
void Add(Data* THIS, int num)		// Add 멤버함수 정의
{
	THIS->data += num;       
}


// 적절히 변경된 main 함수
int main(void)
{

	// 구조체 변수가 함수를 공유함. 
	Data obj1 = { 15, ShowData, Add };		// Data 구조체 변수 obj1 선언과 초기화.
	Data obj2 = { 7, ShowData, Add };       // Data 구조체 변수 obj2 선언과 초기화.
	obj1.Add(&obj1, 17);		// obj1의 주소값, int 17
	obj2.Add(&obj2, 9);			// obj2의 주소값, int 9
	obj1.ShowData(&obj1);		// &obj1 데이터값의 포인터를 입력으로 받음, obj1이 가리키는 데이터 값 출력 		
	obj2.ShowData(&obj2);        
	return 0;
};
