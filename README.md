# Polynomial-Factorization

**Command line program for polynomial factorization mod p^n**

---
## :clipboard: Usage Manual

- The user selects an option from the menu: 2 = factorization, 1 = helper, 0 = exit
- After selecting the factorization, the user is prompted to enter any prime number and then a positive integer greater than 1 (this positive number determines the extension of the finite field *GF(p^n)*).
- In the next step, it is necessary to enter the mononic polynomial, which we will factorize.
- The screen displays an evaluation of whether the entered polynomial is reducible or irreducible.
- In the case of a reducible polynomial, the user is provided with a list of factors in a readable form as well as in a format provided by the [NTL](https://libntl.org/) library.

<p align="center">
<img src="https://github.com/martinkubecka/Polynomial-Factorization/blob/main/images/usage.png" alt="App usage">
</p>

### Help
- If the user selects a help option from the main menu, examples of the polynomial format used by the application are displayed.
- As we can see, the coefficients belonging to *x^0* to *x^n* are written in square brackets in this order.

<p align="center">
<img src="https://github.com/martinkubecka/Polynomial-Factorization/blob/main/images/help.png" alt="Help">
</p>

---
## :running: Running Polynomial-Factorization

Launch the application by running **PolynomialFactorization.exe**, which you can download from the [releases](https://github.com/martinkubecka/Polynomial-Factorization/releases).
