#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#define ENTER 13
#define BACKSPACE 8
#define TAB 9
#define SPACE 32
#define MAX_STOCK_ITEMS 100
#pragma warning(disable:4996)

/*========= STAFF MODULE STRUCTURES - VICTOR POW YIE YUAW =========*/
typedef struct {
	char staffID[7], staffName[20], pw[15], pwr[15], position[20], email[25], state[15], department[15];
	double salary, rating;
} Staff;

/*========= MEMBER MODULE STRUCTURES - TAN KAI YUAN =========*/
struct date {
	int year, month, day;
};

struct member {
	char memberID[6];
	char name[50];
	char gender;
	char IC[13];
	char contactNumber[12];
	char uplineID[5];
	char referral[5];
	char email[50];
	struct date dateOfBirth;
	char address[50];
};

/*========= SALES MODULE STRUCTURES - CHONG MING LI =========*/
typedef struct {
	int day;
	int month;
	int year;
}Date;

typedef struct {
	char salesOrderID[6];
	char itemCode[6];
	char memberID[6];
	int salesQuantity;
	double salesPrice;
	double total;
	double taxed;
	double grandTotal;
	double commission;
	char paymentMethod[9];
	Date date;
}Sales;

/*========= STOCK MODULE STRUCTURES - LOW JING HONG =========*/
typedef struct {
	char itemCode[6];
	char itemDesc[30];
	float itemPrice;
	int qtyInStock;
	int minLevel;
	int reorderQty;
	float size;
	char color[20];
	char shoesType[30];
	double shoesWeight;

}Stock;

/*========= STAFF MODULE FUNCTIONS - VICTOR POW YIE YUAW =========*/
// main
void login();
void staffmenu();
// search
void staffsearch();
void searchid();
void searchname();
void searchposition();
void searchstate();
void searchdepartment();
void searchsalary();
// 3 functions
void staffdelete();
void staffdisplay();
void displayForOthers();
void staffreport();
void staffreport2();
void reportStats(char* message1, int* i, char* message2, int* count, char* message3, int* count1, char* message4, double* stotal1,
	char* message5, double* max, char* message6, double* min, char* message7, double* stotal);
// add + validations
void staffadd();
void userDecision(char* decision, char* message);
int valDecision(char* decision);
void staffID(char* id);
int valID(char* id);
void staffName(char* staffName);
int valName(char* staffName);
void password(char* password, char* message);
int valPassword(char* password);
void staffPosition(char* position);
int valPosition(char* position);
void staffEmail(char* email);
int valEmail(char* email);
void stateDepartment(char* state, char* message, char* message2);
int valState(char* state, char* message);
int valDepartment(char* department, char* message);
void salary(double* salary, char* comment);
int valSalary(double* salary);
int valRating(double* rating);
void staffRating(double* update);
// modify
void staffmodify();
void staffmodify2(char id[7]);
void modstaffid(char id[7]);
void modsname(char id[7]);
void modpw(char id[7]);
void modpwr(char id[7]);
void modpos(char id[7]);
void modemail(char id[7]);
void modstate(char id[7]);
void moddepartment(char id[7]);
void modrating(char id[7]);
void modsalary(char id[7]);
// misc 
void staffheader();
void staffFooter();
void searchascii();
void modifyascii();
void reportascii();
void thank();
void loginascii();
void addascii();
void displayascii();
void deleteascii();
void welcomeascii();
void modiftascii();
void positionList();
void loginProcess();
void menuList();
void adminList();
void managerList();
void cashierList();
void promoterList();

/*========= MEMBER MODULE FUNCTIONS - TAN KAI YUAN =========*/
int memberMain();
int menu();
void memberSearch();
int memberAdd();
void memberModify();
void memberDisplay();
void memberDelete();
void memberReport();

int validateMemberID(char* memberID, struct member* members, int numMembers);
char validateName(const char* name);
int validateIC(char* IC, struct member* member, int numMembers);
int validateContactNumber(char* contactNumber, struct member* member, int numMembers);
int validateUplineID(char* uplineID, struct member* member, int numMembers);
int validateReferralID(char* referralID, struct member* member, int numMembers);
int validateEmail(char* email, struct member* member, int numMembers);

/*========= SALES MODULE FUNCTIONS - CHONG MING LI =========*/
//Sales Module Function Declaration

//Main
void salesMain();

//Main Functions
int addSale(Sales* sales, int count, Sales* mSale);
int saleSearch(int choice, Sales* sales, int count, Sales* filtered);
void modifySale(Sales* sales);
void displaySales(Sales* sales, int count);
void deleteSales(Sales* sales);
void salesReport(Sales* sales);
void rearrange(Sales* sales, int totalSales);
void commission(struct member* memRecord, Sales* salesRecord);

//Menus
int salesMenu();
int searchOptions();
int preOptions(char words[50]);
int moreOrLess();
int rearrangeMenu();

//Validations
int menuSelection(int max);
char choiceSelection();
int salesDupe(char compare[6], Sales* read);
int codeValidation(char code[6], char codeChar, char codeChecked[10]);
int integerValidation(char dataName[50], int numberChecked, int min, int max);
int decimalValidation(char dataName[50], double numberChecked, int min, int max);
int paymentValidation(char method[50]);
int dateValidation(int day, int month, int year);
int isExistingMember(char memberID[6], struct member* memRecord, int totalMembers);
int isExistingItem(char itemCode[6], Stock* stkRecord, int totalStock);
int isMinimumLevel(char itemCode[6], Stock* stkRecord, int totalStock);
int checkAvailableStock(int quantity, char itemCode[6], Stock* stkRecord, int totalStock);

//Files
void appendSalesFile(Sales* writeSales, int count);
int readSalesFile(Sales* sales);
void writeSalesFile(Sales* writeSales, int count, int skip);
int scanMemberFile(struct member* memRecord);
int readStockFile(Stock* stkRecord);
void writeStockFile(Stock* stkRecord, int totalStock);

//Others
void salesHead();
void salesDataFields();
void salesFoot();
void salesGraph(int skipRow[6], char data[50]);
void salesStats(int year[6], double amount[6], char title[50], int isMoney);
int minusCurrentStock(int quantity, char itemCode[6], Stock* stkRecord, int totalStock);

/*========= STOCK MODULE FUNCTIONS - LOW JING HONG =========*/
void stockMain();
int stockmenu();
void stockadd();
void stockdisplay();
void displayHeader();

void searchforstock();
void searchItemcode();
void searchItemdesc();
void searchItemprice();
void searchQty();
void searchMinlevel();
void searchReorderqty();
void searchsize();
void searchcolor();
void searchtype();
void searchWeight();

void stockmodify();
void selectstockmodify(char stockcode[6]);
void modiCode(char stockcode[6]);
void modiDesc(char stockcode[6]);
void modiPrice(char stockcode[6]);
void modiQty(char stockcode[6]);
void modiMinlvl(char stockcode[6]);
void modiReorderQty(char stockcode[6]);
void modiSize(char stockcode[6]);
void modiColor(char stockcode[6]);
void modiType(char stockcode[6]);
void modiWeight(char stockcode[6]);
void deleteStock();
void totalValue();
float calculateRowTotal(int qtyInStock, float itemPrice);
void printStockValueRow(char* itemCode, float rowTotal);
void printStockValueHeader();

void stockModuleLogo();
void addStockLogo();
void searchStockLogo();
void modifyStockLogo();
void displayStockLogo();
void deleteStockLogo();
void StockValuesLogo();

int stockCodeExists(char newStockCode[]);
void sortStockByCode();

/*========= Sole Haven Program Starts here!- void main() =========*/
void main() {
	int loop = 0;
	login();

	do {
		system("cls");
		//LOGO - Sole Haven shoe shop
		printf("   _____       _         _    _ \n");
		printf("  / ____|     | |       | |  | | \n");
		printf(" | (___   ___ | | ___   | |__| | __ ___   _____ _ __ \n");
		printf(" \\___  \\ / _ \\| |/ _ \\  |  __  |/ _` \\ \\ / / _ \\ '_ \\ \n");
		printf("  ____) | (_) | |  __/  | |  | | (_| |\\ V /  __/ | | | \n");
		printf(" |_____/ \\___/|_|\\___|  |_|  |_|\\__,_| \\_/ \\___|_| |_| \n\n");
		printf("\nWelcome to the Sole Haven shoe shop main menu! Here is a list of the modules available:\n\n");

		printf("=================================\n");
		printf("| 1) Enter the Staff Module     |\n");
		printf("|-------------------------------|\n");
		printf("| 2) Enter the Member Module    |\n");
		printf("|-------------------------------|\n");
		printf("| 3) Enter the Sales Module     |\n");
		printf("|-------------------------------|\n");
		printf("| 4) Enter the Stock Module     |\n");
		printf("|-------------------------------|\n");
		printf("| 5) Exit the program           |\n");
		printf("|-------------------------------|\n");

		printf("\nSelect one of the options (1 - 5) ");

		switch (menuSelection(5)) {
		case 1:
			staffmenu();
			printf("\nGoing back to Sole Haven Main Menu! \n\n");
			system("pause");
			break;
		case 2:
			memberMain();
			printf("Going back to Sole Haven Main Menu! \n\n");
			system("pause");
			break;
		case 3:
			salesMain();
			break;
		case 4:
			stockMain();
			printf("\nGoing back to Sole Haven Main Menu! \n\n");
			system("pause");
			break;
		default:
			loop = 1;
			system("cls");
			thank();
			exit(0);
		}
	} while (loop == 0);
}

/*========= STAFF MODULE - VICTOR POW YIE YUAW =========*/
void staffadd() {

	system("cls");
	int i = 0;
	char decision;

	addascii();

	do {

		Staff staff;
		FILE* fstaffadd = fopen("staff.txt", "a");

		if (!fstaffadd) {
			printf("Error!");
			exit(1);
		}

		do {
			staffID(&staff.staffID);
		} while (valID(&staff.staffID));

		do {
			staffName(&staff.staffName);
		} while (valName(&staff.staffName));

		do {
			password(&staff.pw, "Enter Password");
		} while (valPassword(&staff.pw));

		do {
			password(&staff.pwr, "Enter Recovery Password");
		} while (valPassword(&staff.pwr));

		positionList();
		do {
			staffPosition(&staff.position);
		} while (valPosition(&staff.position));

		do {
			staffEmail(&staff.email);
		} while (valEmail(&staff.email));

		do {
			stateDepartment(&staff.state, "Enter state", "State cannot be left blank, please enter a state.");
		} while (valState(&staff.state, "State name is too long! Enter in shorter form."));


		if (strcmp(staff.position, "Administrator") == 0)
			adminList();

		if (strcmp(staff.position, "Manager") == 0)
			managerList();

		if (strcmp(staff.position, "Cashier") == 0)
			cashierList();

		if (strcmp(staff.position, "Promoter") == 0)
			promoterList();

		if (strcmp(staff.position, "Cleaner") == 0)
			strcpy(staff.department, "Cleaning");


		do {

			if (strcmp(staff.position, "Cleaner") == 0)
				break;

			stateDepartment(&staff.department, "Enter department", "Department cannot be left blank, please enter a department.");
		} while (valDepartment(&staff.department, "Department name is too long! Enter in shorter form."));


		do {
			salary(&staff.salary, "Enter Salary");
		} while (valSalary(&staff.salary));

		fprintf(fstaffadd, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+5\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary);

		fclose(fstaffadd);

		do {
			userDecision(&decision, "Add another Staff? (Y/N)");
		} while (valDecision(&decision));

		i++;
		printf("\n");

	} while (decision == 'Y');

	printf("%d staff(s) information added.\n\n", i);

	system("pause");
	staffmenu();
}

void userDecision(char* decision, char* message) {
	printf("%s > ", message);
	scanf("%c", decision);
	rewind(stdin);
	*decision = toupper(*decision);
}
int valDecision(char* decision) {
	if (*decision != 'Y' && *decision != 'N') {
		printf("\nError! Please enter 'Y' or 'N'\n\n");
		return 1;
	}
	return 0;
}
int valID(char* id) {

	FILE* fval = fopen("staff.txt", "r");
	char temp[7], temp1[180];

	while (fscanf(fval, "%[^+]+%[^\n]\n", temp, temp1) != EOF) {
		if (strcmp(id, temp) == 0) {
			printf("\nRecord already exists!\n\n");
			fclose(fval);
			return 1;
		}
	}

	fclose(fval);
	return 0;
}
void staffID(char* id) {

	printf("%-25s > ", "Enter Staff ID (Format: STXXXX)");
	scanf("%s", id);
	rewind(stdin);

	while (strlen(id) != 6 || id[0] != 'S' || id[1] != 'T' || !isdigit(id[2]) || !isdigit(id[3]) || !isdigit(id[4]) || !isdigit(id[5])) {
		printf("Please enter correct Staff ID Format! (Format: STXXXX) > ");
		scanf("%s", id);
		rewind(stdin);
	}
}
int valName(char* staffName) {

	if (strlen(staffName) > 20) {
		printf("\nName must not exceed 20 characters, please enter a shorter name. \n");
		return 1;
	}

	for (int i = 0; staffName[i] != '\0'; i++) {
		if (!isalpha(staffName[i]) && !isspace(staffName[i])) {
			printf("\nError! Please only enter characters!\n");
			return 1;
		}
	}

	return 0;
}
void staffName(char* staffName) {

	int checkName;

	do {
		printf("%-25s > ", "Enter Staff Name");
		checkName = scanf("%[^\n]", staffName);
		rewind(stdin);

		if (checkName == 0 || checkName < 1)
			printf("\nName cannot be left blank, please enter a name. \n");

	} while (checkName == 0 || checkName < 1);

}
int valPassword(char* password) {

	if (strlen(password) > 15) {
		printf("\nPassword too long! Enter a shorter password. \n");
		return 1;
	}

	return 0;
}
void password(char* password, char* message) {

	int check;

	do {
		printf("%-25s > ", message);
		check = scanf("%[^\n]", password);
		rewind(stdin);

		if (check == 0 || check < 1)
			printf("\nWarning! You MUST enter a password. \n");

	} while (check == 0 || check < 1);

}
int valPosition(char* position) {

	char positionList[][20] = { "Administrator", "Manager", "Cashier", "Cleaner", "Promoter" };
	int numPositions = sizeof(positionList) / sizeof(positionList[0]);
	// 5 positions x 20 = 100, ^ this code takes 100 and divide by 20 = 5
	for (int j = 0; j < numPositions; j++) {
		if (strcmp(position, positionList[j]) == 0) {
			return 0;
		}
	}

	return 1;
}
void staffPosition(char* position) {

	printf("%-25s > ", "Enter Listed Position (In Text)");
	scanf("%s", position);
	rewind(stdin);

}
int valEmail(char* email) {

	if (strlen(email) > 25) {
		printf("\Email is too long! Enter a shorter Email. \n");
		return 1;
	}

	if (!isalpha(email[0])) {
		printf("\nEmail must start with a character!\n");
		return 1;
	}

	if (strstr(email, "@gmail.com") == NULL && isalpha(email[0])) {
		// if there is @gmail.com in the input, it will return a nonzero pointer
		printf("\nInvalid input, email must contain '@gmail.com'.\n");
		return 1;
	}

	return 0;
}
void staffEmail(char* email) {
	printf("%-25s > ", "Enter Email");
	scanf("%s", email);
	rewind(stdin);
}
int valState(char* state, char* message) {

	if (strlen(state) > 15) {
		printf("\n%-25s \n", message);
		return 1;
	}

	for (int i = 0; i < strlen(state); i++) {
		if (!isalpha(state[i]) && state[i] != '\0' && !isspace(state[i])) {
			printf("\nPlease only enter characters! \n");
			return 1;
		}
	}

	return 0;
}
int valDepartment(char* department, char* message) {

	if (strlen(department) > 15) {
		printf("\n%-25s \n", message);
		return 1;
	}

	for (int i = 0; i < strlen(department); i++) {
		if (!isalpha(department[i]) && department[i] != '\0' && !isspace(department[i])) {
			printf("\nPlease only enter characters! \n");
			return 1;
		}
	}

	char departmentList[][20] = { "PR", "HR", "Accounting", "Finance", "Marketing", "Sales", "IT", "IS", "Cleaning" };
	int numPositions = sizeof(departmentList) / sizeof(departmentList[0]);
	// 9 positions x 20 = 180, ^ this code takes 180 and divide by 20 = 9
	for (int j = 0; j < numPositions; j++) {
		if (strcmp(department, departmentList[j]) == 0) {
			return 0;
		}
	}

	return 1;
}
void stateDepartment(char* state, char* message, char* message2) {

	int checkstate;

	do {
		printf("%-25s > ", message);
		checkstate = scanf("%[^\n]", state);
		rewind(stdin);
		if (checkstate == 0 || checkstate < 1)
			printf("\n%-25s \n", message2);
	} while ((checkstate == 0 || checkstate < 1));

}
int valSalary(double* salary) {

	if (*salary < 0 || *salary > 99999) {
		printf("\nInvalid input, illogical salary.\n");
		return 1;
	}

	return 0;
}
void salary(double* salary, char* comment) {

	printf("%-25s > ", comment);
	scanf("%lf", salary);
	rewind(stdin);

}
int valRating(double* rating) {
	if (*rating < 0 || *rating > 5.0) {
		printf("\nInvalid input, illogical rating.\n");
		return 1;
	}

	return 0;
}
void staffRating(double* update) {

	int checkrating;

	do {
		printf("What rating did the customer give to this staff? (0~5)\n");
		printf("Input > ");
		checkrating = scanf("%lf", update);
		rewind(stdin);
		if (checkrating == 0 || checkrating < 1)
			printf("\nInvalid! You MUST enter a number.\n");
	} while ((checkrating == 0 || checkrating < 1));
}

