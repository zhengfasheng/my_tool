#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "md5/md5.h"
using namespace std;

/*
门面模式/外观模式
要求一个子系统的外部与其内部的通信必须通
过一个统一的对象进行。 门面模式提供一个高层次的接口， 使得子系统更易于使用。

● Facade门面角色
客户端可以调用这个角色的方法。 此角色知晓子系统的所有功能和责任。 一般情况下，
本角色会将所有从客户端发来的请求委派到相应的子系统去， 也就说该角色没有实际的业务
逻辑， 只是一个委托类。
● subsystem子系统角色
可以同时有一个或者多个子系统。 每一个子系统都不是一个单独的类， 而是一个类的集
合。 子系统并不知道门面的存在。 对于子系统而言， 门面仅仅是另外一个客户端而已。


某软件公司欲开发一个可应用于多个软件的文件加密模块，
该模块可以对文件中的数据进行加密并将加密之后的数据存储在一个新文件中，
具体的流程包括三个部分，分别是读取源文件、加密、保存加密之后的文件，
其中，读取文件和保存文件使用流来实现，加密操作通过求模运算实现。
这三个操作相对独立，为了实现代码的独立重用，让设计更符合单一职责原则，
这三个操作的业务代码封装在三个不同的类中。

现使用外观模式设计该文件加密模块。


*/

namespace Facade
{
	//subsystem子系统角色
	//文件读取
	class FileReader
	{
	public:
		string readFile(string filePath)
		{
			string result = "";
			cout << "正在读取文件:" << filePath << endl;
			ifstream read(filePath);
			if ( read.is_open())
			{
				char buffer[256]{0};
				//一直读取到文件末尾
				while ( !read.eof() )
				{
					read.getline(buffer, 200);
					result += buffer;
				}

				read.close();
			}
			else
			{
				cout << "读取文件:" << filePath << "失败" << endl;
			}
			cout << "读取文件:" << filePath << "成功" << endl;
			return result;
		}
	};

	//文件写入
	class FileWriter
	{
	public:
		void write(string content, string filePath)
		{
			cout << "正在写入文件:" << filePath << endl;

			ofstream write(filePath);
			if ( write.is_open() )
			{
				write << content;
				write.close();
			}
			else
			{
				cout << "打开文件" << filePath << "失败" << endl;
			}
			cout << "写入文件:" << filePath << "成功" << endl;
		}
	};

	//文件加密
	class FileEncrypt
	{
	public:
		string encrypt(string content)
		{
			MD5 md5(content);
			cout << content << "加密后为:" << md5.md5() << endl;
			return md5.md5();
		}
	};

	//外观类
	class EncrytFile
	{
	private:
		
		FileEncrypt* m_pEncrypt;
		FileReader* m_pReader;
		FileWriter* m_pWriter;
	public:
		EncrytFile()
		{
			m_pEncrypt = new FileEncrypt;
			m_pReader = new FileReader;
			m_pWriter = new FileWriter;
		}
		~EncrytFile()
		{
			if (m_pWriter)
				delete m_pWriter;
			if (m_pReader)
				delete m_pReader;
			if (m_pEncrypt)
				delete m_pEncrypt;
		}

		//调用其它对象的业务处理
		void fileEncrypt(string srcPath, string destPath)
		{
			string content = m_pReader->readFile(srcPath);
			string encryptString = m_pEncrypt->encrypt(content);
			m_pWriter->write(encryptString, destPath);
		}
	};
}