#pragma once

#ifndef PRETCHEL_H
#define PRETCHEL_H

#include <iostream>
#include "./../header/Eigen/Dense"
#include "./../header/json.hpp"


using namespace nlohmann;
using namespace std;
using namespace Eigen;


VectorXd tanh(VectorXd _input);
VectorXd tanh_derive(VectorXd _input);



class Node {
	//
};
class ActivationLayer {
private:
	VectorXd(*activation)(VectorXd);
	VectorXd(*derive)(VectorXd);
	VectorXd o;

public:
	ActivationLayer(VectorXd(*_activation)(VectorXd), VectorXd(*_derive)(VectorXd), int _node);
	void feedForward(VectorXd _input);
	VectorXd calcDerive(VectorXd _input);

};
class Layer {
	// CNN 같은 다양한 레이어를 새로 정의하기 편하게 인터페이스로 만들어야겠음
	// 자기 노드 개수만 저장해놓고, 가중치값은 네트워크 레벨에서 정하는 걸로.
private:
	double learningRate;
	int nodeCount;
	VectorXd net; // n
	MatrixXd delta; // i * n
	MatrixXd w; // i * n
	VectorXd b; // n

public:
	Layer(int _node, int _inputCount, double _learningRate);

	// Load from JSON file
	// json => vector => vector.data => VectorXf or MatrixXf
	Layer(int _node, json _jsonFile);


	void initLayer();

	void feedForward(VectorXd _input);

	void backpropagation(VectorXd _input, VectorXd _derive, Layer* outputLayer);
};

class NeuralNetwork {
	//내부에 저장할 것들: 레이어들
	// 함수: forward, backward

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



#endif