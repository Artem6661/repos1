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
			"Ежемесячные расходы:" << Rent() << endl
			<< "Зарплаты: " << Salary << endl
			<< "Аренда помещения: " << Rent() << endl
			<< "Охрана Мракоборцами: " << AurorPayment
			<< endl << endl <<
			"Общие ежемесячные расходы филиала: " << TotalExpenses()
			<< endl << "\n\n" << "Прибыль чистая: ";
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
		cout << "Добро пожаловать в " << BranchName << " филиал Оливандера!"
			<< endl;
	}
	~NewBranch()
	{
		cout << endl << "Приятного дня!";
	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите название вашей лавки!";
	string MyBranchName;
	cin >> MyBranchName;

	NewBranch MyBranch(MyBranchName);

	cout << "Прибыль: " << MyBranch.GrossProfit();
	MyBranch.TotalExpenses();
	MyBranch.ShowMeMyExpences();
	cout << MyBranch.NetProfit();
}
