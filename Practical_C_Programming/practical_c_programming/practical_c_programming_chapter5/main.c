#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//chapter 5 end exercises

double CentigradeToFahrenheit(double C){
    return (9/(double)5)*C + 32;
}

float SphereVolume(float r){
    return 4/(float)3*(float)3.1415*r*r*r;
}

float rectanglePerimeter(float height, float width){
    return(2*(width+height));
}

double kmhTomph(double km){
    return km*0.6213712;
}

int hoursTomin(double time){
    int time2=(int) time*10;
    return time2/10*60+(int)(time2%10/(float)10)*60;
}

double minToHours(int min){
    double result = 0;
    result += min/60;

    result+= (min-min/60*60)/(double)60;

    return result;
}


//Capter 6 exercieses
//find the square of the distance beteen 2 points
double findDistance2Points2D(int X1,int Y1,int X2, int Y2){
    double result = sqrt((Y2-Y1)*(Y2-Y1)+(X2-X1)*(X2-X1));
    return result;
}

void printGradeValue(int percentage){
    if(percentage>=0&&percentage<=60)
        printf("F\n");
    else if(percentage>=61&&percentage<=70)
        printf("F\n");
    else if(percentage>=71&&percentage<=80)
        printf("F\n");
    else if(percentage>=81&&percentage<=90)
        printf("F\n");
    else if(percentage>=91&&percentage<=100)
        printf("F\n");
}

void printGrade2ndLetter(int percentage){
    switch(percentage%10){
    case 1:case 2:case 3:
        printf("-\n");
        break;
    case 4:case 5: case 6:
        printf(" \n");
        break;
    default:
        printf("+\n");
        break;
    }
}

//6-4 calcular centimos para entregar num valor menor que 1€
void printTrocos(float value){
    unsigned short int m50,m20,m10,m5,m2,m1,total;
        if(value >1||value < 0)
                return;
        else {
            total=(unsigned short int)value*100;
            m50=0;
            m20=0;
            m10=0;
            m5=0;
            m2=0;
            m1=0;

            m50=total/50;
            total-=m50;

        }




}


int main()
{
    printf("Hello World!\n");

    double test = CentigradeToFahrenheit(50);

    printf("%lf\n",test);


    printf("Time %.2lf %d\n",1.5,hoursTomin(1.5));

    printf("Time %.2lf %d\n",minToHours(90),90);

    printf("Distance: %.2lf\n",findDistance2Points2D(2,3,2,10));

    return 0;
}
