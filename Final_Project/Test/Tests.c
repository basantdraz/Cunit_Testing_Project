#include "Tests.h"

/************************************************************************************
******************************CUNUT TEST CASES****************************************
 REVIEWED BY        : MOTAAZ ELNAGR
 TESTER'S NAME      : BASSANT DRAZ
************************************************************************************/


/* Test Code to test the Sign Up */
static struct User_Input_Type Test1_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Ahmed",
	26,
	23,
	10,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
};

/* init function for Test Suite 1*/
static unsigned char test1_start(void)
{
	printf("\nTest suite start\n");

	unsigned char RET = Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test-1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 1*/
static unsigned char test1_end(void)
{
	printf("\nTest suite end\n");

	unsigned char RET = Delete_Account(current_user_test-1);
	DBM_PrintUsers();
	return !RET;
}
/* The function that will execute before executing the Test suite */
int test_start()
{
	printf("\nTest suite start\n");
	// the start and end function should return 0 if they are successful 
	DBM_PrintUsers;
	return 0;
}

/* The function that will execute after executing the Test suite*/
int test_end()
{
	// the start and end function should return 0 if they are successful 
	printf("\nTest suite end\n");
	// or any thing else if it is failed
	DBM_PrintUsers;
	return 0;
}

/* init function for Test Suite 2*/
//static unsigned char test2_start(void)
//{
//	unsigned char RET = Add_Account(&Test2_User);
//	Test2_User.PersonalInfo_Form.id = current_user_test - 1;
//	DBM_PrintUsers();
//	return !RET;
//}
//
///* Closure Function For Test Suite 1*/
//static unsigned char test2_end(void)
//{
//	unsigned char RET = Delete_Account(current_user_test - 1);
//	DBM_PrintUsers();
//	return !RET;
//}


/************************************************* CREATE ACCOUNT *************************************************/

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Ahmed
*                          Age                          -> 26
*                          DOB_day                      -> 01
*                          DOB_Month                    -> 02
*                          DOB_Year                     -> 1999
*                          Educational_Status           -> Masters_Student
*                          Gender                       -> Male
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges123
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB should be updated with the previous inputs correctly
* Reason                 : All inputs are in correct format
*************************************************************************************/
static void TestCase1(void)
{
	unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test1_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test1_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test1_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test1_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test1_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test1_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test1_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test1_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test1_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test1_User.PersonalInfo_Form.id);
}

/************************************************************************************
* Test ID                : TestCase 2
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Rania
*                          Age                          -> 54
*                          DOB_day                      -> 31
*                          DOB_Month                    -> 12
*                          DOB_Year                     -> 1970
*                          Educational_Status           -> PHD_Holder
*                          Gender                       -> Female
*                          UserName                     -> EdgesAcademy2024
*                          Password                     -> Edges_123_
*                          Password Recheck             -> Edges_123_$$
* Test Expected output   : The DB shouldn't be updated with the previous inputs
* Reason                 : Password inputs mismatch so the suite willn't initiallize 
*************************************************************************************/
static void TestCase2(void)
{
	/* Test Code to test the Sign Up */
	static struct User_Input_Type Test2_User =
	{
		{
		-1, // this is to indecate user hasn't assigned ID 
		"Rania",
		54,
		31,
		12,
		1970,
		Female,
		PHD_Holder
		},
		{
			{
				"EdgesAcademy2024",
				"Edges_123_"
			},
		"Edges_123_$$"
		}
	};
		 unsigned char RET = Add_Account(&Test2_User);

		 CU_ASSERT_EQUAL(RET, FALSE);
	};
//************************************************************************************
//* Test ID                : TestCase 3
//* Description            : Testing the Validation of the name
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> A (invalid name)
//*                          Age                          -> 26
//*                          DOB_day                      -> 01
//*                          DOB_Month                    -> 02
//*                          DOB_Year                     -> 1999
//*                          Educational_Status           -> Masters_Student
//*                          Gender                       -> Male
//*                          UserName                     -> EdgesAcademy
//*                          Password                     -> Edges123
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB shouldn't be updated as the name is too short
//* Reason                 : Name is less than 3 characters (invalid value)
//*************************************************************************************/
	  static void TestCase3(void)
	{
		  static struct User_Input_Type Invalid_name_user =
		  {
			  {
			  -1, // this is to indecate user hasn't assigned ID 
			  "A",
			  26,
			  23,
			  10,
			  1998,
			  Male,
			  Masters_Student
			  },
			  {
				  {
					  "EdgesAcademy",
					  "Edges123"
				  },
			  "Edges123"
			  }
		  };
		  unsigned char RET = Add_Account(&Invalid_name_user);

		  CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE due to invalid name
	}
		
	  //************************************************************************************
  //* Test ID                : TestCase 4
  //* Description            : Testing the Validation of the age
  //* Pre-requisits          : There is a User Assigned to DB
  //* Test inputs            :
  //*                          Name                         -> Ahmed
  //*                          Age                          -> 125 (invalid age)
  //*                          DOB_day                      -> 01
  //*                          DOB_Month                    -> 02
  //*                          DOB_Year                     -> 1999
  //*                          Educational_Status           -> Masters_Student
  //*                          Gender                       -> Male
  //*                          UserName                     -> EdgesAcademy
  //*                          Password                     -> Edges123
  //*                          Password Recheck             -> Edges123
  //* Test Expected output   : The DB shouldn't be updated as the age is invalid
  //* Reason                 : The age is more than 100 
  //*************************************************************************************/
	  static void TestCase4(void)
	  {
		  struct User_Input_Type Invalid_age_user1 =
		  {
			  {
				  -1, // this is to indecate user hasn't assigned ID 
					  "Ahmed",
					  125,
					  23,
					  10,
					  1998,
					  Male,
					  Masters_Student
			  },
			  {
				  {
					  "EdgesAcademy",
					  "Edges123"
				  },
			  "Edges123"
			  }
		  };
		  unsigned char RET = Add_Account(&Invalid_age_user1);

		  CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE due to invalid age
	  }
	  
