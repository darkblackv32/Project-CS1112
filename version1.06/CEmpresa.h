#include "CPelicula.h"
#include <fstream>
#include <iomanip>
#include <cstdio>
#include "FuncionSIGNO.h"


class empresa {
private:
  string nombre;
  string direccion;
  string ruc;

protected:
  vector<Pelicula *> Peliculas;
  vector<Usuario *> Usuarios;
  float peli_alquiladas=0;//dinero que gana con las alquiladas
  float peli_devueltas=0;//dinero que gana con las devueltas.h
  int cant_alquiladas=0;
  int cant_disponibles=0;


public:
  empresa();
  empresa(string _nombre, string _direccion, string _ruc);
  string get_nombre();
  int get_size_usuario();
  void adicionar_pelicula(Pelicula *pelicula);
  void adicionar_usuario(Usuario *usuario);
  void buscar_pelicula(int opcion, string palabra);
  int dni_search(string dato);

    int pelicula_search(string nombre);

  void mostrar_usuarios();
  void mostrar_peliculas();
  void registrar_usuario();
  void registrar_pelicula();
  void peliculas_disponibles();
  int Calcular_alquiladas();
  int Calcular_disponibles();
  


  float calc_renta(int peli, int tiempo);
  void alquilar_pelicula();

  void comprobacion_nombre_id(string palabra, int opcion);

  void devolver_pelicula();




  void reporte_peliculas();
  void almacenar_registro();
  void cerrar_empresa();

};
