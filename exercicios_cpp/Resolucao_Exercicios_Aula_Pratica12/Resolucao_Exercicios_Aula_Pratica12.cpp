#include "graphics.h"
#include <cstdlib>
#include <ctime>

//10.1
void desenha_circulos()
{
	for(int i=1; i<=10; i++)
		circle(500/2, 500/2, i*50/2);
} 

//10.2
void mouse_click()
{
	int mx,my,cor;
	do {
		mx=mousex(); my=mousey(); cor=rand()%15+1;
		setcolor(cor); setfillstyle(1,cor);
		if (ismouseclick(513)) fillellipse(mx,my,10,10);
		if (ismouseclick(516)) bar(mx-10,my-10,mx+10,my+10);
		clearmouseclick(513); clearmouseclick(516);
		delay(1);		
	} while(!ismouseclick(519));
}

//10.3
void desenha_grelha(int n)
{
	for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++) {
        	setcolor(((i+j)%2)*15);	setfillstyle(1,((i+j)%2)*15);
			bar(i*500/n,j*500/n,i*500/n+500/n,j*500/n+500/n);
		}
}

double diffclock(clock_t clock1,clock_t clock2) { 
	return (double)(clock1-clock2)/CLOCKS_PER_SEC; 
}

//10.4
void mouse_game()
{
	clock_t begin=clock(), end; 
	int mx,my,px,py;
	for(int i=1; i<=10; i++) {
		px=rand()%460+20; py=rand()%460+20;
		setcolor(1); setfillstyle(1,1);
		fillellipse(px,py,20,20);
		do {
			mx=mousex(); my=mousey();
			delay(1);		
		} while((mx-px)*(mx-px)+(my-py)*(my-py)> 400);
		setcolor(0); setfillstyle(1,0);
		fillellipse(px,py,20,20);
	}
	end=clock();
	char st[30]; sprintf(st,"Time: %1.2f seg",diffclock(end,begin));
	setcolor(15); setbkcolor(0); outtextxy(200,240,st);
	delay(100);
}

#define amp 30

struct vert{
	int x, y;      //posicao x,y relativa a (xx,yy) do vertice
};
struct peca{
	int xx, yy;    //posicao absoluta
	int cor;       //cor da linha e enchimento (0-15)
	int nv;  	  //numero de vertices
	vert v[20];    //array de vertices da peca
};

void desenha_peca(peca p)
{
	setcolor(p.cor); setfillstyle(1,p.cor);
	moveto(p.xx*amp,p.yy*amp);
	for(int i=0; i<p.nv; i++) {
		lineto(p.xx*amp+p.v[i].x*amp, p.yy*amp+p.v[i].y*amp);
		//char st[5]; sprintf(st,"%d",i);	
		//outtextxy(p.xx*amp+p.v[i].x*amp, p.yy*amp+p.v[i].y*amp,st);
	}
	lineto(p.xx*amp,p.yy*amp);
	floodfill(p.xx*amp+1,p.yy*amp+1,p.cor);
}

int desenha_tetris()
{
  peca pe[5];
  int i;
  for(i=0;i<5;i++) {
  	  pe[i].cor=i+1;
  	  pe[i].xx=1; pe[i].yy=i*3+1; 
  	  pe[i].v[0].x=0; pe[i].v[0].y=0; 
  }
  pe[0].nv=4;
  pe[0].v[1].x=4; pe[0].v[1].y=0; pe[0].v[2].x=4; pe[0].v[2].y=1;
  pe[0].v[3].x=0; pe[0].v[3].y=1;
  pe[1].nv=4;
  pe[1].v[1].x=2; pe[1].v[1].y=0; pe[1].v[2].x=2; pe[1].v[2].y=2;
  pe[1].v[3].x=0; pe[1].v[3].y=2;  
  pe[2].nv=8;
  pe[2].v[1].x=3; pe[2].v[1].y=0; pe[2].v[2].x=3; pe[2].v[2].y=1;
  pe[2].v[3].x=2; pe[2].v[3].y=1; pe[2].v[4].x=2; pe[2].v[4].y=2;
  pe[2].v[5].x=1; pe[2].v[5].y=2; pe[2].v[6].x=1; pe[2].v[6].y=1;
  pe[2].v[7].x=0; pe[2].v[7].y=1; 
  pe[3].nv=6;
  pe[3].v[1].x=3; pe[3].v[1].y=0; pe[3].v[2].x=3; pe[3].v[2].y=2;
  pe[3].v[3].x=2; pe[3].v[3].y=2; pe[3].v[4].x=2; pe[3].v[4].y=1;
  pe[3].v[5].x=0; pe[3].v[5].y=1;  
  pe[4].nv=8;
  pe[4].v[1].x=2; pe[4].v[1].y=0; pe[4].v[2].x=2; pe[4].v[2].y=1;
  pe[4].v[3].x=3; pe[4].v[3].y=1; pe[4].v[4].x=3; pe[4].v[4].y=2;
  pe[4].v[5].x=1; pe[4].v[5].y=2; pe[4].v[6].x=1; pe[4].v[6].y=1;  
  pe[4].v[7].x=0; pe[4].v[7].y=1;  
  
  for(i=0;i<5;i++) 
  	desenha_peca(pe[i]); 
}

