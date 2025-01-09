int tetris[21][12]; // arreglo bidimensional donde se juega
int tetrisCompleto[21][12]; // arreglo bidimensional donde estan las piezas ya caidas 

int posJuegox=100;
int posJuegoy=50; // posisiones en donde esta el juego

int sx=600, sy=500;// tammano de la pantalla


void dibujaFondo(int r, int g, int b){ // funcion para pintar el fondo en los menus
	color_rgb(r,g,b);
	rectangulo_lleno(0,0,sx,sy);
}
     
/*
Los que dicen "piece" son para evaluar la pieza con puro 1 y 0 en el arreglo bidimensional
regresan 0 o 1 para indicar la pieza continua callendo o no


los que dicen "figura" es para dibujar la pieza en su respectiva posision
*/



int JPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1){
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x-1]==0&&tetris[y][x+1]==0){
			}else{
				rot=4;
			}
		}else{
			if(rot==2){
				if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y-1][x+1]==0&&tetris[y+1][x]==0){
				}else{
					rot=1;
				}
			}else{
				if(rot==3){
					if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x+1]==0&&tetris[y][x-1]==0){
					}else{
						rot=2;
					}
				}else{
					if(rot==4){
						if(tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y+1][x-1]==0&&tetris[y-1][x]==0){
						}else{
							rot=3;
						}
					}
				}
			}
		}
		giro=false;	
	}
  	switch(rot){
	  	case 1:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x-1]==0&&tetris[y][x+1]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
					
				}
				if(move == 1){
					x--;
					regresa=1;										

				}
				if (move == 2){
					x++;
					regresa =1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y-1][x-1]=1;
		  	tetris[y][x+1]=1;
		  	return regresa;
		case 2:
			if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y-1][x+1]==0&&tetris[y+1][x]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
			tetris[y-1][x+1]=1;
			tetris[y+1][x]=1;
			return regresa;
		case 3:
			if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x+1]==0&&tetris[y][x-1]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;					
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x+1]=1;
			tetris[y+1][x+1]=1;
			tetris[y][x-1]=1;
			return regresa;
		case 4:
			if (tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y+1][x-1]==0&&tetris[y-1][x]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y+1][x]=1;
			tetris[y+1][x-1]=1;
			tetris[y-1][x]=1;
			return regresa;
  	}
}

int LPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1){
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y-1][x+1]==0){
			}else{
				rot=4;
			}
		}else{
			if(rot==2){
				if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y+1][x]==0&&tetris[y+1][x+1]==0){
				}else{
					rot=1;
				}
			}else{
				if(rot==3){
					if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y][x-1]==0&&tetris[y+1][x-1]==0){
					}else{
						rot=2;
					}
				}else{
					if(rot==4){
						if(tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y-1][x]==0&&tetris[y-1][x-1]==0){
						}else{
							rot=3;
						}
					}
				}
			}
		}
		giro=false;	
	}
	switch(rot){
		case 1:
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y-1][x+1]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
			tetris[y][x+1]=1;
			tetris[y-1][x+1]=1;
			return regresa;
		case 2:
			if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y+1][x]==0&&tetris[y+1][x+1]==0){
				regresa =1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
			tetris[y+1][x]=1;
			tetris[y+1][x+1]=1;
			return regresa;
		case 3:
			if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y][x-1]==0&&tetris[y+1][x-1]==0){
				regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x+1]=1;
			tetris[y][x-1]=1;
			tetris[y+1][x-1]=1;
			return regresa;
		case 4:
			if(tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y-1][x]==0&&tetris[y-1][x-1]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y+1][x]=1;
			tetris[y-1][x]=1;
			tetris[y-1][x-1]=1;
			return regresa;	
	}
}

int SPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1){
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x]==0&&tetris[y-1][x+1]==0){
			}else{
				rot=4;
			}
		}else{
			if(rot==2){
				if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x+1]==0){
				}else{
					rot=1;
				}
			}else{
				if(rot==3){
					if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x]==0&&tetris[y+1][x-1]==0){
					}else{
						rot=2;
					}
				}else{
					if(rot==4){
						if(tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x-1]==0){
						}else{
							rot=3;
						}
					}
				}
			}
		}
		giro=false;	
	}
	switch (rot){
		case 1:
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x]==0&&tetris[y-1][x+1]==0){
				regresa =1;
			}else{
				if (move==0){
					y--;
					regresa =0;
				}
				if (move==1){
					x--;
					regresa=1;
				}
				if (move==2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
			tetris[y-1][x]=1;
			tetris[y-1][x+1]=1;
			return regresa;
		case 2:
			if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x+1]==0){
				regresa =1;
			}else{
				if (move==0){
					y--;
					regresa =0;
				}
				if (move==1){
					x--;
					regresa=1;
				}
				if (move==2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
			tetris[y][x+1]=1;
			tetris[y+1][x+1]=1;
			return regresa;
		case 3:
			if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y+1][x]==0&&tetris[y+1][x-1]==0){
				regresa =1;
			}else{
				if (move==0){
					y--;
					regresa =0;
				}
				if (move==1){
					x--;
					regresa=1;
				}
				if (move==2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x+1]=1;
			tetris[y+1][x]=1;
			tetris[y+1][x-1]=1;
			return regresa;
		case 4:
			if (tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y][x-1]==0&&tetris[y-1][x-1]==0){
				regresa =1;
			}else{
				if (move==0){
					y--;
					regresa =0;
				}
				if (move==1){
					x--;
					regresa=1;
				}
				if (move==2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y+1][x]=1;
			tetris[y][x-1]=1;
			tetris[y-1][x-1]=1;
			return regresa;
	}
}

int ZPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1){
			if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x-1]==0&&tetris[y-1][x]==0){
			}else{
				rot=4;
			}
		}else{
			if(rot==2){
				if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x+1]==0&&tetris[y+1][x]==0){
				}else{
					rot=1;
				}
			}else{
				if(rot==3){
					if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x]==0&&tetris[y+1][x+1]==0){
					}else{
						rot=2;
					}
				}else{
					if(rot==4){
						if(tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x-1]==0){
						}else{
							rot=3;
						}
					}
				}
			}
		}
		giro=false;	
	}
  	switch(rot){
	  	case 1:
	  		if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x-1]==0&&tetris[y-1][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x+1]=1;
		  	tetris[y-1][x-1]=1;
		  	tetris[y-1][x]=1;
		  	return regresa;
		case 2:
			if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x+1]==0&&tetris[y+1][x]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x+1]=1;
			tetris[y-1][x+1]=1;
			tetris[y+1][x]=1;
			return regresa;
		case 3:
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x]==0&&tetris[y+1][x+1]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;					
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
			tetris[y+1][x]=1;
			tetris[y+1][x+1]=1;
			return regresa;
		case 4:
			if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x-1]==0){
				regresa=1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if(move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
			tetris[y][x-1]=1;
			tetris[y+1][x-1]=1;
			return regresa;
  	}
}

int TPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1){
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y-1][x]==0){
			}else{
				rot=4;
			}
		}else{
			if(rot==2){
				if (tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x]==0){
				}else{
					rot=1;
				}
			}else{
				if(rot==3){
					if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y+1][x]==0){
					}else{
						rot=2;
					}
				}else{
					if(rot==4){
						if(tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x]==0&&tetris[y-1][x]==0){
						}else{
							rot=3;
						}
					}
				}
			}
		}
		giro=false;	
	}
	switch(rot){
	  	case 1:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y-1][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y][x+1]=1;
		  	tetris[y-1][x]=1;
		  	return regresa;
		case 2:
	  		if (tetris[y][x]==0&&tetris[y+1][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y+1][x]=1;
		  	tetris[y][x+1]=1;
		  	tetris[y-1][x]=1;
		  	return regresa;
		case 3:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y+1][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y][x+1]=1;
		  	tetris[y+1][x]=1;
		  	return regresa;
		case 4:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y+1][x]==0&&tetris[y-1][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y+1][x]=1;
		  	tetris[y-1][x]=1;
		  	return regresa;
	}
}

