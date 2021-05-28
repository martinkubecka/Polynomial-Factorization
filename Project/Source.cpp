#include <iostream>
#include <NTL/ZZ_pXFactoring.h>
#include <NTL/ZZ_pEX.h>
#include <NTL/ZZ_pEXFactoring.h>

NTL_CLIENT

string polynomialToString(ZZ_pX p) {

	stringstream ss;

	for (int i = deg(p); i >= 0; i--) {
		if (p[i] != 0) {
			if (i != deg(p)) {
				ss << " + ";
			}
			if (i == 0) {
				ss << p[i];
			}
			else if (i == 1) {
				if (p[i] != 1) {
					ss << p[i] << "*";
				}
				ss << 'x';
			}
			else {
				if (p[i] != 1) {
					ss << p[i] << "*";
				}
				ss << "x^" << i;
			}
		}
	}

	return ss.str();
}

string polynomialToString(vec_pair_ZZ_pEX_long p) {

	stringstream ss;

	for (int i = 0; i < p.length(); i++) {
		if (i != 0) {
			cout << " * ";
		}
		cout << "(";
		pair_ZZ_pEX_long a = p.get(i);
		ZZ_pEX pex = a.a;
		for (int j = deg(pex); j >= 0; j--) {
			ZZ_pE pe = pex[j];
			ZZ_pX px = rep(pe);

			for (int k = deg(px); k >= 0; k--) {
				if (px[k] != 0) {
					if (j != deg(pex)) {
						cout << " + ";
					}
					if (k == 0) {
						cout << px[k];
					}
					else if (k == 1) {
						if (px[k] != 1) {
							cout << px[k] << "*";
						}
						cout << 'a';
					}
					else {
						if (px[k] != 1) {
							cout << px[k] << "*";
						}
						cout << "a^" << k;
					}
					if (j != 0)
						cout << "*x^" << j;
				}
			}
		}
		cout << ")";
		if (a.b != 1) {
			cout << "^" << a.b;
		}
	}

	return ss.str();
}

bool PolynomialFactorization() {

	ZZ prime_number;
	ZZ_pX polynom;

	// Enter prime number
	do {

		cout << "   Enter prime number: ";
		cin >> prime_number;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "   Enter prime number: ";
			std::cin >> prime_number;
		}
		
	} while (!ProbPrime(prime_number));

	ZZ_p::init(prime_number);	// define GF(prime_number)

	// Enter n
	long n;
	do {

		cout << "   Enter n: ";
		cin >> n;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "   Enter n: ";
			cin >> n;
		}

	} while (n < 1);

	// Generate an irreducible polynomial P of degree n over GF(prime_number)
	BuildIrred(polynom, n);		

	// Define GF(prime_number^n)
	ZZ_pE::init(polynom);		

	cout << "\n   GF(" << prime_number << "^" << n << ")/(" << polynomialToString(polynom) << ")" << endl << endl;

	cout << endl;
	cout << "   -- Input help: [2 1 1] = 2 + x + x^2 --" << endl << endl;

	// Enter polynom
	ZZ_pX input_polynom;
	cout << "   Enter polynomial: ";
	cin >> input_polynom;

	cout << "   Entered polynomial: " << polynomialToString(input_polynom) << endl << endl;
	
	if (LeadCoeff(input_polynom) != 1) {
		cout << "   Entered polynomial is not monic !";
		return false;
	}

	ZZ_pEX convert_polynom;
	conv(convert_polynom, input_polynom);

	//if (DetIrredTest(convert_polynom)) {
	//if (ProbIrredTest(convert_polynom)) {
	if (IterIrredTest(convert_polynom)) {

		cout << "   -> Irreducible polynomial" << endl;
	}
	else {

		cout << "   -> Reducible polynomial" << endl << endl;
		vec_pair_ZZ_pEX_long vector = CanZass(convert_polynom);
		//cout << "   Vectors: ";
		//cout << vector << endl;
		cout << "   Vectors: ";
		cout << polynomialToString(vector) << endl;
	}
	
	return false;
}

void Help() {

	cout << "\n   -------------------------------------------------------------" << endl;
	cout << "   ---------------------------- HELP ---------------------------\n" << endl << endl;
	cout << "   Polynomials need to be entered in a format as shown below :" << endl << endl;
	cout << "   x                       : [1]" << endl;
	cout << "   x + 1                   : [1 1]" << endl;
	cout << "   x2 + x + 1              : [1 1 1]" << endl;
	cout << "   x3 + x2 + 1             : [1 0 1 1]" << endl;
	cout << "   x3 + x + 1              : [1 1 0 1]" << endl;
	cout << "   x4 + x3 + x2 + x + 1    : [1 1 1 1 1]" << endl;
	cout << "   x4 + x3 + 1             : [1 0 0 1 1]" << endl;
	cout << "   x4 + x + 1              : [1 1 0 0 1]" << endl;
	cout << "   x5 + x4 + x3 + x2 + 1   : [1 0 1 1 1 1 1]" << endl;
}

void PrintMenu()
{
	int choice = -1;

	while (choice != 0) {

		
		cout << "\n   -------------------------------------------------------------" << endl << endl;
		cout << "   (2): Polynomial Factorization" << endl;
		cout << "   (1): Help" << endl;
		cout << "   (0): Exit" << endl;

		cout << "\n   > : "; cin >> choice;
		cout << endl;

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

			cout << "   Invalid choice." << endl;
			break;
		}
	}
}

int main() {

	std::wcout << R"(
    __________________________________________________________
   |                                             _            |
   |               _                            (_)      _    |
   |   _ __   ___ | |_   _ _ __   ___  _ __ ___  _  __ _| |   |
   |  | |_ \ / _ \| | | | |  _ \ / _ \|  _ \ _ \| |/ _  | |   |
   |  | |_) | (_) | | |_| | | | | (_) | | | | | | | (_| | |   |
   |  | |__/ \___/|_|\__  |_| |_|\___/|_| |_| |_|_|\__/_|_|   |
   |  | |             __/ |                                   |
   |  |_|            |___/                                    |
   |  __           _             _          _   _             |
   | / _|         | |           (_)        | | (_)            |
   || |_ __ _  ___| |_ ___  _ __ _ ______ _| |_ _  ___  _ __  |
   ||  _/ _  |/ __| __/ _ \|  __| |_  / _  | __| |/ _ \|  _ \ |
   || || (_| | (__| || (_) | |  | |/ / (_| | |_| | (_) | | | ||
   ||_| \__/_|\___|\__\___/|_|  |_/___\__/_|\__|_|\___/|_| |_||
   |                                                          |
   |               Viliam Alaksa, Martin Kubecka              |
   |                           2021                           |
   |                                                          |
   |          -------------------------------------           |
   |                      Source code :                       |
   |  www.github.com/martinkubecka/Polynomial-Factorization   |                                            
   |__________________________________________________________|
)" << '\n';

	cout << "   Console application for polynomial factorization over GF(p^n)" << endl << endl;
	

	PrintMenu();

	return 0;
}