void staffsearch() {

	system("cls");

	searchascii();

	int input;

	do {
		printf("Search staff information by? \n");
		printf("1) Staff ID\n");
		printf("2) Staff Name\n");
		printf("3) Staff Position\n");
		printf("4) Staff State\n");
		printf("5) Staff Department\n");
		printf("6) Staff Salary\n");
		printf("7) Exit\n\n");
		printf("Input: ");
		scanf("%d", &input);
		rewind(stdin);

		if (input > 7 || input < 1)
			printf("\nInvalid option! Please choose between 1 to 7.\n\n");

	} while (input > 7 || input < 1);

	switch (input) {
	case 1:
		searchid();
		break;
	case 2:
		searchname();
		break;
	case 3:
		searchposition();
		break;
	case 4:
		searchstate();
		break;
	case 5:
		searchdepartment();
		break;
	case 6:
		searchsalary();
		break;
	case 7:
		staffmenu();
		break;
	}
}
void searchsalary() {

	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	double salary1, salary2;
	int i = 0, z = 1;

	do {
		salary(&salary1, "Enter minimum salary threshold");
	} while (valSalary(&salary1));


	do {
		salary(&salary2, "Enter maximum salary threshold");
	} while (valSalary(&salary2));

	rewind(stdin);
	printf("\n\n");

	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (salary1 <= staff.salary && salary2 >= staff.salary) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();
	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();

}
void searchid() {

	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char id[7];
	int i = 0;

	printf("Enter Staff ID (Format: STXXXX) > ");
	scanf("%[^\n]", &id);

	rewind(stdin);
	printf("\n\n");

	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};

	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();
}
void searchname() {
	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char name[20];
	int i = 0;

	printf("Enter Staff Name > ");
	scanf("%[^\n]", &name);

	rewind(stdin);
	printf("\n\n");
	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(name, staff.staffName) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};

	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();
}
void searchposition() {
	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	char position[20];
	int i = 0;

	positionList();

	do {
		staffPosition(&position);
	} while (valPosition(&position));

	printf("\n\n");

	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(position, staff.position) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};

	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();
}
void searchstate() {
	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	char state[20];
	int i = 0;

	do {
		stateDepartment(&state, "Enter state", "State cannot be left blank!");
	} while (valState(&state, "State entered is too long! Try entering in a shorter form."));

	printf("\n\n");

	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(state, staff.state) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};

	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();
}
void searchdepartment() {
	system("cls");
	searchascii();
	FILE* fstaffsearch = fopen("staff.txt", "r");
	if (!fstaffsearch) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	char department[15];
	int i = 0;

	adminList();

	do {
		stateDepartment(&department, "Enter department", "Department cannot be left blank!");
	} while (valDepartment(&department, "Department entered is too long! Try entering in a shorter form."));

	printf("\n\n");
	staffheader();
	while (fscanf(fstaffsearch, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(department, staff.department) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();
	if (i < 1) {
		printf("\n[ No Records Found ]");
	}

	printf("\nPress Enter to go back to search page.\n\n");
	system("pause");
	fclose(fstaffsearch);
	staffsearch();
}

void staffdisplay() {
	system("cls");

	displayascii();

	FILE* fstaffdisplay = fopen("staff.txt", "r");
	if (!fstaffdisplay) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	int i = 0;
	printf("\n\n");
	staffheader();
	while (fscanf(fstaffdisplay, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(staff.staffID, staff.staffID) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}
	fclose(fstaffdisplay);
	system("pause");
	staffmenu();

}
void displayForOthers() {
	FILE* fstaffdisplay = fopen("staff.txt", "r");
	if (!fstaffdisplay) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	int i = 0;
	printf("\n\n");
	staffheader();
	while (fscanf(fstaffdisplay, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(staff.staffID, staff.staffID) == 0) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();

	if (i < 1) {
		printf("\n[ No Records Found ]");
	}
	fclose(fstaffdisplay);
}

void staffdelete() {
	system("cls");


	Staff staff;

	char input[7], decision;

	do {
		FILE* foldstaff = fopen("staff.txt", "r");
		FILE* fnewstaff = fopen("temp.txt", "w");

		system("cls");
		deleteascii();
		displayForOthers();

		if (!foldstaff) {
			printf("Error!");
			exit(1);
		}

		if (!fnewstaff) {
			printf("Error!");
			exit(1);
		}

		int i = 0;
		printf("\nWhose data do you wish to remove? Enter Staff ID.\n");
		printf("Input (Format: STXXXX) > ");
		scanf("%s", &input);
		rewind(stdin);

		while (fscanf(foldstaff, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
			if (strcmp(input, staff.staffID) != 0) {
				fprintf(fnewstaff, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			}
			else
				i++;
		};

		if (i < 1) {
			printf("\n[ No Records Found ]\n");
		}
		else {
			printf("\nRow has been successfully deleted.\n");
		};

		do {
			userDecision(&decision, "Do you wish to delete another row? (Y/N)");
		} while (valDecision(&decision));

		fclose(foldstaff);
		fclose(fnewstaff);
		remove("staff.txt");
		rename("temp.txt", "staff.txt");

	} while (decision == 'Y');

	staffmenu();

}

void login() {

	loginascii();

	Staff staff;

	char password[30], input, id[7];
	int j = 0;

	do {

		FILE* fptr = fopen("staff.txt", "r");

		if (!fptr) {
			printf("Error!");
			exit(1);
		}

		int i = 0;

		printf("Enter Staff ID: ");
		rewind(stdin);
		scanf("%s", &id);
		printf("Enter Password: ");
		rewind(stdin);

		while (1) {
			input = getch();
			if (input == ENTER) {
				break;
			}
			else if (input == BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}
			}
			else {
				password[i] = input;
				printf("*");
				i++;
			}
		}
		password[i] = '\0';

		while (fscanf(fptr, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
			if (strcmp(id, staff.staffID) == 0 && (strcmp(password, staff.pw) == 0 || strcmp(password, staff.pwr) == 0)) {
				j++;
				fclose(fptr);
				loginProcess();
				break;
			}
		};

		if (j < 1) {
			printf("\n\nIncorrect Username or Password!\n\n");
		}

		fclose(fptr);
	} while (j < 1);
}

void staffmenu() {
	system("cls");

	int input;

	modiftascii();

	do {
		menuList();
		printf("Input: ");
		scanf("%d", &input);
		rewind(stdin);

		if (input > 7 || input < 1)
			printf("\nError! Enter valid option.\n\n");

	} while (input > 7 || input < 1);

	switch (input) {
	case 1:
		staffadd();
		break;
	case 2:
		staffsearch();
		break;
	case 3:
		staffmodify();
		break;
	case 4:
		staffdisplay();
		break;
	case 5:
		staffdelete();
		break;
	case 6:
		staffreport();
		break;
	case 7:
		break;
	}
}

void staffmodify() {

	system("cls");
	modifyascii();
	FILE* fmodify = fopen("staff.txt", "r");
	if (!fmodify) {
		printf("Error!");
		exit(1);
	}
	Staff staff;
	int i = 0;
	char id[7];

	displayForOthers();

	printf("\nWhose information do you want to modify?\n");
	printf("Type 'X' if you wish to exit.\n");
	printf("Enter Staff ID (Format: STXXXX) > ");
	scanf("%[^\n]", &id);
	rewind(stdin);

	if (strcmp(id, "X") == 0) {
		fclose(fmodify);
		return staffmenu();
	}

	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) == 0) {
			i++;
			fclose(fmodify);
			staffmodify2(staff.staffID);
		}
	};

	if (i < 1) {
		printf("\n[ No Records Found ]\n\n");

		fclose(fmodify);
		system("pause");
		staffmodify();
	};

}
void staffmodify2(char id[7]) {

	int input;

	do {
		printf("\n\nWhich data do you want to modify for staff %s?\n", id);
		printf("1.  ID\n");
		printf("2.  Name\n");
		printf("3.  Password\n");
		printf("4.  Password Recovery\n");
		printf("5.  Position\n");
		printf("6.  Email\n");
		printf("7.  State\n");
		printf("8.  Department\n");
		printf("9.  Salary\n");
		printf("10. Customer rating feedback\n");
		printf("\nInput (Number) > ");
		scanf("%d", &input);
		rewind(stdin);

		printf("\n\n");

		switch (input) {
		case 1:
			modstaffid(id);
			break;
		case 2:
			modsname(id);
			break;
		case 3:
			modpw(id);
			break;
		case 4:
			modpwr(id);
			break;
		case 5:
			modpos(id);
			break;
		case 6:
			modemail(id);
			break;
		case 7:
			modstate(id);
			break;
		case 8:
			moddepartment(id);
			break;
		case 9:
			modsalary(id);
			break;
		case 10:
			modrating(id);
			break;
		default:
			printf("Invalid choice! Enter a number between 1 to 10!");
		}
	} while (input > 10 || input < 1);
}
void modstaffid(char id[7]) {

	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[7];


	do {
		printf("What do you want to change the ID to?\n");
		printf("Input (Format: STXXXX) > ");
		scanf("%[^\n]", &update);
		rewind(stdin);
		while (strlen(update) != 6 || update[0] != 'S' || update[1] != 'T' || !isdigit(update[2]) || !isdigit(update[3]) || !isdigit(update[4]) || !isdigit(update[5])) {
			printf("Please enter correct Staff ID Format! (Format: STXXXX) > ");
			rewind(stdin);
			scanf("%[^\n]", &update);
			rewind(stdin);
		}
		while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
			if (strcmp(id, staff.staffID) != 0) {
				fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			}
			else {
				fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", strcpy(staff.staffID, update), staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			}
		}
	} while (valID(update));

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");


	staffmodify();
};
void modsname(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[20];

	do {
		staffName(&update);
	} while (valName(&update));


	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, strcpy(staff.staffName, update), staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modpw(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[30];

	do {
		password(&update, "Change Password To");
	} while (valPassword(&update));
	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, strcpy(staff.pw, update), staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modpwr(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[30];
	do {
		password(&update, "Change Recovery PW To");
	} while (valPassword(&update));

	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, strcpy(staff.pwr, update), staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modpos(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[20];

	char sel[][20] = { "Administrator", "Manager", "Cashier", "Cleaner", "Promoter" };
	int k = 0;

	while (!k) {
		printf("\nStaff Position List:\n");
		printf("--------------------\n");
		printf("1. Administrator\n");
		printf("2. Manager\n");
		printf("3. Cashier\n");
		printf("4. Cleaner\n");
		printf("5. Promoter\n");
		printf("What do you want to change the Position to?\n");

		printf("Input (In Text) > ");
		scanf("%s", &update);
		rewind(stdin);
		for (int j = 0; j < sizeof(sel); j++) {
			if (strcmp(update, sel[j]) == 0) {
				k = 1;
				break;
			}
			else if (j >= sizeof(sel) && strcmp(update, sel[j]) != 0) {
				printf("\nInvalid Position! Please only enter valid position from the list below.\n");
				break;
			}
		}
	}

	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, strcpy(staff.position, update), staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modemail(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[25];

	while (1) {
		printf("What do you want to change the Email to?\n");
		printf("Input > ");
		scanf("%s", &update);
		rewind(stdin);
		if (strstr(update, "@gmail.com") != NULL && isalpha(update[0])) {
			//if there is @gmail.com in input, will return a non-null ponter
			break;
		}
		else if (!isalpha(update[0]))
			printf("\nEmail must start with a character!\n");
		else {
			printf("\nInvalid input, email must contain '@gmail.com'.\n");
		}
	}
	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, strcpy(staff.email, update), staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modstate(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[20];

	do {
		stateDepartment(&update, "Change State To", "Invalid! You MUST enter a state!");
	} while (valState(&update, "Input too long! Try something shorter."));

	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, strcpy(staff.state, update), staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void moddepartment(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	char update[30];


	adminList();
	do {
		stateDepartment(&update, "Change Department To", "Invalid! You MUST enter a department.");
	} while (valDepartment(&update, "Input is too long! Enter something shorter."));


	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, strcpy(staff.department, update), staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");
	staffmodify();
};
void modsalary(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	double update;

	while (1) {
		printf("What do you want to change the salary to?\n");
		printf("Input > ");
		scanf("%lf", &update);
		rewind(stdin);
		if (update < 0 || update > 99999) {
			printf("\nInvalid input, illogical salary.\n");
		}
		else {
			break;
		}
	};


	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			staff.salary = update;
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");

	system("pause");

	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");


	staffmodify();
};
void modrating(char id[7]) {
	FILE* fmodify = fopen("staff.txt", "r");
	FILE* fnew = fopen("temp.txt", "w");

	if (!fmodify) {
		printf("Error!");
		exit(1);
	}

	if (!fnew) {
		printf("Error!");
		exit(1);
	}

	Staff staff;
	double update;

	do {
		staffRating(&update);
	} while (valRating(&update));


	while (fscanf(fmodify, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (strcmp(id, staff.staffID) != 0) {
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
		else {
			staff.rating = (staff.rating + update) / 2.0;
			fprintf(fnew, "%s+%s+%s+%s+%s+%s+%s+%s+%.2lf+%.2lf\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
		}
	};

	printf("\n[ Data Modified ]\n");
	system("pause");
	fclose(fmodify);
	fclose(fnew);
	remove("staff.txt");
	rename("temp.txt", "staff.txt");


	staffmodify();
};

void staffreport() {

	system("cls");
	reportascii();
	Staff staff;
	FILE* fReport = fopen("staff.txt", "r");

	if (!fReport) {
		printf("Error!");
		exit(-1);
	}

	int count = 0, count1 = 0, j;
	int i = 0;
	double stotal = 0, stotal1 = 0, min = 9999999.99, max = 0.00, top, bottom;


	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {

		stotal1 += staff.salary;

		if (staff.salary >= max)
			max = staff.salary;

		if (staff.salary < min)
			min = staff.salary;

		i++;
	}

	stotal = stotal1 / i;

	rewind(fReport);

	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {

		if (staff.salary >= stotal)
			count++;

		if (staff.salary < stotal)
			count1++;

	}

	top = (double)count / i * 100;
	bottom = (double)count / i * 100;

	time_t date = time(NULL);
	printf("\n\n%18s %s", "Report for:", ctime(&date));

	printf("\n\n%39s", "Average Salary Graph For Staff");
	printf("\n----------------------------------------------------\n");
	printf("\n%-50s \n", "More than or equal to average of salary");
	for (int k = 0; k < count; k++) {
		printf(">>>>>");
	}
	printf("  %.2lf%%\n", top);

	printf("\n%-50s \n", "Less than the average salary");
	for (int l = 0; l < count1; l++) {
		printf(">>>>>");
	}
	printf("  %.2lf%%\n", bottom);
	printf("\n----------------------------------------------------\n");

	rewind(fReport);


	reportStats("Total number of staff", &i, "Total staff who has more than or equal to average of salary", &count, "Total staff who has less than the average salary", &count1, "Total staff salary",
		&stotal1, "Highest staff salary", &max, "Lowest staff salary", &min, "Average Salary", &stotal);


	printf("\n%100s\n", "More than or equal to average salary");
	staffheader();
	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (staff.salary >= stotal) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();

	rewind(fReport);

	printf("\n%100s\n", "Less than the average salary");
	staffheader();
	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (staff.salary < stotal) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();
	fclose(fReport);
	printf("\n\n%165s\n", "Page 1 of 2");

	system("pause");
	staffreport2();

}
void staffreport2() {
	system("cls");
	reportascii();

	Staff staff;
	FILE* fReport = fopen("staff.txt", "r");

	if (!fReport) {
		printf("Error!");
		exit(-1);
	}

	int count = 0, count1 = 0, x;
	int i = 0;
	double stotal = 0, stotal1 = 0, min = 5.00, max = 0.00;

	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		i++;
		stotal1 += staff.rating;

		if (staff.rating >= max)
			max = staff.rating;

		if (staff.rating < min)
			min = staff.rating;
	}

	stotal = stotal1 / i;

	rewind(fReport);

	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {

		if (staff.rating >= stotal)
			count++;

		if (staff.rating < stotal)
			count1++;

	}

	double topp = (double)count / i * 100;
	double bottomm = (double)count1 / i * 100;

	time_t date = time(NULL);
	printf("\n\n%18s %s", "Report for:", ctime(&date));

	printf("\n\n%35s", "Rating Graph For Staff");
	printf("\n----------------------------------------------------\n");
	printf("\n%-50s \n", "More than or equal to 50% of employees");
	for (int y = 0; y < count; y++) {
		printf(">>>>>");
	}
	printf("  %.2lf%%\n", topp);

	printf("\n%-50s \n", "Less than 50% of other employees  ");
	for (int z = 0; z < count1; z++) {
		printf(">>>>>");
	}
	printf("  %.2lf%%\n", bottomm);
	printf("\n----------------------------------------------------\n");

	rewind(fReport);


	reportStats("Total number of staff", &i, "Total staff who has higher rating than 50% of the employees", &count, "Total staff who has lower rating than the other 50% of the employees", &count1, "Total staff rating",
		&stotal1, "Highest staff rating", &max, "Lowest staff rating", &min, "Average staff rating", &stotal);


	printf("\n%100s\n", "More than or equal to average staff rating");
	staffheader();
	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (staff.rating >= stotal) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();

	rewind(fReport);

	printf("\n%100s\n", "Less than the average staff rating");
	staffheader();
	while (fscanf(fReport, "%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%[^+]+%lf+%lf\n", &staff.staffID, &staff.staffName, &staff.pw, &staff.pwr, &staff.position, &staff.email, &staff.state, &staff.department, &staff.salary, &staff.rating) != EOF) {
		if (staff.rating < stotal) {
			printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10.2lf %-8.2lf |\n", staff.staffID, staff.staffName, staff.pw, staff.pwr, staff.position, staff.email, staff.state, staff.department, staff.salary, staff.rating);
			i++;
		}
	};
	staffFooter();

	printf("\n\n%165s\n", "Page 2 of 2");

	system("pause");
	fclose(fReport);
	staffmenu();
}
void reportStats(char* message1, int* i, char* message2, int* count, char* message3, int* count1, char* message4, double* stotal1, char* message5, double* max, char* message6, double* min, char* message7, double* stotal) {
	printf("\n%-68s > %d\n", message1, *i);
	printf("%-68s > %d\n", message2, *count);
	printf("%-68s > %d\n", message3, *count1);
	printf("%-68s > %.2lf\n", message4, *stotal1);
	printf("%-68s > %.2lf\n", message5, *max);
	printf("%-68s > %.2lf\n", message6, *min);
	printf("%-68s > %.2lf\n\n", message7, *stotal);
}

void staffheader() {
	printf("|====================================================================================================================================================================|\n");
	printf("| %-10s %-20s %-15s %-15s %-20s %-25s %-15s %-15s %-10s %-8s |\n", "Staff ID", "Staff Name", "Password", "Recovery PW", "Position", "Email", "State", "Department", "Salary", "Rating");
	printf("|====================================================================================================================================================================|\n");
}
void staffFooter() {
	printf("|====================================================================================================================================================================|\n");
}

void searchascii() {
	printf(" _______  _______  _______  _______  _______             _______ _________ _______  _______  _______ \n"
		"(  ____ \\(  ____ \\(  ___  )(  ____ )(  ____ \\|\\     /|  (  ____ \\\\__   __/(  ___  )(  ____ \\(  ____ \\ \n"
		"| (    \\/| (    \\/| (   ) || (    )|| (    \\/| )   ( |  | (    \\/   ) (   | (   ) || (    \\/| (    \\/ \n"
		"| (_____ | (__    | (___) || (____)|| |      | (___) |  | (_____    | |   | (___) || (__    | (__     \n"
		"(_____  )|  __)   |  ___  ||     __)| |      |  ___  |  (_____  )   | |   |  ___  ||  __)   |  __)    \n"
		"      ) || (      | (   ) || (\\ (   | |      | (   ) |        ) |   | |   | (   ) || (      | (       \n"
		"/\\____) || (____/\\| )   ( || ) \\ \\__| (____/\\| )   ( |  /\\____) |   | |   | )   ( || )      | )       \n"
		"\\_______)(_______/|/     \\||/   \\__/(_______/|/     \\|  \\_______)   )_(   |/     \\||/       |/        \n\n\n");
}
void modifyascii() {
	printf(" _______  _______  ______  _________ _______                _________ _        _______  _______ \n");
	printf("(       )(  ___  )(  __  \\ \\__   __/(  ____ \\|\\     /|      \\__   __/( (    /|(  ____ \\(  ___  )\n");
	printf("| () () || (   ) || (  \\  )   ) (   | (    \\/( \\   / )         ) (   |  \\  ( || (    \\/| (   ) |\n");
	printf("| || || || |   | || |   ) |   | |   | (__     \\ (_) /          | |   |   \\ | || (__    | |   | |\n");
	printf("| |(_)| || |   | || |   | |   | |   |  __)     \\   /           | |   | (\\ \\) ||  __)   | |   | |\n");
	printf("| |   | || |   | || |   ) |   | |   | (         ) (            | |   | | \\   || (      | |   | |\n");
	printf("| )   ( || (___) || (__/  )___) (___| )         | |         ___) (___| )  \\  || )      | (___) |\n");
	printf("|/     \\|(_______)(______/ \\_______/|/          \\_/         \\_______/|/    )_)|/       (_______)\n\n\n");
}
void reportascii() {
	printf(" _______ _________ _______  _______  _______        _______  _______  _______  _______  _______ _________\n");
	printf("(  ____ \\\\__   __/(  ___  )(  ____ \\(  ____ \\      (  ____ \\(  ____ \\(  ____ )(  ___  )(  ____ )\\__   __/\n");
	printf("| (    \\/   ) (   | (   ) || (    \\/| (    \\/      | (    )|| (    \\/| (    )|| (   ) || (    )|   ) (   \n");
	printf("| (_____    | |   | (___) || (__    | (__          | (____)|| (__    | (____)|| |   | || (____)|   | |   \n");
	printf("(_____  )   | |   |  ___  ||  __)   |  __)         |     __)|  __)   |  _____)| |   | ||     __)   | |   \n");
	printf("      ) |   | |   | (   ) || (      | (            | (\\ (   | (      | (      | |   | || (\\ (      | |   \n");
	printf("/\\____) |   | |   | )   ( || )      | )            | ) \\ \\__| (____/\\| )      | (___) || ) \\ \\__   | |   \n");
	printf("\\_______)   |_|   |_)   (_||_)      |_)            |_)  \\__/(_______/|_)      (_______)|_)  \\__/   |_|\n\n\n");

}
void thank() {
	printf("\n\n\n_________          _______  _        _        _______          _______  _______  _______                   _______ _________ _        _______     _ \n");
	printf("\\__   __/|\\     /|(  ___  )( (    /|| \\    /\\(  ____ \\        (  ____ \\(  ___  )(  ____ )        |\\     /|(  ____ \\\\__   __/( (    /|(  ____ \\   ( )\n");
	printf("   ) (   | )   ( || (   ) ||  \\  ( ||  \\  / /| (    \\/        | (    \\/| (   ) || (    )|        | )   ( || (    \\/   ) (   |  \\  ( || (    \\/   | |\n");
	printf("   | |   | (___) || (___) ||   \\ | ||  (_/ / | (_____)        | (__    | |   | || (____)|        | |   | || (_____    | |   |   \\ | || |         | |\n");
	printf("   | |   |  ___  ||  ___  || (\\ \\) ||   _ (  (_____  )        |  __)   | |   | ||     __)        | |   | |(_____  )   | |   | (\\ \\) || | ____    | |\n");
	printf("   | |   | (   ) || (   ) || | \\   ||  ( \\ \\       ) |        | (      | |   | || (\\ (           | |   | |      ) |   | |   | | \\   || | \\_  )   (_)\n");
	printf("   | |   | )   ( || )   ( || )  \\  ||  /  \\ \\/____)  |        | )      | (___) || ) \\ \\__        | (___) |/\\____) |___) (___| )  \\  || (___) |    _ \n");
	printf("   )_(   |/     \\||/     \\||/    )_)|_/    \\/\\_______)        |/       (_______)|/   \\__/        (_______)\\_______)\\_______/|/    )_)(_______)   (_)\n\n\n");

}
void loginascii() {
	printf(" _          _______    _______   _________   _         \n");
	printf("( \\        (  ___  )  (  ____ \\  \\__   __/  ( (    /|  \n");
	printf("| (        | (   ) |  | (    \\/     ) (     |  \\  ( |  \n");
	printf("| |        | |   | |  | |           | |     |   \\ | |  \n");
	printf("| |        | |   | |  | | ____      | |     | (\\ \\) |  \n");
	printf("| |        | |   | |  | | \\_  )     | |     | | \\   |  \n");
	printf("| (____/\\  | (___) |  | (___) |  ___) (___  | )  \\  |  \n");
	printf("(_______/  (_______)  (_______)  \\_______/  |/    )_)  \n\n\n");
}
void addascii() {
	printf(" _______  ______   ______     _______ _________ _______  _______  _______ \n"
		"(  ___  )(  __  \\ (  __  \\   (  ____ \\\\__   __/(  ___  )(  ____ \\(  ____ \\ \n"
		"| (   ) || (  \\  )| (  \\  )  | (    \\/   ) (   | (   ) || (    \\/| (    \\/ \n"
		"| (___) || |   ) || |   ) |  | (_____    | |   | (___) || (__    | (__     \n"
		"|  ___  || |   | || |   | |  (_____  )   | |   |  ___  ||  __)   |  __)    \n"
		"| (   ) || |   ) || |   ) |        ) |   | |   | (   ) || (      | (       \n"
		"| )   ( || (__/  )| (__/  )  /\\____) |   | |   | )   ( || )      | )       \n"
		"|/     \\|(______/ (______/   \\_______)   )_(   |/     \\||/       |/        \n\n\n");
}
void displayascii() {
	printf(" _______  _        _          _______ _________ _______  _______  _______  _______ \n");
	printf("(  ___  )( \\      ( \\        (  ____ \\\\__   __/(  ___  )(  ____ \\(  ____ \\(  ____ \\\n");
	printf("| (   ) || (      | (        | (    \\/   ) (   | (   ) || (    \\/| (    \\/| (    \\/\n");
	printf("| (___) || |      | |        | (_____    | |   | (___) || (__    | (__    | (_____ \n");
	printf("|  ___  || |      | |        (_____  )   | |   |  ___  ||  __)   |  __)   (_____  )\n");
	printf("| (   ) || |      | |              ) |   | |   | (   ) || (      | (            ) |\n");
	printf("| )   ( || (____/\\| (____/\\  /\\____) |   | |   | )   ( || )      | )      /\\____) |\n");
	printf("|/     \\|(_______/(_______/  \\_______)   )_(   |/     \\||/       |/       \\_______)\n\n\n");
}
void deleteascii() {
	printf(" ______   _______  _        _______ _________ _______        _______ _________ _______  _______  _______ \n");
	printf("(  __  \\ (  ____ \\( \\      (  ____ \\\\__   __/(  ____ \\      (  ____ \\\\__   __/(  ___  )(  ____ \\\\  ____ \\ \n");
	printf("| (  \\  )| (    \\/| (      | (    \\/   ) (   | (    \\/      | (    \\/   ) (   | (   ) || (    \\/| (    \\/ \n");
	printf("| |   ) || (__    | |      | (__       | |   | (__          | (_____    | |   | (___) || (__    | (__     \n");
	printf("| |   | ||  __)   | |      |  __)      | |   |  __)         (_____  )   | |   |  ___  ||  __)   |  __)    \n");
	printf("| |   ) || (      | |      | (         | |   | (                  ) |   | |   | (   ) || (      | (       \n");
	printf("| (__/  )| (____/\\| (____/\\| (____/\\   | |   | (____/\\      /\\____) |   | |   | )   ( || )      | )       \n");
	printf("(______/ (_______/(_______/(_______/   )_(   (_______/      \\_______)   )_(   |/     \\||/       |/        \n\n\n");
}
void welcomeascii() {
	printf("  _    _      _                          \n");
	printf(" | |  | |    | |                         \n");
	printf(" | |  | | ___| | ___ ___  _ __ ___   ___ \n");
	printf(" | |\\/| |/ _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\\n");
	printf(" \\  /\\  /  __/ | (_| (_) | | | | | |  __/\n");
	printf("  \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|\n");
	printf("                                        \n");
}
void modiftascii() {
	printf(" _______ _________ _______  _______  _______    _______  _______  ______            _        _______ \n"
		"(  ____ \\\\__   __/(  ___  )(  ____ \\(  ____ \\  (       )(  ___  )(  __  \\ |\\     /|( \\      (  ____ \\ \n"
		"| (    \\/   ) (   | (   ) || (    \\/| (    \\/  | () () || (   ) || (  \\  )| )   ( || (      | (    \\/ \n"
		"| (_____    | |   | (___) || (__    | (__      | || || || |   | || |   ) || |   | || |      | (__    \n"
		"(_____  )   | |   |  ___  ||  __)   |  __)     | |(_)| || |   | || |   | || |   | || |      |  __)   \n"
		"      ) |   | |   | (   ) || (      | (        | |   | || |   | || |   ) || |   | || |      | (      \n"
		"/\\____) |   | |   | )   ( || )      | )        | )   ( || (___) || (__/  )| (___) || (____/\\| (____/\\ \n"
		"\\_______)   )_(   |/     \\||/       |/         |/     \\|(_______)(______/ (_______)(_______/(_______/ \n\n\n");
}
void positionList() {
	printf("\n\nStaff Position List:\n");
	printf("--------------------\n");
	printf("1. Administrator\n");
	printf("2. Manager\n");
	printf("3. Cashier\n");
	printf("4. Cleaner\n");
	printf("5. Promoter\n");
}
void menuList() {
	printf("Choose function: \n");
	printf("1) Add Staff\n");
	printf("2) Search Staff\n");
	printf("3) Modify Staff\n");
	printf("4) Display Staff\n");
	printf("5) Delete Staff\n");
	printf("6) Staff Report\n");
	printf("7) Exit\n\n");
}
void loginProcess() {
	printf("\nLogin successful.\n");
	Sleep(500);
	printf("Loading ");
	Sleep(500);
	for (int i = 0; i < 3; i++) {
		printf(". ");
		Sleep(500);
	}
	printf("\nLoading complete!\n\n\n");
	Sleep(1000);
	welcomeascii();
	Sleep(1000);
}
void adminList() {
	printf("\n\nDepartment List:\n");
	printf("--------------------\n");
	printf("1. PR\n");
	printf("2. HR\n");
	printf("3. Accounting\n");
	printf("4. Finance\n");
	printf("5. Marketing\n");
	printf("6. Sales\n");
	printf("7. IT\n");
	printf("8. IS\n");
	printf("9. Cleaning\n");
}
void managerList() {
	printf("\n\nDepartment List:\n");
	printf("--------------------\n");
	printf("1. PR\n");
	printf("2. HR\n");
	printf("3. IT\n");
	printf("4. IS\n");
}
void cashierList() {
	printf("\n\nDepartment List:\n");
	printf("--------------------\n");
	printf("1. Accounting\n");
	printf("2. Finance\n");
	printf("3. Sales\n");
}
void promoterList() {
	printf("\n\nDepartment List:\n");
	printf("--------------------\n");
	printf("1. PR\n");
	printf("2. Marketing\n");
	printf("3. Sales\n");
}

/*========= MEMBER MODULE - TAN KAI YUAN =========*/
int memberMain() {
	system("cls");
	int option;
	int year, month, day;
	do {
		option = menu();
		switch (option) {
		case 1:
			memberAdd();
			break;
		case 2:
			memberSearch();
			break;
		case 3:
			memberModify();
			break;
		case 4:
			memberDisplay();
			break;
		case 5:
			memberDelete();
			break;
		case 6:
			memberReport();
			break;
		case 7:
			break;
		default:
			printf("Please enter in between 1-7!!\n");
			break;
		}
	} while (option != 7);
}

int menu() {
	int function;
	printf(" _______  _______  _______  ______   _______  _______   _________ _        _______  _______  _______  _______  _______ __________________ _______  _          _______  _______  ______            _        _______  \n");
	printf("(       )(  ____ \\(       )(  ___ \\ (  ____ \\(  ____ )  \\__   __/( (    /|(  ____ \\(  ___  )(  ____ )(       )(  ___  )\\__   __/\\__   __/(  ___  )( (    /|  (       )(  ___  )(  __  \\ |\\     /|( \\      (  ____ \\ \n");
	printf("| () () || (    \\/| () () || (   ) )| (    \\/| (    )|     ) (   |  \\  ( || (    \\/| (   ) || (    )|| () () || (   ) |   ) (      ) (   | (   ) ||  \\  ( |  | () () || (   ) || (  \\  )| )   ( || (      | (    \\/ \n");
	printf("| || || || (__    | || || || (__/ / | (__    | (____)|     | |   |   \\ | || (__    | |   | || (____)|| || || || (___) |   | |      | |   | |   | ||   \\ | |  | || || || |   | || |   ) || |   | || |      | (__     \n");
	printf("| |(_)| ||  __)   | |(_)| ||  __ (  |  __)   |     __)     | |   | (\\ \\) ||  __)   | |   | ||     __)| |(_)| ||  ___  |   | |      | |   | |   | || (\\ \\) |  | |(_)| || |   | || |   | || |   | || |      |  __)    \n");
	printf("| |   | || (      | |   | || (  \\ \\ | (      | (\\ (        | |   | | \\   || (      | |   | || (\\ (   | |   | || (   ) |   | |      | |   | |   | || | \\   |  | |   | || |   | || |   ) || |   | || |      | (       \n");
	printf("| )   ( || (____/\\| )   ( || )___) )| (____/\\| ) \\ \\__  ___) (___| )  \\  || )      | (___) || ) \\ \\__| )   ( || )   ( |   | |   ___) (___| (___) || )  \\  |  | )   ( || (___) || (__/  )| (___) || (____/\\| (____/\\ \n");
	printf("|/     \\|(_______/|/     \\||/ \\___/ (_______/|/   \\__/  \\_______/|/    )_)|/       (_______)|/   \\__/|/     \\||/     \\|   )_(   \\_______/(_______)|/    )_)  |/     \\|(_______)(______/ (_______)(_______/(_______/ \n");

	printf("Please select an option:\n");
	printf("1) Add member\n");
	printf("2) Search member\n");
	printf("3) Modify member\n");
	printf("4) Display all members\n");
	printf("5) Delete member\n");
	printf("6) Generate member report\n");
	printf("7) Exit\n\n");
	printf("Enter your choice (1-7): ");
	rewind(stdin);
	scanf("%d", &function);
	printf("\n");
	return function;
}

int memberAdd() {
	struct member member[50];
	char yes;
	int how;
	char memberID[6], contactNumber[50], IC[50], uplineID[50], email[50], gender, referral[50];
	FILE* fp2 = fopen("member.txt", "r");
	FILE* fp = fopen("member.txt", "a");

	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int j = 0;
	while (fscanf(fp2, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[j].memberID, &member[j].name, &member[j].gender, &member[j].IC, &member[j].contactNumber, &member[j].uplineID, &member[j].referral, &member[j].email, &member[j].dateOfBirth.year, &member[j].dateOfBirth.month, &member[j].dateOfBirth.day, &member[j].address) != EOF) {
		j++;
	};
	printf(" _______  ______   ______     _______  _______  _______  _______  ______   _______  _______   _________ _        _______  _______  _______  _______  _______ __________________ _______  _       \n");
	printf("(  ___  )(  __  \\ (  __  \\   (       )(  ____ \\(       )(  ____ \\(  ___ \\ (  ____ \\(  ____ )  \\__   __/( (    /|(  ____ \\(  ___  )(  ____ )(       )(  ___  )\\__   __/\\__   __/(  ___  )( (    /|\n");
	printf("| (   ) || (  \\  )| (  \\  )  | () () || (    \\/| () () || (    \\/| (   ) )| (    \\/| (    )|     ) (   |  \\  ( || (    \\/| (   ) || (    )|| () () || (   ) |   ) (      ) (   | (   ) ||  \\  ( |\n");
	printf("| (___) || |   ) || |   ) |  | || || || (__    | || || || (__    | (__/ / | (__    | (____)|     | |   |   \\ | || (__    | |   | || (____)|| || || || (___) |   | |      | |   | |   | ||   \\ | |\n");
	printf("|  ___  || |   | || |   | |  | |(_)| ||  __)   | |(_)| ||  __)   |  __ (  |  __)   |     __)     | |   | (\\ \\) ||  __)   | |   | ||     __)| |(_)| ||  ___  |   | |      | |   | |   | || (\\ \\) |\n");
	printf("| (   ) || |   ) || |   ) |  | |   | || (      | |   | || (      | (  \\ \\ | (      | (\\ (        | |   | | \\   || (      | |   | || (\\ (   | |   | || (   ) |   | |      | |   | |   | || | \\   |\n");
	printf("| )   ( || (__/  )| (__/  )  | )   ( || (____/\\| )   ( || (____/\\| )___) )| (____/\\| ) \\ \\__  ___) (___| )  \\  || )      | (___) || ) \\ \\__| )   ( || )   ( |   | |   ___) (___| (___) || )  \\  |\n");
	printf("|/     \\|(______/ (______/   |/     \\|(_______/|/     \\|(_______/|/ \\___/ (_______/|/   \\__/  \\_______/|/    )_)|/       (_______)|/   \\__/|/     \\||/     \\|   )_(   \\_______/(_______)|/    )_)\n");



	do {
		printf("Do you want to add new record (Y:yes or N:no)?");
		rewind(stdin);
		scanf("%c", &yes);
		if (yes == 'y' || yes == 'Y') {
			printf("How many you want to add new record >");
			rewind(stdin);
			if (scanf("%d", &how) != 1) {
				printf("Please enter a number\n");
				scanf("%d", &how);
			}
			int a = 0;
			for (int i = 1; i <= how; i++) {
				printf("Enter member ID (M####)>");
				rewind(stdin);
				scanf("%[^\n]", memberID);
				while (1) {
					int result = validateMemberID(memberID, member, j);
					if (result == 1) {
						strcpy(member[i].memberID, memberID);
						break;
					}
					else if (result == 0) {
						printf("Please enter a different member ID (M####) >");
					}
					else if (result == -1) {
						printf("Please enter the right format member ID(M####)>");
					}
					rewind(stdin);
					scanf("%[^\n]", memberID);
				}
				printf("Enter name > ");
				rewind(stdin);
				scanf("%[^\n]", member[i].name);
				while (!validateName(member[i].name)) {
					printf("Please enter alphabets only >");
					rewind(stdin);
					scanf("%[^\n]", member[i].name);
				}
				printf("Enter IC (############)>");
				rewind(stdin);
				scanf("%[^\n]", IC);
				while (1) {
					int result = validateIC(IC, member, j);
					if (result == 1) {
						strcpy(member[i].IC, IC);
						break;
					}
					else if (result == 0) {
						printf("Please enter a different IC (############) >");
					}
					else if (result == -1) {
						printf("Please enter the right format of IC(############)>");
					}
					rewind(stdin);
					scanf("%[^\n]", IC);
				}
				if ((IC[11] - '0') % 2 == 0) {
					member[i].gender = 'F';
				}
				else {
					member[i].gender = 'M';
				}
				printf("Gender > %c\n", member[i].gender);
				printf("Enter contact number(0##-######) >");
				rewind(stdin);
				scanf("%[^\n]", contactNumber);
				while (1) {
					int result = validateContactNumber(contactNumber, member, j);
					if (result == 1) {
						strcpy(member[i].contactNumber, contactNumber);
						break;
					}
					else if (result == 0) {
						printf("Please enter a different contact number (0##-######) >");
					}
					else if (result == -1) {
						printf("Please enter a correct format contact number (0##-######)>");
					}
					rewind(stdin);
					scanf("%[^\n]", contactNumber);
				}
				printf("Enter up line ID (U###)> ");
				rewind(stdin);
				scanf("%[^\n]", uplineID);
				while (1) {
					int result = validateUplineID(uplineID, member, j);
					if (result == 1) {
						strcpy(member[i].uplineID, uplineID);
						break;
					}
					else if (result == 0) {
						printf("Please enter a different uplineID (U###) >");
					}
					else if (result == -1) {
						printf("Please enter the right format uplineID(U###)>");
					}
					rewind(stdin);
					scanf("%[^\n]", uplineID);
				}
				printf("Enter the referral uplineID (U###)> ");
				rewind(stdin);
				scanf("%[^\n]", &member[i].referral);
				int isValidReferralID = validateReferralID(member[i].referral, member, j);
				while (!isValidReferralID) {
					printf("Please enter the correct referral uplineID (U###) that matches an existing uplineID >");
					rewind(stdin);
					scanf("%[^\n]", &member[i].referral);

					isValidReferralID = validateReferralID(member[i].referral, member, j);
				}
				printf("Please enter email(XXX@gmail.com) >");
				rewind(stdin);
				scanf("%[^\n]", &email);
				int result;
				while (1) {
					result = validateEmail(email, member, j);
					if (result == 1) {
						strcpy(member[i].email, email);
						break;
					}
					else if (result == 0) {
						printf("Please enter a different email (XXX@gmail.com) that is not already taken >");
					}
					else if (result == -1) {
						printf("Please enter correct email format (XXX@gmail.com)>");
					}
					rewind(stdin);
					scanf("%[^\n]", email);
				}
				printf("Please enter the date of birth (YYYY-MM-DD) >");
				rewind(stdin);
				scanf("%d-%d-%d", &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day);
				validate(member[i].dateOfBirth.year, member[i].dateOfBirth.month, member[i].dateOfBirth.day);
				printf("Please enter the address >");
				rewind(stdin);
				scanf("%[^\n]", &member[i].address);
				a++;
				fprintf(fp, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[i].memberID, member[i].name, member[i].gender, member[i].IC, member[i].contactNumber, member[i].uplineID, member[i].referral, member[i].email, member[i].dateOfBirth.year, member[i].dateOfBirth.month, member[i].dateOfBirth.day, member[i].address);
			}
			printf("You already add %d records.\n", a);
		}
	} while (yes == 'y' || yes == 'Y');
	system("pause");
	system("cls");
	fclose(fp);
}

void memberSearch() {
	struct member member[50];
	char need;
	char memberID[50], name[50], contactNumber[50], IC[50], uplineID[50], dateOfBirth[50], referral[50];
	char what[50];
	FILE* fp = fopen("member.txt", "r");

	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int i = 0;
	while (fscanf(fp, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[i].memberID, &member[i].name, &member[i].gender, &member[i].IC, &member[i].contactNumber, &member[i].uplineID, &member[i].referral, &member[i].email, &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day, &member[i].address) != EOF) {
		i++;
	};
	printf(" _______  _______  _______  _______  _______             _______  _______  _______  _______  ______   _______  _______   _________ _        _______  _______  _______  _______  _______ __________________ _______  _       \n");
	printf("(  ____ \\(  ____ \\(  ___  )(  ____ )(  ____ \\|\\     /|  (       )(  ____ \\(       )(  ____ \\(  ___ \\ (  ____ \\(  ____ )  \\__   __/( (    /|(  ____ \\(  ___  )(  ____ )(       )(  ___  )\\__   __/\\__   __/(  ___  )( (    /|\n");
	printf("| (    \\/| (    \\/| (   ) || (    )|| (    \\/| )   ( |  | () () || (    \\/| () () || (    \\/| (   ) )| (    \\/| (    )|     ) (   |  \\  ( || (    \\/| (   ) || (    )|| () () || (   ) |   ) (      ) (   | (   ) ||  \\  ( |\n");
	printf("| (_____ | (__    | (___) || (____)|| |      | (___) |  | || || || (__    | || || || (__    | (__/ / | (__    | (____)|     | |   |   \\ | || (__    | |   | || (____)|| || || || (___) |   | |      | |   | |   | ||   \\ | |\n");
	printf("(_____  )|  __)   |  ___  ||     __)| |      |  ___  |  | |(_)| ||  __)   | |(_)| ||  __)   |  __ (  |  __)   |     __)     | |   | (\\ \\) ||  __)   | |   | ||     __)| |(_)| ||  ___  |   | |      | |   | |   | || (\\ \\)|\n");
	printf("      ) || (      | (   ) || (\\ (   | |      | (   ) |  | |   | || (      | |   | || (      | (  \\ \\ | (      | (\\ (        | |   | | \\   || (      | |   | || (\\ (   | |   | || (   ) |   | |      | |   | |   | || | \\   |\n");
	printf("/\\____) || (____/\\| )   ( || ) \\ \\__| (____/\\| )   ( |  | )   ( || (____/\\| )   ( || (____/\\| )___) )| (____/\\| ) \\ \\__  ___) (___| )  \\  || )      | (___) || ) \\ \\__| )   ( || )   ( |   | |   ___) (___| (___) || )  \\  |\n");
	printf("\\_______)(_______/|/     \\||/   \\__/(_______/|/     \\|  |/     \\|(_______/|/     \\|(_______/|/ \\___/ (_______/|/   \\__/  \\_______/|/    )_)|/       (_______)|/   \\__/|/     \\||/     \\|   )_(   \\_______/(_______)|/    )_)\n");

	do {
		printf("Do you need to search (Y:yes or N:no) >");
		rewind(stdin);
		scanf("%c", &need);
		if (need == 'Y' || need == 'y') {
			printf("What you want to seach(memberID,name,IC,contact number,uplineID or referralID) >");
			rewind(stdin);
			scanf("%[^\n]", &what);
			while (strcmp(what, "memberID") != 0 && strcmp(what, "name") != 0 && strcmp(what, "IC") != 0 && strcmp(what, "contact number") != 0 && strcmp(what, "uplineID") != 0 && strcmp(what, "referralID") != 0) {
				printf("Please enter the right thing (memberID,name,IC,contact number,uplineID or referralID) >");
				rewind(stdin);
				scanf("%[^\n]", &what);
			}
			if (strcmp("memberID", what) == 0) {
				printf("Enter the memberID (M####)>");
				rewind(stdin);
				scanf("%[^\n]", &memberID);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].memberID, memberID) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n", member[j].address);
						found = 1;
						break;
					}
				}
				while (!found) {
					printf("Please enter a valid memberID (M####)>");
					rewind(stdin);
					scanf("%[^\n]", &memberID);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].memberID, memberID) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n", member[j].address);
							found = 1;
							break;
						}
					}
				}
			}
			else if (strcmp("name", what) == 0) {
				printf("Enter the name >");
				rewind(stdin);
				scanf("%[^\n]", &name);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].name, name) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n", member[j].address);
						found = 1;
						break;
					}
				}
				while (!found) {
					printf("Please enter a valid name >");
					rewind(stdin);
					scanf("%[^\n]", &name);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].name, name) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n", member[j].address);
							found = 1;
							break;
						}
					}
				}
			}
			else if (strcmp("IC", what) == 0) {
				printf("Enter the IC (############) >");
				rewind(stdin);
				scanf("%[^\n]", &IC);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].IC, IC) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n", member[j].address);
						found = 1;
						break;
					}
				}
				while (!found) {
					printf("Please enter a valid IC (############) >");
					rewind(stdin);
					scanf("%[^\n]", &IC);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].IC, IC) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n", member[j].address);
							found = 1;
							break;
						}
					}
				}
			}
			else if (strcmp("contact number", what) == 0) {
				printf("Enter the contact number (0##-#######)>");
				rewind(stdin);
				scanf("%[^\n]", &contactNumber);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].contactNumber, contactNumber) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n", member[j].address);
						found = 1;
						break;
					}
				}
				while (!found) {
					printf("Please enter a valid contact number(0##-#######) >");
					rewind(stdin);
					scanf("%[^\n]", &contactNumber);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].contactNumber, contactNumber) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n", member[j].address);
							found = 1;
							break;
						}
					}
				}
			}
			else if (strcmp("uplineID", what) == 0) {
				printf("Enter the uplineID (U###)>");
				rewind(stdin);
				scanf("%[^\n]", &uplineID);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].uplineID, uplineID) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n", member[j].address);
						found = 1;
						break;
					}
				}
				while (!found) {
					printf("Please enter a valid uplineID (U###)>");
					rewind(stdin);
					scanf("%[^\n]", &uplineID);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].uplineID, uplineID) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n", member[j].address);
							break;
						}
					}
				}
			}
			else if (strcmp("referralID", what) == 0) {
				printf("Enter the referral ID (U###)>");
				rewind(stdin);
				scanf("%[^\n]", &referral);
				int found = 0;
				for (int j = 0; j <= i; j++) {
					if (strcmp(member[j].referral, referral) == 0) {
						printf("MemberID:%s\n", member[j].memberID);
						printf("Name:%s\n", member[j].name);
						printf("Gender:%c\n", member[j].gender);
						printf("IC:%s\n", member[j].IC);
						printf("Contact Number:%s\n", member[j].contactNumber);
						printf("Upline ID:%s\n", member[j].uplineID);
						printf("Referral ID:%s\n", member[j].referral);
						printf("Email :%s\n", member[j].email);
						printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
						printf("Address :%s\n\n", member[j].address);
						found = 1;
					}
				}
				while (!found) {
					printf("Please enter a valid referral ID (U###)>");
					rewind(stdin);
					scanf("%[^\n]", &referral);
					for (int j = 0; j <= i; j++) {
						if (strcmp(member[j].referral, referral) == 0) {
							printf("MemberID:%s\n", member[j].memberID);
							printf("Name:%s\n", member[j].name);
							printf("Gender:%c\n", member[j].gender);
							printf("IC:%s\n", member[j].IC);
							printf("Contact Number:%s\n", member[j].contactNumber);
							printf("Upline ID:%s\n", member[j].uplineID);
							printf("Referral ID:%s\n", member[j].referral);
							printf("Email :%s\n", member[j].email);
							printf("Date Of Birth :%02d-%02d-%02d\n", member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day);
							printf("Address :%s\n\n", member[j].address);
							found = 1;
						}
					}
				}
			}
			else {
				printf("Please enter the correct seach(memberID,name,IC,contact number,uplineID or referralID)");
				rewind(stdin);
				scanf("%[^\n]", &what);
			}
		}
	} while (need == 'Y' || need == 'y');
	system("pause");
	system("cls");
	fclose(fp);
}

