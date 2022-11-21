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

public:
  Usuario();
  Usuario(string _nombre, string _apellido, string _dni);
  string get_nombre();
  string get_apellido();
  string get_dni();
  int get_pelis();
  int get_peliculas_alquiladas();
  int set_peliculas_alquiladas(int cant);

  void agregar_pelicula_usuario(string _titulo, string _id_);
  bool pelicula_pertenece(string parametro, string nombre_o_id);

};

// string generarador_id() {
//     string id = "";
//     for (int i = 0; i < 8; i++) {
//         id += (char) (rand() % ('z' - 'a')) + 'a';
//     }
//     return id;
// }

