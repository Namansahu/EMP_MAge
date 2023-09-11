#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  Date structure format
struct Date {
    int dd, mm, yy;
};

// Employee structure format 
struct Employee {
    int Empno;
    char EmpName[50];
    struct Date hiredate;
    float BasicSalary;
    float NetSalary;
};

// Function to Insert employee data details
void ADDEmployeeData(struct Employee *emp) {
    printf("Enter Employee Number: ");
    scanf("%d", &emp->Empno);
    
    printf("Enter Employee Name: ");
    scanf(" %[^\n]s", emp->EmpName);
    
    printf("Enter Hire Date (dd mm yyyy): ");
    scanf("%d %d %d", &emp->hiredate.dd, &emp->hiredate.mm, &emp->hiredate.yy);
    
    printf("Enter Basic Salary: ");
    scanf("%f", &emp->BasicSalary);
}

// Function to calculate net pay
void CalculateNetPay(struct Employee *emp) {
    float DA = 0.4 * emp->BasicSalary;
    float TA = 0.1 * emp->BasicSalary;
    float PF = 0.05 * emp->BasicSalary;
    
    emp->NetSalary = emp->BasicSalary + DA + TA - PF;
}

// Function to display employee data
void ShowEmployeeData(struct Employee emp) {
    printf("Employee Number: %d\n", emp.Empno);
    printf("Employee Name: %s\n", emp.EmpName);
    printf("Hire Date: %02d/%02d/%04d\n", emp.hiredate.dd, emp.hiredate.mm, emp.hiredate.yy);
    printf("Basic Salary: %.2f\n", emp.BasicSalary);
    printf("Net Salary: %.2f\n", emp.NetSalary);
}

int main() {
    struct Employee employees[1000]; 
    int numEmployees = 0;
    int choice;

    while (1) {
    
    printf("\n****************************************************\n");
    printf("\nWelcome to the Employee Management System\n");
    printf("\n****************************************************\n");

printf("1. Insert  Employee details\n");
printf("2. Search Employee details\n");
printf("3. Show ALL details of Employees\n");
printf("4. Delete Employee details\n");
printf("5. Update Employee details\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);


        switch (choice) {
            case 1:
                if (numEmployees < 100) {
                    printf("\nEnter Employee Details:\n");
                    ADDEmployeeData(&employees[numEmployees]);
                    CalculateNetPay(&employees[numEmployees]);
                    numEmployees++;
                    printf("Employee details added successfully!\n");
                } else {
                    printf("Maximum employee limit reached!\n");
                }
                break;

            case 2:
                if (numEmployees > 0) {
                    int searchEmpNo;
                    printf("\nEnter Employee Number to Search: ");
                    scanf("%d", &searchEmpNo);
                    int found = 0;

                    for (int i = 0; i < numEmployees; i++) {
                        if (employees[i].Empno == searchEmpNo) {
                            printf("\nEmployee Found:\n");
                            ShowEmployeeData(employees[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Employee  details not found!\n");
                    }
                } else {
                    printf("No employees in the database!\n");
                }
                break;

            case 3:
                if (numEmployees > 0) {
                    printf("\nShow ALL details of EmployeesEmployees:\n");
                    for (int i = 0; i < numEmployees; i++) {
                        ShowEmployeeData(employees[i]);
                        printf("\n");
                    }
                } else {
                    printf("No employees in the database!\n");
                }
                break;

         
            case 4:
    if (numEmployees > 0) {
        int deleteEmpNo;
        printf("\nEnter Employee Number to Delete: ");
        scanf("%d", &deleteEmpNo);
        int found = 0;

        for (int i = 0; i < numEmployees; i++) {
            if (employees[i].Empno == deleteEmpNo) {
                // Delete the employee by shifting all subsequent employees one position left
                for (int j = i; j < numEmployees - 1; j++) {
                    employees[j] = employees[j + 1];
                }
                numEmployees--;
                printf("Employee  details deleted successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Employee not found!\n");
        }
    } else {
        printf("No employees in the database!\n");
    }
    break;
           case 5:
    if (numEmployees > 0) {
        int updateEmpNo;
        printf("\nEnter Employee Number to Update: ");
        scanf("%d", &updateEmpNo);
        int found = 0;

        for (int i = 0; i < numEmployees; i++) {
            if (employees[i].Empno == updateEmpNo) {
                printf("\nEnter Updated Employee Details:\n");
                ADDEmployeeData(&employees[i]);
                CalculateNetPay(&employees[i]);
                printf("Employee updated successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Employee not found!\n");
        }
    } else {
        printf("No employees in the database!\n");
    }
    break;
       case 6:
                printf("Exiting the program.\n");
                return 0;
                

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}
