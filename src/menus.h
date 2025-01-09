struct Usuarios{ // informacion de usuarios
	std::string usuario;
	std::string contra;
	int maxLine;
	bool jugado;
};
Usuarios users[5]; // cantidad permitida para usuarios

int usersCont = 0; // cantidad que hay de usuarios registrados
int activePlayer; // jugador activo


// procedimientos
void singInMenu();
void logInMenu();
void playMenu();
void autorsView();
void estdView();
void menuPrincipal();
void juegaTetris();


void juegaTetris(){
 	srand((unsigned)time(NULL)); // para las piezas random
	Tetris t1(posJuegox, posJuegoy,1 + rand() % 7 ); // crea el juego en las posisiones y la primer pieza random
	
	for(int i = 0; i < 20; i++){
		for(int j = 1; j < 11; j++){
			b1[i][j] = new Bloques(j,i); // crea los objetos bloques en sus respectivas posisiones
		} 
	}
	t1.imprimirTetris();// dibuja la primer vista del juego
	          
 	
	bool juega=true; // loop para el tiempo del juego
	while(juega){
		
		int rot=1; // la posision que lleva la pieza, va de 1 a 4
		int cont=0; // donde se encuentra la pieza en y
		int px=5; // donde se encuentra la pieza en x
		bool giro=false;//detecta si la pieza esta girando
		int t; // variable para detectar los movimientos de pieza
		
		
		int pieza = t1.getSigPieza(); //se agarra la primer pieza que se creo junto con el juego
		t1.setSigPieza(1 + rand() % 7); // se genera una sigiente pieza
		
		
		
		bool sigue=true;//loop para el tiempo de caida de la pieza
		while(sigue){
			int move=0;  //////tipo de movimiento /// 0=nada; 1=derecha; 2=izq  
			asignarTetris();
			if(cont!=0){
	    		if(inputKey(pieza, cont, px, rot, move, giro, t1)){// posibilidad de mover la pieza con teclas
					juega=false; // termina el loop de la pieza
					sigue=false; // termina el loop del juego
				}
			}
			cont++; // hace que la pieza baje
			t=piezas(pieza, cont, px, rot, move, giro, t1);
		    if(!t){// detecta si la pieza puede bajar mas o no
				sigue=false; // el loop de la pieza termina
				for (int y=19; y>=0; y--){
					int suma=0;
					for (int x=1; x<11; x++){
						suma=suma+tetris[y][x];// valida si una fila ha sido completada de abajo para arriba
					}
					if (suma==10){
						t1.incrLineas(); //si hay una linea completada suma tu puntaje
						for (int x=1; x<11; x++){
							tetris[y][x]=0; // borra esa linea 
						}
						for (int w=y; w>0; w--){
							for (int x=1; x<11; x++){
								tetris[w][x]=tetris[w-1][x]; //toma el numero del bloque de arriba
								int r, g, b;
								bool ex;
								b1[w-1][x]->getProps(r,g,b,ex); // tama las propiedades del bloque de ariiba
								b1[w][x]->getUp(r,g,b,ex); //los aplica para el bloque de la linea que ha sido borrada
							}
						}              
						y++;		     
					}
				}  
				if (cont==1||cont==0){// valida si la pieza esta hasta arriba
					juega=false;// termina el loop del juego
					mensaje("Perdiste");
					users[activePlayer].jugado=true;
					if (users[activePlayer].maxLine<t1.getLineas()){// cambia tus estadisticas
						users[activePlayer].maxLine=t1.getLineas();
					}
				}
				for (int y=0; y<20; y++){
					for (int x=1; x<11; x++){
						tetrisCompleto[y][x]=tetris[y][x]; // asigna los valores de tetris a tetrisCompleto
						if (tetris[y][x]==1){
							b1[y][x]->setExiste(pieza); // hace que los bloques existan cuando se acaba el loop de la pieza     
         
						}          
						
					}
				}	      
			}
		}
	}
}

