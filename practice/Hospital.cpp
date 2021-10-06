#include <string>
#include <iostream>
#include <vector>

using namespace std;

class HospitalDepartment {
protected:
	string hospitalName;
	int numberOfDoctors;

public:
	//HospitalDepartment(string hospitalName, int nrDocs) : hospitalName(hospitalName), numberOfDoctors(nrDocs) {};
	virtual bool isEfficient() = 0;
	virtual string toString() {
		string resultString = "";
		resultString += this->hospitalName;
		resultString += ", ";
		resultString += to_string(this->numberOfDoctors);
		return resultString;
	}
};


class NeonatalUnit : public HospitalDepartment {
private:
	int numberOfMothers;
	int numberOfNewborns;
	double averageGradeNewborns;

public:
	NeonatalUnit(string hName, int nrDocs, int nrM, int nrN, double avg) {
		this->hospitalName = hName;
		this->numberOfDoctors = nrDocs;
		this->numberOfMothers = nrM; 
		this->numberOfNewborns = nrN;
		this->averageGradeNewborns = avg;
	}

	bool isEfficient() override {
		return averageGradeNewborns > 8.5 && numberOfNewborns >= numberOfMothers;
	}

	string toString() override {
		string resultString = "";
		resultString += this->hospitalName;
		resultString += ", ";
		resultString += to_string(this->numberOfDoctors);
		resultString += ", ";
		resultString += to_string(this->numberOfMothers);
		resultString += ", ";
		resultString += to_string(this->numberOfNewborns);
		resultString += ", ";
		resultString += to_string(this->averageGradeNewborns);
		return resultString;
	};
};


class Surgery : public HospitalDepartment {
private:
	int numberOfPatients;

public:
	Surgery(string hName, int nrDocs, int nrP) {
		this->hospitalName = hName;
		this->numberOfDoctors = nrDocs;
		this->numberOfPatients = nrP;
	}

	bool isEfficient() override {
		return numberOfPatients / numberOfDoctors >= 2;
	}

	string toString() override {
		string resultString = "";
		resultString += this->hospitalName;
		resultString += ", ";
		resultString += to_string(this->numberOfDoctors);
		resultString += ", ";
		resultString += to_string(this->numberOfPatients);
		return resultString;
	}
};

/*
class HospitalMonitoring {
private:
	vector<HospitalDepartment> departments;

public:
	HospitalMonitoring() {};

	void addDepartment(HospitalDepartment& d) {
		departments.push_back(d);
	}

	vector<HospitalDepartment> getAllEfficientDepartments() {
		vector<HospitalDepartment> efficientDepartments;
		for (auto department : departments) {
			if (department.isEfficient())
				efficientDepartments.push_back(department);
		}
		return efficientDepartments;
	}
};


int main() {
	HospitalMonitoring monitor;

	HospitalDepartment* d1;
	HospitalDepartment* d2;
	HospitalDepartment* d3;
	HospitalDepartment* d4;

	NeonatalUnit n1("a", 2, 5, 11, 9);
	monitor.addDepartment(n1);

	monitor.addDepartment(NeonatalUnit{ "a", 2, 5, 11, 9 });
	monitor.addDepartment(NeonatalUnit{ "b", 2, 5, 11, 9 });
	monitor.addDepartment(Surgery{ "s", 2, 5 });
	monitor.addDepartment(Surgery{ "ss", 2, 5 });

	vector<HospitalDepartment> dep = monitor.getAllEfficientDepartments();
	cout << "All efficient departments: " << endl;
	for (auto d : dep)
		cout << d.toString() << endl;

	return 0;
}
*/