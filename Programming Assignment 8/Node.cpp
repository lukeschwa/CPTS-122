#include "Node.h"\
//Node
Node::Node() {
	mpLeft = nullptr;
	mpRight = nullptr;
	mData = nullptr;
}
Node::Node(string newData) {
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}
Node::~Node() {

}
Node *&Node::getLeftPtr() {
	return this->mpLeft;
}
Node *&Node::getRightPtr() {
	return this->mpRight;
}
string Node::getData() {
	return this->mData;
}
void Node::setLeftPtr(Node *newLeft) {
	this->mpLeft = newLeft;
}
void Node::setRightPtr(Node *newRight) {
	this->mpRight = newRight;
}
void Node::setData(string newData) {
	this->mData = newData;
}

//tNode
tNode::tNode() {
	mUnits = 0;
}
tNode::tNode(string newData, int units) {
	Node(newData);
	mUnits = units;
}
tNode::~tNode() {

}