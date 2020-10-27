#include <stdio.h>
#include <iostream>

using namespace std;

class Point {
public:
	Point();
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
	bool a;
	Rectangle(bool a_) : a(a_) {};
	Rectangle* Initializer(Rectangle* initRecptr) {
		cout << "Enter X and Y left up, left low, right up, right low points" << endl;
		cout << "The sides must be parallel to the axes" << endl;
		cout << "left up" << endl;
		cin >> initRecptr->LU.x;
		cin >> initRecptr->LU.y;
		cout << "left low" << endl;
		cin >> initRecptr->LL.x;
		cin >> initRecptr->LL.y;
		cout << "right up" << endl;
		cin >> initRecptr->RU.x;
		cin >> initRecptr->RU.y;
		cout << "right low" << endl;
		cin >> initRecptr->RL.x;
		cin >> initRecptr->RL.y;
		if (LL.y != RL.y || LU.y != RU.y || LL.x != LU.x || RL.x != RU.x) {
			cout << "Enter correct coordinates" << endl;
			return nullptr;
		}
		else {
			return initRecptr;
		}
	}
};

int main()
{
	Rectangle A(true);
}
