#include "Runway.hpp"
#include "Resource.hpp"
#include <string>

using std::string;

Runway::Runway(){

}
Runway::Runway(string name): Resource(ResourceType::Runway), name(name){

}
string Runway::getName(){
    return name;
}
void Runway::setName(string nome){
    name=nome;
}
