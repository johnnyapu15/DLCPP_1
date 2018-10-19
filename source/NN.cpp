
#include <iostream>
#include "./../header/Eigen/Dense"
#include "./../header/json.hpp"


using namespace nlohmann;
using namespace std;
using namespace Eigen;


VectorXd Tanh(VectorXd _input) {
	return VectorXd(Eigen::tanh(_input.array()));
}
VectorXd Tanh_derive(VectorXd _input) {
	VectorXd tmp = Tanh(_input).cwiseProduct(Tanh(_input));
	return VectorXd (_input - tmp);
	//return VectorXd(2);

}



class Node {
	//
};
class ActivationLayer {
private:
	VectorXd(*activation)(VectorXd);
	VectorXd(*derive)(VectorXd);
	VectorXd o;

public:
	ActivationLayer(VectorXd(*_activation)(VectorXd), VectorXd(*_derive)(VectorXd), int _node) {
		activation = _activation;
		derive = _derive;
		o = VectorXd::Zero(_node);
	}
	void feedForward(VectorXd _input) {
		o = activation(_input);
	}
	VectorXd calcDerive(VectorXd _input) {
		return derive(_input);
	}

};
class Layer {
	// CNN ���� �پ��� ���̾ ���� �����ϱ� ���ϰ� �������̽��� �����߰���
	// �ڱ� ��� ������ �����س���, ����ġ���� ��Ʈ��ũ �������� ���ϴ� �ɷ�.
private:
	double learningRate;
	int nodeCount;
	VectorXd net; // n
	MatrixXd delta; // i * n
	MatrixXd w; // i * n
	VectorXd b; // n

public:
	Layer(int _node, int _inputCount, double _learningRate) {
		nodeCount = _node;
		learningRate = _learningRate;
		net = VectorXd::Zero(_node);
		delta = MatrixXd::Zero(_inputCount, _node);
		w = MatrixXd::Zero(_inputCount, _node);
		b = VectorXd::Zero(_node);
	}

	// Load from JSON file
	// json => vector => vector.data => VectorXf or MatrixXf
	Layer(int _node, json _jsonFile) {
		nodeCount = _node;
		net = VectorXd::Zero(_node);
		//delta = MatrixXf::Zero(_inputLayer->nodeCount, _node);
		//w = MatrixXf::Zero(_inputLayer->nodeCount, _node);
		//inputLayer = _inputLayer;
	}


	void initLayer() {
		w.setRandom();
		w /= 5;
		b.setRandom();
	}

	void feedForward(VectorXd _input) {
		//inputLayer�� ������ ������, �� ���� �̿��� ����Ѵ�.
		// ������� ���̾� ���ο� �����Ѵ�.
		this->net = w.transpose() * _input + b;
	}

	void backpropagation(VectorXd _input, VectorXd _derive, Layer* outputLayer) {
		this->delta = outputLayer->w * outputLayer->delta * _derive;
		w += learningRate * _input * this->delta;
	}
};

class NeuralNetwork {
	//���ο� ������ �͵�: ���̾��
	// �Լ�: forward, backward

};




///////////////Spike Neural Network Implementation //////////////////
// node(w[in_node][synapse], net) - synapse (delays[])

class SpikeNeuron {
private:
	MatrixXd w;
	double net;
public:

};

//More try more intense
class Synapse {
private:
	VectorXd delay;

public:

};


