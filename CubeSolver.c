#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<windows.h>
int i,j,k,side,pairs;
char cube[6][3][3],cube1[6][3][3],temp[3],movesdb[19][15]={"Right up","Right Down","Left up","Left Down","V-Middle Up","V-Middle Down","Top Right","Top Left","Bottom Right","Bottom Left","H-Middle Right","H-Middle Left","Front Right","Front Left","Back Right","Back Left","B-Middle Right","B-Middle Left"};
int s=1,b[100],a[100],bi=1,m=0,n=18,bj,nofmv=0;
long int xiter,yiter,unibox=1,unix=10,uniy=6;
int xy(int x,int y)
{
	COORD san={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),san);
}
long int mtrxmvmnt(int n,char **chr)
{ 
	long int yremvl=n*2,xremvl=n*4,box=unibox,x=unix,y=uniy,xf,yf;
	xf=10;yf=6;
	int mtrx()
	{
	int im=0,t=0;
	xy(5,5);
	printf("\t%c",218);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",450);
	}
	printf("%c",191);
	while(t<n)
	{
	printf("\n\t%c",179);
	for(im=0;im<n;im++)
	{
		printf(" %c %c",chr[t][im],179);
	}
	if(t<n-1)
	{
	printf("\n\t%c",195);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",197);
	}
	printf("%c",180);
	}
	t++;
	}
	printf("\n\t%c",192);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",193);
	}
	printf("%c",217);
	}
	mtrx();
	while(1)
	{	
		long int d;
		xy(x,y);
		d=retarr();
		if(d/1000!=0){
			d/=1000;
			switch(d){	
			case 72:{
				box=((box-1+(n-1)*n)%(n*n))+1;
				yiter-=2;
				y=((yiter)%yremvl)+yf;
				break;
				}
			case 75:{
				box=((box+n-2)%n)+1+((box-1)/n)*n;
				xiter-=4;
				x=((xiter)%xremvl)+xf;
				break;
			}
			case 77:{
				box=(box%n)+1+((box-1)/n)*n;
				xiter+=4;
				x=((xiter)%xremvl)+xf;
				break;
			}
			case 80:{
				box=((box+n-1)%(n*n))+1;
				yiter+=2;
				y=((yiter)%yremvl)+yf;
				break;
			}
		}
	}
	else
		{
			d%=1000;
			unibox=box;
			unix=x;
			uniy=y;
			box=box*1000;
			box=box+d;
			return box;
		}
	}
}

char** mtrxassgn(long int boxsize)
{
	char **a;
	long long int i;
	a=(char **)malloc(boxsize*sizeof(char *));
	for(i=0;i<boxsize;i++)
		a[i]=(char *)malloc(boxsize*sizeof(char));
		
	long int boxes=boxsize*boxsize;
	for(i=1;i<=boxes;i++)
	{
		a[(i-1)/boxsize][(i-1)%boxsize]=' ';
	}
	return a;
}
retarr()
{
		char d=0,c;
		long int m;
		c=getch();
		if(c==-32){
		d=getch();
		}
		if(d!=0)
			{c=6;}
		m=(d*1000)+c;
		return m;
}
char** boxfill(char** a,long int box,int boxsize)
{
	int b=box/1000,val=box%1000;
	a[(b-1)/boxsize][(b-1)%boxsize]=val;
	return a;
}

int matrixADD(int n,char chr[4][4])
{
	int im=0,t=0;
	printf("\t%c",218);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",450);
	}
	printf("%c",191);
	while(t<n)
	{
	printf("\n\t%c",179);
	for(im=0;im<n;im++)
	{
		printf(" %c %c",chr[t][im],179);
	}
	if(t<n-1)
	{
	printf("\n\t%c",195);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",197);
	}
	printf("%c",180);
	}
	t++;
	}
	printf("\n\t%c",192);
	for(im=0;im<n;im++)
	{
	printf("%c%c%c",196,196,196);
	if(im<n-1)
		printf("%c",193);
	}
	printf("%c",217);
}

