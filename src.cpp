/*
* DATE       : 25-10-2021
* COURSE     : PROGRAMMING QUEST (CO2210)
* TITLE      : QUEST 05- MONTHLY PAYMENT OF BANK LOAN
* AUTHOR     : MADHUWANTHA A.P.
* INDEX NO   : 19/ENG/121
*/
#include <iostream>
#include <string>   //string headre
#include <iomanip>  //for setprecision
#include <vector>   //vector header
#include <math.h> //for power function
#include <fstream>  //for file straming(write into the report)
using namespace std;

//store details of each type of loan into structs
struct LoanDetails
{
    string type;
    int minAge;
    int maxAge;
    float monthlyIncome;
    float maxAmmount;
    int maxRepayPeriod;
    float annualIR;
};
//define structs into loan types
LoanDetails vehicle, housing, education, seniorCitizen, personal1, personal2;
//define vector wich use to store loans one person allowed
vector<LoanDetails> vec;

/*
Function    : setType
Iputs       : char ch
Output      : LoanDetails struct
*/
LoanDetails setType(char ch)
{
    LoanDetails details;
    switch (ch)
    {   //select the type of loan
        case 'V': details = vehicle;   break;
        case 'H': details = housing;   break;
        case 'E': details = education;   break;
        case 'S': details = seniorCitizen;   break;
        case 'O': details = personal1;   break;
        case 'T': details = personal2;   break;
        default: cout << "Your Input Is Worng :! "; exit(0);    //exit from the programm when wrong type included
    }
    return details;
}

/*
Function    : showDetails
Iputs       : char ch
Output      : N/A
*/
void showDetails(char ch)
{   //show the loan details to the customer
    LoanDetails details = setType(ch);
    cout << "\n--------------------------------------------------------\n";
    cout << "Loan Name\t\t\t : " << details.type<<endl;
    cout << "Customer's Age(yrs)\t\t : Between " << details.minAge << " to " << details.maxAge << " years\n";
    cout << "Monthly Income\t\t\t : "<<fixed<<setprecision(2) << details.monthlyIncome << endl;
    cout << "Max Loan Amount\t\t\t : " <<fixed << setprecision(2) << details.maxAmmount << endl;
    cout << "Max Repay Period(in months)\t : " << details.maxRepayPeriod << endl;
    cout << "Anual Interset Rate(%) FIXED\t : " << details.annualIR; 
}

/*
Function    : availableLoans
Iputs       : age, monthlyIncome
Output      : N/A
*/
void availableLoans(int age, float monthlyIncomeOfCus)
{
    //check the condition for a loan
    //if satisfy a condition, then it will add to the vector of which include all the loans have that person
    if(age>=18 && age<=55 && monthlyIncomeOfCus>=45000)
    {
        vec.push_back(vehicle);
        showDetails('V');
    }
    if(age>=25 && age<=55 && monthlyIncomeOfCus>=100000)
    {
        vec.push_back(housing);
        showDetails('H');
    }
    if(age>=25 && age<=35 && monthlyIncomeOfCus>=45000)
    {   
        vec.push_back(education);
        showDetails('E');
    }
    if(age>=60 && monthlyIncomeOfCus>=35000)
    {    
        vec.push_back(seniorCitizen);
        showDetails('S');
    }
    if(age>=30 && age<=55 && monthlyIncomeOfCus>=100000)
    {    
        vec.push_back(personal1);
        showDetails('O');   //O-personal1
    }
    if(age>=30 && age<=55 && monthlyIncomeOfCus>=100000)
    {    
        vec.push_back(personal2);
        showDetails('T');   //T-personal2
    }
}

