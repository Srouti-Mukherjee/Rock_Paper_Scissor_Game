#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//here we'll try to write every piece of code inside the function..So that if we have to repeat the code then we simply call the function and that particular piece of code will get repeated.In making functions memory is better utilised.
int you,Computer;   //declaring 2 variables globally;basically name of 2 players;Computer is the opposite player.For Computer we'll have to assign random number.Bcz we don't know what opposite player will select rock,paper or scissor.
//First we need the menu to understand.This is for the user,and for the computer we'll automatically assign.
int menu()    //To this function we'll return the value of choice
{
	int choice;
	printf("\n1.Select Rock");
	printf("\n2.Select Paper");
	printf("\n3.Select scissor");
	printf("\n4.Exit");   //making 1 more option of exit as we'll make infinite loop.
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	return(choice);  //that is why we've written the function type as int
}
//Assigning random numbers to the opposite player.So creating another function of name setup()
void setup()
{
	label:
	//assigning random nos. to the Computer(opposite player)
	Computer=rand()%4;   //calling the rand function for random numbers;rand function returns a very large number and if we do modulus of that number with 4 then we'll get remainder between 0-3(always).But we don't want 0.so what we'll do?
	if(Computer==0)
	goto label;     //goto is used to transfer the control where the label will be written.The goto statement is a jump statement which is sometimes also referred to as unconditional jump statement. The goto statement can be used to jump from anywhere to anywhere within a function.
//Syntax:

//Syntax1      |   Syntax2
//----------------------------
//goto label;  |    label:  
//.            |    .
//.            |    .
//.            |    .
//label:       |    goto label;
	//the choices made by the user must go to the variable named you.So I'll call the menu().
	
	you=menu();      //so automatically the choices made by the user will go to you named variable.
}
void MakeLogic()         //to check you and computer value.
{
	//there will be many combinations 1,1;1,2;1,3;2,1;2,2;2,3; etc.We'll not use here if-else bcz if-else is used for taking multiple decision.The better option here is switch.
	switch(you)    //we can write either computer or you.Here we've written you.
	{
		//3 cases will be here as only 3 possibilities are here for the user.
		case 1:            //you value must be rock;you=rock
			//make combination for 1,1;1,2;1,3
			{
			if (Computer==1)     ///you=rock,Computer=rock
			{
			printf("\nGame Draw");
			printf("\nyou=rock\nComputer=rock");
		}
		else if(Computer==2)       ////you=rock,Computer=paper
		{
			printf("\nComputer won.");
			printf("\nyou=rock\nComputer=paper");
		}
		else              ///you=rock,Computer=scissor
		{
			printf("\nYou won.");
			printf("\nyou=rock\nComputer=scissor");
		}
		break;
	}
		case 2:         //you=paper
		{
			if (Computer==1)     ///you=paper,Computer=rock
			{
			printf("\nYou won.");
			printf("\nyou=paper\nComputer=rock");
		}
		else if(Computer==2)       ////you=paper,Computer=paper
		{
			printf("\nGame draw.");
			printf("\nyou=paper\nComputer=paper");
		}
		else              ///you=paper,Computer=scissor
		{
			printf("\nComputer won.");
			printf("\nyou=paper\nComputer=scissor");
		}
		break;
	}
			
		case 3:        ///you=scissor
			{
			if (Computer==1)     ///you=scissor,Computer=rock
			{
			printf("\nComputer won.");
			printf("\nyou=scissor\nComputer=rock");
		}
		else if(Computer==2)       ////you=scissor,Computer=paper
		{
			printf("\nYou won.");
			printf("\nyou=scissor\nComputer=paper");
		}
		else              ///you=scissor,Computer=scissor
		{
			printf("\nGame draw.");
			printf("\nyou=scissor\nComputer=scissor");
		}
		break;
	}
		//case 4 for exit
		case 4:
			exit(0);  //to pass 0 in the exit function means I myself is terminating the game.
		default:
			printf("\nInvalid choice.");
	}
}
int main(){
	//No need to call here the menu().We'll call here only the setup() and that will itself call the menu().
	while(1)     //to repeat the game many time until user presses 4.
	{
	//system("cls");  //when 2nd time this come will be executed previous result will be deleted so that the user don't get confused.It clears the output screen of the program.In compilers like- Turbo C or Borland C, the statement clrscr() clears the output screen. But, in GNU based MinGW compilers the clrscr() statement is not supported because, clrscr () is not a part of the standard C library. So, to achieve this task in MinGW compilers, we use the system (“cls") statement. Anything inside the brackets of system () is directly sent to the command prompt of Windows. So, if you write system (“cls"), the program sends the cls command to Windows command prompt directly. And in response to the cls command, the Windows command prompt clears the output screen of the program.
	setup();
	MakeLogic();
	//getch();    //so that until we enter any character the while loop will not run.So we'll be able to see the output.
}
return 0;
}
