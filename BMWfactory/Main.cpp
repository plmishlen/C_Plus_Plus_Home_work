#include<iostream>
#include<string>
using namespace std;

class BMWfactory
{
	std::string vendor;
	std::string model;
	unsigned int year;
	unsigned int max_speed;
	unsigned int engine;
	static BMWfactory* pattern;		
	BMWfactory() :vendor(vendor), model(model), max_speed(max_speed), year(year), engine(engine)
	{
		vendor = "BMW";
		model = "X3";
		year = 2021;
		max_speed = 215;
		engine = 1998;
		cout << "BMWConstructor:\t" << this << endl;
	}

	BMWfactory(const BMWfactory& other) = delete;
	BMWfactory& operator=(const BMWfactory& other) = delete;

	~BMWfactory()
	{
		delete pattern;
		pattern = nullptr;
		cout << "BMWDestructor:\t" << this << endl;
	}
public:
	const std::string& get_vendor()const
	{
		return vendor;
	}
	const std::string& get_model()const
	{
		return model;
	}
	const unsigned int get_year()const
	{
		return year;
	}
	const unsigned int get_max_speed()const
	{
		return max_speed;
	}
	const unsigned int get_engine()const
	{
		return engine;
	}
	void set_vendor(const std::string& vendor)
	{
		this->vendor = vendor;
	}
	void set_model(const std::string& model)
	{
		this->model = model;
	}
	void set_year(const unsigned int year)
	{
		this->year = year;
	}
	void set_max_speed(const unsigned int max_speed)
	{
		this->max_speed = max_speed;
	}
	void set_engine(const unsigned int engine)
	{
		this->engine = engine;
	}


	static BMWfactory* getPattern()
	{
		if (pattern == nullptr)pattern = new BMWfactory();
		return pattern;
	}
	void info()const
	{
		cout << this << "\nМарка, модель: " << vendor << " " << model << ", год выпуска: " << year << ",\nмаксимальная скорость: " << max_speed
			<< ", объем двигателя: " << engine << endl;
	}
};

BMWfactory* BMWfactory::pattern = nullptr;

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "This is a singletone pattern \"BMWfactory\": " << endl;
	BMWfactory::getPattern()->info();
	BMWfactory::getPattern()->set_vendor("BMW");
	BMWfactory::getPattern()->set_model("X5");
	BMWfactory::getPattern()->set_year(2015);
	BMWfactory::getPattern()->set_max_speed(250);
	BMWfactory::getPattern()->set_engine(2998);
	BMWfactory::getPattern()->info();

}