
#include "./../header/Eigen/Dense"
#include <iostream>
#include <vector>

using namespace std;
using namespace Eigen;

int main() {
	MatrixXf w = MatrixXf::Zero(4,2);
	w.setRandom();
	w /= 5;
	VectorXf b = VectorXf::Random(4);
	
	VectorXf x(2);
	x = Vector2d (1, 3);
	


	cout << "HERE \n" << w << "\n\n" << b << "\n\n" << w*x + b << "\n\n" << x - x << endl;

	return 0;

}