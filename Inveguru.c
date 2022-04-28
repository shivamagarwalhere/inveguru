#include <stdio.h>
#include<math.h>
int npv();
int irr();
int pi();
int pp();

int main()
{
    int choice;
    printf("Welcome to INVEGURU\nthe new age investment guide\n");
    printf("***********************************\n");
    printf("What do you want to do today?");
    printf("\n1. Calculate Net Present Value\n2. Calculate Internal Rate of Return\n3. Find Profitability Index\n4. Find Payback Period\n");
    printf("***********************************\n Enter your choice: ");
    scanf("%d", &choice);
    if (choice==1)
    {
        npv();
    }
    else if (choice==2)
    {
        irr();
    }
    else if (choice==3)
    {
        pi();
    }
    else if (choice==4)
    {
        pp();
    }
    else
    {
        printf("Invalid Choice");
    }
    printf("\n***********************************\n");
    printf("Thankyou for using INVEGURU");
    return 0;
}

int npv()
{
    int out, num; ///out: cash outflow, num: number of years
    float dr, pv, drr, inf, npv; //dr: discount rate, pv: present value, drr: discount rate reduced, inf:net cash inflow(pv), npv=net present value
    inf=0;
    printf("Enter total money invested today:");
    scanf("%d", &out);
    printf("Enter number of years:");
    scanf("%d",&num);
    int fva[num]; //array for future values of all inflows
    float pva[num]; //array for present values of all inflows
    printf("Enter Discount Rate:");
    scanf("%f",&dr);
    drr=dr/100; //reducing discount rate
    for(int i=1;i<=num;i++) //taking value for each year
    {
        int fve;
        float pve;
        printf("Enter the amount to be recieved in Year %d:",i);
        scanf("%d",&fve);
        fva[i-1]=fve; //adding the value to the array
        pve=fve/(pow((1+drr),i)); //calculating present value of that year
        printf("The Present Value of Year %d is : %.2f\n",i,pve);
        pva[i-1]=pve; //adding pv to array
        inf+=pve; //adding all pvs together to find total inflow
    }
    npv=inf-out;
    printf("\n***********************************\n");
    if (npv>0) //criteria for NPV
    printf("Accept the project.");
    else if (npv==0)
    printf("Accept the project considering other intangible benefits.");
    else
    printf("Reject the project.");
    
    return 0;
}

int irr()
{
    int out, num; ///out: cash outflow, num: number of years
    float dr, pv, drr, inf, npv; //dr: discount rate, pv: present value, drr: discount rate reduced, inf:net cash inflow(pv), npv=net present value
    inf=0;
    printf("Enter total money invested today:");
    scanf("%d", &out);
    printf("Enter number of years:");
    scanf("%d",&num);
    int fva[num]; //array for future values of all inflows
    float pva[num]; //array for present values of all inflows
    printf("Enter Discount Rate:");
    scanf("%f",&dr);
    drr=dr/100; //reducing discount rate
    for(int i=1;i<=num;i++) //taking value for each year
    {
        int fve;
        float pve;
        printf("Enter the amount to be recieved in Year %d:",i);
        scanf("%d",&fve);
        fva[i-1]=fve; //adding the value to the array
        pve=fve/(pow((1+drr),i)); //calculating present value of that year
        printf("The Present Value of Year %d is : %.2f\n",i,pve);
        pva[i-1]=pve; //adding pv to array
        inf+=pve; //adding all pvs together to find total inflow
    }
    npv=inf-out;
    printf("\n***********************************\n");
    if (npv>0) //criteria for IRR
    printf("Reduce Discount Rate to get NPV=0");
    else if (npv==0)
    printf("The discount rate is the Internal Return Rate.");
    else
    printf("Increase Discount Rate to get NPV=0");
    
    return 0;
}

int pi()
{
   int out, n; ///out: cash outflow,n: number of years
   float dr,pv,drr,inf,pi;
    inf=0;
    printf("Enter money invested today:");
    scanf("%d",&out);
    printf("Enter number of years invested for:");
    scanf("%d",&n);
    int fva[n]; //array for future values of all inflows
    float pva[n]; //array for present values of all inflows
    printf("Enter Discount Rate:");
    scanf("%f",&dr);
    drr=dr/100; //reducing discount rate
    for(int i=1;i<=n;i++) //taking value for each year
    {
        int fve;
        float pve;
        printf("Enter the amount to be recieved in Year %d:",i);
        scanf("%d",&fve);
        fva[i-1]=fve; //adding the value to the array
        pve=fve/(pow((1+drr),i)); //calculating present value of that year
        printf("The Present Value of Year %d is : %.2f\n",i,pve);
        pva[i-1]=pve; //adding pv to array
        inf+=pve; //adding all pvs together to find total inflow
    }
    pi=inf/out;
    printf("\n***********************************\n");
    if (pi>1) //criteria for PI
    printf("Accept the project");
    else if (pi==1)
    printf("Accept the project considering other intangible benefits");
    else
    printf("Reject the project");

    return 0;
}

int pp()
{
    int num,i,out;//num=number of years,out=total money invested
    int sum=0;
    printf("Enter total money invested:\n");
    scanf("%d",&out);
    printf("Enter number of years:\n");
    scanf("%d",&num);
    int fva[num];//array to store money received in the particular years
    for(i=1;i<=num;i++)//for loop to equate money received to array
    {
        int fve;
        printf("Enter money received in year %d:\n",i);
        scanf("%d",&fve);
        fva[i-1]=fve;
    }
    printf("\n***********************************\n");
    int j;
    for (j=0;j<num;j++)// for loop to calculate sum and copare sum to total money invested
    {
        sum+=fva[j];
        if(sum>=out)
        {
            printf("The payback period is achieved in year %d",j+1);
            break;
        }
    }
    if (j==num && sum<out)
        printf("The Project is not viable.");
    return 0;
}