# include <iostream>

class AClass {
//private:  �����ϸ� default ������ private�� ��.	
	int num;



public:		// ��������������
	AClass(int anum) {		// ������ �ֿ� ���� : �ʱ�ȭ
		num = anum;

	}
	void AInfo() {
		std::cout << "A:: num: " << num << std::endl;

	}
};

int main()
{
	AClass a(10);		// a��� ��ü�� �����ϸ鼭 10�� �Է��� ��. 
	a.AInfo();

	return 0;
}