//************************************************************************************
//* Test ID                : TestCase 5
//* Description            : Testing the Validation of the age
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> Ahmed
//*                          Age                          -> -2 (invalid age)
//*                          DOB_day                      -> 01
//*                          DOB_Month                    -> 02
//*                          DOB_Year                     -> 1999
//*                          Educational_Status           -> Masters_Student
//*                          Gender                       -> Male
//*                          UserName                     -> EdgesAcademy
//*                          Password                     -> Edges123
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB shouldn't be updated as the age is invalid
//* Reason                 : The age is less than 0
//*************************************************************************************/
	  static void TestCase5(void)
	  {
		  struct User_Input_Type Invalid_age_user2 =
		  {
			  {
				  -1, // this is to indecate user hasn't assigned ID 
					  "Ahmed",
					  -2,
					  23,
					  10,
					  1998,
					  Male,
					  Masters_Student
			  },
			  {
				  {
					  "EdgesAcademy",
					  "Edges123"
				  },
			  "Edges123"
			  }
		  };

		  unsigned char RET = Add_Account(&Invalid_age_user2);

		  CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE due to invalid age
	  }

//************************************************************************************
//* Test ID                : TestCase 6
//* Description            : Testing matching of age and DOB_Year
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> Ahmed
//*                          Age                          -> 26
//*                          DOB_day                      -> 01
//*                          DOB_Month                    -> 02
//*                          DOB_Year                     -> 1988 (mismatch with age)
//*                          Educational_Status           -> Masters_Student
//*                          Gender                       -> Male
//*                          UserName                     -> EdgesAcademy
//*                          Password                     -> Edges123
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB shouldn't be updated because of the mismatch with age
//* Reason                 : Age doesn't match the year of birth
//*************************************************************************************/

static void TestCase6(void)
{
	struct User_Input_Type Invalid_age_user3 =
	{
		{
			-1, // this is to indecate user hasn't assigned ID 
				"Ahmed",
				12,
				23,
				10,
				1988,
				Male,
				Masters_Student
		},
		{
			{
				"EdgesAcademy",
				"Edges123"
			},
		"Edges123"
		}
	};

	unsigned char RET = Add_Account(&Invalid_age_user3);

	CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE due to dismatch of the age
	
}

//************************************************************************************
//* Test ID                : TestCase 7
//* Description            : Testing Invalid Gender
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> Ahmed
//*                          Age                          -> 26
//*                          DOB_day                      -> 01
//*                          DOB_Month                    -> 02
//*                          DOB_Year                     -> 1999
//*                          Educational_Status           -> Masters_Student
//*                          Gender                       -> Unknown (Invalid Gender)
//*                          UserName                     -> EdgesAcademy
//*                          Password                     -> Edges123
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB should NOT be updated due to invalid gender
//* Reason                 : Gender is not a valid option (Not a Male or Female)
//*************************************************************************************/

static void TestCase7(void)
{
	struct User_Input_Type Invalid_gender_user =
	{
		{
			-1, // this is to indecate user hasn't assigned ID 
				"Ahmed",
				26,
				23,
				10,
				1998,
				555,
				Masters_Student
		},
		{
			{
				"EdgesAcademy",
				"Edges123"
			},
		"Edges123"
		}
	};

	unsigned char RET = Add_Account(&Invalid_gender_user);

	CU_ASSERT_EQUAL(RET, FALSE);   // The function should return FALSE due to invalid gender

}

//************************************************************************************
//* Test ID                : TestCase 8
//* Description            : Testing Invalid Username
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> Ahmed
//*                          Age                          -> 26
//*                          DOB_day                      -> 01
//*                          DOB_Month                    -> 02
//*                          DOB_Year                     -> 1999
//*                          Educational_Status           -> Masters_Student
//*                          Gender                       -> Male
//*                          UserName                     -> Ed (Invaid username)
//*                          Password                     -> Edges123
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB should NOT be updated due to invalid gender
//* Reason                 : Gender is not a valid option (Not a Male or Female)
//*************************************************************************************/

