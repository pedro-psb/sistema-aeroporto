#include "includes.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    Destination d1 = Destination("Belo Horizonte", 50);
    Destination d2 = Destination("Justinopolis", 50);
    Destination d3 = Destination("Vale Verde", 80);

    cout << "ID d1: " << d1.getId() << std::endl;
    cout << "ID d2: " << d2.getId() << std::endl;
    cout << "ID d3: " << d3.getId() << std::endl;

    return 0;
}
