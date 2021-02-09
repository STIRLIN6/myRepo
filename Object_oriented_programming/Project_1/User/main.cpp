#include "pile.hpp"
#include <iostream>

int main()
{
    int n;
    std::cout << "Hany elemet szeretne hozzaadni a halmazhoz?" << std::endl;
    std::cin >> n;

    Pile p = Pile();

    for (int i = 0; i < n; i++) {
        int temp;
        std::cout << i+1 << ". elem: ";
        std::cin >> temp;

        try {
            p.add(temp);
        }
        catch (Pile::Exceptions ex) {
            if (ex == Pile::ITEM_IS_ALREDY_CONTAINED) {
                std::cout << "A " << temp << " mar benne van a halmazban. Adjon meg egy masik elemet!" << std::endl;
            }
            i--;
        }
    }

    std::cout << "Jelenleg a halmaz elemei:" << std::endl;
    p.print();
    std::cout << "Jelenlegi elemek osszege: " << p.sum() << std::endl;

    std::cout << "Hany elemet szeretne torolni a halmazbol? (Legfeljebb: " << p.size() << ")" << std::endl;
    do {
        std::cout << "A legnagyobb, amit megadhat: " << p.size() << std::endl;
        std::cin >> n;
    } while (n > p.size());

    for (int i = 0; i < n; i++) {
        int temp;
        std::cout << "Valassza ki a(z) " << i+1 << ". torlendo elemet: ";
        std::cin >> temp;

        try {
            p.remove(p.select(temp));
        }
        catch (Pile::Exceptions ex) {
            if (ex == Pile::ITEM_IS_NOT_CONTAINED) {
                std::cout << "A(z) " << temp << " nincs benne a halmazban.  Adjon meg egy masik elemet!" << std::endl;
            }
            i--;
        }
        
        std::cout << "Jelenlegi elemek: ";
        p.print();
        std::cout << "Jelenlegi elemek osszege: " << p.sum() << std::endl;
    }

    return 0;
}