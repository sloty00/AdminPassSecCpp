// AdminPassSecCpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class PasswordManager {
private:
    std::vector<std::string> passwords;

    std::string generatePassword(int length, bool useSpecialChars) {
        const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        const std::string specialChars = "!@#$%^&*()_+[]{}|;:,.<>?";

        std::string allCharacters = characters;
        if (useSpecialChars) {
            allCharacters += specialChars;
        }

        std::string password;
        for (int i = 0; i < length; ++i) {
            int index = rand() % allCharacters.size();
            password += allCharacters[index];
        }

        return password;
    }

public:
    PasswordManager() {
        srand(static_cast<unsigned>(time(0)));
    }

    void createPassword() {
        int length;
        bool useSpecialChars;

        std::cout << "Ingrese la longitud de la contraseña: ";
        std::cin >> length;
        std::cout << "¿Incluir caracteres especiales? (1 para sí, 0 para no): ";
        std::cin >> useSpecialChars;

        std::string newPassword = generatePassword(length, useSpecialChars);
        passwords.push_back(newPassword);

        std::cout << "Contraseña generada y almacenada.\n";
    }

    void showPasswords() {
        if (passwords.empty()) {
            std::cout << "No hay contraseñas generadas.\n";
            return;
        }

        std::cout << "\nContraseñas generadas:\n";
        for (size_t i = 0; i < passwords.size(); ++i) {
            std::cout << i + 1 << ". " << passwords[i] << "\n";
        }
    }

    void deletePassword() {
        showPasswords();
        if (passwords.empty()) return;

        int index;
        std::cout << "Ingrese el número de la contraseña que desea eliminar: ";
        std::cin >> index;

        if (index < 1 || index > passwords.size()) {
            std::cout << "Número de contraseña inválido.\n";
            return;
        }

        passwords.erase(passwords.begin() + index - 1);
        std::cout << "Contraseña eliminada.\n";
    }

    void menu() {
        int choice;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Crear Contraseña Segura\n";
            std::cout << "2. Mostrar Contraseñas Generadas\n";
            std::cout << "3. Eliminar Contraseña Generada\n";
            std::cout << "4. Salir\n";
            std::cout << "Ingrese su opción: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                createPassword();
                break;
            case 2:
                showPasswords();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
            }
        } while (choice != 4);
    }
};

int main() {
    PasswordManager pm;
    pm.menu();
    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
