#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "md5/md5.h"
using namespace std;

/*
����ģʽ/���ģʽ
Ҫ��һ����ϵͳ���ⲿ�����ڲ���ͨ�ű���ͨ
��һ��ͳһ�Ķ�����С� ����ģʽ�ṩһ���߲�εĽӿڣ� ʹ����ϵͳ������ʹ�á�

�� Facade�����ɫ
�ͻ��˿��Ե��������ɫ�ķ����� �˽�ɫ֪����ϵͳ�����й��ܺ����Ρ� һ������£�
����ɫ�Ὣ���дӿͻ��˷���������ί�ɵ���Ӧ����ϵͳȥ�� Ҳ��˵�ý�ɫû��ʵ�ʵ�ҵ��
�߼��� ֻ��һ��ί���ࡣ
�� subsystem��ϵͳ��ɫ
����ͬʱ��һ�����߶����ϵͳ�� ÿһ����ϵͳ������һ���������࣬ ����һ����ļ�
�ϡ� ��ϵͳ����֪������Ĵ��ڡ� ������ϵͳ���ԣ� �������������һ���ͻ��˶��ѡ�


ĳ�����˾������һ����Ӧ���ڶ��������ļ�����ģ�飬
��ģ����Զ��ļ��е����ݽ��м��ܲ�������֮������ݴ洢��һ�����ļ��У�
��������̰����������֣��ֱ��Ƕ�ȡԴ�ļ������ܡ��������֮����ļ���
���У���ȡ�ļ��ͱ����ļ�ʹ������ʵ�֣����ܲ���ͨ����ģ����ʵ�֡�
������������Զ�����Ϊ��ʵ�ִ���Ķ������ã�����Ƹ����ϵ�һְ��ԭ��
������������ҵ������װ��������ͬ�����С�

��ʹ�����ģʽ��Ƹ��ļ�����ģ�顣


*/

namespace Facade
{
	//subsystem��ϵͳ��ɫ
	//�ļ���ȡ
	class FileReader
	{
	public:
		string readFile(string filePath)
		{
			string result = "";
			cout << "���ڶ�ȡ�ļ�:" << filePath << endl;
			ifstream read(filePath);
			if ( read.is_open())
			{
				char buffer[256]{0};
				//һֱ��ȡ���ļ�ĩβ
				while ( !read.eof() )
				{
					read.getline(buffer, 200);
					result += buffer;
				}

				read.close();
			}
			else
			{
				cout << "��ȡ�ļ�:" << filePath << "ʧ��" << endl;
			}
			cout << "��ȡ�ļ�:" << filePath << "�ɹ�" << endl;
			return result;
		}
	};

	//�ļ�д��
	class FileWriter
	{
	public:
		void write(string content, string filePath)
		{
			cout << "����д���ļ�:" << filePath << endl;

			ofstream write(filePath);
			if ( write.is_open() )
			{
				write << content;
				write.close();
			}
			else
			{
				cout << "���ļ�" << filePath << "ʧ��" << endl;
			}
			cout << "д���ļ�:" << filePath << "�ɹ�" << endl;
		}
	};

	//�ļ�����
	class FileEncrypt
	{
	public:
		string encrypt(string content)
		{
			MD5 md5(content);
			cout << content << "���ܺ�Ϊ:" << md5.md5() << endl;
			return md5.md5();
		}
	};

	//�����
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

		//�������������ҵ����
		void fileEncrypt(string srcPath, string destPath)
		{
			string content = m_pReader->readFile(srcPath);
			string encryptString = m_pEncrypt->encrypt(content);
			m_pWriter->write(encryptString, destPath);
		}
	};
}