#include <iostream>
#include <NTL/ZZ_pXFactoring.h>
#include <NTL/ZZ_pEX.h>

NTL_CLIENT

void Help() {

	cout << "\nHELP\n" << endl;
	system("pause");
}

void Factoring() {

}

bool PolynomialFactorization() {
	//zadaj prvocislo
	ZZ prvocislo;
	ZZ_pX polynom;
	do {
		cout << "Zadajte prvocislo: ";
		cin >> prvocislo;
	} while (!ProbPrime(prvocislo));
	
	ZZ_p::init(prvocislo);
	//zadaj n
	long n;
	do {
		cout << "Zadajte n: ";
		cin >> n;
	} while (n<1);

	//zadaj polynom alebo nie
	//cin >> polynom;
	BuildIrred(polynom, n);
	cout << polynom << endl;
	ZZ_pE::init(polynom);

	ZZ_pEX delenec;

	//cin >> delenec;
	random(delenec, 2);  //1*x^2 + c1*x^1 ...
	cout << delenec;
	return false;
	
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

			PolynomialFactorization();
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

	PolynomialFactorization();
	//PrintMenu();
	system("pause");
	return 0;
}
/*
int main()
{
	ZZ a, b, c;

	cin >> a;
	cin >> b;
	c = a * b;
	cout << c << endl;


	system("pause");
	return 0;
}
*/
