#include <string>

using std::string;

class Airport {
private:
  int id;
  static int currentId;
  string name;

public:
  Airport(string name);
  int getId();
  string getName();
};
