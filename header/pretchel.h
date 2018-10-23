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
	Layer(int _node, int _inputCount, double _learningRate);

	// Load from JSON file
	// json => vector => vector.data => VectorXf or MatrixXf
	Layer(int _node, json _jsonFile);


	void initLayer();

	void feedForward(VectorXd _input);

	void backpropagation(VectorXd _input, VectorXd _derive, Layer* outputLayer);
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



#endif