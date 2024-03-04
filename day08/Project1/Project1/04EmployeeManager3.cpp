#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)		//  �ʱ�ȭ �����ָ鼭 �θ� Ŭ������ ����� ����. 
		: Employee(name), salary(money)   //Employee �θ�Ŭ����, salary�� �ʱ�ȭ ������
	{  }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{  }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;      // �� �ǸŽ���
	double bonusRatio;    // �󿩱� ���� 
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{  }
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const							
	{	
		cout << "SalesWorker" << endl;     // �������̵��� ����Լ��� �ڱ���� ����ȴ�.  
		return PermanentWorker::GetPay()       // ���� �����ǵ� �θ���� ȣ���ҷ��� PermanentWorker(�θ�)�� GetPay �Լ� ȣ��
			+ (int)(salesResult * bonusRatio); //  PermanentWorker:: �Ҽ��� ǥ���ؾ��Ѵ�. 
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];		// ��ü������ �迭
	int empNum;
public:
	EmployeeHandler() : empList(), empNum(0)		// empList - nullptr �ʱ�ȭ == empList[]
		{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const	// �� ��ü�� ����Լ� ȣ�� ����
	{
		/*
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		*/
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		/*
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay();
		*/
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}	
};

int main(void)
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;

	// ������ ���
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// �ӽ��� ���
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);	// 5�ð� ���Ѱ�� ���
	handler.AddEmployee(alba);

	// ������ ���
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);	// �������� 7000
	handler.AddEmployee(seller);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	
	SalesWorker  s("Hong", 1000, 0.1);
	cout << s.GetPay() << endl;        // �ڱⲨ�� �ִ� Getpay() ����
	return 0;														


}