#include<iostream>
using namespace std;

class CPU
{
public:
	virtual void calculate() = 0;
};

class GraphicsCard
{
public:
	virtual void display() = 0;
};

class Memory
{
public:
	virtual void storage() = 0;
};

class IntelCPU : public CPU
{
public:
	void calculate()
	{
		cout << "Intel-Core start work..." << endl;
	}
};

class AMDCPU : public CPU
{
public:
	void calculate()
	{
		cout << "AMD-Ryzen start work..." << endl;
	}
};

class NvidiaGPU : public GraphicsCard
{
public:
	void display()
	{
		cout << "Nvidia RTX 3080 working for display..." << endl;
	}
};

class AMDGPU : public GraphicsCard
{
public:
	void display()
	{
		cout << "AMD Radeon RX 5700 XT working for display..." << endl;
	}
};

class GSkillMemory : public Memory
{
public:
	void storage()
	{
		cout << "G.SKILL Memory in use..." << endl;
	}
};

class CrucialMemory : public Memory
{
public:
	void storage()
	{
		cout << "Crucial Memory in use..." << endl;
	}
};

class Computer
{
public:
	Computer(CPU *cpu, GraphicsCard *gpu, Memory *ram)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_ram = ram;
	}

	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_ram != NULL)
		{
			delete m_ram;
			m_ram = NULL;
		}
	}

	void work()
	{
		cout << "This computer start work..." << endl;
		m_cpu->calculate();
		m_gpu->display();
		m_ram->storage();
	}

// 这些指针可以指定为私有
private:
	CPU* m_cpu;
	GraphicsCard* m_gpu;
	Memory* m_ram;
};

void test01()
{
	// 我的写法
	//Computer Lenovo(new IntelCPU, new NvidiaGPU, new CrucialMemory);
	//Lenovo.work();
	//cout << "---------------------------------------------" << endl;
	//Computer Dell(new IntelCPU, new AMDGPU, new GSkillMemory);
	//Dell.work();
	//cout << "---------------------------------------------" << endl;
	//Computer HP(new AMDCPU, new AMDGPU, new CrucialMemory);
	//HP.work();

	// 黑马的写法
	Computer* Lenovo = new Computer(new IntelCPU, new NvidiaGPU, new CrucialMemory);
	Lenovo->work();
	if (Lenovo != NULL)
	{
		delete Lenovo;
		Lenovo = NULL;
	}
	cout << "---------------------------------------------" << endl;
	Computer* Dell = new Computer(new IntelCPU, new AMDGPU, new GSkillMemory);
	Dell->work();
	if (Dell != NULL)
	{
		delete Dell;
		Dell = NULL;
	}
	cout << "---------------------------------------------" << endl;
	Computer* HP = new Computer(new AMDCPU, new AMDGPU, new CrucialMemory);
	HP->work();
	if (HP != NULL)
	{
		delete HP;
		HP = NULL;
	}
}

int main()
{

	test01();

	system("pause");

	return 0;
}