void memberModify() {
	struct member member[50];
	int row;
	char members[50], name[50], gender, IC[50], contactNumber[50], uplineID[50], referralID[50], email[50], dateOfBirth[50], address[50];
	char want, which[50];
	FILE* fp = fopen("member.txt", "r");

	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int i = 0;
	while (fscanf(fp, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[i].memberID, &member[i].name, &member[i].gender, &member[i].IC, &member[i].contactNumber, &member[i].uplineID, &member[i].referral, &member[i].email, &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day, &member[i].address) != EOF) {
		i++;
	};
	int maxRow = i;
	printf("----------------------------\n");
	printf("|      MODIFY MEMBER       |\n");
	printf("----------------------------\n");
	printf("%-10s %-15s %-8s %-15s %-15s %-8s %-14s %-30s %-19s %s\n", "MemberID", "Name", "Gender", "IC", "Contact Number", "UplineID", "ReferralID", "Email", "Date Of Birth", "Address");
	for (int b = 0; b < i; b++) {
		printf("%-10s %-15s %-8c %-15s %-15s %-8s %-14s %-30s %02d-%02d-%-11d %-15s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
	}

	fclose(fp);
	FILE* fp2 = fopen("member.txt", "w");

	if (!fp2) {
		printf("Error");
		exit(-1);
	}

	do {
		FILE* fp2 = fopen("member.txt", "w");
		printf("Do you want to change anything (Y:yes or N:no)>");
		rewind(stdin);
		scanf("%c", &want);
		if (want != 'y' && want != 'Y') {
			break;
		}
		printf("which one you want to change(memberID,name,IC,contact number,uplineID,referralID,email,date of birth or address) >");
		rewind(stdin);
		scanf("%[^\n]", &which);
		while (strcmp(which, "memberID") != 0 && strcmp(which, "name") != 0 && strcmp(which, "IC") != 0 && strcmp(which, "contact number") != 0 && strcmp(which, "uplineID") != 0 && strcmp(which, "referralID") != 0 && strcmp(which, "email") != 0 && strcmp(which, "date of birth") != 0 && strcmp(which, "address") != 0 && strcmp(which, "emergency name") != 0 && strcmp(which, "emergency contact") != 0) {
			printf("Please enter the right thing(memberID,name,IC,contact number,uplineID,referralID,email,date of birth or address) >");
			rewind(stdin);
			scanf("%[^\n]", &which);
		}
		if (strcmp("memberID", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What memberId you want to change(M####)>");
			rewind(stdin);
			scanf("%[^\n]", &members);
			while (1) {
				int result = validateMemberID(members, member, i);
				if (result == 1) {
					strcpy(member[i].memberID, members);
					break;
				}
				else if (result == 0) {
					printf("Please enter a different member ID (M####) >");
				}
				else if (result == -1) {
					printf("Please enter the right format member ID(M####)>");
				}
				rewind(stdin);
				scanf("%[^\n]", members);
			}
			strcpy(member[row].memberID, members);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("name", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What name you want to change >");
			rewind(stdin);
			scanf("%[^\n]", &name);
			while (!validateName(name)) {
				printf("Please enter alphabet only! > ");
				rewind(stdin);
				scanf("%[^\n]", name);
			}
			strcpy(member[row].name, name);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("IC", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What IC you want to change (############) >");
			rewind(stdin);
			scanf("%[^\n]", &IC);
			while (1) {
				int result = validateIC(IC, member, i);
				if (result == 1) {
					strcpy(member[i].IC, IC);
					break;
				}
				else if (result == 0) {
					printf("Please enter a different IC (############) >");
				}
				else if (result == -1) {
					printf("Please enter the right format of IC(############)>");
				}
				rewind(stdin);
				scanf("%[^\n]", IC);
			}
			strcpy(member[row].IC, IC);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("contact number", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What contact number you want to change (0##-######) >");
			rewind(stdin);
			scanf("%[^\n]", &contactNumber);
			while (1) {
				int result = validateContactNumber(contactNumber, member, i);
				if (result == 1) {
					strcpy(member[i].contactNumber, contactNumber);
					break;
				}
				else if (result == 0) {
					printf("Please enter a different contact number (0##-######) >");
				}
				else if (result == -1) {
					printf("Please enter a correct format contact number (0##-######)>");
				}
				rewind(stdin);
				scanf("%[^\n]", contactNumber);
			}
			strcpy(member[row].contactNumber, contactNumber);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("uplineID", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What uplineID you want to change (U###)>");
			rewind(stdin);
			scanf("%[^\n]", &uplineID);
			while (1) {
				int result = validateUplineID(uplineID, member, i);
				if (result == 1) {
					strcpy(member[i].uplineID, uplineID);
					break;
				}
				else if (result == 0) {
					printf("Please enter a different uplineID (U###) >");
				}
				else if (result == -1) {
					printf("Please enter the right format uplineID(U###)>");
				}
				rewind(stdin);
				scanf("%[^\n]", uplineID);
			}
			strcpy(member[row].uplineID, uplineID);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("referralID", which) == 0) {
			printf("Which row do you want to change (1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;

			printf("What referralID do you want to set (U###)>");
			rewind(stdin);
			scanf("%[^\n]", referralID);
			int isValidReferralID = validateReferralID(member[i].referral, member, i);
			while (!isValidReferralID) {
				printf("Please enter the correct referral uplineID (U###) that matches an existing uplineID >");
				rewind(stdin);
				scanf("%[^\n]", &member[i].referral);

				isValidReferralID = validateReferralID(member[i].referral, member, i);
			}
			strcpy(member[row].referral, referralID);

			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("email", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What email you want to change (XXX@gmail.com)>");
			rewind(stdin);
			scanf("%[^\n]", &email);
			int result;
			while (1) {
				result = validateEmail(email, member, i);
				if (result == 1) {
					strcpy(member[i].email, email);
					break;
				}
				else if (result == 0) {
					printf("Please enter a different email (XXX@gmail.com) that is not already taken >");
				}
				else if (result == -1) {
					printf("Please enter correct email format (XXX@gmail.com)>");
				}
				rewind(stdin);
				scanf("%[^\n]", email);
			}
			strcpy(member[row].email, email);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("date of birth", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What date of birth you want to change (YYYY-MM-DD) >");
			rewind(stdin);
			scanf("%d-%d-%d", &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day);
			validate(member[i].dateOfBirth.year, member[i].dateOfBirth.month, member[i].dateOfBirth.day);
			member[row].dateOfBirth.year = member[i].dateOfBirth.year;
			member[row].dateOfBirth.month = member[i].dateOfBirth.month;
			member[row].dateOfBirth.day = member[i].dateOfBirth.day;
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
		else if (strcmp("address", which) == 0) {
			printf("which row you want to change(1-%d) >", maxRow);
			rewind(stdin);
			scanf("%d", &row);
			while (row < 1 || row > maxRow) {
				printf("Please enter a valid row (1-%d) >", maxRow);
				rewind(stdin);
				scanf("%d", &row);
			}
			row--;
			printf("What address you want to change >");
			rewind(stdin);
			scanf("%[^\n]", &address);
			strcpy(member[row].address, address);
			for (int b = 0; b < i; b++) {
				fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
			}
		}
	} while (want == 'y' || want == 'Y');
	system("pause");
	system("cls");
	fclose(fp2);
}

void memberDisplay() {
	struct member member[50];
	FILE* fp = fopen("member.txt", "r");

	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int i = 0;
	while (fscanf(fp, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[i].memberID, &member[i].name, &member[i].gender, &member[i].IC, &member[i].contactNumber, &member[i].uplineID, &member[i].referral, &member[i].email, &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day, &member[i].address) != EOF) {
		i++;
	};

	fclose(fp);

	for (int j = 0; j < i - 1; j++) {
		for (int k = 0; k < i - j - 1; k++) {
			if (strcmp(member[k].memberID, member[k + 1].memberID) > 0) {
				struct member temp = member[k];
				member[k] = member[k + 1];
				member[k + 1] = temp;
			}
		}
	}

	printf(" ______  _________ _______  _______  _        _______             _______  _______  _______  _______  ______   _______  _______   _________ _        _______  _______  _______  _______  _______ __________________ _______  _       \n");
	printf("(  __  \\ \\__   __/(  ____ \\(  ____ )( \\      (  ___  )|\\     /|  (       )(  ____ \\(       )(  ____ \\(  ___ \\ (  ____ \\(  ____ )  \\__   __/( (    /|(  ____ \\(  ___  )(  ____ )(       )(  ___  )\\__   __/\\__   __/(  ___  )( (    /|\n");
	printf("| (  \\  )   ) (   | (    \\/| (    )|| (      | (   ) |( \\   / )  | () () || (    \\/| () () || (    \\/| (   ) )| (    \\/| (    )|     ) (   |  \\  ( || (    \\/| (   ) || (    )|| () () || (   ) |   ) (      ) (   | (   ) ||  \\  ( |\n");
	printf("| |   ) |   | |   | (_____ | (____)|| |      | (___) | \\ (_) /   | || || || (__    | || || || (__    | (__/ / | (__    | (____)|     | |   |   \\ | || (__    | |   | || (____)|| || || || (___) |   | |      | |   | |   | ||   \\ | |\n");
	printf("| |   | |   | |   (_____  )|  _____)| |      |  ___  |  \\   /    | |(_)| ||  __)   | |(_)| ||  __)   |  __ (  |  __)   |     __)     | |   | (\\ \\) ||  __)   | |   | ||     __)| |(_)| ||  ___  |   | |      | |   | |   | || (\\ \\)|\n");
	printf("| |   ) |   | |         ) || (      | |      | (   ) |   ) (     | |   | || (      | |   | || (      | (  \\ \\ | (      | (\\ (        | |   | | \\   || (      | |   | || (\\ (   | |   | || (   ) |   | |      | |   | |   | || | \\   |\n");
	printf("| (__/  )___) (___/\\____) || )      | (____/\\| )   ( |   | |     | )   ( || (____/\\| )   ( || (____/\\| )___) )| (____/\\| ) \\ \\__  ___) (___| )  \\  || )      | (___) || ) \\ \\__| )   ( || )   ( |   | |   ___) (___| (___) || )  \\  |\n");
	printf("(______/ \\_______/\\_______)|/       (_______/|/     \\|   \\_/     |/     \\|(_______/|/     \\|(_______/|/ \\___/ (_______/|/   \\__/  \\_______/|/    )_)|/       (_______)|/   \\__/|/     \\||/     \\|   )_(   \\_______/(_______)|/    )_)\n");


	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %-10s | %-15s | %-8s | %-15s | %-15s | %-8s | %-10s | %-25s | %-20s |%-38s %-10s\n", "MemberID", "Name", "Gender", "IC", "Contact Number", "UplineID", "ReferralID", "Email", "Date Of Birth", "Address", "|");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int j = 0; j < i; j++) {
		printf("| %-10s | %-15s | %-8c | %-15s | %-15s | %-8s | %-10s | %-25s | %04d-%02d-%-12d | %-20s |\n", member[j].memberID, member[j].name, member[j].gender, member[j].IC, member[j].contactNumber, member[j].uplineID, member[j].referral, member[j].email, member[j].dateOfBirth.year, member[j].dateOfBirth.month, member[j].dateOfBirth.day, member[j].address);
		printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

	system("pause");
	system("cls");
}

void memberDelete() {

	int row;
	struct member member[50];
	FILE* fp = fopen("member.txt", "r");

	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int i = 0;
	while (fscanf(fp, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[i].memberID, &member[i].name, &member[i].gender, &member[i].IC, &member[i].contactNumber, &member[i].uplineID, &member[i].referral, &member[i].email, &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day, &member[i].address) != EOF) {
		i++;
	};
	int maxRow = i;

	printf("%100s\n", "DELETE MEMBER");
	printf("%-10s %-15s %-8s %-15s %-15s %-8s %-14s %-30s %-19s %s\n", "MemberID", "Name", "Gender", "IC", "Contact Number", "UplineID", "ReferralID", "Email", "Date Of Birth", "Address");
	for (int b = 0; b < i; b++) {
		printf("%-10s %-15s %-8c %-15s %-15s %-8s %-14s %-30s %02d-%02d-%-11d %-15s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
	}
	fclose(fp);
	FILE* fp2 = fopen("member.txt", "w");

	if (!fp2) {
		printf("Error");
		exit(-1);
	}

	printf("Which row you want to delete(1 - %d)>", maxRow);
	scanf("%d", &row);

	row--;
	int a = 0;
	for (int p = row; p < i - 1; p++) {
		strcpy(member[p].memberID, member[p + 1].memberID);
		strcpy(member[p].name, member[p + 1].name);
		member[p].gender = member[p + 1].gender;
		strcpy(member[p].IC, member[p + 1].IC);
		strcpy(member[p].contactNumber, member[p + 1].contactNumber);
		strcpy(member[p].uplineID, member[p + 1].uplineID);
		strcpy(member[p].referral, member[p + 1].referral);
		strcpy(member[p].email, member[p + 1].email);
		strcpy(member[p].address, member[p + 1].address);
		member[p].dateOfBirth.year = member[p + 1].dateOfBirth.year;
		member[p].dateOfBirth.month = member[p + 1].dateOfBirth.month;
		member[p].dateOfBirth.day = member[p + 1].dateOfBirth.day;
	}
	i--;
	for (int b = 0; b < i; b++) {
		fprintf(fp2, "%s|%s|%c|%s|%s|%s|%s|%s|%d-%d-%d|%s\n", member[b].memberID, member[b].name, member[b].gender, member[b].IC, member[b].contactNumber, member[b].uplineID, member[b].referral, member[b].email, member[b].dateOfBirth.year, member[b].dateOfBirth.month, member[b].dateOfBirth.day, member[b].address);
	}
	fclose(fp2);
	system("pause");
	system("cls");
}

void memberReport() {
	struct member member[50];
	FILE* fp = fopen("member.txt", "r");
	SYSTEMTIME t;
	GetLocalTime(&t);
	if (!fp) {
		printf("Error");
		exit(-1);
	}

	int i = 0;
	while (fscanf(fp, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &member[i].memberID, &member[i].name, &member[i].gender, &member[i].IC, &member[i].contactNumber, &member[i].uplineID, &member[i].referral, &member[i].email, &member[i].dateOfBirth.year, &member[i].dateOfBirth.month, &member[i].dateOfBirth.day, &member[i].address) != EOF) {
		i++;
	};
	int count = 0, count2 = 0;
	for (int p = 0; p < i; p++) {
		if (member[p].gender == 'F') {
			count++;
		}
		else {
			count2++;
		}
	}
	float percentageFemale = (float)count / i * 100;
	float percentageMale = (float)count2 / i * 100;
	printf("Report Date and Time > %d-%d-%d %02d:%02d\n\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);
	printf("Gender Count Percentage \n");
	printf("---------------------------------\n");
	printf("\nTotal number of members: %d\n", i);
	printf("\nNumber of female members: %d\n", count);
	printf("\nNumber of male members: %d\n", count2);
	printf(" \nPercentage of Female |%.2f%%\n", percentageFemale);
	printf("\nPercentage of Male | %.2f%%\n\n", percentageMale);
	printf("=================================\n");
	printf("All of the member Age\n");
	printf("---------------------------------\n");
	int ageabove18 = 0;
	for (int j = 0; j < i; j++) {
		int age = t.wYear - member[j].dateOfBirth.year;
		printf("Age of %s : %d\n", member[j].name, age);
		if (age > 18) {
			ageabove18++;
		}
	}

	float percentageAbove18 = (float)ageabove18 / i * 100;
	printf("\nPercentage of members above 18 years old: %.2f%%\n", percentageAbove18);
	system("pause");
	system("cls");
}

int validate(int year, int month, int day) {
	while (year < 0 || year > 2023 || month < 0 || month > 12) {
		printf("Please enter a valid date of birth (YYYY-MM-DD): ");
		scanf("%d-%d-%d", &year, &month, &day);
	}

	while (1) {
		switch (month) {
		case 1:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				if (day >= 1 && day <= 29) {
					return 1;
				}
			}
			else {
				if (day >= 1 && day <= 28) {
					return 1;
				}
			}
			break;
		case 3:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 4:
			if (day >= 1 && day <= 30) {
				return 1;
			}
			break;
		case 5:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 6:
			if (day >= 1 && day <= 30) {
				return 1;
			}
			break;
		case 7:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 8:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 9:
			if (day >= 1 && day <= 30) {
				return 1;
			}
			break;
		case 10:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		case 11:
			if (day >= 1 && day <= 30) {
				return 1;
			}
			break;
		case 12:
			if (day >= 1 && day <= 31) {
				return 1;
			}
			break;
		}
		printf("Please enter a valid date of birth (YYYY-MM-DD): ");
		scanf("%d-%d-%d", &year, &month, &day);
	}
}

int validateMemberID(char* memberID, struct member* members, int numMembers) {
	int i, j;
	for (i = 0; i < numMembers; i++) {
		if (strcmp(members[i].memberID, memberID) == 0) {
			return 0;
		}
	}
	if (strlen(memberID) != 5 || memberID[0] != 'M' || !isdigit(memberID[1]) || !isdigit(memberID[2]) || !isdigit(memberID[3]) || !isdigit(memberID[4])) {
		return -1;
	}
	return 1;
}

char validateName(const char* name) {
	for (int i = 0; i < strlen(name); i++) {
		if (isdigit(name[i])) {
			return 0;
		}
	}
	return 1;
}

int validateIC(char* IC, struct member* member, int numMembers) {
	int i, j;
	for (i = 0; i < numMembers; i++) {
		if (strcmp(member[i].IC, IC) == 0) {
			return 0;
		}
	}
	if (strlen(IC) != 12 || !isdigit(IC[0]) || !isdigit(IC[1]) || !isdigit(IC[2]) || !isdigit(IC[3]) || !isdigit(IC[4]) || !isdigit(IC[5]) || !isdigit(IC[6]) || !isdigit(IC[7]) || !isdigit(IC[8]) || !isdigit(IC[9]) || !isdigit(IC[10]) || !isdigit(IC[11])) {
		return -1;
	}
	return 1;
}

int validateContactNumber(char* contactNumber, struct member* member, int numMembers) {
	int i, j;
	for (i = 0; i < numMembers; i++) {
		if (strcmp(member[i].contactNumber, contactNumber) == 0) {
			return 0;
		}
	}
	if (strlen(contactNumber) != 11 && contactNumber[0] != '0' || !isdigit(contactNumber[1]) || !isdigit(contactNumber[2]) || contactNumber[3] != '-' || !isdigit(contactNumber[4]) || !isdigit(contactNumber[5]) || !isdigit(contactNumber[6]) || !isdigit(contactNumber[7]) || !isdigit(contactNumber[8]) || !isdigit(contactNumber[9]) || !isdigit(contactNumber[10])) {
		return -1;
	}
	return 1;
}

int validateUplineID(char* uplineID, struct member* member, int numMembers) {
	int i, j;
	for (int i = 0; i < numMembers; i++) {
		if (strcmp(member[i].uplineID, uplineID) == 0) {
			return 0;
		}
	}
	if (strlen(uplineID) != 4 || uplineID[0] != 'U' || !isdigit(uplineID[1]) || !isdigit(uplineID[2]) || !isdigit(uplineID[3])) {
		return -1;
	}
	return 1;
}

int validateReferralID(char* referralID, struct member* member, int numMembers) {
	int flag = 0;
	for (int k = 0; k < numMembers; k++) {
		if (strcmp(member[k].uplineID, referralID) == 0) {
			flag = 1;
			break;
		}
	}
	if (!flag || strlen(referralID) != 4 || referralID[0] != 'U' || !isdigit(referralID[1]) || !isdigit(referralID[2]) || !isdigit(referralID[3])) {
		return 0;
	}
	return 1;
}

int validateEmail(char* email, struct member* member, int numMembers) {
	if (strstr(email, "@gmail.com") == NULL) {
		return -1;
	}
	for (int i = 0; i < numMembers; i++) {
		if (strcmp(member[i].email, email) == 0) {
			return 0;
		}
	}
	return 1;
}

/*========= SALES MODULE - CHONG MING LI =========*/
void salesMain() {
	// Main Variables
	int addCount = 0, loop = 0;
	Sales sales[1000];
	Sales addSales[100];
	Sales filtered[100];
	struct member memRecord[100];

	// Sales Menu
	do {
		system("cls");
		switch (salesMenu()) {
		case 1:
			system("cls");
			// Add Sales Function |ps: addCount is to continue from where Add Sales left off if the user were to stop adding sales and come back to add more.
			addCount = addSale(addSales, addCount, sales);
			system("cls");
			break;
		case 2:
			system("cls");
			// Search Sales Function |ps: matching number of sales needed to be stored to pass into displaySales function.
			int matching = saleSearch(searchOptions(), sales, readSalesFile(sales), filtered);
			if (matching != 0) {
				displaySales(filtered, matching);
			}
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			// Modify Sales Function
			modifySale(sales);
			system("cls");
			break;
		case 4:
			system("cls");
			// Display All Sales Function
			displaySales(sales, readSalesFile(sales));
			system("pause");
			system("cls");
			break;
		case 5:
			// Delete Sales Function
			deleteSales(sales);
			system("cls");
			break;
		case 6:
			// Report Function
			salesReport(sales);
			system("pause");
			system("cls");
			break;
		case 7:
			// Rearrange Function
			rearrange(sales, readSalesFile(sales));
			system("pause");
			system("cls");
			break;
		case 8:
			// Commission Summary Function
			system("cls");
			commission(memRecord, sales);
			system("pause");
			system("cls");
			break;
		default:
			// Back to main menu
			loop = 1;
			printf("\nGoing back to Sole Haven Main Menu! \n\n");
			system("pause");
		}
	} while (loop == 0);
}

//Add Sales Function
int addSale(Sales* sales, int count, Sales* mSale) {
	struct member memRecord[100];
	Stock stkRecord[100];
	int checkSO;
	double tax = 0.06;
	double com = 0.05;

	do {
		system("cls");
		printf("Adding a new sales order record...\n");

		//Sales order ID
		do {
			printf("\nEnter the Sales Order ID (SXXXX): ");
			rewind(stdin);
			scanf("%s", &sales[count].salesOrderID);
			if ((checkSO = codeValidation(sales[count].salesOrderID, 'S', "Sales Order ID")) == 1) {
				checkSO = salesDupe(sales[count].salesOrderID, mSale);
			}

		} while (checkSO == 0);

		//Member ID

		do {
			printf("\nEnter the Member ID (MXXXX): ");
			rewind(stdin);
			scanf("%s", &sales[count].memberID);
		} while (codeValidation(sales[count].memberID, 'M', "Member ID") == 0 || isExistingMember(sales[count].memberID, memRecord, scanMemberFile(memRecord)) == 0);

		int totalStock = readStockFile(stkRecord);

		//Item code
		do {
			printf("\nEnter the Item Code (VXXXX): ");
			rewind(stdin);
			scanf("%s", &sales[count].itemCode);
		} while (codeValidation(sales[count].itemCode, 'V', "Item Code") == 0 || isExistingItem(sales[count].itemCode, stkRecord, totalStock) == 0 || isMinimumLevel(sales[count].itemCode, stkRecord, totalStock) == 0);

		//Sales quantity
		do {
			printf("\nEnter the Sales Quantity: ");
			rewind(stdin);
			scanf("%d", &sales[count].salesQuantity);
		} while (integerValidation("sales quantity", sales[count].salesQuantity, 1, 100) == 0 || checkAvailableStock(sales[count].salesQuantity, sales[count].itemCode, stkRecord, totalStock) == 0);

		int updatedPrice = 0;
		//Auto enter sales price based on stock module item price
		for (int i = 0; i < readStockFile(stkRecord); i++) {
			if (strcmp(sales[count].itemCode, stkRecord[i].itemCode) == 0) {
				sales[count].salesPrice = stkRecord[i].itemPrice;
				updatedPrice++;
			}
		}
		//If price could not be found
		if (updatedPrice = 0) {
			printf("\nAn error has occured, the price for the item could not be found. Exiting the add sales function...\n\n");
			system("pause");
			exit(-1);
		}

		//Total
		sales[count].total = sales[count].salesQuantity * sales[count].salesPrice;

		//Taxed amount
		sales[count].taxed = sales[count].total * tax;

		//Grand total
		sales[count].grandTotal = sales[count].total + sales[count].taxed;

		//Commission
		sales[count].commission = sales[count].grandTotal * com;

		//Payment method
		do {
			printf("\nEnter the Payment Method (Cash/E-wallet): ");
			rewind(stdin);
			scanf("%s", sales[count].paymentMethod);
		} while (paymentValidation(sales[count].paymentMethod) == 0);

		//Sales date
		do {
			printf("\nEnter the Sales Date (DD/MM/YYYY): ");
			rewind(stdin);
			scanf("%d/%d/%d", &sales[count].date.day, &sales[count].date.month, &sales[count].date.year);
		} while (dateValidation(sales[count].date.day, sales[count].date.month, sales[count].date.year) == 0);

		appendSalesFile(sales, count);
		minusCurrentStock(sales[count].salesQuantity, sales[count].itemCode, stkRecord, totalStock);

		count++;

		printf("\nDo you want to add another sale? (Y/N) ");

	} while (choiceSelection() == 'Y');

	return count;
}

//Sales Search Function
int saleSearch(int choice, Sales* sales, int count, Sales* filtered) {
	Sales search;
	int check, j = 0;
	char wrongChoice[50];

	if (choice == 1) {
		do {
			printf("Enter the Sales Order ID (SXXXX): ");
			rewind(stdin);
			scanf("%s", &search.salesOrderID);
		} while (codeValidation(search.salesOrderID, 'S', "Sales Order ID") == 0);

		for (int i = 0; i < count; i++) {
			if (strcmp(search.salesOrderID, sales[i].salesOrderID) == 0) {
				filtered[j] = sales[i];
				j++;
			}
		}
	}
	else if (choice == 2) {
		do {
			printf("Enter the Member ID (MXXXX): ");
			rewind(stdin);
			scanf("%s", &search.memberID);
		} while (codeValidation(search.memberID, 'M', "Member ID") == 0);

		for (int i = 0; i < count; i++) {
			if (strcmp(search.memberID, sales[i].memberID) == 0) {
				filtered[j] = sales[i];
				j++;
			}
		}
	}
	else if (choice == 3) {
		do {
			printf("Enter the Item Code (VXXXX): ");
			rewind(stdin);
			scanf("%s", &search.itemCode);
		} while (codeValidation(search.itemCode, 'V', "Item Code") == 0);

		for (int i = 0; i < count; i++) {
			if (strcmp(search.itemCode, sales[i].itemCode) == 0) {
				filtered[j] = sales[i];
				j++;
			}
		}
	}
	else if (choice == 4) {
		do {
			printf("Enter the Sales Quantity: ");
			rewind(stdin);
			scanf("%d", &search.salesQuantity);
		} while (integerValidation("sales quantity", search.salesQuantity, 1, 100) == 0);


		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.salesQuantity <= sales[i].salesQuantity) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.salesQuantity >= sales[i].salesQuantity) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 5) {
		do {
			printf("Enter the Sales Price (RM): ");
			rewind(stdin);
			scanf("%lf", &search.salesPrice);
		} while (decimalValidation("price", search.salesPrice, 1, 1000) == 0);

		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.salesPrice <= sales[i].salesPrice) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.salesPrice >= sales[i].salesPrice) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 6) {
		do {
			printf("Enter the Total (Before Tax): ");
			rewind(stdin);
			scanf("%lf", &search.total);
		} while (decimalValidation("total amount", search.total, 1, 100000) == 0);

		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.total <= sales[i].total) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.total >= sales[i].total) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 7) {
		do {
			printf("Enter the Taxed Amount: ");
			rewind(stdin);
			scanf("%lf", &search.taxed);
		} while (decimalValidation("taxed amount", search.taxed, 0.06, 6000) == 0);

		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.taxed <= sales[i].taxed) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.taxed >= sales[i].taxed) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 8) {
		do {
			printf("Enter the Grand Total (After Tax): ");
			rewind(stdin);
			scanf("%lf", &search.grandTotal);
		} while (decimalValidation("grand total", search.grandTotal, 1.06, 106000) == 0);

		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.grandTotal <= sales[i].grandTotal) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.grandTotal >= sales[i].grandTotal) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 9) {
		do {
			printf("Enter the Commission Amount: ");
			rewind(stdin);
			scanf("%lf", &search.commission);
		} while (decimalValidation("commission", search.commission, 0.05, 5300) == 0);

		if (moreOrLess() == 1) {
			for (int i = 0; i < count; i++) {
				if (search.commission <= sales[i].commission) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.commission >= sales[i].commission) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else if (choice == 10) {
		do {
			printf("Enter the Payment Method (Cash/E-wallet): ");
			rewind(stdin);
			scanf("%s", &search.paymentMethod);
		} while (paymentValidation(search.paymentMethod) == 0);

		for (int i = 0; i < count; i++) {
			if (strcmp(search.paymentMethod, sales[i].paymentMethod) == 0) {
				filtered[j] = sales[i];
				j++;
			}
		}
	}
	else if (choice == 11) {
		do {
			printf("Enter the Sales Date (DD/MM/YYYY): ");
			rewind(stdin);
			scanf("%d/%d/%d", &search.date.day, &search.date.month, &search.date.year);
			check = dateValidation(search.date.day, search.date.month, search.date.year);
		} while (check == 0);

		do {
			printf("\nDo you want to search for records that are this date and after or this date and before?\n\n");
			printf("(1 = This and After, 2 = This and Before) > ");
			rewind(stdin);
			if (scanf("%d", &check) != 1) {
				scanf("%[^\n]", &wrongChoice);
				check = 0;
				printf("\nError: '%s' is not an integer, please enter a value of 1 - 2.\n\n", wrongChoice);
			}
			else if (check < 1 || check > 2) {
				printf("\nError: '%d' is not an option, please enter a value of 1 - 2.\n\n", check);
				check = 0;
			}
		} while (check == 0);

		if (check == 1) {
			for (int i = 0; i < count; i++) {
				if (search.date.year < sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.month < sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.day < sales[i].date.day && search.date.month == sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.day == sales[i].date.day && search.date.month == sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
		else {
			for (int i = 0; i < count; i++) {
				if (search.date.year > sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.month > sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.day > sales[i].date.day && search.date.month == sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
				else if (search.date.day == sales[i].date.day && search.date.month == sales[i].date.month && search.date.year == sales[i].date.year) {
					filtered[j] = sales[i];
					j++;
				}
			}
		}
	}
	else {
		printf("\nGoing back to Sales Menu. ");
		return 0;
	}

	if (j == 0) {
		printf("\nNo matching records found!\n\n");
	}
	else {
		printf("\n%d matching records found!\n\n", j);
	}

	return j;
}

//Modify Sales Function
void modifySale(Sales* sales) {
	struct member memRecord[100];
	Stock stkRecord[100];
	Sales edit;
	Date new;
	char choice, wrongChoice[50];
	int retry = 0, check, j = -1;

	system("cls");

	//Loop back to modification menu
	do {
		printf("Modification Menu\n");
		switch (preOptions("Continue to modifications")) {
		case 1:
			//Enter Sales Order ID to compare
			do {
				printf("\nEnter the Sales Order ID you want to modify (SXXXX): ");
				rewind(stdin);
				scanf("%s", &edit.salesOrderID);

			} while (codeValidation(edit.salesOrderID, 'S', "Sales Order ID") == 0);

			//Read binary file and compare for matching Sales Order ID
			int totalSales = readSalesFile(sales);

			for (int i = 0; i < totalSales; i++) {
				if (strcmp(edit.salesOrderID, sales[i].salesOrderID) == 0) {
					printf("\nThis is the record that has been found: \n");
					salesHead();
					salesDataFields();
					printf("|--------|---------|---------|--------|------------|------------|------------------|-----------|---------------|--------------|----------|\n");
					printf("|%8s|%9s|%9s|%8d|RM%10.2lf|RM%10.2lf|RM%16.2lf|RM%9.2lf|RM%13.2lf|%14s|%02d/%02d/%4d|\n", sales[i].salesOrderID, sales[i].memberID,
						sales[i].itemCode, sales[i].salesQuantity, sales[i].salesPrice, sales[i].total, sales[i].taxed, sales[i].grandTotal,
						sales[i].commission, sales[i].paymentMethod, sales[i].date.day, sales[i].date.month, sales[i].date.year);
					salesFoot();
					j = i;
				}
			}

			//Shows no matching records
			if (j == -1) {
				printf("The following Sales Order ID does not exist.\n\n");
				printf("Going back to modification menu... ");
				system("pause");
				system("cls");
				break;
			}

			//Modification confirmation

			printf("\nContinue to modify this record? (Y/N) ");

			//Does not want to edit this record
			if (choiceSelection() == 'N') {
				system("cls");
				printf("Modification cancelled, back to Modification Menu...\n\n");
				break;
			}

			//Select data field to modify
			system("cls");
			printf("============================================\n");
			printf("| Keys available to Modify:                |\n");
			printf("|------------------------------------------|\n");
			printf("| 1) All Data Fields                       |\n");
			printf("|------------------------------------------|\n");
			printf("| 2) Member ID                             |\n");
			printf("|------------------------------------------|\n");
			printf("| 3) Item Code                             |\n");
			printf("|------------------------------------------|\n");
			printf("| 4) Quantity of Item Sold                 |\n");
			printf("|------------------------------------------|\n");
			printf("| 5) Payment Method                        |\n");
			printf("|------------------------------------------|\n");
			printf("| 6) Date of Item Sold                     |\n");
			printf("============================================\n");

			printf("\nSelect one of the options (1 - 6) ");

			check = menuSelection(6);

			if (check == 1) {
				system("cls");
				printf("Editing all data fields - \n");
				//Member ID
				do {
					printf("\nEnter the new Member ID (MXXXX): ");
					rewind(stdin);
					scanf("%s", &sales[j].memberID);
				} while (codeValidation(sales[j].memberID, 'M', "Member ID") == 0 || isExistingMember(sales[j].memberID, memRecord, scanMemberFile(memRecord)) == 0);

				//Item code
				do {
					printf("\nEnter the new Item Code (VXXXX): ");
					rewind(stdin);
					scanf("%s", &sales[j].itemCode);
				} while (codeValidation(sales[j].itemCode, 'V', "Item Code") == 0 || isExistingItem(sales[j].itemCode, stkRecord, readStockFile(stkRecord)) == 0);

				//Sales quantity
				do {
					printf("\nEnter the new Sales Quantity: ");
					rewind(stdin);
					scanf("%d", &sales[j].salesQuantity);
				} while (integerValidation("sales quantity", sales[j].salesQuantity, 1, 100));

				//Total
				sales[j].total = sales[j].salesQuantity * sales[j].salesPrice;

				//Taxed amount
				sales[j].taxed = sales[j].total * 0.06;

				//Grand total
				sales[j].grandTotal = sales[j].total + sales[j].taxed;

				//Commission
				sales[j].commission = sales[j].grandTotal * 0.05;

				//Payment method
				do {
					printf("\nEnter the new Payment Method (Cash/E-wallet): ");
					rewind(stdin);
					scanf("%s", sales[j].paymentMethod);
				} while (paymentValidation(sales[j].paymentMethod) == 0);

				//Sales date
				do {
					printf("\nEnter the new Sales Date (DD/MM/YYYY): ");
					rewind(stdin);
					scanf("%d/%d/%d", &new.day, &new.month, &new.year);
				} while (dateValidation(new.day, new.month, new.year) == 0);
				sales[j].date.day = new.day;
				sales[j].date.month = new.month;
				sales[j].date.year = new.year;
			}
			else if (check == 2) {
				system("cls");
				printf("Editing the Member ID data field - \n");
				//Member ID
				do {
					printf("\nEnter the new Member ID (MXXXX): ");
					rewind(stdin);
					scanf("%s", &sales[j].memberID);
				} while (codeValidation(sales[j].memberID, 'M', "Member ID") == 0 || isExistingMember(sales[j].memberID, memRecord, scanMemberFile(memRecord)) == 0);
			}
			else if (check == 3) {
				system("cls");
				printf("Editing the Item Code data field - \n");
				//Item code
				do {
					printf("\nEnter the new Item Code (VXXXX): ");
					rewind(stdin);
					scanf("%s", &sales[j].itemCode);
				} while (codeValidation(sales[j].itemCode, 'V', "Item Code") == 0 || isExistingItem(sales[j].itemCode, stkRecord, readStockFile(stkRecord)) == 0);
			}
			else if (check == 4) {
				system("cls");
				printf("Editing the Quantity data field - \n");
				//Sales quantity
				do {
					printf("\nEnter the new Sales Quantity: ");
					rewind(stdin);
					scanf("%d", &sales[j].salesQuantity);
				} while (integerValidation("sales quantity", sales[j].salesQuantity, 1, 100) == 0);

				//Total
				sales[j].total = sales[j].salesQuantity * sales[j].salesPrice;

				//Taxed amount
				sales[j].taxed = sales[j].total * 0.06;

				//Grand total
				sales[j].grandTotal = sales[j].total + sales[j].taxed;

				//Commission
				sales[j].commission = sales[j].grandTotal * 0.05;
			}
			else if (check == 5) {
				system("cls");
				printf("Editing the Payment Method data field - \n");
				//Payment method
				do {
					printf("\nEnter the new Payment Method (Cash/E-wallet): ");
					rewind(stdin);
					scanf("%s", sales[j].paymentMethod);
				} while (paymentValidation(sales[j].paymentMethod) == 0);
			}
			else if (check == 6) {
				system("cls");
				printf("Editing the Date data field - \n");
				//Date
				do {
					printf("\nEnter the new Sales Date (DD/MM/YYYY): ");
					rewind(stdin);
					scanf("%d/%d/%d", &new.day, &new.month, &new.year);
				} while (dateValidation(new.day, new.month, new.year) == 0);
				sales[j].date.day = new.day;
				sales[j].date.month = new.month;
				sales[j].date.year = new.year;
			}

			//Writing new modifications into file
			writeSalesFile(sales, totalSales, -1);
			//Modification completion
			printf("\nModifications complete!\n\n");
			system("pause");
			retry = 1;
			break;
		case 2:
			system("cls");

			displaySales(sales, readSalesFile(sales));

			system("pause");
			system("cls");
			break;
		default:
			retry = 1;
			printf("\nGoing back to sales menu... ");
			system("pause");
		}
	} while (retry == 0);
}

//Display Sales Function
void displaySales(Sales* sales, int count) {
	printf("  ____        _             ____  _           _             \n");
	printf(" / ___|  __ _| | ___  ___  |  _ \\(_)___ _ __ | | __ _ _   _ \n");
	printf(" \\___ \\ / _` | |/ _ \\/ __| | | | | / __| '_ \\| |/ _` | | | |\n");
	printf("  ___) | (_| | |  __/\\__ \\ | |_| | \\__ \\ |_) | | (_| | |_| |\n");
	printf(" |____/ \\__,_|_|\\___||___/ |____/|_|___/ .__/|_|\\__,_|\\__, |\n");
	printf("                                       |_|            |___/ \n\n");

	salesHead();
	salesDataFields();
	for (int i = 0; i < count; i++) {
		printf("|--------|---------|---------|--------|------------|------------|------------------|-----------|---------------|--------------|----------|\n");
		printf("|%8s|%9s|%9s|%8d|RM%10.2lf|RM%10.2lf|RM%16.2lf|RM%9.2lf|RM%13.2lf|%14s|%02d/%02d/%4d|\n", sales[i].salesOrderID, sales[i].memberID,
			sales[i].itemCode, sales[i].salesQuantity, sales[i].salesPrice, sales[i].total, sales[i].taxed, sales[i].grandTotal,
			sales[i].commission, sales[i].paymentMethod, sales[i].date.day, sales[i].date.month, sales[i].date.year);
	}
	salesFoot();
}

//Delete Sales Function
void deleteSales(Sales* sales) {
	char salesID[6], choice;
	int retry = 0, j = -1;

	system("cls");

	//Loop back to deletion menu
	do {
		printf("Deletion Menu\n");
		switch (preOptions("Continue to deletion")) {
		case 1:
			//Enter Sales Order ID to compare
			do {
				printf("\nEnter the Sales Order ID you want to delete (SXXXX): ");
				rewind(stdin);
				scanf("%s", &salesID);

			} while (codeValidation(salesID, 'S', "Sales Order ID") == 0);

			//Read binary file and compare for matching Sales Order ID
			int totalSales = readSalesFile(sales);

			for (int i = 0; i < totalSales; i++) {
				if (strcmp(salesID, sales[i].salesOrderID) == 0) {
					printf("\nThis is the record that has been found: \n");
					salesHead();
					salesDataFields();
					printf("|--------|---------|---------|--------|------------|------------|------------------|-----------|---------------|--------------|----------|\n");
					printf("|%8s|%9s|%9s|%8d|RM%10.2lf|RM%10.2lf|RM%16.2lf|RM%9.2lf|RM%13.2lf|%14s|%02d/%02d/%4d|\n", sales[i].salesOrderID, sales[i].memberID,
						sales[i].itemCode, sales[i].salesQuantity, sales[i].salesPrice, sales[i].total, sales[i].taxed, sales[i].grandTotal,
						sales[i].commission, sales[i].paymentMethod, sales[i].date.day, sales[i].date.month, sales[i].date.year);
					salesFoot();
					j = i;
				}
			}

			//Shows no matching records
			if (j == -1) {
				printf("The following Sales Order ID does not exist.\n\n");
				printf("Going back to deletion menu... ");
				system("pause");
				system("cls");
				break;
			}

			//Deletion confirmation
			printf("\nAre you sure you want to delete this row of records? This action can't be undone. (Y/N) ");


			//Does not want to delete this record
			if (choiceSelection() == 'N') {
				system("cls");
				printf("Deletion cancelled, back to Deletion Menu...\n\n");
				break;
			}

			//Deletion process and writing sales file
			writeSalesFile(sales, totalSales, j);
			//Notify completion
			printf("\nDeletion complete!\n\n");
			system("pause");
			retry = 1;
			break;
		case 2:
			system("cls");

			displaySales(sales, readSalesFile(sales));

			system("pause");
			system("cls");
			break;
		default:
			retry = 1;
			printf("\nGoing back to sales menu... ");
			system("pause");
		}
	} while (retry == 0);
}

//Sales Report Function
void salesReport(Sales* sales) {
	int sequence[6], years[6] = { 2020, 2021, 2022, 2023, 2024, 2025 };
	double yearlyAmount[6];

	system("cls");

	//Get data from sales file
	int totalSales = readSalesFile(sales);

	//Sales report menu
	printf("Menu for Sales Report of 2020 - 2025\n");
	printf("====================================\n");
	printf("| 1) Total number of sales         |\n");
	printf("|----------------------------------|\n");
	printf("| 2) Total number of items sold    |\n");
	printf("|----------------------------------|\n");
	printf("| 3) Total amount of tax paid      |\n");
	printf("|----------------------------------|\n");
	printf("| 4) Total profit generated        |\n");
	printf("|----------------------------------|\n");
	printf("| 5) Back to menu                  |\n");
	printf("====================================\n");
	printf("\nSelect one of the options (1 - 5) ");

	switch (menuSelection(5)) {
	case 1:
		//Get amount of sales for each year
		for (int i = 0; i < 6; i++) {
			yearlyAmount[i] = 0;
			for (int j = 0; j < totalSales; j++) {
				if (sales[j].date.year == years[i]) {
					yearlyAmount[i]++;
				}
			}
		}

		//Arrange year sequences according to no. of sales
		for (int i = 0; i < 6; i++) {
			sequence[i] = 0;
			for (int j = 0; j < 6; j++) {
				if (yearlyAmount[i] > yearlyAmount[j]) {
					sequence[i]++;
				}
				else if (yearlyAmount[i] == yearlyAmount[j] && i != j) {
					sequence[i]++;
				}
			}
		}

		salesGraph(sequence, "total amount of sales");

		salesStats(years, yearlyAmount, "sales", 0);

		break;
	case 2:
		//Get amount of items sold for each year
		for (int i = 0; i < 6; i++) {
			yearlyAmount[i] = 0;
			for (int j = 0; j < totalSales; j++) {
				if (sales[j].date.year == years[i]) {
					yearlyAmount[i] = yearlyAmount[i] + sales[i].salesQuantity;
				}
			}
		}

		//Arrange year sequences according to no. of items sold
		for (int i = 0; i < 6; i++) {
			sequence[i] = 0;
			for (int j = 0; j < 6; j++) {
				if (yearlyAmount[i] > yearlyAmount[j]) {
					sequence[i]++;
				}
				else if (yearlyAmount[i] == yearlyAmount[j] && i != j) {
					sequence[i]++;
				}
			}
		}

		salesGraph(sequence, "total amount of items sold");

		salesStats(years, yearlyAmount, "items sold", 0);

		break;
	case 3:
		//Get amount of tax paid for each year
		for (int i = 0; i < 6; i++) {
			yearlyAmount[i] = 0;
			for (int j = 0; j < totalSales; j++) {
				if (sales[j].date.year == years[i]) {
					yearlyAmount[i] = yearlyAmount[i] + sales[i].taxed;
				}
			}
		}

		//Arrange year sequences according to tax paid
		for (int i = 0; i < 6; i++) {
			sequence[i] = 0;
			for (int j = 0; j < 6; j++) {
				if (yearlyAmount[i] > yearlyAmount[j]) {
					sequence[i]++;
				}
				else if (yearlyAmount[i] == yearlyAmount[j] && i != j) {
					sequence[i]++;
				}
			}
		}

		salesGraph(sequence, "total amount of tax paid");

		salesStats(years, yearlyAmount, "tax paid", 1);

		break;
	case 4:
		//Get amount of total for each year
		for (int i = 0; i < 6; i++) {
			yearlyAmount[i] = 0;
			for (int j = 0; j < totalSales; j++) {
				if (sales[j].date.year == years[i]) {
					yearlyAmount[i] = yearlyAmount[i] + sales[i].total;
				}
			}
		}

		//Arrange year sequences according to total
		for (int i = 0; i < 6; i++) {
			sequence[i] = 0;
			for (int j = 0; j < 6; j++) {
				if (yearlyAmount[i] > yearlyAmount[j]) {
					sequence[i]++;
				}
				else if (yearlyAmount[i] == yearlyAmount[j] && i != j) {
					sequence[i]++;
				}
			}
		}

		salesGraph(sequence, "total amount of profits generated");

		salesStats(years, yearlyAmount, "profits generated", 1);

		break;
	default:
		printf("\nGoing back to sales menu... ");
		return;
	}
}

//Record Rearrangement Function
void rearrange(Sales* sales, int totalSales) {
	Sales temp;

	switch (rearrangeMenu()) {
	case 1:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 2:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to MemberID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].memberID, sales[j + 1].memberID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 3:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Item Code
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].itemCode, sales[j + 1].itemCode) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 4:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Quantity
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].salesQuantity > sales[j + 1].salesQuantity) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 5:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Price
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].salesPrice > sales[j + 1].salesPrice) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 6:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Total
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].total > sales[j + 1].total) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 7:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Amount Taxed
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].taxed > sales[j + 1].taxed) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 8:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Grand Total
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].grandTotal > sales[j + 1].grandTotal) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 9:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Commission
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].commission > sales[j + 1].commission) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 10:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Payment Method
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].paymentMethod, sales[j + 1].paymentMethod) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	case 11:
		//Rearrange according to SalesID
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (strcmp(sales[j].salesOrderID, sales[j + 1].salesOrderID) > 0) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}
		//Rearrange according to Date Sold
		for (int i = 0; i < totalSales; i++) {
			for (int j = 0; j < totalSales - 1; j++) {
				if (sales[j].date.year > sales[j + 1].date.year) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
				else if (sales[j].date.year == sales[j + 1].date.year && sales[j].date.month > sales[j + 1].date.month) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
				else if (sales[j].date.year == sales[j + 1].date.year && sales[j].date.month == sales[j + 1].date.month && sales[j].date.day > sales[j + 1].date.day) {
					temp = sales[j];
					sales[j] = sales[j + 1];
					sales[j + 1] = temp;
				}
			}
		}

		break;
	default:
		//Back to sales menu
		printf("\nGoing back to sales menu... ");
		return 0;
	}

	//Reset Sales file and rewrite rearranged records
	writeSalesFile(sales, totalSales, -1);

	printf("\nSale records rearranged successfully! ");
}