void menuPrincipal(){
	float x, y;
	bool sigue = true;
	
	//crea los botones en sus respectivas possiciones
	boton bSingIn(250,100,100,35,"Registrarte",122,255,89);
	boton bLogIn(250,200, 100, 35,"Ingresar", 54,72,219);
	boton bAutors(250, 300,100,35, "Autores", 245, 35, 190);
	boton bSalir(450, 450, 140, 35, "Salir del programa", 190, 12,12);
	
	
	//dibuja el menu principal
	dibujaFondo(255, 174, 36);     
	bSingIn.dibujaBoton(); 
	bLogIn.dibujaBoton();
	bAutors.dibujaBoton();
	bSalir.dibujaBoton();
	refresca();
	
	
	
	while(sigue){  
		raton(x, y);

		if(raton_boton_izq()){//detecta si haces click
			if(bSingIn.isDentro(x,y)){
//detecta si haces click en el boton espesifico gracias a la funcion de la clase (funciona para todos los botones)
				bSingIn.setPress(true);
				refresca();
				espera(300);
				singInMenu(); // te lleva al menu para registrarte
				bSingIn.setPress(false);
			}
			if(bLogIn.isDentro(x,y)){
				bLogIn.setPress(true);
				refresca();
				espera(300);
				logInMenu(); //te lleva al menu para ingresar
				bLogIn.setPress(false);
			}
			if(bAutors.isDentro(x,y)){
				bAutors.setPress(true);
				refresca();
				espera(300);
				autorsView(); //te lleva a la vista de los autores
				bAutors.setPress(false);
			}
			if(bSalir.isDentro(x,y)){
				bSalir.setPress(true);
				refresca();
				espera(300);
				sigue=false; // sales del loop del menu principal y temina el programa
				bSalir.setPress(false);
				refresca();
				mensaje("El programa termino");
			}
			//Vuelve a dibujar el menu por si se fue a otra vista y regresa
			dibujaFondo(255, 174, 36);     
			bSingIn.dibujaBoton(); 
			bLogIn.dibujaBoton();
			bAutors.dibujaBoton();
			bSalir.dibujaBoton();
		}
		refresca();
		espera(50);
	}
}

void estdView(){
	float x, y;
	bool sigue=true;
	
	boton bAtras(30,30,50,35,"Atras",12,98,123);
	
	dibujaFondo(3, 70, 143);
	bAtras.dibujaBoton();
	color(NEGRO);
	
	//textos principales para estadisticas
	texto(250,50,"Estadisticas: ");
	texto(100,100,"Usuario:");
	texto(300,100,"Jugado si/no:");
	texto(500,100,"Max lineas:");
	
	//dibuja los usuarios registrados con sus estadisticas en modo de tabla para abajo
	for(int i=0;i<usersCont;i++){
		texto(100,140+(i*20),users[i].usuario);
		if(users[i].jugado==true){
			texto(300,140+(i*20),"Si");
		} else texto(300,140+(i*20),"No");
		std::string str;
		std::stringstream ss;
		ss<<users[i].maxLine;
		ss>>str;
		texto(500,140+(i*20),str);
	}

	
	refresca();
	while(sigue){
		raton(x, y);
		if(raton_boton_izq()){
			//Solamente un boton para regresar al menu de juego si se le hace click 
			if(bAtras.isDentro(x,y)){
				bAtras.setPress(true);
				refresca();
				espera(300);
				bAtras.setPress(false);
				sigue=false;	
			}			
		}
	}
}

void autorsView(){
	float x, y;
	bool sigue=true;
	
	boton bAtras(30,30,50,35,"Atras",12,98,123);
	
	//dibuja la vista de autores, no hay interaccion
	dibujaFondo(126, 198, 54);
	bAtras.dibujaBoton();
	color(NEGRO);
	texto(200,50,"Programación avanzada");
	texto(100,120,"Id:");
	texto(300,120,"Nombre:");
	texto(100,160,"0252028");
	texto(300,160,"Santiago Arreola Munguia");
	texto(100,200,"0253019");
	texto(300,200,"Jose Bernardo Sandoval Martinez");
	texto(100,240,"0258630");
	texto(300,240,"Diego Sebastian Montoya Rodríguez");
	texto(100,280,"0252854");
	texto(300,280,"Julian Rodriguez Ramírez");
	texto(180,370,"Profesor: Juan Carlos López Pimentel");

	
	refresca();
	while(sigue){
		raton(x, y);
		if(raton_boton_izq()){
			//Solamente un boton para regresar al menu de juego si se le hace click 
			if(bAtras.isDentro(x,y)){
				bAtras.setPress(true);
				refresca();
				espera(300);
				bAtras.setPress(false);
				sigue=false;	
			}			
		}
	}
}

