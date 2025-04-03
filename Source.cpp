#include <iostream>
#include <string>
#include "List.h"
using namespace std;

int main() {

    List<string> lunch;
    lunch.insert("Tacos", 0);
    lunch.insert("Gyros", 1);
    lunch.insert("Kebab", 2);
    lunch.insert("Burger", 3);
    lunch.insert("PB&J", 4);
    lunch.insert("Sushi", 5);

    cout << lunch.get(2) << endl;
    cout << lunch.get("PB&J") << endl;
    lunch.remove(0);
    lunch.display();

    return 0;
}
