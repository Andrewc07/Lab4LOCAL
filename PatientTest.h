/* A class called user would log into a system and then have access to a database of patients. The user would have access to specific patient
functions depending on the access level; Radiologist, Nurse, or Doctor. Each user would have a Name and ID associated with them 
and this would be added to the comment in order to personalize the comment */

class PartialPatient{
	BloodPressure bloodpressure;
	Vitals vitals;
	Urinalysis urinalysis;
public:
	void show();
	void test();
	void comment();
};


void PartialPatient::comment(){
	bloodpressure.addcomment();
	vitals.addcomment();
	urinalysis.addcomment();
}


void PartialPatient::show(){
	cout<<"---------------Results---------------\n";
	cout<<endl;
	bloodpressure.show();
	bloodpressure.checkhealthy();
	cout<<endl;
	vitals.show();
	vitals.checkhealthy();
	cout<<endl;
	urinalysis.show();
	urinalysis.checkhealthy();
}

void PartialPatient::test(){
	bloodpressure.taketest();
	vitals.taketest();
	urinalysis.taketest();
}

