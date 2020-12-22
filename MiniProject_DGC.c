#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
void additem(FILE *fp,FILE *fplist);//function to add item
void manager();//login function
void manager_menu();
void deleteitem(char toRemove[100],FILE *fptr);
void removeAll(char * str, const char * toRemove);
int IndexOf(FILE *fptr, const char *word, int *line, int *col);
void printdetails(char *str);
int Check(char *word,FILE *fptr);
void search();
//function definition of all the functions in ht e program
void categories();
void women_wear();
void offers();
void editoffers();
void login();
void Customer();
//defining range for few variables globally
#define LSIZ 128
#define RSIZ 10
#define MAX 256
void fileprint(char* s);
#define BUFFER_SIZE 1000
void review();
//A structure to store the update the offers for the customer and manager
struct customer
{
	//variables are defined in the data types
	char name[100];
    char mobilenumber[10];
	char gpayid[100];
};
struct customer c;//structure pointer to access the variable
struct item
{
	//storing the required variables in a structure to access when needed
	char name[100];
	int code;
	//variables to access various items availability
	int floor;
	int row;
	int stand;
	char price[100];
	char offer[100];
};
struct item item;
//item is a structure pointer

int main()
{
	system("color 04");
	//char n[50];
	int l;
	//displaying the menu page
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n\t\t\t                    WELCOME TO THE SHOPPING PORTAL!!            \t\t\t\n ");
    printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    //using a do while loop to continue the process until user or customer asks to exit the application
	do
    {
    	printf("\nChoose Who You Are :<!!!\n" );
    	//Giving them the choice
    	printf("\n\n(1.)Customer\n\n(2.)Manager\n\n(3.)Exit\n\n");
        scanf("%d",&l);
        switch(l)
        {
        	//In case1 the customer is provided to view few modules and that can be accessed by entering 1
        	case 1:printf("\n\n\n------------------------------------------------------------------------------------------------------------------------\n");
        	       printf("\n\n\t\t\t\t\t\tHELLO CUSTOMER!!\n\t\t\t\t\tWELOCOME TO THE DOORWAY GROCERY CATALOGUE             \n");
        	       printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");
        	       //function call for customer function
        	       Customer();
		           break;
            case 2://printf("\n---------------------------------------------------------------\n\n");
                   //Managers  option is 2 he can enter the login portal by choosing it
	               printf("\n\n\t\t\tDear manager to access the cart, You need to login!!\n");
                	login();
	               printf("\n\t\t\t---------------------------------------------------------------------------------------\n");
	               printf("\n\t\t\t---------------------------------------------------------------------------------------\n");
                   break;
            case 3:exit(1);
            default:printf("\n\nWrong Choice!!\n");
        }
    }while(l<=3);
    system("cls");
	return 0;
}
void Customer()
{
	//the function is for customer and to choose his options and that function calls are given using a switch case 
    system("color 0A");
	int n,d;
	printf("\n\nDear, Customer!!Here is the shopping menu\n");
     //A menu driven program is given displaying different modules

	printf("\n\n( 1.)Search product\n\n( 2.)Categories\n\n( 3.)View Offers\n\n( 4.)Review ( Necessary )\n\n( 5.)Return to menu\n\n");
	printf("\n\nPlease Enter your choice :    ");
	scanf("%d",&n);
	//do
	//{
	switch(n)
	{
		       //searching a product
		case 1:printf("\n\nYou can search the required item here!!\n");
		      search();
			  break;
			  //Categories will be diplayed
		case 2:printf("\n\nWe will be displaying you all the cateogies available in the store!!\n");
		       categories();
			   break;
			   //the customer can view the offers available in the store
	    case 3:printf("\n\nWe will be displaying you all the offers available:\n");
	           offers();
	           break;
	           //review of the store is given by the customer
	    case 4:printf("\n\n----------REVIEW OF THE STORE---------\n");
	           review();
	    case 5:return;
		default:printf("\n\nInvalid Choice!!\n");
	}
//}while(n<=3);
	printf("\n\nDo you want to continue shopping!!\n\n( 1.)Yes\n\n ( 2.)No\n\n");
	scanf("%d",&d);

	system("cls");
	if(d==1)
	{
		//if the customer wants to continue he'll go back to the customer function
		Customer();
	}
	else
	{
		//or else returns to the main menu
		main();
	}
	//system("clear");
}
void login()
{
	system("color 05");
	//if manager i entered then it enters into the login function
	printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");

	printf("\n\n\t\t\t\t\t\tManager!!Enter the password for logging in !!                     \n");

	printf("\n\n------------------------------------------------------------------------------------------------------------------------\n");

	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    //user and password are already inbuilt 
    char user[10]="Manager";
    char pass[10]="12345";
    do
   {

  // if the manager enters the correct login id nd password then it enters into further modules 

    printf("\n ======================  LOGIN FORM  ======================  \n");
    printf(" \n          ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n           ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"Manager")==0 && strcmp(pword,"12345")==0)
	{
	printf("  \n\n\n    WELCOME TO DOORWAY GROCERY CATALOGUE !! YOUR LOGIN IS SUCCESSFUL\n\n\n");
	manager_menu();
	getch();//holds the screen
	break;
	}
	else
	{
		//ele displays error message
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen
		system("cls");

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
		system("cls");
}

void manager_menu()
{
	//manager menu is shown all the modules are included and their functions are called
	//creating a background colour
	system("color 08");

	int d,n,m;
	char f[100];
	FILE *fp,*fplist;
	//do{
	printf("\n\nSelect your choice Manager!!\n\n");
	printf("\n\n( 1.)AddItem\n\n( 2.)DeleteItem\n\n( 3.)Update Offers\n\n( 4.)Exit\n\n");

//meny driven to add delete and update the particular items and offers 
	scanf("%d",&d);
	switch(d)
	{

		//if the manager wanrts to add item he can enter the category and then delete
		case 1:printf("\n\nSelect catagory to add item\n( 1.)Clothing\n\n( 2.)Footwear\n\n( 3.)Vegtables\n\n( 4.)Fruits\n\n( 5.)Furniture\n\n( 6.)Electronics \n\n ( 7.)Beauty\n\n ( 8.)Exit\n\n");
			printf("\n\nEnter your choice :   " );
			scanf("%d",&n);
			switch(n)
			{

				//two lists are taken one to store the details of the item and another to store only the particular items
				case 1:fp=fopen("item.txt","a+");
					fplist=fopen("clothing.txt","a+");
					//append mode enables to create changes
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
					//footwear
				case 2:fp=fopen("item.txt","a+");
					fplist=fopen("footwear.txt","a+");
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
					//veggies
				case 3:fp=fopen("item.txt","a+");
					fplist=fopen("vegetable.txt","a+");
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
					//fruits
				case 4:fp=fopen("item.txt","a+");
					fplist=fopen("fruits.txt","a+");
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
					//furniture
				case 5:fp=fopen("item.txt","a+");
					fplist=fopen("furniture.txt","a+");
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
					//electonics
				case 6:fp=fopen("item.txt","a+");
					fplist=fopen("electronics.txt","a+");
					additem(fp,fplist);  
					fclose(fp);
					fclose(fplist);
					break;
					//beauty
				case 7:fp=fopen(
					"item.txt","a+");
					fplist=fopen("beauty.txt","a+");
					additem(fp,fplist);
					fclose(fp);
					fclose(fplist);
					break;
				case 8://exit(1);
				       break;
				default:printf("Invalid option !! go for next :<");
			}

			system("cls");
			break;

			//Manager can delete items if they are in the particular list
			//else gives a message

		case 2:printf("\n\nSelect the  catagory to  delete item : \n\n ( 1.)Clothing\n\n( 2.)Footwear\n\n( 3.)Vegtables\n\n( 4.)Fruits\n\n ( 5.)Furniture\n\n( 6.)Electronic Appliances\n\n( 7.)Beauty And Cosmetics\n\n( 8.)Exit\n\n");
			printf("\n\nEnter The category which you want to choose:  ");
			scanf("%d",&n);
			switch(n)
			{
				//opens the particular file  
				//where the item names are stored
				case 1:fplist=fopen("clothing.txt","a+");
                       printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       //checks if the item is available
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	//goes to the function and deletes the item
                       	deleteitem(f,fplist);
					    fclose(fplist);
					    //closes the file afyter finishing the task
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//footwear deletion
				case 2:fplist=fopen("footwear.txt","a+");
					   printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//vegetable deletion
				case 3:fplist=fopen("vegetable.txt","a+");
					   printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//fruit deletion
				case 4:fplist=fopen("fruits.txt","a+");
					   printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//furniture deletion
				case 5:fplist=fopen("furniture.txt","a+");
					    printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//electronics deletion
				case 6:fplist=fopen("electronics.txt","a+");
					   printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
					//beauty deletion
				case 7:fplist=fopen("beauty.txt","a+");
					   printf("\n\nEnter the item you want to delete : ");
                       scanf("%s",&f);
                       m=Check(f,fplist);
                       if(m==1)
                       {
                       	deleteitem(f,fplist);
					    fclose(fplist);
                       }
                       else
                       {
                       	printf("\n\nThe item yow anted to delete is unavailable in the store!!\n");
                       }

					break;
				case 8:return;

				default:printf("\nInvalid choice!! go for next!!\n\n");
		       }
		       break;
		       //manager have a option to delete offers

		       system("cls");

		case 3:editoffers();
		       break;
		case 4:break;
		default:printf("\n\nInvalid choice!! go for next\n\n");
	}
    //}while(d<=3);
	int man;
	//he can continue by choosing any on eof it
	printf("\n\nManager if you want to continue : \nPress\n ( 1.) Yes\n\n( 2.)No\n\n");
	printf("\n\nChoose: ");
    scanf("%d",&man);
    system("cls");
    if(man==1)
    {
    	manager_menu();
    }
    else
    {
    	printf("\n\nYou will be returning to the login portal!...\n\n");
    	main();
    }
    //system("clear");
}
void additem(FILE *fp,FILE *fplist)
{

    system("color 0E");
    //FILE *fp1=fopen("offers.txt","a+");
	int a,n,m,st,fl;
	//char temp;
	//do{
	printf("\n\nManager now you can add items!\n\n( 1.)Add\n\n(2.)Return to menu\n\n");
	printf("\n\nChoose: ");
	scanf("%d",&a);
	switch(a)
	{
                //manager can enter details of item and that will be tored in theitem file
		case 1:	printf("\n\nPlease Enter the  item name you want to add in the list :  ");
				scanf("%s",&item.name);
				//scanf("%[^\n]",&item.name);
				//fgets(item.name,strlen(item.name),stdin);

				//check whether the item is there if it it there prints mesage
		       	n=Check(item.name,fplist);
		       	m=Check(item.name,fp);
		       	if(n==1 && m==1)
		       	{
					printf("\n\nThe item  is already avaliable the category you have chosen!! \n\nChoose another item to insert: ");
		        }
		       	if(n==0)

		       	{
		       		//if item i deleted then it updates to the file containing only the item names 
	        		fprintf(fplist, "%s\n",item.name);
	        	}
        		if(m==0)
        		{
        			//else it gets into the two file
	        	fprintf(fp," \n%s",item.name);
         		printf("\n\nEnter the unique code of the item :  ");
		        scanf("%d",&item.code);

        		fprintf(fp,"\nThe item code is :  %d",item.code);
	        	printf("\n\nEnter the particular location of the item :  " );
	        	printf("\n\nFloor : ");
                scanf("%d",&item.floor);
		        printf("\n\nStand : ");
        		scanf("%d",&item.stand);
        		printf("\n\nRow:  ");
        		scanf("%d",&item.row);
        		fprintf(fp,"\nThe location of the item is : Floor :  %d \nStand :  %d \nRow :  %d ",item.floor,item.stand,item.row);
        		printf("\n\nEnter the  price of the item:  " );
	        	scanf("%s",&item.price);
        		//gets(item.price);
        		fprintf(fp,"\nThe price of the item is :  %s ",item.price );

        		printf("\n\nEnter the offer if available else type ( Offer Ended):\n\n");
        		scanf("%s",&item.offer);

        		fprintf(fp, "\nOffer:%s",item.offer);
        		//fprintf(fp1, "\n%s",item.offer);

        		 }
        		break;
        		//if manager enters 2 then it returns to main menu
        case 2:manager_menu();
               break;

        default:printf("\n\nInvalid choice!!\n");
   	}
   //}while(a<=3);
	fclose(fp);
	//fclose(fp1);
	fclose(fplist);
	int h;
	printf("\n\nManager do you want to continue : \n\n( 1.)Yes\n\n( 2.) Return to Main Menu\n\n");
	scanf("%d",&h);
	system("cls");
	if(h==1)
	{
		manager_menu();
	}
	else
	{
		main();
	}

	//system("clear");
	//clearing the screen
}



//function to delete items

void deleteitem(char toRemove[100],FILE *fptr)
{
	system("color 0C");


    FILE * fTemp;
    char path[100];

    //char toRemove[100];
    char buffer[1000];
    int e,m;
    /* Input source file path path */
    //do
    //{
    	printf("\n\nDo you want  to delete items:\n\n( 1.)Yes\n\n( 2.)Return to mainmenu\n\n");
    	printf("\nChoose:  ");
    	scanf("%d",&e);
    	switch(e)
    	{
    	    case 1:printf("\n\nEnter the path  of source file:  ");
                    scanf("%s", path);
                   // fplist=path;
                //    printf("\n\nEnter the item you want  to remove from the category list: ");
                  //  scanf("%s", toRemove);
                    //m=Check(toRemove,fptr);
			       //if(m==1)
			       {
			       /*  Open files */
                    fTemp = fopen("delete.txt", "w");
                      /* fopen() return NULL if unable to open file in given mode. */
                    if (fptr == NULL || fTemp == NULL)
                    {
                      /* Unable to open file hence exit */
                      printf("\n\nUnable to open file.\n\n");
                       printf("\n\nPlease check whether file exists and you have read/write privilege.\n\n");
                       exit(EXIT_SUCCESS);
                     }


                          /*
                            * Read line from source file and write to destination
                               * file after removing given word.
                                */
                    while ((fgets(buffer, sizeof(buffer), fptr)) != NULL)
                    {
                                 printf("%s\n",buffer);
                          // Remove all occurrence of word from current line
                            removeAll(buffer, toRemove);

                          // Write to temp file
                         fputs(buffer, fTemp);
                    }//fptr inka path oktey kavali kadha ikkada sink ledh i guess  haa may be


                       /* Close all files to release resource */
                    fclose(fptr);//chusava indhihaa adey akkada ithundhi ikkada katle haa
                    fclose(fTemp);


                     /* Delete original source file */
                    remove(path);

                    /* Rename temp file as original file *///
                    rename("delete.txt", path);
                    printf("\n\nAll occurrence of '%s' removed successfully.\n\n", toRemove);	
			      }
		        	//else
		        //	{
		       // 		printf("\n\nSorry!the item you searched is not available in the store....Go for next\n\n");
		        //	}
                  
                    break;
            case 2:break;
            default:printf("\n\nInvalid choice!!\n\n");
    	}
    //}while(e<=3);
   // manager_menu();
    	printf("\n\nIf you want to further delete items: \n\n ( 1.)Yes\n\n( 2.)Return to menu\n\n");
    	scanf("%d",&e);
    	system("cls");
    	if(e==1)
    	{
    		manager_menu();
    	}
    	else
    	{
    		main();
    	}

    	//system("clear");

}



/**
 * Remove all occurrences of a given word in string.
 */
void removeAll(char * str, const char * toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j < toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */
        if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0')
        {
            found = 0;
        }

        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1)
        {
            for(j=i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }
}
void search()
{
	//searches whether the item is there or not

    system("color 08");
	char s[1000];
	int n,m;
	FILE *fplist;
	//customer can search a item by chosing different categories
	printf("\n\nSelect a category :\n\n ( 1.)Clothing\n\n( 2.)Footwear\n\n( 3.)Vegtables\n\n ( 4.)Fruits\n\n( 5.)Furniture\n\n( 6.)Electronic Appliances\n\n( 7.)Beauty And Cosmetics\n\n( 8.)Return to menu\n\n");
	printf("\n\nChoose a category from above displayed: ");
	scanf("%d",&n);

	//switch case to check
	switch(n)
	{
		       //clothing
		case 1:fplist=fopen("clothing.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category: ");
		       	scanf("%s",&s);
			    m=Check(s,fplist);//checks the item is available
			   //check functions returns 1 or 0 
			    //if 1 it prints the details
			   if(m==1)
			   {
			   	//print the details
			    	printdetails(s);
		    	}
		    	else
		    	{
		    		//else returns error message
		     		printf("\n\nSorry!!!the item you searched is not available in the store....Go for next\n\n");
			    }
			break;
			 //footwaer
		case 2:fplist=fopen("footwear.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category: ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store....Go for next\n\n");
			}
			break;
			//vegetable
		case 3:fplist=fopen("vegetable.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category :  ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store....Go for next\n");
			}
			break;
			//fruits
		case 4:fplist=fopen("fruits.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category : ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store.....Go for next\n\n");
			}
			break;
			//furniture
		case 5:fplist=fopen("furniture.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category : ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store.....Go for next\n\n");
			}
			break;
			//electronic
		case 6:fplist=fopen("electronics.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category : ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store.....Go for next\n\n");
			}
			break;
			//beauty
		case 7:fplist=fopen("beauty.txt","r");
		       printf("\n\nEnter the item you want to search from the choosen category : ");
		       	scanf("%s",&s);
			m=Check(s,fplist);
			if(m==1)
			{
				printdetails(s);
			}
			else
			{
				printf("\n\nSorry!the item you searched is not available in the store.....Go for next\n\n");
			}
			break;
	    case 8:break;
		default:printf("\n\nSorry !! the option is unavailable\n\n");
	}
	printf("\n\nDo you want to search an another item:\n\n( 1.)Yes\n\n( 2.)No\n\n");
	printf("\nChoose :  " );
	scanf("%d",&m);
	system("cls");
	if(m==1)
	{
		search();
	}
	else
	{
		Customer();
	}
	//system("clear");
}