//Commission Function
void commission(struct member* memRecord, Sales* salesRecord) {
	int first, second, comAmount, refAmount;
	double totalCom, gTotalCom;
	//Read data from Member and Sales File
	int totalMembers = scanMemberFile(memRecord);
	int totalSales = readSalesFile(salesRecord);

	printf("   ____                          _         _             \n");
	printf("  / ___|___  _ __ ___  _ __ ___ (_)___ ___(_) ___  _ __  \n");
	printf(" | |   / _ \\| '_ ` _ \\| '_ ` _ \\| / __/ __| |/ _ \\| '_ \\ \n");
	printf(" | |__| (_) | | | | | | | | | | | \\__ \\__ \\ | (_) | | | |\n");
	printf("  \\____\\___/|_| |_| |_|_| |_| |_|_|___/___/_|\\___/|_| |_|\n\n");

	printf("===================================================================================================\n");
	printf("|%10s|%10s|%10s|%15s|%16s|%15s|%15s|\n", "Member ID", "Upline ID", "Referrees", "Sales", "Commissions (5%)", "Total", "Grand Total");

	//Each individual Member ID
	for (int i = 0; i < totalMembers; i++) {
		refAmount = 0;
		gTotalCom = 0;
		first = 0;
		for (int j = 0; j < totalMembers; j++) {
			//Print Member ID with referrees
			if (strcmp(memRecord[i].uplineID, memRecord[j].referral) == 0) {
				printf("|----------|----------|----------|---------------|----------------|---------------|---------------|\n");
				printf("|%10s|%10s|", memRecord[i].memberID, memRecord[i].uplineID);
				break;
			}
		}
		for (int j = 0; j < totalMembers; j++) {
			//Find amount of referrees
			if (strcmp(memRecord[i].uplineID, memRecord[j].referral) == 0) {
				refAmount++;
			}
		}
		for (int j = 0; j < totalMembers; j++) {
			comAmount = 0;
			totalCom = 0;
			second = 0;

			//Print referrees
			if (strcmp(memRecord[i].uplineID, memRecord[j].referral) == 0) {

				if (first != 0) {
					printf("|          |          |");
				}
				printf("%10s|", memRecord[j].memberID);
				first++;
				//Find amount of commissions
				for (int k = 0; k < totalSales; k++) {
					if (strcmp(memRecord[j].memberID, salesRecord[k].memberID) == 0) {
						comAmount++;
					}
				}
				//Print commissions
				for (int k = 0; k < totalSales; k++) {
					if (strcmp(memRecord[j].memberID, salesRecord[k].memberID) == 0) {
						totalCom = totalCom + (roundf(salesRecord[k].commission * 100) / 100);
						gTotalCom = gTotalCom + (roundf(salesRecord[k].commission * 100) / 100);
						if (second != 0) {
							printf("|          |          |          |");
						}
						printf("RM%13.2lf|RM%14.2lf|", salesRecord[k].grandTotal, salesRecord[k].commission);

						if (comAmount == 1 && refAmount == 1) {
							printf("RM%13.2lf|RM%13.2lf|\n", totalCom, gTotalCom);
						}
						else if (comAmount == 1) {
							printf("RM%13.2lf|               |\n", totalCom);
							printf("|          |          |----------|---------------|----------------|---------------|               |\n");
							refAmount--;
						}
						else {
							printf("               |               |\n");
							comAmount--;
						}
						second++;
					}
				}

			}

		}
	}
	printf("===================================================================================================\n");
}

