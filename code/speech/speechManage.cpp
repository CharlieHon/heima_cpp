#include "speechManage.h"

using namespace std;

// 构造函数
SpeechManage::SpeechManage() {
	// 初始化容器和属性
	initSpeech();

	// 创建12名选手
	createSpeaker();

	// 加载往届记录
	loadRecord();
}

// 显示菜单
void SpeechManage::showMenu() {
	cout << "**************************" << endl;
	cout << "*****欢迎参加演讲比赛*****" << endl;
	cout << "***** 1.开始演讲比赛 *****" << endl;
	cout << "***** 2.查看往届记录 *****" << endl;
	cout << "***** 3.清空比赛记录 *****" << endl;
	cout << "***** 0.退出比赛程序 *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

// 0.退出系统
void SpeechManage::exitSystem() {
	cout << "欢迎下次使用" << endl;
	exit(0);
}

// 1.开始比赛
void SpeechManage::startSpeech() {
	// 第一轮比赛
	// 1.抽签
	this->speechDraw();
	
	// 2.比赛
	this->speechContest();

	// 3.显示晋级
	this->showScore();

	// 第二轮比赛
	++this->m_Index;
	// 1.抽签
	this->speechDraw();
	// 2.比赛
	this->speechContest();
	// 3.显示最终结果
	this->showScore();
	// 4.保存结果到文件中
	this->saveRecord();

	// 重置比赛，获取记录
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();

	cout << "本届比赛完毕" << endl;
	system("pause");
	system("cls");
}

// 初始化容器和属性
void SpeechManage::initSpeech() {
	// 容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	// 初始化比赛轮数
	this->m_Index = 1;

	// 将记录容器清空
	this->m_Record.clear();
}

// 创建12名选手
void SpeechManage::createSpeaker() {
	string nameSeed = "ABCDEFJHIJKL";
	for (int i = 0; i < nameSeed.size(); ++i) {
		string name = string("选手") + nameSeed[i];
		Speaker sp(name);
		
		// 创建选手编号，并且放入到v1容器中
		this->v1.push_back(i + 10001);

		// 选手编号以及对应选手 放入到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

// 抽签
void SpeechManage::speechDraw() {
	cout << "第 (" << this->m_Index << ") 比赛选手正在抽签" << endl;
	cout << "-----------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	if (this->m_Index == 1) {
		// 第一轮比赛
		random_shuffle(v1.begin(), v1.end());
		for (auto it = v1.begin(); it != v1.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

	}
	else {
		// 第二轮比赛
		random_shuffle(v2.begin(), v2.end());
		for (auto it = v2.begin(); it != v2.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
}

// 比赛
void SpeechManage::speechContest() {
	cout << "第 (" << this->m_Index << ") 轮比赛正式开始" << endl;
	
	// 准备临时容器，存放小组成绩
	multimap<double, int, greater<double>> groupScore;
	int num = 0;	// 记录人员个数 6人一组

	vector<int> v_Src;	// 比赛选手容器
	if (this->m_Index == 1) {
		v_Src = v1;
	}
	else {
		v_Src = v2;
	}
	// 遍历所有选手进行比赛
	for (auto it = v_Src.begin(); it != v_Src.end(); ++it) {
		++num;
		// 评委打分
		deque<double> d;
		for (int i = 0; i < 10; ++i) {
			double score = (rand() % 401 + 600) / 10.f;
			// cout << score << " ";
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());	// 降序排序
		d.pop_front();	// 去除最高分
		d.pop_back();	// 去除最低分
		
		double sum = accumulate(d.begin(), d.end(), 0.f);	// 总分
		double avg = sum / double(d.size());	// 平均分
		
		/*
		// 打印平均分
		cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].Name
			<< " 平均分：" << avg << endl;
		*/

		// 将平均分放入到map容器中
		this->m_Speaker[*it].Score[this->m_Index-1] = avg;
	
		// 将打分数据放入到小组容器中
		groupScore.insert(make_pair(avg, *it));	// (得分，选手编号)
		// 每六人取出前三名
		if (num % 6 == 0) {
			cout << "第 " << num / 6 << " 小组比赛名次" << endl;
			for (auto iter = groupScore.begin(); iter != groupScore.end(); ++iter) {
				cout << "编号：" << iter->second << " 姓名：" << this->m_Speaker[iter->second].Name
					<< " 成绩：" << this->m_Speaker[iter->second].Score[this->m_Index - 1] << endl;
			}

			// 取走前三名
			int count = 0;
			for (auto iter = groupScore.begin(); iter != groupScore.end() && count<3; ++iter, ++count) {
				if (this->m_Index == 1) {
					v2.push_back(iter->second);
				}
				else {
					vVictory.push_back(iter->second);
				}
			}
			groupScore.clear();	// 小组容器清空
			cout << endl;
		}
	}
	cout << "---------第 (" << this->m_Index << ") 轮比赛完毕！---------" << endl;
	system("pause");
}

// 显示比赛分数
void SpeechManage::showScore() {
	cout << "---------第 (" << this->m_Index << ") 轮晋级选手信息如下：---------" << endl;
	vector<int> v;
	if (this->m_Index == 1) {
		v = v2;
	}
	else {
		v = vVictory;
	}
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].Name
			<< " 得分：" << this->m_Speaker[*it].Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->showMenu();
}

// 保存分数
void SpeechManage::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);	// 用追加的方式写文件
	
	// 将每个选手的数据写入到文件中
	for (auto it = vVictory.begin(); it != vVictory.end(); ++it) {
		ofs << *it << "," << this->m_Speaker[*it].Score[1] << ",";
	}
	ofs << endl;

	// 关闭
	ofs.close();
	cout << "记录已保存" << endl;
	// 更改文件不为空状态
	this->fileIsEmpty = false;
}

// 读取记录
void SpeechManage::loadRecord() {
	ifstream ifs("speech.csv", ios::in);
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		// cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	// 文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);	// 将上面读取的单个字符再放回来

	string data;
	int ix = 0;
	while (ifs >> data) {
		vector<string> v;	// 存放6个string字符串
		int pos = -1;	// 查找“,”位置的变量
		int start = 0;
		while (true) {
			pos = data.find(",", start);
			if (pos == -1) {
				// 没有找到
				break;
			}
			string temp = data.substr(start, pos - start);
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(ix, v));
		++ix;
	}
	ifs.close();
	/*
	for (auto it = this->m_Record.begin(); it != this->m_Record.end(); ++it) {
		cout << "第" << it->first+1 << "届" << "冠军编号：" << it->second[0] << " 分数：" << it->second[1] << endl;
	}
	*/
}

// 显示往届记录
void SpeechManage::showRecord() {
	if (this->fileIsEmpty) {
		cout << "文件为空或不存在！" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); ++i) {
		cout << "第" << i + 1 << "届"
			<< " 冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
			<< "\t亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
			<< "\t季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
	}
	system("pause");
	system("cls");
}

// 3.清空记录
void SpeechManage::clearRecord() {
	cout << "是否清空数据？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select;
	cin >> select;
	if (select == 1) {
		// 打开模式 ios::trunc 如果存在，删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// 初始化属性
		this->initSpeech();
		// 创建选手
		this->createSpeaker();
		// 获取往届记录
		this->loadRecord();

		cout << "清空成功" << endl;
	}

	system("pause");
	system("cls");
}

// 析构函数
SpeechManage::~SpeechManage() {

}