int Check(char *word,FILE *fptr)
{

    char path[100];
    int line, col;

    /* Exit if file not opened successfully */
    if (fptr == NULL)
    {
        printf("\n\nUnable to open file.\n\n");
        printf("\nPlease check you have read/write previleges.\n");

        return 0;
    }


    // Find index of word in fptr
    IndexOf(fptr, word, &line, &col);

    if (line != -1)
       // printf("'%s' is available",word);
	return 1;
    else
       // printf("'%s'  is out of stock", word);
	return 0;


}


/**
 * Finds, first index of a word in given file. First index is represented
 * using line and column.
 */
int IndexOf(FILE *fptr, const char *word, int *line, int *col)
{
    char str[BUFFER_SIZE];
    char *pos;

    *line = -1;
    *col  = -1;

    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        *line += 1;

        // Find first occurrence of word in str
        pos = strstr(str, word);

        if (pos != NULL)
        {
            // First index of word in str is
            // Memory address of pos - memory
            // address of str.
            *col = (pos - str);
            break;
        }
    }


    // If word is not found then set line to -1
    if (*col == -1)
        *line = -1;

    return *col;
}



/**
 * Finds, first index of a word in given file. First index is represented
 * using line and column.
 */

void printdetails(char *str)
{
   //prints the details of the item 
        FILE *ptr;
        ptr=fopen("item.txt","r");

    char temp[500],ftemp[10][500],loc[500],ch,t[500];
    int i=0,k=0;
   while ((ch = fgetc(ptr) )!= EOF)
        {
        	//checks until the next line
        if(ch=='\n')
        {
        	//check until the 7 line
            if(k<7)
            {
            	//copies into a temp vaiable
            strcpy(ftemp[k],temp);
             k++;
            }
            //compare with the string and temp
            if(strcmp(str,ftemp[0])==0){
                if(k==7)
                {
                    break;
                }
            }
            //if k is 7 k i again assigned to 0
            if(k==7)
            {
                k=0;
            }
           memset(temp,0,strlen(temp));
           i=0;
        }
        else{
        temp[i]=ch;
        i++;
        }

    }
    i=0;
    strcpy(ftemp[5],temp);
    if(strcmp(str,ftemp[0])==0)
    {
    while(i<6)
    {
    printf("%s\n",ftemp[i]);
    i++;
    }
    }
}
void categories()
{
	system("color 03");
	//checks the categories
	int i,k,d;
	char *path;
	printf("\n\nDear Customer , We are displaying all the categories available in the store!!\n\n");
	//do{
	//diplays the categories
	printf("\n---------CATEGORIES:----------------\n\n");
	printf("\n\n( 1.)Clothing\n\n( 2.)Footwear\n\n( 3.)Vegtables  And  Fruits\n\n( 4.)Home Furniture\n\n( 5.)Electronic Appliances\n\n( 6.)Beauty And Cosmetics\n\n( 7.) Return to menu\n\n");
	printf("\nCHOOSE ONE:  ");
	scanf("%d",&d);
	switch(d)
	{
  		case 1: printf("\n\nCategories in Footwear:\n\n");
			printf("\n\n( 1.)Women\n\n( 2.)Men\n\n( 3.)Kids");
			printf("\n\nChoose your item: ");
			scanf("%d",&k);
            //switch statement
			switch(k)
			{
				case 1:printf("\n\nWOMEN WEAR:\n\n");
				       printf("\n\nLocation :  2nd Floor\n\nStand : 2,3,4,5\n\n");
					  women_wear();
					  break;
				case 2:
					printf("\n\nMEN WEAR:\n\n");
					printf("\n\nLocation : 2 nd Floor\n\nStand : 6,7,8,9\n\n");
					printf("\n\n( 1.)Top Wear\n\n( 2.)Bottom Wear\n\n( 3.)Sports And Active Wear\n \n( 4.)Party Wear \n\n( 5.)Sleep Wear\n\n");
					break;
					//kids wear
				case 3: printf("\n\nKIDS WEAR:\n\n");
					    printf("\n\nLocation : 2 nd Floor\n\nStand:10,11,12,13\n\n");
					printf("\n\n( 1.)Newborn( 0 - 3 months )\n\n( 2.)Baby ( 3 months - 2 years )\n\n( 3.)Kids( 2 - 8 years)\n\n( 4.)Tweens( 8 - 12 years )\n\n( 5.)Teens(12+)\n\n");
					break;

			}

			break;

		case 2:printf("\n\nFOOTWEAR\n\n");
			printf("\n\n( 1.)Women\n\n( 2.)Men\n\n ( 3.)Kids\n\n");
			printf("\n\nEnter your choice : ");
			scanf("%d",&d);
			switch(d)
			{
				case 1:printf("\n\nMEN FOOTWEAR\n\n");
					printf("\n\nLocation : floor 2\n\nStand : 14,15,16,17\n\n");
					printf("\n\n( 1.)Flats And Casual Shoesn\n\n( 2.)Heels\n\n( 3.)Boots\n\n( 4.)Sports Shoes And Floaters\n\n");
					break;
				case 2:printf("\n\nWOMEN FOOTEAR\n\n");
					printf("\n\nLocation : floor 2\n\nStand : 18,19,20,21\n\n");
					printf("\n\n( 1.)Sneakers\n\n( 2.)Shoes\n\n( 3.)Sandals And Floaters\n\n( 4.)Flipflops\n\n");
					break;
				case 3: printf("\n\nKIDS FOOTWEAR\n\n");
					printf("\n\nLocation : floor 2\n\nStand :  22,23,24,25\n");
					printf("\n\n( 1.)Newborn( 0 - 3 months )\n\n( 2.)Baby( 3 months - 2 years )\n\n( 3.)Kids( 2 - 8 years )\n\n( 4.)Tweens( 8 - 12 years)\n\n( 5.) Teens(12+)\n\n");
					break;
			}
			break;
		case 3:printf("\n\nVEGETABLES AD FRUITS\n\n");
			printf("\n\n( 1.)Vegtables\n\n( 2.)Fruits\n\n");
			printf("\n\nPlease Enter: ( 1.) Vegtables \n\n( 2.)Fruits\n\n");
			printf("\n\nChoose : ");
			scanf("%d",&d);
			switch(d)
			{
				case 1:printf("\n\nVEGETABLES\n\n");
					path="vegetable.txt";
					fileprint(path);
					break;
				case 2:printf("\n\nFRUITS\n\n");
					path="fruits.txt";
					fileprint(path);
					break;
			}
			break;
		case 4:printf("\n\nFURNITURE\n\n");
			path="furniture.txt";
			fileprint(path);
			break;
		case 5:printf("\n\nELECTRONICS\n\n");
			path="electronics.txt";
			fileprint(path);
			break;
		case 6:printf("\n\nBEAUTY\n\n");
		       path="beauty.txt";
			fileprint(path);
			break;
		case 7:return;
		default:printf("\n\nSorry!!! Such category is not available!!:(\n\n");

	}
	//}while(d<=7);
	int l;
	printf("\n\nDo you want to continue shopping : \n\n( 1.)Yes\n\n( 2.)No\n\n");
	printf("\n\nChoose : ");
	scanf("%d",&l);
	system("cls");
	if(l==1)
	{
		categories();
	}
	else
	{
		Customer();
	}

	//system("clear");

}
void  women_wear()
{
	system("color 0A");
	int d,n;
	printf("\n\n Categories in WOMEN CLOTHING\n\n");
	printf("\n\n( 1.)Indian & Fusion Wear\n( 2.)Western Wear\n\n");
    printf("\n\nChoose :  ");
		scanf("%d",&d);
		system("clear");
	switch(d)
	{
//women wear items
		case 1: printf("\n\nTRADITIONAL\n\n");
			 printf("\n( 1.)kurtas\n ");
			printf("\n( 2.)Tunics and tops\n");
			printf("\n( 3.)Ethnic Dresses\n ");
			printf("\n( 4.)Leggings,Salwars and Churidars\n ");
			printf("\n( 5.)Skirts and palazzos\n ");
			printf("\n( 6.)Sarees\n ");
			printf("\n( 7.)Lehanga Choli\n ");
			printf("\n( 8.)Dupattas and Shawls\n");
			printf("\n( 9.)Jackets and Waistcoats\n ");
			break;


			//Western wear of women category
		case 2:printf("\n\nWESTERN\n\n");
			printf("\n( 1.)Jump Suits\n");
			printf("\n(2.)Shorts And Skirts\n");
			printf("\n( 3.)Shrugs AND Style Coats\n");
			printf("\n( 4.)Sweaters And Sweatshirts\n");
			printf("\n( 5.)Blazers\n");
			printf("\n( 6.)sports and active wear\n");
			break;
	}

	system("cls");
}
void fileprint(char* fname)
{
    char line[RSIZ][LSIZ];
    FILE *fptr = NULL;
    int i = 0;
    int tot = 0;
	//printf(" Input the filename to be opened : ");
	//scanf("%s",fname);
    //opens the file
    //and prints the available items 
    fptr = fopen(fname, "r");
    while(fgets(line[i], LSIZ, fptr))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n Items  are : \n");
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }

    printf("\n");

}
void offers()
{
	system("color 0C");
	//customer can view the offers
	char fname[MAX]="offers.txt";
	char ch;
    int d;
	FILE *fptr1;

	//printf("\n Input the file name to be opened : \n");
		//scanf("%s",fname);

  printf("\n\nDo want to check the offers:\n\n( 1.)Yes\n\n( 2.)No\n\n");
  printf("\n\nChoose : ");
  scanf("%d",&d);
  getch();
  system("cls");
  if(d==1)
  {
	fptr1=fopen(fname,"r");
	 ch=fgetc(fptr1);//open tyhe file offers.txt and prints the offers line by line
          printf("\n\nAvailable offers in the store are : \n");
          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(fptr1);
            }
          }
    else
    {

    	printf("Returning to the main menu.....\n");
    	Customer();
        //system("clear");
    }
    

}
 void editoffers()
 {

 	system("color 0C");
 	//manager can edit the offers
        int lno, ctr = 0 ;
	    int n;
        char ch;
        FILE *fptr1, *fptr2;
		char fname[MAX]="offers.txt";
        char str[MAX], temp[] = "temp.txt";
		//aa temporary file is stored

		printf("\n------------------------------------------------------------\n");
		
		//printf(" \n\nInput the file name to be opened :  ");
		//scanf("%s",fname);
        fptr1 = fopen(fname, "a+");
        //opens the file
        if (!fptr1)
		{
                printf("\n\n File not found or unable to open the input file!!\n\n");
        }

	     ch=fgetc(fptr1);
          //printf("\n\nNow the content of the file %s is :  ",fname);
          printf("\n\nOffers in the store are: ");

          while(ch!=EOF)
            {
                printf("%c",ch);
                 ch=fgetc(fptr1);
            }

        rewind(fptr1);
	printf("\n\nManager!!Do you want to:\n\n ( 1.)Remove Offers\n\n( 2.)Add Offers\n\n");
	printf("\n\nChoose : ");
	scanf("%d",&n);

    //manager have 2 options can add offer or delete offer
	if(n==1)
	{
        	fptr2 = fopen(temp, "w"); // open the temporary file in write mode
        	if (!fptr2)
		{
                	printf("\n\nUnable to open a temporary file to write!!\n\n");
 	               fclose(fptr1);

        	}
        	printf("\n\nInput the line you want to remove : ");
        	scanf("%d", &lno);
		lno++;
        // copy all contents to the temporary file except the specific line
        	while (!feof(fptr1))
        	{
            		strcpy(str, "\0");
            		fgets(str, MAX, fptr1);
            		if (!feof(fptr1))
            		{
                		ctr++;
                /* skip the line at given line number */
                		if (ctr != lno)
                		{
                    			fprintf(fptr2, "%s", str);
               			 }
           		 }
        	}
        	printf("\n\nThe offer is removed successfully!!\n");
       		 fclose(fptr1);
        	fclose(fptr2);
        	remove(fname);  		// remove the original file
       		 rename(temp, fname); 	// rename the temporary file to original name
	}

	if(n==2)
	{
		char s[MAX];
		//offers will be added in the file
		printf("\n\nNow you can add offers!!\n\n");
 		fflush(stdin);

		fgets(s, MAX, stdin);
		fputs(s, fptr1);
	}

	int g;
	printf("\n\nIf you want to continue : \n\n( 1.)Yes\n\n( 2.)No\n\n");
	scanf("%d",&g);
	getch();
	system("cls");

	if(g==1)
	{
		editoffers();
	}
	else
	{
		manager_menu();
	}

  }
  //random function to generate a random number to aign rewards
 int printRandoms(int lower, int upper,  
                             int count) 
{ 
    int i,num; 
    for (i = 0; i < count; i++) { 
         num = (rand() % (upper - lower + 1)) + lower; 
         
    } 
    return num;
} 
//a common function to take the review of the customer and store it in file
void GetReview()
{
	system("color 01");
	int lower=1,upper=100,count=1;
	srand(time(0));
	int reward=printRandoms(lower, upper, count);
	FILE *fp;
	fp=fopen("review.txt","a+");
	//review .txt file is opened
	printf(" \n\nPhone number: ");
				scanf("%s",&c.mobilenumber);
				//prints the line in the file
				fprintf(fp,"\nphone number: %s ",c.mobilenumber);
				printf("\n\nEnter your google pay id: ");
				scanf("%s",&c.gpayid);
				fprintf(fp, "\ngpayid: %s",c.gpayid );
				//after entering the details he get a cartch card and the money will be tranferred to the bank 
				printf("\n\nCONGRATULATIONS!!!\n\n");
				printf("\n\nYou Have won a reward of %d\n",reward);
				printf("\n\nYor reward will be transefered to your account shortly!!\n\n");
				fprintf(fp, "\nMoney Recieved : %d",reward);
				fclose(fp);

				//system("cls");

}
  
