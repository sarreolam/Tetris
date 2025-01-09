
class Tetris { // clase tetris
	private : 
		std::string color;
		int posx;
		int posy;
		int lineas;
		int nivel;
		void impPiezas(int, int, int, int);
		void todo0();
		int sigPieza;
	public: 
		Tetris(int, int, int);
		void vista();
		void incrLineas();
		void incrNivel();
		void imprimirTetris();
		void imprimirTetris(int, int, int, int);
		int getNivel();
		int getLineas();
		void impSiguientePieza(int,int,int,int);
		int getSigPieza();
		void setSigPieza(int);
};

class Bloques { // clase para bloques
	private:
		int posx;
		int posy;
		int r;
		int g;
		int b;
		bool existe;
	public:
		Bloques(int,int);
		void setExiste(int);
		void dibujar(int , int);
		void getUp(int,int,int,bool);
		void getProps(int &,int &,int &,bool &);

		
};

Bloques *b1[21][12]; // se crea un arreglo bidimensional de bloques

//funciones y procedimiento fuera de las clases
void asignarTetris();
int piezas(int pieza, int &y, int &x, int &rot, int move, bool &giro, Tetris t1);


int Tetris::getLineas(){//get
	return lineas;
}

int Tetris::getSigPieza(){//get
	return sigPieza;
}

void Tetris::setSigPieza(int p){//set
	sigPieza=p;
}

Tetris::Tetris(int x, int y, int p){// constructor
	posx=x;
	posy=y;
	lineas=0;
	nivel=1;
	sigPieza = p;
	todo0(); // empiezas con un teris vacio
}
	
void Tetris::vista(){ // lo que se ve cuando juegas
	miniwin::color(BLANCO);
	rectangulo_lleno(posx-4,posy-4,posx+204,posy+404);
	rectangulo_lleno(posx+226,posy-4,posx+384,posy+129);
	rectangulo_lleno(posx+226,posy+146,posx+384,posy+279);
	
	color_rgb(76, 76, 76);
	rectangulo_lleno(posx+230,posy,posx+380,posy+125);
	rectangulo_lleno(posx+230,posy+150,posx+380,posy+275); 
	miniwin::color(NEGRO);
	rectangulo_lleno(posx-1,posy-1,posx+201,posy+401);
	rectangulo_lleno(posx+240,posy+30,posx+370,posy+55);
	rectangulo_lleno(posx+240,posy+85,posx+370,posy+110);
	rectangulo_lleno(posx+240,posy+185,posx+370,posy+265);
	
	miniwin::color(BLANCO);
	
	std::string str;
	std::stringstream ll, nn;
	
	ll<<lineas;
	ll>>str;
	texto(posx+240,posy+10, "Lineas:");
	texto(posx+245,posy+35,	str);
	
	nn<<nivel;
	nn>>str;
	texto(posx+240,posy+65, "Nivel:");
	texto(posx+245,posy+90, str);
	
	texto(posx+240,posy+160, "Siguiente: ");

	color_rgb(89, 92, 95);
	for (int x=1;x<10;x++){
		linea(posJuegox+(x*20),posJuegoy,posJuegox+(x*20),posJuegoy+400);
	}
	for (int x=1;x<20;x++){
		linea(posJuegox,posJuegoy+(x*20),posJuegox+200,posJuegoy+(x*20));
	}
	miniwin::color(BLANCO);
}

void Tetris::incrLineas(){//set
	lineas++;
	if(lineas%5==0){
		incrNivel();
	}
}

void Tetris::incrNivel(){//set
	nivel++;	
}

int Tetris::getNivel(){//get
	return nivel;
}

void Tetris::imprimirTetris(){// se dibuja el juego sin pieaza ni bloques
	borra();
	vista();
	impSiguientePieza(posx+295,posy+225,1,sigPieza);
    refresca();
    espera(50);
//    borra();
}

// se dibuja el juego con pieza y bloques
void Tetris::imprimirTetris(int x, int y, int rot, int pieza){
	borra();
	vista();
	impSiguientePieza(posx+295,posy+225,1,sigPieza);// se dibuja la siguiente pieza que va a salir
	impPiezas(x,y,rot,pieza);
	for (int i=0; i<20; i++){
      	for (int j=1; j<11; j++){
			b1[i][j]->dibujar(i,j);// dibuja los bloques que existen
      	}
    }
    //////Por metodo del juego aqui se ve el juego con puros 1 y 0/////////
    
    
//	miniwin::color(BLANCO);////////////////////////////////
//	for (int y=0; y<21; y++){
//    	for (int x=0; x<12; x++){
//    		std::string str;
//			std::stringstream ss;
//    		ss<<tetris[y][x];
//			ss>>str;
//			if (tetris[y][x]){
//        		texto(80+(x*20),50+(y*20),str);
//			}
//      	}
//
//    }////////////////////////////////
    refresca();
    espera(50);
}