main()
{		
	system("color 80");
	for(i=0;i<6;i++)
	{
		char **a;
		long int x;
		printf("\t\t*****  Cubo Solver 2.0  *****\n\n");
		printf(" Colors of side %d\n\n",i+1);
		xiter=480;yiter=480;
		unibox=1;unix=10;uniy=6;
		a=mtrxassgn(3);
		while((x=mtrxmvmnt(3,a))%1000!=13)
		{
			a=boxfill(a,x,3);
		}
		printf("\n\n\n\n\n\n");
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				cube1[i][j][k]=a[j][k];
			}
			printf("\n");
		}
		system("cls");
	}
		printf("\t\t*****  Cubo Solver 2.0  *****\n\n");
	printf("\n Side to solve :");
	scanf("%d",&side);
	for(pairs=1;pairs<=200;pairs++)
	{
		if(side==9)
			{break;
			}
		s=1,bi=1,m=0,n=18,bj,nofmv=0;
		strcpy(cube,cube1);
		printf(" Started %d pairs\n",pairs);	
		Brain(side-1);
	}
san:
{
	char mtr[4][4];
	printf("\n Side to display :");
	scanf("%d",&side);
	if(side<1||side>6){
		printf("\n\tInvalid side\n");
		goto san;
	}
	
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				mtr[j][k]=cube1[side-1][j][k];
			}
		}
		
	matrixADD(3,mtr);
}
	goto san;
}