void mdir(int &d)
{
	if (ismouseclick(513)) d--; else if (ismouseclick(516)) d++; 
	if (d>3) d=0; else if (d<0) d=3;
	clearmouseclick(513); clearmouseclick(516);
}

void cdir(int &d, int x, int y, int dx[], int dy[])
{
	if (getpixel(x+dx[d]*2,y+dy[d]*2)!=15) return;  //nao vai haver colisao
	int dn = (rand()%2)*2-1;  //dn = dn +1 ou -1
	int dnovo=d+dn; if (dnovo>3) dnovo=0; else if (dnovo<0) dnovo=3;
	if (getpixel(x+dx[dnovo]*2,y+dy[dnovo]*2)==15) {
		dn=-dn; dnovo=d+dn; 
		if (dnovo>3) dnovo=0; else if (dnovo<0) dnovo=3;
	}
	d=dnovo;		
}

void snake_game()
{
	srand(time(NULL));
	rectangle(150,150,350,350);  //desenha area de jogo
	int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};  //direcoes 
	int hx=250, hy=250, tx=200, ty=250, dir=0; //cabeça, cauda e direção da snake
	int bx, by;
	setcolor(15); line(tx,ty,hx,hy); putpixel(hx,hy,1); //desenha snake inicial
	bool col=false, cat=true; int score=0;
	do {
		if (cat) {  //recoloca bonus em posição aleatoria
			bx=200+rand()%100; by=200+rand()%100;
			setcolor(8); setfillstyle(1,8);
			bar(bx-2,by-2,bx+2,by+2);
			cat=false; 
		}
		delay(1+100/(score/100+2));  //delay diminui com aumento do score
		mdir(dir);  //controlo usando o rato
		cdir(dir,hx,hy,dx,dy);  //correcao da direção pelo PC para não colidir
		if (getpixel(hx+dx[dir]*2,hy+dy[dir])==8) {  //recolhe bonus
			setcolor(0); setfillstyle(1,0); bar(bx-2,by-2,bx+2,by+2);
			cat=true; score+=100;
		}
		putpixel(hx,hy,15); putpixel(hx+dx[dir],hy+dy[dir],15);
		hx=hx+dx[dir]*2; hy=hy+dy[dir]*2;
		if (getpixel(hx,hy)==15) col=true;  //colide com parede ou corpo
		putpixel(hx,hy,1);
	} while(!col);
	setcolor(1); circle(hx,hy,4); 
}

int main(void)
{
  initwindow(509,511);
  
  cleardevice();
  snake_game();
  delay(1000);
  
  cleardevice();
  desenha_circulos();
  delay(1000); 
  
  cleardevice();
  mouse_click();
  
  cleardevice();
  desenha_grelha(5); delay(1000); 
  desenha_grelha(10); delay(1000); 
  desenha_grelha(50); delay(1000); 
  
  cleardevice();
  mouse_game();
  delay(1000); 

  cleardevice();
  desenha_tetris();
  delay(1000); 
  
  system("pause");
  
}