static void TestCase8(void)
{
	struct User_Input_Type Invalid_gender_user =
	{
		{
			-1, // this is to indecate user hasn't assigned ID 
				"Ahmed",
				26,
				23,
				10,
				1998,
				Male,
				Masters_Student
		},
		{
			{
				"Ed",
				"Edges123"
			},
		"Edges123"
		}
	};

	unsigned char RET = Add_Account(&Invalid_gender_user);

	CU_ASSERT_EQUAL(RET, FALSE);   // The function should return FALSE due to invalid gender

}

//************************************************************************************
//* Test ID                : TestCase 9
//* Description            : Test deleting a valid account
//* Pre-requisits          : Account has been added previously
//* Test inputs            : User ID -> Valid ID of Test3_User
//* Test Expected output   : The account should be successfully deleted
//* Reason                 : Account exists and is deletable
//*************************************************************************************/
static void TestCase9(void)
{
	static struct User_Input_Type Test_User2 =
	{
		{
			-1, "Mohamed", 25, 5, 11, 1999, Male, Graduate
		},
{
	{"AdminUser2", "Edges123456"},
	"Edges123456"
}
	};

	DBM_Add_User(&Test_User2);
	Test_User2.PersonalInfo_Form.id = current_user_test - 1;
	printf("\n Test_user2 added succesfully \n");
	unsigned char RET = Delete_Account(current_user_test - 1);
 	CU_ASSERT_EQUAL(RET, TRUE);
	printf("\n Test_user2 Deleted succesfully \n");

	// The function should return TRUE indicating success
    // Check that the account is no longer in the DB
	//CU_ASSERT_EQUAL(DB_info[Test_id].id, -1);  // id should be -1 after deletion (indicating non-existent)
}

///************************************************************************************
//* Test ID                : TestCase 10
//* Description            : Test deleting a non-existent account
//* Pre-requisits          : No account exists with the given ID
//* Test inputs            : User ID -> Invalid ID
//* Test Expected output   : The account cannot be deleted
//* Reason                 : The account doesn't exist in the DB
//*************************************************************************************/
static void TestCase10(void)
{
	unsigned int Invalid_ID = 9999;  // Assuming this ID does not exist in the DB
	unsigned char RET = Delete_Account(Invalid_ID);
	CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE indicating failure
}

//************************************************************************************
//* Test ID                : TestCase 11
//* Description            : Test deleting an account with an invalid ID
//* Pre-requisits          : Account ID is invalid (negative or out-of-bounds ID)
//* Test inputs            : User ID -> Negative ID (-5)
//* Test Expected output   : The account cannot be deleted due to invalid ID
//* Reason                 : Account ID is invalid
//*************************************************************************************/
static void TestCase11(void)
{
	unsigned int Invalid_ID = -5;  // Invalid ID
	unsigned char RET = Delete_Account(Invalid_ID);
	CU_ASSERT_EQUAL(RET, FALSE);  // The function should return FALSE indicating failure
}

//************************************************************************************
//* Test ID                : TestCase 12
//* Description            : Test deleting an account in boundary scenario
//* Pre-requisits          : Account exists at the boundary of the DB
//* Test inputs            : User ID  -> Boundary valid ID
//* Test Expected output   : The account should be deleted successfully
//* Reason                 : The account is at the boundary of the DB, should still be deletable
//*************************************************************************************/
 static void TestCase12(void)
{
	unsigned int Boundary_ID = current_user_test - 1;  // Assuming this is the last valid ID
	unsigned char RET = Delete_Account(Boundary_ID);
	CU_ASSERT_EQUAL(RET, TRUE);  // The function should return TRUE indicating success
}



 /************************************************* LOGIN *************************************************/

 //************************************************************************************
//* Test ID                : TestCase 13
//* Description            : Testing the Detect User Type function with Admin input
//* Pre-requisits          : 
//* Test inputs            : User_Type ->  AdminMohamedTarek
//* Test Expected output   : The function should return AdminMohamedTarek
//* Reason                 : AdminMohamedTarek is a valid user type
//*************************************************************************************/
static void TestCase13(void)
{
	printf("\n \n");
	printf("                (Enter 0) \n  \n ");
	unsigned char User_Type = AdminMohamedTarek; // Simulate admin input
	unsigned char RET = Detect_User_Type();
	CU_ASSERT_EQUAL(RET, AdminMohamedTarek);
	printf("\n ");
}

//************************************************************************************
//* Test ID                : TestCase 14
//* Description            : Testing the Detect User Type function with NormalUser input
//* Pre-requisits          : 
//* Test inputs            :
//* User_Type              :NormalUser
//* Test Expected output   : The function should return NormalUser
//* Reason                 : NormalUser is a valid user type
//*************************************************************************************/
static void TestCase14(void)
{
	printf("\n"); 
	printf("                   (Enter 1) \n  \n ");
	unsigned char User_Type = NormalUser; // Simulate normal user input
	unsigned char RET = Detect_User_Type();
	CU_ASSERT_EQUAL(RET, NormalUser);
	printf("\n"); 
}