// Sales Module Menu
int salesMenu() {

	printf("  ____   __   __    ____  ____ \n");
	printf(" / ___) / _\\ (  )  (  __)/ ___)\n");
	printf(" \\___ \\/    \\/ (_/\\ ) _) \\___ \\ \n");
	printf(" (____/\\_/\\_/\\____/(____)(____/ \n\n");

	printf("===================================\n");
	printf("| 1) Add a sales record           |\n");
	printf("|---------------------------------|\n");
	printf("| 2) Search for sales record      |\n");
	printf("|---------------------------------|\n");
	printf("| 3) Modify a sales record        |\n");
	printf("|---------------------------------|\n");
	printf("| 4) Display all sales records    |\n");
	printf("|---------------------------------|\n");
	printf("| 5) Delete a sales record        |\n");
	printf("|---------------------------------|\n");
	printf("| 6) Report of sales              |\n");
	printf("|---------------------------------|\n");
	printf("| 7) Rearrange sales record       |\n");
	printf("|---------------------------------|\n");
	printf("| 8) Generate commission summary  |\n");
	printf("|---------------------------------|\n");
	printf("| 9) Exit the sales function      |\n");
	printf("===================================\n");
	printf("\nSelect one of the options (1 - 9) ");

	return menuSelection(9);
}

