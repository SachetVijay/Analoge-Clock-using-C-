#include<iostream>
#include<conio.h>
#include<windows.h>
#include<graphics.h>
#include<math.h>
#include<cmath>
using namespace std;

int x_ap(int a) {
	return (getmaxx() / 2 ) + a;
}

int y_ap(int a) {
	return (getmaxy() / 2 ) - a;
}

void drawLine(int x1, int y1,int x2, int y2, int color) {
	setcolor(color);
	setlinestyle(0,0,1);
	line(x_ap(x1), y_ap(y1), x_ap(x2), y_ap(y2));
}

void drawCircle(int x, int y, int& r, int color) {
	setcolor(color);
	circle(x_ap(x), y_ap(y), r);
}

void drawHand(pair<int, int>& center, float angle, int length, int color) {
	drawLine(center.first, center.second,
	center.first + length*cos(angle), 
	center.second + length*sin(angle), color);
}

int main() {
	int gd = DETECT, gm, color;
	initgraph(&gd, &gm, NULL);
	
	int CLOCK_RADIUS = 150;
	int MINUTE_HAND = 120;
	int SECOND_HAND = 100;
	int HOUR_HAND = 85;
	
	pair<int, int> CLOCK_CENTER = make_pair(0, getmaxy()/2 - 20 - CLOCK_RADIUS);
	
	float minute_angle = M_PI / 2;
	float second_angle = M_PI / 2;
	float hour_angle = M_PI / 2;
	int seconds = 0;
	
	while(1) {
		cleardevice();
		seconds++;
		char h[5];
		char m[5];
		char s[5];
		sprintf(h, "%d", (seconds/(60*60))%12);
		sprintf(m, "%d", (seconds/60)%60);
		sprintf(s ,"%d", seconds%60);
		
		outtextxy(getmaxx()/2 - 25, getmaxy() - 60,h );
		outtextxy(getmaxx()/2, getmaxy() - 60, m);
		outtextxy(getmaxx()/2 + 25, getmaxy() - 60, s);
		
		second_angle -= (M_PI / 30);
		minute_angle -= (M_PI / (30*60));
		hour_angle -= (M_PI / (30*60*12));
		
		drawCircle(CLOCK_CENTER.first, CLOCK_CENTER.second, CLOCK_RADIUS,9);
		drawHand(CLOCK_CENTER, minute_angle, MINUTE_HAND, 8 );
		drawHand(CLOCK_CENTER, hour_angle, HOUR_HAND, 2);
		drawHand(CLOCK_CENTER, second_angle, SECOND_HAND, 7);
		
		if(second_angle <= -3*M_PI/2) {
			second_angle = M_PI/2;
		}
		if(hour_angle <= -3*M_PI/2) {
			hour_angle = M_PI/2;
		}
		if(minute_angle <= -3*M_PI/2){
			minute_angle = M_PI/2;
		}
		delay(1000);
	}
	getch();
	closegraph();
	return 0;
}