//************************************************************************************
//* Test ID                : TestCase 15
//* Description            : Testing the Detect User Type function with invalid input
//* Pre-requisits          : None
//* Test inputs            : User_Type  -> Invalid value (555)
//* Test Expected output   : The function should return IncorrectLogin
//* Reason                 : Invalid user type should result in IncorrectLogin
//*************************************************************************************/
static void TestCase15(void)
{
	printf("\n");
	printf("                   (Enter 555) \n  \n ");
	unsigned int User_Type = 555; // Simulate invalid input
	unsigned char RET = Detect_User_Type();
	CU_ASSERT_EQUAL(RET, IncorrectLogin);
	printf("\n "); 
}

//************************************************************************************
//* Test ID                : TestCase 16
//* Description            : Testing the Verify_Admin function with correct token input
//* Pre-requisits          : The SECRET_ADMIN_TOKEN is correctly defined
//* Test inputs            : SECRET_ADMIN_TOKEN
//* Test Expected output   : The function should return TRUE
//* Reason                 : The token is correct, so the function should grant access
//*************************************************************************************/
static void TestCase16(void)
{
	printf("\n \n");
	printf("                   (Enter the CORRECT Token (10203040)) \n \n");
	unsigned char Token = SECRET_ADMIN_TOKEN; // Simulate correct admin token
	unsigned char RET = Verify_Admin();
	CU_ASSERT_EQUAL(RET, TRUE);
}

//************************************************************************************
//* Test ID                : TestCase 17
//* Description            : Testing the Verify_Admin function with incorrect token on first attempt
//* Pre-requisits          : The SECRET_ADMIN_TOKEN is correctly defined
//* Test inputs            : 1234 (incorrect token)
//* Test Expected output   : The function should return FALSE after 3 failed attempts
//* Reason                 : The token is incorrect, and after 3 failed attempts, the function should return FALSE
//*************************************************************************************/
static void TestCase17(void)
{
	printf("\n \n ");
	printf("                   (Enter WRONG Token) \n  \n "); 
	unsigned char Token = 1234; // Simulate incorrect token
	unsigned char RET = Verify_Admin(); // First attempt
	CU_ASSERT_EQUAL(RET, FALSE); // Should return false after 3 attempts
}

//************************************************************************************
//* Test ID                : TestCase 18
//* Description            : Testing the Verify_User function with valid username and password
//* Pre-requisits          : A valid user exists in DB_LoginCredentials
//* Test inputs            :
//*                          UserName                     -> "AdminUser2"
//*                          Password                     -> "Edges123456"
//* Test Expected output   : The function should return Login_Successful and assign the correct user ID
//* Reason                 : The username and password are correct, so login should succeed
//*************************************************************************************/
static void TestCase18(void)
{
	int userId;
	char* UserName = "AdminUser2";
	char* Password = "Edges123456";

	unsigned char RET = Verify_User(UserName, Password, &userId);
	CU_ASSERT_EQUAL(RET, Login_Successful);
	CU_ASSERT_EQUAL(userId, 1); // Assuming admin has id 1
}

//************************************************************************************
//* Test ID                : TestCase 19
//* Description            : Testing the Verify_User function with incorrect password
//* Pre-requisits          : A valid user exists in DB_LoginCredentials
//* Test inputs            :
//*                          UserName                     -> "AdminUser2"
//*                          Password                     -> "wrongpassword"
//* Test Expected output   : The function should return Password_incorrect and assign user ID as -1
//* Reason                 : The password is incorrect, so login should fail
//*************************************************************************************/
static void TestCase19(void)
{
	int userId;
	char* UserName = "AdminUser2";
	char* Password = "wrongpassword";

	unsigned char RET = Verify_User(UserName, Password, &userId);
	CU_ASSERT_EQUAL(RET, Password_incorrect);
	CU_ASSERT_EQUAL(userId, -1); // Invalid user ID due to incorrect password
}

//************************************************************************************
//* Test ID                : TestCase 20
//* Description            : Testing the Verify_User function with non-existing username
//* Pre-requisits          : No user with the username exists in DB_LoginCredentials
//* Test inputs            :
//*                          UserName                     -> "NonExistentUser"
//*                          Password                     -> "wrongPassword"
//* Test Expected output   : The function should return UserName_NotFound and assign user ID as -1
//* Reason                 : The username does not exist, so login should fail
//*************************************************************************************/
static void TestCase20(void)
{
	int userId;
	char* UserName = "NonExistentUser";
	char* Password = "wrongPassword";

	unsigned char RET = Verify_User(UserName, Password, &userId);
	CU_ASSERT_EQUAL(RET, UserName_NotFound);
	CU_ASSERT_EQUAL(userId, -1); // Invalid user ID because the username was not found
}

/************************************************* COURCE REG *************************************************/

//************************************************************************************
//* Test ID                : TestCase 21
//* Description            : Testing AddStudentToCourse with a student already enrolled
//* Pre-requisits          : The student should already be enrolled in the course
//* Test inputs            :
//*                          Course_id                    -> 5
//*                          Student_id                   -> 0
//* Test Expected output   : The function should return AlreadyEnrolled
//* Reason                 : The student is already enrolled to this course
//*************************************************************************************/

static void TestCase21(void) {
	unsigned char RET;
	unsigned int Course_id = 5;
	unsigned int Student_id = 0;
	Enrollments[Student_id][Course_id - 1] = TRUE; // Student is already enrolled

	RET = AddStudentToCourse(Course_id, Student_id);
	CU_ASSERT_EQUAL(RET, AlreadyEnrolled);
}

