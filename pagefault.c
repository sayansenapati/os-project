#include <stdio.h>
#include <stdlib.h>
double fR();
void input(void);

double PageUnmodified;
double PageModified;
double mATime_nsec;
float PaModPages;
double efAT_nsec;
double d;
double pageUnmodified_nsec;
double pageModifie_nsec;
double rPModified;
	

int main(){
	int i;
	
	do{
	printf("*****************************************\n");
	printf("Select anyy option: \n");
	printf("1.Find Max Acceptable Page-Fault Rate\n");
	printf("2.Exit\n");
	printf("Choice : ");
	scanf("%d",&i);
	switch(i){
		case 1:input();
		       break;
		case 2:exit(0);
	}
	printf("\n\n");

}
while(i<3);
}
void input(){
	
	
	printf("\nEnter time to service a Page-Fault [Empty Page or Unmodified Replaced Page]: ");
	scanf("%lf",&PageUnmodified);
	printf("Enter time to Service a Page-Fault [Modified Replaced Page]: ");
	scanf("%lf",&PageModified);
	printf("Enter Memory Access Time: ");
	scanf("%lf",&mATime_nsec);
	printf("Enter Percentage for the time,the page to be replaced is modified [0-100] : ");
	scanf("%f",&PaModPages);
	printf("Enter Effective Access time: ");
	scanf("%lf",&efAT_nsec);

	printf("\n\n\n");
	pageUnmodified_nsec = (PageUnmodified*1000000);  
	pageModifie_nsec = (PageModified*1000000);                    
	rPModified = (PaModPages/100);                            
	printf("Data for calculating Page-Fault Rate : \n\n");
	printf("Time taken to service a Page-Fault for Unmodified Replaced Page = %lf \n",pageUnmodified_nsec);
	printf("Time taken to service a Page-Fault for Modified Replaced Page = %lf \n",pageModifie_nsec);
	printf("Time taken for Memory Acess= %lf\n",mATime_nsec);
	printf("Value of Page to be replaced = %f\n",rPModified);
	printf("Time taken for Effective Access = %lf\n",efAT_nsec);
    d = fR(pageUnmodified_nsec,pageModifie_nsec,mATime_nsec,rPModified,efAT_nsec);
	printf("\nFor Access Time Maximum Acceptable Page-Fault rate = %.2le",d);

}

double fR(double emptyUnmodifiedP,double mPage,double mATime ,double mTPages,double eATime){
	double num,deno;
	double pF;
	num = eATime - mATime ;
    deno = (1-mTPages)*emptyUnmodifiedP + mTPages*mPage -mATime ;

	pF = num/deno;
	return pF;
}
