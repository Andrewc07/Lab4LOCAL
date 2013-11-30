#include "PhysicalTest.h"
#include "PatientTest.h"



int main(void)
{
	PartialPatient x;
	x.test();
	x.show();
	x.comment();
	x.show();
	system("PAUSE");
}

bool PhysicalTest::istesttaken(){
	return testtaken;
}

void BloodPressure::show(){
	if(testtaken==0){
		cout<<endl<<"Blood Pressure: Test not yet taken"<<endl;
	}
	else if(testtaken==1){
	cout<<"Blood Pressure: "<<SystolicPressure<<"/"<<DiastolicPressure<<endl;
	cout<<"\nBlood Pressure Comment: \n";
	cout<<comment<<endl;
	}
}

void BloodPressure::taketest()
{
	cout<<"Enter Systolic Pressure: "<<endl;
	cin>>SystolicPressure;
	cout<<"Enter Diastolic Pressure: "<<endl;
	cin>>DiastolicPressure;
	testtaken=1;
}

void BloodPressure::checkhealthy(){
	if(testtaken==1){
		if(SystolicPressure<90 && DiastolicPressure<60){
			cout<<"Hypotension"<<endl;
			normal=0;
		}
		if(90<SystolicPressure&& SystolicPressure<119 && 60<DiastolicPressure&& DiastolicPressure<79){
			cout<<"Desired"<<endl;
			normal=1;
		}
		if(120<SystolicPressure&& SystolicPressure<139 && 80<DiastolicPressure&& DiastolicPressure<89){
			cout<<"Prehypertension"<<endl;
			normal=0;
		}
		if(140<SystolicPressure&& SystolicPressure<159 && 90<DiastolicPressure&& DiastolicPressure<99){
			cout<<"Stage 1 Hypertension"<<endl;
			normal=0;
		}
		if(160<SystolicPressure&& SystolicPressure<179 && 100<DiastolicPressure&& DiastolicPressure<109){
			cout<<"Stage 2 Hypertension"<<endl;
			normal=0;
		}
		if(SystolicPressure>180 && DiastolicPressure>110){
			cout<<"Hypertensive Emergency"<<endl;
			normal=0;
		}
	}
}


void BloodPressure::addcomment(){
	if(testtaken==1){
		cout<<"Blood Pressure comment: \n";
		string temp;
		temp= writecomment();
		comment.append(temp);
		time_t timer;
		struct tm * timeinfo;
		time(&timer);
		timeinfo= localtime(&timer);
		comment.append(asctime(timeinfo));
	}
}

void Vitals::addcomment(){
	if(testtaken==1){
		cout<<"Vitals comment: \n";
		string temp;
		temp= writecomment();
		comment.append(temp);
		time_t timer;
		struct tm * timeinfo;
		time(&timer);
		timeinfo= localtime(&timer);
		comment.append(asctime(timeinfo));
	}
}

void Vitals::taketest()
{
	cout<<"Enter Pulse: "<<endl;
	cin>>pulse;
	cout<<"Enter Respiratory Rate: "<<endl;
	cin>>respiratory;
	testtaken=1;
}

void Vitals::checkhealthy()
{
	if(testtaken==1){
		if(pulse<60){
			cout<<"Lower than normal heart rate"<<endl;
			normal=0;
		}
		else if(pulse>120){
			cout<<"Higher than normal heart rate"<<endl;
			normal=0;
		}
		else if(pulse<120 && pulse>60){
			cout<<"Normal heart rate"<<endl;
			normal=1;
		}

		if(respiratory<12){
			cout<<"Lower than normal respirations per minute"<<endl;
			normal=0;
		}
		else if(respiratory>20){
			cout<<"Higher than normal respirations per minute"<<endl;
			normal=0;
		}
		else if(respiratory<20 && pulse>12){
			cout<<"Normal respirations per minute"<<endl;
			normal=1;
		
		}
	}
}

void Vitals::show()
{
	if(testtaken==0){
		cout<<endl<<"Vitals: Test not yet taken"<<endl<<endl;
	}
	else if(testtaken==1){
		cout<<"Vitals: "<<endl<<pulse<<" beats per minute"<<endl<<respiratory<<" breaths per minute"<<endl;
		cout<<"\nVitals Comment: \n";
		cout<<comment<<endl;
	}
}

void Urinalysis::addcomment(){
	if(testtaken==1){
		cout<<"Urinalysis comment: \n";
		string temp;
		temp= writecomment();
		comment.append(temp);
		time_t timer;
		struct tm * timeinfo;
		time(&timer);
		timeinfo= localtime(&timer);
		comment.append(asctime(timeinfo));
	}
}

void Urinalysis::taketest()
{
	cout<<"Enter Urinary Calicum: "<<endl;
	cin>>UrinaryCalcium;
	cout<<"Enter Sodium: "<<endl;
	cin>>Sodium;
	testtaken=1;
}

void Urinalysis::checkhealthy()
{
	if(testtaken==1){
		if(Sodium>300){
			cout<<"Sodium levels are high"<<endl;
			normal=0;
		}
		else if(Sodium<150){
			cout<<"Sodium levels are low"<<endl;
			normal=0;
		}
		else if(Sodium<300 && Sodium>150){
			cout<<"Sodium levels are normal"<<endl;
			normal=1;
		
		}

		if(UrinaryCalcium>20){
			cout<<"Urinary Calcium levels are high"<<endl;
			normal=0;
		}
		else if(UrinaryCalcium<15){
			cout<<"Urinary Calcium levels are low"<<endl;
			normal=0;
		}
		else if(UrinaryCalcium<20 && UrinaryCalcium>15){
			cout<<"Urinary Calcium levels are normal"<<endl;
			normal=1;
		}
	}
}



void Urinalysis::show()
{
	if(testtaken==0){
		cout<<endl<<"Urinalysis: Test not yet taken"<<endl<<endl;
	}
	else if(testtaken==1){
		cout<<"Urinalysis: "<<endl;
		cout<<"Calcium: "<<UrinaryCalcium<<" mmol/24hours"<<endl<<"Sodium: "<<Sodium<<" mmol/24hours"<<endl;
		cout<<"\nUrinalysis Comment: \n";
		cout<<comment<<endl;
	}
}

PhysicalTest::PhysicalTest(){
	testtaken=0;
}

string PhysicalTest::writecomment(){

        string line;
        string word;

        cout<<"Type in the desire comments and when finished enter a return then type 'done'\n";

        while(word!="done")
		{
                getline (cin, word);
				if(word=="done")break;
                line.append(word);
				line.append("\n");
        }
        return line;
}