//Search options
int searchOptions() {
	system("cls");

	printf("============================================\n");
	printf("| Keys available to search for:            |\n");
	printf("|------------------------------------------|\n");
	printf("| 1) Sales Order ID                        |\n");
	printf("|------------------------------------------|\n");
	printf("| 2) Member ID                             |\n");
	printf("|------------------------------------------|\n");
	printf("| 3) Item Code                             |\n");
	printf("|------------------------------------------|\n");
	printf("| 4) Quantity of Item Sold                 |\n");
	printf("|------------------------------------------|\n");
	printf("| 5) Price of Item                         |\n");
	printf("|------------------------------------------|\n");
	printf("| 6) Total of Items Sold (Before tax)      |\n");
	printf("|------------------------------------------|\n");
	printf("| 7) Taxed amount                          |\n");
	printf("|------------------------------------------|\n");
	printf("| 8) Grand Total of Items Sold (After tax) |\n");
	printf("|------------------------------------------|\n");
	printf("| 9) Commission                            |\n");
	printf("|------------------------------------------|\n");
	printf("| 10) Payment Method                       |\n");
	printf("|------------------------------------------|\n");
	printf("| 11) Date of Item Sold                    |\n");
	printf("|------------------------------------------|\n");
	printf("| 12) Back to menu                         |\n");
	printf("============================================\n");

	printf("\nSelect one of the options (1 - 12) ");

	return menuSelection(12);
}

//Modify Options
int preOptions(char words[50]) {

	printf("=================================\n");
	printf("| 1) %-27s|\n", words);
	printf("|-------------------------------|\n");
	printf("| 2) Display sales records first|\n");
	printf("|-------------------------------|\n");
	printf("| 3) Back to sales menu         |\n");
	printf("=================================\n");
	printf("\nSelect one of the options (1 - 3) ");

	return menuSelection(3);
}

//Search for higher or lower
int moreOrLess() {

	printf("\nDo you want to search for records that are higher and equal than this value or lower and equal than this value?\n");
	printf("(1 = Higher and Equal, 2 = Lower and Equal) ");
	rewind(stdin);

	return menuSelection(2);
}

//Menu for Record Rearrangement
int rearrangeMenu() {
	system("cls");

	printf("============================================\n");
	printf("| Keys available to rearrange (Ascending): |\n");
	printf("|------------------------------------------|\n");
	printf("| 1) Sales Order ID                        |\n");
	printf("|------------------------------------------|\n");
	printf("| 2) Member ID                             |\n");
	printf("|------------------------------------------|\n");
	printf("| 3) Item Code                             |\n");
	printf("|------------------------------------------|\n");
	printf("| 4) Quantity of Item Sold                 |\n");
	printf("|------------------------------------------|\n");
	printf("| 5) Price of Item                         |\n");
	printf("|------------------------------------------|\n");
	printf("| 6) Total of Items Sold (Before tax)      |\n");
	printf("|------------------------------------------|\n");
	printf("| 7) Taxed amount                          |\n");
	printf("|------------------------------------------|\n");
	printf("| 8) Grand Total of Items Sold (After tax) |\n");
	printf("|------------------------------------------|\n");
	printf("| 9) Commission                            |\n");
	printf("|------------------------------------------|\n");
	printf("| 10) Payment Method                       |\n");
	printf("|------------------------------------------|\n");
	printf("| 11) Date of Item Sold                    |\n");
	printf("|------------------------------------------|\n");
	printf("| 12) Back to menu                         |\n");
	printf("============================================\n");

	printf("\nSelect one of the options (1 - 12) ");

	return menuSelection(12);
}

//Function for number choices (1 to x)
int menuSelection(int max) {
	int choice;
	char wrongChoice[50];
	do {
		printf("> ");
		rewind(stdin);
		if (scanf("%d", &choice) != 1) {
			scanf("%[^\n]", &wrongChoice);
			choice = 0;
			printf("\nError: '%s' is not an integer, please enter a value of 1 - %d.\n\n", wrongChoice, max);
		}
		else if (choice < 1 || choice > max) {
			printf("\nError: '%d' is not an option, please enter a value of 1 - %d.\n\n", choice, max);
			choice = 0;
		}
	} while (choice == 0);
	return choice;
}

//Function for Yes or No choices
char choiceSelection() {
	char choice[50];
	do {
		printf("> ");
		rewind(stdin);
		scanf("%[^\n]", &choice);
		if (strlen(choice) > 1) {
			printf("\nError '%s' is not a valid option, please enter Y or N.\n", choice);
		}
		else if (toupper(choice[0]) != 'Y' && toupper(choice[0]) != 'N') {
			printf("\nError '%c' is not a valid option, please enter Y or N.\n", choice[0]);
		}
	} while (toupper(choice[0]) != 'Y' && toupper(choice[0]) != 'N');
	return toupper(choice[0]);
}

//Validation for IDs
int codeValidation(char code[6], char codeChar, char codeChecked[10]) {
	if (strlen(code) != 5) {
		printf("The %s should contain exactly 5 characters.\n", codeChecked);
		return 0;
	}
	else if (code[0] != codeChar) {
		printf("The first character of the %s should be '%c', please enter again.\n", codeChecked, codeChar);
		return 0;
	}
	else if (!isdigit(code[1]) || !isdigit(code[2]) || !isdigit(code[3]) || !isdigit(code[4])) {
		printf("There should be 4 digits after the character '%c', please enter again.\n", codeChar);
		return 0;
	}

	return 1;
}

//Check for Duplicate salesOrderID
int salesDupe(char compare[6], Sales* read) {
	for (int i = 0; i < readSalesFile(read); i++) {
		if (strcmp(compare, read[i].salesOrderID) == 0) {
			printf("Duplicate ID found! Please enter a different Sales Order ID.\n");
			return 0;
		}
	}

	return 1;
}

//Validation for numbers
int integerValidation(char dataName[50], int numberChecked, int min, int max) {
	if (numberChecked < min) {
		printf("The %s should be at least %d, please enter something more than %d.\n", dataName, min, min);
		return 0;
	}
	else if (numberChecked > max) {
		printf("The %s is limited to %d at most, please enter something less than %d.\n", dataName, max, max + 1);
		return 0;
	}
	return 1;
}

//Validation for decimals
int decimalValidation(char dataName[50], double numberChecked, int min, int max) {
	if (numberChecked < min) {
		printf("The %s should be at least %d, please enter something more than %d.\n", dataName, min, min);
		return 0;
	}
	else if (numberChecked > max) {
		printf("The %s is limited to %d at most, please enter something less than %d.\n", dataName, max, max + 1);
		return 0;
	}
	return 1;
}

//Payment Method Validation
int paymentValidation(char method[50]) {
	if (strcmp(method, "Cash") != 0 && strcmp(method, "E-wallet") != 0) {
		printf("The Payment Method must be in Cash or E-wallet only.\n");
		return 0;
	}
	return 1;
}

//Date Validation
int dateValidation(int day, int month, int year) {
	int maxDays = 31;
	//Year Check
	if (year < 2020) {
		printf("Our store opened after the year 2020, please enter a year after 2000.\n");
		return 0;
	}
	else if (year > 2025) {
		printf("Please enter a recent year, from 2020-2025.\n");
		return 0;
	}
	//Month Check
	if (month < 1 || month > 12) {
		printf("Please enter a valid month in numerals (1-12).\n");
		return 0;
	}

	//Setting days according to months
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		maxDays = 30;
	}
	else if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			maxDays = 29;
		}
		else {
			maxDays = 28;
		}
	}

	//Day Check
	if (day < 1) {
		printf("The first day starts from 1... Please enter again.\n");
		return 0;
	}
	else if (day > maxDays) {
		printf("The maximum amount of days for month %d is %d, please enter again.\n", month, maxDays);
		return 0;
	}

	return 1;
}

//Check if new MemberID exists in member file
int isExistingMember(char memberID[6], struct member* memRecord, int totalMembers) {
	for (int i = 0; i < totalMembers; i++) {
		if (strcmp(memberID, memRecord[i].memberID) == 0) {
			return 1;
		}
	}
	printf("The member you entered does not exist, please enter an existing MemberID from the member module.\n");
	return 0;
}

//Check if new Item Code exists in stock file
int isExistingItem(char itemCode[6], Stock* stkRecord, int totalStock) {
	for (int i = 0; i < totalStock; i++) {
		if (strcmp(itemCode, stkRecord[i].itemCode) == 0) {
			return 1;
		}
	}
	printf("The item code you entered does not exist, please enter an existing Item Code from the stock module.\n");
	return 0;
}

//Check if Item Stock Quantity is at min level
int isMinimumLevel(char itemCode[6], Stock* stkRecord, int totalStock) {
	for (int i = 0; i < totalStock; i++) {
		if (strcmp(itemCode, stkRecord[i].itemCode) == 0 && stkRecord[i].qtyInStock == stkRecord[i].minLevel) {
			printf("The item code you entered is at minimum stock level, please enter a different Item Code from the stock module.\n");
			return 0;
		}
	}
	return 1;
}

//Check if there is enough quantity of stock to be sold
int checkAvailableStock(int quantity, char itemCode[6], Stock* stkRecord, int totalStock) {
	int j = 0;
	//Find the matching itemCode first
	for (int i = 0; i < totalStock; i++) {
		if (strcmp(itemCode, stkRecord[i].itemCode) == 0) {
			j = i;
		}
	}

	//Check if the quantity sold exceeds the stock quantity min level
	if (stkRecord[j].qtyInStock - quantity < stkRecord[j].minLevel) {
		printf("We don't have enough of the specific item in stock to carry out this transaction. Please try a different quantity.\n");
		return 0;
	}
	return 1;
}

//Write data into Sales Binary File
void appendSalesFile(Sales* writeSales, int count) {
	FILE* aSalesFile;
	if ((aSalesFile = fopen("Sales.bin", "ab")) == 0) {
		printf("Error opening file.");
		exit(-1);
	}
	fwrite(&writeSales[count], sizeof(Sales), 1, aSalesFile);
	fclose(aSalesFile);
	printf("\nData(s) written to file successfully.\n");
}

//Read data from Sales Binary File
int readSalesFile(Sales* sales) {
	FILE* rSalesFile;
	int count = 0;

	if ((rSalesFile = fopen("Sales.bin", "rb")) == 0) {
		printf("Error opening file.\n");
		exit(-1);
	}

	while (fread(&sales[count], sizeof(Sales), 1, rSalesFile) == 1) {
		count++;
	}

	return(count);
	fclose(rSalesFile);
}

