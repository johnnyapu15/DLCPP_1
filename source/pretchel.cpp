
#include "./../header/pretchel.h"



// Activation function

	// Tanh
	VectorXd tanh(VectorXd _input) {
		return VectorXd(Eigen::tanh(_input.array()));
	}
	VectorXd tanh_derive(VectorXd _input) {
		VectorXd tmp = tanh(_input).cwiseProduct(tanh(_input));
		return VectorXd (_input - tmp);  
	}


// Error function

	VectorXd softmax(VectorXd _input, ) {

	}



// class ActivationLayer implementation

ActivationLayer::ActivationLayer(VectorXd(*_activation)(VectorXd), VectorXd(*_derive)(VectorXd), int _node) {
	activation = _activation;
	derive = _derive;
	o = VectorXd::Zero(_node);
}
void ActivationLayer::feedForward(VectorXd _input) {
	o = activation(_input);
}
VectorXd ActivationLayer::calcDerive(VectorXd _input) {
	return derive(_input);
}


// class Layer implementation


Layer::Layer(int _node, int _inputCount, double _learningRate) {
	nodeCount = _node;
	learningRate = _learningRate;
	net = VectorXd::Zero(_node);
	delta = MatrixXd::Zero(_inputCount, _node);
	w = MatrixXd::Zero(_inputCount, _node);
	b = VectorXd::Zero(_node);
}

// Load from JSON file
// json => vector => vector.data => VectorXf or MatrixXf
Layer::Layer(int _node, json _jsonFile) {
	nodeCount = _node;
	net = VectorXd::Zero(_node);
	//delta = MatrixXf::Zero(_inputLayer->nodeCount, _node);
	//w = MatrixXf::Zero(_inputLayer->nodeCount, _node);
	//inputLayer = _inputLayer;
}


void Layer::initLayer() {
	w.setRandom();
	w /= 5;
	b.setRandom();
}

void Layer::feedForward(VectorXd _input) {
	//inputLayer를 가지고 있으니, 그 값을 이용해 계산한다.
	// 결과값은 레이어 내부에 저장한다.
	this->net = w.transpose() * _input + b;
}

void Layer::backpropagation(VectorXd _input, VectorXd _derive, Layer* outputLayer) {
	this->delta = outputLayer->w * outputLayer->delta * _derive;
	w += learningRate * _input * this->delta;
}





///////////////Spike Neural Network Implementation //////////////////
// node(w[in_node][synapse], net) - synapse (delays[])


