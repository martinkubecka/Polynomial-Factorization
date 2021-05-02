#include<iostream>
//#include<NTL/ZZ_pXFactoring.h> // polynomial factorization

//NTL_CLIENT
using namespace std;

void Help() {

	cout << "\nHELP\n" << endl;
	system("pause");
}

void PrintMenu()
{
	int choice = -1;

	while (choice != 0) {
	
		cout << "***********************************" << endl;
		cout << "********** Main Menu **************" << endl;
		cout << "***********************************" << endl;
		cout << "(2): Polynomial Factorization" << endl;
		cout << "(1): Help" << endl;
		cout << "(0): Exit" << endl;

		cout << "\n> : "; cin >> choice;

		switch (choice)
		{
		case 2:

			//PolynomialFactorization();
			break;
		
		case 1:

			Help();
			break;

		case 0:

			break;

		default:

			cout << "Invalid choice." << endl;
			break;
		}
	}
}

int main() {

	PrintMenu();

	return 0;
}