void playMenu(){
	float x, y;
	bool sigue = true;
	
	//crea los botones en sus respectivas possiciones
	boton bPlay(250,100,100,35,"Jugar",245, 154, 35);
	boton bEtd(250,200, 100, 35,"Estadisticas", 77, 162, 60);
	boton bLogOut(250, 300,100,35, "Cerrar sesión", 167, 28, 28);	
	
	//dibuja el menu
	dibujaFondo(138, 148, 255);
	bPlay.dibujaBoton();
	bEtd.dibujaBoton();
	bLogOut.dibujaBoton();
	
	while(sigue){  
		raton(x, y);
		if(raton_boton_izq()){//detecta si haces click
//detecta si haces click en el boton espesifico gracias a la funcion de la clase (funciona para todos los botones)
			if(bPlay.isDentro(x,y)){
				bPlay.setPress(true);
				refresca();
				espera(300);
				juegaTetris(); // telleva a jugar el juego
				bPlay.setPress(false);
			}
			if(bEtd.isDentro(x,y)){
				bEtd.setPress(true);
				refresca();
				espera(300);
				estdView(); // te lleva a la vista de estadisticas
				bEtd.setPress(false);
			}
			if(bLogOut.isDentro(x,y)){
				bLogOut.setPress(true);
				refresca();
				espera(300);
				sigue=false;// termina el loop de la vista de menu de juego, te regresa al menu principal
				bLogOut.setPress(false);
			}
			dibujaFondo(138, 148, 255);
			bPlay.dibujaBoton();
			bEtd.dibujaBoton();
			bLogOut.dibujaBoton();
		}
		refresca();
		espera(50);
	}

}

void singInMenu(){
	
	float ratx, raty;
	int cont =0;
	boton bAtras(30,30,50,35,"Atras",12,98,123);
	
	//informacion que esta registrando el usuario
	std::string userInfo[3]= {"","",""};
	
	//componentes de la vista
	dibujaFondo(35, 150, 243);
	bAtras.dibujaBoton();
	texto(250, 75, "Usuario");
	texto(250, 95,  userInfo[0]);
	texto(250, 150, "Constraseña");
	texto(250, 170, userInfo[1]);
	texto(250, 225, "Confirmar Contraseña");
	texto(250, 235, userInfo[2]);
	
	while (cont < 3){
		int x=250, y=75+(75*cont);
	  	char nombre[50];
	  	int i=0;
	  	nombre[i]='_'; // para que se vea el cursor
	  	nombre[i+1]='\0';
	  	bool sigue=true;
	  	color(NEGRO);
	  	texto(x,y+20,nombre);
	  	refresca();
	  	do{
			int t = tecla(); //funcion de miniwin lee un caracter
			if(t==NINGUNA){
			}
			else{
				if(t==RETURN){
		            nombre[i]='\0';
		            sigue=false;
		            std::string escribiste(nombre); 
					userInfo[cont]=escribiste;
				}else{
					if(t==IZQUIERDA){
						if(i>1)
			               	i--;
			            else
			            	i=0;
				  	}else{
						if(t==ESPACIO){
							nombre[i]=' ';
						}else{
				  			nombre[i]=t;	
						}
						i++;
					}
					// si se escribe o se borra algo se vuelve a actualizar toda la pagina	
					borra();		
					dibujaFondo(35, 150, 243);
					bAtras.dibujaBoton();
					
					texto(250, 75, "Usuario");
					texto(250, 95,  userInfo[0]);
					texto(250, 150, "Constraseña");
					texto(250, 170, userInfo[1]);
					texto(250, 225, "Confirmar Contraseña");
					texto(250, 235, userInfo[2]);


				    nombre[i]='_'; // para que se vea el cursor
					nombre[i+1]='\0';
					texto(x,y+20,nombre);
					refresca();
				}
			}
			raton(ratx,raty);
			if(raton_boton_izq()){
				//Solamente un boton para regresar al menu de juego si se le hace click 
				//Se le puede hacer click en cualquier momento
				if(bAtras.isDentro(ratx,raty)){
					bAtras.setPress(true);
					refresca();
					espera(300);
					bAtras.setPress(false);
					sigue=false;
					cont=3;
				}
			}
			espera(30);
		}while(sigue);
		cont++;
	}
	if(usersCont<=4){// valida si hay espacio en la base de datos
		if (cont !=4){// valida si se salio del loop antes de llenar los campos
			int i=0;
			bool registro = true;
			while(i<5){
				if (userInfo[0]==users[i].usuario){// valida si el nombre de usuario ya esta tomado
					mensaje("El nombre de usuario ya esta tomado");
					registro = false;
					i=5;
				}
				i++;
			}
			if(userInfo[1]!=userInfo[2]){ // valida si las contrasenas con iguales
				mensaje("Las contraseñas no coinciden");
				registro = false;
			}
			if(registro==true){// si todo cuadra registra un nuevo usuario
				users[usersCont].usuario=userInfo[0];
				users[usersCont].contra=userInfo[1];
				users[usersCont].jugado=false;
				users[usersCont].maxLine = 0;
				usersCont++;
			}
		}
	}else mensaje("Solo se pueden registras 5 usuarios. Base de datos llena");
}

