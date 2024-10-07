#include <iostream>
#include <iomanip>
int main() {

    const int value_min = 2;
    const int value_max = 1000;
    const int spacing = 10;


    bool restart = true;
    while (restart){

        int user_choice = 0;

        while (user_choice < value_min || user_choice > value_max) {
            std::cout << "Entrer une valeur [" << value_min << '-' << value_max << ']' << std::endl;
            std::cin >> user_choice;
        }


        int column = 0;
        // Calcule des n nombres premiers
        for (int tested_value = 2; tested_value <= user_choice; tested_value++) {
            bool prime = true;

            for (int divisor = 2; divisor < tested_value; divisor++) {
                if (tested_value % divisor == 0) {
                    prime = false;
                    break;
                }
            }

            // Affichage
            if (prime) {
                std::cout  << tested_value << std::setw(spacing);
                if (column < 4) {
                    column++;
                } else {
                    std::cout << std::endl;
                    column = 0;
                }
            }
        }

        std::cout << std::endl;

        while(true) {
            char restart_choice = ' ';

            std::cout << "Voulez-vous recommencer [O/N]" << std::endl;
            std::cin >> restart_choice;
            if (restart_choice == 'O') {
                break;
            } else if (restart_choice == 'N') {
                restart = false;
                break;
            }
        }

    }

    return 0;
}
