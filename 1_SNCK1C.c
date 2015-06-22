
#include <stdio.h>
#include <math.h>
int main()
{
	int t,n,sx,sy,ex,ey,bx,by;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d %d %d %d",&n,&sx,&sy,&ex,&ey,&bx,&by);
		int minmoves = abs(ex-sx)+abs(ey-sy);
		if((sx==ex&&sx==bx&&(abs(ey-sy)>abs(by-sy)))||(sy==ey&&sy==by&&(abs(ex-sx)>abs(bx-sx))))
			printf("%d\n", minmoves+2);
		else
			printf("%d\n", minmoves);
	}
}