ru()
{
	temp[0]=cube[0][0][2];
	temp[1]=cube[0][1][2];
	temp[2]=cube[0][2][2];
	cube[0][0][2]=cube[3][0][2];
	cube[0][1][2]=cube[3][1][2];
	cube[0][2][2]=cube[3][2][2];
	cube[3][0][2]=cube[2][0][2];
	cube[3][1][2]=cube[2][1][2];
	cube[3][2][2]=cube[2][2][2];
	cube[2][0][2]=cube[1][0][2];
	cube[2][1][2]=cube[1][1][2];
	cube[2][2][2]=cube[1][2][2];
	cube[1][0][2]=temp[0];
	cube[1][1][2]=temp[1];
	cube[1][2][2]=temp[2];
	temp[0]=cube[5][0][0];
	temp[1]=cube[5][0][1];
	temp[2]=cube[5][0][2];
	cube[5][0][0]=cube[5][2][0];
	cube[5][0][1]=cube[5][1][0];
	cube[5][1][0]=cube[5][2][1];
	cube[5][2][0]=cube[5][2][2];
	cube[5][2][1]=cube[5][1][2];
	cube[5][0][2]=temp[0];
	cube[5][1][2]=temp[1];
	cube[5][2][2]=temp[2];
}
rd()
{
	temp[0]=cube[0][0][2];
	temp[1]=cube[0][1][2];
	temp[2]=cube[0][2][2];
	cube[0][0][2]=cube[1][0][2];
	cube[0][1][2]=cube[1][1][2];
	cube[0][2][2]=cube[1][2][2];
	cube[1][0][2]=cube[2][0][2];
	cube[1][1][2]=cube[2][1][2];
	cube[1][2][2]=cube[2][2][2];
	cube[2][0][2]=cube[3][0][2];
	cube[2][1][2]=cube[3][1][2];
	cube[2][2][2]=cube[3][2][2];
	cube[3][0][2]=temp[0];
	cube[3][1][2]=temp[1];
	cube[3][2][2]=temp[2];	
	temp[0]=cube[5][0][0];
	temp[1]=cube[5][1][0];
	temp[2]=cube[5][2][0];
	cube[5][0][0]=cube[5][0][2];
	cube[5][1][0]=cube[5][0][1];
	cube[5][0][1]=cube[5][1][2];
	cube[5][0][2]=cube[5][2][2];
	cube[5][1][2]=cube[5][2][1];
	cube[5][2][0]=temp[0];
	cube[5][2][1]=temp[1];
	cube[5][2][2]=temp[2];
}
lu()
{
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][1][0];
	temp[2]=cube[0][2][0];
	cube[0][0][0]=cube[3][0][0];
	cube[0][1][0]=cube[3][1][0];
	cube[0][2][0]=cube[3][2][0];
	cube[3][0][0]=cube[2][0][0];
	cube[3][1][0]=cube[2][1][0];
	cube[3][2][0]=cube[2][2][0];
	cube[2][0][0]=cube[1][0][0];
	cube[2][1][0]=cube[1][1][0];
	cube[2][2][0]=cube[1][2][0];
	cube[1][0][0]=temp[0];
	cube[1][1][0]=temp[1];
	cube[1][2][0]=temp[2];
	temp[0]=cube[4][0][0];
	temp[1]=cube[4][1][0];
	temp[2]=cube[4][2][0];
	cube[4][0][0]=cube[4][0][2];
	cube[4][1][0]=cube[4][0][1];
	cube[4][0][1]=cube[4][1][2];
	cube[4][0][2]=cube[4][2][2];
	cube[4][1][2]=cube[4][2][1];
	cube[4][2][0]=temp[0];
	cube[4][2][1]=temp[1];
	cube[4][2][2]=temp[2];
}
ld()
{
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][1][0];
	temp[2]=cube[0][2][0];
	cube[0][0][0]=cube[1][0][0];
	cube[0][1][0]=cube[1][1][0];
	cube[0][2][0]=cube[1][2][0];
	cube[1][0][0]=cube[2][0][0];
	cube[1][1][0]=cube[2][1][0];
	cube[1][2][0]=cube[2][2][0];
	cube[2][0][0]=cube[3][0][0];
	cube[2][1][0]=cube[3][1][0];
	cube[2][2][0]=cube[3][2][0];
	cube[3][0][0]=temp[0];
	cube[3][1][0]=temp[1];
	cube[3][2][0]=temp[2];	
	temp[0]=cube[4][0][0];
	temp[1]=cube[4][0][1];
	temp[2]=cube[4][0][2];
	cube[4][0][0]=cube[4][2][0];
	cube[4][0][1]=cube[4][1][0];
	cube[4][1][0]=cube[4][2][1];
	cube[4][2][0]=cube[4][2][2];
	cube[4][2][1]=cube[4][1][2];
	cube[4][0][2]=temp[0];
	cube[4][1][2]=temp[1];
	cube[4][2][2]=temp[2];
}
tl()
{
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][0][1];
	temp[2]=cube[0][0][2];
	cube[0][0][0]=cube[5][0][0];
	cube[0][0][1]=cube[5][0][1];
	cube[0][0][2]=cube[5][0][2];
	cube[5][0][0]=cube[2][2][2];
	cube[5][0][1]=cube[2][2][1];
	cube[5][0][2]=cube[2][2][0];
	cube[2][2][2]=cube[4][0][0];
	cube[2][2][1]=cube[4][0][1];
	cube[2][2][0]=cube[4][0][2];
	cube[4][0][0]=temp[0];
	cube[4][0][1]=temp[1];
	cube[4][0][2]=temp[2];
	temp[0]=cube[1][0][0];
	temp[1]=cube[1][0][1];
	temp[2]=cube[1][0][2];
	cube[1][0][0]=cube[1][2][0];
	cube[1][0][1]=cube[1][1][0];
	cube[1][1][0]=cube[1][2][1];
	cube[1][2][0]=cube[1][2][2];
	cube[1][2][1]=cube[1][1][2];
	cube[1][0][2]=temp[0];
	cube[1][1][2]=temp[1];
	cube[1][2][2]=temp[2];
}
tr()
{
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][0][1];
	temp[2]=cube[0][0][2];
	cube[0][0][0]=cube[4][0][0];
	cube[0][0][1]=cube[4][0][1];
	cube[0][0][2]=cube[4][0][2];
	cube[4][0][0]=cube[2][2][2];
	cube[4][0][1]=cube[2][2][1];
	cube[4][0][2]=cube[2][2][0];
	cube[2][2][2]=cube[5][0][0];
	cube[2][2][1]=cube[5][0][1];
	cube[2][2][0]=cube[5][0][2];
	cube[5][0][0]=temp[0];
	cube[5][0][1]=temp[1];
	cube[5][0][2]=temp[2];	
	temp[0]=cube[1][0][0];
	temp[1]=cube[1][1][0];
	temp[2]=cube[1][2][0];
	cube[1][0][0]=cube[1][0][2];
	cube[1][1][0]=cube[1][0][1];
	cube[1][0][1]=cube[1][1][2];
	cube[1][0][2]=cube[1][2][2];
	cube[1][1][2]=cube[1][2][1];
	cube[1][2][0]=temp[0];
	cube[1][2][1]=temp[1];
	cube[1][2][2]=temp[2];
}
bl()
{
	temp[0]=cube[0][2][0];
	temp[1]=cube[0][2][1];
	temp[2]=cube[0][2][2];
	cube[0][2][0]=cube[5][2][0];
	cube[0][2][1]=cube[5][2][1];
	cube[0][2][2]=cube[5][2][2];
	cube[5][2][0]=cube[2][0][2];
	cube[5][2][1]=cube[2][0][1];
	cube[5][2][2]=cube[2][0][0];
	cube[2][0][2]=cube[4][2][0];
	cube[2][0][1]=cube[4][2][1];
	cube[2][0][0]=cube[4][2][2];
	cube[4][2][0]=temp[0];
	cube[4][2][1]=temp[1];
	cube[4][2][2]=temp[2];
	temp[0]=cube[3][0][0];
	temp[1]=cube[3][1][0];
	temp[2]=cube[3][2][0];
	cube[3][0][0]=cube[3][0][2];
	cube[3][1][0]=cube[3][0][1];
	cube[3][0][1]=cube[3][1][2];
	cube[3][0][2]=cube[3][2][2];
	cube[3][1][2]=cube[3][2][1];
	cube[3][2][0]=temp[0];
	cube[3][2][1]=temp[1];
	cube[3][2][2]=temp[2];
}
br()
{
	temp[0]=cube[0][2][0];
	temp[1]=cube[0][2][1];
	temp[2]=cube[0][2][2];
	cube[0][2][0]=cube[4][2][0];
	cube[0][2][1]=cube[4][2][1];
	cube[0][2][2]=cube[4][2][2];
	cube[4][2][0]=cube[2][0][2];
	cube[4][2][1]=cube[2][0][1];
	cube[4][2][2]=cube[2][0][0];
	cube[2][0][2]=cube[5][2][0];
	cube[2][0][1]=cube[5][2][1];
	cube[2][0][0]=cube[5][2][2];
	cube[5][2][0]=temp[0];
	cube[5][2][1]=temp[1];
	cube[5][2][2]=temp[2];	
	temp[0]=cube[3][0][0];
	temp[1]=cube[3][0][1];
	temp[2]=cube[3][0][2];
	cube[3][0][0]=cube[3][2][0];
	cube[3][0][1]=cube[3][1][0];
	cube[3][1][0]=cube[3][2][1];
	cube[3][2][0]=cube[3][2][2];
	cube[3][2][1]=cube[3][1][2];
	cube[3][0][2]=temp[0];
	cube[3][1][2]=temp[1];
	cube[3][2][2]=temp[2];
}
fl()
{
	temp[0]=cube[1][2][0];
	temp[1]=cube[1][2][1];
	temp[2]=cube[1][2][2];
	cube[1][2][0]=cube[5][0][0];
	cube[1][2][1]=cube[5][1][0];
	cube[1][2][2]=cube[5][2][0];
	cube[5][0][0]=cube[3][0][2];
	cube[5][1][0]=cube[3][0][1];
	cube[5][2][0]=cube[3][0][0];
	cube[3][0][2]=cube[4][2][2];
	cube[3][0][1]=cube[4][1][2];
	cube[3][0][0]=cube[4][0][2];
	cube[4][2][2]=temp[0];
	cube[4][1][2]=temp[1];
	cube[4][0][2]=temp[2];
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][1][0];
	temp[2]=cube[0][2][0];
	cube[0][0][0]=cube[0][0][2];
	cube[0][1][0]=cube[0][0][1];
	cube[0][0][1]=cube[0][1][2];
	cube[0][0][2]=cube[0][2][2];
	cube[0][1][2]=cube[0][2][1];
	cube[0][2][0]=temp[0];
	cube[0][2][1]=temp[1];
	cube[0][2][2]=temp[2];
}
fr()
{
	temp[0]=cube[1][2][0];
	temp[1]=cube[1][2][1];
	temp[2]=cube[1][2][2];
	cube[1][2][0]=cube[4][2][2];
	cube[1][2][1]=cube[4][1][2];
	cube[1][2][2]=cube[4][0][2];
	cube[4][2][2]=cube[3][0][2];
	cube[4][1][2]=cube[3][0][1];
	cube[4][0][2]=cube[3][0][0];
	cube[3][0][2]=cube[5][0][0];
	cube[3][0][1]=cube[5][1][0];
	cube[3][0][0]=cube[5][2][0];
	cube[5][0][0]=temp[0];
	cube[5][1][0]=temp[1];
	cube[5][2][0]=temp[2];
	temp[0]=cube[0][0][0];
	temp[1]=cube[0][0][1];
	temp[2]=cube[0][0][2];
	cube[0][0][0]=cube[0][2][0];
	cube[0][0][1]=cube[0][1][0];
	cube[0][1][0]=cube[0][2][1];
	cube[0][2][0]=cube[0][2][2];
	cube[0][2][1]=cube[0][1][2];
	cube[0][0][2]=temp[0];
	cube[0][1][2]=temp[1];
	cube[0][2][2]=temp[2];
}
bal()
{
	temp[0]=cube[1][0][0];
	temp[1]=cube[1][0][1];
	temp[2]=cube[1][0][2];
	cube[1][0][0]=cube[5][0][2];
	cube[1][0][1]=cube[5][1][2];
	cube[1][0][2]=cube[5][2][2];
	cube[5][0][2]=cube[3][2][2];
	cube[5][1][2]=cube[3][2][1];
	cube[5][2][2]=cube[3][2][0];
	cube[3][2][2]=cube[4][2][0];
	cube[3][2][1]=cube[4][1][0];
	cube[3][2][0]=cube[4][0][0];
	cube[4][2][0]=temp[0];
	cube[4][1][0]=temp[1];
	cube[4][0][0]=temp[2];
	temp[0]=cube[2][0][0];
	temp[1]=cube[2][0][1];
	temp[2]=cube[2][0][2];
	cube[2][0][0]=cube[2][2][0];
	cube[2][0][1]=cube[2][1][0];
	cube[2][1][0]=cube[2][2][1];
	cube[2][2][0]=cube[2][2][2];
	cube[2][2][1]=cube[2][1][2];
	cube[2][0][2]=temp[0];
	cube[2][1][2]=temp[1];
	cube[2][2][2]=temp[2];
}
bar()
{
	temp[0]=cube[1][0][0];
	temp[1]=cube[1][0][1];
	temp[2]=cube[1][0][2];
	cube[1][0][0]=cube[4][2][0];
	cube[1][0][1]=cube[4][1][0];
	cube[1][0][2]=cube[4][0][0];
	cube[4][2][0]=cube[3][2][2];
	cube[4][1][0]=cube[3][2][1];
	cube[4][0][0]=cube[3][2][0];
	cube[3][2][2]=cube[5][0][2];
	cube[3][2][1]=cube[5][1][2];
	cube[3][2][0]=cube[5][2][2];
	cube[5][0][2]=temp[0];
	cube[5][1][2]=temp[1];
	cube[5][2][2]=temp[2];
	temp[0]=cube[2][0][0];
	temp[1]=cube[2][1][0];
	temp[2]=cube[2][2][0];
	cube[2][0][0]=cube[2][0][2];
	cube[2][1][0]=cube[2][0][1];
	cube[2][0][1]=cube[2][1][2];
	cube[2][0][2]=cube[2][2][2];
	cube[2][1][2]=cube[2][2][1];
	cube[2][2][0]=temp[0];
	cube[2][2][1]=temp[1];
	cube[2][2][2]=temp[2];
}

