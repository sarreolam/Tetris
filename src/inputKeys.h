int inputKey(int pieza, int &y, int &x, int &rot, int move, bool &giro, Tetris t1){
	for(int i=0;i<10;i++){ // tienes oportunidad para mover la pieza como tu quieras 10 veces
		
		int t = tecla();
		if (t==NINGUNA){
		}
		else{
			if(t==IZQUIERDA){
				x--;
	         	move = 2;
				piezas(pieza, y, x, rot, move, giro, t1); //mueve la pieza a la izq si es que puede

			}
			else{
				if(t==DERECHA){
					x++;
		            move = 1;
					piezas(pieza, y, x, rot, move, giro, t1); //mueve la pieza a la der si es que puede
	
				}
				else{
					if(t==ARRIBA){
						if(rot==4){//si es igual a 4 pasa a 1, si no solo aumenta
							rot=1;
						}else{
							rot++;
						}
						giro=true;
						piezas(pieza, y, x, rot, move, giro, t1);//rota la pieza si es que puede
					}
					else{
						if(t==ESPACIO){
							move=0;
							bool sigue=true;
							while(sigue){
								y++;
								if(!piezas(pieza, y, x, rot, move, giro, t1)){//hace que la pieza llegue hasta abajo inmediatamente
									sigue = false;
								}
							}
							return 0;
						}else{
							if(t==ABAJO){ //mata inmediatamente esta funcion para que simplemente baje la pieza
								return 0;
							}else{
								if(t==ESCAPE){// mata inmediatamente esta funcion y regresa un 1 para dejar de jugar
									mensaje("Has dejado de jugar");
									return 1;
								}else{
								}
							}
						}
					}
				}
			}
		}
		espera(100/t1.getNivel());// el tiempo de espera entre cada movimiento de pieza que tienes, mientras mayor el nivel mas rapido se mueve
		// como esta funcion se repite 10 veces al principio tienes un minuto
	}
	
}

