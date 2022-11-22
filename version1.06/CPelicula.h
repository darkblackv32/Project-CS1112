#include "CUsuario.h"

class Pelicula {
private:
  string nombre;
  string publicacion;
  string id;

protected:
  int cantidad_ejemplares;
  int ejemplares_totales;
  int ejemplares_alquilados;//=ejemplares_totales-cantidad_ejemplares;
  int ranking;
  //faltan set y get de estas.
  float ganancia_alquiladas;
  float ganancia_devueltas;


public:
  Pelicula();
  Pelicula(string _nombre, string _publicacion, int _ejemplares_totales);
  string get_nombre();
  string get_publicacion();
  string get_id();
  int get_ranking();
  int get_cantidad_ejemplares();
  int get_ejemplares_totales();
  void peli_alquilada();
  void set_ranking(int _ranking);
  void devolver();
};