//Rewrite sales binary file
void writeSalesFile(Sales* writeSales, int count, int skip) {
	FILE* wSalesFile;
	if ((wSalesFile = fopen("Sales.bin", "wb")) == 0) {
		printf("Error, File could not be open");
		exit(-1);
	}


	for (int i = 0; i < count; i++) {
		if (i != skip) {
			fwrite(&writeSales[i], sizeof(Sales), 1, wSalesFile);
		}
	}

	fclose(wSalesFile);
}

//Scan Member File Records
int scanMemberFile(struct member* memRecord) {
	FILE* memberFile = fopen("member.txt", "r");

	if (!memberFile) {
		printf("Error, file could not be opened.");
		exit(-1);
	}

	int totalMembers = 0;
	while (fscanf(memberFile, "%[^|]|%[^|]|%c|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^\n]\n", &memRecord[totalMembers].memberID, &memRecord[totalMembers].name, &memRecord[totalMembers].gender, &memRecord[totalMembers].IC, &memRecord[totalMembers].contactNumber, &memRecord[totalMembers].uplineID, &memRecord[totalMembers].referral, &memRecord[totalMembers].email, &memRecord[totalMembers].dateOfBirth.year, &memRecord[totalMembers].dateOfBirth.month, &memRecord[totalMembers].dateOfBirth.day, &memRecord[totalMembers].address) != EOF) {
		totalMembers++;
	};

	fclose(memberFile);

	return totalMembers;
}

//Read Stock File Records
int readStockFile(Stock* stkRecord) {
	FILE* stockFile = fopen("addstock.bin", "rb");

	if (!stockFile) {
		printf("Error, unable to open file.");
		exit(-1);
	}

	int totalStock = 0;
	while (fread(&stkRecord[totalStock], sizeof(Stock), 1, stockFile) == 1) {
		totalStock++;
	};

	fclose(stockFile);

	return totalStock;
}

//Write new data into Stock File
void writeStockFile(Stock* stkRecord, int totalStock) {
	FILE* writeStock;
	writeStock = fopen("addstock.bin", "wb");

	if (!writeStock) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}
	for (int i = 0; i < totalStock; i++) {
		fwrite(&stkRecord[i], sizeof(Stock), 1, writeStock);
	}

	fclose(writeStock);
}

//Sales table header
void salesHead() {
	printf("==========================================================================================================================================\n");
}

//Sales table headings
void salesDataFields() {
	printf("|%8s|%9s|%9s|%8s|%12s|%12s|%18s|%10s|%15s|%14s|%10s|\n", "Order ID", "Member ID", "Item Code", "Quantity", "Price",
		"Total", "Taxed Amount (6 %)", "Grand Total", "Commission (5%)", "Payment Method", "Date");
}

//Sales table footer
void salesFoot() {
	printf("==========================================================================================================================================\n\n");
}

//Function for Sales Graph of 2020-2025
void salesGraph(int skipRow[6], char data[50]) {
	char title[100] = "Barchart of ", title2[50] = " from 2020 - 2025";

	system("cls");
	printf("  ____        _             ____                       _   \n");
	printf(" / ___|  __ _| | ___  ___  |  _ \\ ___ _ __   ___  _ __| |_ \n");
	printf(" \\___ \\ / _` | |/ _ \\/ __| | |_) / _ \\ '_ \\ / _ \\| '__| __|\n");
	printf("  ___) | (_| | |  __/\\__ \\ |  _ <  __/ |_) | (_) | |  | |_ \n");
	printf(" |____/ \\__,_|_|\\___||___/ |_| \\_\\___| .__/ \\___/|_|   \\__|\n");
	printf("                                     |_|                    \n\n");

	//Insert data field name in between string
	strcat(title, data);
	strcat(title, title2);
	//Center Title
	for (int g = 0; g < ((68 - strlen(title)) / 2); g++) {
		printf(" ");
	}
	//Chart Title
	printf("%s\n\n", title);

	//Chart Top
	printf(" ^\n");

	//Chart Body
	printf(" |\n");

	//Bar Top
	printf(" |       ");
	for (int h = 0; h < 6; h++) {
		if (skipRow[h] == 5) {
			printf("__        ");
		}
		else {
			printf("          ");
		}
	}
	printf("\n");

	//Bar Body
	printf(" |      ");
	//Row
	for (int i = 0; i <= 4; i++) {
		//Column
		for (int j = 0; j < 6; j++) {
			if (skipRow[j] == 5) {
				printf("|  |      ");
			}
			else if (skipRow[j] == 4) {
				printf(" __       ");
				skipRow[j] = skipRow[j] + 1;
			}
			else {
				printf("          ");
				skipRow[j] = skipRow[j] + 1;
			}
		}

		if (i != 4) {
			printf("\n");
			printf(" |      ");
		}
	}
	printf("\n");

	//Chart Bottom
	printf(" |");
	for (int k = 0; k < 6; k++) {
		printf("----------");
	}
	printf("------");
	printf(">");
	printf("\n");
	printf("        2020      2021      2022      2023      2024      2025\n");
}

//Basic stats function
void salesStats(int year[6], double amount[6], char title[50], int isMoney) {
	int temp = -1, highest;
	double total = 0;

	total = amount[0] + amount[1] + amount[2] + amount[3] + amount[4] + amount[5];

	for (int i = 0; i < 6; i++) {
		if (isMoney == 0) {
			printf("\nThe amount of %s for the year %d: %.0lf (%.2lf%s)", title, year[i], amount[i], amount[i] / total * 100, "%");
		}
		else {
			printf("\nThe amount of %s for the year %d: RM%.2lf (%.2lf%s)", title, year[i], amount[i], amount[i] / total * 100, "%");
		}
		if (temp < amount[i]) {
			temp = amount[i];
			highest = i;
		}
	}

	if (isMoney == 0) {
		printf("\n\nThe year with the highest amount of %s is %d, with the amount of %.0lf.\n", title, year[highest], amount[highest]);

		printf("\nThe average amount of %s each year is %.2lf.\n\n", title, total / 6);
	}
	else {
		printf("\n\nThe year with the highest amount of %s is %d, with the amount of RM%.2lf.\n", title, year[highest], amount[highest]);

		printf("\nThe average amount of %s each year is RM%.2lf.\n\n", title, total / 6);
	}
}

//Minus Stock Quantity with Sales Quantity
int minusCurrentStock(int quantity, char itemCode[6], Stock* stkRecord, int totalStock) {
	//Find the matching itemCode first
	for (int i = 0; i < totalStock; i++) {
		if (strcmp(itemCode, stkRecord[i].itemCode) == 0) {
			//Minus stock quantity with sales
			stkRecord[i].qtyInStock = stkRecord[i].qtyInStock - quantity;
		}
	}

	writeStockFile(stkRecord, totalStock);
}


/*========= STOCK MODULE - LOW JING HONG =========*/
void stockMain() {

	int menuChoice;
	char yesorno;

	do {
		system("cls");
		do {
			menuChoice = stockmenu();
			switch (menuChoice) {
			case 1:
			{
				stockadd();
				break;
			}
			case 2:
			{
				searchforstock();
				break;
			}
			case 3:
			{
				stockmodify();
				break;
			}
			case 4:
			{
				stockdisplay();
				break;
			}
			case 5:
			{
				deleteStock();
				break;
			}
			case 6:
			{
				totalValue();
				break;
			}
			case 7:
			{
				sortStockByCode();
				break;
			}
			case 8:
				break;
			default:
			{
				printf("Error: Please enter a digit between 1 and 8!\n");
			}
			}

		} while (menuChoice < 1 || menuChoice > 8);

		do {
			printf("Would you like to continue for next function? (Yes = Y , No = N): ");
			rewind(stdin);
			scanf("%c", &yesorno);
			yesorno = toupper(yesorno);
			if (yesorno != 'Y' && yesorno != 'N')
				printf("Error: Please enter (Yes = Y , No = N) only!\n");
		} while (yesorno != 'Y' && yesorno != 'N');

	} while (yesorno == 'Y');
}

int stockmenu() {

	int userChoice;
	stockModuleLogo();
	printf("\nSelect functions for stock module\n");
	printf("===================================\n");
	printf("1. Add new stock information\n");
	printf("2. Search for stock items\n");
	printf("3. Modify stock information\n");
	printf("4. Display all stock items\n");
	printf("5. Delete Stock items\n");
	printf("6. Total value for stock items\n");
	printf("7. Sort Stock (By stock code)\n");
	printf("8. Exit\n");
	printf("\nSelect options between (1 - 8) > ");
	rewind(stdin);
	scanf("%d", &userChoice);

	return userChoice;

}

void stockadd() {
	system("cls");
	char userChoice;
	int numStockItems = 0;
	Stock stockList[MAX_STOCK_ITEMS];
	FILE* fptrAddStock;

	fptrAddStock = fopen("addstock.bin", "ab");

	if (fptrAddStock == NULL) {
		printf("Error: unable to open file!");
		exit(-1);
	}

	addStockLogo();

	do {
		printf("\nPlease enter new stock information: \n");
		printf("===================================\n");

		do {
			printf("Stock item code (e.g. V2001): ");
			rewind(stdin);
			scanf("%[^\n]", stockList[numStockItems].itemCode);

			if (strlen(stockList[numStockItems].itemCode) != 5) {
				printf("Error: Item code only can contain 5 characters!\n");
			}
			else if (stockList[numStockItems].itemCode[0] != 'V') {
				printf("Error: 5-character code must starting with letter 'V'!\n");
			}
			else if (!isdigit(stockList[numStockItems].itemCode[1]) || !isdigit(stockList[numStockItems].itemCode[2]) || !isdigit(stockList[numStockItems].itemCode[3]) || !isdigit(stockList[numStockItems].itemCode[4])) {
				printf("Error: There should be 4 digits after the first character!\n");
			}
			else if (stockCodeExists(stockList[numStockItems].itemCode)) {
				printf("Error: Stock item code already exists!\n");
			}
		} while ((strlen(stockList[numStockItems].itemCode) != 5) || (stockList[numStockItems].itemCode[0] != 'V') || !isdigit(stockList[numStockItems].itemCode[1]) || !isdigit(stockList[numStockItems].itemCode[2]) || !isdigit(stockList[numStockItems].itemCode[3]) || !isdigit(stockList[numStockItems].itemCode[4]) || stockCodeExists(stockList[numStockItems].itemCode));

		do {
			printf("Stock item description (max of 30 characters): ");
			rewind(stdin);
			scanf("%[^\n]", &stockList[numStockItems].itemDesc);

			if (strlen(stockList[numStockItems].itemDesc) > 30) {
				printf("Error: Item description too long!\n");
			}

		} while (strlen(stockList[numStockItems].itemDesc) > 30);

		do {
			printf("Stock price: ");
			rewind(stdin);
			if (scanf("%f", &stockList[numStockItems].itemPrice) != 1) {
				printf("Error: Invalid input for price!\n");
			}
			else if (stockList[numStockItems].itemPrice < 0) {
				printf("Error: Item price must be greater than or equal to zero!\n");
			}
			else if (stockList[numStockItems].itemPrice > 1000) {
				printf("Error: Item price must be lesser than or equal to one thousand!\n");
			}
		} while (stockList[numStockItems].itemPrice < 0 || stockList[numStockItems].itemPrice > 1000);

		do {
			printf("Stock quantity: ");
			rewind(stdin);
			if (scanf("%d", &stockList[numStockItems].qtyInStock) != 1) {
				printf("Error: Invalid input for quantity!\n");
			}
			else if (stockList[numStockItems].qtyInStock < 0) {
				printf("Error: Quantity must be greater than or equal to zero!\n");
			}
		} while (stockList[numStockItems].qtyInStock < 0);

		do {
			printf("Stock item minimum level: ");
			rewind(stdin);
			if (scanf("%d", &stockList[numStockItems].minLevel) != 1) {
				printf("Error: Invalid input for minimum level!\n");
			}
			else if (stockList[numStockItems].minLevel < 0) {
				printf("Error: Minimum level cannot be negative!\n");
			}
			else if (stockList[numStockItems].minLevel > stockList[numStockItems].qtyInStock) {
				printf("Error: Minimum level cannot be greater than quantity in stock!\n");
			}
		} while (stockList[numStockItems].minLevel < 0 || stockList[numStockItems].minLevel > stockList[numStockItems].qtyInStock);

		do {
			printf("Stock item reorder quantity: ");
			rewind(stdin);
			if (scanf("%d", &stockList[numStockItems].reorderQty) != 1) {
				printf("Error: Invalid input for reorder quantity!\n");
				while (getchar() != '\n');
			}
			else if (stockList[numStockItems].reorderQty < 0) {
				printf("Error: Reorder quantity must be greater than or equal to zero!\n");
			}
			else if (stockList[numStockItems].reorderQty > stockList[numStockItems].qtyInStock) {
				printf("Error: Reorder quantity should not be greather than current stock quantity!\n");
			}
		} while (stockList[numStockItems].reorderQty < 0 || stockList[numStockItems].reorderQty > stockList[numStockItems].qtyInStock);

		do {
			printf("Shoes size in (US): ");
			rewind(stdin);
			if (scanf("%f", &stockList[numStockItems].size) != 1) {
				printf("Error: Invalid input for shoe size!\n");
			}
			else if (stockList[numStockItems].size < 1 || stockList[numStockItems].size > 20) {
				printf("Error: Shoe size should be between 1 and 20!\n");
			}
		} while (stockList[numStockItems].size < 1 || stockList[numStockItems].size > 20);

		do {
			printf("Shoes color: ");
			rewind(stdin);
			scanf("%[^\n]", stockList[numStockItems].color);
			if (!isalpha(stockList[numStockItems].color[0])) {
				printf("Error: Color should only contain alphabetic characters!\n");
			}
		} while (!isalpha(stockList[numStockItems].color[0]));

		do {
			printf("Shoes type (max 20 characters): ");
			rewind(stdin);
			scanf("%[^\n]", stockList[numStockItems].shoesType);
			if (strlen(stockList[numStockItems].shoesType) > 20) {
				printf("Error: Shoes type too long!\n");
			}
		} while (strlen(stockList[numStockItems].shoesType) > 20);

		do {
			printf("Shoes weight (in grams): ");
			rewind(stdin);
			if (scanf("%lf", &stockList[numStockItems].shoesWeight) != 1) {
				printf("Error: Please enter a numeric value!\n");
			}
			else if (stockList[numStockItems].shoesWeight <= 0) {
				printf("Error: Shoes weight must be greater than zero.\n");
			}
			else {
				break;
			}
		} while (1);

		fwrite(&stockList[numStockItems], sizeof(Stock), 1, fptrAddStock);
		printf("New stock has been added successfully!\n");
		numStockItems++;

		do {
			printf("Would like to continue on adding stock information? (Y/N): ");
			rewind(stdin);
			scanf("%c", &userChoice);
			if (userChoice != 'Y' && userChoice != 'y' && userChoice != 'n' && userChoice != 'N') {
				printf("Please enter (Y/y for yes) or (N/n for no)! \n");
			}
			else if (userChoice == 'n' || userChoice == 'N') {
				break;
			}
		} while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'n' && userChoice != 'N');

	} while (userChoice == 'y' || userChoice == 'Y');

	fclose(fptrAddStock);
	rewind(stdin);

}

void stockdisplay() {
	system("cls");
	Stock display[MAX_STOCK_ITEMS];
	FILE* fptrsearch;
	fptrsearch = fopen("addstock.bin", "rb");

	if (fptrsearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	int xcount = 0;

	while (fread(&display[xcount], sizeof(Stock), 1, fptrsearch) == 1) {
		xcount++;
	};
	if (xcount < 1) {
		printf("\n[No records found]\n");
	}

	fclose(fptrsearch);
	displayStockLogo();
	displayHeader();
	for (int y = 0; y < xcount; y++) {
		printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", display[y].itemCode, display[y].itemDesc, display[y].itemPrice, display[y].qtyInStock, display[y].minLevel, display[y].reorderQty, display[y].size, display[y].color, display[y].shoesType, display[y].shoesWeight);
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}
	system("pause");

}

void searchforstock() {
	system("cls");
	int UserSelection;
	searchStockLogo();
	do {
		printf("\nSearch Stock information by: \n");
		printf("-------------------------------\n");
		printf("1. Item Code\n");
		printf("2. Item Description\n");
		printf("3. Item Price\n");
		printf("4. Quantity In Stock\n");
		printf("5. Minimum Level\n");
		printf("6. Reorder Quantity\n");
		printf("7. Size\n");
		printf("8. Color\n");
		printf("9. Shoes Type\n");
		printf("10. Shoes Weight\n");
		printf("11. Exit\n");
		printf("\nInput > ");
		scanf("%d", &UserSelection);
		rewind(stdin);

		if (UserSelection > 11 || UserSelection < 1) {
			printf("\nInvalid option! Please choose between (1 to 11). \n");
		}
	} while (UserSelection > 11 || UserSelection < 1);

	switch (UserSelection) {
	case 1:
		searchItemcode();
		break;
	case 2:
		searchItemdesc();
		break;
	case 3:
		searchItemprice();
		break;
	case 4:
		searchQty();
		break;
	case 5:
		searchMinlevel();
		break;
	case 6:
		searchReorderqty();
		break;
	case 7:
		searchsize();
		break;
	case 8:
		searchcolor();
		break;
	case 9:
		searchtype();
		break;
	case 10:
		searchWeight();
		break;
	case 11:
		break;
	}
}

void searchItemcode() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	char stockCode[6];
	int records = 0;

	do {
		printf("\nEnter item code to search: ");
		rewind(stdin);
		scanf("%s", stockCode);
		if (strlen(stockCode) != 5) {
			printf("\nError: Item code can only contain 5 characters!\n");
		}
		if (stockCode[0] != 'V') {
			printf("\nError: 5-character code must start with letter 'V'!\n");
		}
		if (!isdigit(stockCode[1]) || !isdigit(stockCode[2]) || !isdigit(stockCode[3]) || !isdigit(stockCode[4])) {
			printf("\nError: There should be 4 digits after the first character!\n");
		}
	} while ((strlen(stockCode) != 5) || !isdigit(stockCode[1]) || !isdigit(stockCode[2]) || !isdigit(stockCode[3]) || !isdigit(stockCode[4]));

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (strcmp(stockforsearch.itemCode, stockCode) == 0) {

			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}

	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchItemdesc() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	char stockName[30];
	int records = 0;

	do {
		printf("\nEnter item description to search (max of 30 characters): ");
		rewind(stdin);
		scanf("%[^\n]", &stockName);

		if (strlen(stockName) > 30) {
			printf("\nError: Item description too long!\n");
		}
	} while (strlen(stockName) > 30);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (strcmp(stockforsearch.itemDesc, stockName) == 0) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchItemprice() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	float stockPrice;
	int records = 0;

	do {
		printf("\nEnter item price to search: ");
		rewind(stdin);
		if (scanf("%f", &stockPrice) != 1) {
			printf("\nError: Invalid input for price!\n");
		}
		else if (stockPrice < 0) {
			printf("Error: Item price must be greater than or equal to zero!\n");
		}
	} while (stockPrice < 0);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.itemPrice == stockPrice) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchQty() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	int stockQty;
	int records = 0;

	do {
		printf("\nEnter item Quantity to search: ");
		rewind(stdin);
		if (scanf("%d", &stockQty) != 1) {
			printf("Error: Invalid input for quantity!\n");
		}
		else if (stockQty < 0) {
			printf("Error: Quantity must be greater than or equal to zero!\n");
		}
	} while (stockQty < 0);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.qtyInStock == stockQty) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchMinlevel() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	int stockMinLevel;
	int records = 0;

	do {
		printf("\nEnter item minimum level to search: ");
		rewind(stdin);
		if (scanf("%d", &stockMinLevel) != 1) {
			printf("Error: Invalid input for minimum level!\n");
		}
		else if (stockMinLevel < 0) {
			printf("Error: Minimum level cannot be negative!\n");
		}
	} while (stockMinLevel < 0);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.minLevel == stockMinLevel) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchReorderqty() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	int stockReorderQty;
	int records = 0;

	do {
		printf("\nEnter item reorder quantity to search: ");
		rewind(stdin);
		if (scanf("%d", &stockReorderQty) != 1) {
			printf("Error: Invalid input for reorder quantity!\n");
			while (getchar() != '\n');
		}
		else if (stockReorderQty < 0) {
			printf("Error: Reorder quantity must be greater than or equal to zero!\n");
		}
	} while (stockReorderQty < 0);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.reorderQty == stockReorderQty) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchsize() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	float stockSize;
	int records = 0;

	do {
		printf("\nEnter size to search: ");
		rewind(stdin);
		if (scanf("%f", &stockSize) != 1) {
			printf("Error: Invalid input for shoe size!\n");
		}
		else if (stockSize < 1 || stockSize > 20) {
			printf("Error: Shoe size should be between 1 and 20!\n");
		}
	} while (stockSize < 1 || stockSize > 20);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.size == stockSize) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchcolor() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	char stockColor[6];
	int records = 0;

	do {
		printf("\nEnter stock color to search: ");
		rewind(stdin);
		scanf("%[^\n]", stockColor);
		if (!isalpha(stockColor[0])) {
			printf("Error: Color should only contain alphabetic characters!\n");
		}
	} while (!isalpha(stockColor[0]));

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (strcmp(stockforsearch.color, stockColor) == 0) {

			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}

	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void searchtype() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	char stockType[6];
	int records = 0;

	do {
		printf("\nEnter stock type to search: ");
		rewind(stdin);
		scanf("%[^\n]", stockType);
		if (strlen(stockType) > 20) {
			printf("Error: Shoes type too long!\n");
		}
	} while (strlen(stockType) > 20);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (strcmp(stockforsearch.shoesType, stockType) == 0) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
}