rud(int ud)
{
	if(ud==1)
	{
		ru();
	}
	else if(ud==2)
	{
		rd();
	}
}
lud(int ud)
{
	
	if(ud==2)
	{
		ld();
	}
	else if(ud==1)
	{
		lu();
	}
}
trl(int ud)
{	
	if(ud==1)
	{
		tr();
	}
	else if(ud==2)
	{
		tl();
	}
}
brl(int ud)
{	
	if(ud==1)
	{
		br();
	}
	else if(ud==2)
	{
		bl();
	}
}
mud(int ud)
{
	if(ud==1)
	{
		ld();
		rd();
	}
	else if(ud==2)
	{
		ru();
		lu();
	}
}
mrl(int ud)
{
	if(ud==2)
	{
		tr();
		br();
	}
	else if(ud==1)
	{
		tl();
		bl();
	}
}
frl(int ud)
{	
	if(ud==2)
	{
		fl();
	}
	else if(ud==1)
	{
		fr();
	}
}
barl(int ud)
{
	if(ud==1)
	{
		bar();
	}
	else if(ud==2)
	{
		bal();
	}
}
bmrl(int ud)
{
	if(ud==2)
	{
		fr();
		bar();
	}
	else if(ud==1)
	{
		fl();
		bal();
	}
}