void logInMenu(){
	float ratx, raty;
	int cont =0;
	boton bAtras(30,30,50,35,"Atras",12,98,123);
	
	//Informacion que ingresa el usuario
	std::string userInfo[2]= {"",""};
	
	//dibuja la vista
	dibujaFondo(255, 91, 89);
	bAtras.dibujaBoton();
	texto(250, 75, "Usuario");
	texto(250, 95,  userInfo[0]);
	texto(250, 150, "Constraseña");
	texto(250, 170, userInfo[1]);

	
	while (cont < 2){
		int x=250, y=75+(75*cont);
	  	char nombre[50];
	  	int i=0;
	  	nombre[i]='_'; // para que se vea el cursor
	  	nombre[i+1]='\0';
	  	bool sigue=true;
	  	color(NEGRO);
	  	texto(x,y+20,nombre);
	  	refresca();
	  	do{
			int t = tecla(); //funcion de miniwin lee un caracter
			if(t==NINGUNA){
			}
			else{
				if(t==RETURN){
		            nombre[i]='\0';
		            sigue=false;
		            std::string escribiste(nombre); 
		            userInfo[cont]=escribiste;
		            
				}else{
					if(t==IZQUIERDA){
						if(i>1)
			               	i--;
			            else
			            	i=0;
				  	}else{
						if(t==ESPACIO){
							nombre[i]=' ';
						}else{
				  			nombre[i]=t;	
						}
						i++;
					}	
					borra();		
					dibujaFondo(255, 91, 89);
					bAtras.dibujaBoton();
					
					texto(250, 75, "Usuario");
					texto(250, 95,  userInfo[0]);
					texto(250, 150, "Constraseña");
					texto(250, 170, userInfo[1]);



				    nombre[i]='_'; // para que se vea el cursor
					nombre[i+1]='\0';
					texto(x,y+20,nombre);
					refresca();
				}
			}
			raton(ratx,raty);
			if(raton_boton_izq()){
				if(bAtras.isDentro(ratx,raty)){
					bAtras.setPress(true);
					refresca();
					espera(300);
					bAtras.setPress(false);
					sigue=false;
					cont=2;
				}
			}
			espera(30);
		}while(sigue);
		cont++;
	}
	if (cont !=3){// valida si se salio del loop antes de llenar los campos
		int i=0;
		if (userInfo[0]==""){// valida si se ingreso algun usuario
			i=5;
		}
		while(i<5){
			if (userInfo[0]==users[i].usuario){// verifica si el usuario existe
				if(userInfo[1]==users[i].contra){// verifica si la contrasena es corecta
					activePlayer=i;// activa el jugador que ingreso para que sus estadisticas cambien si fuera el caso
					playMenu(); // te lleva  al menu para jugar
					
				}
				else{
					mensaje("La contraseña no es correcta");
				}
				i=5;
			}
			i++;
		}
		if (i==5){//sucede si no se encontro ningun usuario con el nombre que se ingreso
			mensaje("Este usuario no se encuntra de la base de datos");
		}
	}
}



