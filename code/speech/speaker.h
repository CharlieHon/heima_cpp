#pragma once
#include <string>

class Speaker {	// ѡ����
public:
	Speaker() = default;	// Ĭ�Ϲ��캯��
	Speaker(const std::string& n) : Name(n){
		this->Score[0] = 0;
		this->Score[1] = 0;
	}

	std::string Name;	// ����
	double Score[2];	// �÷� ��������ֵ÷�
};
