#include <bits/stdc++.h>
using namespace std;
#pragma once

class Usuario {
private:
  string nombre;
  string apellido;
  string dni;

protected:
  int peliculas_alquiladas;

public:
  Usuario();
  Usuario(string _nombre, string _apellido, string _dni);
  string get_nombre();
  string get_apellido();
  string get_dni();
  int get_pelis();
  int get_peliculas_alquiladas();
  int set_peliculas_alquiladas(int cant);
};

