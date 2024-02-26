# include <iostream>

class AClass {
//private:  생략하면 default 값으로 private가 들어감.	
	int num;



public:		// 접근제어지시자
	AClass(int anum) {		// 생성자 주요 역할 : 초기화
		num = anum;

	}
	void AInfo() {
		std::cout << "A:: num: " << num << std::endl;

	}
};

int main()
{
	AClass a(10);		// a라는 객체를 생성하면서 10의 입력을 줌. 
	a.AInfo();

	return 0;
}