#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int PIN = 1111;
const int MAX_CAP = 700;
const double COST_CAPUCHINO = 3.2;
const double COST_ESSPRESO = 2.7;
const double COST_LATTE = 3.0;

void showServiceMenu();
void showBalance();
int restCups();
void takeOffAllMoney();
void serviceMenu();

void showStartMenu();
void depositMoney();
void choiseMoney();
void showChoiseMoneyMenu();
void cookCoffee(double costCoffee, string nameCoffee);
void progresBar();

double totalBalance = 0.0;
double balance = 5.0;
int totalCups = 7;
int barl = 100;

int main() {
        int choise = -1;
        double costCoffee = 0.0;

        while(true) {
                system("cls");
                showStartMenu();

                cout << "Your choise: ";
                cin >> choise;

                if (choise == 1) {
                        depositMoney();
                }
                else if (choise == 2) {
                        costCoffee = COST_ESSPRESO;
                        cookCoffee(costCoffee, "esspresso");
                }
                else if (choise == 3) {
                        costCoffee = COST_CAPUCHINO;
                        cookCoffee(costCoffee, "cappuccino");
                }
                else if (choise == 4) {
                        costCoffee = COST_LATTE;
                        cookCoffee(costCoffee, "latte");
                }
        }

        return 0;
}

void showStartMenu()
{
        cout << "*** CoffeeBOX MENU ***" << endl;
        cout << endl;
        cout << "\t" << "Welcome!" << endl;
        cout << "\t" << "You balance is " << balance << endl;
        cout << endl;
        cout << "1 - Deposite money" << endl;
        cout << "2 - Espresso\t" << COST_ESSPRESO << endl;
        cout << "3 - Cappuccino\t" << COST_CAPUCHINO << endl;
        cout << "4 - Latte\t" << COST_LATTE << endl;
        cout << "5 - Service menu" << endl;
        cout << "0 - Exit" << endl;
        cout << endl;
}

void cookCoffee(double costCoffee, string nameCoffee) {
        if (costCoffee > balance) {
                system("cls");
                cout << "You need deposit more money" << endl;
        }
        else if (totalCups == 0) {
                system("cls");
                cout << "All cups end. You can't order coffee" << endl;
        }
        else {
                system("cls");
                cout << "    " << "Your coffee is preparing..." << endl;
                progresBar();
        	cout << "       " << "You " << nameCoffee << " is ready!" << endl;
        	cout << endl;
        	cout << "      " << "Thank you!" << endl;
        	cout << "   " << "Have a nice day!"<< endl;
                totalCups--;
                balance -= costCoffee;
        }
}

void progresBar() {
        cout << "[";
        for (int i = 0; i < 30; i++) {
           Sleep(100);
           cout << "*";
        }
        cout << "]" << endl;
}

void depositMoney() {
        int choise = -1;

        while(true) {
                system("cls");
                showChoiseMoneyMenu();

                cout << "Your choise: ";
                cin >> choise;

                if (choise == 1) {
                        totalBalance += 0.1;
                        balance += 0.1;
                }
                else if (choise == 2) {
                        totalBalance += 0.2;
                        balance += 0.2;
                }
                else if (choise == 3) {
                        totalBalance += 0.5;
                        balance += 0.5;
                }
                else if (choise == 4) {
                        totalBalance += 1.0;
                        balance += 1.0;
                }
                else if (choise == 5) {
                        totalBalance += 2.0;
                        balance += 2.0;
                }
                else if (choise == 0) {
                        break;
                }
                else
                        ;
        }
}

void showChoiseMoneyMenu() {
        cout << "*** COFFEEbox deposit menu ***" << endl;
        cout << "\t" << "You balance is " << balance << endl;
	cout << endl;
	cout << "1 - Deposut 10 kopecks" << endl;
        cout << "2 - Deposut 20 kopecks" << endl;
        cout << "3 - Deposut 50 kopecks" << endl;
        cout << "4 - Deposut 1 rubles" << endl;
        cout << "5 - Deposut 2 rubles" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}




/*error
1 - You add cups less than 0
2 - Sum totalCups and new cups more than 700
*/
void serviceMenu() {
        int serviceChoise = 0;
        int error = 0;

        while(true) {
                system("cls");
                showServiceMenu();

                cout << "Your choise: ";
                cin >> serviceChoise;
                if (serviceChoise == 1) {
                        showBalance();
                }
                else if (serviceChoise == 2) {
                        error = restCups();
                }
                else if (serviceChoise == 3) {
                        takeOffAllMoney();
                }
                else if (serviceChoise == 0) {
                        break;
                }

                if (error == 1) {
                        cout << "" << endl;
                }
                //else if ()
        }
}

void showServiceMenu()
{
	cout << "*** COFFEEbox SERVICE MENU ***" << endl;
	cout << endl;
	cout << "1 - Show total balance" << endl;
	cout << "2 - Rest of the cups" << endl;
	cout << "3 - Take off all money" << endl;
	cout << "0 - Exit" << endl;
	cout << endl;
}

void showBalance() {
        int choise = 0;

        while (true) {
                system("cls");
                cout << "*** COFFEEbox SERVICE MENU ***" << endl;
                cout << totalBalance << " rubles in a coffee machine" << endl;
                cout << "0 - Back to Service menu" << endl;
                cout << "Your choise: ";
                cin >> choise;
                if (choise == 0)
                        break;
        }

}

int restCups() {
        int addCups = 0;
        int maxForCheck = MAX_CAP;
        system("cls");
        cout << "*** COFFEEbox SERVICE MENU ***" << endl;
        cout << totalCups << " cups in a coffee machine" << endl;
        cout << "Your choise: ";
        cin >> addCups;
        if (addCups < 0) {
                return 1;
        }
        else if ((addCups + totalCups) > maxForCheck){
                return 2;
        }
        else {
                totalCups += addCups;
                return 0;
        }

}

void takeOffAllMoney() {
        totalBalance = 0.0;
        balance = 0.0;
        int choise = 0;
        while (true) {
                system("cls");
                cout << "*** COFFEEbox SERVICE MENU ***" << endl;
                cout << "You take all money in a coffee machine. Total balance is " << totalBalance << endl;
                cout << "0 - Back to Service menu" << endl;
                cout << "Your choise: ";
                cin >> choise;
                if (choise == 0)
                        break;
        }
}
