#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // pour isdigit

// Priorité des opérateurs
int priorite(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
//
// Convertit une expression infixée en NPI (postfixe)
std::string infixeVersNPI(const std::string& expr) {
    std::stack<char> pile;
    std::string npi;
    int i = 0;

    while (i < expr.size()) {
        if (isdigit(expr[i])) {
            // Lire un nombre complet
            std::string num;
            while (i < expr.size() && isdigit(expr[i])) {
                num += expr[i];
                i++;
            }
            npi += num + ' ';  // ajouter nombre et espace
        }
        else if (expr[i] == '(') {
            pile.push(expr[i]);
            i++;
        }
        else if (expr[i] == ')') {
            while (!pile.empty() && pile.top() != '(') {
                npi += pile.top();
                npi += ' ';
                pile.pop();
            }
            if (!pile.empty()) pile.pop(); // retire '('
            i++;
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            while (!pile.empty() && priorite(pile.top()) >= priorite(expr[i])) {
                npi += pile.top();
                npi += ' ';
                pile.pop();
            }
            pile.push(expr[i]);
            i++;
        }
        else {
            // Ignorer les espaces
            i++;
        }
    }

    // Dépiler les opérateurs restants
    while (!pile.empty()) {
        npi += pile.top();
        npi += ' ';
        pile.pop();
    }

    return npi;
}

// Calcule le résultat d'une expression NPI
int calculNPI(const std::string& npi) {
    std::stack<int> pile;
    int i = 0;

    while (i < npi.size()) {
        if (isdigit(npi[i])) {
            int num = 0;
            while (i < npi.size() && isdigit(npi[i])) {
                num = num * 10 + (npi[i] - '0');
                i++;
            }
            pile.push(num);
        }
        else if (npi[i] == '+' || npi[i] == '-' || npi[i] == '*' || npi[i] == '/') {
            int b = pile.top(); pile.pop();
            int a = pile.top(); pile.pop();
            int res = 0;
            switch (npi[i]) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/': res = a / b; break;
            }
            pile.push(res);
            i++;
        }
        else {
            // Ignorer espaces
            i++;
        }
    }

    return pile.top();
}

int main() {
    std::string expr;
    std::cout << "Entrez une expression (ex: 2+(7*(7-5))+8) : ";
    std::getline(std::cin, expr);

    std::string npi = infixeVersNPI(expr);
    std::cout << "Expression en NPI : " << npi << "\n";

    int resultat = calculNPI(npi);
    std::cout << "Resultat : " << resultat << "\n";

    return 0;
}
