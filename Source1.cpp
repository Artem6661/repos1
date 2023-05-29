#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class BranchFinances
{
private:
	const double CostPerMonth = 50;
	const double FixProfitPercent = 0.07;
	const double FixProfit = 270;
	const double Salary = 35;
	const double AurorPayment = 15;
public:
	BranchFinances() {}

	double GrossProfit()
	{
		srand(time(nullptr));
		return rand() % 251 + 250;
	}

	double Rent()
	{
		if (GrossProfit() > FixProfit)
			return CostPerMonth + (GrossProfit() - FixProfit) * FixProfitPercent;
		else return CostPerMonth;
	}

	double TotalExpenses()
	{
		return Salary + Rent() + AurorPayment;
	}

	void ShowMeMyExpences()
	{
		cout << endl <<
			"����������� �������:" << Rent() << endl
			<< "��������: " << Salary << endl
			<< "������ ���������: " << Rent() << endl
			<< "������ ������������: " << AurorPayment
			<< endl << endl <<
			"����� ����������� ������� �������: " << TotalExpenses()
			<< endl << "\n\n" << "������� ������: ";
	}

	double NetProfit()
	{
		return GrossProfit() - TotalExpenses();
	}

	~BranchFinances() {}
};

class NewBranch :public BranchFinances
{
private:
	string BranchName;
public:
	NewBranch(string Name)
	{
		BranchName = Name;
		cout << "����� ���������� � " << BranchName << " ������ ����������!"
			<< endl;
	}
	~NewBranch()
	{
		cout << endl << "��������� ���!";
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� ����� �����!";
	string MyBranchName;
	cin >> MyBranchName;

	NewBranch MyBranch(MyBranchName);

	cout << "�������: " << MyBranch.GrossProfit();
	MyBranch.TotalExpenses();
	MyBranch.ShowMeMyExpences();
	cout << MyBranch.NetProfit();
}
