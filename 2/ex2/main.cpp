#include <iostream>
#include <vector>

using namespace std;

class Account
{
private:
  int saldo{0};
  vector<double> transactions;
  static double interest_rate;

public:
  explicit Account(int s) : saldo{s} {}
  void deposit(int amount)
  {
    transactions.push_back(amount);
    saldo += amount;
  }
  void withdraw(int x)
  {
    transactions.push_back(-x);
    saldo -= x;
  }
  void print(void)
  {
    cout << "T:";
    for (int i; i < transactions.size(); i++)
    {
      cout << transactions.at(i) << " ";
    }
    cout << endl
         << "Saldo:" << saldo << endl;
  }
  void add_interest(void)
  {
  }
  static void set_interest_rate(double interest_rate)
  {
  }
  double Account::interest_rate = 0.01;
};

int main()
{
  Account myAccount(1);
  myAccount.deposit(1000);
  myAccount.deposit(1000);
  myAccount.deposit(1000);
  myAccount.withdraw(100);
  myAccount.print();
  Account::set_interest_rate;

  return 0;
}