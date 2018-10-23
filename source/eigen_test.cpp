

#include "./../header/pretchel.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace Eigen;

int main() {
	MatrixXd w = MatrixXd::Zero(4,2);
	w.setRandom();
	w /= 5;
	VectorXd b = VectorXd::Random(4);
	
	VectorXd x(2);
	x = Vector2d (1, 3);
	

	
	cout << "HERE \n" << w << "\n\n" << b << "\n\n" << w*x + b << "\n\n" << Tanh_derive(x) << endl;

	return 0;

}