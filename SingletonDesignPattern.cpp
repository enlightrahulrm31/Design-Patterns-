#include<bits/stdc++.h>

using namespace std;


class Logger{
private:
	static Logger * instance;
	static mutex mtx; // this is for thread safety 

	// Private constructor to prevent instantiaion 

	Logger(){
		cout<<"Logger initialized.\n";
	}


	// delete copy constructor and assigment operator to avoid duplication 

	Logger(const Logger&) = delete;
	Logger& operator = (const Logger&) = delete;

public:
	// we will be creating the static method to accesss the single instance 

	static Logger* getInstance(){
		if(instance == NULL){ // it mean it is already created 
			lock_guard<mutex> lock(mtx);
			if(instance == NULL){
				instance = new Logger(); //  calling the private constructo to create the instance of Logger class 
			}

		}
		return instance;
	}


	// create method to lgo the message 

	void Log(const string &message){
		lock_guard<mutex> lock(mtx);
		cout<<"log message: "<<message<<"\n";
	}


};


// since instace and mtx are static variable we need to define them outside the class as we are doing below 
Logger* Logger::instance = nullptr;
mutex Logger::mtx; // we cannot define mutex mtx = new mutex althrough we can degine them dynamically

int main(){
	Logger* logger1 = Logger::getInstance();
	logger1->Log("random log ");

	Logger* logger2 =  Logger::getInstance(); // calling this second time no new instance of Logger call will be created we will be going to use the previous instance 

	logger2->Log("random log ");


	cout<<" are instance equal "<<(logger1 ==logger2 ? "YES":"NO")<<"\n";

	return 0;
}