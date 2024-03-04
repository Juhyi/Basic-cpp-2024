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
	permanentWorker* empList[50];	// ��ü������ �迭
	int empNum;
public:
	EmployeeHander() : empNum(0)
	{ }
	void AddEmployee(permanentWorker* emp) // ������ ��ü�� ����Ʈ(�ּҰ�)�� �޾Ƽ� empList �迭�� �������. �Է��� ��ü�� ������ : �ּ� 
	{
		empList[empNum++] = emp;	// ���� ������ : ���� �� ������. 
	}
	void ShowAllSalaryInfo() const	// const �Լ�  �迭�̹Ƿ� for���� ���. 
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();		// empList�迭�� ��Ұ��� ��ü�� �ּҰ��̱� ������ ���� ������ -> �� ����Ͽ� ��� �Լ��� �����Ѵ�. 
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
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
	EmployeeHander handler;
	
	// �������
	handler.AddEmployee(new permanentWorker("Kim", 1000));	// new �����ڸ� ����Ͽ� heap ������ �Ҵ� �� handler ��ü�� AddEmployee�� 
	                                                        // �����Ͽ� ��ü ���� 
	handler.AddEmployee(new permanentWorker("Lee", 1000));	
	handler.AddEmployee(new permanentWorker("Jun", 1000));

	// �̹��޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	//�̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowTotalSalary();
	return 0;

}