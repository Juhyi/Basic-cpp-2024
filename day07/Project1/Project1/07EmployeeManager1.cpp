#include <iostream>
using namespace std;


class permanentWorker
{
private:
	char name[100];
	int salary;
public:
	permanentWorker(const char* name, int money)
		: salary(money)
	{
		strcpy(this->name, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHander
{
private:
	permanentWorker* empList[50];	// 객체포인터 배열
	int empNum;
public:
	EmployeeHander() : empNum(0)
	{ }
	void AddEmployee(permanentWorker* emp) // 정규직 객체의 포인트(주소값)를 받아서 empList 배열에 집어넣음. 입력이 객체의 포인터 : 주소 
	{
		empList[empNum++] = emp;	// 후위 연산자 : 연산 후 증감함. 
	}
	void ShowAllSalaryInfo() const	// const 함수  배열이므로 for문을 사용. 
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();		// empList배열의 요소값이 객체의 주소값이기 때문에 간접 연산자 -> 을 사용하여 멤버 함수에 접근한다. 
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHander()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHander handler;
	
	// 직원등록
	handler.AddEmployee(new permanentWorker("Kim", 1000));	// new 연산자를 사용하여 heap 영역에 할당 후 handler 객체의 AddEmployee에 
	                                                        // 접근하여 객체 생성 
	handler.AddEmployee(new permanentWorker("Lee", 1000));	
	handler.AddEmployee(new permanentWorker("Jun", 1000));

	// 이번달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	//이번 달에 지불해야 할 급여의 총합
	handler.ShowTotalSalary();
	return 0;

}