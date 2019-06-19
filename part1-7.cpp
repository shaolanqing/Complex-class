/*定义复数（complex ）类，其中至少包括实部和虚部，对复数类实现尽可能丰富的运算。
功能要求：
1）建立复数类
2）复数信息的初始化
3）复数信息的输出
4）将复数信息保存为文件
5）求复数的绝对值
6）实现复数的加、减、自加、自减等运算。*/

#include<iostream>
using namespace std;
class Complex;
Complex & operator +(Complex &c1,Complex &c2);
Complex & operator -(Complex &c,Complex &c2);
istream & operator >>(istream &is,Complex &c);
ostream & operator <<(ostream &os,Complex &c);
class Complex
{
private:
	int real;
	int image;
public:
	Complex();
	Complex(int r,int i);
	Copmlex(Complex &c);
	~Complex();
	void printinfo();
	friend Complex & operator +(Complex &c1,Complex &c2);
	friend Complex & operator -(Complex &c,Complex &c2);
	  Complex operator ++()
 {
	 real++;
	 image++;
	 return *this;
 }
 Complex operator --()
{
	 
	 real--;
	 image--;
	 return *this;
 }
	 Complex operator ++(int)//后置++
 {
	Complex &t=*this;
	real++;
	image++;
	return t;
}
Complex operator --(int) //前置--
{
	Complex &t=*this;
	real--;
	image--;
	return t;
}
	
    friend istream & operator >>(istream &is,Complex &c);
	friend ostream & operator <<(ostream &os,Complex &c);
    

};
//#include"ComplexHeader.h"
Complex::Complex()
{
	real=0;
	image=0;
}
Complex::Complex(int r,int i)
{
    real=r;
	image=i;
}
Complex::Copmlex(Complex &c)
{
	real=c.real;
	image=c.image;
}
Complex::~Complex()
{
	cout<<"complex is construction!"<<endl;
}
void Complex::printinfo()
{
	if(image<0)
		cout<<"the complex:"<<real<<image<<"i"<<endl;
	else if(image==0)
        cout<<"the complex:"<<real<<endl;
	else 
		cout<<"the complex:"<<real<<"+"<<image<<"i"<<endl;
}
Complex & operator +(Complex &c1,Complex &c2)
{
	return Complex(c1.real+c2.real,c1.image+c2.image);
}
Complex & operator -(Complex &c1,Complex &c2)
{
	return Complex(c1.real-c2.real,c1.image-c2.image);
}
 /*Complex operator ++()
 {
	 real++;
	 image++;
	 return *this;
 }
Complex operator --()
 {
	 real--;
	 image--;
	 return *this;
 }*/
/*Complex operator ++(int) //后置++
{
	Complex &t=*this;
	real++;
	image++;
	return t;
}
Complex operator --(int) //前置--
{
	Complex &t=*this;
	real--;
	image--;
	return t;
}*/
istream & operator >>(istream &is,Complex &c)
{
	cout<<"input the complex:"<<endl;
	is>>c.real>>c.image;
	return is;
}
ostream & operator <<(ostream &os,Complex &c)
{
    
	if(c.image<0)
		os<<"the complex:"<<c.real<<c.image<<"i"<<endl;
	else if(c.image==0)
        os<<"the complex:"<<c.real<<endl;
	else 
		os<<"the complex:"<<c.real<<"+"<<c.image<<"i"<<endl;
	return os;
}
int main()
{
	Complex c1(5,7),c2(-3,-4);
	c1.printinfo();
	c2.printinfo();

	Complex c3=c1+c2;
	cout<<c3<<endl;

	Complex c4=c1-c2;
	cout<<c4<<endl;

	cout<<c1++<<endl;
	cout<<c1--<<endl;

	cout<<++c2<<endl;
	cout<<--c2<<endl;

	Complex c5;
	cin>>c5;
	cout<<c5;

	return 0;
}