void Tetris::impPiezas(int x,int y,int rot,int pieza){ // dibuja la pieza segun sea con su rotacion
	switch(pieza){
		case 1:
			FiguraJ(posx-20+(x*20),posy+(y*20),rot);
			break;
		case 2:
			FiguraL(posx-20+(x*20),posy+(y*20),rot);
			break;
		case 3:
			FiguraS(posx-20+(x*20),posy+(y*20),rot);
			break;
		case 4:
			FiguraZ(posx-20+(x*20),posy+(y*20),rot);
			break;
		case 5: 
			FiguraT(posx-20+(x*20),posy+(y*20),rot);
			break;
		case 6:
			FiguraO(posx-20+(x*20),posy+(y*20));;
			break;
		case 7: 
			FiguraI(posx-20+(x*20),posy+(y*20),rot);;
			break;	
	}	
}

void Tetris::impSiguientePieza(int x,int y,int rot,int pieza){// se dibuja la siguente pieza
	switch(pieza){
		case 1:
			FiguraJ(x,y,rot);
			break;
		case 2:
			FiguraL(x,y,rot);
			break;
		case 3:
			FiguraS(x,y,rot);
			break;
		case 4:
			FiguraZ(x,y,rot);
			break;
		case 5: 
			FiguraT(x,y,rot);
			break;
		case 6:
			FiguraO(x-10,y);
			break;
		case 7: 
			FiguraI(x-10,y-10,rot);
			break;	
	}	
}

void Tetris::todo0(){
	for (int y=0; y<20; y++){
		for (int x=1; x<11; x++){
			tetrisCompleto[y][x]=0;// se vacia tetris completo
		}
	}
	for (int x=0; x<11; x++){
    	tetris[20][x]=2;// suelo
	}
	for (int y=0; y<21; y++){
    	tetris[y][0]=2; // pared izq
	}
	for (int y=0; y<21; y++){
    	tetris[y][11]=2;// pared der
	}
}

Bloques::Bloques(int x, int y){ // constructor de bloques es su posision
	existe=false;
	posx=posJuegox-20+(x*20);
	posy=posJuegoy+(y*20);
	
}

void Bloques::setExiste(int pieza){
// si el bloque aun no existe se le asignan sus atributos con la pieza que estaba callendo
	if(!existe){
		switch(pieza){
		case 1:
			r=0;
			g=0;
			b=255;
			break;
		case 2:
			r=255;
			g=165;
			b=0;
			break;
		case 3:
			r=0;
			g=255;
			b=0;
			break;
		case 4:
			r=255;
			g=0;
			b=0;
			break;
		case 5: 
			r=147;
			g=112;
			b=219;
			break;
		case 6:
			r=255;
			g=255;
			b=0;
			break;
		case 7: 
			r=176;
			g=226;
			b=255;
			break;	
		}
		existe=true;
	}
		
}

void Bloques::dibujar(int x, int y){
	if(existe){ // si existe el bloque se pinta con sus atributos, osea colores 
		color_rgb(r,g,b);
		rectangulo_lleno(posx,posy,posx+20,posy+20);
		color(NEGRO);
		rectangulo(posx,posy,posx+20,posy+20);
	}
}

void Bloques::getProps(int &rP, int &gP, int &bP, bool &ex){
// como es paso por referencia agarras los valores del bloque
	rP=r;
	gP=g;
	bP=b;
	ex=existe;
}

void Bloques::getUp(int r1, int g1, int b1, bool ex){
	// aqui intentas poner los valores del bloque de arriba,
	// si el bloque de arriba existe cambian sus valores para el color
	if(ex){
		r=r1;
		g=g1;
		b=b1;
	}else{// si no existe hace que este bloque ya no exista
		existe=false;
	}
}

void asignarTetris(){// esta funcion se repite cada que la pieza cambia en algun sentido
	for (int y=0; y<20; y++){
      	for (int x=1; x<11; x++){
			tetris[y][x]=0;// todo tetris vale 0
      	}
    }
	for (int y=0; y<20; y++){
		for (int x=1; x<11; x++){
			// tetris vale lo que vale tetris completo sin la pieza que esta callendo
			tetris[y][x]=tetrisCompleto[y][x];
			// luego la pieza existe
		}
	}
}
	
int piezas(int pieza, int &y, int &x, int &rot, int move, bool &giro, Tetris t1){ // evalua la pieza que esta callendo en terminos de 0 y 1
	asignarTetris();
	int regresa;
	switch(pieza){
		case 1:
			regresa=(JPiece(y,x,rot,move,giro));
			break;
		case 2:
			regresa=(LPiece(y,x,rot,move,giro));
			break;
		case 3:
			regresa=(SPiece(y,x,rot,move,giro));
			break;
		case 4:
			regresa=(ZPiece(y,x,rot,move,giro));
			break;
		case 5: 
			regresa=(TPiece(y,x,rot,move,giro));
			break;
		case 6:
			regresa=(OPiece(y,x,move));
			break;
		case 7: 
			regresa=(IPiece(y,x,rot,move,giro));
			break;
		
	}
	
	t1.imprimirTetris(x,y,rot,pieza);
	return regresa; //  si la pieza aun se puede mover regresa un 1, si no un 0
}