void review()
{	
	system("color 01");

	int n,m;
	int lower=1,upper=100,count=1;
	srand(time(0));
	int reward=printRandoms(lower, upper, count);
	FILE *fp;
	fp=fopen("review.txt","a+");
	printf("\n\nIs this  the first time visted our store ??\n\n( 1.)Yes \n\n(2.)Already Visited\n\n");
	//checks the condition and takes the review
	scanf("%d",&n);
	if(n==1)
	{
		printf("\n\n================HAPPY SHOPPING=========================\n\n");
		printf("\n\nGive review after your shopping and get amazing offers\n\n");
		printf("\n\nPlease, Rate Our Store\n\n");
		printf("( 1.)  *****  ( Awesome )\n\n( 2.)  ****  ( Best )\n\n( 3.) ***  ( Good )\n\n( 4.) ** (Bad)\n\n( 5.)  *  (Worst)\n\n");
		scanf("%d",&m);
		switch(m)
		{
			//details and the ratinf will be chooen and
			//getreview funtion will be called
			case 1:printf("\n\nEnter your details:\n");
			       printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 5*\nName: %s",c.name);
			       GetReview();
				   break;
				   //****
			case 2:printf("\n\nEnter your details:\n");
			       printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 4*\nName: %s",c.name);
			       GetReview();
				break;
				//***
	        case 3:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 3*\nName: %s",c.name);
			       GetReview();
				break;
				//**
	        case 4:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 2*\nName: %s",c.name);
			       GetReview();
				  break;
				  //*
			case 5:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 1*\nName: %s",c.name);
			       GetReview();
				  break;
		}

 	}

 	//if the cutomer already visits the store then
	else
	{
		printf("\n\nPlease, Rate Our Store\n\n");
		printf("( 1.)  *****  ( Awesome )\n\n( 2.)  ****  ( Best )\n\n( 3.) ***  ( Good )\n\n( 4.) ** (Bad)\n\n( 5.)  *  (Worst)\n\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:printf("\n\nEnter your details:\n");
			       printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 5*\nName: %s",c.name);
			       GetReview();
				   break;
			case 2:printf("\n\nEnter your details:\n");
			       printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 4*\nName: %s",c.name);
			       GetReview();
				break;
	        case 3:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 3*\nName: %s",c.name);
			       GetReview();
				break;
	        case 4:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 2*\nName: %s",c.name);
			       GetReview();
				  break;
			case 5:printf("\n\nEnter your details:\n");
	               printf("\n\nEnter Your name:\n");
				   scanf("%s",&c.name);
				   fprintf(fp," \nrating : 1*\nName: %s",c.name);
			       GetReview();
				  break;
		}


	}
	int e;
	printf("Thankyou for reviewing!!\n");
	printf("If you want to exit press 1 or 2 for shopping\n");
	scanf("%d",&e);
	getch();
	system("cls");
	if(e==1)
	{
		main();
		//system("cls");
	}
	else
	{
		Customer();
		//system("cls");
	}
}
//__________________________________________//
