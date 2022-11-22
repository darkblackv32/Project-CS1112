#include "CEmpresa.h"
#include "signo.h"

  empresa::empresa() = default;
  empresa::empresa(string _nombre, string _direccion, string _ruc) {
    nombre = _nombre;
    direccion = _direccion;
    ruc = _ruc;
  }
  string empresa::get_nombre() { return nombre; }
  int empresa::get_size_usuario() { return Usuarios.size(); }
  void empresa::adicionar_pelicula(Pelicula *pelicula) { Peliculas.push_back(pelicula); }
  void empresa::adicionar_usuario(Usuario *usuario) { Usuarios.push_back(usuario); }
  void empresa::buscar_pelicula(int opcion, string palabra) {
    string ejemplo;
    if (opcion == 1) {
      for (int i = 0; i < Peliculas.size(); i++) {
        ejemplo = Peliculas[i]->get_nombre();
        if (ejemplo.find(palabra) != std::string::npos) {
          cout << Peliculas[i]->get_nombre() << endl;
        }
      }
    }
    if (opcion == 2) {
        string signo;
        int anio_referencia;
        cout<<"Ingrese su anio de refrencia: "<<endl;
        cin>>anio_referencia;
        cout<<"Mayor(>=) o Menor(<=): "<<endl;
        cin>>signo;

       if(Signo(signo)){
           for (int i = 0; i < Peliculas.size(); i++) {
               ejemplo = Peliculas[i]->get_publicacion();
               if(anio_referencia<=stoi(ejemplo)){
                   cout<<Peliculas[i]->get_nombre()<<endl;
               }
           }
       }
       else{
           for (int i = 0; i < Peliculas.size(); i++) {
               ejemplo = Peliculas[i]->get_publicacion();
               if(anio_referencia>=stoi(ejemplo)){
                   cout<<Peliculas[i]->get_nombre()<<endl;
               }
           }
       }

    }
    if (opcion == 3) {
      int rank;
      cout<<"Ingrese el ranking: "<<endl;
      cin>>rank;
      string signo;
      cout<<"Mayor(>=) o Menor(<=): "<<endl;
      cin>>signo;
      if(Signo(signo)){
          for (int i = 0; i < Peliculas.size(); i++) {
                ejemplo = Peliculas[i]->get_ranking();
                if(rank<=stoi(ejemplo)){
                    cout<<Peliculas[i]->get_nombre()<<endl;
                }
            }
        }
      else{
          for (int i = 0; i < Peliculas.size(); i++) {
              ejemplo = Peliculas[i]->get_ranking();
              if(rank>=stoi(ejemplo)){
                  cout<<Peliculas[i]->get_nombre()<<endl;
              }
            }
        }
    }
  }

  int empresa::dni_search(string dato) {
      int indice=0;
      int i=0;
      bool stop=false;
      do{
          if (Usuarios[i]->get_dni() == dato) {
              indice=i;
              stop=true;
          }
          else {
              indice = -1;
              stop=false;
          }
          i++;

      }while(stop==false);
    return indice;
  }

    int empresa::pelicula_search(string nombre) {
        int indice=0;
        int i=0;
        bool stop=false;
        do{
            if (Peliculas[i]->get_nombre() == nombre) {
                indice=i;
                stop=true;
            }
            else {
                indice = -1;
                stop=false;
            }
            i++;

        }while(stop==false);
        return indice;
    }

  void empresa::mostrar_usuarios() {
    for (int i = 0; i < Usuarios.size(); i++) {
      cout << Usuarios[i]->get_nombre() << " " << Usuarios[i]->get_dni()
           << endl;
    }
  }
  void empresa::mostrar_peliculas() {
    for (int i = 0; i < Peliculas.size(); i++) {
      cout << Peliculas[i]->get_nombre() << " "
           << Peliculas[i]->get_cantidad_ejemplares() << endl;
    }
  }

  void empresa::registrar_usuario() {

    int num = Usuarios.size() + 1;
    string nombre, apellido, dni;

    cout << "Nombre\n";
    cin >> nombre;
    cout << "\nApellido\n";
    cin >> apellido;
    cout << "\nDni\n";
    cin >> dni;
    Usuarios.push_back(new Usuario(nombre, apellido, dni));
  }
  void empresa::registrar_pelicula() {
    string nombre;
    string publicacion;
    int ejemplares = 0;
    cin.ignore();

    cout << "Nombre\n";
    getline(cin, nombre);
    cout << "\nPublicacion\n";
    getline(cin, publicacion);
    cout << "\nEjemplares\n";
    cin >> ejemplares;
    // peliculas.emplace_back(nombre,publicacion,ejemplares);
    Peliculas.push_back(new Pelicula(nombre, publicacion, ejemplares));
  }
  void empresa::peliculas_disponibles() {
    for (int i = 0; i < Peliculas.size(); i++) {
      cout << endl
           << i + 1 << ". " << Peliculas[i]->get_nombre() << " :"<<endl;
        cout <<"Anio publicaciOn: "<< Peliculas[i]->get_publicacion() <<endl;
        cout <<"Ranking: "<< Peliculas[i]->get_ranking() <<endl;
        cout <<"Cantidad ejemplares disponibles: "<< Peliculas[i]->get_cantidad_ejemplares() <<endl;
        cout <<"Id: "<< Peliculas[i]->get_id() << endl;
    }
  }

  int empresa::Calcular_alquiladas(){
      int cant=0;
      for(int i=0;i<Usuarios.size();i++){
          cant += Usuarios[i]->get_peliculas_alquiladas();

    } return cant;
  };
  int empresa::Calcular_disponibles(){
      int cant=0;
      for(int i=0;i<Peliculas.size();i++){
          cant += Peliculas[i]->get_cantidad_ejemplares();

      } return cant;

  }


  float empresa::calc_renta(int peli, int tiempo) {
    int rank = Peliculas[peli]->get_ranking();
    if (rank >= 3) {
      return tiempo * 5.4;
    }
    else if (rank < 3) {
      return tiempo * 4.3;
    }
  }
  void empresa::alquilar_pelicula() {
    string carnet;
    cout << "Ingresar DNI:";
    cin >> carnet; //carnet = DNI
    int peli;
    int peliagudo;
    int tiempo_renta;
    float dinero;
    if (dni_search(carnet) == -1) {//si el dni es de algun Usuario ya registrado
      registrar_usuario();
    }
    else if (dni_search(carnet) >= 0) {
      peliculas_disponibles();
      cout << "Que pelicula desea alquilar?\n";
      cin >> peli;//qué película de las mostradas escoges, la número 1 o 2 o 3...
      peliagudo = peli - 1;//porque el indice en los vectores empieza desde cero.
      //agregando la pelicula al vector del usuario
      //
      Usuarios[dni_search(carnet)]->agregar_pelicula_usuario(Peliculas[peliagudo]->get_nombre(),Peliculas[peliagudo]->get_id());

      cout << "Por cuanto tiempo desea rentarla (dias)?\n";
      cin >> tiempo_renta;
      dinero = calc_renta(peliagudo, tiempo_renta);
      cout << "El monto a pagar es igual a " << dinero<<" soles."<<endl;
      Peliculas[peliagudo]->peli_alquilada();//setea la cantidad de ejemplares en -1.
      Usuarios[dni_search(carnet)]->set_peliculas_alquiladas(Usuarios[dni_search(carnet)]->get_peliculas_alquiladas()+1);//agrega 1 a la cantidad de pelis alquiladas del usuario

      peli_alquiladas += dinero;
      Usuarios[dni_search(carnet)]->set_costo(dinero);
    }
  }

  void empresa::comprobacion_nombre_id(string palabra, int opcion) {
        int nuevo_rank = 0;
        int indice;//indice de la pelicula a devolver, en el vector peliculas
        bool acceso=false;

        //validando que el usuario haya alquilado esa pelicula


        for (int i = 0; i < Peliculas.size(); i++) {
            if(opcion==1 && acceso==false) {
                if ((palabra == Peliculas[i]->get_nombre()) &&
                        (Peliculas[i]->get_ejemplares_totales() >
                    Peliculas[i]->get_cantidad_ejemplares())){
                    acceso = true;
                    indice=i;

                }
                else{
                    acceso = false;
                    cout<<Peliculas[i]->get_nombre();
                }
            }
            else if(opcion==2  && acceso==false) {
                if ((palabra == Peliculas[i]->get_id() )&& (Peliculas[i]->get_ejemplares_totales() > Peliculas[i]->get_cantidad_ejemplares())){
                    acceso = true;
                    indice=i;

                }
                else{
                    acceso = false;
                }
            }

            }
        if(acceso){
            cout << "Nuevo ranking:\n";
            cin >> nuevo_rank;
            Peliculas[indice]->set_ranking(nuevo_rank);
            cout << "Esta de acuerdo con la devolucion?\n";
            cout << "1. Si.\n";
            cout << "2. No.\n";
            cin >> opcion;
            if (opcion == 1) {
                Peliculas[indice]->devolver();
                cout << "Devolucion exitosa.\n";

            }
            else if (opcion == 2) {
                cout << "--------\n";
            }

        }
        else if(acceso==false){
            cout<<"No puede realizar la devolucion."<<endl;
        }
    }

  void empresa::devolver_pelicula() {
      string dni;
      cout<<"Ingrese su dni para verificar que haya alquilado: "<<endl;
      cin>>dni;
    string indicio;
    int llave; //llave puedes ser 1 o 2, la opcion que escoja el usuario.

    cout << "Ingrese nombre o id de la pelicula a devolver:\n";
    cout << "1. Nombre\n";
    cout << "2. Id\n";
    cin >> llave;
    cin.ignore();
    if (llave == 1) {
      cout << "nombre: ";
      getline(cin, indicio);
      //indicio=nombre
      cout<<"op"<<endl;
      int indice=dni_search(dni);
      if(indice>=0 && Usuarios[indice]->pelicula_pertenece("nombre", indicio)){
            comprobacion_nombre_id(indicio,llave);
          cant_alquiladas -=1;
            peli_devueltas += Usuarios[indice]->get_costo();
                    peli_alquiladas-= Usuarios[indice]->get_costo();
      }else
            cout<<"No puede realizar esta accion."<<endl;

      //cout<<"."<<endl;//comprobando
    }
    else if (llave == 2) {
      cout << "Id: ";
        int indice=dni_search(dni);
      getline(cin, indicio);
        if(indice>=0 && Usuarios[indice]->pelicula_pertenece("id",indicio)){
            comprobacion_nombre_id(indicio,llave);
            cant_alquiladas -=1;
            peli_devueltas += Usuarios[indice]->get_costo();
            peli_alquiladas-= Usuarios[indice]->get_costo();
        }else
            cout<<"No puede realizar esta accion."<<endl;
    }
    else{
        cout<<"No existe esa opcion."<<endl;
    }
  }




  void empresa::reporte_peliculas(){
      cout<<"Reporte: "<<endl;
      cant_alquiladas=Calcular_alquiladas();
      cout<<"Cantidad de peliculas alquiladas: "<<cant_alquiladas<<endl;
      cant_disponibles=Calcular_disponibles();//ejecutamos estas funciones aquí porque
      // los datos pueden variar afuera de esta funcion
      cout<<"Cantidad de peliculas disponibles: "<<cant_disponibles<<endl;//cantidad_ejemplares

      cout<<"Ganancia por peliculas alquiladas: "<<peli_alquiladas<<endl;

      cout<<"Ganancia por peliculas devueltas: "<<peli_devueltas<<endl;
      cout<<"Ganancia total de peliculas: "<<peli_devueltas +peli_alquiladas<<endl;

  };

  void empresa::almacenar_registro(){
      //fstream archivo_escribir("../registro.txt",ios::out);
      ofstream archivo_escribir;
      //if(!archivo_escribir.is_open()){
        //  cout<<"Error al abrir el archivo registro.txt"<<endl;
      //}
      archivo_escribir.open("../registro.txt");

      archivo_escribir<<"Tienda:"<<endl<<get_nombre()<<endl;

      archivo_escribir<<"Peliculas:"<<endl;
      archivo_escribir<<setw(30)<<"Nombre,"<<setw(25)<< "Anio_publicacion, "<<setw(25)<<"Ejemplares_alquilados, "<<setw(25)<<"Ejemplares_disponibles, "<<setw(4)<<"Ranking, "<<setw(4)<<setw(12)<<"Id"<<endl;
      for(int i=0 ; i < Peliculas.size();i++){
          archivo_escribir<<setw(30)<<Peliculas[i]->get_nombre()+", "<<setw(25)<<Peliculas[i]->get_publicacion()+", "<<setw(25)<<to_string(Peliculas[i]->get_ejemplares_totales()-Peliculas[i]->get_cantidad_ejemplares())<<", "<<setw(25)<<to_string(Peliculas[i]->get_cantidad_ejemplares())+", "
                  <<setw(4)<<to_string(Peliculas[i]->get_ranking())<<setw(12)<<", "<<Peliculas[i]->get_id()<<endl;

      }
      archivo_escribir<<"Usuarios:"<<endl;
      archivo_escribir<<setw(10)<<"Nombre, "<<setw(10)<<"Apellido, "<<setw(15)<<"Dni, "<<setw(25)<<"Peliculas alquiladas"<<endl;
      for(int i=0 ; i < Usuarios.size();i++){
          archivo_escribir<<setw(10)<<Usuarios[i]->get_nombre()+", "<<setw(10)<<Usuarios[i]->get_apellido()+", "<<setw(15)<<Usuarios[i]->get_dni()<<", "<<setw(25)<<to_string(Usuarios[i]->get_peliculas_alquiladas())<<endl;

      }
      archivo_escribir.close();


  }

