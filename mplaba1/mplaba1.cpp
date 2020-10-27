#include <stdio.h>
#include <iostream>

using namespace std;

class Point {
public:
	Point() {};
	int x;
	int y;
	Point(int x_, int y_) :x(x_), y(y_) {};
};

class Rectangle : public Point {
private:
	Point LU;
	Point LL;
	Point RU;
	Point RL;
public:
	Rectangle() {};
	Rectangle* Creator(Rectangle* creatPtr) {
		cout << "Enter X and Yleft low, right up points" << endl;
		cout << "The sides must be parallel to the axes" << endl;
		cout << "left low" << endl;
		cin >> creatPtr->LL.x;
		cin >> creatPtr->LL.y;
		cout << "right up" << endl;
		cin >> creatPtr->RU.x;
		cin >> creatPtr->RU.y;
		creatPtr = Maker(creatPtr);
		return creatPtr;
	}

	Rectangle* Maker(Rectangle* makeptr) {
		makeptr->LU.x = makeptr->LL.x;
		makeptr->RL.x = makeptr->RU.x;
		makeptr->LU.y = makeptr->RU.y;
		makeptr->RL.y = makeptr->LL.y;
		return makeptr;
	}

	void Tester (Rectangle * rec1, Rectangle * rec2) {
		if (rec1->LL.x >= rec2->LL.x) {
			Intersection(rec2, rec1);
		}
		if (rec1->LL.x <= rec2->LL.x) {
			Intersection(rec1, rec2);
		}
	}

	Rectangle* Intersection (Rectangle* L, Rectangle* R) {
		Rectangle Inter;
		Rectangle* InterPtr = &Inter;
		if (L->RL.x <= R->LL.x || L->RL.y >= R->LU.y || L->RU.y <= R->LL.y) {
			cout << "Rectangle havn't intersection rectangle" << endl;
			return nullptr;
		} 
		if (L->LL.y >= R->LL.y) { InterPtr->LL.x = R->LL.x; InterPtr->LL.y = L->LL.y; }  //left low
		if (L->LL.y < R->LL.y) { InterPtr->LL.x = R->LL.x; InterPtr->LL.y = R->LL.y; }   //------
		if (L->RU.y <= R->RU.y) { InterPtr->RU.y = L->RU.y; } //y right up
		if (L->RU.y > R->RU.y) { InterPtr->RU.y = R->RU.y; }  //------
		if (L->RU.x >= R->RU.x) { InterPtr->RU.x = R->RU.x; }//x right up
		if (L->RU.x <= R->RU.x) { InterPtr->RU.x = L->RU.x; }//-------
		InterPtr = Maker(InterPtr);
		cout << &Inter << endl;
		return InterPtr;
	}
};

void starter() {
	Rectangle A;
	A.Creator(&A);
	Rectangle B;
	B.Creator(&B);
	A.Tester(&A, &B);
}

int main(){
	starter();
}