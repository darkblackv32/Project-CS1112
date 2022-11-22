#include <bits/stdc++.h>
using namespace std;
#pragma once


class Usuario{
private:
  string nombre;
  string apellido;
  string dni;

protected:
  int peliculas_alquiladas;
  vector <pair<string,string>> datos_alquiladas;
  float costo;

public:
  Usuario();
  Usuario(string _nombre, string _apellido, string _dni);
  string get_nombre();
  string get_apellido();
  void set_costo(float _costo);
  float get_costo();
  string get_dni();
  int get_pelis();
  int get_peliculas_alquiladas();
  int set_peliculas_alquiladas(int cant);

  void agregar_pelicula_usuario(string _titulo, string _id_);

  bool pelicula_pertenece(string parametro, string nombre_o_id);



};



