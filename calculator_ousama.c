#include <stdio.h>
float add(char operation,float x, float y);
float substract(char operation,float x, float y);
float multiply(char operation,float x, float y);
float devide(char operation,float x, float y);

int main(void){
	float x,y,result = 0;
	char operation;
	printf("enter the operation, exemple : +,-,*,/ : ");
	scanf("%c",&operation);
	printf("Enter frist the operand : ");
	scanf("%f",&x);
	printf("Enter second  operand : ");
	scanf("%f",&y);
	switch (operation)
	{
	case '+':
		result = add(operation,x,y);
		break;
	case '-':
		result = substract(operation,x,y);
		break;
	case '*':
		result = multiply(operation,x,y);
		break;
	case '/':
		result = devide(operation,x,y);
		break;
	default:
		break;
	}
	if (operation == '/' && y == 0)
		printf("Error, can't devide by 0\n");
	else
		printf("%.2f%c%.2f = %.2f\n",x,operation,y,result);
	return(0);
}
float add(char operation,float x,float y){
	return(x+y);
}
float substract(char operation,float x,float y){
	return(x-y);
}
float multiply(char operation,float x,float y){
	return(x*y);
}
float devide(char operation,float x,float y){
	return(x/y);
}