int OPiece(int &y, int &x, int move){
	int regresa;
	if (tetris[y][x]==0&&tetris[y][x+1]==0&&tetris[y-1][x]==0&&tetris[y-1][x+1]==0){
		regresa = 1;
	}else{
		if(move == 0){
			y--;
			regresa = 0;
		}
		if(move == 1){
			x--;
			regresa=1;
		}
		if (move == 2){
			x++;
			regresa=1;
		}
	}
	tetris[y][x]=1;
	tetris[y][x+1]=1;
  	tetris[y-1][x]=1;
  	tetris[y-1][x+1]=1;
  	return regresa;
}

int IPiece(int &y, int &x, int &rot, int move, bool &giro){
	int regresa;
	if(giro){
		if(rot==1||rot==3){
			if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y][x+2]==0){
			}else{
				rot=2;
			}
		}else{
			if(rot==2||rot==4){
				if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y+1][x]==0&&tetris[y+2][x]==0){
				}else{
					rot=1;
				}
			}
		}
		giro=false;	
	}
	switch(rot){
	  	case 1:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y][x+2]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y][x+1]=1;
		  	tetris[y][x+2]=1;
		  	return regresa;
		case 2:
	  		if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y+1][x]==0&&tetris[y+2][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
		  	tetris[y+1][x]=1;
		  	tetris[y+2][x]=1;
		  	return regresa;
		case 3:
	  		if (tetris[y][x]==0&&tetris[y][x-1]==0&&tetris[y][x+1]==0&&tetris[y][x+2]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y][x-1]=1;
		  	tetris[y][x+1]=1;
		  	tetris[y][x+2]=1;
		  	return regresa;
		case 4:
	  		if (tetris[y][x]==0&&tetris[y-1][x]==0&&tetris[y+1][x]==0&&tetris[y+2][x]==0){
		  		regresa = 1;
			}else{
				if(move == 0){
					y--;
					regresa = 0;
				}
				if(move == 1){
					x--;
					regresa=1;
				}
				if (move == 2){
					x++;
					regresa=1;
				}
			}
			tetris[y][x]=1;
			tetris[y-1][x]=1;
		  	tetris[y+1][x]=1;
		  	tetris[y+2][x]=1;
		  	return regresa;
	}
}


void FiguraT(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 

//  borra();
  int sizeX= 20;
  int sizeY = 20;
   
	
	switch(giro){
	case 1: // Dibujar T posicion 1(Invertida) (CUADRADOS)
		color_rgb(147, 112, 219); 
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
		//arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    

		break;
		
	case 2:	// Dibujar T posicion 2(Derecha) (CUADRADOS)
	
		color_rgb(147, 112, 219); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		//abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				

		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);    

	break;	
	
	  
	case 3: // Dibujar T posicion 3(Invertida) (CUADRADOS)
		
		color_rgb(147, 112, 219); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
			
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    

	break;	
	 
	case 4: // Dibujar T posicion 4(Izquierda) (CUADRADOS)
		 
		color_rgb(147, 112, 219); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		color_rgb(147, 112, 219); //arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		color_rgb(147, 112, 219); //abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
		color_rgb(147, 112, 219);//Izquierda
			rectangulo_lleno(x, y, x-sizeX, y+sizeY);	
				
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Izquierda
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY); 
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);    

	
	break;
	}
}

void FiguraO(int x,int y){ //un switch de la variable giro con cada una de las posiciones 
  int sizeX= 20;
  int sizeY = 20;	
//Cubo en única posicion
	
	color_rgb (255, 255, 0); 
	
	//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
	//arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);			
			
	//Derecha arriba
		rectangulo_lleno(x+sizeX, y-sizeY, x+2*sizeX, y); 
		
	//Derecha 
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
		
		
		
	//**********************  LINEAS  *********	
	color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
			//Lineas cuadrado Superior
			linea(x,y, x, y-sizeY);
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y); 
			 
			
			//Lineas cuadrado Derecho 
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
			//Lineas cuadrado Derecho arriba
			linea(x+sizeX, y-sizeY, x+2*sizeX, y-sizeY);
			linea(x+2*sizeX, y-sizeY, x+2*sizeX, y);
}

