#include <iostream>

using namespace std;

struct quadtree{
	int puntos;
	int H;
	float X1,Y1;
	float X2,Y2;
	quadtree* hijos[4];

	quadtree(int h, float x1, float y1, float x2, float y2){
		H = h;
		puntos = 0;

		X1 = x1;
		Y1 = y1;
		X2 = x2;
		Y2 = y2;

		if (h-1){
			hijos[0] = new quadtree(h-1,x1,y1,(x1+x2)/2,(y1+y2)/2);
			hijos[1] = new quadtree(h-1,(x1+x2)/2,y1,x2,(y1+y2)/2);
			hijos[2] = new quadtree(h-1,x1,(y1+y2)/2,(x1+x2)/2,y2);
			hijos[3] = new quadtree(h-1,(x1+x2)/2,(y1+y2)/2,x2,y2);
		}
	}

	void print(int h = 0) {
		cout << puntos;
		if (h < H-1){
			cout << "(";
			hijos[0]->print();
			cout << " ";
			hijos[1]->print();
			cout << " ";
			hijos[2]->print();
			cout << " ";
			hijos[3]->print();
			cout << ")";
		}
	}

	void add(float x, float y, int h = 0) {
		puntos++;
		if (h < H-1){
			if (x >= X1 && x <= X2 && y >= Y1 && y <= Y2){
				if (x <= (X1+X2)/2){
					if (y <= (Y1+Y2)/2)
						hijos[0]->add(x,y,h++);
					else
						hijos[2]->add(x,y,h++);
				}
				else {
					if (y <= (Y1+Y2)/2)
						hijos[1]->add(x,y,h++);
					else
						hijos[3]->add(x,y,h++);
				}
			}
		}
	}
};

int main() {
	quadtree *RQT = new quadtree(3,0,0,4,4);
	RQT->add(1.2,1.5);
	RQT->add(0.2,2.5);
	RQT->add(1.5,3.5);
	RQT->add(3.2,2.5);
	RQT->add(3.5,2.7);
	RQT->print();
	cout << endl;
    return 0;
}