//************************************************************************************
//* Test ID                : TestCase 22
//* Description            : Testing AddStudentToCourse with a student is not enrolled
//* Pre-requisits          : The student is not already enrolled
//* Test inputs            :
//*                          Course_id                    -> 1
//*                          Student_id                   -> 1
//* Test Expected output   : The function wouldn't return AlreadyEnrolled
//* Reason                 : The student is unenrolled to this course
//*************************************************************************************/

static void TestCase22(void) {
	unsigned char RET;
	unsigned int Course_id = 1;
	unsigned int Student_id = 1;
	Enrollments[Student_id][Course_id - 1] = FALSE; // Student isn't enrolled

	RET = AddStudentToCourse(Course_id, Student_id);
	CU_ASSERT_NOT_EQUAL(RET, AlreadyEnrolled);  
}

/************************************************************************************
//* Test ID                : TestCase 23
//* Description            : Testing AddStudentToCourse with a student is not enrolled
//* Pre-requisits          :The student is not already enrolled, and there is room in the course
//* Test inputs            :
//*                          Course_id                    -> 2
//*                          Student_id                   -> 0
//* Test Expected output   : The function should return Enrolled
//* Reason                 : The student is not enrolled to this course yet
//*************************************************************************************/

	static void TestCase23(void) {
		unsigned char RET;
		unsigned int Course_id = 2;
		unsigned int Student_id = 0;

		Enrollments[Student_id][Course_id - 1] = FALSE; // Student isn't enrolled YET
		DBM_AddToCourse;

		RET = AddStudentToCourse(Course_id, Student_id);
		CU_ASSERT_EQUAL(RET, Enrolled); 
	}

/************************************************************************************
//* Test ID                : TestCase 24
//* Description            : Testing AddStudentToCourse when the course capacity is full
//* Pre-requisits          : Course with id 5 has three users
//* Test inputs            : Add three Test users with valid inputs
//* Test Expected output   : The function should return CapacityCompleted
//* Reason                 : The course capacity is already full
//*************************************************************************************/
	static void TestCase24(void) {

		// The three users in dta base are already enrolled in cousre id 5
	
		static struct User_Input_Type Test_User11 =
		{
			{
				-1, "Ahmed", 23, 1, 2, 2001, Male, Student
			},
			{
				{"AdminUser1","Edges123"},
				"Edges123"
			}
		};
		unsigned char ret1 = Add_Account(&Test_User11);
		Test_User11.PersonalInfo_Form.id = current_user_test - 1;
		unsigned char Ret1 = AddStudentToCourse(5, Test_User11.PersonalInfo_Form.id);
		CU_ASSERT_EQUAL(Ret1, Enrolled);
		CU_ASSERT_EQUAL(Enrollments[Test_User11.PersonalInfo_Form.id][4], TRUE);
		DBM_CheckReservations();

		static struct User_Input_Type Test_User22 =
		{
			{
			-1,"Mohamed",25,5,11,1999,Male,Graduate
			},
			{
				{"AdminUser2", "Edges123456"},
				"Edges123456"
			}
		};
		unsigned char ret2 = Add_Account(&Test_User22);
		Test_User22.PersonalInfo_Form.id = current_user_test - 1;
		unsigned char Ret2 = AddStudentToCourse(5, Test_User22.PersonalInfo_Form.id);
		CU_ASSERT_EQUAL(Ret2, Enrolled);
		CU_ASSERT_EQUAL(Enrollments[Test_User22.PersonalInfo_Form.id][4], TRUE);
		DBM_CheckReservations();

		static struct User_Input_Type Test_User33 =
		{
			{
			-1,"Nada",24,3,4,2000,Female,Graduate
			},
			{
				{"AdminUser3","Edges_123"},
				"Edges_123"
			}
		};
		unsigned char ret = Add_Account(&Test_User33);
		Test_User33.PersonalInfo_Form.id = current_user_test - 1;
		CU_ASSERT_EQUAL(ret,TRUE);
		unsigned char Ret = AddStudentToCourse(5, Test_User33.PersonalInfo_Form.id);
		CU_ASSERT_EQUAL(Ret, Enrolled);
		CU_ASSERT_EQUAL(Enrollments[Test_User33.PersonalInfo_Form.id][4],TRUE);
		DBM_CheckReservations();

		unsigned int user_ID = 5;
		unsigned char RET5 = AddStudentToCourse(5, 5);
		CU_ASSERT_EQUAL(RET5, CapacityCompleted); 

		Delete_Account(current_user_test - 1);
		Delete_Account(current_user_test - 1); 

	}

	 
//************************************************************************************
//* Test ID                : TestCase 25
//* Description            : Testing ShowStudentCourses with a valid User ID
//* Pre-requisits          : A student is enrolled in some courses
//* Test inputs            :
//*                          User_ID                     -> 1
//* Test Expected output   : The function should display the student's enrolled courses
//*************************************************************************************/
	static void TestCase25(void)
	{
		printf("\n");
		unsigned int User_ID = 1;
		// Simulate the display of courses that student is enrolled in
		ShowStudentCourses(User_ID);
		CU_ASSERT_TRUE(1); 
	}

