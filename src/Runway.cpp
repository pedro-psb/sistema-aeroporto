#include "Runway.hpp"
#include <string>
using std::string;
Runway::Runway(){

}
Runway::Runway(string name, int id):Resource(id), name(name){

}
string Runway::getName(){
    return name;
}
void Runway::setName(string nome){
    name=nome;
}