void FiguraI(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 
  int sizeX= 20;
  int sizeY = 20;
   
	
	switch(giro){
	case 2:
		// Dibujar I posicion 1(I) (CUADRADOS)
	
		color_rgb(176, 226, 255); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
								
		 //abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
				
		//mas abajo
			rectangulo_lleno(x, y+3*sizeY, x+sizeX, y+2*sizeY);
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
			
		//Lineas cuadrado Más abajo
			linea(x,y+3*sizeY, x, y+2*sizeY);
			linea(x, y+3*sizeY, x+sizeX, y+3*sizeY);
			linea(x+sizeX, y+3*sizeY, x+sizeX, y+2*sizeY);    
			
		break;
		
	case 1:	// Dibujar I posicion 2(----) (CUADRADOS)
	
		color_rgb(176, 226, 255); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);			
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);					
		 //,Mas derecha
			rectangulo_lleno(x+2*sizeX, y, x+3*sizeX, y+sizeY);	
				
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Más Drecho
			linea(x+2*sizeX, y, x+3*sizeX, y);
			linea(x+2*sizeX, y+sizeY, x+3*sizeX, y+sizeY);
			linea(x+3*sizeX, y, x+3*sizeX, y+sizeY); 
			   
		
	break;	
		case 4:
		// Dibujar I posicion 1(I) (CUADRADOS)
	
		color_rgb(176, 226, 255); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
								
		 //abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
				
		//mas abajo
			rectangulo_lleno(x, y+3*sizeY, x+sizeX, y+2*sizeY);
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
			
		//Lineas cuadrado Más abajo
			linea(x,y+3*sizeY, x, y+2*sizeY);
			linea(x, y+3*sizeY, x+sizeX, y+3*sizeY);
			linea(x+sizeX, y+3*sizeY, x+sizeX, y+2*sizeY);    
			
		break;
		
	case 3:	// Dibujar I posicion 2(----) (CUADRADOS)
	
		color_rgb(176, 226, 255); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);			
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);					
		 //,Mas derecha
			rectangulo_lleno(x+2*sizeX, y, x+3*sizeX, y+sizeY);	
				
		// Dibujar T posicion 1 (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Más Drecho
			linea(x+2*sizeX, y, x+3*sizeX, y);
			linea(x+2*sizeX, y+sizeY, x+3*sizeX, y+sizeY);
			linea(x+3*sizeX, y, x+3*sizeX, y+sizeY); 
			   
		
	break;	
	
	}
}

void FiguraS(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 

  int sizeX= 20;
  int sizeY = 20;
   
	
	switch(giro){
		
	case 1: 
	color_rgb (0, 255, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
		
	//ARRIBA		
	rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
	//IZQUIERDA
		rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
	//ARRIBA DERECHA
		rectangulo_lleno(x+sizeX, y, x+2*sizeX, y-sizeY);	

			
    //**************************** - LINEAS - ****************************
    
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
					
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);    
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    

		//Lineas cuadrado Derecho Arriba
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+2*sizeX, y-sizeY);	
	
	
			
	break;
		
	case 2:	
	
	color_rgb(0, 255, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);

	//Arriba 
		rectangulo_lleno(x, y-sizeY, x+sizeX, y);
		
	//Derecha	
		rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);
	
	//Derecha abajo
		rectangulo_lleno(x+sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);

	
    //**************************** - LINEAS - ****************************
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);

		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);

		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
		
		//Lineas cuadrado abajo Derecho
			linea(x+sizeX, y+sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+2*sizeX, y+2*sizeY);
			linea(x+2*sizeX, y+2*sizeY, x+2*sizeX, y+sizeY);
			
					
	break;	
	
	case 3:
		
		color_rgb(0, 255, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
		
	//Derecha	
		rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);
		
	//Abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
			
	//Izquierda abajo
		rectangulo_lleno(x-sizeX, y+sizeY, x, y+2*sizeY);
		
	//**************** - LINEAS - ************
	
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);	
	
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
			
		//Lineas cuadrado abajo Izquierda
			linea(x-sizeX, y+sizeY, x-sizeX, y+2*sizeY);
			linea(x-sizeX, y+2*sizeY, x, y+2*sizeY);
			linea(x, y+sizeY, x-sizeX, y+sizeY);	
		
		
		
	break;
	
	case 4:
		
		color_rgb(0, 255, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
		
	//abajo
		rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
	
	//IZQUIERDA
		rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
	//Izquierda arriba
		rectangulo_lleno(x, y-sizeY, x-sizeX, y);	
	
	//**************** - LINEAS - ************
	
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
		
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);			
			
		//Lineas cuadrado Izquierda arriba
			linea(x,y-sizeY, x-sizeX, y-sizeY);
			linea(x-sizeX, y-sizeY, x-sizeX, y);
			linea(x-sizeX, y, x, y);
			
		
	break;
	}
}

