#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <stdlib.h>
#include <time.h>
main()
{
	
	int A[10];
	char et[5];

    srand(time(NULL));

	/* cargo array con valor igual al indice mas 10*/
	for (int i=0;i<10;i++)
	{
		A[i]=rand() % 51;
	}
	
    int gd = DETECT, gm;
 
   initgraph(&gd, &gm, "C:\\TC\\BGI");
   
   int x = 100;
   
   rectangle(50, 50, 600, 400);
   
    for (int i=0;i<9;i++)
	{
		//line(x1,y1,x2,y2);
		printf("%d\n",A[i]);
		setcolor(9);
		line(x,400-(A[i]*5), x+50, 400-(A[i+1]*5));
		itoa(A[i], et, 10);
		setcolor(15);
		outtextxy(x-5, 400-(A[i]*5)-10, et);
	
		line(x,400,x,400-(A[i]*5));
		
		x=x+50;
	}
    setcolor(15);
   itoa(A[9], et, 10);
   outtextxy(x-5, 400-(A[9]*5)-10, et);
  
   line(x,400,x,400-(A[9]*5));
 
   getch();
   closegraph();
   return 0;
}
