#pragma once
#include <iostream>
#include <string>
using namespace std;

//用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
/*
参与对象 
• Prototype
— 声明一个克隆自身的接口。
• Concrete Prototype
— 实现一个克隆自身的操作。
• Client
— 让一个原型克隆自身从而创建一个新的对象。

*/

namespace Prototype
{
	//Prototype克隆对象的抽象
	class Control
	{
	public:
		Control(){}
		virtual ~Control(){}
		virtual Control* clone()
		{
			return nullptr;
		}

		virtual const char* getName() = 0;

		virtual float getWidth() = 0;
		virtual float getHeight() = 0;

		virtual void setWidth( float fwidth ) = 0;
		virtual void setHeight( float fheight ) = 0;

		virtual float getPositionX() = 0;
		virtual float getPositionY() = 0;

		virtual void setPositionX( float fx ) = 0;
		virtual void setPositionY( float fy ) = 0;

		void display()
		{
			cout << "name:" << getName() << endl;
			cout << "width:" << getWidth() << endl;
			cout << "height:" << getHeight() << endl;
			cout << "x:" << getPositionX() << endl;
			cout << "y:" << getPositionY() << endl;
		}
	};

	//Concrete Prototype
	class Button :
		public Control
	{
		float m_fWidth;
		float m_fHeight;
		float m_fx;
		float m_fy;
	public:
		Button():m_fHeight(0.f),m_fWidth(0.f),m_fx(0.f),m_fy(0.f){}
		~Button(){}

		Button(float fx, float fy, float fwidth, float fheight) :m_fWidth(fwidth), m_fHeight(fheight), m_fx(fx), m_fy(fy)
		{
		}

		Button(Button& btn) :m_fHeight(btn.m_fHeight), m_fWidth(btn.m_fWidth), m_fx(btn.m_fx), m_fy(btn.m_fy)
		{
		}

		virtual const char* getName() {
			return "button";
		}

		virtual float getHeight() override
		{
			return m_fHeight;
		}

		virtual float getWidth() override
		{
			return m_fWidth;
		}

		virtual float getPositionX() override
		{
			return m_fx;
		}

		virtual float getPositionY() override
		{
			return m_fy;
		}

		virtual void setHeight(float fheight) override
		{
			m_fHeight = fheight;
		}

		virtual void setWidth(float fwidth) override
		{
			m_fWidth = fwidth;
		}

		virtual void setPositionX(float fx) override
		{
			m_fx = fx;
		}

		virtual void setPositionY(float fy) override
		{
			m_fy = fy;
		}

		virtual Control* clone() override
		{
			return new Button(*this);
		}

	};

}