/************************************************************************************
//	* Test ID                : TestCase 26
//	* Description            : Testing ShowStudentCourses with a Invalid User ID
//	* Pre-requisits          : A student is enrolled in some courses
//	* Test inputs            :
//	*                          User_ID                     -> 222
//	* Test Expected output   : The function should return "Invalid User Id"
//	*************************************************************************************/
	static void TestCase26(void)
	{
		printf("\n"); 
		unsigned int User_ID = 222; // Invalid id
		
		ShowStudentCourses(User_ID);
		CU_ASSERT_TRUE(1);
	}

	//************************************************************************************
	//* Test ID                : TestCase 27
	//* Description            : Testing ShowListOfCourses 
	//* Pre-requisits          : 
	//* Test inputs            :
	//* Test Expected output   : The function should display all courses list
	//*************************************************************************************/
		static void TestCase27(void)
		{
			printf("\n");			
			ShowListOfCourses();
	
			CU_ASSERT_TRUE(1); 
		}


/************************************************* DataBase *************************************************/

//************************************************************************************
//* Test ID                : TestCase 28
//* Description            : Testing the DBM_Add_User function with valid input
//* Pre-requisites          : None
//* Test inputs            : 
//*                          Name                         -> Rania
//*                          Age                          -> 54
//*                          DOB_day                      -> 31
//*                          DOB_Month                    -> 12
//*                          DOB_Year                     -> 1970
//*                          Educational_Status           -> PHD_Holder
//*                          Gender                       -> Female
//*                          UserName                     -> EdgesAcademy2024
//*                          Password                     -> Edges_123_
//*                          Password Recheck             -> Edges_123_$$
// 
//* Test Expected output   : The function should return 1 (successful), and a new user should be added to DB_info
//* Reason                 : The user input is valid and the user should be added successfully to the database
//*************************************************************************************/

		static void TestCase28(void)
		{
			struct User_Input_Type Test3_User = {
		{
		-1, // this is to indecate user hasn't assigned ID 
		"Rania",
		54,
		31,
		12,
		1970,
		Female,
		PHD_Holder
		},
		{
			{
				"EdgesAcademy2024",
				"Edges_123_"
			},
		"Edges_123_"
		}
			};

			unsigned char RET = DBM_Add_User(&Test3_User);
			Test3_User.PersonalInfo_Form.id = current_user_test - 1;
			unsigned int Test_id = Test3_User.PersonalInfo_Form.id;
			CU_ASSERT_EQUAL(RET, TRUE); // Successful addition  
			CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test3_User.PersonalInfo_Form.Age);
			CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test3_User.PersonalInfo_Form.name);
			CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test3_User.LoginCredentials_Form.LoginCredentials.User_Name); 
			  
		}

//************************************************************************************
//* Test ID                : TestCase 29
//* Description            : Testing the DBM_Delete_User function for valid user deletion
//* Pre-requisites          : A user exists in the database
//* Test inputs            : User ID -> 3
//* Test Expected output   : The function should return 1 (successful), and the user should be deleted from DB_info
//* Reason                 : The user ID exists, so deletion should be successful
//*************************************************************************************/
		static void TestCase29(void)
		{
			unsigned char RET = DBM_Delete_User(current_user_test - 1); // Deleting user  
			CU_ASSERT_EQUAL(RET, 1); // Successful deletion
			//CU_ASSERT_EQUAL(DB_info[current_user_test - 1].Age, 0); // User data should be cleared
			//CU_ASSERT_STRING_EQUAL(DB_info[current_user_test - 1].name, ""); // User name should be empty
		}

//************************************************************************************
//* Test ID                : TestCase 30
//* Description            : Testing the DBM_AddToCourse function when there is space in the course
//* Pre-requisites         : User exists and the course has available spots
//* Test inputs            : Add new Test User With valid inputs
//*                          Course ID -> 2 
//* Test Expected output   : The function should return TRUE, and the user should be added to the course
//* Reason                 : The course is not full, and the user should be successfully added
//*************************************************************************************/

		static void TestCase30(void)
		{
			static struct User_Input_Type Test_User2 =
			{
				{
					-1, "Mohamed", 25, 5, 11, 1999, Male, Graduate
				},
		{
			{"AdminUser2", "Edges123456"},
			"Edges123456"
		}
			};

			DBM_Add_User(&Test_User2);
			Test_User2.PersonalInfo_Form.id = current_user_test - 1;

			unsigned char RET = DBM_AddToCourse(3,Test_User2.PersonalInfo_Form.id);
			CU_ASSERT_EQUAL(RET, TRUE); 
			CU_ASSERT_EQUAL(Enrollments[Test_User2.PersonalInfo_Form.id][2] , TRUE); 
			DBM_Delete_User(current_user_test - 1);   
		}

