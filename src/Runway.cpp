#include "Runway.hpp"
#include <string>
using std::string;
Runway::Runway(){

}
Runway::Runway(string name): Resource(), name(name){

}
string Runway::getName(){
    return name;
}
void Runway::setName(string nome){
    name=nome;
}