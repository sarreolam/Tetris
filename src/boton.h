class boton {
	private:
		int posx, posy, sizex, sizey;
		int r, g, b;
		std::string txt;
		bool press;
	public:
		boton(int, int,int ,int ,std::string, int, int, int);
		bool isDentro(float, float);
		void dibujaBoton();
		void setPress(bool);
};

boton::boton(int x, int y, int zx, int zy, std::string tx, int r1, int g1, int b1){
	posx=x;
	posy=y;
	txt=tx;
	r=r1;
	g=g1;
	b=b1;
	sizex=zx;
	sizey=zy;
	press=false;
}

void boton::dibujaBoton(){
	int marx=10, mary=10;
	color_rgb(r,g,b);
	rectangulo_lleno(posx,posy,posx+sizex,posy+sizey);
	color((press==true)?NEGRO:BLANCO);
	linea(posx,posy,posx+sizex,posy);
	linea(posx+sizex,posy,posx+sizex,posy+sizey);
	color((press==true)?BLANCO:NEGRO);
	linea(posx,posy+sizey,posx+sizex,posy+sizey);
	linea(posx,posy,posx,posy+sizey);
	texto(posx+marx, posy+mary,txt);	
}

bool boton::isDentro(float x, float y){
	if (posx<x && x<posx+sizex&& posy<y && y<posy+sizey){
		return true;
	}
	return false;
}
void boton::setPress(bool p){
	press=p;
	dibujaBoton();
}










