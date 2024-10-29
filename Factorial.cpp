#include <iostream>
using namespace std;

int factorial(int);
void cajero();



int main() {
    int opcion;
    
    /** imprimimos el menu principal **/
    cout << "--- menu principal ---\n";
    cout << "1. calcular factorial\n";
    cout << "2. usar cajero automatico\n";
    cout << "seleccione una opcion: ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            /** calculo del factorial de un numero ingresado por el usuario **/
            int num;
            cout << "ingrese un numero entero para calcular su factorial: ";
            cin >> num;

            if (num < 0)
                cout << "el factorial no esta definido para numeros negativos." << endl;
            else
                cout << "el factorial de " << num << " es: " << factorial(num) << endl;
            break;
        }
        case 2:
            /** ejecuta la funcion del cajero **/
            cajero();
            break;
        default:
            /** mensaje de error si la opcion no es valida **/
            cout << "opcion no valida. cerrando el programa." << endl;
    }

    return 0;
}
/** funcion para calcular el factorial de un numero **/
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

/** funcion de cajero automatico con opciones de consultar saldo y retirar efectivo **/
void cajero() {
    int saldo = 20000;  /** inicializamos el saldo en 20000 **/
    int opcion;
    int retiro;

    do {
        /** imprimimos el menu del cajero automatico **/
        cout << "\n--- menu de cajero automatico ---\n";
        cout << "1. consultar saldo\n";
        cout << "2. retirar efectivo\n";
        cout << "3. salir\n";
        cout << "seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                /** consultar el saldo actual **/
                cout << "su saldo actual es: $" << saldo << endl;
                break;
            case 2:
                /** retirar efectivo **/
                cout << "ingrese la cantidad a retirar: $";
                cin >> retiro;
                if (retiro > saldo) {
                    cout << "fondos insuficientes." << endl;
                } else {
                    saldo -= retiro;
                    cout << "retiro exitoso. su saldo actual es: $" << saldo << endl;
                }
                break;
            case 3:
                /** salir del cajero automatico **/
                cout << "gracias por usar el cajero automatico." << endl;
                break;
            default:
                /** mensaje de error si la opcion no es valida **/
                cout << "opcion no valida. intente de nuevo." << endl;
        }
    } while (opcion != 3);  /** repetimos el menu hasta que el usuario elija salir **/
}