Brain(int center)
{
	if(s<=pairs)
	{
		for(b[bi]=0;b[bi]<n;b[bi]++)
		{
			a[m]=b[bi];
			++m;
			++s;
			bi++;
			Brain(center);
			if(center==9)
			{break;
			}
			--bi;
			--m;
			--s;
		}
	}
	else if(s>200)
	{
		
	}
	else
	{	
		for(bj=0;bj<m;bj++)
		{
			if(a[bj]/2==0)
			{
				rud((a[bj]%2)+1);
			}
			else if(a[bj]/2==1)
			{
				lud((a[bj]%2)+1);
			}
			else if(a[bj]/2==2)
			{
				mud((a[bj]%2)+1);
			}
			else if(a[bj]/2==3)
			{
				trl((a[bj]%2)+1);
			}
			else if(a[bj]/2==4)
			{
				brl((a[bj]%2)+1);
			}
			else if(a[bj]/2==5)
			{
				mrl((a[bj]%2)+1);
			}
			else if(a[bj]/2==6)
			{
				frl((a[bj]%2)+1);
			}
			else if(a[bj]/2==7)
			{
				barl((a[bj]%2)+1);
			}
			else if(a[bj]/2==8)
			{
				bmrl((a[bj]%2)+1);
			}
		}
		i=0;
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				if(cube[center][j][k]==cube[center][1][1])
				{
					i++;
				}
				else
				{
					j=5;
					strcpy(cube,cube1);
					break;
				}
			}
		}
		if(i==9)
		{
			strcpy(cube1,cube);
			printf("\n\n");
			for(bj=0;bj<m;bj++)
			{
				printf(" %d. %s\n",bj+1,movesdb[a[bj]]);
			}
			center=9;
			side=9;
			s=250;	
		}
	}
}
