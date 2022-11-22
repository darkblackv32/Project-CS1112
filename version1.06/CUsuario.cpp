#include "CUsuario.h"

  Usuario::Usuario() = default;
  Usuario::Usuario(string _nombre, string _apellido, string _dni) {
    nombre = _nombre;
    apellido = _apellido;
    dni = _dni;
    peliculas_alquiladas = 0;
  }
  string Usuario::get_nombre() { return nombre; }
  string Usuario::get_apellido() { return apellido; }
  void Usuario::set_costo(float _costo){ costo=_costo;}
  float Usuario::get_costo(){return costo;}
  string Usuario::get_dni() { return dni; }
  int Usuario::get_pelis() { return peliculas_alquiladas; }
  int Usuario::get_peliculas_alquiladas(){return peliculas_alquiladas;}
  int Usuario::set_peliculas_alquiladas(int cant){peliculas_alquiladas = cant;}

  void Usuario::agregar_pelicula_usuario(string _titulo, string _id_){
      datos_alquiladas.emplace_back(make_pair(_titulo, _id_));
  }

  bool Usuario::pelicula_pertenece(string parametro, string nombre_o_id){ //parametro: nombre o id
      bool stop=false;
      int i=0;
      do{
          if(parametro=="nombre"){
          if (nombre_o_id==datos_alquiladas[i].first) {
              stop=true;
          }
          else {
              stop=false;
          }}
          else if(parametro=="id"){
              if (nombre_o_id==datos_alquiladas[i].second) {
                  stop=true;
              }
              else {
                  stop=false;
              }}
          i++;

      }while(!stop);
      return stop;
  }


