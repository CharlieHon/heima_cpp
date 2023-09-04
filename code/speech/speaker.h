#pragma once
#include <string>

class Speaker {	// 选手类
public:
	Speaker() = default;	// 默认构造函数
	Speaker(const std::string& n) : Name(n){
		this->Score[0] = 0;
		this->Score[1] = 0;
	}

	std::string Name;	// 姓名
	double Score[2];	// 得分 最多有两轮得分
};