void searchWeight() {

	FILE* stocksearch;
	stocksearch = fopen("addstock.bin", "rb");

	if (stocksearch == NULL) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	Stock stockforsearch;
	double stockWeight;
	int records = 0;

	do {
		printf("\nEnter weight to search (in gram): ");
		rewind(stdin);
		if (scanf("%lf", &stockWeight) != 1) {
			printf("Error: Please enter a numeric value!\n");
		}
		else if (stockWeight <= 0) {
			printf("Error: Shoes weight must be greater than zero.\n");
		}
		else {
			break;
		}
	} while (1);

	while (fread(&stockforsearch, sizeof(Stock), 1, stocksearch) == 1) {
		if (stockforsearch.shoesWeight == stockWeight) {
			printf("\n%18s\n", "Stock Found: ");
			printf("==============================\n");
			printf("Item code: %s\n", stockforsearch.itemCode);
			printf("Item description: %s\n", stockforsearch.itemDesc);
			printf("Item price: %.2f\n", stockforsearch.itemPrice);
			printf("Quantity in stock: %d\n", stockforsearch.qtyInStock);
			printf("Minimum level: %d\n", stockforsearch.minLevel);
			printf("Reorder quantity: %d\n", stockforsearch.reorderQty);
			printf("Size: US %.2f\n", stockforsearch.size);
			printf("Color: %s\n", stockforsearch.color);
			printf("Shoes type: %s\n", stockforsearch.shoesType);
			printf("Shoes Weight: %.2lf grams\n", stockforsearch.shoesWeight);
			records++;
		}
	}
	if (records < 1) {
		printf("\n[No Records found]\n");
	}
	system("pause");
	fclose(stocksearch);
	searchforstock();
}

void stockmodify() {
	system("cls");
	Stock modify[MAX_STOCK_ITEMS];
	FILE* stockmodi;
	stockmodi = fopen("addstock.bin", "rb");

	if (!stockmodi) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	int countstock = 0;
	char modistockcode[6];

	while (fread(&modify[countstock], sizeof(Stock), 1, stockmodi) == 1) {
		countstock++;
	}

	if (countstock < 1) {
		printf("[ No records in the file, unable to modify ]\n");
		fclose(stockmodi);
		exit(-1);
	}

	modifyStockLogo();
	displayHeader();
	for (int y = 0; y < countstock; y++) {
		printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", modify[y].itemCode, modify[y].itemDesc, modify[y].itemPrice, modify[y].qtyInStock, modify[y].minLevel, modify[y].reorderQty, modify[y].size, modify[y].color, modify[y].shoesType, modify[y].shoesWeight);
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

	printf("\nPlease enter stock code to select which stock information to modify ('X' or 'x' to exit): ");
	rewind(stdin);
	scanf("%[^\n]", modistockcode);

	if (strcmp(modistockcode, "x") == 0 || strcmp(modistockcode, "X") == 0) {
		printf("\nExiting stock modify menu...\n\n");
		return;
	}

	int j = 0;
	for (int q = 0; q < countstock; q++) {
		if (strcmp(modify[q].itemCode, modistockcode) == 0) {
			j++;
			selectstockmodify(modify[q].itemCode);
		}
	}
	if (j < 1) {
		printf("\nPlease enter a valid stock code\n");
		system("pause");
		printf("\n");
		stockmodify();
	}

	fclose(stockmodi);
}

void selectstockmodify(char stockcode[6]) {

	int stockSelect;
	do {
		printf("\nWhich information do you want to modify for stock code (%s): ", stockcode);
		printf("\n---------------------------------------------------------------\n");
		printf(" 1. Item Code\n");
		printf(" 2. Item Description\n");
		printf(" 3. Item Price\n");
		printf(" 4. Quantity In Stock\n");
		printf(" 5. Minimum Level\n");
		printf(" 6. Reorder Quantity\n");
		printf(" 7. Size\n");
		printf(" 8. Color\n");
		printf(" 9. Shoes Type\n");
		printf("10. Shoes Weight\n");
		printf("11. Modify other stock code\n\n");
		printf("Selection: ");
		rewind(stdin);
		scanf("%d", &stockSelect);
		printf("\n");

		switch (stockSelect) {
		case 1:
		{
			modiCode(stockcode);
			break;
		}
		case 2:
		{
			modiDesc(stockcode);
			break;
		}
		case 3:
		{
			modiPrice(stockcode);
			break;
		}
		case 4:
		{
			modiQty(stockcode);
			break;
		}
		case 5:
		{
			modiMinlvl(stockcode);
			break;
		}
		case 6:
		{
			modiReorderQty(stockcode);
			break;
		}
		case 7:
		{
			modiSize(stockcode);
			break;
		}
		case 8:
		{
			modiColor(stockcode);
			break;
		}
		case 9:
		{
			modiType(stockcode);
			break;
		}
		case 10:
		{
			modiWeight(stockcode);
			break;
		}
		case 11:
			stockmodify();
			break;

		default:
			printf("Invalid choice! Please enter a digit between (1 to 11)\n");
		}
	} while (stockSelect < 1 || stockSelect > 11);
}

void modiCode(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	char updateCode[6];

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update Stock item code (e.g. V2001): ");
		rewind(stdin);
		scanf("%[^\n]", &updateCode);

		if (strlen(updateCode) != 5) {
			printf("Error: Item code only can contain 5 characters!\n");
		}
		else if (updateCode[0] != 'V') {
			printf("Error: 5-character code must starting with letter 'V'!\n");
		}
		else if (!isdigit(updateCode[1]) || !isdigit(updateCode[2]) || !isdigit(updateCode[3]) || !isdigit(updateCode[4])) {
			printf("Error: There should be 4 digits after the first character!\n");
		}
	} while ((strlen(updateCode) != 5) || (updateCode[0] != 'V') || !isdigit(updateCode[1]) || !isdigit(updateCode[2]) || !isdigit(updateCode[3]) || !isdigit(updateCode[4]));

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			strcpy(stock[xcount].itemCode, updateCode);
			printf("\n\nStock code modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);

}

void modiDesc(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	char updateDesc[30];

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update Stock item description (max of 30 characters): ");
		rewind(stdin);
		scanf("%[^\n]", &updateDesc);
		if (strlen(updateDesc) > 30) {
			printf("Error: Item description too long!\n");
		}

	} while (strlen(updateDesc) > 30);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			strcpy(stock[xcount].itemDesc, updateDesc);
			printf("\n\nStock description modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);

}

void modiPrice(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	Sales sales[100];
	float updatePrice;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update Stock price: ");
		rewind(stdin);
		if (scanf("%f", &updatePrice) != 1) {
			printf("Error: Invalid input for price!\n");
		}
		else if (updatePrice < 0) {
			printf("Error: Item price must be greater than or equal to zero!\n");
		}
		else if (updatePrice > 1000) {
			printf("Error: Item price must be greater than or equal to one thousand!\n");
		}
	} while (updatePrice < 0 || updatePrice > 1000);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			stock[xcount].itemPrice = updatePrice;
			printf("\n\nStock price modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	//Update price in sales records aswell
	int totalSales = readSalesFile(sales);
	//find item first
	for (int i = 0; i < totalSales; i++) {
		if (strcmp(sales[i].itemCode, stockcode) == 0) {
			sales[i].salesPrice = updatePrice;
		}
	}
	//Rewwrite into file
	writeSalesFile(sales, totalSales, -1);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void modiQty(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	int updateQty;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock quantity: ");
		rewind(stdin);
		if (scanf("%d", &updateQty) != 1) {
			printf("Error: Invalid input for quantity!\n");
		}
		else if (updateQty < 0) {
			printf("Error: Quantity must be greater than or equal to zero!\n");
		}
	} while (updateQty < 0);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			stock[xcount].qtyInStock = updateQty;
			printf("\n\nStock quantity modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void modiMinlvl(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	int updateMinlvl;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock minimum Level: ");
		rewind(stdin);
		if (scanf("%d", &updateMinlvl) != 1) {
			printf("Error: Invalid input for minimum level!\n");
		}
		else if (updateMinlvl < 0) {
			printf("Error: Minimum level cannot be negative!\n");
		}
	} while (updateMinlvl < 0);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			if (updateMinlvl > stock[xcount].qtyInStock) {
				printf("Error: Minimum level cannot be greater than quantity in stock!\n");
				exit(-1);
			}
			stock[xcount].minLevel = updateMinlvl;
			printf("\n\nStock minimum level modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void modiReorderQty(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	int updateReorderQty;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock reorder quantity: ");
		rewind(stdin);
		if (scanf("%d", &updateReorderQty) != 1) {
			printf("Error: Invalid input for reorder quantity!\n");
			while (getchar() != '\n');
		}
		else if (updateReorderQty < 0) {
			printf("Error: Reorder quantity must be greater than or equal to zero!\n");
		}
	} while (updateReorderQty < 0);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			if (updateReorderQty > stock[xcount].qtyInStock) {
				printf("Error: Reorder quantity should not be greather than current stock quantity!\n");
				exit(-1);
			}
			stock[xcount].reorderQty = updateReorderQty;
			printf("\n\nStock reorder quantity modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void modiSize(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	float updateSize;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock size in (US): ");
		rewind(stdin);
		if (scanf("%f", &updateSize) != 1) {
			printf("Error: Invalid input for shoe size!\n");
		}
		else if (updateSize < 1 || updateSize > 20) {
			printf("Error: Shoe size should be between 1 and 20!\n");
		}
	} while (updateSize < 1 || updateSize > 20);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			stock[xcount].size = updateSize;
			printf("\n\nStock size modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void modiColor(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	char updateColor[20];

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock item color: ");
		rewind(stdin);
		scanf("%[^\n]", updateColor);
		if (!isalpha(updateColor[0])) {
			printf("Error: Color should only contain alphabetic characters!\n");
		}
	} while (!isalpha(updateColor[0]));

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			strcpy(stock[xcount].color, updateColor);
			printf("\n\nStock color modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);

}

void modiType(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	char updateType[30];

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock item type: ");
		rewind(stdin);
		scanf("%[^\n]", updateType);
		if (strlen(updateType) > 20) {
			printf("Error: Shoes type too long!\n");
		}
	} while (strlen(updateType) > 20);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			strcpy(stock[xcount].shoesType, updateType);
			printf("\n\nShoe type modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);

}

void modiWeight(char stockcode[6]) {

	FILE* modify;
	FILE* updatemodify;
	Stock stock[MAX_STOCK_ITEMS];
	double updateWeight;

	modify = fopen("addstock.bin", "rb");

	if (!modify) {
		printf("Error: Unable to open file!");
		exit(-1);
	}

	do {
		printf("Update stock weight in (grams): ");
		rewind(stdin);
		if (scanf("%lf", &updateWeight) != 1) {
			printf("Error: Please enter a numeric value!\n");
		}
		else if (updateWeight <= 0) {
			printf("Error: Shoes weight must be greater than zero.\n");
		}
		else {
			break;
		}
	} while (1);

	int xcount = 0;
	while (fread(&stock[xcount], sizeof(Stock), 1, modify) == 1) {
		if (strcmp(stock[xcount].itemCode, stockcode) == 0) {
			stock[xcount].shoesWeight = updateWeight;
			printf("\n\nStock weight modified!\n");
			displayHeader();
			printf("|%-13s|%-30s|%-13.2f|%-13d|%-16d|%-18d|%-13.2f|%-20s|%-30s|%-8.2lf|\n", stock[xcount].itemCode, stock[xcount].itemDesc, stock[xcount].itemPrice, stock[xcount].qtyInStock, stock[xcount].minLevel, stock[xcount].reorderQty, stock[xcount].size, stock[xcount].color, stock[xcount].shoesType, stock[xcount].shoesWeight);
			printf("=========================================================================================================================================================================================\n\n");
		}
		xcount++;
	}

	fclose(modify);

	updatemodify = fopen("addstock.bin", "wb");

	if (!updatemodify) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	for (int k = 0; k < xcount; k++) {
		fwrite(&stock[k], sizeof(Stock), 1, updatemodify);
	}

	fclose(updatemodify);
}

void deleteStock() {
	system("cls");
	Stock stock;
	char deleteInput[6];
	char yesno = 'Y';
	do {
		FILE* fp = fopen("addstock.bin", "rb");
		FILE* temp = fopen("temp.bin", "wb");

		if (!fp) {
			printf("Error:Unable to open file!\n");
			exit(-1);
		}

		if (!temp) {
			printf("Error:Unable to open file!\n");
			exit(-1);
		}

		int k = 0;

		deleteStockLogo();
		printf("\nEnter a Stock code to remove data (e.g. V2001): ");
		rewind(stdin);
		scanf("%s", &deleteInput);

		while (fread(&stock, sizeof(Stock), 1, fp) == 1) {
			if (strcmp(deleteInput, stock.itemCode) != 0) {
				fwrite(&stock, sizeof(stock), 1, temp);
			}
			else {
				k++;
			}
		}

		if (k < 1) {
			printf("\n [ Records not found! ]\n");
		}
		else {
			printf("\nRecord has been deleted successfully!\n");
		}
		do {
			printf("\nDo you wish to delete another stock information? (Yes=Y/No=N): ");
			rewind(stdin);
			if (scanf("%c", &yesno) != 1) {
				printf("Error: Invalid input!/n");
				exit(-1);
			}
			yesno = toupper(yesno);
			if (yesno != 'Y' && yesno != 'N') {
				printf("Error: Please enter (Y for yes or N for no)!\n");
			}
		} while (yesno != 'Y' && yesno != 'N');

		fclose(fp);
		fclose(temp);
		remove("addstock.bin");
		rename("temp.bin", "addstock.bin");

	} while (yesno == 'Y');

}

void printStockValueHeader() {
	printf("\n");
	printf("=================================================\n");
	printf("|| Stock Code ||     Total Value (each row)    ||\n");
	printf("=================================================\n");
}

void printStockValueRow(char* itemCode, float rowTotal) {
	printf("|| %-10s || RM %-26.2f ||\n", itemCode, rowTotal);
	printf("=================================================\n");
}

float calculateRowTotal(int qtyInStock, float itemPrice) {
	return qtyInStock * itemPrice;
}

void totalValue() {
	system("cls");
	Stock stock[MAX_STOCK_ITEMS];
	int numStock = 0;
	float total = 0, rowTotal;

	FILE* ftotalvalue;
	ftotalvalue = fopen("addstock.bin", "rb");

	if (!ftotalvalue) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	while (fread(&stock[numStock], sizeof(Stock), 1, ftotalvalue) == 1) {
		numStock++;
	}
	fclose(ftotalvalue);

	StockValuesLogo();
	printStockValueHeader();

	for (int z = 0; z < numStock; z++) {
		rowTotal = calculateRowTotal(stock[z].qtyInStock, stock[z].itemPrice);
		printStockValueRow(stock[z].itemCode, rowTotal);
		total += rowTotal;
	}

	printf("|| Total Value of all stocks: || RM %-10.2f ||\n", total);
	printf("=================================================\n\n");
}

void sortStockByCode() {

	Stock stock[MAX_STOCK_ITEMS];
	int numStock = 0;

	FILE* fsortcode;
	fsortcode = fopen("addstock.bin", "rb");

	if (!fsortcode) {
		printf("Error: Unable to open file!\n");
		exit(-1);
	}

	while (fread(&stock[numStock], sizeof(Stock), 1, fsortcode) == 1) {
		numStock++;
	}

	for (int i = 0; i < numStock - 1; i++) {
		for (int j = 0; j < numStock - i - 1; j++) {
			if (strcmp(stock[j].itemCode, stock[j + 1].itemCode) > 0) {
				// Swap stock items
				Stock temp = stock[j];
				stock[j] = stock[j + 1];
				stock[j + 1] = temp;
			}
		}
	}

	FILE* fnew;
	fnew = fopen("addstock.bin", "wb");

	if (!fnew) {
		printf("Error: Unable to create file!\n");
		exit(-1);
	}

	if (fwrite(stock, sizeof(Stock), numStock, fnew) != numStock) {
		printf("Error: Unable to write to file!\n");
		exit(-1);
	}

	fclose(fnew);
	printf("\nStock items have been sorted and saved successfully to file!\n\n");
}

void stockModuleLogo() {
	printf("  _____ _             _        __  __           _       _      \n");
	printf(" / ____| |           | |      |  \\/  |         | |     | |     \n");
	printf("| (___ | |_ ___   ___| | __   | \\  / | ___   __| |_   _| | ___ \n");
	printf(" \\___ \\| __/ _ \\ / __| |/ /   | |\\/| |/ _ \\ / _` | | | | |/ _ \\\n");
	printf(" ____) | || (_) | (__|   <    | |  | | (_) | (_| | |_| | |  __/\n");
	printf("|_____/ \\__\\___/ \\___|_|\\_\\   |_|  |_|\\___/ \\__,_|\\__,_|_|\\___|\n");
}

void addStockLogo() {
	printf("              _     _       _____ _             _        \n");
	printf("     /\\      | |   | |     / ____| |           | |       \n");
	printf("    /  \\   __| | __| |    | (___ | |_ ___   ___| | _____ \n");
	printf("   / /\\ \\ / _` |/ _` |     \\___ \\| __/ _ \\ / __| |/ / __|\n");
	printf("  / ____ \\ (_| | (_| |     ____) | || (_) | (__|   <\\__ \\\n");
	printf(" /_/    \\_\\__,_|\\__,_|    |_____/ \\__\\___/ \\___|_|\\_\\___/\n");
}

void searchStockLogo() {
	printf("   _____                     _           _____ _             _        \n");
	printf("  / ____|                   | |         / ____| |           | |       \n");
	printf(" | (___   ___  __ _ _ __ ___| |__      | (___ | |_ ___   ___| | _____ \n");
	printf("  \\___ \\ / _ \\/ _` | '__/ __| '_ \\      \\___ \\| __/ _ \\ / __| |/ / __|\n");
	printf("  ____) |  __/ (_| | | | (__| | | |     ____) | || (_) | (__|   <\\__ \\\n");
	printf(" |_____/ \\___|\\__,_|_|  \\___|_| |_|    |_____/ \\__\\___/ \\___|_|\\_\\___/\n");
}

void modifyStockLogo() {
	printf("  __  __           _ _  __             _____ _             _        \n");
	printf(" |  \\/  |         | (_)/ _|           / ____| |           | |       \n");
	printf(" | \\  / | ___   __| |_| |_ _   _     | (___ | |_ ___   ___| | _____ \n");
	printf(" | |\\/| |/ _ \\ / _` | |  _| | | |     \\___ \\| __/ _ \\ / __| |/ / __|\n");
	printf(" | |  | | (_) | (_| | | | | |_| |     ____) | || (_) | (__|   <\\__ \\\n");
	printf(" |_|  |_|\\___/ \\__,_|_|_|  \\__, |    |_____/ \\__\\___/ \\___|_|\\_\\___/\n");
	printf("                            __/ |                                    \n");
	printf("                           |___/                                     \n");
}

void displayStockLogo() {
	printf("  _____  _           _                   _____ _             _        \n");
	printf(" |  __ \\(_)         | |                 / ____| |           | |       \n");
	printf(" | |  | |_ ___ _ __ | | __ _ _   _     | (___ | |_ ___   ___| | _____ \n");
	printf(" | |  | | / __| '_ \\| |/ _` | | | |     \\___ \\| __/ _ \\ / __| |/ / __|\n");
	printf(" | |__| | \\__ \\ |_) | | (_| | |_| |     ____) | || (_) | (__|   <\\__ \\\n");
	printf(" |_____/|_|___/ .__/|_|\\__,_|\\__, |    |_____/ \\__\\___/ \\___|_|\\_\\___/\n");
	printf("              | |             __/ |                                    \n");
	printf("              |_|            |___/                                     \n");
}

void deleteStockLogo() {
	printf("  _____       _      _             _____ _             _        \n");
	printf(" |  __ \\     | |    | |           / ____| |           | |       \n");
	printf(" | |  | | ___| | ___| |_ ___     | (___ | |_ ___   ___| | _____ \n");
	printf(" | |  | |/ _ \\ |/ _ \\ __/ _ \\     \\___ \\| __/ _ \\ / __| |/ / __|\n");
	printf(" | |__| |  __/ |  __/ ||  __/     ____) | || (_) | (__|   <\\__ \\\n");
	printf(" |_____/ \\___|_|\\___|\\__\\___|    |_____/ \\__\\___/ \\___|_|\\_\\___/\n");
}

void StockValuesLogo() {
	printf(" _____ _             _         __      __   _                 \n");
	printf("/ ____| |           | |        \\ \\    / /  | |                \n");
	printf("| (___ | |_ ___   ___| | _____  \\ \\  / /_ _| |_   _  ___  ___ \n");
	printf("\\___ \\| __/ _ \\ / __| |/ / __|  \\ \\/ / _` | | | | |/ _ \\/ __|\n");
	printf(" ____) | || (_) | (__|   <\\__ \\   \\  / (_| | | |_| |  __/\\__ \\\n");
	printf("|_____/ \\__\\___/ \\___|_|\\_\\___/    \\/ \\__,_|_|\\__,_|\\___||___/\n");
}

int stockCodeExists(char newStockCode[]) {
	FILE* fptr = fopen("addstock.bin", "rb");
	if (!fptr) {
		printf("Error: Unable to open binary file!\n");
		exit(-1);
	}

	Stock stock;
	while (fread(&stock, sizeof(Stock), 1, fptr) == 1) {
		if (strcmp(newStockCode, stock.itemCode) == 0) {
			fclose(fptr);
			return 1;
		}
	}
	fclose(fptr);
	return 0;
}

void displayHeader() {
	printf("=========================================================================================================================================================================================\n");
	printf("|%-13s|%-30s|%-13s|%-13s|%-16s|%-18s|%-13s|%-20s|%-30s|%-8s|\n", "Item_Code", "Item_Description", "Price", "Quantity", "Minimum_level", "Reorder_Quantity", "Size", "Color", "Type", "Weight");
	printf("=========================================================================================================================================================================================\n");
}