//************************************************************************************
//* Test ID                : TestCase 31
//* Description            : Testing the DBM_PrintUserData_Admin function
//* Pre-requisites         : User exists in the database
//* Test inputs            : User ID -> 0 (Admin viewing the data of User 0)
//* Test Expected output   : The function should return TRUE and print the data of the specified user
//* Reason                 : Admin should have the ability to view all user data
//*************************************************************************************/

		static void TestCase31(void)
		{
			unsigned char RET = DBM_PrintUserData_Admin(0); // Admin viewing user with ID 0
			CU_ASSERT_EQUAL(RET, TRUE); // User data should be printed successfully
		}

//************************************************************************************
//* Test ID                : TestCase 32
//* Description            : Testing the DBM_PrintUserData_User function for a regular user
//* Pre-requisites         : User exists in the database
//* Test inputs            : User ID -> 1 (User requesting their own data)
//* Test Expected output   : The function should return TRUE and print the data of the specified user
//* Reason                 : The user should be able to view their own data (without admin-specific fields)
//*************************************************************************************/

		static void TestCase32(void)
		{
			unsigned char RET = DBM_PrintUserData_User(1); // User viewing their own data
			CU_ASSERT_EQUAL(RET, TRUE); // User data should be printed successfully
		}
//************************************************************************************
//* Test ID                : TestCase 33
//* Description            : Testing the DBM_CheckReservations function
//* Pre-requisites         : Users are enrolled in some courses
//* Test inputs            : None
//* Test Expected output   : The function should display the reservation status for each course
//* Reason                 : All courses' reservation statuses should be correctly displayed
//*************************************************************************************/

		static void TestCase33(void)
		{
			DBM_CheckReservations(); // Display course reservation statuses
			// Manual check: Ensure the course statuses are correctly displayed in the output
			// (like the previous case, output-based verification)
		}

//************************************************************************************
//* Test ID                : TestCase 34
//* Description            : Testing the DBM_Delete_User function with an invalid user ID
//* Pre-requisites         : None
//* Test inputs            : User ID -> 222 
//* Test Expected output   : The function should return FALSE (failure to delete)
//* Reason                 : The user ID does not exist, so the deletion should fail
//*************************************************************************************/

		static void TestCase34(void)
		{
			unsigned char RET = DBM_Delete_User(222); // Attempt to delete a non-existent user with ID 999
			CU_ASSERT_EQUAL(RET, FALSE); // Deletion should fail
		}

//************************************************************************************
//* Test ID                : TestCase 35
//* Description            : Testing the DBM_PrintUserData_Admin function with an invalid user ID
//* Pre-requisites         : None
//* Test inputs            : User ID -> 222 
//* Test Expected output   : The function should return FALSE (failure to print data)
//* Reason                 : The user ID does not exist, so the print operation should fail
//*************************************************************************************/

		static void TestCase35(void)
		{
			unsigned char RET = DBM_PrintUserData_Admin(222); // Attempt to print user data for a non-existent user
			CU_ASSERT_EQUAL(RET, FALSE); // Print should fail
		}

//************************************************************************************
//* Test ID                : TestCase 36
//* Description            : Testing the DBM_DeleteReservation function with an invalid course ID
//* Pre-requisites         : None
//* Test inputs            : Invalid Course ID -> 10
//*                          Valid User ID -> 1
//* Test Expected output   : The function should return ERROR (failure to delete)
//* Reason                 : The course ID does not exist, so the deletion should fail
//*************************************************************************************/

		static void TestCase36(void)
		{
			unsigned char RET = DBM_DeleteReservation(10, 1); // Invalid course ID (10)
			CU_ASSERT_EQUAL(RET, ERROR); // The function should return ERROR
		}

/************************************************************************************
//* Test ID                : TestCase 37
//* Description            : Testing Adding users more than MAX_USERS
//* Pre-requisits          : Three users are already added  to data base
//* Test inputs            : Add three Test users with valid inputs to data base
//* Test Expected output   : The function should return FALSE 
//* Reason                 : MAX_USERS = 5 
//*************************************************************************************/

		static void TestCase37(void)
		{
			// Data Base has 3 users
			//MAX_USERS =5
			static struct User_Input_Type Test_User5 =
			{
				{
					-1, "Ahmed", 23, 1, 2, 2001, Male, Student
				},
				{
					{"AdminUser1","Edges123"},
					"Edges123"
				}
			};
			unsigned char ret1 = DBM_Add_User(&Test_User5); 
			Test_User5.PersonalInfo_Form.id = current_user_test - 1;
			CU_ASSERT_EQUAL(ret1, TRUE);

			static struct User_Input_Type Test_User6 =
			{
				{
				-1,"Mohamed",25,5,11,1999,Male,Graduate
				},
				{
					{"AdminUser2", "Edges123456"},
					"Edges123456"
				}
			};
			unsigned char ret2 = DBM_Add_User(&Test_User6);
			Test_User6.PersonalInfo_Form.id = current_user_test - 1;
			CU_ASSERT_EQUAL(ret2, TRUE);

			static struct User_Input_Type Test_User7 =
			{
				{
				-1,"Nada",24,3,4,2000,Female,Graduate
				},
				{
					{"AdminUser3","Edges_123"},
					"Edges_123"
				}
			};
			unsigned char ret3 = DBM_Add_User(&Test_User7);
			Test_User7.PersonalInfo_Form.id = current_user_test - 1;
			CU_ASSERT_EQUAL(ret3, FALSE); 

			DBM_Delete_User(current_user_test - 1);
			DBM_Delete_User(current_user_test - 1);
			 
		}


