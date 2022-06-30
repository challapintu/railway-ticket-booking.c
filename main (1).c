#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct online_railway
{
int mobile[10];
char name[15];
int seat_num;
char email[15];
struct online_railway *following;
}
*begin, *stream;
struct online_railway *dummy;
void main()
{
void reserve(int x), cancel(), display(), savefile();
int choice;
begin = stream = NULL;
int num = 1;
do
{
printf("Welcome To online railway Online Booking Hub\n");
printf("1. Reservation\n");
printf("2. Cancel\n");
printf("3. Display Records\n");
printf("4. Exit\n");
printf("Enter Your Choice\n");
scanf("%d", &choice);
switch (choice)
{
case 1:
reserve(num);
num++;
break;
case 2:
cancel();
break;
case 3:
display();
break;
case 4:
{
savefile();
break;
}
default:
printf("ENTER VALID CHOICE(1-4)");
printf("Press Any Key To Go Back To Main Menu");
}
getch();
} while (choice != 4);
}
void details()
{
printf("Enter Your mobile Number: ");
scanf("%s", stream->mobile);
printf("Enter your name: ");
scanf("%s", stream->name);
printf("Enter your email address: ");
scanf("%s", stream->email);
}
void details();
void reserve(int x)
{
stream = begin;
if (begin == NULL)
{
// first user
begin = stream = (struct online_railway*)malloc(sizeof(struct online_railway));
details();
stream->following = NULL;
printf("Seat Booking Successful!\n");
printf("Your Seat Number Is: Seat A-%d", x);
stream->seat_num = x;
return;
}
else if (x > 15)
{
printf("\nSeats Full");
return;
}
else
{
// next user
while (stream->following)
stream = stream->following;
stream->following = (struct online_railway *)malloc(sizeof(struct online_railway));
stream = stream->following;
details();
stream->following = NULL;
printf("\nSeat Booking Succesful!");
printf("\nYour Seat Number Is: Seat A-%d", x);
stream->seat_num = x;
return;
}
}
void savefile()
{
FILE *fpointer = fopen("online Records", "w");
if (!fpointer)
{
printf("\n Error In Opening File!");
return;
}
stream = begin;
//fprintf(fpointer, "mobile No.\t\t\tName\t\t\tEmail\n");
while (stream)
{
fprintf(fpointer, "%-6s", stream->mobile);
fprintf(fpointer, "%-15s", stream->name);
fprintf(fpointer, "%-15s", stream->email);
fprintf(fpointer, "\n");
stream = stream->following;
}
printf("Details Have Been Saved To A File (online Records)");
fclose(fpointer);
}
void display()
{
stream = begin;
while (stream)
{
printf("\nmobile Number : %-6s", stream->mobile);
printf("\nName : %-15s", stream->name);
printf("\nEmail addressddress: %-15s", stream->email);
printf("\nSeat number: A-%d", stream->seat_num);
stream = stream->following;
}
}
void cancel()
{
stream = begin;
char mobile[6];
printf("\nEnter Ticket number to Delete Record?:");
scanf("%s", mobile);
if (strcmp(begin->mobile, mobile) == 0)
{
dummy = begin;
begin = begin->following;
free(dummy);
printf("Booking Has Been Deleted\n");
return;
}
while (stream->following)
{
if (strcmp(stream->following->mobile, mobile) == 0)
{
dummy = stream->following;
stream->following = stream->following->following;
free(dummy);
printf("Has Been Deleted\n");
getch();
return;
}
stream = stream->following;
}
printf("mobile Number Is Wrong Please Check Your mobile\n");
}