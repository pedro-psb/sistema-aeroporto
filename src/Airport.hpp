#include <string>

using std::string;

class Airport {
private:
  int id;
  string name;

public:
  Airport(string name);
  int getId();
  string getName();
};
