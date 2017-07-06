#include <iostream>
using namespace std;

int main(){
    char op;
    float operand1, operand2;

    cout << "-- Einfacher Taschenrechner --\nEingabe: op1 op op2\n";
    cin >> operand1 >> op >> operand2;
    
    switch(op) {
        case '+' :
            cout << operand1 << " + " << operand2 << " = " << operand1 + operand2 << endl;
            break;
            
        case '-' :
            cout << operand1 << " - " << operand2 << " = " << operand1 - operand2 << endl;
            break;
            
        case '*' :
            cout << operand1 << " * " << operand2 << " = " << operand1 * operand2 << endl;
            break;
        
        case '/' :
            if (operand2 == 0)
            {
                cout << "Division durch 0 nicht möglich.\n";
                break;
            }
            cout << operand1 << " / " << operand2 << " = " << operand1 / operand2 << endl;
            break;
            
        default :
            cout << "Falsche Eingabe.\n";
            break;
    }
    return 0;
}    

/*
    

    }
*/    
