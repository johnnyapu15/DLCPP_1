#include "NN.cpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace Eigen;

int main() {
	MatrixXf w = MatrixXf::Zero(4,2);
	w.setRandom();
	w /= 5;
	VectorXf b = VectorXf::Random(4);
	
	Vector2f x(1, 2);

	


	cout << "HERE \n" << w << "\n\n" << b << "\n\n" << w*x + b << endl;

	return 0;

}