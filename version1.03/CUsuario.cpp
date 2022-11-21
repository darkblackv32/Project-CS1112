#include "CUsuario.h"

  Usuario::Usuario() = default;
  Usuario::Usuario(string _nombre, string _apellido, string _dni){
    nombre = _nombre;
    apellido = _apellido;
    dni = _dni;
    peliculas_alquiladas = 0;
  }
  
  string Usuario::get_nombre(){return nombre; }
  string Usuario::get_apellido(){return apellido; }
  string Usuario::get_dni(){return dni; }
  int Usuario::get_pelis(){return peliculas_alquiladas; }
  int Usuario::get_peliculas_alquiladas(){return peliculas_alquiladas;}
  int Usuario::set_peliculas_alquiladas(int cant){peliculas_alquiladas = cant;}