void FiguraJ(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 
  int sizeX= 20;
  int sizeY = 20;
   
	
	switch(giro){
	case 1: 
	
		color_rgb(0,0,255); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//Izquierda arriba
			rectangulo_lleno(x, y-sizeY, x-sizeX, y);
			
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Izquierda arriba
			linea(x,y-sizeY, x-sizeX, y-sizeY);
			linea(x-sizeX, y-sizeY, x-sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    
		break;
		
	case 2:	
	
		color_rgb(0,0,255); 
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		 //abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
		//arriba derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y-sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado superior derecho
			linea(x+sizeX, y-sizeY, x+2*sizeX, y-sizeY);
			linea(x+2*sizeX, y-sizeY, x+2*sizeX, y);
			linea(x+sizeX, y, x+2*sizeX, y);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);    
	break;	
	
	  
	case 3: // Dibujar (CUADRADOS)
		
		color_rgb(0,0,255); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
	//Derecha abajo
		rectangulo_lleno(x+sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);
			
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado abajo Derecho
			linea(x+sizeX, y+sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+2*sizeX, y+2*sizeY);
			linea(x+2*sizeX, y+2*sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    
	break;	
	 
	case 4: // Dibujar (CUADRADOS)
		 
		color_rgb(0,0,255);
		 //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		//abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
	//Izquierda abajo
		rectangulo_lleno(x-sizeX, y+sizeY, x, y+2*sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado abajo Izquierda
			linea(x-sizeX, y+sizeY, x-sizeX, y+2*sizeY);
			linea(x-sizeX, y+2*sizeY, x, y+2*sizeY);
			linea(x, y+sizeY, x-sizeX, y+sizeY); 
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);
		
	break;
	}
}

void FiguraL(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 
  int sizeX= 20;
  int sizeY = 20;
   
	
	switch(giro){
	case 1: 
	
		color_rgb(255,165,0); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//arriba derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y-sizeY);
			
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior derecho
			linea(x+sizeX, y-sizeY, x+2*sizeX, y-sizeY);
			linea(x+2*sizeX, y-sizeY, x+2*sizeX, y);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    
		break;
		
	case 2:	
	
		color_rgb(255,165,0); 
		
		//centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		 //abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
		//Derecha abajo
			rectangulo_lleno(x+sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado inferiorDerecho
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			linea(x+2*sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+2*sizeX, y+2*sizeY);
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);    
	break;	
	
	  
	case 3: // Dibujar (CUADRADOS)
		
		color_rgb(255,165,0); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		 //Abajo izquierda
			rectangulo_lleno(x-sizeX, y+sizeY, x, y+2*sizeY);
			
		//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
		
		//Derecha
			rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Abajo izquierda
			linea(x,y+sizeY, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x-sizeX, y+2*sizeY);
			linea(x-sizeX, y+2*sizeY, x, y+2*sizeY);
			
		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);    
	break;	
	 
	case 4: // Dibujar (CUADRADOS)
		 
		color_rgb(255,165,0); //centro
			rectangulo_lleno(x, y, x+sizeX, y+sizeY);
			
		//arriba
			rectangulo_lleno(x, y-sizeY, x+sizeX, y);
			
		//abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
		//Izquierda arriba
			rectangulo_lleno(x, y-sizeY, x-sizeX, y);	
				
		// Dibujar (LINEAS)
		
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);
			
		//Lineas cuadrado Izquierda arriba
			linea(x,y-sizeY, x-sizeX, y-sizeY);
			linea(x-sizeX, y-sizeY, x-sizeX, y);
			linea(x-sizeX, y, x, y); 
			
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY,x+sizeX, y+sizeY);
			
			
	break;
	}
}

