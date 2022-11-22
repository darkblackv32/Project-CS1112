#include <bits/stdc++.h>
#include "CEmpresa.h"
using namespace std;

void menu() {
  cout << "1. Registrar pelicula\n";
  cout << "2. Registrar usuario\n";
  cout << "3. Buscar Pelicula\n";
  cout << "4. Alquilar pelicula\n";
  cout << "5. Devolver pelicula\n";
  cout << "6. Reporte pelicula\n";
  cout << "7. Salir\n";
}

void menu_buscar_pelicula() {
  cout << "3.1 Por nombre\n";
  cout << "3.2 Por anio de publicacion\n";
  cout << "3.3 Por ranking\n";
}

int main() {
  srand((unsigned int)time(NULL));

  empresa *e1 = new empresa("Block buster", "manuel bonilla 211", "213123123");

  int master_key = 0;
  int second_key = 0;
  string referencia_3;
  do {
    menu();
    cin >> master_key;
    if (master_key == 1) {
      e1->registrar_pelicula();
    }
    if (master_key == 2) {
      e1->registrar_usuario();
    }
    if (master_key == 3) {
      menu_buscar_pelicula();
      cin >> second_key;
      cout << "referencia\n";
      cin >> referencia_3;
      e1->buscar_pelicula(second_key, referencia_3);
    }
    if (master_key == 4) {
      e1->alquilar_pelicula();
    }
    if (master_key == 5) {
      e1->devolver_pelicula();
    }
    if (master_key == 6) {
      e1->reporte_peliculas();
    }
    if (master_key == 7) {
    }

  } while (master_key != 7 && master_key > 0 && master_key < 6);
}