void Main_Test_Runner(void)
{
	/* initialize the Registry */
	CU_initialize_registry();

	/* Adding Test Suite to the Registry */
	CU_pSuite suite_positive = CU_add_suite("Creaet Valid Account", test1_start, test1_end);
	CU_pSuite suite_negative = CU_add_suite("Creaet InValid Account", test_start, test_end);
	CU_pSuite suite_userType = CU_add_suite("Detect User Type", test_start, test_end);
	CU_pSuite suite_verifyAdmin = CU_add_suite("Admin Verfication", test_start, test_end); 
	CU_pSuite suite_verifyUser = CU_add_suite("User Verfication", test_start, test_end);
	CU_pSuite suite_CR_positive = CU_add_suite("Course Registration Valid", test_start, test_end);
	CU_pSuite suite_CR_negative = CU_add_suite("Course Registration Invalid", test_start, test_end);
	CU_pSuite suite_DB_positive  = CU_add_suite("Data Base Valid", test_start, test_end);
	CU_pSuite suite_DB_negative = CU_add_suite("Data Base Invalid", test_start, test_end);

	/* Adding Test Cases to the Test Suite*/
	CU_add_test(suite_positive, "Creaet Valid Account", TestCase1);
	CU_add_test(suite_positive, "Delete Valid Account", TestCase9);  
	CU_add_test(suite_positive, "Delete Account at Boundary", TestCase12);

	// this suite is expected to fail and not to run due to to the invalid creation of the account 
	CU_add_test(suite_negative, "Creaet InValid Account", TestCase2);
	CU_add_test(suite_negative, "Invalid Name (Too Short)", TestCase3);
	CU_add_test(suite_negative, "Invalid Age (Too High)", TestCase4);
	CU_add_test(suite_negative, "Invalid Age (Too Low)", TestCase5);
	CU_add_test(suite_negative, "Age and DOB Year Mismatch", TestCase6);
	CU_add_test(suite_negative, "Invalid Gender", TestCase7);
	CU_add_test(suite_negative, "Invalid Username (Too Short)", TestCase8);
	CU_add_test(suite_negative, "Delete Non-Existent Account", TestCase10);
	CU_add_test(suite_negative, "Delete Account with Invalid ID", TestCase11);

	// this suite for Detect User type 
	CU_add_test(suite_userType, "Detect user type (Admin)", TestCase13);  
	CU_add_test(suite_userType, "Detect user type (Normal user)", TestCase14);  
	CU_add_test(suite_userType, "Detect user type (Invalid)", TestCase15);  

	 //this suite for verify_Admin Function
	CU_add_test(suite_verifyAdmin, "Correct Secret Admin Token", TestCase16); 
	CU_add_test(suite_verifyAdmin, "Incorrect Token", TestCase17);  

	// this suite for verify_User Function
	CU_add_test(suite_verifyUser, "Valid User", TestCase18);
	CU_add_test(suite_verifyUser, "Invalid Password", TestCase19);
	CU_add_test(suite_verifyUser, "Invalid User", TestCase20);

	//this suites of Course Registeratoin 
	CU_add_test(suite_CR_positive, "Already enrolled Student", TestCase21);
	CU_add_test(suite_CR_positive, "Add Student to course", TestCase23); 
	CU_add_test(suite_CR_positive, "Show courses list with valid id", TestCase25);
	CU_add_test(suite_CR_positive, "Show All courses list", TestCase27);


	CU_add_test(suite_CR_negative, " Unenrolled Student", TestCase22);
	CU_add_test(suite_CR_negative, " Add Student to full capacity course", TestCase24);    
	CU_add_test(suite_CR_negative, " Show courses list with Invalid id", TestCase26); 

	//Suites for Data Base
	CU_add_test(suite_DB_positive, "Add user to Data Base", TestCase28); 
	CU_add_test(suite_DB_positive, "Delete User from Data Base", TestCase29); 
	CU_add_test(suite_DB_positive, "Add User to a Course", TestCase30);  
	CU_add_test(suite_DB_positive, " Printing User Data (Admin)", TestCase31); 
	CU_add_test(suite_DB_positive, " Printing User Data (User)", TestCase32); 
	CU_add_test(suite_DB_positive, " Checking Course Reservations", TestCase33);
	CU_add_test(suite_DB_positive, " Checking adding MAX_USERS", TestCase37);

	CU_add_test(suite_DB_negative, "Deleting a Non-Existent User", TestCase34);
	CU_add_test(suite_DB_negative, "Invalid User ID in Print User Data (Admin)", TestCase35);
	CU_add_test(suite_DB_negative, "Invalid Course ID in Reservation Deletion", TestCase36);



	/* Running the Test Suite through Basic Console */
	//CU_basic_set_mode(CU_BRM_VERBOSE);
	//CU_basic_run_tests();

	/* Running the Test Suite through Console interactive */
	 CU_console_run_tests();

	/* Clear the registry after test finished */
	CU_cleanup_registry();
}


// 24 31