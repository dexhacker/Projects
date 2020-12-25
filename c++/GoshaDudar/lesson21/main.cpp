#include <iostream>

using namespace std;

class Person;

class Dog {
    friend class Person;
private:
    int health = 100;
};

class Person {
public:
    void Damage(Dog &d) {
        d.health -= 20;
        cout << "Health of the animal " << d.health << endl;
    }

    void Kill(Dog &d) {
        d.health = 0;
        cout << "Health of the animal " << d.health << endl;
    }

    void Heal(Dog &d) {
        d.health += 30;
        cout << "Health of the animal " << d.health << endl;
    }
};

int main() {
    Dog skuby;
    Person Volodya;

    Volodya.Damage(skuby);
    Volodya.Kill(skuby);
    Volodya.Damage(skuby);
    Volodya.Heal(skuby);

    cout << endl;
    Dog haski;
    Volodya.Damage(haski);

    return 0;
}