/*
Function    : main
Iputs       : N/A
Output      : 0 
*/
int main()
{
    //add details for Vehicle loan
    vehicle.type = "Vehicle";
    vehicle.minAge = 18;
    vehicle.maxAge = 55;
    vehicle.monthlyIncome = 45000;
    vehicle.maxAmmount = 1000000.00;
    vehicle.maxRepayPeriod = 60;
    vehicle.annualIR = 14;
    //add details for Housing loan
    housing.type = "Housing";
    housing.minAge = 25;
    housing.maxAge = 55;
    housing.monthlyIncome = 100000;
    housing.maxAmmount = 2500000.00;
    housing.maxRepayPeriod = 60;
    housing.annualIR = 8;
    //add details for Education loan
    education.type = "Education";
    education.minAge = 25;
    education.maxAge = 35;
    education.monthlyIncome = 45000;
    education.maxAmmount = 1500000.00;
    education.maxRepayPeriod = 84;  //assume here 84 not 284
    education.annualIR = 6;
    //add details for Senior Citizen loan
    seniorCitizen.type = "Senior Citizen";
    seniorCitizen.minAge = 60;
    seniorCitizen.monthlyIncome = 35000;
    seniorCitizen.maxAmmount = 500000.00;
    seniorCitizen.maxRepayPeriod = 60;
    seniorCitizen.annualIR = 4.5;
    //add details for personal loan type 1
    personal1.type = "Personal";
    personal1.minAge = 30;
    personal1.maxAge = 60;
    personal1.monthlyIncome = 1000000;
    personal1.maxAmmount = 2000000.00;
    personal1.maxRepayPeriod = 60;
    personal1.annualIR = 14.5;
    //add details for personal loan type 2
    personal2.type = "Personal";
    personal2.minAge = 30;
    personal2.maxAge = 60;
    personal2.monthlyIncome = 1000000;
    personal2.maxAmmount = 3000000.00;
    personal2.maxRepayPeriod = 84;
    personal2.annualIR = 16.2;

    ofstream report;    //to write

    string name;
    int age;
    float monthlyIncomeOfCus;
    //customer enter details
    cout << "Please Enter your Name\t\t : ";
    cin >> name;
    report.open(name +".txt",fstream::app); //make a report with customer name
    report << "\nI. Name Of The Customer : " << name<<endl;  //write the name first
    cout << "Enter Your Age\t\t\t : ";
    cin >> age;
    cout << "Enter Your Monthly Income\t : ";
    cin >> monthlyIncomeOfCus;

    availableLoans(age, monthlyIncomeOfCus);
    cout << "\n--------------------------------------------------------\n";
    //select a loan from them
    char typeOfLoan='y';
    bool flag;
    LoanDetails loan;
    cout << "\n\nEnter The Loan Name To Select A loan : \n";
    cout << "V-vehicle, H-Housing, E-Education, S-Senior Citizen, P-Person\n";
    for (int i = 0; i < vec.size(); i++)
    {   //go throug the available loans, those are element of the vector vec
        cout << vec[i].type<<endl;
        cout << "If You want To Select This Loan Type Press 'y' And Hit Enter.\n";
        cout << "If You Want To See Next Please Enter 'n'\n";
        
        cin >> typeOfLoan;
        typeOfLoan = tolower(typeOfLoan);
        if(typeOfLoan=='y')
        {    
            loan = vec[i];
            flag = true;    //if select loan then flag will be true
            break;
        }
        else if(typeOfLoan=='n')
            continue;   //prceed next
        else
            i--;    //input is not both of them then give a chance to input again
        
    }
    if(!flag) 
    {
        cout << "You Did Not Selected Any Loan.\nprogramme May End Now.\n" << endl;
        exit(0);
    }          
    cout << "You Selected : " << loan.type << " Loan" << endl;
    report << "II. Selected Loan : " << loan.type<<" Loan" << endl;  //write the type of loan into the report
    report << "III. Maximum Repay Period Allowed : "<<fixed<<setprecision(2) << loan.maxRepayPeriod << endl;    //write the maximum repay period allowed
    report << "IV. Annual Interest Rate : " << loan.annualIR << endl;   //write annual interest rate into the report

    float amountOfLoan=1000000;
    int period=60;
    do
    {
        cout << "Enter The Ammount You Want To Borrow : ";
        cin >> amountOfLoan;
        cout << "Enter The Repay Period You Wish : ";
        cin >> period;
        // checking for is values(ammount and period) are allowed
        if(amountOfLoan > loan.maxAmmount)
            cout << "Ammount of Money You Wish To Borrow Is Greater Than Maximum Value Of This Loan Type...Try Again.\n";
        if(period > loan.maxRepayPeriod)
            cout << "Period Of Time To Payback Is Greater Than Maximum Value Of This Loan Type...Try Again.\n";
    }while (amountOfLoan > loan.maxAmmount || period > loan.maxRepayPeriod);
    report << "V. Requested Loan Ammount: " << amountOfLoan<<endl;  //write requeste ammount of loan and repay period
    report << "   Requested Period For Repay: " << period <<endl;

    //monthly repay calculation
    int n = period;
    float ir = loan.annualIR/1200.0;
    float D = float(pow((1 + ir), n) - 1) / (ir * pow((1 + ir), n));
    float totalMonthlyPayment = amountOfLoan / D;

    //calculate other remaining ammounts
    float remainingAmmount, interestAmmount, repaidAmmount, totalAmmountCustomerPaid;

    vector<float> reAmm;
    vector<float> intRa;
    vector<float> rePayAmm;

    remainingAmmount = amountOfLoan;    //initial remaining loan
    reAmm.push_back(remainingAmmount);
    interestAmmount = remainingAmmount * ir;    //interest for this month
    intRa.push_back(interestAmmount);
    repaidAmmount = totalMonthlyPayment - interestAmmount;  //repaid loan ammount for this month
    rePayAmm.push_back(repaidAmmount);
    remainingAmmount -= repaidAmmount;  //remaining loan forn next month
    reAmm.push_back(remainingAmmount);

    //loop start
    while (interestAmmount >= 0 && remainingAmmount >= 0)
    {
        interestAmmount = remainingAmmount * ir;    //interest for this month
        intRa.push_back(interestAmmount);
        repaidAmmount = totalMonthlyPayment - interestAmmount;  //repaid loan ammount for this month
        rePayAmm.push_back(repaidAmmount);
        remainingAmmount -= repaidAmmount;  //remaining loan forn next month
        if(remainingAmmount>=0)
            reAmm.push_back(remainingAmmount);
    }
    report << "VI. Table Od Payment : " << endl;
    cout << "\nMonth\t Remaining Loan Ammount\t\t Interest\t\t Repaid Loan Ammount\n";
    //write the table into the report
    report << "\nMonth\t | Remaining Loan Ammount | Interest\t\t | Repaid Loan Ammount\n";
    cout << "\n--------------------------------------------------------------------\n";
    report << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < reAmm.size(); i++)
    {
        cout << i+1<<"\t "<<reAmm[i] << "\t\t\t  " << intRa[i] << "\t\t\t " << rePayAmm[i]<<endl;
        report << i+1<<"\t\t | "<<reAmm[i] << " \t\t\t\t | " << intRa[i] << " \t\t\t | " << rePayAmm[i]<<endl;
    }
    report << "-------------------------------------------------------------------------------\n";

    totalAmmountCustomerPaid = period * totalMonthlyPayment;
    float totalInterestEarned = totalAmmountCustomerPaid - amountOfLoan;
    cout << "Total Ammount Of Money Paid By The Customer At The End Of The Loan Repay Period : \n" << totalAmmountCustomerPaid << endl;
    cout << "Total Ammount Of Interset Enered By The Bank : " << totalInterestEarned << endl;
    //wite total ammount Of Money Paid By The Customer At The End Of The Loan Repay Period
    report << "VII. Total Ammount Of Money Paid By The Customer At The End Of The Loan Repay Period : \n     " << totalAmmountCustomerPaid << endl;
    report << "     Total Ammount Of Interset Enered By The Bank : " << totalInterestEarned << endl;


    cout << "\nEnd Of The Programme\n";
    return 0;
}

