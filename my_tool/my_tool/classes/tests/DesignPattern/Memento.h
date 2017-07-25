#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
//备忘录模式 

在不破坏封装性的前提下， 捕获一个对象的内部状
态， 并在该对象之外保存这个状态。 这样以后就可将该对象恢复到原先保存的状态。

● Originator发起人角色
记录当前时刻的内部状态， 负责定义哪些属于备份范围的状态， 负责创建和恢复备忘录
数据。
● Memento备忘录角色
负责存储Originator发起人对象的内部状态， 在需要的时候提供发起人需要的内部状态。
● Caretaker备忘录管理员角色
对备忘录进行管理、 保存和提供备忘录。

*/

namespace Memento
{
	//备忘者类备份发起者的状态
	class Memento
	{
	public:
		//构造的时候备份数据
		Memento(string state) :_state(state){};
		string _state;
	};
	//发起者类备份自己的状态
	class Originator
	{
	public:
		//建立备份
		Memento* createBackups(){
			return new Memento(_state);
		}
		//恢复备份内容
		void restoreBackups(Memento* memento){
			_state = memento->_state;
		}
		//显示状态
		void show() {
			cout << _state << endl;
		}
		string _state;
	};
	//管理者类管理备份
	class Caretaker
	{
	public:
		//得到备份
		Memento* getMemento(){
			return _memento;
		}
		//设置备份
		void setMemento(Memento* memento){
			_memento = memento;
		}
		Memento *_memento;
	};

}