void FiguraZ(int x,int y, int giro ){ //un switch de la variable giro con cada una de las posiciones 
  int sizeX= 20;
  int sizeY = 20;

	
	switch(giro){
		
	case 1: 
	color_rgb (255, 0, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
	// ARRIBA		
		rectangulo_lleno(x,y, x+sizeX, y-sizeY);
			
	//Arriba IZQUIERDA
		rectangulo_lleno(x-sizeX, y-sizeY, x, y);
		
	//Derecha
		rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);	

			
    //**************************** - LINEAS - ****************************
    
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
					
		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);    
			
		//Lineas cuadrado arriba Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y-sizeY);
			linea(x-sizeX, y-sizeY, x, y-sizeY);    

		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);	
	
	
			
	break;
		
	case 2:	
	
	color_rgb(255, 0, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);

	//Abajo
		rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);
		
	//Derecha	
		rectangulo_lleno(x+sizeX, y, x+2*sizeX, y+sizeY);
	
	//Derecha abajo -> Derecha Arriba
		rectangulo_lleno(x+sizeX, y-sizeY, x+2*sizeX, y);

	
    //**************************** - LINEAS - ****************************
    color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);

		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);

		//Lineas cuadrado Derecho
			linea(x+sizeX, y, x+2*sizeX, y);
			linea(x+2*sizeX, y, x+2*sizeX, y+sizeY);
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
		
			//Lineas cuadrado Derecho arriba
			linea(x+sizeX, y-sizeY, x+2*sizeX, y-sizeY);
			linea(x+2*sizeX, y-sizeY, x+2*sizeX, y);
			
					
	break;	
	
	case 3:
		
	color_rgb(255, 0, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
	
	//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);
			
	//Abajo
			rectangulo_lleno(x,y+sizeY, x+sizeX, y+2*sizeY);

	//Derecha abajo
			rectangulo_lleno(x+sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);
			
	// ************************* LINEAS ****************************
	
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);	
				
		//Lineas cuadrado Inferior
			linea(x,y+sizeY, x, y+2*sizeY);
			linea(x, y+2*sizeY, x+sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+sizeX, y+sizeY);

		//Lineas cuadrado inferiorDerecho
			linea(x+sizeX, y+sizeY, x+2*sizeX, y+sizeY);
			linea(x+2*sizeX, y+sizeY, x+2*sizeX, y+2*sizeY);
			linea(x+sizeX, y+2*sizeY, x+2*sizeX, y+2*sizeY);
					
		
	break;	
	
	case 4:
		
	color_rgb(255, 0, 0); 
	//Centro
		rectangulo_lleno(x, y, x+sizeX, y+sizeY);
		
	//Izquierda
			rectangulo_lleno(x-sizeX, y, x, y+sizeY);		
		
	// ARRIBA		
		rectangulo_lleno(x,y, x+sizeX, y-sizeY);
		
		 //Abajo izquierda
			rectangulo_lleno(x-sizeX, y+sizeY, x, y+2*sizeY);
					
	// ************************* LINEAS ****************************
	
		color(NEGRO);	
		//LINEAS cuadrado centro
			linea(x, y, x+sizeX, y);
			linea(x+sizeX, y, x+sizeX, y+sizeY);
			linea(x, y+sizeY, x+sizeX, y+sizeY);	
			linea(x, y, x, y+sizeY);
			
		//Lineas cuadrado Izquierdo
			linea(x,y, x-sizeX, y);
			linea(x-sizeX, y, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x, y+sizeY);

		//Lineas cuadrado superior
			linea(x, y-sizeY, x+sizeX, y-sizeY);
			linea(x+sizeX, y-sizeY, x+sizeX, y);
			linea(x, y-sizeY, x, y);		
	
			//Lineas cuadrado Abajo izquierda
			linea(x,y+sizeY, x-sizeX, y+sizeY);
			linea(x-sizeX, y+sizeY, x-sizeX, y+2*sizeY);
			linea(x-sizeX, y+2*sizeY, x, y+2*sizeY);
	break;
	}
}

