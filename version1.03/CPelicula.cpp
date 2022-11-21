#include "CPelicula.h"
#include "Generator.h"

    Pelicula::Pelicula() = default;
    Pelicula::Pelicula(string _nombre, string _publicacion, int _ejemplares_totales) {
    nombre = _nombre;
    publicacion = _publicacion;
    ejemplares_totales = _ejemplares_totales;
    cantidad_ejemplares = _ejemplares_totales;
    ranking = 5;
    id = generarador_id();
  }
  string Pelicula::get_nombre() { return nombre; }
  string Pelicula::get_publicacion() { return publicacion; }
  string Pelicula::get_id() { return id; }
  int Pelicula::get_ranking() { return ranking; }
  int Pelicula::get_cantidad_ejemplares() { return cantidad_ejemplares; }
  int Pelicula::get_ejemplares_totales() { return ejemplares_totales; }
  void Pelicula::peli_alquilada() { cantidad_ejemplares = get_cantidad_ejemplares() - 1; }
  void Pelicula::set_ranking(int _ranking) { ranking = _ranking; }
  void Pelicula::devolver() { cantidad_ejemplares = get_cantidad_ejemplares() + 1; }