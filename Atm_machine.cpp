// Atm_machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include "windows.h"

#define dollar_1 1
#define dollar_5 5
#define dollar_10 10
#define dollar_20 20

int welcome(int user_or_not); //function for welcoming user

int _tmain(int argc, _TCHAR* argv[])
{
	int user_or_not, user_answer, banker_response, total_bank_money, random1, user_withdrawal, user_withdrawal_backup; //variable declaration
	int current_user_balance, user_deposit, one_dollar_restock, five_dollar_restock, ten_dollar_restock, twenty_dollar_restock;
	int money[4] = { 10, 10, 10, 10 };
	current_user_balance = 500;
	user_or_not = 0;
	banker_response == 0;
	welcome_user: user_or_not = welcome(user_or_not); //function call
	
	if (user_or_not == 0) //USER ACCOUNT
	{
		printf("WELCOME AKSHAT GARG/user\n\n");
		printf("Your current balance is: %i\n\n", current_user_balance);
		printf("Would you like to deposit or withdraw money\n\n");
		printf("Press 0 to deposit and 1 to withdraw\n\n");
		scanf_s("%i", &user_answer);
		if (user_answer == 0) //USER DEPOSIT
		{
			user_depos: printf("You have chosen to deposit money\n\n");
			printf("Type in the amount of money you would like to deposit and that amount will be added to your balance\n\n"); 
			scanf_s("%i", &user_deposit);
			if (user_deposit <= 0) //IF AMOUNT IS LESS THAN USER
			{
				printf("The value that you provided was equal to zero or negative please try again\n\n");
				Sleep(5000);
				system("cls");
				goto welcome_user;
			}
			else
			{
				current_user_balance = current_user_balance + user_deposit;
				printf("This is your current balance: %i\n\n", current_user_balance);
				printf("Thank you for your business, bye-bye\n\n");
				Sleep(2000);
				system("cls");
				goto welcome_user;
			}
		}
		if (user_answer == 1) 
		{
			user_withdraw: printf("You have chosen to withdraw money\n\n");
			printf("Type in the amount of money you would like to withdraw and that amount will be subtracted from your balance\n\n");
			scanf_s("%i", &user_withdrawal);
			user_withdrawal_backup = user_withdrawal;
			current_user_balance = current_user_balance - user_withdrawal;
			if (user_withdrawal <= 0)
			{
				printf("Your value provided was negative or zero, please try again\n\n");
				current_user_balance = current_user_balance + user_withdrawal;
				Sleep(2000);
				system("cls");
				goto welcome_user;
			}
			else if (current_user_balance < 0)
			{
				printf("Sorry my bank does not loan any money\n\n");
				printf("Your balance will not be changed\n\n");
				current_user_balance = current_user_balance + user_withdrawal;
				Sleep(2000);
				system("cls");
			}
			else
			{
				if ((user_withdrawal / dollar_20) > 0)
				{
					if (money[3] <= (user_withdrawal / dollar_20))
					{
						printf("Not enough twenty dollar bills\n\n");
						current_user_balance = current_user_balance + user_withdrawal;
					}
					else
					{
						money[3] = money[3] - (user_withdrawal / dollar_20);
						printf("Your will receive %i 20 dollar bills\n\n", user_withdrawal / dollar_20);
						user_withdrawal = user_withdrawal - ((user_withdrawal / dollar_20) * dollar_20);
					}
				}
				if ((user_withdrawal / dollar_10) > 0)
				{
					if (money[2] <= (user_withdrawal / dollar_10))
					{
						printf("Not enough ten dollar bills\n\n");
						current_user_balance = current_user_balance + user_withdrawal;
					}
					else
					{
						money[2] = money[2] - (user_withdrawal / dollar_10);
						printf("Your will receive %i 10 dollar bills\n\n", user_withdrawal / dollar_10);
						user_withdrawal = user_withdrawal - ((user_withdrawal / dollar_10) * dollar_10);
					}
				}
				if ((user_withdrawal / dollar_5) > 0)
				{
					if (money[1] <= (user_withdrawal / dollar_5))
					{
						printf("Not enough five dollar bills\n\n");
						current_user_balance = current_user_balance + user_withdrawal;
					}
					else
					{
						money[1] = money[1] - (user_withdrawal / dollar_5);
						printf("Your will receive %i 5 dollar bills\n\n", user_withdrawal / dollar_5);
						user_withdrawal = user_withdrawal - ((user_withdrawal / dollar_5) * dollar_5);
					}
				}
				if ((user_withdrawal / dollar_1) > 0)
				{
					if (money[0] <= (user_withdrawal / dollar_1))
					{
						printf("Not enough one dollar bills\n\n");
						current_user_balance = current_user_balance + user_withdrawal;
					}
					else
					{
						money[0] = money[0] - (user_withdrawal / dollar_1);
						printf("Your will receive %i 1 dollar bills\n\n", user_withdrawal / dollar_1);
						user_withdrawal = user_withdrawal - ((user_withdrawal / dollar_1) * dollar_1);
					}
				}
				Sleep(5000);
				system("cls");
			}
			printf("This is your current balance: %i\n\n", current_user_balance);
			printf("Thank you for your business, bye-bye\n\n");
			Sleep(2000);
			system("cls");
			goto welcome_user;
			}
		}
	else if (user_or_not == 1) //BANKER ACCOUNT
	{
		banker_welcome: printf("WELCOME ARNAV GARG/BANKER\n\n");
		printf("There is currently one user and his/her balance is: %i\n\n", current_user_balance);
		printf("Type 0 to return to the user welcoming screen or type 1 to view the amount of each bill\n\n");
		scanf_s("%i", &banker_response);
		if (banker_response == 0)
		{
			printf("BYE-BYE");
			system("cls");
			goto welcome_user;
		}
		else if (banker_response == 1)
		{
			printf("There are currently %i 1 dollar bills\n\n",money[0]);
			printf("There are currently %i 5 dollar bills\n\n", money[1]);
			printf("There are currently %i 10 dollar bills\n\n", money[2]);
			printf("There are currently %i 20 dollar bills\n\n", money[3]);
			if (money[0] < 5)
			{
				printf("Please restock on one dollar bills\n\n");
				printf("To restock on one dollar bills type in the number of bills to restock");
				scanf_s("%i", &one_dollar_restock);
				money[1] = money[1] + one_dollar_restock;
				printf("\n\nYou have successfully restocked\n\n");
			}
			if (money[1] < 5)
			{
				printf("Please restock on five dollar bills\n\n");
				printf("To restock on five dollar bills type in the number of bills to restock");
				scanf_s("%i", &five_dollar_restock);
				money[1] = money[1] + five_dollar_restock;
				printf("\n\nYou have successfully restocked\n\n");
			}
			if (money[2] < 5)
			{
				printf("Please restock on ten dollar bills\n\n");
				printf("To restock on ten dollar bills type in the number of bills to restock");
				scanf_s("%i", &ten_dollar_restock);
				money[2] = money[2] + ten_dollar_restock;
				printf("\n\nYou have successfully restocked\n\n");
			}
			if (money[3] < 5)
			{
				printf("Please restock on twenty dollar bills\n\n");
				printf("To restock on twenty dollar bills type in the number of bills to restock");
				scanf_s("%i", &twenty_dollar_restock);
				money[3] = money[3] + twenty_dollar_restock;
				printf("\n\nYou have successfully restocked\n\n");
			}
		}
		total_bank_money = (money[0] * 1) + (money[1] * 5) + (money[2] * 10) + (money[2] * 20);
		printf("The total amount of money is: %i\n\n", total_bank_money + current_user_balance);
		printf("Type in any number to continue: ");
		scanf_s("%i", &random1);
		system("cls");
		goto banker_welcome;
	}

	else if (user_or_not == 2)
	{
		printf("Sorry you are not a recognized, try again\n\n");
		Sleep(5000);
		system("cls");
		goto welcome_user;
	}
}

int welcome(int user)
{
	char bank_username[10], bank_password[10];
	
	printf("Hello, welcome to the Auto-Teller Machine(ATM)\n\n");
	printf("Please type in your bank information, your username and password\n\n");
	printf("Username:");
	scanf_s("%9s", bank_username, 10);
	printf("\n\nPassword:");
	scanf_s("%9s", bank_password, 10);
	printf("\n\nYour username is: %s\n\n", bank_username);
	printf("Your password is: %s\n\n", bank_password);
	printf("VERIFYING YOUR INFORMATION. . .\n\n");
	Sleep(2000);
	system("cls");
	if (strcmp(bank_username,"akshatg") == 0 && strcmp(bank_password, "user") == 0)
	{
		return 0;
	}
	if (strcmp(bank_username,"arnavg") == 0 && strcmp(bank_password, "banker") == 0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

